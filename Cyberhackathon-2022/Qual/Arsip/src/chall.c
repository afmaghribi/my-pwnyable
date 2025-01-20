#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char flag[50] __attribute__((__section__(".data")));

char data[5][10]  __attribute__ ((aligned (512))) = {
                "flag",
                "cyber",
                "warriors{",
                "tapi_boong",
                "}"
            };

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

int baca_data(){
    int idx;
    printf("Masukkan indeks: ");
    scanf("%d",&idx);
    if ( idx > 5 ){
        printf("Indeks terlalu banyak!\n");
        return 0;
    }
    printf("Nilai yang tersimpan: %s\n",data[idx]);
    printf("Bye!");
}

void menu(){
    printf("┌──────────────────────────┐\n");
    printf("│ Cyber Security Hackathon │\n");
    printf("└──────────────────────────┘\n");
}


int main(){
    setup();
    FILE *fp;

    fp = fopen("flag.txt", "r");
    if (fp == NULL) {
        puts("Error: flag not found");
        return 0;
    }
    
    fgets(flag, sizeof(flag), fp);

    menu();

    baca_data(data);
    return 0;
}
