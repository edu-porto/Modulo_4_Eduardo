#include <iostream>
#include <string>

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor
using namespace std ;


//Função simples que recebe três inputs do usuario 
float converteSensor(int medida, int min, int max){

float intervalo = max - min ;
float medidas = medida - min ;
float resposta = medidas/intervalo ;
  
return resposta;
  
}

// Descomente a função main abaixo para testar o exercício 1
int main(){
  cout << "Teste Ex 1" << endl;
	cout << converteSensor(100,100,400) << endl;
  //valor esperado: 0
  
	cout << converteSensor(400,100,400) << endl;
  //valor esperado: 1
  
	cout << converteSensor(250,100,400) << endl;
  //valor esperado: 0.5
}

