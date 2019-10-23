import matplotlib.pyplot as plt
import numpy as np

filename = "/home/ada/Documents/CompFys/Fys3150_Project3/build-Scripts-Desktop-Debug/data_MCI.txt"

x = []
y = []
c = []

with open(filename, 'r') as infile:
    for line in infile:
        x.append(int(line.split()[0]))
        y.append(float(line.split()[1]))
        c.append(0.1927657)

plt.plot(x, y, label = "I(N)")
plt.plot(x, c, label = "Exact integration value")
plt.legend()
plt.title('Improved integration approximation Monte Carlo sum')
plt.xlabel('N')
plt.ylabel('integrationvalue')
plt.savefig("/home/ada/Documents/CompFys/Fys3150_Project3/build-Scripts-Desktop-Debug/Figur_MCI.png")

plt.show()
