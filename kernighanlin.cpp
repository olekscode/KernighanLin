#include "kernighanlin.h"

KernighanLin::KernighanLin(Graph* graph)
{
    _graph = graph;
}

int KernighanLin::internalCost(Vertex v) const
{

}

int KernighanLin::externalCost(Vertex v) const
{

}

int KernighanLin::D(Vertex v) const
{
    return externalCost(v) - internalCost(v);
}

int KernighanLin::reduction(Vertex a, Vertex b) const
{
    // ERROR
    //return D(a) + D(b) - 2 * _graph->weightBetween(a, b);
}

void KernighanLin::run()
{

}
