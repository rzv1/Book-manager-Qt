//
// Created by Razvan Andrei on 23.08.2025.
//

#ifndef REPO_H
#define REPO_H
#include <utility>
#include <vector>
#include "domain.h"
using std::vector;
using std::move;

class RepoException {
private:
    string message;
public:
    RepoException(string  message) : message{std::move( message )} {}
    ~RepoException() = default;
    [[nodiscard]] const string& get_message() const {
        return message;
    }
};

class Repo {
private:
    vector<Book> books;
    int next_id;
    string filepath;
public:
    explicit Repo(string filepath) : next_id{ 1 }, filepath{std::move( filepath )} {
        read_file();
    }

    ~Repo() = default;

    void add(Book& book);

    void remove(int id);

    //void update_by_parameter(Book& book, void(Book::*setter)(const string&), const string& parameter) const;
    void update_title(int id, const string& title);
    void update_author(int id, const string& author);
    void update_genre(int id, const string& genre);
    void update_year(int id, int year);
    void read_file();
    void write_file() const;

    Book& get_by_id(int id);

    [[nodiscard]] const vector<Book>& get_all() const {
        return books;
    }

    [[nodiscard]] size_t get_size() const {
        return books.size();
    }
};
#endif //REPO_H
