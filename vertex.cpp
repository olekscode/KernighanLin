#include "vertex.h"

Vertex::Vertex()
{
    _color.setRgb(255, 255, 255);
}

QColor Vertex::color() const
{
    return _color;
}

void Vertex::setColor(QColor color)
{
    _color = color;
}

int Vertex::x() const
{
    return _x;
}

int Vertex::y() const
{
    return _y;
}

void Vertex::setX(int x)
{
    _x = x;
}

void Vertex::setY(int y)
{
    _y = y;
}
