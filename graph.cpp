#include "graph.h"

Graph::Graph()
{
    _adj_mtrx = new weight_t*[0];
}

Graph::~Graph()
{
    for (int i = 0; i < _vertices.size(); ++i) {
        delete[] _adj_mtrx[i];
    }
    delete[] _adj_mtrx;
}

Graph::Graph(const Graph &other)
{
    _vertices = other._vertices;

    int n = (int) _vertices.size();
    _adj_mtrx = new weight_t*[n];

    for (int i = 0; i < n; ++i) {
        _adj_mtrx[i] = new weight_t[n];

        for (int j = 0; j < n; ++j) {
            _adj_mtrx[i][j] = other._adj_mtrx[i][j];
        }
    }
}

Graph& Graph::operator= (const Graph& other)
{
    _vertices = other._vertices;

    int n = (int) _vertices.size();
    _adj_mtrx = new weight_t*[n];

    for (int i = 0; i < n; ++i) {
        _adj_mtrx[i] = new weight_t[n];

        for (int j = 0; j < n; ++j) {
            _adj_mtrx[i][j] = other._adj_mtrx[i][j];
        }
    }
    return *this;
}

QHash<QString, Vertex> Graph::vertices() const
{
    return _vertices;
}

void Graph::addVertex(QString id)
{
    _vertices.insert(id, Vertex());
    qDebug() << _vertices.size();
    _increase_adj_mtrx();
}

void Graph::connect(QString id1, QString id2, weight_t weight)
{
    // TODO: Find a way to get an index of element by it's key

    int i1 = _index_of_vertex(id1);
    int i2 = _index_of_vertex(id2);

    _adj_mtrx[i1][i2] = weight;
}

Vertex& Graph::operator[] (QString id)
{
    return _vertices[id];
}

weight_t Graph::weightBetween(QString id1, QString id2) const
{
    int i1 = _index_of_vertex(id1);
    int i2 = _index_of_vertex(id2);

    return _adj_mtrx[i1][i2];
}

void Graph::deleteVertex(QString id)
{
    _vertices.remove(id);
    _decrease_adj_mtrx();
}

int Graph::_index_of_vertex(QString id) const
{
    int index = 0;

    for (auto i = _vertices.begin(); i != _vertices.end(); ++i) {
        if (i.key() == id) {
            return index;
        }
        ++index;
    }
    throw NoVertexException();
}

void Graph::_increase_adj_mtrx()
{
    int n = (int) _vertices.size();
    weight_t** other = new weight_t*[n];

    for (int i = 0; i < n - 1; ++i) {
        other[i] = new weight_t[n];

        for (int j = 0; j < n - 1; ++j) {
            other[i][j] = _adj_mtrx[i][j];
        }
        delete[] _adj_mtrx[i];
    }

    delete[] _adj_mtrx;
    _adj_mtrx = other;

    for (int i = 0; i < n; ++i) {
        _adj_mtrx[i][n - 1] = 0;
        _adj_mtrx[n - 1][i] = 0;
    }
}

void Graph::_decrease_adj_mtrx()
{
    int n = (int) _vertices.size();
    weight_t** other = new weight_t*[n];

    for (int i = 0; i < n; ++i) {
        other[i] = new weight_t[n];

        for (int j = 0; j < n; ++j) {
            other[i][j] = _adj_mtrx[i][j];
        }
        delete[] _adj_mtrx[i];
    }

    delete[] _adj_mtrx;
    _adj_mtrx = other;
}
