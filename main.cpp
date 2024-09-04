#include <iostream>
#include <fstream>
#include "functions/filter_operator.hpp"
#include "functions/convolution_algorithm.hpp"
#include "functions/gaussian_smooth.hpp"

template <typename T>
void exportFile(const std::vector<T>& file, const std::string& file_path) 
{
    std::ofstream outfile(file_path);
    if (!outfile.is_open()) {
        throw std::runtime_error("Could not open file. Please verify the file path.");
    }
    for (const auto& value : file) {
        outfile << value << "\n";
    }
}

int main()
{
    int f1 = 6;
    int f2 = 9;
    int f3 = 80;
    int f4 = 180;
    int sample_points = 900;

    std::vector<double> trapezoidal_bp_filter = bandPassFilter(f1, f2, f3, f4, sample_points);

    std::vector<double> gaussian_function = gaussianFunction(sample_points, 1);

    std::vector<double> convolve = sameConvolutionAlgorithm(trapezoidal_bp_filter, gaussian_function);

    exportFile(trapezoidal_bp_filter, "bp_filter.txt"); 
    exportFile(gaussian_function, "gaussian_function.txt");
    exportFile(convolve, "convolve.txt");
    return 0;
}