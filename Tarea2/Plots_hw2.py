import numpy as np
import matplotlib.pyplot as plt

euler1 = np.genfromtxt("euler_dt=0.050000.dat")
euler2 = np.genfromtxt("euler_dt=0.010000.dat")
euler3 = np.genfromtxt("euler_dt=0.001000.dat")

leapFrog1 = np.genfromtxt("leapFrog_dt=0.050000.dat")
leapFrog2 = np.genfromtxt("leapFrog_dt=0.010000.dat")
leapFrog3 = np.genfromtxt("leapFrog_dt=0.001000.dat")

rungeKutta1 = np.genfromtxt("rungeKutta_dt=0.050000.dat")
rungeKutta2 = np.genfromtxt("rungeKutta_dt=0.010000.dat")
rungeKutta3 = np.genfromtxt("rungeKutta_dt=0.001000.dat")

#Graficas para todos los metodos y todos los dt d X CONTRA Y
plt.figure(figsize=(15,15))

plt.subplot(3,3,1)
plt.plot(euler1[:,1], euler1[:,2], color="blue")
plt.title("Euler con dt = 0.05")
plt.xlabel("X (unidades astronomicas)")
plt.ylabel("Y (unidades astronomicas)")

plt.subplot(3,3,2)
plt.plot(euler2[:,1], euler2[:,2], color="blue")
plt.title("Euler con dt = 0.01")
plt.xlabel("X (unidades astronomicas)")
plt.ylabel("Y (unidades astronomicas)")

plt.subplot(3,3,3)
plt.plot(euler3[:,1], euler3[:,2], color="blue")
plt.title("Euler con dt = 0.001")
plt.xlabel("X (unidades astronomicas)")
plt.ylabel("Y (unidades astronomicas)")

plt.subplot(3,3,4)
plt.plot(leapFrog1[:,1], leapFrog1[:,2], color="green")
plt.title("Leapfrog con dt = 0.05")
plt.xlabel("X (unidades astronomicas)")
plt.ylabel("Y (unidades astronomicas)")

plt.subplot(3,3,5)
plt.plot(leapFrog2[:,1], leapFrog2[:,2], color="green")
plt.title("Leapfrog con dt = 0.01")
plt.xlabel("X (unidades astronomicas)")
plt.ylabel("Y (unidades astronomicas)")

plt.subplot(3,3,6)
plt.plot(leapFrog3[:,1], leapFrog3[:,2], color="green")
plt.title("Leapfrog con dt = 0.001")
plt.xlabel("X (unidades astronomicas)")
plt.ylabel("Y (unidades astronomicas)")

plt.subplot(3,3,7)
plt.plot(rungeKutta1[:,1], rungeKutta1[:,2], color="red")
plt.title("RungeKutta con dt = 0.05")
plt.xlabel("X (unidades astronomicas)")
plt.ylabel("Y (unidades astronomicas)")

plt.subplot(3,3,8)
plt.plot(rungeKutta2[:,1], rungeKutta2[:,2], color="red")
plt.title("RungeKutta con dt = 0.01")
plt.xlabel("X (unidades astronomicas)")
plt.ylabel("Y (unidades astronomicas)")

plt.subplot(3,3,9)
plt.plot(rungeKutta2[:,1], rungeKutta2[:,2], color="red")
plt.title("RungeKutta con dt = 0.001")
plt.xlabel("X (unidades astronomicas)")
plt.ylabel("Y (unidades astronomicas)")

plt.savefig("posiciones.png")

#Graficas para todos los metodos y todos los dt de ENERGIA CONTRA TIEMPO
plt.figure(figsize=(15,15))

plt.subplot(3,3,1)
plt.plot(euler1[:,0], euler1[:,5], color="blue")
plt.title("Euler con dt = 0.05")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Energia (MasaSolar*(AU/anios)**2)")

plt.subplot(3,3,2)
plt.plot(euler2[:,0], euler2[:,5], color="blue")
plt.title("Euler con dt = 0.01")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Energia (MasaSolar*(AU/anios)**2)")

plt.subplot(3,3,3)
plt.plot(euler3[:,0], euler3[:,5], color="blue")
plt.title("Euler con dt = 0.001")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Energia (MasaSolar*(AU/anios)**2)")

plt.subplot(3,3,4)
plt.plot(leapFrog1[:,0], leapFrog1[:,5], color="green")
plt.title("Leapfrog con dt = 0.05")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Energia (MasaSolar*(AU/anios)**2)")

plt.subplot(3,3,5)
plt.plot(leapFrog2[:,0], leapFrog2[:,5], color="green")
plt.title("Leapfrog con dt = 0.01")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Energia (MasaSolar*(AU/anios)**2)")

plt.subplot(3,3,6)
plt.plot(leapFrog3[:,0], leapFrog3[:,5], color="green")
plt.title("Leapfrog con dt = 0.001")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Energia (MasaSolar*(AU/anios)**2)")

plt.subplot(3,3,7)
plt.plot(rungeKutta1[:,0], rungeKutta1[:,5], color="red")
plt.title("RungeKutta con dt = 0.05")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Energia (MasaSolar*(AU/anios)**2)")

plt.subplot(3,3,8)
plt.plot(rungeKutta2[:,0], rungeKutta2[:,5], color="red")
plt.title("RungeKutta con dt = 0.01")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Energia (MasaSolar*(AU/anios)**2)")

