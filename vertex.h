#ifndef VERTEX_H
#define VERTEX_H

#include <QColor>

class Vertex
{
    QColor _color;
    int _x;
    int _y;

public:
    Vertex();

    QColor color() const;
    void setColor(QColor color);

    int x() const;
    int y() const;

    void setX(int x);
    void setY(int y);
};

#endif // VERTEX_H
