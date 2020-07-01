import matplotlib.pyplot as plt
from matplotlib import style
import numpy as np
style.use("ggplot")

class Support_Vector_Machine:
   def __init__(self, visualization=True):
      self.visualization = visualization
      self.color = {1:"r", -1:"b"}
      if self.visualization:
         self.fig = plt.figure()
         self.ax = self.fig.add_subplot(1,1,1) # for multiply plots to display
   
   def fit(self, data):
      self.data = data # "data" is dictionary
      # ||w||: [w,b]
      opt_dict = {}
      transforms = [[1,1],
                    [-1,1],
                    [-1,-1],
                    [1,-1],]
      
      all_data = []
      for yi in self.data: # "yi" loop through each key of "data"
         for featureset in self.data[yi]: # "featureset" loop through each a key, that contain further datasets of "data" <=> list in a list 
            for feature in featureset: # feature loop through each the set, of the featureset in data
               all_data.append(feature) # finally append each given value to empty array "all_data"

      self.max_feature_value = max(all_data) # declare the highest value of array "all_data"
      self.min_feature_value = min(all_data) # declare the lowest value of array "all_data"
      all_data = None # clear the array, since we already have the highest and lowest values

      #suprot vectors:= yi(xi.w+b) = 1 //for both negative and positive "classes/sign" of equation at least to be the nearest to 1 
      step_sizes = [self.max_feature_value * 0.1,
                    self.max_feature_value * 0.01,]
                    # point of expense:
                    #self.max_feature_value * 0.001,]

      # extremely expensive
      b_range_multiple = 5
      # we do not need to take as small steps
      # with b as we do with w
      b_multiple = 5 
      latest_optimum = self.max_feature_value*10

      for step in step_sizes:
         w = np.array([latest_optimum, latest_optimum])
         optimized = False # able, since it convex probelm if no then you should ensure that you will add some further steps.
         while not optimized: 
            for b in np.arange(-1*(self.max_feature_value*b_range_multiple), #start from:
                               self.max_feature_value*b_range_multiple, #till:
                               step*b_multiple): #each loop steps
               for transformation in transforms:
                  w_t = w*transformation  #you have to tranform the svm, since svm must be able to be a "slope" possible to be graph in any direction etc.
                  found_option = True
                  #weakest link in the SVM fundamentally
                  #yi(xi.w+b0) >= 1 
                  for i in self.data:
                     for xi in self.data[i]: # looping though each value of "data" that have been passed
                        yi = i 
                        if not yi*(np.dot(w_t,xi)+b)>= 1: # the result have to be nearest to the 1 itself, to get the exact nearest result
                           found_option = False
                        #print(xi,":",yi*(np.dot(w_t,xi)+b))
                        

                  if found_option:
                     opt_dict[np.linalg.norm(w_t)] = [w_t,b]
                     
            if w[0] < 0: # if x-coordinate is less then 0
               optimized = True
               print("Optimized a step")
            else:
               w = w - step # step:= [step, step]
         norms = sorted([n for n in opt_dict]) #sorting ascending
         #||w|| : [w,b]
         opt_choice = opt_dict[norms[0]]
         self.w = opt_choice[0]
         self.b = opt_choice[1]
         latest_optimum = opt_choice[0][0]+step*2
       
      for i in self.data: # this loop is just for print the finally calculation to the how near to the 1 the data was predicted
         for xi in self.data[i]:
            yi = i
            print(xi,":",yi*(np.dot(self.w,xi)+self.b))

   def predict(self, features): # "features" are the values that should be classified
      # sign(x.w+b) // sign := is "+" or "-" sign, so this is the classification itself
      classification = np.sign(np.dot(np.array(features),self.w) + self.b) # instead of "np.sign" use lambda/anonymous fu
      if classification !=0 and self.visualization: # if classification is 0 than it is exactly on the decision boundary "slope"
         self.ax.scatter(features[0],features[1], s=200, marker="*", c=self.color[classification]) #if not the scatter the loc of the given featres
      return classification

   def visualize(self): # the program itself, do not need this to work, it is just for us Human to get sight of whats going on.
      [[self.ax.scatter(x[0],x[1],s=100,color=self.color[i]) for x in data_dict[i]] for i in data_dict]
      #hyperplane <=> v = x.w+b
      #psv = 1; nsv = -1; dec_bound = 0
      def hyperplane(x,w,b,v):
         return (-w[0]*x-b+v) / w[1] # "end form" 

      datarange = (self.min_feature_value*0.9,self.max_feature_value*1.1) #the datarange it is the boundary of how much errorrates it can tolerate
      hyp_x_min = datarange[0]
      hyp_x_max = datarange[1]

      #(w.x+b) = 1
      #positive support vector hyperplane
      psv1 = hyperplane(hyp_x_min, self.w, self.b, 1)
      psv2 = hyperplane(hyp_x_max, self.w, self.b, 1)
      self.ax.plot([hyp_x_min, hyp_x_max], [psv1,psv2])

       #(w.x+b) = -1
      #negative support vector hyperplane
      nsv1 = hyperplane(hyp_x_min, self.w, self.b, -1)
      nsv2 = hyperplane(hyp_x_max, self.w, self.b, -1)
      self.ax.plot([hyp_x_min, hyp_x_max], [nsv1,nsv2])

       #(w.x+b) = 0
      #boundary support vector hyperplane
      dec_bound1 = hyperplane(hyp_x_min, self.w, self.b, 0)
      dec_bound2 = hyperplane(hyp_x_max, self.w, self.b, 0)
      self.ax.plot([hyp_x_min, hyp_x_max], [dec_bound1,dec_bound2])


data_dict = {-1:np.array([[1,7],
                         [2,8],
                         [3,8],]),
            1:np.array([[5,1],
                        [6,-1],
                        [7,3],])}



svm = Support_Vector_Machine() #crate obj of class
svm.fit(data=data_dict) # by obj use method fit with passed arguments/parameters

predict_us = [[0,10], 
              [1,5],
              [4,6],
              [4,4],
              [6,4],
              [5,8],]

for p in predict_us:
   svm.predict(p)

svm.visualize()

   