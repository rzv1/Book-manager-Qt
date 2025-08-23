//
// Created by Razvan Andrei on 23.08.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "repo.h"
#include "domain.h"
#include "rentalcart.h"
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>
#include "DTO.h"
using std::string;
using std::vector;
using std::map;
using std::copy_if;
using std::unique_ptr;


class ActiuneUndo {
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() noexcept = default;
};

class UndoAdauga final : public ActiuneUndo {
	Repo& repo;
	int id;
public:
	UndoAdauga(Repo& r, const int idCarteNoua) : repo{ r }, id{ idCarteNoua } {}
	void doUndo() override {
		repo.remove(id);
	}
};

class UndoSterge final : public ActiuneUndo {
	Repo& repo;
	Book carteStearsa;
public:
	UndoSterge(Repo& r, const Book& c) : repo{ r }, carteStearsa{ c } {}
	void doUndo() override {
		repo.add(carteStearsa);
	}
};

class UndoModifica final : public ActiuneUndo {
	Repo& repo;
	Book carteVeche;
public:
	UndoModifica(Repo& r, const Book& inainte) : repo{ r }, carteVeche{ inainte } {}
	void doUndo() override {
		repo.update_title(carteVeche.get_id(), carteVeche.get_title());
		repo.update_author(carteVeche.get_id(), carteVeche.get_author());
		repo.update_genre(carteVeche.get_id(), carteVeche.get_genre());
		repo.update_year(carteVeche.get_id(), carteVeche.get_year());
	}
};

class Service {
private:
	Repo& repo;
	Rentalcart& cart;
	map<string, DTO> type_pairs;
	vector<unique_ptr<ActiuneUndo>> undoActions;
public:
	Service(Repo& repo, Rentalcart& cart) : repo{ repo }, cart{ cart } {}
	Service(const Service&) = delete;
	Service& operator=(const Service&) = delete;

	void add(const string& title, const string& author, const string& genre, const int year);
	void remove(int id);
	void update_title(int id, const string& title);
	void update_author(int id, const string& author) const;
	void update_genre(int id, const string& genre) const;
	void update_year(int id, int year) const;
	[[nodiscard]] vector<Book> filter_title(const string& title) const;
	[[nodiscard]] vector<Book> filter_year(int year) const;
	[[nodiscard]] vector<Book> sort_title() const;
	[[nodiscard]] vector<Book> sort_author() const;
	[[nodiscard]] vector<Book> sort_year_and_genre() const;

	void undo();

	void add_to_map() {
		for (const auto& book : repo.get_all()) {
			string genre = book.get_genre();
			auto it = type_pairs.find(genre);
			if (it == type_pairs.end()) {
				type_pairs.insert({ genre, DTO(genre) });
			}
			else {
				it->second.increment();
			}
		}
	}

	void clear_map() {
		type_pairs.clear();
	}

	[[nodiscard]] map<string, DTO> get_map() const {
		return type_pairs;
	}

	[[nodiscard]] Rentalcart& get_cart() const {
		return cart;
	}
	bool clear_cart() const;
	bool add_cart(const string& title) const;
	bool generate_cart(int n) const;
	bool export_cart(const string& filename) const;
	vector<Book>& cart_get_all() const;

	const vector<Book>& get_all() const {
		return repo.get_all();
	}
};
#endif //SERVICE_H
