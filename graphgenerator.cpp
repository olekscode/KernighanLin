#include "graphgenerator.h"

GraphGenerator::GraphGenerator(GraphController* graphController) :
    _graphController(graphController) {}

void GraphGenerator::generate(int vertices, int edges)
{
    for (int i = 0; i < vertices; ++i) {
        _graphController->addVertex();
    }
}
