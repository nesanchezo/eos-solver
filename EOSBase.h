#ifndef EOS_BASE_H
#define EOS_BASE_H

#include <vector>

class EOSBase {
public:
    virtual void calculateCoefficients(double T, double P) = 0;
    virtual std::vector<double> findRoots() = 0;
    virtual ~EOSBase() {}
};

#endif