#ifndef VERTEX_H
#define VERTEX_H

#include <QColor>

// TEMPORARY
#include <stdlib.h> // rand
#include <time.h>   // time

// TODO: Make it a child of QObject

class Vertex
{
    QColor _color;
    qreal _x;
    qreal _y;

public:
    Vertex();

    QColor color() const;
    void setColor(QColor color);

    qreal x() const;
    qreal y() const;

    void setX(qreal x);
    void setY(qreal y);
};

#endif // VERTEX_H
