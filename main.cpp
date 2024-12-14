#include "PengRobinson.h"
#include "SRK.h"
#include <iostream>
#include <limits> 

void testEOS(EOSBase* eos, double T, double P) {
    eos->calculateCoefficients(T, P);
    std::vector<double> roots = eos->findRoots();

    std::cout << "Roots of the EOS at T=" << T << " K and P=" << P << " bar:\n";
    for (size_t i = 0; i < roots.size(); ++i) {
        std::cout << "Root " << i + 1 << ": " << roots[i] << "\n";
    }
    std::cout << std::endl;
}

int main() {
    double T, P;

    // Validate temperature input
    while (true) {
        std::cout << "Enter temperature (K): ";
        std::cin >> T;

        // Check for valid input
        if (std::cin.fail() || T <= 0) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cerr << "Invalid temperature! Please enter a value greater than 0.\n";
        } else {
            break; 
        }
    }

    // Validate pressure input
    while (true) {
        std::cout << "Enter pressure (bar): ";
        std::cin >> P;

        // Check for valid input
        if (std::cin.fail() || P <= 0) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cerr << "Invalid pressure! Please enter a value greater than 0.\n";
        } else {
            break; // Exit loop if input is valid
        }
    }

    // User chooses EOS
    int choice;
    while (true) {
        std::cout << "Choose EOS:\n";
        std::cout << "1. Peng-Robinson\n";
        std::cout << "2. Soave-Redlich-Kwong\n";
        std::cout << "Enter choice (1 or 2): ";
        std::cin >> choice;

        // Validate choice
        if (std::cin.fail() || (choice != 1 && choice != 2)) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cerr << "Invalid choice! Please enter 1 or 2.\n";
        } else {
            break; // Exit loop if input is valid
        }
    }

    // Select EOS
    EOSBase* eos;
    if (choice == 1) {
        double Tc = 190.6; // Example: Critical temperature in K (methane)
        double Pc = 45.99; // Critical pressure in bar (methane)
        double omega = 0.011; // Acentric factor (methane)
        eos = new PengRobinson(Tc, Pc, omega);
        std::cout << "Using Peng-Robinson EOS.\n";
    } else {
        double Tc = 190.6; // Example: Critical temperature in K (methane)
        double Pc = 45.99; // Critical pressure in bar (methane)
        double omega = 0.011; // Acentric factor (methane)
        eos = new SoaveRedlichKwong(Tc, Pc, omega);
        std::cout << "Using Soave-Redlich-Kwong EOS.\n";
    }

    // Perform the calculation
    testEOS(eos, T, P);

    // Release memory
    delete eos;

    return 0;
}