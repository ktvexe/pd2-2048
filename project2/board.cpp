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
    color=rand()%4;
    switch (color) {
    case 0:
        switch(level){
            case 0:
            label->setPixmap(QPixmap(":/pic/B0.png"));
            break;
            case 1:
            label->setPixmap(QPixmap(":/pic/B1.png"));
            break;
        }
        break;
    case 1:
            switch(level){
                case 0:
                label->setPixmap(QPixmap(":/pic/G0.png"));
                break;
                case 1:
                label->setPixmap(QPixmap(":/pic/G1.png"));
                break;
           }
        break;
    case 2:
                switch(level){
                case 0:
                label->setPixmap(QPixmap(":/pic/O0.png"));
                break;
                case 1:
                label->setPixmap(QPixmap(":/pic/O1.png"));
                break;
               }
        break;
    case 3:
                    switch(level){
                    case 0:
                    label->setPixmap(QPixmap(":/pic/R0.png"));
                    break;
                    case 1:
                    label->setPixmap(QPixmap(":/pic/R1.png"));
                    break;
                    }
       break;
    }
}

bool Board::doexist(){
    if(exist ==false)
        return false;
    else
        return true;

}

void Board::pics(int Level,int Color){
    switch(Level){
    case 0:
        if(Color == 0)
                label->setPixmap(QPixmap(":/pic/B0.png"));
        else if (Color ==1)
                 label->setPixmap(QPixmap(":/pic/G0.png"));
        else if(Color ==2)
                 label->setPixmap(QPixmap(":/pic/O0.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R0.png"));
        break;
    case 1:
        if(Color == 0)
                label->setPixmap(QPixmap(":/pic/B1.png"));
        else if (Color ==1)
                 label->setPixmap(QPixmap(":/pic/G1.png"));
        else if(Color ==2)
                 label->setPixmap(QPixmap(":/pic/O1.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R1.png"));
        break;
    case 2:
        if(Color == 0)
                label->setPixmap(QPixmap(":/pic/B2.png"));
        else if (Color ==1)
                 label->setPixmap(QPixmap(":/pic/G2.png"));
        else if(Color ==2)
                 label->setPixmap(QPixmap(":/pic/O2.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R2.png"));
        break;
    case 3:
        if(Color == 0)
                label->setPixmap(QPixmap(":/pic/B3.png"));
        else if (Color ==1)
                 label->setPixmap(QPixmap(":/pic/G3.png"));
        else if(Color ==2)
                 label->setPixmap(QPixmap(":/pic/O3.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R3.png"));
        break;
    case 4:
        if(Color == 0)
                label->setPixmap(QPixmap(":/pic/B4.png"));
        else if (Color ==1)
                 label->setPixmap(QPixmap(":/pic/G4.png"));
        else if(Color ==2)
                 label->setPixmap(QPixmap(":/pic/O4.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R4.png"));
        break;
    case 5:
        if(Color == 0)
                label->setPixmap(QPixmap(":/pic/B5.png"));
        else if (Color ==1)
                 label->setPixmap(QPixmap(":/pic/G5.png"));
        else if(Color ==2)
                 label->setPixmap(QPixmap(":/pic/O5.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R5.png"));
        break;
    case 6:
        if(Color == 0)
                label->setPixmap(QPixmap(":/pic/B6.png"));
        else if (Color ==1)
                 label->setPixmap(QPixmap(":/pic/G6.png"));
        else if(Color ==2)
                 label->setPixmap(QPixmap(":/pic/O6.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R6.png"));
        break;
    case 7:
        if(Color == 0)
                label->setPixmap(QPixmap(":/pic/B7.png"));
        else if (Color ==1)
                 label->setPixmap(QPixmap(":/pic/G7.png"));
        else if(Color ==2)
                 label->setPixmap(QPixmap(":/pic/O7.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R7.png"));
        break;
    case 8:
        if(Color == 0)
                label->setPixmap(QPixmap(":/pic/B8.png"));
        else if (Color ==1)
                 label->setPixmap(QPixmap(":/pic/G8.png"));
        else if(Color ==2)
                 label->setPixmap(QPixmap(":/pic/O8.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R8.png"));
        break;
    case 9:
        if(Color == 0)
                label->setPixmap(QPixmap(":/pic/B9.png"));
        else if (Color ==1)
                 label->setPixmap(QPixmap(":/pic/G9.png"));
        else if(Color ==2)
                 label->setPixmap(QPixmap(":/pic/O9.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R9.png"));
        break;
    default:
        exist =false;
        level =-1;
        color = -1;
        label->clear();
        label->setStyleSheet("border:1px solid;");
        break;
    }
}

