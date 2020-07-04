# clipboard

points = [(2,4),(4,2)]
def F(w):
   return sum((x * x - y)**2 for x, y in points)
def dF(w):
   return sum(2*(x*y-y)*x for x, y in points)

# Gradient descent
w = 0
eta = 0.01
for t in range(1000):
   value = F(w)
   gradient = dF(w)
   w = w -eta * gradient
   print("iteration {}: w = {}, F(w) = {}".format(t,w,value))
