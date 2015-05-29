#ifndef BOARD_H
#define BOARD_H
#include <QObject>
#include <QLabel>
#include <QPushButton>

enum Direction { UP, DOWN, LEFT, RIGHT };

class Board:public QObject
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent, bool exist, int Row, int Col,int Level,int Color);
    ~Board();
    void init();
  //  void reset();
    void keyPressEvent(QKeyEvent *event);
    void appear( int Level,int Color);
    void disappear( );
    void overlape(int Level1,int Level2);
    bool doexist();

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
