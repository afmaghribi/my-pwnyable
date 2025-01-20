/* gcc source.c -o uDecide -no-pie -fno-stack-protector */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void readnline(char *ptr, int size) {
  for (int i = 0; i != size; i++, ptr++) {
    read(0, ptr, 1);
    if (*ptr == '\n') break;
  }
}

int main() {
  int size;
  char *buf;
  setup();

  printf("Masukkan panjang pesan yang akan dikirim: ");
  scanf("%d%*c", &size);
  buf = alloca(size);

  printf("Masukkan pesan yang ingin dikirim: ");
  readnline(buf, size);

  puts("Pesanmu terkirim!\n");

  return 0;
}