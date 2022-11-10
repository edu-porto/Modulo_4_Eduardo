#include <iostream>

using namespace std;

/*Esta função analisa cada item do vetor e descobre qual é o maior e retorna em qual indice esta esse número. Então a partir do indice foram feitas condições para dizer se ele é direita/esquerda/frente/trás. 
*/
int dirMaiorDist(int *vetor) {
  int posicaoInicial = vetor[0];
  int maiorNumero, posicao;

  for (int i = 0; i < 4; i++) {
    if (posicaoInicial < vetor[i]) {
      posicaoInicial = vetor[i];
      maiorNumero = i;
    }
  }
  if (maiorNumero == 0) {
    cout << "Direita ";
  }
  if (maiorNumero == 1) {
    cout << "Esquerda ";
  }
  if (maiorNumero == 2) {
    cout << "Frente ";
  }
  if (maiorNumero == 3) {
    cout << "Trás ";
  }
  return 0;
}

/*A mesma lógica do for utilizada acima foi feita nesta função, mas ao invés de retornar o indice eu retorno o maior número da array  */

int maiorDist(int*Vetor){
  int posicaoInicial = Vetor[0];
  int maiorNumero, posicao;

  for (int i = 0; i < 4; i++) {
    if (posicaoInicial < Vetor[i]) {
      posicaoInicial = Vetor[i];
      maiorNumero = i;
    }
  }
  return posicaoInicial;
}

int main() {
  // Considere que os valores sempre serão distintos
  // Considere valores de distância inteiros entre 0 e 100

  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes[4] = {0, 20, 100, 50};

  cout << dirMaiorDist(posicoes) << endl;
  // valor esperado: Frente

  cout << maiorDist(posicoes) << endl;
  // valor esperado: 100

  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes2[4] = {95, 70, 80, 50};

  cout << dirMaiorDist(posicoes2) << endl;
  // valor esperado: Direita

  cout << maiorDist(posicoes2) << endl;
  // valor esperado: 95

  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes3[4] = {10, 0, 50, 60};

  cout << dirMaiorDist(posicoes3) << endl;
  // valor esperado: Tras

  cout << maiorDist(posicoes3) << endl;
  // valor esperado: 60

  // "Direita", "Esquerda", "Frente", "Tras"
  int posicoes4[4] = {54, 55, 30, 0};

  cout << dirMaiorDist(posicoes4) << endl;
  // valor esperado: Esquerda

  cout << maiorDist(posicoes4) << endl;
  // valor esperado: 55
}
