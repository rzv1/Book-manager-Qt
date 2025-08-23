//
// Created by Razvan Andrei on 23.08.2025.
//

#ifndef REPO_H
#define REPO_H
#include <vector>
#include "domain.h"
using std::vector;

class RepoException {
private:
    string message;
public:
    RepoException(const string& message) : message{ message } {}
    ~RepoException() = default;
    const string& get_message() const {
        return message;
    }
};

class Repo {
private:
    vector<Carte> books;
    int next_id;
    string filepath;
public:
    Repo(string filepath) : next_id{ 1 }, filepath{ filepath } {
        read_file();
    }

    ~Repo() = default;

    void add(Carte& book);

    void remove(int id);

    //void update_by_parameter(Carte& book, void(Carte::*setter)(const string&), const string& parameter) const;
    void update_title(int id, const string& title);
    void update_author(int id, const string& author);
    void update_genre(int id, const string& genre);
    void update_year(int id, const int year);
    void read_file();
    void write_file();

    Carte& get_by_id(int id);

    const vector<Carte>& get_all() const {
        return books;
    }

    size_t get_size() const {
        return books.size();
    }
};
#endif //REPO_H
