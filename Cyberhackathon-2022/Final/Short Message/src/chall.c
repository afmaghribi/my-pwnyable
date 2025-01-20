#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void win(int cek1, int cek2){
	if (cek1 == 0xd34dc4f3 && cek2 == 0xf4c3c0d3){
		printf("Good job!\n");
		system("/bin/sh");
	} else {
		printf("Nice Try!\n");
	}
}

int main()
{
	setup();
	char message[50];
	printf("Silahkan kirim pesan anda: ");
	gets(message);
	printf(message);
	printf(" Terkirim!\n");
	return 0;
}
