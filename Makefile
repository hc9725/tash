
#CFLAGS= -Wall -O2 -D_GNU_SOURCE -DNOREADLINE
CFLAGS= -Wall -O2 -D_GNU_SOURCE -DREADLINE

LIB= ragel-pgn/libpgn.a -lreadline -ltermcap 

all: main

main: main.o scli.o strutil.o dict.o app.o
	cc -o main $^ $(LIB)

cp.c:cp.gperf
	gperf -G -C -L ANSI-C -t -Nfindcp cp.gperf --output-file cp.c

test: main
	valgrind ./main < 1 

clean:
	rm -rf *.o cp.c
