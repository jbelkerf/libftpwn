#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


char buff[100];
int fd, bytes;


int main(){
    setvbuf(stdout, NULL, _IONBF, 0);
    char name[8];
    int auth = 0;
    int offset = 0; 
    fd = open("flag.txt", 0);
    bytes = read(fd, buff + 42 , 30);
    buff[bytes+42] = 0;
    printf("what is your name player?\n");
    read(0, name, 16);
    if (auth)
        printf("hello %s here is your buffer %s\n", name, (buff + 42));
    else
        printf("you are not autorized \n");
}