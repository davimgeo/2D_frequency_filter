#include "gaussian_smooth.hpp"
#include <iostream>
#include <vector>
#include <cmath>

std::vector<double> gaussianFunction(int sample_points, int sigma) 
{
    std::vector<double> result(sample_points);
    double mean = sample_points / 2.0;
    double sigma_squared = sigma * sigma;
    double arg = sqrt(2.0 * M_PI * sigma_squared);

    for(int x = 0; x < sample_points; x++) {
        double value = x - mean;
        result[x] = 1.0 / arg * exp(-value * value / (2.0 * sigma_squared));
    }
    return result;
}