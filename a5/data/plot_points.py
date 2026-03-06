# this program needs the following modules:
# - matplotlib
# - pandas
# install them via "pip install <module name>"
import matplotlib.pyplot as plt
import pandas as pd

# read the points from the file
df = pd.read_csv('coordinates.txt', sep=',', header=None)

# print the first 5 points
print(df.head().values)

# x = [1, 2, 3, 4, 5, 6, 7, 8]
# y = [2, 3, 1, 3, 1, 4, 2, 3]

# get the x and y coordinates of the first X points, the X is the determined by the num_points variable
num_points = 30
x = df.iloc[0:num_points, 0].values
y = df.iloc[0:num_points, 1].values

# plot the points
plt.scatter(x, y)
plt.show()
