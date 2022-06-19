#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace System;
using namespace std;

int Tablero[16][15] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void dibujar_tablero() {
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 15; j++)
		{
			Console::SetCursorPosition(j, i);

			if (Tablero[i][j] == 0) Console::ForegroundColor = ConsoleColor::Black;
			else if (Tablero[i][j] == 1)Console::ForegroundColor = ConsoleColor::Yellow;
			else if (Tablero[i][j] == 2) Console::ForegroundColor = ConsoleColor::Red;


			cout << (unsigned char)254;
		}
}

struct Jugador {

	int x = 6;
	int y = 6;
	char c = 4;
	void Mover(char tecla) {
		if (tecla == 72)
			y--;
		else if (tecla == 80)
			y++;
		else if (tecla == 75)
			x--;
		else if (tecla == 77)
		{
			x++;
		}
		else if (tecla == 70)
		{
			Tablero[x][y]++;
		}
	}
	void mostrar() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y);
		cout << c;
	}
	/*void Colocar(char tecla) {
		if (tecla == 27)
		{
			Tablero[x][y] = Tablero[x][y]+1;
		}
	}*/
};

int main()
{
	Console::SetWindowSize(80, 20);
	Console::CursorVisible = false;
	Jugador* jugador = new Jugador;
	while (true) {
		if (_kbhit()) {
			dibujar_tablero();
			char tecla = _getch();
			jugador->Mover(tecla);
			jugador->mostrar();
		}
	}
	return 0;

}
