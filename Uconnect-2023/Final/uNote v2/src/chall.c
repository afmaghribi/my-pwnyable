// gcc source.c -o uNotev2

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>

struct note
{
	void (*func)(char*);
	char* content;
};

struct note** notes;

void setup()	{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	notes = malloc(8 * sizeof(void *));
}

unsigned int read_int()	{
	char buf[16];
	fgets(buf, 16, stdin);
	return strtoul(buf, NULL, 10);
}

void print_menu(){
    char *menu[7] = {
        "--- Selamat datang di aplikasi pencatatan (latest) ---",
        "--- Sekarang kalian bisa membuat 5 catatan ---",
        "Silahkan pilih salah satu menu di bawah ini:",
        "[1] Tambah catatan",
        "[2] Ubah catatan",
        "[3] Lihat catatan",
        "[4] Keluar"
    };
    for (int i = 0; i < 7; i++){
        printf("%s\n",menu[i]);
    }
}

void add_note()	{
	unsigned int size;
	printf("Masukkan ukuran catatan: ");
	size = read_int();
	if(size > 0x200)	{
		puts("Ga bakal ada yang baca catetan sepanjang itu!");
		exit(-1);
	}
	int i = 0;
	while(notes[i] != NULL && ++i < 8);
	if(i == 8)	{
		puts("Catatan sudah penuh!");
		exit(-1);
	}
	notes[i] = malloc(8);
	notes[i]->func = &puts;
	notes[i]->content = malloc(size);
	printf("Masukkan isi catatan: ");
	fgets(notes[i]->content, size, stdin);
	puts("Berhasil menambahkan catatan!");
}

void edit_note()	{
	unsigned int idx;
	printf("Masukkan indeks: ");
	idx = read_int();
	if(notes[idx] == NULL)	{
		puts("Tidak ada catatan pada indeks tersebut!");
		return;
	}
	printf("Masukkann isi catatan baru: ");
	read(0,notes[idx]->content,1337);
	puts("Catatan berhasil diubah!");
}

void print_note()	{
	unsigned int idx;
	printf("Indeks yang ingin ditampilkan: ");
	idx = read_int();
	if(notes[idx] == NULL)	{
		puts("Tidak ada catatan pada indeks tersebut!");
		return;
	}
	printf("Isi catatan: ");
	(*(notes[idx]->func))(notes[idx]->content);
}

int main(int argc, char const *argv[])
{
	unsigned int choice;

	setup();
	while(1)	{
		print_menu();
		choice = read_int();
		switch(choice)	{
			case 1:
				add_note();
				break;
			case 2:
				edit_note();
				break;
			case 3:
				print_note();
				break;	
			case 4:
				puts("Bye bye!");
				exit(0);
				break;
			default:
				puts("Invalid choice!");
				break;
		}
	}
	return 0;
}