plt.subplot(3,3,9)
plt.plot(rungeKutta2[:,0], rungeKutta2[:,5], color="red")
plt.title("RungeKutta con dt = 0.001")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Energia (MasaSolar*(AU/anios)**2)")

plt.savefig("energia.png")

#Graficas para todos los metodos y todos los dt de MOMENTO CONTRA TIEMPO
plt.figure(figsize=(15,15))

plt.subplot(3,3,1)
plt.plot(euler1[:,0], euler1[:,6], color="blue")
plt.title("Euler con dt = 0.05")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Momento Angular (MasaSolar*(AU**2)/anios")

plt.subplot(3,3,2)
plt.plot(euler2[:,0], euler2[:,6], color="blue")
plt.title("Euler con dt = 0.01")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Momento Angular (MasaSolar*(AU**2)/anios")

plt.subplot(3,3,3)
plt.plot(euler3[:,0], euler3[:,6], color="blue")
plt.title("Euler con dt = 0.001")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Momento Angular (MasaSolar*(AU**2)/anios")

plt.subplot(3,3,4)
plt.plot(leapFrog1[:,0], leapFrog1[:,6], color="green")
plt.title("Leapfrog con dt = 0.05")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Momento Angular (MasaSolar*(AU**2)/anios")

plt.subplot(3,3,5)
plt.plot(leapFrog2[:,0], leapFrog2[:,6], color="green")
plt.title("Leapfrog con dt = 0.01")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Momento Angular (MasaSolar*(AU**2)/anios")

plt.subplot(3,3,6)
plt.plot(leapFrog3[:,0], leapFrog3[:,6], color="green")
plt.title("Leapfrog con dt = 0.001")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Momento Angular (MasaSolar*(AU**2)/anios")

plt.subplot(3,3,7)
plt.plot(rungeKutta1[:,0], rungeKutta1[:,6], color="red")
plt.title("RungeKutta con dt = 0.05")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Momento Angular (MasaSolar*(AU**2)/anios")

plt.subplot(3,3,8)
plt.plot(rungeKutta2[:,0], rungeKutta2[:,6], color="red")
plt.title("RungeKutta con dt = 0.01")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Momento Angular (MasaSolar*(AU**2)/anios")

plt.subplot(3,3,9)
plt.plot(rungeKutta2[:,0], rungeKutta2[:,6], color="red")
plt.title("RungeKutta con dt = 0.001")
plt.xlabel("Tiempo (anios)")
plt.ylabel("Momento Angular (MasaSolar*(AU**2)/anios")

plt.savefig("momento.png")

#Graficas para todos los metodos y todos los dt de VELOCIDADES
plt.figure(figsize=(15,15))

plt.subplot(3,3,1)
plt.plot(euler1[:,3], euler1[:,4], color="blue")
plt.title("Euler con dt = 0.05")
plt.xlabel("Velocidad en x (AU/anios)")
plt.ylabel("Velocidad en y (AU/anios)")

plt.subplot(3,3,2)
plt.plot(euler2[:,3], euler2[:,4], color="blue")
plt.title("Euler con dt = 0.01")
plt.xlabel("Velocidad en x (AU/anios)")
plt.ylabel("Velocidad en y (AU/anios)")

plt.subplot(3,3,3)
plt.plot(euler3[:,3], euler3[:,4], color="blue")
plt.title("Euler con dt = 0.001")
plt.xlabel("Velocidad en x (AU/anios)")
plt.ylabel("Velocidad en y (AU/anios)")

plt.subplot(3,3,4)
plt.plot(leapFrog1[:,3], leapFrog1[:,4], color="green")
plt.title("Leapfrog con dt = 0.05")
plt.xlabel("Velocidad en x (AU/anios)")
plt.ylabel("Velocidad en y (AU/anios)")

plt.subplot(3,3,5)
plt.plot(leapFrog2[:,3], leapFrog2[:,4], color="green")
plt.title("Leapfrog con dt = 0.01")
plt.xlabel("Velocidad en x (AU/anios)")
plt.ylabel("Velocidad en y (AU/anios)")

plt.subplot(3,3,6)
plt.plot(leapFrog3[:,3], leapFrog3[:,4], color="green")
plt.title("Leapfrog con dt = 0.001")
plt.xlabel("Velocidad en x (AU/anios)")
plt.ylabel("Velocidad en y (AU/anios)")

plt.subplot(3,3,7)
plt.plot(rungeKutta1[:,3], rungeKutta1[:,4], color="red")
plt.title("RungeKutta con dt = 0.05")
plt.xlabel("Velocidad en x (AU/anios)")
plt.ylabel("Velocidad en y (AU/anios)")

plt.subplot(3,3,8)
plt.plot(rungeKutta2[:,3], rungeKutta2[:,4], color="red")
plt.title("RungeKutta con dt = 0.01")
plt.xlabel("Velocidad en x (AU/anios)")
plt.ylabel("Velocidad en y (AU/anios)")

plt.subplot(3,3,9)
plt.plot(rungeKutta2[:,3], rungeKutta2[:,4], color="red")
plt.title("RungeKutta con dt = 0.001")
plt.xlabel("Velocidad en x (AU/anios)")
plt.ylabel("Velocidad en y (AU/anios)")

plt.savefig("velocidades.png")