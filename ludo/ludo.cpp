#include "ludo.h"
#include "ui_ludo.h"



#include <QThread>
#include <QDebug>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


int RandomNumber(int min, int max){
  return (rand() % (max - min + 1) + min);
}


ludo::ludo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ludo)
{
    ui->setupUi(this);
    QGraphicsView* view = ui->playingField;
    scene = new QGraphicsScene;

    //connections

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

    createBoard();

    Cell *cell = new Cell(colors[Color::red], 350, 0, 200, 0, Tiles::regular);
    scene->addItem(cell);
    Cell *cell2 = new Cell(colors[Color::blue], 0, 0, 200, 0, Tiles::regular);
    scene->addItem(cell2);
    Cell *cell3 = new Cell(colors[Color::yellow], 0, 350, 200, 0, Tiles::regular);
    scene->addItem(cell3);
    Cell *cell4 = new Cell(colors[Color::green], 350, 350, 200, 0, Tiles::regular);
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

    Pawn* a1 = new Pawn(colors[Color::blue], 40, 40, 50, 0);
    Pawn* a2 = new Pawn(colors[Color::blue], 100, 40, 50, 1);
    Pawn* a3 = new Pawn(colors[Color::blue], 40, 100, 50, 2);
    Pawn* a4 = new Pawn(colors[Color::blue], 100, 100, 50, 3);



    Player* player1 = new Player(0, colors[Color::blue], std::vector<Pawn*>{a1, a2, a3, a4}, path[33]);

    scene->addItem(a1);
    scene->addItem(a2);
    scene->addItem(a3);
    scene->addItem(a4);

    Pawn* b1 = new Pawn(colors[Color::green], 460, 400, 50, 0);
    Pawn* b2 = new Pawn(colors[Color::green], 460, 460, 50, 1);
    Pawn* b3 = new Pawn(colors[Color::green], 400, 400, 50, 2);
    Pawn* b4 = new Pawn(colors[Color::green], 400, 460, 50, 3);


    Player* player2 = player1->Clone();
    player2->set_player_num(1);
    player2->set_Color(colors[Color::green]);
    player2->set_pawns(std::vector<Pawn*>{b1,b2,b3,b4});
    player2->set_starting_loc(path[15]);
    scene->addItem(b1);
    scene->addItem(b2);
    scene->addItem(b3);
    scene->addItem(b4);

    players.push_back(player1);
    players.push_back(player2);


//  for debuggin purposes
//    this->test = new Pawn(colors[Color::red], path[0]->get_x(), path[0]->get_y(), 50, 0);
//    scene->addItem(test);

   // 2, 6, 11, 15 20, 23, 28, 32
   // 12, 21, 29,
    //setting up the special tiles
    path[2]->set_tile(Tiles::times2);
    path[2]->setColor(QColor(255,215,0));


    path[15]->set_tile(Tiles::times2);
    path[15]->setColor(QColor(255,215,0));
    path[20]->set_tile(Tiles::times2);
    path[20]->setColor(QColor(255,215,0));

    path[28]->set_tile(Tiles::times2);
    path[28]->setColor(QColor(255,215,0));


    path[12]->set_tile(Tiles::times_2);
    path[12]->setColor(QColor(220,20,60));

    path[24]->set_tile(Tiles::times_2);
    path[24]->setColor(QColor(220,20,60));


}



void ludo::createBoard(){
    srand(time(0));
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
        Cell* cell = new Cell(Qt::white, start_x, start_y, 50, path_size, Tiles::regular);
        path_size += 1;
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
    int pos = 0;
    for(int i = 0; i < 3; ++i){
        Cell* cell = new Cell(colors[c], start_x, start_y, 50, pos, Tiles::regular);
        pos += 1;
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

int rollDice(){
    int probability = 0;
    probability = RandomNumber(1, 60);
    int roll = 0;

    if(probability <= 10){
        roll = 1;
    } else if(probability > 10 && probability <= 20){
        roll = 2;
    } else if (probability > 20 && probability <= 30){
        roll = 3;
    } else if (probability > 30 && probability <= 40){
        roll = 4;
    } else if (probability > 40 && probability <= 50){
        roll = 5;
    } else {
        roll = 6;
    }

    return roll;
}


void ludo::on_pushButton_clicked() {
    if(hasNotRolled){
        if(this->player_turn == 2){
            player_turn = 0;
        }

        int roll = rollDice();
        loc += roll;
        qDebug() << roll;

        std::string t = "Player Turn: " + std::to_string(player_turn + 1);
        QString qs(t.c_str());
        ui->turnLabel->setText(qs);




        if(players[player_turn]->get_in_field_pawns() == 0){
            if(roll == 1 || roll == 6){
                players[player_turn]->spawn_pawn();
                player_turn += 1;
            }
        } else {
            int check = players[player_turn]->move_pawn(roll, path);
            int player_check = 0;
            if(player_turn == 0){
                player_check = 1;
            }
            Pawn* p = players[player_check]->get_pawn();
            if(check == p->get_pawn_loc()){
                scene->removeItem(p);
                players[player_check]->death();
            }
            player_turn += 1;
        }

//for debugging
//        if(loc >= int(path.size())){
//            loc -= path.size();
//        }
//        test->set_x(path[loc]->get_x());
//        test->set_y(path[loc]->get_y());
        scene->update();
    }

}

