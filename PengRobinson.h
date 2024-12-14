#ifndef PENG_ROBINSON_H
#define PENG_ROBINSON_H

#include "EOSBase.h"
#include <vector>

class PengRobinson : public EOSBase {
private:
    double Tc, Pc, omega;  // Critical properties
    double a, b, alpha;    // Peng-Robinson parameters
    double A, B;           // Reduced parameters for the cubic equation
    const double R = 0.08314; // Gas constant in L·bar/(mol·K)

    // Helper method to calculate alpha
    double calcAlpha(double T);

public:
    // Constructor
    PengRobinson(double Tc, double Pc, double omega);

    // Methods overridden from the base class
    void calculateCoefficients(double T, double P) override;
    std::vector<double> findRoots() override;

    // Destructor
    ~PengRobinson() override = default;
};

#endif