#include <iostream>
#include <string>

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor
using namespace std ;

int main(){
  float valorMin = 0 ;
  float valorMedio = 0;
  float valorMax = 0;

  cout << "Digite o número mínimo ";
  cin >> valorMin; 
  cout << "Digite o número máximo ";
  cin >> valorMax;

  cout << "Digite o número para comparar se está mais perto do mínimo ou máximo ";
  cin >> valorMedio;

int resultMin = valorMedio - valorMin;
int resultMax = valorMax - valorMedio;

float resultado = 0;

int intervalo = valorMax -+ valorMin ;
int media = valorMedio -+ valorMin ;
int resposta = (media * 100)/intervalo ;
  
  cout << "Esse é o valor mínimo : " << resposta << "%";

  return 0;
}


