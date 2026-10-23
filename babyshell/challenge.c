#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
    char buff[1100];
    printf("gimme your recipie\n");
    read(0, buff, 1100);
    ((void(*)())buff)();
}
