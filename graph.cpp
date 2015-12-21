#include "graph.h"

Graph& Graph::operator= (const Graph& other)
{
    _vertices = other._vertices;
    _adj_mtrx = other._adj_mtrx;

    return *this;
}

QHash<QString, Vertex> Graph::vertices() const
{
    return _vertices;
}

QHash<QString, QHash<QString, int>> Graph::weights() const
{
    return _adj_mtrx;
}

void Graph::addVertex(QString id)
{
    _vertices.insert(id, Vertex());

    QHash<QString, int> last_row;
    for (auto it = _adj_mtrx.begin(); it != _adj_mtrx.end(); ++it) {
        last_row.insert(it.key(), 0);
        it.value().insert(id, 0);
    }
    _adj_mtrx.insert(id, last_row);
}

void Graph::connect(QString id1, QString id2, int weight)
{
    _adj_mtrx[id1][id2] = _adj_mtrx[id2][id1] = weight;
}

Vertex& Graph::operator[] (QString id)
{
    return _vertices[id];
}

int Graph::weight(QString id1, QString id2) const
{
    return _adj_mtrx.value(id1).value(id2);
}

void Graph::deleteVertex(QString id)
{
    _vertices.remove(id);

    _adj_mtrx.erase(_adj_mtrx.end() - 1);
    for (auto it = _adj_mtrx.begin(); it != _adj_mtrx.end(); ++it) {
        it.value().erase(it.value().end() - 1);
    }
}

void Graph::clear()
{
    _vertices.clear();
    _adj_mtrx.clear();
}
