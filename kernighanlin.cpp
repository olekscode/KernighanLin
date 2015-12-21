#include "kernighanlin.h"

KernighanLin::KernighanLin(Graph* graph)
{
    _graph = graph;
}

int KernighanLin::_internal_cost(QString id, int si) const
{
    int cost = 0;

    foreach (QString id2, _subsets[si]) {
        cost += _graph->weight(id, id2);
    }
    return cost;
}

int KernighanLin::_external_cost(QString id, int si) const
{
    int cost = 0;

    for (int i = 0; i < si; ++i) {
        foreach (QString id2, _subsets[i]) {
            cost += _graph->weight(id, id2);
        }
    }

    for (int i = si + 1; i < _num_of_subsets; ++i) {
        foreach (QString id2, _subsets[i]) {
            cost += _graph->weight(id, id2);
        }
    }
    return cost;
}

int KernighanLin::_D(QString id, int si) const
{
    return _external_cost(id, si) - _internal_cost(id, si);
}

int KernighanLin::_reduction(QString id1, int si1, QString id2, int si2) const
{
    return _D(id1, si1) + _D(id2, si2) - 2 * _graph->weight(id1, id2);
}

void KernighanLin::run()
{
    _subsets = new QList<QString>[2];
    _num_of_subsets = n;
    _initial_partition();

    QList<QString> gv, av, bv;

    foreach (QString aid, _subsets[0]) {
        foreach (QString bid, _subsets[1]) {

        }
    }

    delete[] _subsets;
}

void KernighanLin::_initial_partition()
{
    QList<QString> ids = _graph->vertices().keys();
    int part_size = ids.size() / _num_of_subsets;
    auto iter = ids.cbegin();

    for (int i = 0; i < _num_of_subsets - 1; ++i) {
        for (int j = 0; j < part_size; ++j) {
            _subsets[i].append(*iter);
            ++iter;
        }
    }
    while (iter != ids.cend()) {
        _subsets[_num_of_subsets - 1].append(*iter);
        ++iter;
    }
}
