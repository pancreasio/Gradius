#include "pantallaJuego.h"

#include "raylib.h"
#include "Juego/juego.h"
#include "objetos/nave.h"
#include "objetos/asteroides.h"
#include "objetos/disparo.h"
#include "colisiones/colisiones.h"
#include "oleadas/oleadas.h"
#include "botones/botones.h"

namespace Juego {
	namespace PantallaJuego {
		using namespace Asteroides;
		using namespace Nave;
		using namespace Disparo;
		using namespace Colisiones;
		using namespace Oleadas;
		using namespace Botones;

		using namespace Juego;
		static bool estaInicializado = false;
		fases fase = inicio;
		static bool desinicializar = false;
		bool pausa = false;
		Sound sonidoDisparo;
		Sound sonidoExplosionAsteroide;
		Sound sonidoExplosionDisparo;
		bool hayVolumen=true;

		static bool jugadorPerdio();

		bool jugadorPerdio() {
			if (nave.perdio||nave.gano){
				return true;
			}
			else {
				return false;
			}	
		}

		void actualizarJuego() {
			actualizarBotones();
			if (!pausa && fase==juego) {
				actualizarNave();
				actualizarDisparos();
				actualizarAsteroides();
				actualizarOleadas();
				actualizarColisiones();
			}
			if (jugadorPerdio()) {
				if (!desinicializar) {
					desinicializar = true;
					fase = fin;
				}
			}
			if (fase==salirAMenu) {
				if (!desinicializar) {
					desinicializar = true;
				}
				else {
					estado = menu;
					estaInicializado = false;
					desinicializar = false;
				}
			}
				
		}

		void dibujarJuego() {
			dibujarDisparos();
			dibujarNave();
			dibujarAsteroides();
			dibujarBotones();

			const double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0042 / 100;

			DrawText(FormatText("%f", temporizador),0+tamanioLetras,0+tamanioLetras,tamanioLetras,DARKGRAY);
			DrawText(FormatText("%i", oleadaActual+1), GetScreenWidth() / 2, 0 + tamanioLetras, tamanioLetras, DARKGRAY);
		}

		void inicializarPantJuego() {
			if (!estaInicializado || fase == inicio) {
				inicializarNave();
				inicializarOleadas();
				inicializarAsteroides();
				inicializarDisparos();
				inicializarBotones();
				fase = juego;
				pausa = false;
				if (!hayVolumen) {
					SetSoundVolume(sonidoDisparo, 0.0f);
					SetSoundVolume(sonidoExplosionAsteroide, 0.0f);
					SetSoundVolume(sonidoExplosionDisparo, 0.0f);
					hayVolumen = false;
				}
				else {
					SetSoundVolume(sonidoDisparo, 0.5f);
					SetSoundVolume(sonidoExplosionAsteroide, 0.5f);
					SetSoundVolume(sonidoExplosionDisparo, 0.5f);
					hayVolumen = true;
				}
			}
			estaInicializado = true;
		}

		void desinicializarPantJuego() {
			if (desinicializar && !IsSoundPlaying(sonidoExplosionAsteroide)) {
				desinicializarNave();
				desinicializarAsteroides();
				UnloadSound(sonidoExplosionAsteroide);
				UnloadSound(sonidoDisparo);
				UnloadSound(sonidoExplosionDisparo);
			
				if (jugadorPerdio()) {
					estado = gameOver;
					desinicializar = false;
					estaInicializado = false;
				}	
			}
		}
	}
}