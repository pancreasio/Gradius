#include "colisiones.h"

#include "objetos/asteroides.h"
#include "objetos/disparo.h"
#include "objetos/nave.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Colisiones {
		using namespace Asteroides;
		using namespace Nave;
		using namespace Disparo;
		using namespace PantallaJuego;

		void actualizarColisiones() {
			//Nave con asteroides------------------------------
			if (asteroide.activo) {
				if (CheckCollisionCircles(nave.pos, nave.posYEscala.width / 2, asteroide.pos, asteroide.radio)) {
					nave.perdio = true;
				}
			}

			//Asteroides con disparos----------------------------

		}
	}
}