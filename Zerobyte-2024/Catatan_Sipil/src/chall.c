// gcc chall.c -Wl,-z,relro,-z,now -fPIE -pie -o chall
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *note;

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void print_menu(){
    char *menu[6] = {
        "--- Selamat datang di aplikasi pencatatan sipil ---",
        "Silahkan pilih salah satu menu di bawah ini:",
        "[1] Tambah catatan",
        "[2] Hapus catatan",
        "[3] Lihat catatan",
        "[4] Keluar"
    };
    for (int i = 0; i < 6; i++){
        printf("%s\n",menu[i]);
    }
}

unsigned int read_int()	{
   char buf[16];
   fgets(buf, 16, stdin);
   return strtoul(buf, NULL, 10);
}

void tambah(void)
{
    unsigned int input_length;

    printf("Panjang catatan sipil > ");
    input_length = read_int();
    note = malloc(sizeof(char) * input_length);
    printf("Masukkan catatan sipil > ");
    if(read(0,note,*(int *)(note-8))){
        return;
    } else {
        read(0,note,input_length);
    }
    return;
}

void tampil(void)
{
    if (!note)
    {
        puts("Catatan tidak ada!");
        return;
    }

    printf("Isi catatan sipil : %s\n",note);
}

void hapus(void)
{
    free(note);
    note = 0;
    return;
}

int main(){
    unsigned int pilih;
    setup();

    for (;;){
        print_menu();
        pilih = read_int();
        if (pilih == 1){
            tambah();
        } else if (pilih == 2){
            hapus();
        } else if (pilih == 3){
            tampil();
        } else {
            if (pilih == 4){
                puts("Bye!");
				exit(0);
				break;
            }
            printf("Pilihan salah!\n");
        }
    }
    return 0;
}

