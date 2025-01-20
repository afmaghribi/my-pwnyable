#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

int main() { 
    setup();
    char buf[32]; 
    char welcome[] = "Ini program yang sangat sederhana!\n";
    char pwn[] = "Apakah kalian bisa mengeksploitasinya?\n";
    char bye[] =  "Bye!\n";
    write(1,welcome,strlen(welcome));
    write(1,pwn,strlen(pwn));
    read(0,buf,2000);
    return 0; 
}