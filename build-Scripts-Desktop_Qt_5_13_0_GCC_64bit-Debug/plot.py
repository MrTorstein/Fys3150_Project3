import matplotlib.pyplot as plt
import numpy as np

filename = input("filnavn: ")

f = open(filename, 'r')
fl = f.readlines()

x = []
integration = []

for i in fl:
    integration.append(float(i))
for j in range(len(integration)):
    x.append(j)

plt.plot(x,integration, label = "N = 5")
plt.legend()
plt.title('Integration approximation by sum')
plt.xlabel('number of summations')
plt.ylabel('integrationvalue')
plt.savefig("Figur00.png")

plt.show()

