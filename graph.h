#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>
#include <QHash>
#include <QVector>
#include <QDebug>

#include "vertex.h"
#include "exception.h"

class Graph : public QObject
{
    Q_OBJECT

    // Probably, it would be better to use arrays and matrices
    // instead of hash-tables
    QHash<QString, Vertex> _vertices;
    QHash<QString, QHash<QString, int>> _adj_mtrx;

public:
    Graph() = default;
    ~Graph() = default;

    Graph(const Graph& other) = default;
    Graph& operator= (const Graph& other);

    QHash<QString, Vertex> vertices() const;
    QHash<QString, QHash<QString, int>> weights() const;

    // CREATE
    void addVertex(QString id);
    void connect(QString id1, QString id2, int weight);

    // READ, UPDATE
    Vertex& operator[] (QString id);
    int weight(QString id1, QString id2) const;

    // DELETE
    void deleteVertex(QString id);
    void clear();
};

#endif // GRAPH_H
