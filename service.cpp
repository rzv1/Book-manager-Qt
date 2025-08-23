//
// Created by Razvan Andrei on 23.08.2025.
//

#include "service.h"

/*
Functia valideaza o carte apoi o adauga in repo
throw: gen / autor invalid
*/
void Service::add(const string& title, const string& author, const string& genre, const int year) {
	Book c{ title, author, genre, year };
	(void)c.validate_book();
	repo.add(c);
	undoActions.push_back(std::make_unique<UndoAdauga>(repo, c.get_id()));
}

/*
Functia sterge cartea cu id-ul dat
throw: Cartea cu ID nu exista
*/
void Service::remove(int id) {
	Book sters = repo.get_by_id(id);
	repo.remove(id);
	undoActions.push_back(std::make_unique<UndoSterge>(repo, sters));
}

/*
Functia actualizeaza titlul unei carti
throw: Cartea cu ID nu exista
*/
void Service::update_title(int id, const string& title) {
	Book veche = repo.get_by_id(id);
	repo.update_title(id, title);
	undoActions.push_back(std::make_unique<UndoModifica>(repo, veche));
}

/*
Functia actualizeaeza autorul unei carti
throw: Cartea cu ID nu exista sau autor invalid
*/
void Service::update_author(int id, const string& author) const {
	repo.update_author(id, author);
}

/*
Functia actualizeaeza gen-ul unei carti
throw: Cartea cu ID nu exista sau gen invalid
*/
void Service::update_genre(int id, const string& genre) const {
	repo.update_genre(id, genre);
}

/*
Functia actualizeaeza anul unei carti
throw: Cartea cu ID nu exista
*/
void Service::update_year(int id, const int year) const {
	repo.update_year(id, year);
}

/*
Functia filtreaza cartile dupa un titlu dat
*/
vector<Book> Service::filter_title(const string& title) const {
	vector<Book> filtered;
	auto& all = get_all();
	copy_if(all.begin(), all.end(), std::back_inserter(filtered), [&](const Book& carte) { return carte.get_title() == title; });
	return filtered;
}

/*
Functia filtreaza cartile dupa un an dat
*/
vector<Book> Service::filter_year(const int year) const {
	vector<Book> filtered;
	auto& all = get_all();
	copy_if(all.begin(), all.end(), std::back_inserter(filtered), [&](const Book& carte) { return carte.get_year() == year; });
	return filtered;
}

/*
Functia sorteaza cartile dupa un titlu dat
*/
vector<Book> Service::sort_title() const {
	vector<Book> sorted = get_all();

	std::sort(sorted.begin(), sorted.end(), [](const Book& a, const Book& b) { return a.get_title() < b.get_title(); });
	return sorted;
}

/*
Functia filtreaza cartile dupa un autor dat
*/
vector<Book> Service::sort_author() const {
	vector<Book> sorted = get_all();

	std::sort(sorted.begin(), sorted.end(), [](const Book& a, const Book& b) { return a.get_author() < b.get_author(); });
	return sorted;
}

/*
Functia filtreaza cartile dupa un an si gen date
*/
vector<Book> Service::sort_year_and_genre() const {
	vector<Book> sorted = get_all();

	std::sort(sorted.begin(), sorted.end(), [](const Book& a, const Book& b) {
		return (a.get_year() < b.get_year()) ||
			(a.get_year() == b.get_year() && a.get_genre() < b.get_genre());
		});
	return sorted;
}

bool Service::clear_cart() const {
	cart.clear_cart();
	return true;
}

bool Service::add_cart(const string& title) const {
	vector<Book> filtered = filter_title(title);
	cart.add_cart(filtered);
	return true;
}

bool Service::generate_cart(const int n) const {
	cart.generate_cart(n);
	return true;
}

bool Service::export_cart(const string& filename) const {
	(void)cart.export_cart(filename);
	return true;
}

vector<Book>& Service::cart_get_all() const {
	return cart.get_all();
}

void Service::undo() {
	if (undoActions.empty())
		throw std::runtime_error("Nu exista operatii de anulat.");
	undoActions.back()->doUndo();
	undoActions.pop_back();
}