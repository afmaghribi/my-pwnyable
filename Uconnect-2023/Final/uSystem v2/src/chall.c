#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define NUM_USERS 0x8
#define USERNAME_LEN 0x18
#define ADMIN_UID 0x13337

typedef struct {
    int uid;
    char username[USERNAME_LEN];
} *user_t;

int curr_user_id = ADMIN_UID;
user_t users[NUM_USERS];

void setup(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void readnline(char* buf, size_t n) {
    char c;
    size_t i = 0;
    while(i <= n - 1) {
        if(read(0, &c, 1) != 1) {
            break;
        }

        if(c == '\n') {
            break;
        }

        buf[i++] = c;
    }
    buf[i] = '\0';
}

int read_int() {
    char buf[8];
    readnline(buf, 8);
    return atoi(buf);
}


void print_menu(){
    char *menu[5] = {
        "--- Selamat datang di program login (latest) ---",
        "Silahkan pilih salah satu menu di bawah ini:",
        "[1] Buat akun baru",
        "[2] Masuk",
        "[3] Keluar"
    };
    for (int i = 0; i < 5; i++){
        printf("%s\n",menu[i]);
    }
}

void add_user() {
    user_t user = (user_t) malloc(sizeof(user_t));
    users[curr_user_id++ - ADMIN_UID] = user;

    printf("Panjang username: ");
    size_t len = read_int();
    if(len > USERNAME_LEN) {
        puts("Ga boleh panjang-panjang!");
        exit(1);
    }

    if(!user->uid) {
        user->uid = curr_user_id;
    }
    printf("Username: ");
    readnline(user->username, len);
}

void login() {
    int found = 0;

    char username[USERNAME_LEN];
    printf("Username: ");
    readnline(username, USERNAME_LEN);
    for(int i = 0; i < NUM_USERS; i++) {
        if(users[i] != NULL) {
            if(strncmp(users[i]->username, username, USERNAME_LEN) == 0) {
                found = 1;

                if(users[i]->uid == 0x13337) {
                    system("/bin/sh");
                } else {
                    printf("Berhasil login! uid: 0x%x\n", users[i]->uid);
                }
            }
        }
    }

    if(!found) {
        puts("Username tidak di termukan");
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
            login();
        } else if(choice == 3){
            puts("Bye!");
            exit(1);
        } else {
            puts("Pilihan salah!");
        }
    }
}
