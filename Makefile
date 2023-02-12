CFLAGS = -O2 -g -Wall -Wno-unused-variable -fgnu89-inline

LIB = $(wildcard lib/*.c)
LIB_DIR = lib/
TEST = test/

all: ${TEST}/${target}.out

%.out: %.c $(LIB:%.c=%.o)
	gcc -o $@ $(CFLAGS) -I ${LIB_DIR} $^

clean:
	rm -rf *.o *.a ${TEST}/*.out main
