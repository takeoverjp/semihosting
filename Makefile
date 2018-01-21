CC=aarch64-linux-gnu-gcc
QEMU=qemu-aarch64-static
BIN=semihosting
all: $(BIN)
clean:
	rm -f *~ *.o $(BIN)
.PHONY: all clean

semihosting: semihosting.c
	$(CC) -g -O0 -o $@ -static $^
