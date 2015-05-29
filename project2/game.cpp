#include "game.h"
#include "board.h"
#include "result.h"
#include "ui_game.h"
#include <stdlib.h>
#include <time.h>
#include <QKeyEvent>

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
}

game::game(QWidget *parent,result* res) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    mainWindow=parent;
    resWindow=res;
    int score =0;

    int i , j;
    int level=-1,color =0;
    srand((unsigned)time(NULL));
    bool exist =false;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
           board[i][j]=new Board(this,exist,i,j,level,color);
        }
    }
    i = rand() % 4;
    j = rand() % 4;
    ui->label_2->setText(QString::number(score));
    board[i][j]->init();
}

game::~game()
{
    delete ui;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            delete board[i][j];
        }
    }
}

bool game::checkfull(){
    int full=0;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if (board[i][j]->doexist()==true)
                full++;
        }
    }
    if(full ==16)
        return true;
    else
        return false;
}

void game::checkthesame(QKeyEvent *event){
    switch(event->key())
    {
        case Qt::Key_Left:
               for(int i=0;i<4;i++)
               {
                    if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1&&board[i][3]->showlevel()!=-1){
                             if((board[i][0]->showlevel()==board[i][1]->showlevel())&&(board[i][3]->showlevel()==board[i][4]->showlevel())){
                                 board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                                 board[i][1]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel());
                                 board[i][2]->disappear();
                                 board[i][3]->disappear();
                             }
                             else if((board[i][0]->showlevel()==board[i][1]->showlevel())&&(board[i][3]->showlevel()!=board[i][4]->showlevel())){
                                 board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                                 board[i][1]->appear(board[i][2]->showlevel());
                                 board[i][2]->appear(board[i][3]->showlevel());
                                 board[i][3]->disappear();
                             }
                             else if((board[i][1]->showlevel()==board[i][2]->showlevel())){
                                 board[i][1]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel());
                                 board[i][2]->appear(board[i][3]->showlevel());
                                 board[i][3]->disappear();
                             }
                             else if((board[i][2]->showlevel()==board[i][3]->showlevel())){
                                board[i][2]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel());
                                board[i][3]->disappear();
                             }
                   }
                   else if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1){
                           if((board[i][0]->showlevel()==board[i][1]->showlevel())){
                               board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                               board[i][1]->appear(board[i][2]->showlevel());
                               board[i][2]->disappear();
                           }
                           else  if((board[i][1]->showlevel()==board[i][2]->showlevel())){
                               board[i][1]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel());
                               board[i][2]->disappear();
                           }
                   }
                   else if(board[i][0]->showlevel()!=-1 && board[i][1]->showlevel()!=-1  && (board[i][0]->showlevel() == board[i][1]->showlevel())    ){
                           board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                           board[i][1]->disappear();
                   }
              }
        case Qt::Key_Right:
               for(int i=0;i<4;i++)
               {
                    if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1&&board[i][3]->showlevel()!=-1){
                             if((board[i][0]->showlevel()==board[i][1]->showlevel())&&(board[i][3]->showlevel()==board[i][4]->showlevel())){
                                 board[i][3]->overlape(board[i][3]->showlevel(),board[i][2]->showlevel());
                                 board[i][2]->overlape(board[i][1]->showlevel(),board[i][0]->showlevel());
                                 board[i][1]->disappear();
                                 board[i][0]->disappear();
                             }
                             else if((board[i][0]->showlevel()==board[i][1]->showlevel())&&(board[i][3]->showlevel()!=board[i][4]->showlevel())){
                                 board[i][1]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                                 board[i][0]->disappear();
                             }
                             else if((board[i][1]->showlevel()==board[i][2]->showlevel())){
                                 board[i][2]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel());
                                 board[i][1]->appear(board[i][0]->showlevel());
                                 board[i][0]->disappear();
                             }
                             else if((board[i][2]->showlevel()==board[i][3]->showlevel())){
                                board[i][3]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel());
                                board[i][2]->appear(board[i][1]->showlevel());
                                board[i][1]->appear(board[i][0]->showlevel());
                                board[i][0]->disappear();
                             }
                   }
                   else if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1){
                           if((board[i][2]->showlevel()==board[i][3]->showlevel())){
                               board[i][3]->overlape(board[i][3]->showlevel(),board[i][2]->showlevel());
                               board[i][2]->appear(board[i][1]->showlevel());
                               board[i][1]->disappear();
                           }
                           else  if((board[i][1]->showlevel()==board[i][2]->showlevel())){
                               board[i][2]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel());
                               board[i][1]->disappear();
                           }
                   }
                   else if(board[i][2]->showlevel()!=-1 && board[i][3]->showlevel()!=-1  && (board[i][2]->showlevel() == board[i][3]->showlevel())    ){
                           board[i][3]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel());
                           board[i][2]->disappear();
                   }
              }

        case Qt::Key_Up:
               for(int i=0;i<4;i++)
               {
                    if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1&&board[i][3]->showlevel()!=-1){
                             if((board[i][0]->showlevel()==board[i][1]->showlevel())&&(board[i][3]->showlevel()==board[i][4]->showlevel())){
                                 board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                                 board[i][1]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel());
                                 board[i][2]->disappear();
                                 board[i][3]->disappear();
                             }
                             else if((board[i][0]->showlevel()==board[i][1]->showlevel())&&(board[i][3]->showlevel()!=board[i][4]->showlevel())){
                                 board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                                 board[i][1]->appear(board[i][2]->showlevel());
                                 board[i][2]->appear(board[i][3]->showlevel());
                                 board[i][3]->disappear();
                             }
                             else if((board[i][1]->showlevel()==board[i][2]->showlevel())){
                                 board[i][1]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel());
                                 board[i][2]->appear(board[i][3]->showlevel());
                                 board[i][3]->disappear();
                             }
                             else if((board[i][2]->showlevel()==board[i][3]->showlevel())){
                                board[i][2]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel());
                                board[i][3]->disappear();
                             }
                   }
                   else if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1){
                           if((board[i][0]->showlevel()==board[i][1]->showlevel())){
                               board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                               board[i][1]->appear(board[i][2]->showlevel());
                               board[i][2]->disappear();
                           }
                           else  if((board[i][1]->showlevel()==board[i][2]->showlevel())){
                               board[i][1]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel());
                               board[i][2]->disappear();
                           }
                   }
                   else if(board[i][0]->showlevel()!=-1 && board[i][1]->showlevel()!=-1  && (board[i][0]->showlevel() == board[i][1]->showlevel())    ){
                           board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                           board[i][1]->disappear();
                   }
              }
        case Qt::Key_Down:
               for(int i=0;i<4;i++)
               {
                    if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1&&board[i][3]->showlevel()!=-1){
                             if((board[i][0]->showlevel()==board[i][1]->showlevel())&&(board[i][3]->showlevel()==board[i][4]->showlevel())){
                                 board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                                 board[i][1]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel());
                                 board[i][2]->disappear();
                                 board[i][3]->disappear();
                             }
                             else if((board[i][0]->showlevel()==board[i][1]->showlevel())&&(board[i][3]->showlevel()!=board[i][4]->showlevel())){
                                 board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                                 board[i][1]->appear(board[i][2]->showlevel());
                                 board[i][2]->appear(board[i][3]->showlevel());
                                 board[i][3]->disappear();
                             }
                             else if((board[i][1]->showlevel()==board[i][2]->showlevel())){
                                 board[i][1]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel());
                                 board[i][2]->appear(board[i][3]->showlevel());
                                 board[i][3]->disappear();
                             }
                             else if((board[i][2]->showlevel()==board[i][3]->showlevel())){
                                board[i][2]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel());
                                board[i][3]->disappear();
                             }
                   }
                   else if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1){
                           if((board[i][0]->showlevel()==board[i][1]->showlevel())){
                               board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                               board[i][1]->appear(board[i][2]->showlevel());
                               board[i][2]->disappear();
                           }
                           else  if((board[i][1]->showlevel()==board[i][2]->showlevel())){
                               board[i][1]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel());
                               board[i][2]->disappear();
                           }
                   }
                   else if(board[i][0]->showlevel()!=-1 && board[i][1]->showlevel()!=-1  && (board[i][0]->showlevel() == board[i][1]->showlevel())    ){
                           board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel());
                           board[i][1]->disappear();
                   }
              }


    }
}

