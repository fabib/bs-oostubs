CC=gcc
CXX=g++
ASM=gcc
LD=ld
EMU=qemu
EMUTARGET=${TARGET}
GDB=gdb
SED=sed
OBJDUMP=objdump
DOCGEN=doxygen

CFLAGS+=-fno-exceptions -m32 -fno-stack-protector
CXXFLAGS+=${CFLAGS} -fno-rtti -nostdinc++
LDFLAGS=-e entry -T misc/sections -melf_i386
ASMFLAGS=--32

OBJDUMPFLAGS=-Cxd
EMUFLAGS+=-no-kvm -kernel
DEBUGFLAGS+=-s -S
GDBFLAGS+=-x misc/gdb.script

LDHEAD := $(addprefix misc/linux64/build/, crti.o crtbegin.o)
LDTAIL := $(addprefix misc/linux64/build/, crtend.o crtn.o)
