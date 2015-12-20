#ifndef GRAPH_H
#define GRAPH_H

#include <QHash>
#include <QDebug>

#include "vertex.h"
#include "exception.h"

typedef int weight_t;

class Graph
{
    QHash<QString, Vertex> _vertices;
    weight_t** _adj_mtrx;

public:
    Graph();
    ~Graph();

    Graph(const Graph& other);
    Graph& operator= (const Graph& other);

    QHash<QString, Vertex> vertices() const;

    // CREATE
    void addVertex(QString id);
    void connect(QString id1, QString id2, weight_t weight);

    // READ, UPDATE
    Vertex& operator[] (QString id);
    weight_t weightBetween(QString id1, QString id2) const;

    // DELETE
    void deleteVertex(QString id);

private:
    int _index_of_vertex(QString id) const;
    void _increase_adj_mtrx();
    void _decrease_adj_mtrx();
};

#endif // GRAPH_H
