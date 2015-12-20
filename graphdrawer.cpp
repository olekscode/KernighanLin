#include "graphdrawer.h"

GraphDrawer::GraphDrawer(Graph* graph) :
    _graph(graph)
{
    //this->setBackgroundBrush(QBrush(QColor(0, 0, 0)));

    this->addEllipse(0, 0, 10, 10,
                     QPen(QColor(0, 0, 0)));

    this->addEllipse(100, 100, 10, 10,
                     QPen(QColor(0, 0, 0)));
}

void GraphDrawer::draw()
{

}
