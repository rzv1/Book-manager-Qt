//
// Created by Razvan Andrei on 23.08.2025.
//

#ifndef RENTALCART_H
#define RENTALCART_H
#include "domain.h"
#include <vector>
#include <random>

using std::vector;

class Rentalcart {
private:
    vector<Book> books;
    size_t size;

    std::string chars = "abcdefghijklmnopqrstuvwxyz";
    std::mt19937 gen;

    string random_string(int lenght);
    string random_genre();
    int random_int(int limit);
public:
    Rentalcart() : gen(std::random_device{}()), size{ 0 } {}

    bool clear_cart();
    bool add_cart(const vector<Book>& carti);
    bool generate_cart(int n);
    bool export_cart(const string& filename) const;

    vector<Book>& get_all() {
        return books;
    }

    [[nodiscard]] size_t get_size() const{
        return size;
    }
};
#endif //RENTALCART_H
