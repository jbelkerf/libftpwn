#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 #include <fcntl.h>

char flag[50];



void game(){
    printf("Welcome to the game!\n");
    size_t number = 0;
    printf("gimme your lucky number \n");
    scanf("%ld", &number);
    if (number == 1){
        printf("good choise but it gives nothing\n");
    }
    else if (number == 0)
    {
        printf("that's leteraly notong\n");
    }
    else if (number == 1337){
        printf("lucky number , i will give you a hint try play with the integer\n");

    }
    else if ((int)number <0)
    {
        printf("oh you crash it here is your flag : %s\n", flag);
    }
}

int main(int argc, char **argv){
    setvbuf(stdout, NULL, _IONBF, 0);
    int fd = open("flag.txt", 0);
    
    int bytes = read(fd, flag, 50);
    flag[bytes] = '\0';

    game();
}