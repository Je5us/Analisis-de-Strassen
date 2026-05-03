CC = gcc
CFLAGS = -Wall -g
TARGET = programa

OBJ = main.o multiplicacion_estandar.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c multiplicacion_estandar.h
	$(CC) $(CFLAGS) -c main.c

multiplicacion_estandar.o: multiplicacion_estandar.c multiplicacion_estandar.h
	$(CC) $(CFLAGS) -c multiplicacion_estandar.c

clean:
	rm -f $(OBJ) $(TARGET)
