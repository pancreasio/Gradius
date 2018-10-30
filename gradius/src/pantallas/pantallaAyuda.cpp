#include "pantallaAyuda.h"

#include "raylib.h"
#include "botones/botones.h"

namespace Juego {
	namespace Ayuda {
		using namespace Botones;

		static bool estaInicializado = false;

		void inicializarAyuda() {
			if (!estaInicializado) {
				inicializarBotones();
			}
			estaInicializado = true;
		}

		void actualizarAyuda() {
			actualizarBotones();
		}

		void dibujarAyuda() {
			double tamanioTitulo = (GetScreenHeight()*GetScreenWidth())*0.015 / 100;
			double tamanioTexto = (GetScreenHeight()*GetScreenWidth())*0.0045 / 100;
			char titulo1[] = "OBJETIVO";
			char titulo2[] = "CONTROLES";
			char objetivo[] = "-El objetivo del juego es destruir 10 asteroides";
			char controlesMov[] = "-El movimiento se realiza con las flechas(arriba y abajo)";
			char controlesDisparo[] = "-El disparo se realiza con la barra espaciadora";
			char controlesPausa[] = "-Para pausar el juego, apriete Esc";
			char controlesPausa2[] = "o pulse el boton Pausa con el click izquierdo del mouse";
			DrawText(titulo1, GetScreenWidth() / 2 - MeasureText(titulo1, tamanioTitulo) / 2, GetScreenHeight()*0.01f, tamanioTitulo, DARKGRAY);
			DrawText(titulo2, GetScreenWidth() / 2 - MeasureText(titulo2, tamanioTitulo) / 2, GetScreenHeight()*0.3f, tamanioTitulo, DARKGRAY);

			DrawText(objetivo, GetScreenWidth() / 2 - MeasureText(objetivo, tamanioTexto) / 2, GetScreenHeight()*0.15f, tamanioTexto, DARKGRAY);
			DrawText(controlesMov, GetScreenWidth() / 2 - MeasureText(controlesMov, tamanioTexto) / 2, GetScreenHeight()*0.45f, tamanioTexto, DARKGRAY);
			DrawText(controlesDisparo, GetScreenWidth() / 2 - MeasureText(controlesDisparo, tamanioTexto) / 2, GetScreenHeight()*0.5f, tamanioTexto, DARKGRAY);
			DrawText(controlesPausa, GetScreenWidth() / 2 - MeasureText(controlesPausa, tamanioTexto) / 2, GetScreenHeight()*0.55f, tamanioTexto, DARKGRAY);
			DrawText(controlesPausa2, GetScreenWidth() / 2 - MeasureText(controlesPausa2, tamanioTexto) / 2, GetScreenHeight()*0.6f, tamanioTexto, DARKGRAY);

			dibujarBotones();
		}
	}
}