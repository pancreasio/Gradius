#include "pantallaJuego.h"

#include "raylib.h"
#include "Juego/juego.h"
#include "objetos/nave.h"
#include "objetos/asteroides.h"
#include "objetos/disparo.h"
#include "colisiones/colisiones.h"
#include "botones/botones.h"

namespace Juego {
	namespace PantallaJuego {
		using namespace Asteroides;
		using namespace Nave;
		using namespace Disparo;
		using namespace Colisiones;
		using namespace Botones;

		using namespace Juego;
		static bool estaInicializado = false;
		fases fase = inicio;
		static bool desinicializar = false;
		bool pausa = false;
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
		}

		void inicializarPantJuego() {
			if (!estaInicializado || fase == inicio) {
				inicializarNave();
				inicializarAsteroides();
				inicializarDisparos();
				inicializarBotones();
				fase = juego;
				pausa = false;
			}
			estaInicializado = true;
		}

		void desinicializarPantJuego() {
			if (desinicializar) {
				desinicializarNave();
				desinicializarAsteroides();
			
				if (jugadorPerdio()) {
					estado = gameOver;
					desinicializar = false;
					estaInicializado = false;
				}	
			}
		}
	}
}