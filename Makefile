

SRC = $(wildcard src/*)
OBJECTS = $(foreach file, $(SRC), out/$(basename $(notdir $(file))).o) #defino object, a partir de la carpeta SRC, todos los .c

CC = gcc
CFLAGS = -Wall -std=c99 -Iinc #-Iinc: incorpora los .h, 

all: out $(OBJECTS)  #;Targets: "...:", particularmente "all:" es "compila todo"
	@echo Building...
	@$(CC) -o main.exe $(OBJECTS) -lm #crea el ejecutable. Chequea si estan todos los .o, si no lo hizo, pasa a los "out:"
	@echo Done

out: 	
	@mkdir -p $@

out/%.o: src/%.c  #Convierto los .c a .o (object)
	@echo CC $<
	@$(CC) $(CFLAGS) -c -o $@ $< #Compilar los .c a .o

clean:
	rm -rf out
