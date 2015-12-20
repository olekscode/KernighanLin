#ifndef KERNIGHANLIN_H
#define KERNIGHANLIN_H

#include <QHash>

#include "algorythm.h"
#include "graph.h"
#include "vertex.h"

class KernighanLin : public Algorythm
{
    Graph* _graph;

public:
    KernighanLin(Graph* graph);

    int internalCost(Vertex v) const;
    int externalCost(Vertex v) const;

    int D(Vertex v) const;
    int reduction(Vertex a, Vertex b) const;

    void run();
};

#endif // KERNIGHANLIN_H
