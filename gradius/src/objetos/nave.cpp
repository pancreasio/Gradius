#include "nave.h"

#include <cmath>

#include "raylib.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Nave {

		void moverNave();
		void chequearColisionBordes();
		Jug nave;
		static const float aceleracionBase = 100.0f;
		static const float velocidadMax = 200.0f;
		static Vector2 vecReferncia;		//vector de la nave.pos al x=0 y=nave.pos
		static Vector2 vecDireccion;		//vector de la nave.pos a la pos del mouse
		static float prodVec;
		static float moduloVRef;
		static float moduloVDir;
		static float prodMod;
		
		void chequearColisionBordes() {
			//Colision con bordes
			if (nave.pos.x <= 0) {
				nave.pos.x = GetScreenWidth();
			}else if (nave.pos.x >= GetScreenWidth()) {
				nave.pos.x = 0;
			}

			if (nave.pos.y <= 0) {
				nave.pos.y = GetScreenHeight();
			}else if (nave.pos.y >= GetScreenHeight()) {
				nave.pos.y = 0+5;
			}
		}


		void moverNave() {
			//MOVIMIENTO -------------------------------------------
			if (IsKeyDown(KEY_UP)||IsKeyDown(KEY_W)){
				nave.velocidad.y = -500.0f*GetFrameTime();
				nave.spriteFuente= { ((float)nave.textura.width / 3)*2, 0.0f, (float)nave.textura.width/3, (float)nave.textura.height };
			}else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
				nave.velocidad.y = 500.0f*GetFrameTime();
				nave.spriteFuente = { 0.0f, 0.0f, (float)nave.textura.width/3, (float)nave.textura.height };
			}else {
				nave.velocidad.y = 0;
				nave.spriteFuente = { (float)nave.textura.width / 3, 0.0f, (float)nave.textura.width / 3, (float)nave.textura.height };
			}

			nave.pos.y += nave.velocidad.y;
			nave.posYEscala.y = nave.pos.y;
		}

		void actualizarNave() {
			moverNave();
			chequearColisionBordes();
		}

		void dibujarNave() {
			if (!PantallaJuego::pausa) {
				DrawTexturePro(nave.textura, nave.spriteFuente, nave.posYEscala, nave.origen, 0.0f, WHITE);
			}else {
				DrawTexturePro(nave.textura, nave.spriteFuente, nave.posYEscala, nave.origen, 0.0f, LIGHTGRAY);
			}
			
		}

		void inicializarNave() {
			nave.velocidad.x = 0.0f;
			nave.velocidad.y = 0.0f;
			nave.aceleracion.x = 0.0f;
			nave.aceleracion.y = 0.0f;
			nave.textura = LoadTexture("res/naveGradius.png");
			nave.pos.x = (float)GetScreenWidth()*0.01+nave.textura.width;
			nave.pos.y = (float)GetScreenHeight() / 2;
			nave.posYEscala = { nave.pos.x, nave.pos.y, (float)nave.textura.width * 1.5f, (float)nave.textura.height * 1.5f };			//los primeros dos valores dan la posicion y los otros escalan la textura al tamaño deseado
			nave.spriteFuente = { (float)nave.textura.width / 3, 0.0f, (float)nave.textura.width/3, (float)nave.textura.height };		//indica que parte del archivo de imagen se toma(por si hay una tira de sprites)
			nave.origen = { (float)nave.textura.width * 0.75f,(float)nave.textura.height * 0.75f };										//pto de referencia para la rotacion
			nave.perdio = false;
			nave.gano = false;
		}

		void desinicializarNave() {

		}
	}
}