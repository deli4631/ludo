#ifndef SHAPE_
#define SHAPE_

#include <QColor>
#include <QGraphicsItem>
#include <QDebug>
#include <QtWidgets>


class Shape : public QObject, public QGraphicsItem {
    Q_OBJECT

protected:
    QColor color_;
    int x_;
    int y_;
    int width_;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

public:
    Shape(QColor color, const int x, const int y, const int width):
    color_(color),
    x_(x),
    y_(y),
    width_(width)
    {}

    void setColor(QColor color){ this->color_ = color; }
    void set_x(int x){ this->x_ = x; }
    void set_y(int y){this->y_ = y; }

    int get_x() { return this->x_; }
    int get_y() { return this->y_; }

    QColor get_color() { return color_; }

//    virtual ~Shape() {};

};


#endif
