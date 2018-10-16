#include "asteroides.h"

#include "raylib.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Asteroides {
		using namespace PantallaJuego;

		static const int velocidadAst = 200;
		static int radioMaxAst = 8;
		static int radioMinAst = 4;
		static Texture2D spriteAsteroide;
		static const int totalAsteroides = 40;
		int asteroidesDestruidos = 0;
		static void chequearColisionBordes();
		static void moverAsteroides();
		static void crearAsteroides();

		Asteroide asteroide[totalAsteroides];

		void chequearColisionBordes() {
		
		}

		void crearAsteroides() {
			/*for (int i = 0; i < oleada[cantOleadas-1].maxAstPosibles; i++){
				do {
					asteroide[i].pos.x = GetRandomValue(0, GetScreenWidth());
					asteroide[i].pos.y = GetRandomValue(0, GetScreenHeight());
				} while (chequearPosNuevoAst(i));
				do {
					asteroide[i].velocidad.x = GetRandomValue(-velocidadAst, velocidadAst);
					asteroide[i].velocidad.y = GetRandomValue(-velocidadAst, velocidadAst);
				} while (chequearVelNuevoAst(i));

				asteroide[i].radio =(GetRandomValue(radioMinAst,radioMaxAst)/100000.0f) *(float)(GetScreenWidth()*GetScreenHeight());
				asteroide[i].activo = false;
				asteroide[i].textura = spriteAsteroide;
				asteroide[i].posYEscala = { asteroide[i].pos.x , asteroide[i].pos.y , asteroide[i].radio*2 , asteroide[i].radio*2 };
				asteroide[i].spriteFuente = { 0.0f , 0.0f , (float)spriteAsteroide.width , (float)spriteAsteroide.height };
				asteroide[i].origen = { asteroide[i].radio , asteroide[i].radio };
			}*/
		}

		void desinicializarAsteroides() {

		}

		void moverAsteroides() {
			chequearColisionBordes();
			
			/*for (int i = 0; i < ; i++){
				if (asteroide[i].activo){
					asteroide[i].pos.x += asteroide[i].velocidad.x*GetFrameTime();
					asteroide[i].pos.y += asteroide[i].velocidad.y*GetFrameTime();
					asteroide[i].posYEscala.x = asteroide[i].pos.x;
					asteroide[i].posYEscala.y = asteroide[i].pos.y;
				}
			}*/
		}

		void inicializarAsteroides() {
			crearAsteroides();
		}

		void actualizarAsteroides() {
			moverAsteroides();
			chequearColisionBordes();
		}

		void dibujarAsteroides(){
		
		}
	}
}