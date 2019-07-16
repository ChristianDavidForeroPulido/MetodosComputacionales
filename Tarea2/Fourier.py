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
#plt.imshow(tristeTransOrganizada.real, vmax=5000)
plt.imshow(tristeTransOrganizada.real)
plt.savefig("TranformafaFourierTriste.png", vmax=1)

plt.figure()
plt.imshow(felizTransOrganizada.real)
plt.savefig("TranformafaFourierFeliz.png", vmax=1)

print("Ambas transformadas tiene el mismo tamanio: ", tristeTransOrganizada.shape==felizTransOrganizada.shape)

n = tristeTransOrganizada.shape[0]
m = tristeTransOrganizada.shape[1]

#filtros
t = 1

booleCaraTriste = np.ones((254, 170), dtype=bool)
booleCaraFeliz = np.ones((254, 170), dtype=bool)

for i in range(n):
    for j in range(m):
        if(tristeTrans[i,j] < t):
            booleCaraTriste[i,j] = False

for i in range(n):
    for j in range(m):
        if(felizTrans[i,j] > t):
            booleCaraFeliz[i,j] = False
            
tristeTrans = np.where(booleCaraTriste , tristeTrans, 0)
felizTrans = np.where(booleCaraFeliz , felizTrans, 0)

hibridaTrans = tristeTrans + felizTrans

hibridaFlitrado = np.fft.ifft2(hibridaTrans)

plt.figure()
plt.imshow(hibridaFlitrado.real)
plt.savefig("hibrida.png")