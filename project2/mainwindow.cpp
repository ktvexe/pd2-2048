#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "result.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

 //   connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(StartClick()));
  //  Gamewindow=NULL;
     resDialog = new result;
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void MainWindow::StartClick()
{
    Gamewindow=new Game(this,resDialog);
    connect(resDialog,SIGNAL(reset()),this,SLOT(resetGame()));
    this->setCentralWidget(Gamewindow);
}
*/
/*
void MainWindow::resetGame()
{
    resDialog->hide();
    if(Gamewindow!=NULL){
        delete Gamewindow;
    }
    Gamewindow=new Game(this,resDialog);
    this->setCentralWidget(Gamewindow);
}
*/

void MainWindow::on_pushButton_clicked()
{
    game *Gamewindow = new game(this,resDialog);
    Gamewindow->setFocus();
    Gamewindow->setFocusPolicy(Qt::StrongFocus);

  //  Gamewindow->show();
    this->setCentralWidget(Gamewindow);
   // Gamewindow->show();

}
