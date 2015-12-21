#include "vertex.h"

Vertex::Vertex()
{
    _color.setRgb(255, 255, 255);

    // TEMPORARY
    _x = rand() % 500;
    _y = rand() % 500;
}

QColor Vertex::color() const
{
    return _color;
}

void Vertex::setColor(QColor color)
{
    _color = color;
}

qreal Vertex::x() const
{
    return _x;
}

qreal Vertex::y() const
{
    return _y;
}

void Vertex::setX(qreal x)
{
    _x = x;
}

void Vertex::setY(qreal y)
{
    _y = y;
}
