#ifndef ANALYZER_H
#define ANALYZER_H

#include <QObject>

#include "algorythm.h"
#include "systemmonitor.h"

class Analyzer : public QObject
{
    Q_OBJECT

    Algorythm* _algorythm;
    SystemMonitor* _sysMonitor;

public:
    Analyzer(Algorythm* alg);
    ~Analyzer();

    Analyzer(const Analyzer& other);
    Analyzer& operator= (const Analyzer& other);
};

#endif // ANALYZER_H
