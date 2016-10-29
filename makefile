GCC = gcc -g

all: stat.c
	$(GCC) stat.c -o out

clean:
	rm *.o
	rm *~

run: all
	./out

debug: all
	gdb out