# Ejercicio 1

import numpy as np
import matplotlib.pylab as plt


# Use esta funcion que recibe un valor x y retorna un valor f(x) donde f es la forma funcional que debe seguir su distribucion. 
def mifun(x):
    x_0 = 3.0
    a = 0.01
    return np.exp(-(x**2))/((x-x_0)**2 + a**2)

def integral(a, b, m):
    return ((b-a)/m)*np.sum(mifun(np.linspace(a, b, m)))

integ = integral(-4, 4, 10000)

# Dentro de una funcion que reciba como parametros el numero de pasos y el sigma de la distribucion gausiana que va a usar para calcular el paso de su caminata, implemente el algortimo de Metropolis-Hastings. Finalmente, haga un histograma de los datos obtenidos y grafique en la misma grafica, la funcion de distribucion de probabilidad fx (Ojo, aca debe normalizar). Guarde la grafica sin mostrarla en un pdf. Use plt.savefig("histograma_"+str(sigma)+"_"+str(pasos)+".pdf"), donde sigma y pasos son los parametros que recibe la funcion. 

def metropolis(fun, sigma, n):
    lista = np.array([])
    l = 0
    xviejo = np.random.rand()*8 - 4
    while l<n:
        
        xnuevo = np.random.normal(0, sigma) + xviejo
        
        alpha = fun(xnuevo)/fun(xnuevo)
        beta = np.random.rand()
        
        if(alpha > 1 or beta < alpha):
            xviejo = xnuevo
            
        lista = np.append(lista, [xviejo])
        l+=1
    
    
    x = np.linspace(-4, 4, n)
    
    plt.figure()
    plt.hist(lista, 100,density=True)
    plt.plot(x, fun(x)/integ)
    plt.xlabel("X")
    plt.ylabel("Probabilidad")
    plt.title("Sigma: "+str(sigma)+"; Numero de pasos: "+str(n))
    plt.savefig("histograma_"+str(sigma)+"_"+str(n)+".png")
    

# Cuando haya verificado que su codigo funciona, use los siguientes parametros:
# sigma = 5, pasos =100000 

metropolis(mifun, 5, 100000)

# sigma = 0.2, pasos =100000 

metropolis(mifun, 0.2, 100000)

# sigma = 0.01, pasos =100000 

metropolis(mifun, 0.01, 100000)

# sigma = 0.1, pasos =1000 

metropolis(mifun, 0.1, 1000)

# sigma = 0.1, pasos =100000 

metropolis(mifun, 0.1, 100000)

# este puede ser muy demorado dependiendo del computador: sigma = 0.1, pasos =500000 

# Al ejecutar el codigo, este debe generar 6 (o 5) graficas .pdf una para cada vez que se llama a la funcion.