void Board::appear(int Level,int Color){
    exist =true;
    level =Level;
    color=Color;
    switch(level){
    case 0:
        if(color == 0)
                label->setPixmap(QPixmap(":/pic/B0.png"));
        else if (color ==1)
                 label->setPixmap(QPixmap(":/pic/G0.png"));
        else if(color ==2)
                 label->setPixmap(QPixmap(":/pic/O0.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R0.png"));
        break;
    case 1:
        if(color == 0)
                label->setPixmap(QPixmap(":/pic/B1.png"));
        else if (color ==1)
                 label->setPixmap(QPixmap(":/pic/G1.png"));
        else if(color ==2)
                 label->setPixmap(QPixmap(":/pic/O1.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R1.png"));
        break;
    case 2:
        if(color == 0)
                label->setPixmap(QPixmap(":/pic/B2.png"));
        else if (color ==1)
                 label->setPixmap(QPixmap(":/pic/G2.png"));
        else if(color ==2)
                 label->setPixmap(QPixmap(":/pic/O2.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R2.png"));
        break;
    case 3:
        if(color == 0)
                label->setPixmap(QPixmap(":/pic/B3.png"));
        else if (color ==1)
                 label->setPixmap(QPixmap(":/pic/G3.png"));
        else if(color ==2)
                 label->setPixmap(QPixmap(":/pic/O3.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R3.png"));
        break;
    case 4:
        if(color == 0)
                label->setPixmap(QPixmap(":/pic/B4.png"));
        else if (color ==1)
                 label->setPixmap(QPixmap(":/pic/G4.png"));
        else if(color ==2)
                 label->setPixmap(QPixmap(":/pic/O4.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R4.png"));
        break;
    case 5:
        if(color == 0)
                label->setPixmap(QPixmap(":/pic/B5.png"));
        else if (color ==1)
                 label->setPixmap(QPixmap(":/pic/G5.png"));
        else if(color ==2)
                 label->setPixmap(QPixmap(":/pic/O5.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R5.png"));
        break;
    case 6:
        if(color == 0)
                label->setPixmap(QPixmap(":/pic/B6.png"));
        else if (color ==1)
                 label->setPixmap(QPixmap(":/pic/G6.png"));
        else if(color ==2)
                 label->setPixmap(QPixmap(":/pic/O6.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R6.png"));
        break;
    case 7:
        if(color == 0)
                label->setPixmap(QPixmap(":/pic/B7.png"));
        else if (color ==1)
                 label->setPixmap(QPixmap(":/pic/G7.png"));
        else if(color ==2)
                 label->setPixmap(QPixmap(":/pic/O7.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R7.png"));
        break;
    case 8:
        if(color == 0)
                label->setPixmap(QPixmap(":/pic/B8.png"));
        else if (color ==1)
                 label->setPixmap(QPixmap(":/pic/G8.png"));
        else if(color ==2)
                 label->setPixmap(QPixmap(":/pic/O8.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R8.png"));
        break;
    case 9:
        if(color == 0)
                label->setPixmap(QPixmap(":/pic/B9.png"));
        else if (color ==1)
                 label->setPixmap(QPixmap(":/pic/G9.png"));
        else if(color ==2)
                 label->setPixmap(QPixmap(":/pic/O9.png"));
         else
                 label->setPixmap(QPixmap(":/pic/R9.png"));
        break;
    }
}

void Board::disappear(){
    exist =false;
    level =-1;
    color =-1;
    label->clear();
    label->setStyleSheet("border:1px solid;");
}

void Board::overlape(int Level1,int Level2,int Color1,int Color2){
    if(Color1 ==Color2 || Level1 ==Level2){
            int Level =Level1+Level2;
            if (Level ==0){
                level=Level+1;
                color=Color1;
                pics(level,color);
             }
            else{
                level=Level;
                color=Color1;
                pics(level,color);

            }
    }
    /*
    else if(Level1 == Level2){
            Level =Level1+Level2;
            if (Level ==0){
                pics(Level,Color1);
                level=Level+1;
                color=Color1;
             }
            else{
                pics(Level,Color1);
                level=Level;
                color=Color1;
            }
    }
    */



            /*
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
            */

}


int Board::showlevel(){
    return level;
}

int Board::showcolor(){
    return color;
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
