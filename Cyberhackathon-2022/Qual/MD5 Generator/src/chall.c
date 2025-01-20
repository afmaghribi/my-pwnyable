#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

int main(){
	setup();
	char kata[20]="",cmd[50]="";
	printf("Selamat datang di program MD5hash Generator\n");
	printf("Silahkan masukkan kata yang ingin digenerate : ");
	scanf("%s",kata);
	sprintf(cmd,"echo %s | md5sum",kata);
	system(cmd);
	return 0;
}