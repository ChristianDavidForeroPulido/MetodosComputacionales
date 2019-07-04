import numpy as np
import matplotlib.pyplot as plt

datosEuler = np.genfromtxt("datosEuler.txt")
datosRK = np.genfromtxt("datosRK.txt")

plt.figure(figsize=(12,7))
plt.subplot(1,2,1)
plt.plot(datosEuler[:,0], datosEuler[:,1], color="black", label="Metodo Euler")
plt.legend()

plt.subplot(1,2,2)
plt.plot(datosRK[:,0], datosRK[:,1], label="Metodo RK")
plt.legend()

plt.savefig("graficasODE.png")