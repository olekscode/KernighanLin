#ifndef GRAPHCONTROLLER_H
#define GRAPHCONTROLLER_H

#include <QObject>
#include <stdlib.h> // rand
#include <time.h>   // time

#include "graph.h"
#include "vertex.h"
#include "math.h"

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

    void completeConnectVertex(QString id);

    QString suggestedId() const;

    void clear();

private:
    void _set_weight_from_dist(QString id1, QString id2);
};

#endif // GRAPHCONTROLLER_H
