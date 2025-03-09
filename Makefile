# SimpleScalar
SS_CC=/usr/ensta/pack/simplescalar-3v0d/bin/sslittle-na-sstrix-gcc
SIM = /usr/ensta/pack/simplescalar-3v0d/simplesim-3.0/sim-outorder

CC=${SS_CC}

all: heap_sort.ss mlp.ss conv2D_unroll.ss dijkstra_large.ss

#sim-outorder
#Cortex A7
simulate:
	$(SIM) \
		-fetch:ifqsize 4 \
		-decode:width 2 \
		-issue:width 4 \
		-commit:width 2 \
		-ruu:size 2 \
		-lsq:size 8 \
		-res:ialu 1 \
		-res:fpalu 1 \
		-res:imult 1 \
		-res:fpmult 1 \
		-bpred bimod \
		-bpred:bimod 256 \
		-bpred:ras 8 \
		-cache:il1 il1:16:32:2:l \
		-cache:dl1 dl1:16:32:2:l \
		-cache:il2 il2:512:32:8:l \
		-cache:dl2 dl2:512:32:8:l \
		mlp.ss

#Cortex A15
#-fetch:ifqsize 8 
#-decode:width 4 
#-issue:width 8 
#-commit:width 4 
#-ruu:size 16 
#-lsq:size 16 
#-res:ialu 5 
#-res:fpalu 1 
#-res:imult 1 
#-res:fpmult 1 
#-bpred 2lev 
#-bpred:btb 256 4
#-bpred:ras 16 
#-cache:il1 il1:2:64:2:l 
#-cache:dl1 dl1:2:64:2:l 
#-cache:il2 il2:512:64:16:l 
#-cache:dl2 dl2:512:64:16:l 

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
