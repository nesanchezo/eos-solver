#include "SRK.h"
#include <cmath>
#include <algorithm>

// Constructor
SoaveRedlichKwong::SoaveRedlichKwong(double Tc, double Pc, double omega)
    : Tc(Tc), Pc(Pc), omega(omega), a(0), b(0), alpha(0), A(0), B(0) {}

// Helper method to calculate alpha
double SoaveRedlichKwong::calcAlpha(double T) {
    double Tr = T / Tc;
    double m = 0.48 + 1.574 * omega - 0.176 * omega * omega;
    return std::pow(1 + m * (1 - std::sqrt(Tr)), 2);
}

// Calculate SRK parameters
void SoaveRedlichKwong::calculateCoefficients(double T, double P) {
    alpha = calcAlpha(T);
    a = 0.42748 * alpha * std::pow(R * Tc, 2) / Pc;
    b = 0.08664 * R * Tc / Pc;
    A = (a * P) / std::pow(R * T, 2);
    B = (b * P) / (R * T);
}

// Find roots of the cubic SRK equation
std::vector<double> SoaveRedlichKwong::findRoots() {
    // Coefficients of the cubic equation: Z^3 + c2*Z^2 + c1*Z + c0 = 0
    double c2 = -(1 - B);
    double c1 = A - B - B * B;
    double c0 = -(A * B);

    // Solve using Cardano's formula
    double Q = (3 * c1 - c2 * c2) / 9;
    double R = (9 * c2 * c1 - 27 * c0 - 2 * c2 * c2 * c2) / 54;
    double D = Q * Q * Q + R * R; // Discriminant

    std::vector<double> roots;
    if (D >= 0) {
        // One real root
        double S = std::cbrt(R + std::sqrt(D));
        double T = std::cbrt(R - std::sqrt(D));
        roots.push_back(-c2 / 3 + (S + T));
    } else {
        // Three real roots
        double theta = std::acos(R / std::sqrt(-Q * Q * Q));
        for (int k = 0; k < 3; ++k) {
            double root = 2 * std::sqrt(-Q) * std::cos((theta + 2 * M_PI * k) / 3) - c2 / 3;
            roots.push_back(root);
        }
    }

    // Sort roots in descending order
    std::sort(roots.begin(), roots.end(), std::greater<double>());
    return roots;
}