NAME=stacky

all:
	gcc -no-pie -fno-stack-protector -fuse-ld=bfd -Wl,-Ttext-segment=0x41410000 -o challenge challenge.c