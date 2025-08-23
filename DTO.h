//
// Created by Razvan Andrei on 23.08.2025.
//

#ifndef DTO_H
#define DTO_H
#include <string>

using std::string;

class DTO
{
private:
    string type;
    int freq;
public:
    DTO(const string& type) : type{ type }, freq{ 1 } {}
    ~DTO() = default;
    void increment() {
        freq++;
    }
    int get_freq() const {
        return freq;
    }
};
#endif //DTO_H