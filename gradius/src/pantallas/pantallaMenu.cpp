#include "pantallaMenu.h"

#include "raylib.h"
#include "botones/botones.h"

namespace Juego {
	namespace Menu {
		using namespace Botones;
		static bool estaInicializado = false;

		void inicializarMenu() {
			if (!estaInicializado) {
				inicializarBotones();
			}
			estaInicializado = true;
		}

		void actualizarMenu() {
			actualizarBotones();
		}

		void dibujarMenu() {	
			double tamanioTitulo = (GetScreenHeight()*GetScreenWidth())*0.0190 / 100;
			double tamanioVersion = (GetScreenHeight()*GetScreenWidth())*0.0042 / 100.0;
			char titulo[] = "Gradius";
			char version[] = "Gradius v0.3";
			dibujarBotones();
			DrawText(titulo, (GetScreenWidth() - MeasureText(titulo, tamanioTitulo)) / 2, GetScreenHeight()*0.1f, tamanioTitulo, DARKGRAY);
			DrawText(version, GetScreenWidth() - MeasureText(version, tamanioVersion), 0 + tamanioVersion, (int)tamanioVersion, DARKGRAY);
		}
	}
}