#include <stdio.h>
#include <unistd.h>

void win(){
    printf("congrats player you did it \n\t\t here is your flag: ");
    int flagfd = open("flag.txt", 'r');
    char flag[50];
    int bytes = read(flagfd, flag, 1337);
    flag[bytes] = '\0';
    printf("%s\n", flag);
}

int main(int argc , char ** argv){
    char buff[8];
    printf("what is you lucky name player?\n");
    write(1, "answer:  ", 10);
    gets(buff);
}