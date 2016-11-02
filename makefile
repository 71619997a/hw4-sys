GCC = gcc -g

all: stat.c
	$(GCC) stat.c -o out.out

clean:
	rm *.out
	rm *~

run: all
	./out.out

debug: all
	gdb out.out