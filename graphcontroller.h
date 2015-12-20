#ifndef GRAPHCONTROLLER_H
#define GRAPHCONTROLLER_H

#include <QObject>

#include "graph.h"

class GraphController : public QObject
{
    Q_OBJECT

    Graph* _graph;
    int _id_counter;

public:
    GraphController();
    ~GraphController();

    GraphController(const GraphController& other);
    GraphController& operator= (const GraphController& other);

    Graph* graph() const;

    void addVertex(QString id = QString());
    void addEdge(QString id1, QString id2, int weight);

    QString suggestedId() const;
};

#endif // GRAPHCONTROLLER_H
