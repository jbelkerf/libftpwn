#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


char buff[100];
int main(){
    char name[8];
    int offset = 0; 
    buff[read(open("flag.txt", 'r'), buff + 42 , 30)+42] = 0;
    printf("what is your name player?\n");
    gets(name);
    printf("hello %s here is your buffer %s\n", name, (buff + offset));
}