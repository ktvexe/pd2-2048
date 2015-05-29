#ifndef RESULT_H
#define RESULT_H

#include <QWidget>

namespace Ui {
class result;
}

class result : public QWidget
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::result *ui;
     QWidget *mainWindow;
};

#endif // RESULT_H
