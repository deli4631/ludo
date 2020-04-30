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

    Cell *cell = new Cell(QColor(240,128,128), 350, 0, 200);
    scene->addItem(cell);


}

void ludo::createPath(){

    int start_x = 200;
    int start_y = 150;
    int cell_size = 50;

    createPath(start_x, start_y, cell_size, true, false, true);
    createPath(start_x, start_y, cell_size, false, true, false);
    createPath(start_x, start_y, cell_size, true, false, true);
    createPath(start_x, start_y, cell_size, false, true, false);

    for(Cell* c : path){
        scene->addItem(c);
    }
}

void ludo::createPath(int &start_x, int &start_y, int &cell_size, bool is_neg, bool add_x_axis, bool version){
    int sign = -1;

    if(is_neg){
        cell_size *= sign;
    }

    for(int i = 0; i < 9; i++){
        Cell* cell = new Cell(Qt::white, start_x, start_y, 50);
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


ludo::~ludo()
{
    delete ui;
}

