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
		cout << "� Pal�ndrono" << endl;
	}else {
		cout << "N�o � Pal�ndrono" << endl;
	}
	
	return 0;
}


/*
Exerc�cio 2  - Receber atrav�s de digita��o uma mensagem. 

Informar se esta mensagem � ou n�o um dado pal�ndromo (no caso de haver espa�os no texto, desconsider�-los para a verifica��o). Exemplos:

OVO
ARARA
SOCORRAM ME SUBI NO ONIBUS EM MARROCOS
*/