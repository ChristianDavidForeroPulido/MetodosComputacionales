Resultados_hw2.tex : all
pdflatex Resultados_hw2.tex : FFtIm.pdf ImHybrid.pdf ImProceso.pdf XY_met_dt.pdf VxVy_met_dt.pdf Mome_met_dt.pdf Ener_met_dt.pdf

FFtIm.pdf:Fourier.py
	python Fourier.py
    
ImProceso.pdf:Fourier.py
	python Fourier.py
    
ImHybrid.pdf:Fourier.py
	python Fourier.py

XY_met_dt.pdf:Plots_hw2.py
	python Plots_hw2.py

VxVy_met_dt.pdf:Plots_hw2.py
	python Plots_hw2.py

Mome_met_dt.pdf:Plots_hw2.py
	python Plots_hw2.py
    
Ener_met_dt.pdf:Plots_hw2.py
	python Plots_hw2.py

Plots_hw2.py : euler_dt=0.050000.dat euler_dt=0.010000.dat euler_dt=0.001000.dat leapFrog_dt=0.050000.dat leapFrog_dt=0.010000.dat leapFrog_dt=0.001000.dat rungeKutta_dt=0.050000.dat rungeKutta_dt=0.010000.dat rungeKutta_dt=0.001000.dat
	python Plots_hw2.py

euler_dt=0.050000.dat :a.out
	./a.out
    
euler_dt=0.010000.dat : a.out
	./a.out
    
euler_dt=0.001000.dat : a.out
	./a.out
    
leapFrog_dt=0.050000.dat : a.out
	./a.out
    
leapFrog_dt=0.010000.dat :a .out
	./a.out
    
leapFrog_dt=0.001000.dat : a.out
	./a.out
    
rungeKutta_dt=0.050000.dat : a.out
	./a.out
    
rungeKutta_dt=0.010000.dat : a.out
	./a.out
    
rungeKutta_dt=0.001000.dat : a.out
	./a.out
    
a.out:ODEs.cpp
	g++ ODEs.cpp