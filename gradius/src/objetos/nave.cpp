#include "nave.h"

#include "raylib.h"
#include "pantallas/pantallaJuego.h"

namespace Juego {
	namespace Nave {

		void moverNave();
		void chequearColisionBordes();
		Jug nave;
		static const float velocidadNave = 600.0f;
		
		void chequearColisionBordes() {
			//Colision con bordes
			if (nave.pos.y- nave.textura.height  <= 0) {
				nave.pos.y = nave.textura.height ;
			}else if (nave.pos.y + nave.textura.height >= GetScreenHeight()) {
				nave.pos.y = GetScreenHeight() - nave.textura.height;
			}
		}

		void moverNave() {
			//MOVIMIENTO -------------------------------------------
			if (IsKeyDown(KEY_UP)||IsKeyDown(KEY_W)){
				nave.velocidad.y = -velocidadNave *GetFrameTime();
				nave.spriteFuente= { ((float)nave.textura.width / 3)*2, 0.0f, (float)nave.textura.width/3, (float)nave.textura.height };
			}else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
				nave.velocidad.y = velocidadNave *GetFrameTime();
				nave.spriteFuente = { 0.0f, 0.0f, (float)nave.textura.width/3, (float)nave.textura.height };
			}else {
				nave.velocidad.y = 0;
				nave.spriteFuente = { (float)nave.textura.width / 3, 0.0f, (float)nave.textura.width / 3, (float)nave.textura.height };
			}

			nave.pos.y += nave.velocidad.y;
			nave.posYEscala.y = nave.pos.y;
			nave.cajaColision.y = nave.pos.y - nave.posYEscala.height / 2;
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
			nave.posYEscala = { nave.pos.x, nave.pos.y, (float)nave.textura.width * 1.5f, (float)nave.textura.height * 2.0f };			//los primeros dos valores dan la posicion y los otros escalan la textura al tamaño deseado
			nave.cajaColision = {nave.pos.x-nave.posYEscala.width/2,nave.pos.y-nave.posYEscala.height/2,nave.posYEscala.width,nave.posYEscala.height};
			nave.spriteFuente = { (float)nave.textura.width / 3, 0.0f, (float)nave.textura.width/3, (float)nave.textura.height };		//indica que parte del archivo de imagen se toma(por si hay una tira de sprites)
			nave.origen = { (float)nave.textura.width * 0.75f,(float)nave.textura.height };												//pto de referencia para la rotacion
			nave.perdio = false;
			nave.gano = false;
		}

		void desinicializarNave() {
			UnloadTexture(nave.textura);
		}
	}
}