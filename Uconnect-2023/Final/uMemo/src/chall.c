// gcc source.c -o uMemo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char *memo[50];

#define buf_size 64

void set_flag()
{
	srand(time(0));
	int flag_index = (rand() % (49 - 10 + 1)) + 10;
	memo[flag_index] = malloc(buf_size);
	FILE *fp = fopen("flag.txt", "r");
	fgets(memo[flag_index], buf_size, fp);
	// printf("flag index: %d\n", flag_index);
}

unsigned int read_int()	{
   char buf[16];
   fgets(buf, 16, stdin);
   return strtoul(buf, NULL, 10);
}

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	set_flag();
}

void print_menu(){
    char *menu[7] = {
        "--- Selamat datang di aplikasi pencatatan (updated) ---",
        "--- Sekarang kalian bisa membuat 10 catatan ---",
        "Silahkan pilih salah satu menu di bawah ini:",
        "[1] Tambah catatan",
        "[2] Hapus catatan",
        "[3] Lihat catatan",
        "[4] Keluar"
    };
    for (int i = 0; i < 7; i++){
        printf("%s\n",menu[i]);
    }
}

void tambah(){
	printf("Indeks: ");
	int idx = read_int();
	if(idx < 0 || idx > 9)	{
		puts("Cuma bisa pilih indeks 0-9");
		return;
	}

	memo[idx] = malloc(buf_size);
	printf("Tuliskan memo (maks. 64 karakter): ");
	read(0,memo[idx], buf_size);
	printf("Berhasil menambahkan memo ke indeks %d\n", idx);
}

void tampil()	{
	printf("Indeks: ");
	int idx = read_int();
	if(idx < 0 || idx > 9)	{
		puts("Cuma bisa pilih indeks 0-9");
		return;
	}
	printf("Isi memo: %s\n", memo[idx]);
}

void hapus()	{
	printf("Indeks: ");
	int idx = read_int();

	free(memo[idx]);
	printf("Memo di indeks %d berhasil dihapus\n", idx);
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
}
