NAME=stacky
CFLAGS = -Wno-implicit-function-declaration


all:
	gcc $(CFLAGS) -no-pie -fno-stack-protector -Wl,-Ttext-segment=0x41410000 -o challenge challenge.c 2>&1 | grep -v "gets"