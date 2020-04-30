#ifndef SHAPE_
#define SHAPE_

#include <QColor>
#include <QGraphicsItem>
#include <QDebug>

class Shape : public QObject, public QGraphicsItem {
    Q_OBJECT

protected:
    QColor color_;
    int x_;
    int y_;
    int width_;

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

public:
    Shape(QColor color, const int x, const int y, const int width):
    color_(color),
    x_(x),
    y_(y),
    width_(width)
    {}


    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    void setColor(QColor color){ this->color_ = color; }

//    void printCoords(){ qDebug() << this->x_ << this->y_; }
};


#endif
