#ifndef GRAPHCONTROLLER_H
#define GRAPHCONTROLLER_H

#include "graph.h"

class GraphController
{
    Graph* _graph;

public:
    GraphController();
    ~GraphController();

    GraphController(const GraphController& other);
    GraphController& operator= (const GraphController& other);

    Graph* graph() const;

    void addVertex(QString id);
    void addEdge(QString id1, QString id2, weight_t weight);
};

#endif // GRAPHCONTROLLER_H
