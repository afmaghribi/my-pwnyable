// gcc chall.c -o chall -fno-stack-protector -no-pie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main()
{
    setup();
    char receiver[32];

    printf("%s","Heker jangan menyerang, pliss!!\n");
    scanf("%64s",receiver);
    if(strlen(receiver) >= 32){
        printf("%s","Udah dibilang, heker jangan menyerang! >__<\n");
        exit(0);
    }
    return 0;
}