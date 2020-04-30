#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QGraphicsItem>
#include "shape.h"

class Cell : public Shape{

public:
    Cell(QColor color, const int x, const int y, const int width):
        Shape(color, x, y, width){
    }

//    friend bool operator==(const Cell &first, const Cell &other);

//protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};





#endif
