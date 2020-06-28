all: tokenize

tokenize: tokenize.c history.c mainUI.c
	gcc $^ -o $@

clean:
	rm -f *.o *.c~ tokenize
