#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <random>
#include <fstream>

#include "utils/simulateSDE.hpp"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    cout << "Setting parameter" << endl;
    // Setting the parameter for simulate
    const int n = 250;

    // [Chan, Karyolyi, Longstaff and Sanders, 1992]
    // dr_t = mu(alpha - r_t) dt + sigma * r_t ^ gamma dW_t
    // must consider about prameters!!
    const double r_0 = 0.01, alpha = 0.079, mu = 0.093, gamma = 1.474, sigma = 0.794; // given by [Jiang, 1998]

    simulateSDE::SimulateSDE calculateSDE;
    
    // create partition
    std::vector<double> partition = calculateSDE.createTimeInterval(n);
    // simulate the SDE
    std::vector<double> price_process = calculateSDE.simulateEulerMaruyama(n, r_0, mu, alpha, sigma, gamma);

    // calculateSDE.checkVector(price_process);

    return 0;
}