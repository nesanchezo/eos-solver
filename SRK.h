#ifndef SRK_H
#define SRK_H

#include "EOSBase.h"

class SoaveRedlichKwong : public EOSBase {
private:
    double Tc, Pc, omega;  // Critical properties and acentric factor
    double a, b, alpha;    // SRK parameters
    double A, B;           // Reduced parameters for the cubic equation
    const double R = 0.08314; // Gas constant in L·bar/(mol·K)

    // Helper method to calculate alpha
    double calcAlpha(double T);

public:
    // Constructor
    SoaveRedlichKwong(double Tc, double Pc, double omega);

    // Override methods
    void calculateCoefficients(double T, double P) override;
    std::vector<double> findRoots() override;

    // Destructor
    ~SoaveRedlichKwong() override = default;
};

#endif