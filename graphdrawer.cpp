#include "graphdrawer.h"

GraphDrawer::GraphDrawer(Graph* graph) :
    _graph(graph)
{
    _vertex_diameter = 10;
    _scale = 100;
    _label_offset = 0;

    _vertex_outline_pen = QPen(QBrush(QColor(0, 0, 0)), 2);
    _edge_pen = QPen(QColor(255, 0, 0));
}

void GraphDrawer::draw()
{
    this->clear();

    int n = 0;
    foreach (QString id, _graph->vertices().keys()) {
        auto iter = _graph->weights()[id].cbegin();
        for (int i = 0; i < n; ++i) {
            if (iter.value() != 0) {
                drawEdge(id, iter.key());
            }
            ++iter;
        }
        ++n;
    }

    foreach (QString id, _graph->vertices().keys()) {
        drawVertex(id);
    }
}

void GraphDrawer::drawVertex(QString id)
{
    Vertex v = (*_graph)[id];
    qreal x = v.x() - _vertex_diameter / 2;
    qreal y = v.y() - _vertex_diameter / 2;

    this->addEllipse(x, y,
                     _vertex_diameter, _vertex_diameter,
                     _vertex_outline_pen, QBrush(v.color()));

    this->addText(id)->setPos(v.x() + _label_offset, v.y() + _label_offset);
}

void GraphDrawer::drawEdge(QString id1, QString id2)
{
    Vertex v1 = (*_graph)[id1];
    Vertex v2 = (*_graph)[id2];

    this->addLine(v1.x(), v1.y(), v2.x(), v2.y(), _edge_pen);
}
