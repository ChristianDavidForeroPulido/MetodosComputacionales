import numpy as np
import matplotlib.pyplot as plt

datosEuler = np.genfromtxt("datosEuler.txt")
datosRK = np.genfromtxt("datosRK.txt")

plt.figure()
plt.plot(datosEuler[:,0], datosEuler[:,1])
plt.title("Metodo Euler")
plt.savefig("graficaEuler.png")

plt.figure()
plt.plot(datosRK[:,0], datosRK[:,1])
plt.title("Metodo RK")
plt.savefig("graficaRK.png")

