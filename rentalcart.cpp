//
// Created by Razvan Andrei on 23.08.2025.
//

#include "rentalcart.h"
#include <random>
#include <fstream>
#include <string>

string Rentalcart::random_string(const int lenght) {
    std::string random;
    std::uniform_int_distribution<> dist(0, static_cast<int>(chars.size()) - 1);
    random.reserve(lenght);
    std::generate_n(std::back_inserter(random), lenght, [&]() { return chars[dist(gen)]; });
    return random;
}

string Rentalcart::random_genre() {
    const std::string genres[] = { "drama", "comedie", "istorie", "fictiune" };
    std::uniform_int_distribution<> dist(0, 3);
    return genres[dist(gen)];
}

int Rentalcart::random_int(const int limit) {
    std::uniform_int_distribution<> dist(1, limit);
    return dist(gen);
}

bool Rentalcart::clear_cart() {
    books.clear();
    return true;
}

bool Rentalcart::add_cart(const vector<Book>& carti) {
    bool gasit = false;
    for (const auto& book : carti) {
        books.push_back(book);
        size++;
        gasit = true;
    }
    return gasit;
}

bool Rentalcart::generate_cart(int n) {
    while (n--) {
        const int id = random_int(19999);
        const string title = random_string(7);
        const string author = random_string(5);
        const string genre = random_genre();
        const int year = random_int(2020);
        Book book(title, author, genre, year);
        book.set_id(id);
        books.push_back(book);
    }
    return true;
}

bool Rentalcart::export_cart(const string& filename) const {
    std::ofstream fout(filename);

    fout << "ID,Title,Author,Genre,Year\n";

    for (const Book& c : books)
        fout << c.get_id() << "," << c.get_title() << "," << c.get_author() << "," << c.get_genre() << "," << c.get_year() << "\n";

    fout.close();

    return true;
}
