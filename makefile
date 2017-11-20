all: pipe.c
	gcc pipe.c

run: a.out
	./a.out

clean:
	rm *~
	rm *.out
