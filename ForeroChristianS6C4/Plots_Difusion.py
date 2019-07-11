import numpy as np
import matplotlib.pylab as plt
from mpl_toolkits import mplot3d

X = np.linspace(0, 1, 101)
Y = np.linspace(0, 1, 101)
X, Y = np.meshgrid(X, Y)

##Frontera 3, fronteras libres

frontera1Tiempo1 = np.genfromtxt("datosFrontera1.dat", skip_footer = 202)
frontera1Tiempo2 = np.genfromtxt("datosFrontera1.dat", skip_header = 101, skip_footer = 101)
frontera1Tiempo3 = np.genfromtxt("datosFrontera1.dat", skip_header = 202)

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X, Y, frontera1Tiempo1, cmap="plasma", linewidth=0, antialiased=False)
plt.savefig("frontera1Tiempo1.png")

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X, Y, frontera1Tiempo2, cmap="plasma", linewidth=0, antialiased=False)
plt.savefig("frontera1Tiempo2.png")

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X, Y, frontera1Tiempo3, cmap="plasma", linewidth=0, antialiased=False)
plt.savefig("frontera1Tiempo3.png")

##Frontera 2, fronteras periodicas

frontera2Tiempo1 = np.genfromtxt("datosFrontera2.dat", skip_footer = 202)
frontera2Tiempo2 = np.genfromtxt("datosFrontera2.dat", skip_header = 101, skip_footer = 101)
frontera2Tiempo3 = np.genfromtxt("datosFrontera2.dat", skip_header = 202)

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X, Y, frontera2Tiempo1, cmap="plasma", linewidth=0, antialiased=False)
plt.savefig("frontera2Tiempo1.png")

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X, Y, frontera2Tiempo2, cmap="plasma", linewidth=0, antialiased=False)
plt.savefig("frontera2Tiempo2.png")

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X, Y, frontera2Tiempo3, cmap="plasma", linewidth=0, antialiased=False)
plt.savefig("frontera2Tiempo3.png")

##Frontera 3, fronteras fijas

frontera3Tiempo1 = np.genfromtxt("datosFrontera3.dat", skip_footer = 202)
frontera3Tiempo2 = np.genfromtxt("datosFrontera3.dat", skip_header = 101, skip_footer = 101)
frontera3Tiempo3 = np.genfromtxt("datosFrontera3.dat", skip_header = 202)

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X, Y, frontera3Tiempo1, cmap="plasma", linewidth=0, antialiased=False)
plt.savefig("frontera3Tiempo1.png")

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X, Y, frontera3Tiempo2, cmap="plasma", linewidth=0, antialiased=False)
plt.savefig("frontera3Tiempo2.png")

fig = plt.figure()
ax = fig.gca(projection='3d')
surf = ax.plot_surface(X, Y, frontera3Tiempo3, cmap="plasma", linewidth=0, antialiased=False)
plt.savefig("frontera3Tiempo3.png")