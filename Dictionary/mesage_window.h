#ifndef MESAGE_WINDOW_H
#define MESAGE_WINDOW_H
#include <QWidget>
#include<QPixmap>
#include<QPaintEvent>
#include<QPainter>
#include<QDialog>
class mesage_window: public QDialog
{
public:
mesage_window(QDialog *parent = nullptr);

private:
void paintEvent(QPaintEvent *e);


};

#endif // MESAGE_WINDOW_H
