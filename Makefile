CC = gcc
CFLAGS = -Wall -g
TARGET = programa

OBJ = main.o multiplicacion_estandar.o strassen.o
DATA = resultados.dat

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c multiplicacion_estandar.h strassen.h
	$(CC) $(CFLAGS) -c main.c

multiplicacion_estandar.o: multiplicacion_estandar.c multiplicacion_estandar.h
	$(CC) $(CFLAGS) -c multiplicacion_estandar.c

strassen.o: strassen.c strassen.h
	$(CC) $(CFLAGS) -c strassen.c

#REGLA PARA EJECUTAR y GRAFICAR
plot: $(TARGET)
	./$(TARGET) > $(DATA)
	gnuplot -e "set title 'Análisis Empírico: Estándar vs Strassen'; \
	            set xlabel 'Tamaño de matriz (n)'; \
	            set ylabel 'Tiempo (Microsegundos - Escala Log)'; \
	            set grid; \
	            set logscale y; \
	            set logscale x 2; \
	            set arrow from 32, graph 0 to 32, graph 1 nohead lc rgb 'red' dt 2; \
	            set label 'n_0 ≈ 32' at 32, graph 0.9 offset 1,0 tc rgb 'red'; \
	            plot '$(DATA)' using 1:2 with linespoints lw 2 title 'Estandar', \
	                 '$(DATA)' using 1:3 with linespoints lw 2 title 'Strassen'; \
	            pause mouse close"
clean:
	rm -f $(OBJ) $(TARGET) $(DATA)
