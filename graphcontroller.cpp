#include "graphcontroller.h"

GraphController::GraphController()
{
    _graph = new Graph();
    _id_counter = 1;
    srand(time(nullptr));
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

void GraphController::completeConnectVertex(QString id)
{
    foreach (QString id2, _graph->vertices().keys()) {
        if (id != id2) {
            _set_weight_from_dist(id, id2);
        }
    }
}

QString GraphController::suggestedId() const
{
    return QString("v") + QString::number(_id_counter);
}

void GraphController::clear()
{
    _graph->clear();
}

void GraphController::_set_weight_from_dist(QString id1, QString id2)
{
    Vertex v1 = (*_graph)[id1];
    Vertex v2 = (*_graph)[id2];

    qreal dist = sqrt(pow(v1.x() - v2.x(), 2) + pow(v1.y() - v2.y(), 2));
    _graph->connect(id1, id2, (int) dist);
}
