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

plt.figure()
plt.plot(euler1[:,1], euler1[:,2])
plt.savefig("pruebaEuler1.png")

plt.figure()
plt.plot(euler2[:,1], euler2[:,2])
plt.savefig("pruebaEuler2.png")

plt.figure()
plt.plot(euler3[:,1], euler3[:,2])
plt.savefig("pruebaEuler3.png")

plt.figure()
plt.plot(leapFrog1[:,1], leapFrog1[:,2])
plt.savefig("pruebaLeapFrog1.png")

plt.figure()
plt.plot(leapFrog2[:,1], leapFrog2[:,2])
plt.savefig("pruebaLeapFrog2.png")

plt.figure()
plt.plot(leapFrog3[:,1], leapFrog3[:,2])
plt.savefig("pruebaLeapFrog3.png")


plt.figure()
plt.plot(rungeKutta1[:,1], rungeKutta1[:,2])
plt.savefig("pruebaRungeKutta1.png")

plt.figure()
plt.plot(rungeKutta2[:,1], rungeKutta2[:,2])
plt.savefig("pruebaRungeKutta2.png")

plt.figure()
plt.plot(rungeKutta3[:,1], rungeKutta3[:,2])
plt.savefig("pruebaRungeKutta3.png")

