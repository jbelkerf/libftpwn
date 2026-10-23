NAME=challenge
CFLAGS = -Wno-implicit-function-declaration -Wno-deprecated-declarations
LDFLAGS = -lseccomp -lcapstone

all:
	gcc $(CFLAGS)  -fno-stack-protector -z execstack -o $(NAME) challenge.c $(LDFLAGS)