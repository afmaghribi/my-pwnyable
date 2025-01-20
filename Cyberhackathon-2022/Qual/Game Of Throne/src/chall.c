#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int overwrite[32];

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void getFlag(){
	system("cat ./flag.txt");
}

void main(){
	int idx, value;
    setup();
    printf("Masukkan indeks: ");
    scanf("%d", &idx);
    printf("Masukkan nilai: ");
    scanf("%d", &value);
    overwrite[idx] = value;
    puts("good bye");
}