#include "colisiones.h"

#include "objetos/asteroides.h"
#include "objetos/disparo.h"
#include "objetos/nave.h"
#include "objetos/bomba.h"
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
				if (CheckCollisionCircleRec(asteroide.pos, asteroide.radio,nave.cajaColision)) {
					PlaySound(sonidoExplosionAsteroide);
					nave.perdio = true;
				}
			}
			//Asteroides con disparos y bombas----------------------------
			if (asteroide.activo) {
				for (int i = 0; i < cantMaxDisparos; i++) {
					if (disparo[i].activo) {
						if (CheckCollisionCircleRec(asteroide.pos, asteroide.posYEscala.width / 2, disparo[i].posYEscala)) {
							PlaySound(sonidoExplosionNave);
							asteroide.activo = false;
							disparo[i].activo = false;
							asteroidesDestruidos++;
						}
						
					}
				}
				if (CheckCollisionRecs(Bomba::moab.posYEscala, asteroide.posYEscala) && Bomba::moab.activa) {
					PlaySound(sonidoExplosionNave);
					asteroide.activo = false;
					Bomba::moab.activa = false;
					asteroidesDestruidos++;
				}
				if (asteroidesDestruidos >= 10) {
					nave.gano = true;
				}
			}
		}
	}
}