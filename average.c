#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
   float average;
   const int FLAG = -1;
   int number, total_numbers = 0, number_accumulator = 0;

   puts("Entre com -1 para parar de inserir valores");

   do {
      printf("Informe um valor inteiro: ");
      scanf("%d", &number);

      if(number != FLAG) {
         total_numbers++;
         number_accumulator += number;
      }
   } while(number != FLAG);

   average = number_accumulator / total_numbers;
   printf("Media dos valores lidos: %.2f\n", average);

   return EXIT_SUCCESS;
}
