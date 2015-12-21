#include "graphgenerator.h"

GraphGenerator::GraphGenerator(GraphController* graphController) :
    _graphController(graphController) {}

void GraphGenerator::generate(int vertices)
{
    _graphController->clear();
    QString id;

    for (int i = 0; i < vertices; ++i) {
        id = _graphController->suggestedId();
        _graphController->addVertex();
        _graphController->completeConnectVertex(id);
    }
}
