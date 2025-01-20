#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void getFlag() {
    printf("┌──────────────────────────┐\n");
    printf("│   Selamat! Ini Flagnya~  │\n");
    printf("└──────────────────────────┘\n");
    system("cat flag.txt");
}

void vuln() {
    char buff[0xff];
    printf("Masukkan license key yang valid untuk mendapatkan flag:\n");
    gets(buff);
    if(strcmp(buff, "CSH-2022-FLAG") == 0) {
        printf("Kok ngga muncul flagnya?\n");
    } else {
        _exit(0);
    }
}


void main(int argc, char* argv[]) {
    setup();
    printf(" addr of main(): %p\n", main);
    printf("┌──────────────────────────┐\n");
    printf("│ Cyber Security Hackathon │\n");
    printf("└──────────────────────────┘\n");
    vuln();
}

