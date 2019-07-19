import numpy as np
import matplotlib.pyplot as plt

particula = np.genfromtxt("trayectoriaParticula.dat")

plt.figure(figsize=(10,10))

plt.subplot(2,2,1)
plt.plot(particula[:,1], particula[:,2], color="red")
plt.title("Posicion x contra y")
plt.xlabel("X (metros)")
plt.ylabel("Y (metros)")

plt.subplot(2,2,2)
plt.plot(particula[:,1], particula[:,3], color="green")
plt.title("Posicion x contra z")
plt.xlabel("X (metros)")
plt.ylabel("Z (metros)")

plt.subplot(2,2,3)
plt.plot(particula[:,2], particula[:,3], color="blue")
plt.title("Posicion y contra z")
plt.xlabel("Y (metros)")
plt.ylabel("Z (metros)")

plt.savefig("PlotParticula.png")