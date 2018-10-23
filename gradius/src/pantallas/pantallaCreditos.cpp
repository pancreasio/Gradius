#include "pantallaCreditos.h"

#include "raylib.h"
#include "botones/botones.h"

namespace Juego {
	namespace Creditos {
		using namespace Botones;

		static bool estaInicializado = false;

		void inicializarCreditos() {
			if (!estaInicializado) {
				inicializarBotones();
			}
			estaInicializado = true;
		}

		void actualizarCreditos() {
			actualizarBotones();
		}

		void dibujarCreditos() {
			double tamanioTitulo = (GetScreenHeight()*GetScreenWidth())*0.0150 / 100.0;
			double tamanioSubtitulos = (GetScreenHeight()*GetScreenWidth())*0.0062 / 100.0;
			double tamanioVersion = (GetScreenHeight()*GetScreenWidth())*0.0042 / 100.0;
			char titulo[] = "Creditos";
			char subt1[] = "Hecho con la libreria Raylib";
			char subt2[] = "Programador: Federico van Gelderen";
			char subt3[] = "Sonidos: Bfxr";
			char subt4[] = "Imagenes: piskelapp.com";
			char version[] = "Gradius v0.2";

			
			DrawText(titulo, (GetScreenWidth() - MeasureText(titulo, tamanioTitulo)) / 2, 0, tamanioTitulo, DARKGRAY);
			DrawText(subt1, (GetScreenWidth() - MeasureText(subt1, tamanioSubtitulos)) / 2, GetScreenHeight() * 20 / 100, tamanioSubtitulos, DARKGRAY);
			DrawText(subt2, (GetScreenWidth() - MeasureText(subt2, tamanioSubtitulos)) / 2, GetScreenHeight() * 35 / 100 - tamanioSubtitulos, tamanioSubtitulos, DARKGRAY);
			DrawText(subt3, (GetScreenWidth() - MeasureText(subt3, tamanioSubtitulos)) / 2, GetScreenHeight() * 50 / 100 - tamanioSubtitulos, tamanioSubtitulos, DARKGRAY);
			DrawText(subt4, (GetScreenWidth() - MeasureText(subt4, tamanioSubtitulos)) / 2, GetScreenHeight() * 65 / 100 - tamanioSubtitulos, tamanioSubtitulos, DARKGRAY);
			DrawText(version, GetScreenWidth() - MeasureText(version, tamanioVersion), 0 + tamanioVersion, (int)tamanioVersion, DARKGRAY);
			dibujarBotones();
		}

		
	}
}