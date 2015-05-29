#ifndef BOARD_H
#define BOARD_H
#include <QObject>
#include <QLabel>
#include <QPushButton>



class Board:public QObject
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent, bool exist, int Row, int Col,int Level,int Color);
    ~Board();
    void init();
    void appear( int Level,int Color);
    void disappear( );
    void overlape(int Level1,int Level2,int Color1,int Color2);
    bool doexist();
    void pics(int Level,int Color);

    int showlevel();
    int showcolor();
signals:
 //   void Click(int row,int col,char symbol);

public slots:
 //   void click();

private:
   QLabel *label;
    QPushButton *button;
    int row,col,level,color;
    bool exist;
    bool clicked;

};

#endif // BOARD_H
