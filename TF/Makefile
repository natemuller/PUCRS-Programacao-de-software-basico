all: campo_minado

campo_minado: CampoMinado.o Escores.o
	gcc -o campo_minado CampoMinado.o Escores.o

CampoMinado.o: CampoMinado.c escores.h
	gcc -c CampoMinado.c

Escores.o: Escores.c escores.h
	gcc -c Escores.c

clean:
	@rm -f *.o campo_minado
