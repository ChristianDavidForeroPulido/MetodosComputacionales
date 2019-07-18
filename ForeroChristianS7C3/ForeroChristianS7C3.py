#Ejercicio 1 Terminar lo que hizo en clase + dos preguntas adicionales (en mayusculas en el texto)

import numpy as np
import matplotlib.pylab as plt


# 1) lea los datos de resorte.dat y almacenelos.
# 
resorte = np.genfromtxt("resorte.dat")

# Los datos corresponden a las posiciones en x de un oscilador (masa resorte) en funcion del tiempo. La ecuacion de movimiento esta dada por  
# xt=a*np.exp(-gamma*t)*np.cos(omega*t)
# Donde a, gamma, y omega son parametros.
def mifun(t, ah, gammah, omegah):
    return ah*np.exp(- gammah*t)*np.cos(omegah*t)

# 2) Implemente un algoritmo que le permita, por medio de estimacion bayesiana de parametros, encontrar los parametros correspondientes a los datos d. Para esto debe:

def likelihood(aT, gammaT, omegaT, sigmaT):
    xMod = mifun(resorte[:,0], aT, gammaT, omegaT)
    return np.exp(-0.5*(np.sum(resorte[:,1]-xMod))/sigmaT)

# 2a.) definir una funcion que reciba los parametros que se busca estimar y los datos de tiempo y retorne el modelo  

def bayesiana(a0, gamma0, omega0, sigma, n):
    aViejo = a0
    gammaViejo = gamma0
    omegaViejo = omega0
    
    listaA = np.array([aViejo])
    listaGamma = np.array([gammaViejo])
    listaOmega = np.array([omegaViejo])
    
    for i in range (n):
        aNuevo = np.random.normal(aViejo, sigma)
        gammaNuevo = np.random.normal(gammaViejo, sigma)
        omegaNuevo = np.random.normal(omegaViejo, sigma)
        
        alpha = likelihood(aNuevo, gammaNuevo, omegaNuevo, sigma)/likelihood(aViejo, gammaViejo, omegaViejo, sigma)
        beta = np.random.rand()
        
        if(alpha > 1 or beta < alpha):
            aViejo = aNuevo
            gammaViejo = gammaNuevo
            omegaViejo = omegaNuevo
            
        listaA = np.append(listaA, [aViejo])
        listaGamma = np.append(listaGamma, [gammaViejo])
        listaOmega = np.append(listaOmega, [omegaViejo])
        
    return listaA, listaGamma, listaOmega

# 2b.) Definir una funcion que retorne la funcion de verosimilitud

# 2c.) Caminata

#condiciones iniciales
aini=7.5
gammaini=0.6
omegaini=18.2

#numero de pasos
iteraciones=100000


# 2d.) Seleccione los mejores parametros E IMPRIMA UN MENSAJE QUE DIGA: "LOS MEJORES PARAMETROS SON a=... gamma=... Y omgega=..."

resultadosA, resultadosGamma, resultadosOmega = bayesiana(aini, gammaini, omegaini, 0.1, iteraciones)

listaLikelihoods = np.array([])

for k in range(len(resultadosA)):
    listaLikelihoods = np.append(listaLikelihoods, [likelihood(resultadosA[k], resultadosGamma[k], resultadosOmega[k], 0.1)])

j = np.argmax(listaLikelihoods)


print("LOS MEJORES PARAMETROS SON a = "+str(resultadosA[j])+", gamma = "+str(resultadosGamma[j])+" y omgega = "+str(resultadosOmega[j])+".")

# 2f.) Grafique sus datos originales y su modelo con los mejores parametros. Guarde su grafica sin mostrarla en Resorte.pdf

t = np.linspace(0.0, 5.0, 1000)
x = mifun(t, resultadosA[j], resultadosGamma[j], resultadosOmega[j])

plt.figure()
plt.scatter(resorte[:,0], resorte[:,1], s=4)
plt.plot(t, x)
plt.savefig("Resorte.pdf")

# 3) SABIENDO QUE omega=np.sqrt(k/m), IMPRIMA UN MENSAJE DONDE EXPLIQUE SI PUEDE O NO DETERMINAR k Y m DE MANERA INDIVIDUAL USANDO EL METODO ANTERIOR. JUSTIFIQUE BIEN SU RESPUESTA (PUEDE ADEMAS HACER PRUEBAS CON EL CODIGO PARA RESPONDER ESTA PREGUNTA).

print("No se puede porque los parametros k y m estan juntos, es decir que parecen un parametro solo, si estuvieran sumas o almenos separados, si seria posible")