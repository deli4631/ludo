#include "player.h"



Player::Player(int player_num, QColor color, std::vector<Pawn*> pawns, Cell* s){
    this->player_num = player_num;
    this->player_color = color;
    this->pawns_ = pawns;
    this->starting_loc = s;
}

void Player::spawn_pawn(){
    this->pawns_[current_pawn]->set_x(this->starting_loc->get_x());
    this->pawns_[current_pawn]->set_y(this->starting_loc->get_y());
    in_field_pawns += 1;
    pawns_[0]->set_pawn_loc(this->starting_loc->get_location());
}

int Player::move_pawn(int movement, std::vector<Cell*> p){
    int tmp = movement;
    movement += this->pawns_[current_pawn]->get_pawn_loc();
    if(movement >= int(p.size())){
        movement -= p.size();
    }

    if(p[movement]->get_tile() == Tiles::times2){
        tmp *= 2;
    } else if (p[movement]->get_tile() == Tiles::times_2){
         tmp *= -2;
    }

    if(p[movement]->get_tile() == Tiles::regular){
        this->pawns_[current_pawn]->set_pawn_loc(movement);
        this->pawns_[current_pawn]->set_x(p[movement]->get_x());
        this->pawns_[current_pawn]->set_y(p[movement]->get_y());
        return movement;
    } else{
        tmp += this->pawns_[current_pawn]->get_pawn_loc();

        if(tmp >= int(p.size())){
            tmp -= p.size();
        }
        this->pawns_[current_pawn]->set_pawn_loc(tmp);
        this->pawns_[current_pawn]->set_x(p[tmp]->get_x());
        this->pawns_[current_pawn]->set_y(p[tmp]->get_y());
        return tmp;
    }
}

void Player::death() {
    this->current_pawn++;
    this->in_field_pawns--;
}
