#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>
#include <QHash>
#include <QVector>
#include <QPair>
#include <QDebug>

#include "vertex.h"
#include "exception.h"

class Graph : public QObject
{
    Q_OBJECT

    QHash<QString, Vertex> _vertices;
    int** _adj_mtrx;

public:
    Graph();
    ~Graph();

    Graph(const Graph& other);
    Graph& operator= (const Graph& other);

    QHash<QString, Vertex> vertices() const;

    // CREATE
    void addVertex(QString id);
    void connect(QString id1, QString id2, int weight);

    // READ, UPDATE
    Vertex& operator[] (QString id);
    int weightBetween(QString id1, QString id2) const;

    // DELETE
    void deleteVertex(QString id);

private:
    int _index_of_vertex(QString id) const;
    void _increase_adj_mtrx();
    void _decrease_adj_mtrx();
};

#endif // GRAPH_H
