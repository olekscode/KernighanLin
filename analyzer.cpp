#include "analyzer.h"

Analyzer::Analyzer(Algorythm* alg)
{
    _algorythm = alg;
    _sysMonitor = new SystemMonitor();
}

Analyzer::~Analyzer()
{
    delete _sysMonitor;
}
