//
// Created by Razvan Andrei on 23.08.2025.
//

#include "repo.h"
#include <fstream>

using std::ifstream;
using std::ofstream;

void Repo::read_file() {
    ifstream f(filepath);
    int year;
    string title, author, genre;
    while (f >> title >> author >> genre >> year) {
        Book c(title, author, genre, year);
        add(c);
    }
}

void Repo::write_file() const {
    ofstream f(filepath);
    for (const auto& book : books) {
        f << book.get_title() << " " << book.get_author() << " " << book.get_genre() << " " << book.get_year() << "\n";
    }
}

void Repo::add(Book& book) {
    book.set_id(next_id++);
    books.push_back(book);
}

void Repo::remove(const int id) {
    bool gasit = false;
    for (size_t i = 0; i < books.size() && !gasit; i++) {
        if (books[i].get_id() == id) {
            books.erase(books.begin() + i);
            gasit = true;
        }
    }
    if (!gasit)
        throw RepoException("Cartea cu id-ul dat nu exista!");
}

//void Repo::update_by_parameter(Book& book, void(Book::* setter)(const string&), const string& parameter) const {
//	if (parameter.empty())
//		throw RepoException("Parametrul dat este invalid!");
//	(book.*setter)(parameter);
//}

void Repo::update_title(const int id, const string& title) {
    Book& c = get_by_id(id);
    c.set_title(title);
}
void Repo::update_author(const int id, const string& author) {
    Book& c = get_by_id(id);
    Book::validate_author(author);
    c.set_author(author);
}
void Repo::update_genre(const int id, const string& genre) {
    Book& c = get_by_id(id);
    Book::validate_genre(genre);
    c.set_genre(genre);
}
void Repo::update_year(const int id, const int year) {
    Book& c = get_by_id(id);
    c.set_year(year);
}

Book& Repo::get_by_id(const int id) {
    for (auto& carte : books)
        if (carte.get_id() == id)
            return carte;
    throw RepoException("Id-ul nu exista!");
}