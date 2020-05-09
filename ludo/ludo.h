#ifndef LUDO_H
#define LUDO_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <vector>
#include <QColor>

#include "cell.h"
#include "pawn.h"
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ludo; }
QT_END_NAMESPACE

enum class Color {red, blue, green, yellow};

class ludo : public QMainWindow
{
    Q_OBJECT

public:
    ludo(QWidget *parent = nullptr);
    void createBoard();
    void createPath(int &start_x, int &start_y, int &cell_size, bool is_neg, bool add_x_axis, bool version);
    void createEndPath(Color c, int start_x, int start_y, int cell_size, bool is_neg, bool add_x_axis);
    void startGame();


    ~ludo();




private slots:
    void on_pushButton_clicked();



private:
    Ui::ludo *ui;
    QGraphicsScene *scene;
    std::vector<Cell*> path;
    std::vector<Pawn*> p;
    std::map<Color, std::vector<Cell*>> end_path;
    std::map<Color, QColor> colors;
    bool endGame = false;
    int loc = 0;
    int player_turn = 0;
    std::vector<Player*> players;
    int path_size = 0;
    bool hasNotRolled = true;
    std::vector<Cell*> end_cell;


    Pawn* test;

};
#endif // LUDO_H
