#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QGraphicsItem>

class Cell : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    Cell(QColor color, const int x, const int y, const int width_);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

private:
    int x_;
    int y_;
    QColor color_;
    int width_;
    friend bool operator==(const Cell &first, const Cell &other);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

};





#endif
