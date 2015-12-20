#ifndef ANALYZER_H
#define ANALYZER_H

#include "algorythm.h"
#include "systemmonitor.h"

class Analyzer
{
    Algorythm* _algorythm;
    SystemMonitor* _sysMonitor;

public:
    Analyzer(Algorythm* alg);
    ~Analyzer();

    Analyzer(const Analyzer& other);
    Analyzer& operator= (const Analyzer& other);
};

#endif // ANALYZER_H
