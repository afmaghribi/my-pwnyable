// gcc chall.c -o chall

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void setup() {
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
}

unsigned int read_int()	{
   char buf[16];
   fgets(buf, 16, stdin);
   return strtoul(buf, NULL, 10);
}

int main(){
  setup();
  
  unsigned int pilih;
  char jawaban[5][0x20];
  int idx;
  int ctx = 0;

  char *menu[8] = {
        "\033[91m|#############################################|\033[00m\n\033[91m|#############################################|\033[00m\n\033[91m|#############################################|\033[00m\n\033[91m|#############################################|\033[00m\n\033[91m|#############################################|\033[00m\n\033[91m|#############################################|\033[00m",
        "\033[1m|#############################################|\033[00m\n\033[1m|#############################################|\033[00m\n\033[1m|#############################################|\033[00m\n\033[1m|#############################################|\033[00m\n\033[1m|#############################################|\033[00m\n\033[1m|#############################################|\033[00m\n\n"
        "--- Selamat datang di Quiz Kebangsaan ---",
        "Silahkan pilih salah satu menu di bawah ini:",
        "[1] Daftar pertanyaan",
        "[2] Jawab pertanyaan",
        "[3] Cek jawaban",
        "[4] Keluar"
    };

  char *pertanyaan[5] = {
        "\nBerikut adalah daftar pertanyaan yang harus kalian jawab dengan benar!\n"
        "[1] Indonesia merdeka pada",
        "[2] Presiden Indonesia yang pertama",
        "[3] Teks proklamasi diketik oleh",
        "[4] Pencipta lagu kebangsaan Indonesia Raya",
        "[5] Pembacaan teks proklamasi 17 Agustus 1945 berlangsung di\n"
      };
  
  char *kunci_jawaban[5] = {
        "17 Agustus 1945",
        "Ir. Soekarno",
        "Sayuti Melik",
        "W. R. Supratman",
        "Jl. Pegangsaan Timur 53",
      };
  
  menu_utama:
      for (int i = 0; i < 7; i++){
        printf("%s\n",menu[i]);
      }
      printf("Pilih: ");
      pilih = read_int();
      if (pilih == 1){
          goto daftar_pertanyaan;
      } else if (pilih == 2){
          goto jawab_pertanyaan;
      } else if (pilih == 3){
          goto cek_jawaban;
      } else {
          if (pilih == 4){
              puts("Bye!");
          return 0;
          }
      }
      printf("Pilihan salah!\n");
      goto menu_utama;

  daftar_pertanyaan:
    for (int i = 0; i < 5; i++){
      printf("%s\n",pertanyaan[i]);
    }
    goto menu_utama;
  
  jawab_pertanyaan:
    printf("Nomor pertanyaan: ");
    idx = read_int()-1;
    printf("Jawabanmu: ");
    read(0,jawaban[idx],0x40);
    printf("Jawaban telah disimpan!\n\n");
    goto menu_utama;

  cek_jawaban:
    for (int i = 0; i < 5; i++){
        if (strcmp(jawaban[i],kunci_jawaban[i]) == 0){
          printf("%d. %s [\033[92mBENAR\033[00m]\n",i+1,jawaban[i]);
          ctx++;
        } else {
          printf("%d. %s [\033[91mSALAH\033[00m]\n",i+1,jawaban[i]);
        }
    }
    if (ctx == 5){
      printf("Keren sekali kamu kawan!\n");
    }
    printf("\n");
    goto menu_utama;
}
