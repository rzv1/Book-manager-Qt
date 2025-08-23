//
// Created by Razvan Andrei on 23.08.2025.
//

#include "domain.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

void Book::to_lower_genre() {
    for (auto& c : genre)
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
}

bool Book::validate_author(const string& new_author) {
    for (auto c : new_author)
        if (isdigit(c))
            throw ValidationException("Autor invalid!");
    return true;
}

bool Book::validate_genre(const string& new_genre) {
    vector<string> list = { "drama", "comedie", "istorie", "fictiune" };
    bool gasit = false;
    for (auto& word : list)
        if (word == new_genre)
            gasit = true;
    if(!gasit)
        throw ValidationException("Gen invalid!");
    return true;
}

bool Book::validate_book() const {
    return validate_genre(genre) && validate_author(author);
}

string Book::to_string() const {
    return "ID: " + std::to_string(id) +
        " Titlu: " + title +
        " Autor: " + author +
        " Gen: " + genre +
        " An aparitie: " + std::to_string(year);
}
