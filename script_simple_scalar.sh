#!/bin/bash

SIM_PROFILE=/usr/ensta/pack/simplescalar-3v0d/simplesim-3.0/sim-profile

PRG_SS1="heap_sort.ss"
PRG_SS2="mlp.ss"
PRG_SS3="conv2D_unroll.ss"
PRG_SS4="sha.ss"
PRG_SS5="dijkstra_large.ss"

REDIR_OUT_SIMU1="-redir:sim heap_sort.out"
REDIR_OUT_SIMU2="-redir:sim mlp.out"
REDIR_OUT_SIMU3="-redir:sim conv2D_unroll.out"
REDIR_OUT_SIMU5="-redir:sim dijkstra_large.out"

OPTIONS="-iclass -iprof"

$SIM_PROFILE $OPTIONS $REDIR_OUT_SIMU1 $PRG_SS1
$SIM_PROFILE $OPTIONS $REDIR_OUT_SIMU2 $PRG_SS2
$SIM_PROFILE $OPTIONS $REDIR_OUT_SIMU3 $PRG_SS3
$SIM_PROFILE $OPTIONS $REDIR_OUT_SIMU5 $PRG_SS5