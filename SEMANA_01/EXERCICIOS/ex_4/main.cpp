#include <iostream>

using namespace std;

void calcular() {
  int vetor[] = {2, 20, 57, 35};
  int maiorNumero, i, posicao;
  maiorNumero = vetor[0];
  for (i = 1; i < 4; i++) {
    if (vetor[i] > maiorNumero) {
      maiorNumero = vetor[i];
      posicao = i;
    }
  }
  if (posicao == 0) {
    cout << "Direita e número " << maiorNumero;
  }
  if (posicao == 1) {
    cout << "Esquerda e número " << maiorNumero;
  }
  if (posicao == 2) {
    cout << "Frente e número " << maiorNumero;
  }
  if (posicao == 3) {
    cout << "Trás e número " << maiorNumero;
  }
}

int main() {
  calcular();
  return 0;
}
