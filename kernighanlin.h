#ifndef KERNIGHANLIN_H
#define KERNIGHANLIN_H

#include <QString>
#include <QList>
#include <QDebug>

#include "algorythm.h"
#include "graph.h"
#include "vertex.h"

class KernighanLin : public Algorythm
{
    Graph* _graph;
    QList<QString>* _subsets;
    int _num_of_subsets;

public:
    KernighanLin(Graph* graph);

    void run();

private:
    int _internal_cost(QString id, int si) const;
    int _external_cost(QString id, int si) const;

    int _D(QString id, int si) const;
    int _reduction(QString id1, int si1, QString id2, int si2) const;

    void _initial_partition();
};

#endif // KERNIGHANLIN_H
