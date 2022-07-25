#include "simulateSDE.hpp"

#include <stdio.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::endl;
// using std::vector;

void checkVector(std::vector<double> vec){
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << endl;
    }
}

/* 
create the Time Interval
Input:
    n : natural number (the number of partition)
Output:
    vec : partition of time interval
*/
std::vector<double> createTimeInterval(int n){
    
    std::vector<double> vec;

    for (int i = 0; i <= n; i++){
        vec.push_back((double)i / n);
        // cout << (double)i / 100 << endl;
    }

    return vec;
}

/* 
create brownian differences
Input:
    n : natural number (the number of partition)
Output:
    vec : Brownian differences
*/
std::vector<double> _createBrownianDifferences(int n){
    
    std::vector<double> vec;

    std::random_device seed;
    std::mt19937 engine(seed());
    double mu = 0.0, sig = (double)1 / n;

    std::normal_distribution<> dist(mu, sig); // need mean and standard deviation
    for (int i = 0; i <= n; i++){
        double normalDistribution_value = dist(engine);
        vec.push_back(normalDistribution_value);
        // cout << vec[i] << endl;
    }

    return vec;
}

/* 
calculate the sigma function
Input:
    sigma : parameter
    gamma : parameter
    r : parameter
Output:
    sigma_func_value : value of the sigma function
*/
double _sigmaFunc(double sigma, double gamma, double r){
    double sigma_func_value = sigma * pow(r, gamma);
    return sigma_func_value;
}

/* 
calculate the mu function
Input:
    mu : parameter
    alpha : parameter
    r : parameter
Output:
    mu_func_value : value of the mu function
*/
double _muFunc(double mu, double alpha, double r){
    double mu_func_value = mu * (alpha - r);
    return mu_func_value;
}

/* 
calculate the mu function
Input:
    n : the number of partition
    r_0 : initial value of the SDE
    mu : parameter
    alpha : parameter
    sigma : parameter
    gamma : parameter
    r : parameter
Output:
    vec : the value of the SDE
*/
std::vector<double> simulateEulerMaruyama(int n, double r_0, double mu, double alpha, double sigma, double gamma){
    
    // simulate the Brownian motion
    std::vector<double> brownian_diff_vec = _createBrownianDifferences(n);
    
    // simulate SDE by using Euler Maruyama approximation
    double one_step = (double) 1/n;
    std::vector<double> vec;

    vec.push_back((double)r_0);
    for (int i = 1; i <= n; i++){
        double pre_r = vec[i - 1];
        double brownian_diff = brownian_diff_vec[i - 1];
        
        double r = pre_r + _muFunc(mu, alpha, pre_r) * one_step + _sigmaFunc(sigma, gamma, pre_r) * brownian_diff;
        
        vec.push_back(r);
    }

    return vec;
}
