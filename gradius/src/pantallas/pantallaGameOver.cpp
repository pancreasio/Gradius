#include "pantallaGameOver.h"

#include "raylib.h"
#include "objetos/nave.h"
#include "botones/botones.h"

namespace Juego {
	namespace GameOver {
		using namespace Botones;

		static bool estaInicializado = false;

		void inicializarGO() {
			if (!estaInicializado) {
				inicializarBotones();
			}
			estaInicializado = true;
		}

		void actualizarGO() {
			actualizarBotones();
		}

		void dibujarGO() {
			double tamanioTitulo = (GetScreenHeight()*GetScreenWidth())*0.011 / 100;
			char ganador[] = "GANADOR";
			char perdedor[] = "PERDEDOR";
			
			dibujarBotones();
			if (Nave::nave.gano) {
				DrawText(ganador, GetScreenWidth() / 2 - (MeasureText(ganador,tamanioTitulo)/2), GetScreenHeight()*0.3f, tamanioTitulo, DARKGRAY);
			}else {
				DrawText(perdedor, GetScreenWidth() / 2 - (MeasureText(perdedor, tamanioTitulo) / 2), GetScreenHeight()*0.3f, tamanioTitulo, DARKGRAY);
			}
			
			
		}

	}
}