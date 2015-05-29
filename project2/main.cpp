#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w=new MainWindow;
//    game *Gamewindow =new game(w);
//    result *resDialog = new result;
//    game *Gamewindow = new game(w,resDialog);
 //   w->Gamewindow->setFocus();
    w->show();
 //   game *Gamewindow = new game(w,resDialog);
//    Gamewindow->setFocus();

    return a.exec();
}
