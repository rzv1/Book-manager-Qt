//
// Created by Razvan Andrei on 23.08.2025.
//

#ifndef DOMAIN_H
#define DOMAIN_H
#include <string>
#include <iostream>
#include <utility>
using std::string;
using std::move;

// Clasa ValidationException este folosita pentru a arunca exceptii in cazul in care datele introduse nu sunt valide
class ValidationException {
private:
    string message;
public:
    explicit ValidationException(string message) : message{ std::move(message) } {}
    [[nodiscard]] string get_message() const {
        return this->message;
    }
    bool operator==(const string& ot) const {
        return message == ot;
    }
};
// Clasa Book reprezinta o carte cu titlu, autor, gen, an de publicare si id
class Book {
private:
    string title;
    string author;
    string genre;
    int year;
    int id;
public:
    //Constructor cu parametrii
    Book(string  title, string  author, string genre, const int year) : title{std::move( title )}, author{std::move( author )}, genre{ std::move( genre ) }, year{ year }, id{ 0 } {
        to_lower_genre();
    }
    //Copiator
    Book(const Book& other) : title{ other.title }, author{ other.author }, genre{ other.genre }, year{ other.year }, id{ other.id } {
        //std::cout << "Book " << other.get_title() << " copiata!\n";
    }
    //Constructor default
    ~Book() = default;

    // Getters si Setters pentru a accesa si modifica datele private ale cartii
    [[nodiscard]] string get_title() const {
        return title;
    }
    [[nodiscard]] string get_author() const {
        return author;
    }
    [[nodiscard]] string get_genre() const {
        return genre;
    }
    [[nodiscard]] int get_year() const {
        return year;
    }
    [[nodiscard]] int get_id() const {
        return id;
    }

    void set_title(const string& new_title) {
        title = new_title;
    }
    void set_author(const string& new_author) {
        author = new_author;
    }
    void set_genre(const string& new_genre) {
        genre = new_genre;
    }
    void set_year(int new_year) {
        year = new_year;
    }
    void set_id(int new_id) {
        id = new_id;
    }

    // Functii de validare a datelor introduse
    static bool validate_author(const string& author) ;

    static bool validate_genre(const string& genre);
    bool validate_book() const;
    void to_lower_genre();

    // Functie de printare a datelor
    [[nodiscard]] string to_string() const;
};
#endif //DOMAIN_H
