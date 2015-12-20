#ifndef KERNIGHANLIN_H
#define KERNIGHANLIN_H

#include "algorythm.h"
#include "graph.h"

class KernighanLin : public Algorythm
{
    Graph* _graph;

public:
    KernighanLin(Graph* graph);
};

#endif // KERNIGHANLIN_H
