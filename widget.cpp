#include "widget.h"

#include <QMouseEvent>
#include <QPainter>

Widget::Widget()
        : startPoint({-1, -1})
        , endPoint({-1, -1})
{
        setMouseTracking(true);
}

void Widget::paintEvent(QPaintEvent* e)
{
        QPainter painter(this);
        
		for (const auto& it : lines) {
			painter.drawLine(it);
            //painter.drawPoint(it);
		}
        QPen p(Qt::red);
        painter.setPen(p);
		/* if (startPoint != QPoint{-1, -1}) {
				 painter.drawLine(QLine(startPoint, endPoint));
		 }*/
}

void Widget::mouseMoveEvent(QMouseEvent* e)
{
        if (startPoint != QPoint{-1, -1} && e->buttons() == Qt::LeftButton) {
                endPoint = e->pos();
				//point.push_back(endPoint);
                lines.push_back({ startPoint, endPoint });
                startPoint = endPoint;
                update();
        }
        else
        {
			startPoint = QPoint{ -1, -1 };
			endPoint = QPoint{ -1, -1 };
        }

}

void Widget::mousePressEvent(QMouseEvent* e)
{
        if (startPoint == QPoint{-1, -1}) {
                startPoint = e->pos();
        } else {
                endPoint = e->pos();
                //point.push_back(endPoint);
				lines.push_back({ startPoint, endPoint });
				startPoint = endPoint;
        }
}
void Widget::keyPressEvent(QKeyEvent* e)
{
        if (e->key() == Qt::Key_C) {
                lines.clear();
                startPoint = QPoint{-1, -1};
                endPoint = QPoint{-1, -1};
                update();
        }
}


