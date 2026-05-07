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
	gnuplot -p -e "set title 'Estandar vs Strassen'; \
	               set xlabel 'Tamaño de matriz (n)'; \
	               set ylabel 'Tiempo (microsegundos)'; \
	               set grid; \
	               set logscale x 2; \
	               plot '$(DATA)' using 1:2 with linespoints title 'Estandar', \
	                    '$(DATA)' using 1:3 with linespoints title 'Strassen'"
clean:
	rm -f $(OBJ) $(TARGET) $(DATA)
