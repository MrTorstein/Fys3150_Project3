import matplotlib.pyplot as plt
import numpy as np

filename = input("filnavn: ")

x = []
y1 = []
y2 = []

with open(filename, 'r') as infile:
    for line in infile:
        x.append(int(line.split()[0]))
        y1.append(float(line.split()[1]))
        y2.append(float(line.split()[2]))

plt.figure()
plt.plot(x, y1, label = "sigma(N)")
plt.legend()
plt.title('Variance Monte Carlo sum')
plt.xlabel('N')
plt.ylabel('Variance')
plt.savefig("Figur01.png")

plt.figure()
plt.plot(x, y2, label = "I(N)")
plt.legend()
plt.title('Integration approximation Monte Carlo sum')
plt.xlabel('N')
plt.ylabel('integrationvalue')
plt.savefig("Figur02.png")

plt.show()