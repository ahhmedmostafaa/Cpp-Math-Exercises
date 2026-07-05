# C++ Applied Math Exercises

A collection of small C++ programs applying core mathematical concepts: discrete mathematics (logic, probability) and numerical analysis (interpolation).

## Contents

### 1. Discrete Math Toolkit (`discrete-math-toolkit/`)
Three console tools for discrete mathematics:
- **Truth Table Generator** — builds a full truth table for a logical operation (conjunction, disjunction, XOR, negation, implication, biconditional) and checks whether the expression is a **tautology**
- **Logical Equivalence Checker** — verifies whether `~(p v (~p ^ q))` and `(~p ^ ~q)` are logically equivalent (De Morgan's Law)
- **Mean & Variance Calculator** — computes mean and variance of a discrete probability distribution

### 2. Numerical Interpolation (`numerical-interpolation/`)
An implementation of **Newton's Forward and Backward Difference Interpolation** for estimating function values from a discrete set of data points, using forward/backward difference tables and factorial-weighted series expansion.

## Tech Stack
- C++
- Visual Studio project files (.sln / .vcxproj)

## How to Run
```bash
# Discrete math toolkit
g++ discrete-math-toolkit/project.cpp -o discrete_toolkit
./discrete_toolkit

# Numerical interpolation
g++ numerical-interpolation/"numerical project.cpp" -o interpolation
./interpolation
```
Or open either `.sln` file in Visual Studio and run (F5).
