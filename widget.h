#ifndef WIDGET_H
#define WIDGET_H

#include <QHBoxLayout>
#include <QWidget>
#include <QPoint>
#include <QVector>
#include <QTableWidget>

class QPaintEvent;
class QMouseEvent;
class QKeyEvent;

class Widget : public QWidget
{
public:
   Widget();

public:
   void paintEvent(QPaintEvent*) override;
   void mouseMoveEvent(QMouseEvent*) override;
   void mousePressEvent(QMouseEvent*) override;
   void keyPressEvent(QKeyEvent*) override;

private:

   QPoint startPoint;
   QPoint endPoint;
   QVector <QLine> lines;
   QVector <QPoint> point;

};

class Table : public QTableWidget
{
public:
    Table(){};
};


#endif // WIDGET_H
