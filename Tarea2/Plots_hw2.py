import numpy as np
import matplotlib.pyplot as plt

euler1 = np.genfromtxt("euler_dt=0.050000.dat")
euler2 = np.genfromtxt("euler_dt=0.010000.dat")
euler3 = np.genfromtxt("euler_dt=0.001000.dat")

plt.figure()
plt.plot(euler1[:,1], euler1[:,2])
plt.savefig("pruebaeuler1.png")

plt.figure()
plt.plot(euler2[:,1], euler2[:,2])
plt.savefig("pruebaeuler2.png")

plt.figure()
plt.plot(euler3[:,1], euler3[:,2])
plt.savefig("pruebaeuler3.png")