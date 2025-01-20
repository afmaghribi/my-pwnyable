// gcc chall.c -o chall

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct add_s {
  unsigned int _0;
  unsigned int _4;
  long _8;
} adds;

struct sub_s {
  unsigned int _0;
  unsigned int _4;
  long _8;
} subs;

struct mul_s {
  unsigned int _0;
  unsigned int _4;
  long _8;
} muls;

struct div_s {
  unsigned int _0;
  unsigned int _4;
  long _8;
} divs;

void setup() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void handle_newline(void)

{
  int iVar1;
  
  do {
    iVar1 = getchar();
    if ((char)iVar1 == '\n') {
      return;
    }
  } while ((char)iVar1 != -1);
  return;
}

void print_menu(){
    char *menu[8] = {
        "Options Menu:",
        "[1] Addition",
        "[2] Subtraction",
        "[3] Multiplication",
        "[4] Division",
        "[5] Save Result",
        "[6] Show Result",
        "[7] Exit"
    };
    for (int i = 0; i < 8; i++){
        printf("%s\n",menu[i]);
    }
    printf("> ");
}

void add(void){
  printf("Number x: ");
  scanf("%d",&adds._0);
  handle_newline();
  printf("Number y: ");
  scanf("%d",&adds._4);
  handle_newline();
  if ( (adds._0 > 100) && (adds._4 > 100) )
  {
    adds._8 = adds._4 + adds._0;
    printf("Result for x + y is %d.\n\n",adds._8);
    return;
  }
  printf("Bruh, do you really need help calculating such small numbers?\nShame on you... Bye!");
  exit(-1);
}

void sub(void){
  printf("Number x: ");
  scanf("%d",&subs._0);
  handle_newline();
  printf("Number y: ");
  scanf("%d",&subs._4);
  handle_newline();
  if ( (subs._0 > 100) && (subs._4 > 100) )
  {
    subs._8 = subs._0 - subs._4;
    printf("Result for x - y is %d.\n\n",subs._8);
    return;
  }
  printf("Bruh, do you really need help calculating such small numbers?\nShame on you... Bye!");
  exit(-1);
}

void mul(void){
  printf("Number x: ");
  scanf("%d",&muls._0);
  handle_newline();
  printf("Number y: ");
  scanf("%d",&muls._4);
  handle_newline();
  if ( (muls._0 > 100) && (muls._4 > 100) )
  {
    muls._8 = muls._4 * muls._0;
    printf("Result for x * y is %d.\n\n",muls._8);
    return;
  }
  printf("Bruh, do you really need help calculating such small numbers?\nShame on you... Bye!");
  exit(-1);
}

void divide(void){
  printf("Number x: ");
  scanf("%d",&divs._0);
  handle_newline();
  printf("Number y: ");
  scanf("%d",&divs._4);
  handle_newline();
  if ( (divs._0 > 100) && (divs._4 > 100) )
  {
    divs._8 = divs._0 / divs._4;
    printf("Result for x / y is %d.\n\n",divs._8);
    return; 
  }
  printf("Bruh, do you really need help calculating such small numbers?\nShame on you... Bye!");
  exit(-1);
}

int main(){
    setup();
    int choice;
    int calculations;
    int *results;
    char next = 'y';

    puts("\t\t\t|#------------------------#|");
    puts("\t\t\t|      The Calculator      |");
    puts("\t\t\t|#------------------------#|");

    while ( next == 'y' )
    {
        printf("How many calculations do you want to do? ");
        scanf("%d",&calculations);
        handle_newline();
        if ((calculations < 256) && (3 < calculations)){
            results = malloc((long)(calculations << 1));
            for (int index = 0; index < calculations; index++)
            {
                print_menu();
                scanf("%d",&choice);
                handle_newline();
                
                if (choice == 1) {
                    add();
                    results[index] = adds._8;
                } else if (choice == 2) {
                    sub();
                    results[index] = subs._8;
                } else if (choice == 3) {
                    mul();
                    results[index] = muls._8;
                } else if (choice == 4) {
                    divide();
                    results[index] = divs._8;
                } else if (choice == 5) {
                    free(results);
                    results = 0;
                    printf("Want to do the calculation again? (y/n) ");
                    scanf("%c",&next);
                    break;
                } else if (choice == 6) {
                  printf("Result : %ld\n",*(long *)results);
                } else if (choice == 7) {
                    next = 'x';
                    break;
                } else {
                    puts("Invalid choice!\n");
                }               
            }
        } else {
            puts("Too few calcution, you can calculate yourself!");
        }
    }
    return 0;
}
