#include <iostream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	string msg;
	string msgU = "";
	bool isPalindrono = true;
	int revert = 0;

	cout << "Digite a mensagem: " << endl;
	getline(cin, msg);
	
	for (int i = msg.length() - 1; i >= 0; i--)
	{
		if(msg[i] != ' ') {
			msgU.push_back(msg[i]);
		}
	}
	
	for (int i = 0; i < msg.length(); i++) {
		if(msg[i] == ' ') {
			msg.erase(i,1);
		}
	}

	if(msgU == msg){
		cout << "É Palíndrono" << endl;
	}else {
		cout << "Não é Palíndrono" << endl;
	}
	
	return 0;
}


/*
Exercício 2  - Receber através de digitação uma mensagem. 

Informar se esta mensagem é ou não um dado palíndromo (no caso de haver espaços no texto, desconsiderá-los para a verificação). Exemplos:

OVO
ARARA
SOCORRAM ME SUBI NO ONIBUS EM MARROCOS
*/