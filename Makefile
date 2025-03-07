# Warning, this makefile requires that you correctly set SS_CC
SS_CC=/usr/ensta/pack/simplescalar-3v0d/bin/sslittle-na-sstrix-gcc

CC=${SS_CC}

all: heap_sort.ss mlp.ss conv2D_unroll.ss dijkstra_large.ss

heap_sort.ss:
	$(CC) -O -o heap_sort.ss heap_sort.c

mlp.ss:
	$(CC) -O -o mlp.ss mlp.c

conv2D_unroll.ss:
	$(CC) -O -o conv2D_unroll.ss conv2D_unroll.c

dijkstra_large.ss:
	$(CC) -O -o dijkstra_large.ss dijkstra_large.c	

.PHONY:all clean

clean:
	rm heap_sort.ss
	rm mlp.ss
	rm conv2D_unroll.ss
	rm dijkstra_large.ss