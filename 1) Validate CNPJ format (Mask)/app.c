#include <stdio.h>
#include <string.h>

int main (void) {
  char charCPF[19] ;
  int intCPF[19] ;
  int tamanho;
  printf("type your CNPJ: ");
  scanf ("%s",charCPF);
  tamanho = strlen(charCPF);
//passa os valores de uma string em valores da tabela ascii para um vetor
  for(int i = 0; i<tamanho; i++){
      intCPF[i] = charCPF[i];
  }
//checa se eh um CPF apenas com numeros
  if(tamanho == 14){
      for (int i = 0; i < tamanho; i++){
          if(intCPF[i] > 57 || intCPF[i] < 48){
              printf("invalid format");
              break;
          }
          else if(i == 13)
          printf("valid format");
      }
  }
  //checa se eh um cpf formatado
  else if(tamanho == 18){
      // contador de caracteres que não sao numeros
      int cont = 0;
      for (int i = 0; i < tamanho; i++){
          //checa se todas os caracteres diferentes de numeros estao no lugar 
          if (intCPF[2] != 46 || intCPF[6] != 46 || intCPF[10] != 47 || intCPF[15] != 45){
              break;
          }
          //checa se eh um numero
          else if(intCPF[i] > 57 || intCPF[i] < 48){
              cont ++;
          }
          //checa se chegou no final do array com apenas 4 valores diferentes de numeros
          else if(i == 17 && cont == 4 )
              printf("valid format");
      }
      if (cont != 4)
          printf("invalid format");
  }
  else
      printf("invalid format");
  return 0;
  }