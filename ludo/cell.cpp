#include <Qtwidgets>
#include "cell.h"

Cell::Cell(QColor color, const int x, const int y, const int width) {
  this->color_ = color;
  this->x_ = x;
  this->y_ = y;
  this->width_ = width;

}

// where is this object located
// always a rectangle, Qt uses this to know "where" the user
// would be interacting with this object
QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

// define the actual shape of the object
QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, width_);

    return path;
}

// called by Qt to actually display the point

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "( " << x_ << ", " << y_ << ")";
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    QColor c(r, g, b);
    color_ = c;



    // need to make the point actually re-paint itself
    update();

}
void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    // update the line for setBrush to be this
    painter->setBrush(QBrush(color_));
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}
