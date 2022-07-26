#include "calculateFZ.hpp"

#include <stdio.h>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::endl;

/*
calculate the sigma function by using the Florens- Zmirou[1993]
Input:
    n : the number of the partition
    process : the discrete stochastic process
    partiton : the partition of the time interval
Output:
    square_sigma_vec : the values of the square sigma function
*/
std::vector<double> CalculateFZ::estimateSigma(int n, std::vector<double> process, std::vector<double> partition){
    double one_step = (double) 1/n;
    std::vector<double> square_sigma_vec;

    for (int i=0; i < process.size(); i++){
        double square_sigma = (double) (process[i+1] - process[i]) / one_step;
        
        square_sigma_vec.push_back(square_sigma);
    }
    
    return square_sigma_vec;

}