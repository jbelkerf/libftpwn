#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void win(){
    printf("congrats player you did it \n\t\t here is your flag: ");
    int flagfd = open("flag.txt", 0);
    if (flagfd < 0) {
        printf("couldn't open flag\n");
        return;
    }
    char flag[50];
    int bytes = read(flagfd, flag, 49);   // leave room for the null terminator
    if (bytes < 0) bytes = 0;
    flag[bytes] = '\0';
    printf("%s\n", flag);
    return;
}


int main(int argc , char ** argv){
    setvbuf(stdout, NULL, _IONBF, 0);
    char buff[8];
    printf("here is your hint %p\n", win);
    printf("what is you lucky name player?\n");
    printf("answer: ");
    
    read(0, buff, 60);
    return 0;
}