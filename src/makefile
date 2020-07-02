all: tokenize

tokenize: tokenize.c mainUI.c history.c
	gcc $^ -o $@

clean:
	rm -f *.o *.c~ tokenize
run:
	gcc mainUI.c -o mainUI
