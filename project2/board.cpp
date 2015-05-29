#include "board.h"
#include "game.h"
#include <stdlib.h>
#include <time.h>

#include <QKeyEvent>

Board::Board(QWidget *parent, bool Exist, int Row, int Col,int Level,int Color) : QObject(parent)
{
    row=Row;
    col=Col;
    level=Level;
    color=Color;
    label=new QLabel(parent);
    label->setGeometry(95*col+46,95*row+71,90,90);
    label->setStyleSheet("border:1px solid;");
 //   label->setStyleSheet("background-color: yellow");
    exist=Exist;
   // connect(label,SIGNAL(keyPressEvent()),this,SLOT(click()));
}


Board::~Board()
{
    delete label;
}
/*
void Board::click()
{
    if(clicked==false){
        clicked=true;
        (*Turn)+=1;
        if((*Turn%2)==1){
          //  label->setIcon(QIcon(QPixmap(":/O.png")));
            emit Click(row,col,'O');
        }else{
          //  label->setIcon(QIcon(QPixmap(":/X.png")));
            emit Click(row,col,'X');
        }
    }
}
*/
void Board::init( ){
    srand((unsigned)time(NULL));
    exist =true;
    level =rand()%2;
    switch(level){
    case 0:
    label->setPixmap(QPixmap(":/pic/B0.png"));
    break;
    case 1:
    label->setPixmap(QPixmap(":/pic/B1.png"));
    break;
    }
}

bool Board::doexist(){
    if(exist ==false)
        return false;
    else
        return true;

}

void Board::appear(int Level){
    exist =true;
    level =Level;
    switch(level){
    case 0:
        label->setPixmap(QPixmap(":/pic/B0.png"));
        break;
    case 1:
        label->setPixmap(QPixmap(":/pic/B1.png"));
        break;
    case 2:
        label->setPixmap(QPixmap(":/pic/B2.png"));
        break;
    case 3:
        label->setPixmap(QPixmap(":/pic/B3.png"));
        break;
    case 4:
        label->setPixmap(QPixmap(":/pic/B4.png"));
        break;
    case 5:
        label->setPixmap(QPixmap(":/pic/B5.png"));
        break;
    case 6:
        label->setPixmap(QPixmap(":/pic/B6.png"));
        break;
    case 7:
        label->setPixmap(QPixmap(":/pic/B7.png"));
        break;
    case 8:
        label->setPixmap(QPixmap(":/pic/B8.png"));
        break;
    case 9:
        label->setPixmap(QPixmap(":/pic/B9.png"));
        break;
    }
}

void Board::disappear(){
    exist =false;
    level =-1;
    label->clear();
    label->setStyleSheet("border:1px solid;");
}

void Board::overlape(int Level1,int Level2){
    int Level =Level1+Level2;
    switch(Level){
    case 0:
        label->setPixmap(QPixmap(":/pic/B1.png"));
        level =Level+1;
        break;
    case 1:
        label->setPixmap(QPixmap(":/pic/B1.png"));
        level =Level;
        break;
    case 2:
        label->setPixmap(QPixmap(":/pic/B2.png"));
        level =Level;
        break;
    case 3:
        label->setPixmap(QPixmap(":/pic/B3.png"));
        level =Level;
        break;
    case 4:
        label->setPixmap(QPixmap(":/pic/B4.png"));
        level =Level;
        break;
    case 5:
        label->setPixmap(QPixmap(":/pic/B5.png"));
        level =Level;
        break;
    case 6:
        label->setPixmap(QPixmap(":/pic/B6.png"));
        level =Level;
        break;
    case 7:
        label->setPixmap(QPixmap(":/pic/B7.png"));
        level =Level;
        break;
    case 8:
        label->setPixmap(QPixmap(":/pic/B8.png"));
        level =Level;
        break;
    case 9:
        label->setPixmap(QPixmap(":/pic/B9.png"));
        level =Level;
        break;
    default:
        exist =false;
        level =-1;
        label->clear();
        label->setStyleSheet("border:1px solid;");
        break;

    }
}

bool Board::checkthesame(int row1,int col1,int row2,int col2){

}
int Board::showlevel(){
    return level;
}


void Board::keyPressEvent(QKeyEvent *event){
        if(event->key() == QEvent::KeyPress){
                switch(event->key())
                {
                  case Qt::Key_Left:
                    label->setPixmap(QPixmap(":/2.png"));
                    break;
                  case Qt::Key_Right:
                    label->setPixmap(QPixmap(":/2.png"));
                    break;
                  case Qt::Key_Up:
                    for (int i = 0; i < 4; ++i){
                        for (int j = 0; j < 4; ++j){
                           // moveVertically(i,j,UP);
                        }
                    }
                    break;
                  case Qt::Key_Down:
                    label->setPixmap(QPixmap(":/2.png"));
                     break;
                }

        }

 }
/*
void Board::reset()
{
    pointsScoredLastRound = 0;
    tileCollisionLastRound = false;

    for (int i = 0; i < dimension ; ++i) {
        for (int j = 0; j < dimension; ++j) {
            delete board[i][j];
            board[i][j] = NULL;
        }
    }

    QVector<int> start = freePosition();
    board[start[0]][start[1]] = new Tile();
    start = freePosition();
    board[start[0]][start[1]] = new Tile();

}
*/
/*
void Board::move(Direction direction)
{
    Board pre_move_board(*this);

    prepareForNextMove();

    switch (direction) {
    case UP:
        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j)
                moveVertically(i,j,UP);
        break;
    case DOWN:
        for (int i = dimension-1; i >= 0; --i)
            for (int j = 0; j < dimension; ++j)
                moveVertically(i,j,DOWN);
        break;
    case LEFT:
        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j)
                moveHorizontally(i,j,LEFT);
        break;
    case RIGHT:
        for (int i = 0; i < dimension; ++i)
            for (int j = dimension-1; j >= 0; --j)
                moveHorizontally(i,j, RIGHT);
    }
*/
