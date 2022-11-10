#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int continuar() {
  int inputUser;
  printf("Deseja parar o mapeamento ? Digite 1 para sim ou 0 para não ");
  cin >> inputUser;
  return inputUser;
}

// Descomente a função main abaixo para testar o exercício 5

int main() {
  int parar = 0;

  while (parar == 0) {
    parar = continuar();
  }
  // A função deve perguntar: "Digite 1 para parar o mapeamento!"
  // Se o usuário digitar 1, deve sair do loop while declarado acima
  // Em caso contrário, continua no loop acima e pergunta novamente

  return 1;
}