#include "ludo.h"
#include "ui_ludo.h"
#include "cell.h"

#include <QDebug>
#include <QTime>
#include <QTimer>



ludo::ludo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ludo)
{
    ui->setupUi(this);
    QGraphicsView* view = ui->playingField;
    scene = new QGraphicsScene;
    // set the color map
    colors[Color::red] = QColor(240,128,128);
    colors[Color::blue] = QColor(135,206,250);
    colors[Color::green] = QColor(152,251,152);
    colors[Color::yellow] = QColor(255,250,205);

    ui->playingField->setScene(scene);
    ui->playingField->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    view->setScene(scene);

    // make the scene the same size as the view containing it
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());






//    int start_x = 200;
//    int cell_size = 50;
//    int start_y = 0;
//    for(int i = 0; i < 8; i++){
//        for(int j = 0; j < 3; ++j){
//            Cell* cell = new Cell(Qt::white, start_x, start_y,  cell_size);
//            scene->addItem(cell);
//            board.push_back(cell);
//            cell = new Cell(Qt::white, start_y, start_x, cell_size);
//            scene->addItem(cell);
//            start_x += cell_size;
//            board.push_back(cell);

//        }
//        start_y += cell_size;
//        start_x = 200;
//        if(i == 3){
//            start_y += cell_size * 3;
//        }
//    }

    createPath();

    Cell *cell = new Cell(colors[Color::red], 350, 0, 200);
    scene->addItem(cell);
    Cell *cell2 = new Cell(colors[Color::blue], 0, 0, 200);
    scene->addItem(cell2);
    Cell *cell3 = new Cell(colors[Color::yellow], 0, 350, 200);
    scene->addItem(cell3);
    Cell *cell4 = new Cell(colors[Color::green], 350, 350, 200);
    scene->addItem(cell4);

    QGraphicsPolygonItem* t1 = new QGraphicsPolygonItem();
    QPolygonF p;
    p << QPointF(200, 200) << QPointF(275,275) << QPointF(200,350);
    t1->setPolygon(p);
    t1->setBrush(colors[Color::blue]);
    scene->addItem(t1);

    QGraphicsPolygonItem* t2 = new QGraphicsPolygonItem();
    QPolygonF p2;
    p2 << QPointF(200, 200) << QPointF(275,275) << QPointF(350,200);
    t2->setPolygon(p2);
    t2->setBrush(colors[Color::red]);
    scene->addItem(t2);

    QGraphicsPolygonItem* t3 = new QGraphicsPolygonItem();
    QPolygonF p3;
    p3 << QPointF(350, 200) << QPointF(275,275) << QPointF(350,350);
    t3->setPolygon(p3);
    t3->setBrush(colors[Color::green]);
    scene->addItem(t3);

    QGraphicsPolygonItem* t4 = new QGraphicsPolygonItem();
    QPolygonF p4;
    p4 << QPointF(200, 350) << QPointF(275,275) << QPointF(350,350);
    t4->setPolygon(p4);
    t4->setBrush(colors[Color::yellow]);
    scene->addItem(t4);

}

void ludo::createPath(){

    int start_x = 200;
    int start_y = 150;
    int cell_size = 50;

    // creates the path of the board
    createPath(start_x, start_y, cell_size, true, false, true);
    createPath(start_x, start_y, cell_size, false, true, false);
    createPath(start_x, start_y, cell_size, true, false, true);
    createPath(start_x, start_y, cell_size, false, true, false);

    //starting points
    path[6]->setColor(colors[Color::red]);
    path[15]->setColor(colors[Color::green]);
    path[24]->setColor(colors[Color::yellow]);
    path[33]->setColor(colors[Color::blue]);

    start_x = 50;
    start_y = 250;
    createEndPath(Color::blue, start_x, start_y, cell_size, false , true);

    start_x = 250;
    start_y = 50;
    createEndPath(Color::red, start_x, start_y, cell_size, false , false);

    start_y = 250;
    start_x = 450;
    createEndPath(Color::green, start_x, start_y, cell_size, true , true);

    start_x = 250;
    start_y = 450;
    createEndPath(Color::yellow, start_x, start_y, cell_size, true , false);
}

void ludo::createPath(int &start_x, int &start_y, int &cell_size, bool is_neg, bool add_x_axis, bool version){
    int sign = -1;

    if(is_neg){
        cell_size *= sign;
    }

    for(int i = 0; i < 9; i++){
        Cell* cell = new Cell(Qt::white, start_x, start_y, 50);
        scene->addItem(cell);
        path.push_back(cell);
        if(add_x_axis){
            start_x += cell_size;
        } else {
            start_y += cell_size;
        }
        if(i == 2 && version){
            add_x_axis = true;
            cell_size *= -1;
        } else if (i == 2) {
            add_x_axis = false;
        }
        if(i == 4 && version){
            add_x_axis = false;
        } else if (i == 4) {
            add_x_axis = true;
            cell_size *= -1;
        }
    }
    if(version && is_neg){
        start_x += cell_size;
    } else if(version && !is_neg){
        start_x -= cell_size;
    }
    else {
        start_y -= cell_size;
    }
}

void ludo::createEndPath(Color c, int start_x, int start_y, int cell_size, bool is_neg, bool add_x_axis){
    std::vector<Cell*> end;
    for(int i = 0; i < 3; ++i){
        Cell* cell = new Cell(colors[c], start_x, start_y, 50);
        end.push_back(cell);
        scene->addItem(cell);
        if(add_x_axis && is_neg){
            start_x -= cell_size;
        } else if (add_x_axis && !is_neg){
            start_x += cell_size;
        } else if(!add_x_axis && is_neg){
            start_y -= cell_size;
        } else {
            start_y += cell_size;
        }
    }
    end_path[c] = end;
}


ludo::~ludo()
{
    delete ui;
}

