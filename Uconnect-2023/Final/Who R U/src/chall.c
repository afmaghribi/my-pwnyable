// gcc chall.c -no-pie -Wl,-z,norelro -o chall

#include <stdio.h>
#include <stdlib.h>

void setup(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void flag(){
  system("cat ./flag.txt");
}

int main(){
    setup();
    
    char nama[24];

    printf("Kamu siapa? dimana rumahnya? hei! ");
    fgets(nama,24,stdin);
    printf("Baik, terimakasih atas kerja samanya ");
    printf(nama);
    
}
