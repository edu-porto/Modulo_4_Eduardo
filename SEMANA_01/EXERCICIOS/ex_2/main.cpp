#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int leComando() {
  int valorUser;
  cin >> valorUser;
  return valorUser;
}

int main() {
  cout << "Digite o Comando (0 ou 1):";
  int cmd = leComando();
  cout << "Comando Recebido: " << cmd << endl;
}