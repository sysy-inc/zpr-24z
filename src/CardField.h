//
// Created by adrwal on 11/6/24.
//

#ifndef CARDFIELD_H
#define CARDFIELD_H
#include "Field.h"

#include <utility>


class CardField final : public Field {
public:
    explicit CardField(const std::string& name, Board& board)
        : Field(name, board)
    {
    }
    void onPlayerEnter(Player* player) override {};
};



#endif //CARDFIELD_H
