#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

void gotoxy(short x, short y)
{
	COORD coord = {x, y};
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void mostraS(string s, short x, short y)
{
	gotoxy(x, y);
	cout << s;
}

void mostraC(char s, short x, short y)
{
	gotoxy(x, y);
	cout << s;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	string msg;
	char letter;
	bool pular = false;

	cout << "Digite a mensagem." << endl;
	getline(cin, msg);
	
	system("cls");
	mostraS(msg, 50, 5);

	for (int i = 0; i < msg.size(); i++)
	{
		letter = msg[i];
		
		if(msg[i] == ' ') {
			pular = true;
		} else pular = false;
		
		msg.replace(i, 1, " ");
		mostraS(msg, 50, 5);
		
		for (int x = 6; x <= 20; x++)
		{
			if(!pular) {
				mostraC(letter, 50+i, x);
				Sleep(100);
				mostraS(" ", 50+i, x);
			}
		}
		
		mostraC(letter, 50+i, 20);
	}
	return 0;
}


/*
Exercício 1  - Receber através de digitação uma mensagem. 

Apresentar esta mensagem, centralizada, na linha 5 da tela.

À partir daí, cada letra desta mensagem deverá "cair", da linha 5 até a linha 20, simulando
uma "cascata". Ao final, a mensagem deverá estar toda apresentada na linha 20.
*/