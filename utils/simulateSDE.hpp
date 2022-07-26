#ifndef simulateSDE
#define simulateSDE

#include <random>
#include <vector>

class SimulateSDE{
    public:
        void checkVector(std::vector<double> vec);
        
        std::vector<double> createTimeInterval(int n);
        
        std::vector<double> _createBrownianDifferences(int n);
        
        double _sigmaFunc(double sigma, double gamma, double r);
        
        double _muFunc(double mu, double alpha, double r);
        
        std::vector<double> simulateEulerMaruyama(int n, double r_0, double mu, double alpha, double sigma, double gamma);
};

#endif