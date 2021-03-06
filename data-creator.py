import numpy as np
from scipy.stats import randint
from scipy.stats import truncnorm

COUNT_ARRAYS = 5
UNIFORM_DISTRIBUTION = "UNIFORM_DISTRIBUTION"
NORMAL_DISTRIBUTION = "NORMAL_DISTRIBUTION"
FILE_NAME = "input.txt"

def createUniformDistribution(start, end, data_size):
    result = np.zeros((COUNT_ARRAYS, data_size))
    for i in range(COUNT_ARRAYS):
        result[i] = np.random.randint(start, end, size = data_size)
    return result

def createNormalDistribution(start, end, data_size):
    result = np.zeros((COUNT_ARRAYS, data_size))
    for i in range(COUNT_ARRAYS):
        X = np.random.normal((start + end)/2, 10, data_size)
        X = X.round().astype(int)
        result[i] = X
    return np.abs(result)

MAP_DISTRIBUTION = {
    UNIFORM_DISTRIBUTION : createUniformDistribution,
    NORMAL_DISTRIBUTION : createNormalDistribution
}

def out2dArray(data):
    f = open(FILE_NAME, "a")
    for line in data:
        for number in line:
            f.write(str(number) + ' ')
        f.write("\n")
    f.close()

def writeArrays(distribution, start, end, sizes):
    f = open(FILE_NAME, "a")
    f.write(distribution + '-FROM-' + str(start) + '-TO-' + str(end) + "\n")
    f.close()
    for size in sizes:
        f = open(FILE_NAME, "a")
        f.write(str(size) + "\n")
        f.close()
        out2dArray(
            MAP_DISTRIBUTION[distribution](
                start,
                end,
                size
            ).astype(int)
        )
        f = open(FILE_NAME, "a")
        f.write("\n")
        f.close()

def writeArraysWithDifferentLimits(distribution, start, ends, sizes):
    f = open(FILE_NAME, "a")
    f.write(distribution + 'FROM-0-TO-N-1' + "\n")
    f.close()
    for i in range(len(sizes)):
        f = open(FILE_NAME, "a")
        f.write(str(sizes[i]) + "\n")
        f.close()
        out2dArray(
            MAP_DISTRIBUTION[distribution](
                start,
                ends[i],
                sizes[i]
            ).astype(int)
        )
        f = open(FILE_NAME, "a")
        f.write("\n")
        f.close()

def fillInputFile():
    sizes = np.array([30000, 100000, 300000, 1000000])
    ends = sizes - 1
    writeArrays(UNIFORM_DISTRIBUTION, 0, 2**31, sizes)
    writeArraysWithDifferentLimits(UNIFORM_DISTRIBUTION, 0, ends, sizes)
    writeArrays(UNIFORM_DISTRIBUTION, 0, 2**15, sizes)
    writeArrays(NORMAL_DISTRIBUTION, 0, 2**31, sizes)
    f = open(FILE_NAME, "a")
    f.write("END")
    f.close()

fillInputFile()
    
