ForeroChristian_S5C3_plots.py : a.out
	python ForeroChristian_S5C3_plots.py

a.out : ForeroChristian_S5C3_ODEs.cpp
	g++ ForeroChristian_S5C3_ODEs.cpp