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
		string lastNameU = "";
		string firstName = "";
		string middleName = "";
		while( getline(arq, linha) )
		{
			for(int i = linha.length() - 1; i >= 0; i--) {
				if(linha[i] == ' ') {
					lastName.append(linha, i+1, linha.length());
					linha.erase(i, linha.length() - i);
					break;
				}
			}
			
			for(int i = 0; i < linha.length(); i++) {
				if(linha[i] == ' ') {
					firstName.append(linha, 0, i);
					linha.erase(0, i+1);
					break;
				}
			}

			for(int i = 0; i < linha.length(); i++) {	
				if(linha[i] == ' ') {
					middleName.append(linha, 0, 1);
					middleName = middleName + ". ";
					linha.erase(0, i+1);
					break;
				}			
			}
	
			if(linha[0]) {
				middleName.append(linha, 0, 1);
				middleName = middleName + ". ";
				linha.erase();
			}			
				
			for(int i = 0; i < lastName.length(); i++) {
				lastNameU += toupper(lastName[i]);
			}
			
			cout << lastNameU << ", " << firstName << " " << middleName << endl;
			cout << endl;
			lastName = "";
			firstName = "";
			middleName = "";
			lastNameU = "";
		}
		arq.close();
	}
	else
	{
		cout << "N�o foi poss�vel abrir o arquivo";
	}

	return 0;
}

/*
Exerc�cio 4 - � partir de uma lista de nomes dispon�vel em um arquivo TXT, transforma-los em nomes no formato cita��o bibliogr�fica. Exemplo:

Jos� Antonio Santos Silva
SILVA, Jos� A. S.
*/