#include "disparo.h"

#include <cmath>

#include "raylib.h"
#include "nave.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Disparo {
		using namespace Nave;
		using namespace PantallaJuego;

		static void crearDisparos();
		static void disparar();
		static void chequearColisionBordes();
		static void moverDisparos();
		static const float velocidadDisparo = 350.0f;
		const int cantMaxDisparos=4;
		Balas disparo[cantMaxDisparos];

		void crearDisparos() {
			for (int i = 0; i < cantMaxDisparos; i++){
				disparo[i].pos = { 0.0f, 0.0f };
				disparo[i].velocidad = { 0.0f,0.0f };
				disparo[i].radio = 0.000005*((float)GetScreenWidth()*GetScreenHeight());
				disparo[i].rotacion = 0.0f;
				disparo[i].activo = false;
				disparo[i].color = BLACK;	
			}
		}

		void inicializarDisparos() {
			crearDisparos();
		}

		void actualizarDisparos(){
			chequearColisionBordes();
			disparar();
			moverDisparos();
		}

		void disparar() {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				for (int i = 0; i < cantMaxDisparos; i++)	{
					if (!disparo[i].activo) {
						disparo[i].pos = nave.pos;
						disparo[i].activo = true;
						disparo[i].rotacion = 90.0f;
						break;
					}
				}
			}
		}

		void chequearColisionBordes() {
			for (int i = 0; i < cantMaxDisparos; i++)
			{
				if (disparo[i].pos.x < 0){
					disparo[i].activo = false;
				}else if (disparo[i].pos.x > GetScreenWidth()) {
					disparo[i].activo = false;
				}
				if (disparo[i].pos.y < 0){
					disparo[i].activo = false;
				}else if (disparo[i].pos.y > GetScreenHeight()) {
					disparo[i].activo = false;
				}
			}
		}

		void moverDisparos() {
			for (int i = 0; i < cantMaxDisparos; i++){
				if (disparo[i].activo) {
					disparo[i].velocidad.x = sin(disparo[i].rotacion*DEG2RAD)*velocidadDisparo;
					disparo[i].velocidad.y = cos(disparo[i].rotacion*DEG2RAD)*velocidadDisparo;

					disparo[i].pos.x += disparo[i].velocidad.x*GetFrameTime();
					disparo[i].pos.y -= disparo[i].velocidad.y*GetFrameTime();
				}
			}
		}

		void dibujarDisparos() {
			for (int i = 0; i < cantMaxDisparos; i++){
				if (disparo[i].activo) {
					DrawCircle(disparo[i].pos.x, disparo[i].pos.y,disparo[i].radio,disparo[i].color);
				}
			}
		}
	}
}