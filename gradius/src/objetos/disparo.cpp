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
		const int cantMaxDisparos=15;
		Bala disparo[cantMaxDisparos];
		Texture2D spriteDisparo;

		void crearDisparos() {
			for (int i = 0; i < cantMaxDisparos; i++){
				disparo[i].pos = { 0.0f, 0.0f };
				disparo[i].velocidad = { 0.0f,0.0f };
				disparo[i].activo = false;
				disparo[i].textura = spriteDisparo;
				disparo[i].spriteFuente = { 0.0f,0.0f,(float)disparo[i].textura.width,(float)disparo[i].textura.height };
				disparo[i].posYEscala = { (float)disparo[i].pos.x,(float)disparo[i].pos.y, 0.000023f*(float)(GetScreenWidth()*GetScreenHeight()), 0.00001f*(float)(GetScreenWidth()*GetScreenHeight()) };//(float)disparo[i].textura.width,(float)disparo[i].textura.height };
				disparo[i].origen = { (float)disparo[i].textura.width / 2,(float)disparo[i].textura.height / 2 };
				disparo[i].rotacion = 0.0f;
				disparo[i].color = WHITE;	
			}
		}

		void inicializarDisparos() {
			spriteDisparo = LoadTexture("res/laser.png");
			crearDisparos();
		}

		void actualizarDisparos(){
			chequearColisionBordes();
			disparar();
			moverDisparos();
		}

		void disparar() {
			if (IsKeyPressed(KEY_SPACE) ) {
				for (int i = 0; i < cantMaxDisparos; i++)	{
					if (!disparo[i].activo) {
						disparo[i].pos = nave.pos;
						disparo[i].posYEscala.x = nave.pos.x;
						disparo[i].posYEscala.y = nave.pos.y;
						disparo[i].activo = true;
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
					disparo[i].pos.x +=velocidadDisparo*GetFrameTime();
					disparo[i].posYEscala.x = disparo[i].pos.x;
				}
			}
		}

		void dibujarDisparos() {
			for (int i = 0; i < cantMaxDisparos; i++){
				if (disparo[i].activo) {
					DrawTexturePro(disparo[i].textura, disparo[i].spriteFuente, disparo[i].posYEscala, disparo[i].origen, disparo[i].rotacion, disparo[i].color);
				}
			}
		}
	}
}