#include <stdio.h>
#include <unistd.h>

void win(){
    printf("congrats player you did it \n\t\t here is your flag: ");
    system("cat flag.txt");
}

int main(int argc , char ** argv){
    char buff[8];
    printf("what is you lucky name player?\n");
    write(1, "answer:  ", 10);
    gets(buff);
}