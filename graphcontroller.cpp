#include "graphcontroller.h"

GraphController::GraphController()
{
    _graph = new Graph();
    _id_counter = 0;
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
    if (id.isEmpty()) {
        id = suggestedId();
    }

    // not a mistake (but still not clean)
    if (id == suggestedId()) {
        ++_id_counter;
    }

    _graph->addVertex(id);
}

void GraphController::addEdge(QString id1, QString id2, int weight)
{
    _graph->connect(id1, id2, weight);
}

QString GraphController::suggestedId() const
{
    return QString("v") + _id_counter;
}
