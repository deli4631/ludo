#ifndef PAWN_H
#define PAWN_H

#include "shape.h"
#include <QColor>
#include <QGraphicsItem>
#include <QDebug>
#include <QtWidgets>

class Pawn : public Shape {
//    Q_OBJECT

public:
    Pawn(QColor color, const int x, const int y, const int width, int pawn_num):
        Shape(color, x, y, width){
        this->original_x_ = x;
        this->original_y_ = y;
        this->pawn_num = pawn_num;
    }



    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    int get_pawn_loc() { return this->loc; }
    void set_is_out(bool status) { is_out = status; }
//    void set_pawn_num(int num) { this->pawn_num; }
    void set_pawn_loc(int loc) { this->loc = loc; }

    int get_pawn_num() { return pawn_num; }




private:
    int original_x_;
    int original_y_;
    int loc;
    bool is_out = false;
    int pawn_num;



};

#endif
