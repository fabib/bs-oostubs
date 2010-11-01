#----- START OF INPUT BLOCK -----#
TARGET=oostubs

# one of linux, linux64, sunpool
PLATFORM=sunpool

CFLAGS=-Wall -O0 -g
CXXFLAGS=
LDFLAGS=-O0
ASMFLAGS=-g

OBJECT_IGNORE= task1.o

INCPATHS=
LDPATHS=
LIBS=

GDBFLAGS=
EMUFLAGS=
DEBUGFLAGS=

#----- END OF INPUT BLOCK -----#

include misc/${PLATFORM}/config.mk
include misc/rules.mk
-include misc/${PLATFORM}/rules.mk
