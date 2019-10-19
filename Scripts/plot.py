import matplotlib.pyplot as plt
import numpy as np

f = open('example.txt', 'r')
fl = f.readlines()

x = []
integration = []

for i in fl:
    integration.append(float(i))
for j in range(len(integration)):
    x.append(j)

plt.plot(x,integration)
#plt.legend()
plt.title('Integration approximation by sum')
plt.xlabel('number of summations')
plt.ylabel('integrationvalue')
plt.show()
