
DIR_SRC := src
DIR_BIN := bin

bins := $(foreach p,$(wildcard ${DIR_SRC}/*.c),\
	$(patsubst ${DIR_SRC}/%.c,${DIR_BIN}/%,$p)\
)

LIB_SRC := $(wildcard lib/*.c)

all: ${bins}

${DIR_BIN}/% : ${DIR_SRC}/%.c  ${LIB_SRC} | ${DIR_BIN}
	gcc $^ -o $@ -Ilib -g -Wall -pedantic --std=c11

${DIR_BIN} :
	mkdir -p $@
