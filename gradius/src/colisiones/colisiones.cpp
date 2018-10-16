#include "colisiones.h"

#include "objetos/asteroides.h"
#include "objetos/disparo.h"
#include "objetos/nave.h"
#include "oleadas/oleadas.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Colisiones {
		using namespace Asteroides;
		using namespace Nave;
		using namespace Disparo;
		using namespace Oleadas;
		using namespace PantallaJuego;

		void actualizarColisiones() {
			//Nave con asteroides------------------------------
			for (int i = 0; i < oleada[oleadaActual].maxAstPosibles; i++){
				if (asteroide[i].activo) {
					if (CheckCollisionCircles(nave.pos, nave.posYEscala.width / 2, asteroide[i].pos, asteroide[i].radio)) {
						nave.perdio = true;
						PlaySound(sonidoExplosionAsteroide);
						break;
					}
				}
			}

			//Asteroides con disparos----------------------------
			for (int i = 0; i < oleada[oleadaActual].maxAstPosibles; i++) {
				for (int j = 0; j < cantMaxDisparos; j++){
					if (disparo[j].activo && asteroide[i].activo) {
						if (CheckCollisionCircles(disparo[j].pos, disparo[j].radio, asteroide[i].pos, asteroide[i].radio)) {
							asteroidesDestruidos++;
							disparo[j].activo = false;
							asteroide[i].activo = false;
							PlaySound(sonidoExplosionDisparo);
							break;
						}
					}
				}	
			}
		}
	}
}