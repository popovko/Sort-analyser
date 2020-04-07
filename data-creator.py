import numpy as np
from scipy.stats import randint
from scipy.stats import truncnorm

def createUniformDistribution(start, stop, data_size, count_copy = 5):
    result = np.zeros((count_copy, data_size))
    for i in range(count_copy):
        result[i] = np.random.randint(start, stop, size = data_size)
    return result

def createNormalDistribution(start, stop, data_size, count_copy = 5):
    result = np.zeros((count_copy, data_size))
    for i in range(count_copy):
        X = truncnorm(a = start, b = stop, scale = 5).rvs(size = data_size)
        X = X.round().astype(int)
        result[i] = X
    return result