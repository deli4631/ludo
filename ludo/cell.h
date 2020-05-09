#ifndef CELL_H
#define CELL_H

#include "shape.h"
enum class Tiles {regular, times2, times_2};
class Cell : public Shape{

private:
    int location_ = 0;
    Tiles tile;

public:
    Cell(QColor color, const int x, const int y, const int width, int location, Tiles t):
        Shape(color, x, y, width){
        this->location_ = location;
        this->tile = t;
    }

     QRectF boundingRect() const override;
     QPainterPath shape() const override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
     void setColor(QColor color){ this->color_ = color; }

     int get_location(){ return location_; }

     void set_tile(Tiles t){ tile = t;}
     Tiles get_tile() { return tile;}


};









#endif
