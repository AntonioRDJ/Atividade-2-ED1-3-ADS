#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	ifstream  arq("texto.txt");

	if(arq.is_open())
	{
		string linha;
		string lastName = "";
		while( getline(arq, linha) )
		{
			for(int i = linha.length() - 1; i >= 0; i--) {
				if(linha[i] == ' ') {
					lastName.append(linha, i+1, linha.length());
					linha.erase(i, linha.length() - i);
					break;
				}
			}
			cout << lastName << ", " << linha << endl;
			cout << endl;
			lastName = "";
		}
		arq.close();
	}
	else
	{
		cout << "Não foi possível abrir o arquivo";
	}

	return 0;
}

/*
Exercício 3 - À partir de uma lista de nomes disponível em um arquivo TXT, transforma-los em nomes no formato agenda telefônica. Exemplo:

José Antonio Santos Silva
Silva, José Antonio Santos
*/