//
// Created by Razvan Andrei on 23.08.2025.
//

#ifndef DTO_H
#define DTO_H
#include <string>
#include <utility>

using std::string;
using std::move;

class DTO
{
private:
    string type;
    int freq;
public:
    explicit DTO(string  type) : type{std::move( type )}, freq{ 1 } {}
    ~DTO() = default;
    void increment() {
        freq++;
    }
    [[nodiscard]] int get_freq() const {
        return freq;
    }
};
#endif //DTO_H