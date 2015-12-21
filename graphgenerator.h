#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H

#include <QObject>

#include "graphcontroller.h"

class GraphGenerator : public QObject
{
    Q_OBJECT

    GraphController* _graphController;

public:
    GraphGenerator(GraphController* graphController);

    void generate(int vertices);
};

#endif // GRAPHGENERATOR_H
