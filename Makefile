
DIR_SRC := src
DIR_BIN := bin

bins := $(foreach p,$(wildcard ${DIR_SRC}/*.c),\
	$(patsubst ${DIR_SRC}/%.c,${DIR_BIN}/%,$p)\
)

LIB := $(wildcard lib/*)
CC := gcc
ARCH := linux

DEPS := ${LIB} $(wildcard lib_${ARCH}/*) Makefile

all: ${bins}

${DIR_BIN}/% : ${DIR_SRC}/%.c ${DEPS} | ${DIR_BIN}
	${CC} $(filter %.c,$^) -o $@ -Ilib -Ilib_${ARCH} -g -Wall -pedantic

${DIR_BIN} :
	mkdir -p $@
