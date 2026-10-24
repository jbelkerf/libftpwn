#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


char ** arr;
int count;
char *secret;

void allocate(){
    int indx = 0;
    int size = 0;
    printf("gimme the index you picked \n");
    scanf("%d", &indx);
    if (indx >= 6 || indx < 0)
    {
        return allocate();
    }
    printf("gimme the size you want to malloc \n");
    scanf("%d", &size);

    arr[indx] = malloc(size);
    printf("you allocaed %d bytes in index %d\n", size, indx);
}

void freeit(){
    int indx = 0;
    printf("gimme the index you picked to free\n");
    scanf("%d", &indx);
    if (indx >= 6 || indx < 0)
    {
        return freeit();
    }
    free(arr[indx]);
}

void getit(){
    int indx = 0;
    printf("gimme the index you picked to fill\n");
    scanf("%d", &indx);
    if (indx >= 6 || indx < 0)
    {
        return getit();
    }
    gets(arr[indx]);
}

#include <string.h>

void checkit(){
    int indx = 0;
    printf("gimme the index you picked to check against the secret\n");
    scanf("%d", &indx);
    if (indx >= 6 || indx < 0)
    {
        return checkit();
    }
    char * flag = malloc(31);
    flag[read(open("flag.txt", 0), flag, 30)] = 0;
    if (strcmp(secret, arr[indx]) == 0)
    {
        printf("here is your flag player: %s \n",flag);
        exit(1);
    }
}

void game(){
    while (1){
        printf("pick a number\n\t1: malloc\n\t2: free\n\t3:fill\n\t4:check the secret\n");
        int choise = 0;
        scanf("%d", &choise);
        if (choise == 1)
            allocate();
        else if (choise == 2)
            freeit();
        else if (choise == 3){
            getit();
        }
        else if (choise == 4)
        {
            checkit();
        }
        else {
            printf("wrong choise \n");
            exit(1);
        }
    }
}
static char mybuf[1024];
int main(){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdout, mybuf, _IONBF, sizeof(mybuf));
    setvbuf(stdin, mybuf, _IONBF, sizeof(mybuf));
    arr = malloc(6 * sizeof(char *));
    secret = malloc(31);
    secret[read(open("secret",0), secret, 30)] = 0;
    // printf("%s\n", secret);
    char *chunck = malloc(31);
    free(secret);
    free(chunck);
    game();


}