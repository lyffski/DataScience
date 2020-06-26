from statistics import mean
import numpy as np
import matplotlib.pyplot as plt
import random

# xs = np.array([1,2,3,4,5,6]) #input
# ys = np.array([4.2,5,5.3,5.9,6,7]) #output

def create_dataset(qty, variance, step=2, correlation=False):
    var = 1
    ys = []
    for i in range (qty):
        y = var + random.randrange(-variance, variance)
        yes.append(y)
        if correlation and correlation == True
            var += step
        elif correlation and correlation ==  False
            var -= step
    xs = [i for i in range(len(ys))]
    return np.array(xs, dtype=np.float64), np.array(ys, dtype=np.float64)

def bestSlope(xs,ys):
    m, dividend, divisor = 0,0,0
    for i in range(len(ys)):
        dividend += (xs[i]-mean(xs)) * (ys[i]-mean(ys))
        divisor += (xs[i]-mean(xs))**2
        m = dividend / divisor
    t = mean(ys) - m*mean(xs)
    return m, t

def squared_error(ys_orig, ys_regr_line):
    return sum((ys_regr_line-ys_orig)**2)

def coefficient_of_det(ys_orig, ys_regr_line):
    ys_mean_line = [mean(ys_orig) for y in ys_orig]
    sq_error_regr = squared_error(ys_orig, ys_regr_line)
    sq_error_y_mean = squared_error(ys_orig, ys_mean_line)
    return 1 - (sq_error_regr / sq_error_y_mean)
    
xs, ys = create_dataset(40, 40, 2, False)    
m, t = bestSlope(xs,ys)
regr_line = [(m*x)+t for x in xs]
r_squared = coefficient_of_det(ys, regr_line)

print("Confidence PTC: "+str(r_squared))


