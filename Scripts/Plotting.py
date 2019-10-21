import matplotlib.pyplot as plt
import numpy as np

filename = input("filnavn: ")

x = []
y = []

with open(filename, 'r') as infile:
    for line in infile:
        x.append(int(line.split()[0]))
        y.append(float(line.split()[2]))

plt.plot(x, y, label = "I(N)")
plt.legend()
plt.title('Integration approximation Monte Carlo sum')
plt.xlabel('N')
plt.ylabel('integrationvalue')
plt.savefig("Figur01.png")

plt.show()