#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int comando(int sensor) {
  cout << sensor;
  return sensor;
}

int main() {
  int valorUser;
  cout << "Digite o Comando (0 ou 1): ";
  cin >> valorUser;
  int inputUser = comando(valorUser);

  cout << "Comando Recebido: " << inputUser;
}