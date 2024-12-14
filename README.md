# Cubic Equation of State Solver

This project is a modular and object-oriented implementation of cubic equations of state (EOS) in C++. It supports the Peng-Robinson (PR) and Soave-Redlich-Kwong (SRK) EOS for calculating the compressibility factor Z of real gases at specified temperature and pressure.

## Features
### Object-Oriented Design (OOP):
  - Implements a base class EOSBase with virtual methods for flexibility.
  - Derived classes PengRobinson and SoaveRedlichKwong for EOS-specific calculations.
### Polymorphism:
  - Handles different EOS dynamically through a single interface.
### Root-Finding Algorithms:
  - Solves the cubic EOS using Cardano's method to find all roots.
### Interactive User Input:
  - Allows users to input temperature and pressure interactively.
  - Validates inputs to ensure physical feasibility.

---

## Prerequisites
### Compiler: A C++11-compatible compiler (e.g., g++ or clang).
### C++ Standard Library:** Included with most modern compilers.

---

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/nesanchezo/eos-solver.git
   cd eos-solver
