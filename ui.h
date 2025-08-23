//
// Created by Razvan Andrei on 23.08.2025.
//

#ifndef UI_H
#define UI_H
#include "service.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;

class UI {
private:
    Service& service;
public:
    explicit UI(Service& service) : service{ service } {};

    static void print_menu();
    static void print_menu_update_option();
    static void print_menu_filter_option();
    static void print_menu_sort_option();
    static void print_menu_rental_cart();
    static bool print_all(const vector<Book>& carti);
    void print_report() const;

    static string read_string(const string& prompt);
    static int read_int(const string& prompt);

    void run();

    void add();
    void remove();
    void update_title();
    void update_author();
    void update_genre();
    void update_year();
    void filter_title();
    void filter_year();
    void sort_title();
    void sort_author();
    void sort_year_and_genre();
    void clear_cart();
    void add_cart();
    void generate_cart();
    void export_cart();
    void undo();

    static void invalid();
    static void improved_visuals();
};
#endif //UI_H
