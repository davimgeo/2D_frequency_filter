#include "filter_operator.hpp"
#include <iostream>
#include <vector>
#include <fstream>

std::vector<double> bandPassFilter(int f1, int f2, int f3, int f4, int sample_points) 
{
    std::vector<double> result(sample_points);
    
    double increment = (f4 - f1) / static_cast<double>(sample_points - 1);
    double x = f1;
    for(int i = 0; i < sample_points; i++) {
        if(x >= f1 && x <= f2) { 
            result[i] = 1.0 / (f2 - f1) * (x - f1);
        } else if(x > f2 && x < f3) {
            result[i] = 1.0;
        } else if(x >= f3 && x <= f4) { 
            result[i] = -1.0 / (f4 - f3) * (x - f4);
        } else {
            result[i] = 0.0;
        }
        x += increment;
    }
    return result;
}
