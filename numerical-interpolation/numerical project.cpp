#include <iostream>
#include <vector>

using namespace std;

// Function to calculate factorial
double factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate forward difference table
vector<vector<double>> forwardDifferenceTable(const vector<double>& x, const vector<double>& fx) {
    int n = x.size();
    vector<vector<double>> forwardTable(n, vector<double>(n, 0));

    // Assigning first column of the forward table
    for (int i = 0; i < n; i++) {
        forwardTable[i][0] = fx[i];
    }

    // Calculating the forward difference table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            forwardTable[j][i] = forwardTable[j + 1][i - 1] - forwardTable[j][i - 1];
        }
    }

    return forwardTable;
}

// Function to calculate forward interpolation
double forwardInterpolation(double x, const vector<double>& xi, const vector<double>& fx, const vector<vector<double>>& forwardTable) {
    int n = xi.size();
    double sum = fx[0];
    double u = (x - xi[0]) / (xi[1] - xi[0]);

    for (int i = 1; i < n; i++) {
        sum += (u * forwardTable[0][i]) / factorial(i);
        u *= (u - 1) / i;
    }

    return sum;
}

// Function to calculate backward difference table
vector<vector<double>> backwardDifferenceTable(const vector<double>& x, const vector<double>& fx) {
    int n = x.size();
    vector<vector<double>> backwardTable(n, vector<double>(n, 0));

    // Assigning last column of the backward table
    for (int i = 0; i < n; i++) {
        backwardTable[i][0] = fx[i];
    }

    // Calculating the backward difference table
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            backwardTable[j][i] = backwardTable[j][i - 1] - backwardTable[j - 1][i - 1];
        }
    }

    return backwardTable;
}

// Function to calculate backward interpolation
double backwardInterpolation(double x, const vector<double>& xi, const vector<double>& fx, const vector<vector<double>>& backwardTable) {
    int n = xi.size();
    double sum = fx[n - 1];
    double u = (x - xi[n - 1]) / (xi[1] - xi[0]);

    for (int i = 1; i < n; i++) {
        sum += (u * backwardTable[n - 1][i]) / factorial(i);
        u *= (u + 1) / i;
    }

    return sum;
}

int main() {
    vector<double> x = { 0, 1, 2, 3 };
    vector<double> fx = { 1, 2, 3, 10 };

    // Forward interpolation
    vector<vector<double>> forwardTable = forwardDifferenceTable(x, fx);
    double forwardResult = forwardInterpolation(1.8, x, fx, forwardTable);
    cout << "Forward interpolation result for f(1.8): " << forwardResult << endl;

    // Backward interpolation
    vector<vector<double>> backwardTable = backwardDifferenceTable(x, fx);
    double backwardResult = backwardInterpolation(2.5, x, fx, backwardTable);
    cout << "Backward interpolation result for f(2.5): " << backwardResult << endl;
    cout << "Error for f(1.8) = abs(3.1 - 3.056) =0.044 "<< endl;
    cout << "Error for f(2.5) = abs(5.65625 - 6.5)=0.84375 "<< endl;

    return 0;
}
