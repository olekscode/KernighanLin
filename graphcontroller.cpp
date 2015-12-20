#include "graphcontroller.h"

GraphController::GraphController()
{
    _graph = new Graph();
}

GraphController::~GraphController()
{
    delete _graph;
}

Graph* GraphController::graph() const
{
    return _graph;
}

void GraphController::addVertex(QString id)
{
    _graph->addVertex(id);
}

void GraphController::addEdge(QString id1, QString id2, weight_t weight)
{
    _graph->connect(id1, id2, weight);
}
