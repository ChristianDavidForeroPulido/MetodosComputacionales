import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq

#Datos Imagenes
triste = plt.imread("cara_02_grisesMF.png")
feliz = plt.imread("cara_03_grisesMF.png")

#Transformada de fourier usando scipy
tristeTrans = np.fft.fft2(triste)
felizTrans = np.fft.fft2(feliz)

#Graficas espectro de fourier de cada imagen
tristeTransOrganizada = np.fft.fftshift(tristeTrans)
felizTransOrganizada = np.fft.fftshift(felizTrans)

plt.figure()

plt.subplot(1, 2, 1)
plt.imshow(tristeTransOrganizada.real, vmin=-100, vmax=100)
plt.title("Transformada de Fourier Triste")

plt.subplot(1, 2, 2)
plt.imshow(felizTransOrganizada.real, vmin=-100, vmax=100)
plt.title("Transformada de Fourier Feliz")

plt.savefig("FFtIm.pdf")

n = tristeTransOrganizada.shape[0]
m = tristeTransOrganizada.shape[1]

#filtros
t_menor = 14
t_mayor = 14

booleCaraTriste = np.ones((254, 170), dtype=bool)
booleCaraFeliz = np.ones((254, 170), dtype=bool)

for i in range(n):
    for j in range(m):
        if(tristeTrans[i,j] > t_menor):
            booleCaraTriste[i,j] = False

for i in range(n):
    for j in range(m):
        if(felizTrans[i,j] < t_mayor):
            booleCaraFeliz[i,j] = False
            
tristeTrans = np.where(booleCaraTriste , tristeTrans, 0)
felizTrans = np.where(booleCaraFeliz , felizTrans, 0)

plt.figure()

plt.subplot(1, 2, 1)
plt.imshow(tristeTrans.real, vmin=-100, vmax=100)
plt.title("Transformada filtrada Triste")

plt.subplot(1, 2, 2)
plt.imshow(felizTrans.real, vmin=-100, vmax=100)
plt.title("Transformada filtrada Feliz")

plt.savefig("ImProceso.pdf")

hibridaTrans = tristeTrans + felizTrans

hibridaFlitrado = np.fft.ifft2(hibridaTrans)

plt.figure()
plt.imshow(-hibridaFlitrado.real, cmap="Greys")
plt.title("Imagen hibrida de cara feliz y triste")
plt.savefig("ImHybrid.pdf")