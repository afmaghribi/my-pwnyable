// gcc chall.c -o chall -fno-stack-protector -no-pie
#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int read(unsigned char *ptr, int size) {
  int gift = 0;
  for (; size >= 0; --size, ++ptr) {
    syscall(SYS_read,0, ptr, 1);
    if (*ptr == 0xfb) gift++;
    if (*ptr == '\n') break;
  }
  __asm__("mov %0, %%ecx\n\t": "+r" (gift));
  return size;
}

int main()
{
    setup();
    char *message = alloca(0x80);
    char receiver[0x18];
    
    syscall(SYS_write,1,"Welcome to Short Message Sender!\n",34);
    syscall(SYS_write,1,"Send a message to: ",19);
    read(receiver, 0x18);

    syscall(SYS_write,1,"Message to send: ",17);

    if (read(message, 0x80) >= 0){
    syscall(SYS_write,1,"Message sent!\n",14);
    }

    return 0;
}
