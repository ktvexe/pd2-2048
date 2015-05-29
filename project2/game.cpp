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
     score =0;

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
    if(full ==16){
        for(int i=0;i<4;i++){
            for(int j =0;j<3;j++){
                if(checkcolorlevel(i,j,i,j+1))
                    return false;
            }
        }
        for(int j=0;j<4;j++){
            for(int i =0;i<3;i++){
                if(checkcolorlevel(i,j,i+1,j))
                    return false;
            }
        }
         return true;
   }
    else
        return false;
}

bool game:: checkcolorlevel(int i1,int j1,int i2,int j2){
    if((board[i1][j1]->showcolor()==board[i2][j2]->showcolor())){
    //     if((board[i1][j1]->showlevel()==board[i2][j2]->showlevel())&&(board[i1][j1]->showcolor()==board[i2][j2]->showcolor())){
        return true;
    }
    else
        return false;
}

void game::addscore(int *Score,int Level1,int Level2)
{   if((Level1+Level2) ==0)
            *Score+=(Level1+Level2+1);
    else if((Level1+Level2==10))
            *Score+=(Level1+Level2+30);
    else
            *Score+=(Level1+Level2);
}

void game::checkthesame(QKeyEvent *event){
    switch(event->key())
    {
        case Qt::Key_Left:
               for(int i=0;i<4;i++)
               {
                    if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1&&board[i][3]->showlevel()!=-1){         //four elements
                             if((checkcolorlevel(i,0,i,1))&&(checkcolorlevel(i,2,i,3))){                        //all the same
                                 addscore(&score,board[i][0]->showlevel(),board[i][1]->showlevel());
                                 board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel(),board[i][0]->showcolor(),board[i][1]->showcolor());
                                 addscore(&score,board[i][2]->showlevel(),board[i][3]->showlevel());
                                 board[i][1]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel(),board[i][2]->showcolor(),board[i][3]->showcolor());

                                 board[i][2]->disappear();
                                 board[i][3]->disappear();

                             }
                             else if((checkcolorlevel(i,0,i,1))&&!(checkcolorlevel(i,2,i,3))){               //left two the same
                                 addscore(&score,board[i][0]->showlevel(),board[i][1]->showlevel());
                                 board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel(),board[i][0]->showcolor(),board[i][1]->showcolor());
                                 board[i][1]->appear(board[i][2]->showlevel(),board[i][2]->showcolor());
                                 board[i][2]->appear(board[i][3]->showlevel(),board[i][3]->showcolor());
                                 board[i][3]->disappear();


                             }
                             else if(checkcolorlevel(i,1,i,2)){                                                                                                         //mid two the same
                                 addscore(&score,board[i][1]->showlevel(),board[i][2]->showlevel());
                                 board[i][1]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel(),board[i][1]->showcolor(),board[i][2]->showcolor());
                                 board[i][2]->appear(board[i][3]->showlevel(),board[i][3]->showcolor());
                                 board[i][3]->disappear();

                             }
                             else if((checkcolorlevel(i,2,i,3))){                                                                                                     //right two the same
                                addscore(&score,board[i][2]->showlevel(),board[i][3]->showlevel());
                                board[i][2]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel(),board[i][2]->showcolor(),board[i][3]->showcolor());
                                board[i][3]->disappear();

                             }
                   }
                   else if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1){                                           //three elements
                           if(checkcolorlevel(i,0,i,1)){                                                                                                            //left two the same
                               addscore(&score,board[i][0]->showlevel(),board[i][1]->showlevel());
                               board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel(),board[i][0]->showcolor(),board[i][1]->showcolor());
                               board[i][1]->appear(board[i][2]->showlevel(),board[i][2]->showcolor());
                               board[i][2]->disappear();


                           }
                           else  if(checkcolorlevel(i,1,i,2)){                                                                                              //right two the same
                               addscore(&score,board[i][1]->showlevel(),board[i][2]->showlevel());
                               board[i][1]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel(),board[i][1]->showcolor(),board[i][2]->showcolor());
                               board[i][2]->disappear();
                            }
                   }
                   else if(board[i][0]->showlevel()!=-1 && board[i][1]->showlevel()!=-1  && (checkcolorlevel(i,0,i,1))    ){        //two left elements are the same
                           addscore(&score,board[i][0]->showlevel(),board[i][1]->showlevel());
                           board[i][0]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel(),board[i][0]->showcolor(),board[i][1]->showcolor());
                           board[i][1]->disappear();

                   }
              }
               ui->label_2->setText(QString::number(score));
        break;
        case Qt::Key_Right:
               for(int i=0;i<4;i++)
               {
                    if(board[i][0]->showlevel()!=-1&&board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1&&board[i][3]->showlevel()!=-1){             //four elements
                             if((checkcolorlevel(i,0,i,1))&&(checkcolorlevel(i,2,i,3))){                            //all the same
                                addscore(&score,board[i][3]->showlevel(),board[i][2]->showlevel());
                                 board[i][3]->overlape(board[i][3]->showlevel(),board[i][2]->showlevel(),board[i][3]->showcolor(),board[i][2]->showcolor());
                                 addscore(&score,board[i][1]->showlevel(),board[i][0]->showlevel());
                                 board[i][2]->overlape(board[i][1]->showlevel(),board[i][0]->showlevel(),board[i][1]->showcolor(),board[i][0]->showcolor());

                                 board[i][1]->disappear();
                                 board[i][0]->disappear();
                             }
                             else if((checkcolorlevel(i,0,i,1))&&!(checkcolorlevel(i,2,i,3))){                   //left two the same
                                 addscore(&score,board[i][0]->showlevel(),board[i][1]->showlevel());
                                 board[i][1]->overlape(board[i][0]->showlevel(),board[i][1]->showlevel(),board[i][0]->showcolor(),board[i][1]->showcolor());
                                 board[i][0]->disappear();
                             }
                             else if(checkcolorlevel(i,1,i,2)){                                                                                                             //mid two the same
                                 addscore(&score,board[i][1]->showlevel(),board[i][2]->showlevel());
                                 board[i][2]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel(),board[i][1]->showcolor(),board[i][2]->showcolor());

                                 board[i][1]->appear(board[i][0]->showlevel(),board[i][0]->showcolor());
                                 board[i][0]->disappear();
                             }
                             else if(checkcolorlevel(i,2,i,3)){                                                                                                         //right two the same
                                addscore(&score,board[i][2]->showlevel(),board[i][3]->showlevel());
                                 board[i][3]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel(),board[i][2]->showcolor(),board[i][3]->showcolor());

                                board[i][2]->appear(board[i][1]->showlevel(),board[i][1]->showcolor());
                                board[i][1]->appear(board[i][0]->showlevel(),board[i][0]->showcolor());
                                board[i][0]->disappear();
                             }
                   }
                   else if(board[i][1]->showlevel()!=-1&&board[i][2]->showlevel()!=-1&&board[i][3]->showlevel()!=-1){                                                   //three elements
                           if(checkcolorlevel(i,2,i,3)){                                                                                                                //right two the same
                               addscore(&score,board[i][3]->showlevel(),board[i][2]->showlevel());
                               board[i][3]->overlape(board[i][3]->showlevel(),board[i][2]->showlevel(),board[i][3]->showcolor(),board[i][2]->showcolor());

                               board[i][2]->appear(board[i][1]->showlevel(),board[i][1]->showcolor());
                               board[i][1]->disappear();
                           }
                           else  if(checkcolorlevel(i,1,i,2)){                                                                                                  //left two the same
                               addscore(&score,board[i][1]->showlevel(),board[i][2]->showlevel());
                               board[i][2]->overlape(board[i][1]->showlevel(),board[i][2]->showlevel(),board[i][1]->showcolor(),board[i][2]->showcolor());

                               board[i][1]->disappear();
                           }
                   }
                   else if(board[i][2]->showlevel()!=-1 && board[i][3]->showlevel()!=-1  && (checkcolorlevel(i,2,i,3))    ){        //two right elements are the same
                           addscore(&score,board[i][2]->showlevel(),board[i][3]->showlevel());
                            board[i][3]->overlape(board[i][2]->showlevel(),board[i][3]->showlevel(),board[i][2]->showcolor(),board[i][3]->showcolor());
                            board[i][2]->disappear();
                   }
              }
               ui->label_2->setText(QString::number(score));
        break;
        case Qt::Key_Up:
               for(int j=0;j<4;j++)
               {
                    if(board[0][j]->showlevel()!=-1&&board[1][j]->showlevel()!=-1&&board[2][j]->showlevel()!=-1&&board[3][j]->showlevel()!=-1){         //four elements
                             if((checkcolorlevel(0,j,1,j))&&(checkcolorlevel(2,j,3,j))){                        //all the same
                                 addscore(&score,board[0][j]->showlevel(),board[1][j]->showlevel());
                                 board[0][j]->overlape(board[0][j]->showlevel(),board[1][j]->showlevel(),board[0][j]->showcolor(),board[1][j]->showcolor());
                                 addscore(&score,board[2][j]->showlevel(),board[3][j]->showlevel());
                                 board[1][j]->overlape(board[2][j]->showlevel(),board[3][j]->showlevel(),board[2][j]->showcolor(),board[3][j]->showcolor());

                                 board[2][j]->disappear();
                                 board[3][j]->disappear();
                             }
                             else if((checkcolorlevel(0,j,1,j))&&!(checkcolorlevel(2,j,3,j))){               //up two the same
                                 addscore(&score,board[0][j]->showlevel(),board[1][j]->showlevel());
                                 board[0][j]->overlape(board[0][j]->showlevel(),board[1][j]->showlevel(),board[0][j]->showcolor(),board[1][j]->showcolor());

                                 board[1][j]->appear(board[2][j]->showlevel(),board[2][j]->showcolor());
                                 board[2][j]->appear(board[3][j]->showlevel(),board[3][j]->showcolor());
                                 board[3][j]->disappear();
                             }
                             else if((checkcolorlevel(1,j,2,j))){                                                                                                     //mid two the same
                                 addscore(&score,board[1][j]->showlevel(),board[2][j]->showlevel());
                                 board[1][j]->overlape(board[1][j]->showlevel(),board[2][j]->showlevel(),board[1][j]->showcolor(),board[2][j]->showcolor());

                                 board[2][j]->appear(board[3][j]->showlevel(),board[3][j]->showcolor());
                                 board[3][j]->disappear();
                             }
                             else if(checkcolorlevel(2,j,3,j)){                                                                                                 //down two the same
                                addscore(&score,board[2][j]->showlevel(),board[3][j]->showlevel());
                                 board[2][j]->overlape(board[2][j]->showlevel(),board[3][j]->showlevel(),board[2][j]->showcolor(),board[3][j]->showcolor());

                                board[3][j]->disappear();
                             }
                   }
                   else if(board[0][j]->showlevel()!=-1&&board[1][j]->showlevel()!=-1&&board[2][j]->showlevel()!=-1){                                           //three elements
                           if((checkcolorlevel(0,j,1,j))){                                                                                                        //up two the same
                               addscore(&score,board[0][j]->showlevel(),board[1][j]->showlevel());
                               board[0][j]->overlape(board[0][j]->showlevel(),board[1][j]->showlevel(),board[0][j]->showcolor(),board[1][j]->showcolor());

                               board[1][j]->appear(board[2][j]->showlevel(),board[2][j]->showcolor());
                               board[2][j]->disappear();
                           }
                           else  if((checkcolorlevel(1,j,2,j))){                                                                                                  //down two the same
                                addscore(&score,board[1][j]->showlevel(),board[2][j]->showlevel());
                               board[1][j]->overlape(board[1][j]->showlevel(),board[2][j]->showlevel(),board[1][j]->showcolor(),board[2][j]->showcolor());

                               board[2][j]->disappear();
                           }
                   }
                   else if(board[0][j]->showlevel()!=-1 && board[1][j]->showlevel()!=-1  && (checkcolorlevel(0,j,1,j))    ){            //two elements are the same
                           addscore(&score,board[0][j]->showlevel(),board[1][j]->showlevel());
                            board[0][j]->overlape(board[0][j]->showlevel(),board[1][j]->showlevel(),board[0][j]->showcolor(),board[1][j]->showcolor());

                           board[1][j]->disappear();
                   }
              }
               ui->label_2->setText(QString::number(score));
        break;
        case Qt::Key_Down:
               for(int j=0;j<4;j++)
               {
                    if(board[0][j]->showlevel()!=-1&&board[1][j]->showlevel()!=-1&&board[2][j]->showlevel()!=-1&&board[3][j]->showlevel()!=-1){             //four elements
                             if((checkcolorlevel(3,j,2,j))&&(checkcolorlevel(1,j,0,j))){                        //all the same
                                 addscore(&score,board[3][j]->showlevel(),board[2][j]->showlevel());
                                 board[3][j]->overlape(board[3][j]->showlevel(),board[2][j]->showlevel(),board[3][j]->showcolor(),board[2][j]->showcolor());
                                 addscore(&score,board[1][j]->showlevel(),board[0][j]->showlevel());
                                 board[2][j]->overlape(board[1][j]->showlevel(),board[0][j]->showlevel(),board[1][j]->showcolor(),board[0][j]->showcolor());

                                 board[1][j]->disappear();
                                 board[0][j]->disappear();
                             }
                             else if((checkcolorlevel(2,j,3,j))&&!(checkcolorlevel(0,j,1,j))){               //down two the same
                                addscore(&score,board[3][j]->showlevel(),board[2][j]->showlevel());
                                 board[3][j]->overlape(board[3][j]->showlevel(),board[2][j]->showlevel(),board[3][j]->showcolor(),board[2][j]->showcolor());

                                 board[2][j]->appear(board[1][j]->showlevel(),board[1][j]->showcolor());
                                 board[1][j]->appear(board[0][j]->showlevel(),board[0][j]->showcolor());
                                 board[0][j]->disappear();
                             }
                             else if((checkcolorlevel(1,j,2,j))){                                                                                                     //mid the same
                                 addscore(&score,board[1][j]->showlevel(),board[2][j]->showlevel());
                                 board[2][j]->overlape(board[1][j]->showlevel(),board[2][j]->showlevel(),board[1][j]->showcolor(),board[2][j]->showcolor());

                                 board[1][j]->appear(board[0][j]->showlevel(),board[0][j]->showcolor());
                                 board[0][j]->disappear();
                             }
                             else if((checkcolorlevel(0,j,1,j))){                                                                                                     //up two the same
                                addscore(&score,board[0][j]->showlevel(),board[1][j]->showlevel());
                                 board[1][j]->overlape(board[0][j]->showlevel(),board[1][j]->showlevel(),board[0][j]->showcolor(),board[1][j]->showcolor());

                                board[0][j]->disappear();
                             }
                   }
                   else if(board[1][j]->showlevel()!=-1&&board[2][j]->showlevel()!=-1&&board[3][j]->showlevel()!=-1){                                           //three elements
                           if((checkcolorlevel(3,j,2,j))){                                                                                                        //down two the same
                               addscore(&score,board[3][j]->showlevel(),board[2][j]->showlevel());
                               board[3][j]->overlape(board[3][j]->showlevel(),board[2][j]->showlevel(),board[3][j]->showcolor(),board[2][j]->showcolor());

                               board[2][j]->appear(board[1][j]->showlevel(),board[1][j]->showcolor());
                               board[1][j]->disappear();
                           }
                           else  if((checkcolorlevel(1,j,2,j))){                                                                                           //up two the same
                               addscore(&score,board[1][j]->showlevel(),board[2][j]->showlevel());
                               board[2][j]->overlape(board[1][j]->showlevel(),board[2][j]->showlevel(),board[1][j]->showcolor(),board[2][j]->showcolor());

                               board[1][j]->disappear();
                           }
                   }
                   else if(board[2][j]->showlevel()!=-1 && board[3][j]->showlevel()!=-1  && (checkcolorlevel(2,j,3,j))    ){                //two elements are the same
                            addscore(&score,board[3][j]->showlevel(),board[2][j]->showlevel());
                            board[3][j]->overlape(board[3][j]->showlevel(),board[2][j]->showlevel(),board[3][j]->showcolor(),board[2][j]->showcolor());

                           board[2][j]->disappear();
                   }
         }
               ui->label_2->setText(QString::number(score));
        break;

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
                                    board[i][j-1]->appear(board[i][j]->showlevel(),board[i][j]->showcolor());
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
                                    board[i][j+1]->appear(board[i][j]->showlevel(),board[i][j]->showcolor());
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
                                    board[i-1][j]->appear(board[i][j]->showlevel(),board[i][j]->showcolor());
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
                                    board[i+1][j]->appear(board[i][j]->showlevel(),board[i][j]->showcolor());
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
        else    {
                result *resultwindow=new result();
                resultwindow->show();
        }
 }



void game::on_pushButton_clicked()
{
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
