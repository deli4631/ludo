#ifndef PLAYER_
#define PLAYER_

#include "pawn.h"
#include <QColor>
#include "cell.h"
#include <vector>

#define PATH_SIZE 35;

class Player{

//enum class Color {red, blue, green, yellow};

public:
//    Player(int player_num, QColor color, Pawn* p[4], Cell* s);
    Player(int player_num, QColor color, std::vector<Pawn*> pawns, Cell* s);
    void spawn_pawn();

    Player* Clone() const {
      return new Player(*this);
    }

    void set_player_num(int num) {player_num = num; }
    void set_Color(QColor c) {player_color = c; }
    void set_pawns(std::vector<Pawn*> p) {pawns_ = p; }
    void set_starting_loc(Cell* s) { starting_loc = s; }
    int get_player_num() {return player_num; }
    int get_in_field_pawns() {return in_field_pawns;}
    int move_pawn(int movement, std::vector<Cell*> p);
    Pawn* get_pawn(){ return pawns_[current_pawn]; }
    void death();


private:
    int player_num;
    std::vector<Pawn*> pawns_;
    int in_field_pawns = 0;
    QColor player_color;
    Cell* starting_loc;
    int current_pawn = 0;

};


#endif
