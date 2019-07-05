import numpy as np
import matplotlib.pyplot as plt

datos = np.genfromtxt("datosLeapFrog.dat")

plt.figure()
plt.plot(datos[:,0], datos[:,1], color="black")
plt.title("Solucion a ecuacion diferencial de movimiento armonico")
plt.xlabel("Tiempo en segundos")
plt.ylabel("Posicion en metros")
plt.savefig("ForeroChristianResorte.pdf")