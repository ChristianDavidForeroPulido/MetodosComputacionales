import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

datos1 = np.genfromtxt("datosCaso1.dat")
datos2 = np.genfromtxt("datosCaso2.dat")
datos3 = np.genfromtxt("datosCaso3.dat")

x = np.linspace(0,1, int(1/0.005))

plt.figure()
plt.plot(x, datos1[0,1:], color="black", label="0 iteraciones")
plt.plot(x, datos1[250,1:], color="red", label="250 iteraciones")
plt.plot(x, datos1[500,1:], color="green", label="500 iteraciones")
plt.plot(x, datos1[750,1:], color="blue", label="750 iteraciones")
plt.title("Solucion a ecuacion de Onda Caso 1")
plt.xlabel("Posicion X en metros")
plt.ylabel("Posicion Y en metros")
plt.legend()
plt.savefig("grafica1.png")

plt.figure()
plt.plot(x, datos2[0,1:], color="black", label="0 iteraciones")
plt.plot(x, datos2[250,1:], color="red", label="250 iteraciones")
plt.plot(x, datos2[500,1:], color="green", label="500 iteraciones")
plt.plot(x, datos2[750,1:], color="blue", label="750 iteraciones")
plt.title("Solucion a ecuacion de Onda Caso 2")
plt.xlabel("Posicion X en metros")
plt.ylabel("Posicion Y en metros")
plt.legend()
plt.savefig("grafica2.png")

plt.figure()
plt.plot(x, datos3[0,1:], color="black", label="0 iteraciones")
plt.plot(x, datos3[250,1:], color="red", label="250 iteraciones")
plt.plot(x, datos3[500,1:], color="green", label="500 iteraciones")
plt.plot(x, datos3[750,1:], color="blue", label="750 iteraciones")
plt.title("Solucion a ecuacion de Onda Caso 3")
plt.xlabel("Posicion X en metros")
plt.ylabel("Posicion Y en metros")
plt.legend()
plt.savefig("grafica3.png")

def update_line(num, data, line):
    line.set_data(x, data[50*num,1:])
    return line,

fig1 = plt.figure()

l, = plt.plot([], [], 'r-')

plt.xlim(0, 1)
plt.ylim(-0.011, 0.011)
plt.xlabel("Posicion X en metros")
plt.ylabel("Posicion Y en metros")
plt.title("Solucion Ec Onda Caso 1")
line_ani = animation.FuncAnimation(fig1, update_line, 48, fargs=(datos1, l),interval=100, blit=True)
line_ani.save("Caso1.gif")

fig2 = plt.figure()

l, = plt.plot([], [], 'r-')

plt.xlim(0, 1)
plt.ylim(-0.011, 0.011)
plt.xlabel("Posicion X en metros")
plt.ylabel("Posicion Y en metros")
plt.title("Solucion Ec Onda Caso 2")
line_ani = animation.FuncAnimation(fig2, update_line, 48, fargs=(datos2, l),interval=100, blit=True)
line_ani.save("Caso2.gif")

fig3 = plt.figure()

l, = plt.plot([], [], 'r-')

plt.xlim(0, 1)
plt.ylim(-0.021, 0.021)
plt.xlabel("Posicion X en metros")
plt.ylabel("Posicion Y en metros")
plt.title("Solucion Ec Onda Caso 3")
line_ani = animation.FuncAnimation(fig3, update_line, 48, fargs=(datos3, l),interval=100, blit=True)
line_ani.save("Caso3.gif")