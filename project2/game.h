#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "result.h"
#include <board.h>



namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
     void move(QKeyEvent *event);
    explicit   game(QWidget *parent,result* res) ;
    game(QWidget *parent);
    bool checkfull();
    void checkthesame(QKeyEvent *event);
    ~game();

private slots:
   // void SquareClick(int row,int col,char symbol);

    void on_pushButton_clicked();

signals:
    void reset();


private:
    Ui::game *ui;
    QWidget * mainWindow;
    result * resWindow;
    Board *board[4][4];
    void keyPressEvent(QKeyEvent *event);

    int turn;
    char Symbols[4][4];
    char checkWin();

};

#endif // GAME_H
