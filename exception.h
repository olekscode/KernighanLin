#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QException>
#include <QString>

class Exception : public QException
{
    QString _msg;

public:
    Exception(QString msg) :
        _msg(msg) {}

    virtual ~Exception() throw() {}

    virtual Exception* clone() const
    {
        return new Exception(*this);
    }

    virtual void raise() const
    {
        throw *this;
    }

    QString message(void) const throw()
    {
        return _msg;
    }
};

class GraphEmptyException : public Exception
{
public:
    GraphEmptyException() :
        Exception("The graph contains no vertices. Try adding some.") {}

    virtual ~GraphEmptyException() throw() {}

    GraphEmptyException* clone() const
    {
        return new GraphEmptyException(*this);
    }

    void raise() const
    {
        throw *this;
    }
};

class NoVertexException : public Exception
{
public:
    NoVertexException() :
        Exception("There is no vertex with given id.") {}

    virtual ~NoVertexException() throw() {}

    NoVertexException* clone() const
    {
        return new NoVertexException(*this);
    }

    void raise() const
    {
        throw *this;
    }
};

#endif // EXCEPTION_H
