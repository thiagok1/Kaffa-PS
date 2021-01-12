#include <stdio.h>
#include <string.h>

int main (void) {

  char charCNPJ[19] ;
  int asciiCNPJ[19] ;
  int intCNPJ [13];
  int multCNPJ [15];
  int tamanho;
  int dv,cont;

  printf("type your CNPJ: ");
  scanf ("%s",charCNPJ);

  tamanho = strlen(charCNPJ);
//passa os valores de uma string em valores da tabela ascii para um vetor
  for(int i = 0; i<tamanho; i++){
      asciiCNPJ[i] = charCNPJ[i];
  }
//checa se eh um CPF apenas com numeros
  if(tamanho == 14){
      for (int i = 0; i < tamanho; i++){
          if(asciiCNPJ[i] > 57 || asciiCNPJ[i] < 48){
              printf("invalid format");
              break;
          }
          else if(i == 13){
              printf("valid format\n");
//após a validacao do formato preenche um array com os valores de cada digito
              for (int  j = 0; j < tamanho; j++){
                  intCNPJ[j] = asciiCNPJ[j] - 48;
              }
              
          }
      }
  }
  //checa se eh um cpf formatado
  else if(tamanho == 18){
      // contador de caracteres que não sao numeros
      cont = 0;
      for (int i = 0; i < tamanho; i++){
          //checa se todas os caracteres diferentes de numeros estao no lugar 
          if (asciiCNPJ[2] != 46 || asciiCNPJ[6] != 46 || asciiCNPJ[10] != 47 ||asciiCNPJ[15] != 45){
              break;
          }
          //checa se eh um numero
          else if(asciiCNPJ[i] > 57 || asciiCNPJ[i] < 48){
              cont ++;
          }
          //checa se chegou no final do array com apenas 4 valores diferentes de numeros
          else if(i == 17 && cont == 4 ){
              printf("valid format\n");
//após a validacao do formato preenche um array com os valores de cada digito
              cont = 0;
              for (int  j = 0; j < tamanho; j++){
                  if(j == 2 || j == 6 || j == 10 || j == 15 ){
                      cont ++;
                      continue;
                  }
                  intCNPJ[j - cont] = asciiCNPJ[j] - 48;
                  printf("%d" ,intCNPJ[j - cont]);
              }
          }
      }
      if (cont != 4)
          printf("invalid format\n");
  }
  else{
      printf("invalid format");
      return 0;
  }
  cont = 6;
  for(int i = 0;i <= 11; i++){
      multCNPJ[i] = intCNPJ[i] * cont;
      if(cont == 9){
          cont = 2;
          continue;
        }
      cont ++; 
  }
  for(int i = 0;i <= 11; i++){
      dv = dv + multCNPJ[i];
  }
  if (dv % 11 == intCNPJ[12]){
      cont = 5;
      for(int i = 0;i <= 12; i++){
      multCNPJ[i] = intCNPJ[i] * cont;
      if(cont == 9){
          cont = 2;
          continue;
        }
      cont ++; 
  }
      dv = 0;
      for(int i = 0;i <= 12; i++){
          dv = dv + multCNPJ[i];
      }
      if(dv % 11 == intCNPJ[13])
          printf("validation of CNPJ digits: success");

      else{
      printf("validation of CNPJ digits: failed");
  }
  }
  else{
      printf("validation of CNPJ digits: failed");
  }
      
  return 0;
  }