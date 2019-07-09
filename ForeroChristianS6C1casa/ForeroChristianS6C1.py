import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("datos.dat")

x = np.linspace(0,2, 1000)

plt.figure()
plt.plot(x, datos[-1,1:], color="black")
plt.title("Solucion a ecuacion de adveccion")
plt.xlabel("Tiempo en segundos")
plt.ylabel("Posicion en metros")
plt.savefig("grafica.png")