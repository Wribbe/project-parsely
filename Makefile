
DIR_SRC := src
DIR_BIN := bin

bins := $(foreach p,$(wildcard ${DIR_SRC}/*.c),\
	$(patsubst ${DIR_SRC}/%.c,${DIR_BIN}/%,$p)\
)

LIB_SRC := $(wildcard lib/*.c)
CC := gcc
ARCH := linux

DEPS := ${LIB_SRC} $(wildcard lib_${ARCH}/*) Makefile

all: ${bins}

${DIR_BIN}/% : ${DIR_SRC}/%.c ${DEPS} | ${DIR_BIN}
	${CC} $(filter %.c,$^) -o $@ -Ilib -Ilib_${ARCH} -g -Wall -pedantic --std=c11

${DIR_BIN} :
	mkdir -p $@
