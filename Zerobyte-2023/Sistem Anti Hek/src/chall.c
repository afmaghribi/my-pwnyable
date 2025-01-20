#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define NUM_USERS 0x10
#define MAX_LEN 0x20
#define BASE_UID 0x1337

typedef struct users{
    int uid;
    char username[MAX_LEN];
    char password[MAX_LEN];
} *user_t;

int curr_user_id = BASE_UID;
user_t users[NUM_USERS];

void setup(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

unsigned int read_int()	{
   char buf[16];
   fgets(buf, 16, stdin);
   return strtoul(buf, NULL, 10);
}

void print_menu(){
    char *menu[7] = {
        "\033[91m|------------------------------------------------------------------|\033[00m\n\033[91m|##################################################################|\033[00m\n|--- 😎 Selamat datang di sistem anti hek buatan anak bangsa 😎 ---|\n\033[1m|##################################################################|\033[00m\n\033[1m|------------------------------------------------------------------|\033[00m",
        "Silahkan pilih salah satu menu di bawah ini:",
        "[1] Buat akun baru",
        "[2] Hapus akun",
        "[3] Lihat semua akun",
        "[4] Masuk",
        "[5] Keluar"
    };
    for (int i = 0; i < 7; i++){
        printf("%s\n",menu[i]);
    }
}

int add_user() {
    user_t user = (user_t) malloc(sizeof(users));
    int idx =  curr_user_id++ - BASE_UID;
    
    if (idx < NUM_USERS){
        users[idx] = user;
    } else {
        printf("Sudah tidak bisa membuat akun baru!\n");
        curr_user_id--;
        return 0;
    }
    
    user->uid = curr_user_id;

    printf("Username: ");
    scanf("%32s",user->username);
    getchar();
    printf("Password: ");
    scanf("%32s",user->password);
    getchar();
    printf("Berhasil membuat akun baru dengan uid: %x\n",user->uid);
}

void del_user() {
    int found = 0;
    printf("uid akun yang ingin dihapus: ");
	int uid = read_int();

    for(int i = 0; i < NUM_USERS; i++) {
        if(users[i] != NULL) {
            if(users[i]->uid  == uid) {
                found = 1;
                free(users[i]);
                printf("User dengan uid: 0x%x berhasil dihapus\n\n", uid);
                break;
            }
        }
    }
    if(!found) {
        printf("User dengan uid: 0x%x tidak ditemukan\n\n", uid);
    }
    
}

void show_user() {
    for (int i = 0; i < NUM_USERS; i++){
        if(users[i] != NULL){
            printf("uid: 0x%x\nusername: %s\n",users[i]->uid ,users[i]->username);
        }
    }
    printf("\n");
}

void login() {
    int found = 0;
    char username[MAX_LEN];
    char password[MAX_LEN];
    
    printf("Username: ");
    scanf("%32s",username);
    getchar();
    
    printf("Password: ");
    scanf("%32s",password);
    getchar();
    for(int i = 0; i < NUM_USERS; i++) {
        if(users[i] != NULL) {
            if(strncmp(users[i]->username, username, MAX_LEN) == 0) {
                if(strncmp(users[i]->password, password, MAX_LEN) == 0) {
                    found = 1;
                    printf("Berhasil login!\nuid: 0x%x\nusername: ", users[i]->uid);
                    printf(users[i]->username);
                    printf("\nTapi maaf, sekarang layanan sedang dalam pemeliharaan\nSilahkan kembali dilain waktu!\n\n");
                }
           }
        }
    }

    if(!found) {
        printf("Username tidak ditemukan atau password salah!\n");
    }
}


int main() {
    setup();

    while(1) {
        print_menu();
        printf("> ");
        int choice = read_int();
        if(choice == 1) {
            add_user();
        } else if(choice == 2) {
            del_user();
        } else if(choice == 3) {
            show_user();
        } else if(choice == 4) {
            login();
        } else if(choice == 5){
            printf("Bye!\n");
            return 0;
        } else {
            printf("Pilihan salah!\n");
        }
    }
}
