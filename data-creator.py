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
        X = np.random.normal((start + end)/2, (start + end)/5, data_size)
        X = X.round().astype(int)
        result[i] = X
    return result

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
    f.write(distribution + ' ' + str(start) + ' ' + str(end) + "\n")
    f.close()
    for size in sizes:
        f = open(FILE_NAME, "a")
        f.write("Size = " + str(size) + "\n")
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
    f.write(distribution + ' 0 N-1' + "\n")
    f.close()
    for i in range(len(sizes)):
        f = open(FILE_NAME, "a")
        f.write("Size = " + str(sizes[i]) + "\n")
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
    f = open(FILE_NAME, "a")
    f.write("COUNT_ARRAYS = " + str(COUNT_ARRAYS) + "\n")
    f.close()
    sizes = np.array([3*10, 10*5, 3*10*3, 10*6])
    ends = sizes - 1
    writeArrays(UNIFORM_DISTRIBUTION, 0, 100, sizes)
    writeArrays(UNIFORM_DISTRIBUTION, 0, 100, sizes)
    writeArraysWithDifferentLimits(UNIFORM_DISTRIBUTION, 0, ends, sizes)
    writeArrays(NORMAL_DISTRIBUTION, 0, 100, sizes)


fillInputFile()
    
