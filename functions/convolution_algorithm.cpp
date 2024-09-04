#include "convolution_algorithm.hpp"
#include <iostream>
#include <vector>

std::vector<double> sameConvolutionAlgorithm(const std::vector<double>& arr1, const std::vector<double>& arr2)
{
    int N = arr1.size();
    int M = arr2.size();
    int pad = M / 2;
    std::vector<double> y(N, 0);
    for (int n = 0; n < N; n++) {
        for (int k = 0; k < M; k++) {
            int idx = n + k - pad;
            if (idx >= 0 && idx < N) {
                y[n] += arr1[idx] * arr2[k];
            }
        }
    }
    return y;
}
