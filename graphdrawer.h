#ifndef GRAPHDRAWER_H
#define GRAPHDRAWER_H

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QBrush>

#include "graph.h"

class GraphDrawer : public QGraphicsScene
{
    Graph* _graph;

public:
    GraphDrawer(Graph* graph);

    GraphDrawer(const GraphDrawer& other);
    GraphDrawer& operator= (const GraphDrawer& other);

    void draw();
};

#endif // GRAPHDRAWER_H
