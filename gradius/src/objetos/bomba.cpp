#include "bomba.h"

#include "raylib.h"
#include "nave.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Bomba {
		using namespace Nave;
		using namespace PantallaJuego;

		const double cooldownBomba = 2;
		double ultimaBomba;
		Texture2D spriteBomba;
		Bomba moab;
		static const float velocidadBombaY = 350.0f;
		static const float maxVelocidadBombaX = 200.0f;
		static float velocidadBombaX;
		static const float desaceleracionBombaX = 0.02f;

		

		void inicializarBomba() {
			spriteBomba = LoadTexture("res/granadaGradius.png");
			moab.activa = false;
			moab.pos = { 0.0f,0.0f };
			moab.velocidad = { 0.0f,0.0f };
			moab.textura = spriteBomba;
			moab.spriteFuente = { 0.0f,0.0f,(float)moab.textura.width,(float)moab.textura.height };
			moab.posYEscala = { (float)moab.pos.x,(float)moab.pos.y, 0.000023f*(float)(GetScreenWidth()*GetScreenHeight()), 0.00001f*(float)(GetScreenWidth()*GetScreenHeight()) };//(float)moab.textura.width,(float)moab.textura.height };
			moab.origen = { (float)moab.textura.width / 2,(float)moab.textura.height / 2 };
			moab.rotacion = 0.0f;
			moab.color = WHITE;
			ultimaBomba = GetTime();
			velocidadBombaX = maxVelocidadBombaX;
		}

		void chequearColisionBordes() {
			if (moab.pos.x < 0 || moab.pos.x > GetScreenWidth()) {
				moab.activa = false;
			}

			if (moab.pos.y < 0 || moab.pos.y > GetScreenHeight()) {
				moab.activa = false;
			}
		}

		void disparar() {
			if (IsKeyPressed(KEY_LEFT_SHIFT)) {
				if (!moab.activa && ultimaBomba < GetTime() - cooldownBomba) {
					moab.pos = nave.pos;
					moab.posYEscala.x = nave.pos.x;
					moab.posYEscala.y = nave.pos.y;
					moab.activa = true;
					velocidadBombaX = maxVelocidadBombaX;
				}
			}
		}

		void moverBomba() {
			if (moab.activa) {
				moab.pos.y += velocidadBombaY * GetFrameTime();
				moab.pos.x += velocidadBombaX * GetFrameTime();
				if (velocidadBombaX > 0) {
					velocidadBombaX -= desaceleracionBombaX;
				}
				moab.posYEscala.x = moab.pos.x;
				moab.posYEscala.y = moab.pos.y;
			}
		}

		void actualizarBomba() {
			chequearColisionBordes();
			disparar();
			moverBomba();
		}

		void dibujarBomba() {
			if (moab.activa) {
				DrawTexturePro(moab.textura, moab.spriteFuente, moab.posYEscala, moab.origen, moab.rotacion, moab.color);
			}
		}

		void desinicializarBomba() {

		}
	}
}