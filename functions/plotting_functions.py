import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("bp_filter.txt")
data_convolve = np.loadtxt("convolve.txt")
data_gaussian = np.loadtxt("gaussian_function.txt")

x = np.linspace(6, 180, len(data))

plt.plot(x, data)
plt.plot(x, data_convolve)
#plt.plot(data_gaussian)

plt.show()