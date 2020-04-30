#ifndef LUDO_H
#define LUDO_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <vector>
#include <QColor>

#include "cell.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ludo; }
QT_END_NAMESPACE


enum class Color {red, blue, green, yellow};

class ludo : public QMainWindow
{
    Q_OBJECT

public:
    ludo(QWidget *parent = nullptr);
    void createPath();
    void createPath(int &start_x, int &start_y, int &cell_size, bool is_neg, bool add_x_axis, bool version);
    void createEndPath(Color c, int start_x, int start_y, int cell_size, bool is_neg, bool add_x_axis);


    ~ludo();




private:
    Ui::ludo *ui;
    QGraphicsScene *scene;
    std::vector<Cell*> path;
    std::map<Color, std::vector<Cell*>> end_path;
    std::map<Color, QColor> colors;
};
#endif // LUDO_H
