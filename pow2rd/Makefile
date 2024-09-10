CFLAGS= -ggdb -fno-omit-frame-pointer -Ofast -W -Wall -Wunused -Wcast-align -pedantic -pedantic-errors -fstack-protector-all -Wfloat-equal -Wpointer-arith
CC = gcc $(CFLAGS)

all: main.out

main.out: main.c pow2rd.h
	$(CC) -o main.out main.c

clean:
	rm -f perf.data perf.data.old main.out
	find * -name \*~ -delete