void game::keyPressEvent(QKeyEvent *event){
    srand((unsigned)time(NULL));
    if(checkfull()==false){
                switch(event->key())
                {
                  case Qt::Key_Left:
                    for(int k =0;k<3;k++){
                        for(int i=0;i<4;++i){
                            for(int j=3;j>0;--j){
                               if (board[i][j-1]->doexist() == false && board[i][j]->doexist()==true){
                                    board[i][j-1]->appear(board[i][j]->showlevel());
                                    board[i][j]->disappear();
                               }
                            }
                        }
                    }
                    checkthesame(event);
                    do{
                        int i = rand() % 4;
                        int j = rand() % 4;
                        if(board[i][j]->doexist() ==false){
                            board[i][j]->init();
                            break;
                        }
                    }while(true);
                    break;
                  case Qt::Key_Right:
                    for(int k =0;k<3;k++){
                        for(int i=0;i<4;++i){
                            for(int j=0;j<3;++j){
                               if (board[i][j+1]->doexist() == false && board[i][j]->doexist()==true){
                                    board[i][j+1]->appear(board[i][j]->showlevel());
                                    board[i][j]->disappear();
                               }
                            }
                        }
                    }
                    checkthesame(event);
                    do{
                        int i = rand() % 4;
                        int j = rand() % 4;
                        if(board[i][j]->doexist() ==false){
                            board[i][j]->init();
                            break;
                        }
                    }while(true);
                    break;
                  case Qt::Key_Up:
                    for(int k =0;k<3;k++){
                        for(int j=0;j<4;++j){
                            for(int i=3;i>0;--i){
                               if (board[i-1][j]->doexist() == false && board[i][j]->doexist()==true){
                                    board[i-1][j]->appear(board[i][j]->showlevel());
                                    board[i][j]->disappear();
                               }
                            }
                        }
                    }
                    checkthesame(event);
                    do{
                        int i = rand() % 4;
                        int j = rand() % 4;
                        if(board[i][j]->doexist() ==false){
                            board[i][j]->init();
                            break;
                        }
                    }while(true);
                    break;
                  case Qt::Key_Down:
                    for(int k =0;k<3;k++){
                        for(int j=0;j<4;++j){
                            for(int i=0;i<3;++i){
                               if (board[i+1][j]->doexist() == false && board[i][j]->doexist()==true){
                                    board[i+1][j]->appear(board[i][j]->showlevel());
                                    board[i][j]->disappear();
                               }
                            }
                        }
                    }
                    checkthesame(event);
                    do{
                        int i = rand() % 4;
                        int j = rand() % 4;
                        if(board[i][j]->doexist() ==false){
                            board[i][j]->init();
                            break;
                        }
                    }while(true);
                     break;
                }
        }
 }



void game::on_pushButton_clicked()
{
         emit reset();

         for(int i=0;i<4;++i){
             for(int j=0;j<4;++j){
                board[i][j]->disappear();
             }
         }

         int i = rand() % 4;
         int j = rand() % 4;
         ui->label_2->setText("0");
         board[i][j]->init();
}
