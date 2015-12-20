#ifndef GRAPHDRAWER_H
#define GRAPHDRAWER_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>

#include "graph.h"
#include "vertex.h"

class GraphDrawer : public QGraphicsScene
{
    Graph* _graph;

    qreal _vertex_diameter;
    qreal _scale;

    QPen _vertex_outline_pen;
    QPen _edge_pen;

public:
    GraphDrawer(Graph* graph);

    GraphDrawer(const GraphDrawer& other);
    GraphDrawer& operator= (const GraphDrawer& other);

    void draw();

    void drawVertex(QString id);
    void drawEdge(QString id1, QString id2);
};

#endif // GRAPHDRAWER_H
