#include "graphdrawer.h"

GraphDrawer::GraphDrawer(Graph* graph) :
    _graph(graph)
{
    _vertex_diameter = 10;
    _scale = 100;

    _vertex_outline_pen = QPen(QBrush(QColor(0, 0, 0)), 3);
    _edge_pen = QPen(QColor(255, 0, 0));
}

void GraphDrawer::draw()
{

}

void GraphDrawer::drawVertex(QString id)
{
    Vertex v = (*_graph)[id];
    qreal x = v.x() - _vertex_diameter / 2;
    qreal y = v.y() - _vertex_diameter / 2;

    this->addEllipse(x, y,
                     _vertex_diameter, _vertex_diameter,
                     _vertex_outline_pen, QBrush(v.color()));

    this->addText(id);
}

void GraphDrawer::drawEdge(QString id1, QString id2)
{
    Vertex v1 = (*_graph)[id1];
    Vertex v2 = (*_graph)[id2];

    this->addLine(v1.x(), v1.y(), v2.x(), v2.y(), _edge_pen);
}
