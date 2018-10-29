#include "botones.h"

#include "juego/juego.h"
#include "Pantallas/pantallaJuego.h"

namespace Juego {
	namespace Botones {
		using namespace PantallaJuego;

		static const int cantBotonesMenu = 3;
		static Boton botonMenu[cantBotonesMenu];
		static const int cantBotonesJuego = 2;
		static Boton botonJuego[cantBotonesJuego];
		static const int cantBotonesPausa = 3;
		static Boton botonPausa[cantBotonesPausa];
		static const int cantBotonesCreditos = 1;
		static Boton botonCreditos[cantBotonesCreditos];
		static const int cantBotonesGO = 3;
		static Boton botonGO[cantBotonesGO];
		
		static void inicializarBotonesMenu();
		static void actualizarBotonesMenu();
		static void dibujarBotonesMenu();
		static void inicializarBotonesJuego();
		static void actualizarBotonesJuego();
		static void dibujarBotonesJuego();
		static void inicializarBotonesCreditos();
		static void actualizarBotonesCreditos();
		static void dibujarBotonesCreditos();
		static void inicializarBotonesGO();
		static void actualizarBotonesGO();
		static void dibujarBotonesGO();

		//MENU----------------------------------
		void inicializarBotonesMenu() {
			botonMenu[opcJugar].posYTamanio.y = GetScreenHeight()*0.4f;
			botonMenu[opcJugar].opcion = "Jugar";
			botonMenu[opcCreditos].posYTamanio.y = GetScreenHeight()*0.6f;
			botonMenu[opcCreditos].opcion = "Creditos";
			botonMenu[opcSalirMenu].posYTamanio.y = GetScreenHeight()*0.8f;
			botonMenu[opcSalirMenu].opcion = "Salir";

			for (int i = 0; i < cantBotonesMenu; i++) {
				botonMenu[i].posYTamanio.x = GetScreenWidth() *0.3f;
				botonMenu[i].posYTamanio.width = GetScreenWidth() *0.4f;
				botonMenu[i].posYTamanio.height = GetScreenHeight() *0.15f;
				botonMenu[i].estaSeleccionadaConMouse = false;
				botonMenu[i].estaSeleccionadaConTeclado = false;
				botonMenu[i].centroX = botonMenu[i].posYTamanio.x + botonMenu[i].posYTamanio.width / 2;
				botonMenu[i].centroY = botonMenu[i].posYTamanio.y + botonMenu[i].posYTamanio.height / 2;
			}
		}

		void actualizarBotonesMenu() {
			static int ultimaSeleccion=0;
			botonMenu[ultimaSeleccion].estaSeleccionadaConTeclado = true;

			if (IsKeyPressed(KEY_UP)) {
				if (ultimaSeleccion <= 0) {
					botonMenu[ultimaSeleccion].estaSeleccionadaConTeclado = false;
					ultimaSeleccion = cantBotonesMenu - 1;
					botonMenu[ultimaSeleccion].estaSeleccionadaConTeclado = true;
				}
				else {
					botonMenu[ultimaSeleccion].estaSeleccionadaConTeclado = false;
					ultimaSeleccion--;
					botonMenu[ultimaSeleccion].estaSeleccionadaConTeclado = true;
				}
			}

			if (IsKeyPressed(KEY_DOWN)) {
				if (ultimaSeleccion >= cantBotonesMenu - 1) {
					botonMenu[ultimaSeleccion].estaSeleccionadaConTeclado = false;
					ultimaSeleccion = 0;
					botonMenu[ultimaSeleccion].estaSeleccionadaConTeclado = true;
				}
				else {
					botonMenu[ultimaSeleccion].estaSeleccionadaConTeclado = false;
					ultimaSeleccion++;
					botonMenu[ultimaSeleccion].estaSeleccionadaConTeclado = true;
				}
			}

			if (CheckCollisionPointRec(GetMousePosition(), botonMenu[opcJugar].posYTamanio)) {
				botonMenu[opcJugar].estaSeleccionadaConMouse = true;
				ultimaSeleccion = opcJugar;
			}
			else {
				botonMenu[opcJugar].estaSeleccionadaConMouse = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonMenu[opcSalirMenu].posYTamanio)) {
				botonMenu[opcSalirMenu].estaSeleccionadaConMouse = true;
				ultimaSeleccion = opcSalirMenu;
			}
			else {
				botonMenu[opcSalirMenu].estaSeleccionadaConMouse = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonMenu[opcCreditos].posYTamanio)) {
				botonMenu[opcCreditos].estaSeleccionadaConMouse = true;
				ultimaSeleccion = opcCreditos;
			}
			else {
				botonMenu[opcCreditos].estaSeleccionadaConMouse = false;
			}

			if (botonMenu[opcJugar].estaSeleccionadaConMouse || botonMenu[opcJugar].estaSeleccionadaConTeclado) {
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)||IsKeyReleased(KEY_ENTER)) {
					estado = partida;
				}
			}
			else if (botonMenu[opcCreditos].estaSeleccionadaConMouse || botonMenu[opcCreditos].estaSeleccionadaConTeclado) {
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || IsKeyReleased(KEY_ENTER)) {
					estado = creditos;
				}
			}
			else if (botonMenu[opcSalirMenu].estaSeleccionadaConMouse || botonMenu[opcSalirMenu].estaSeleccionadaConTeclado) {
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || IsKeyReleased(KEY_ENTER)) {
					enJuego = false;
				}
			}

			for (int i = 0; i < cantBotonesMenu; i++) {
				if (botonMenu[i].estaSeleccionadaConMouse) {
					for (int j = 0; j < cantBotonesMenu; j++){
						botonMenu[j].estaSeleccionadaConTeclado= false;
					}
				}
			}

		}

		void dibujarBotonesMenu() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			for (int i = 0; i < cantBotonesMenu; i++) {
				if (botonMenu[i].estaSeleccionadaConMouse|| botonMenu[i].estaSeleccionadaConTeclado) {
					DrawRectangleRec(botonMenu[i].posYTamanio, DARKBLUE);
				}
				else {
					DrawRectangleRec(botonMenu[i].posYTamanio, BLUE);
				}

				DrawText(botonMenu[i].opcion.c_str(), botonMenu[i].centroX - (MeasureText(botonMenu[i].opcion.c_str(), tamanioLetras) / 2), botonMenu[i].centroY, tamanioLetras, BLACK);
			}
		}

		//JUEGO-----------------------------------
		void inicializarBotonesJuego() {
			//En partida------------------------------------
			botonJuego[opcPausar].posYTamanio.x = GetScreenWidth()*0.8f;
			botonJuego[opcPausar].opcion = "Pausar";
			botonJuego[opcSilenciar].posYTamanio.x = GetScreenWidth()*0.9f;
			botonJuego[opcSilenciar].opcion = "Sonido: I/O";

			for (int i = 0; i < cantBotonesJuego; i++) {
				botonJuego[i].posYTamanio.y = GetScreenHeight() *0.01f;
				botonJuego[i].posYTamanio.width = GetScreenWidth() *0.09f;
				botonJuego[i].posYTamanio.height = GetScreenHeight() *0.06f;
				botonJuego[i].estaSeleccionadaConMouse = false;
				botonJuego[i].centroX = botonJuego[i].posYTamanio.x + botonJuego[i].posYTamanio.width / 2;
				botonJuego[i].centroY = botonJuego[i].posYTamanio.y + botonJuego[i].posYTamanio.height / 2;
			}

			//En pausa--------------------------------------------- 
			botonPausa[opcDespausar].posYTamanio.y = GetScreenHeight()*0.4f;
			botonPausa[opcDespausar].opcion = "Continuar";
			botonPausa[opcVolverPausa].posYTamanio.y = GetScreenHeight()*0.6f;
			botonPausa[opcVolverPausa].opcion = "Volver al Menu";
			botonPausa[opcReiniciar].posYTamanio.y = GetScreenHeight()*0.8f;
			botonPausa[opcReiniciar].opcion = "Reiniciar";

			for (int i = 0; i < cantBotonesPausa; i++) {
				botonPausa[i].posYTamanio.x = GetScreenWidth() *0.3f;
				botonPausa[i].posYTamanio.width = GetScreenWidth() *0.4f;
				botonPausa[i].posYTamanio.height = GetScreenHeight() *0.15f;
				botonPausa[i].estaSeleccionadaConMouse = false;
				botonPausa[i].centroX = botonPausa[i].posYTamanio.x + botonPausa[i].posYTamanio.width / 2;
				botonPausa[i].centroY = botonPausa[i].posYTamanio.y + botonPausa[i].posYTamanio.height / 2;
			}
		}

		void actualizarBotonesJuego(){
			//En Pausa---------------------------------
			if (pausa) {
				if (CheckCollisionPointRec(GetMousePosition(), botonPausa[opcDespausar].posYTamanio)) {
					botonPausa[opcDespausar].estaSeleccionadaConMouse = true;
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
						pausa = false;
					}
				}
				else {
					botonPausa[opcDespausar].estaSeleccionadaConMouse = false;
				}
				if (CheckCollisionPointRec(GetMousePosition(), botonPausa[opcReiniciar].posYTamanio)) {
					botonPausa[opcReiniciar].estaSeleccionadaConMouse = true;
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
						fase = inicio;
					}
				}
				else {
					botonPausa[opcReiniciar].estaSeleccionadaConMouse = false;
				}
				if (CheckCollisionPointRec(GetMousePosition(), botonPausa[opcVolverPausa].posYTamanio)) {
					botonPausa[opcVolverPausa].estaSeleccionadaConMouse = true;
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
						fase = salirAMenu;
					}
				}
				else {
					botonPausa[opcVolverPausa].estaSeleccionadaConMouse = false;
				}
			}else {
			//En partida------------------------------------
				if (CheckCollisionPointRec(GetMousePosition(), botonJuego[opcPausar].posYTamanio)) {
					botonJuego[opcPausar].estaSeleccionadaConMouse = true;
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
						pausa = true;
					}
				}
				else {
					botonJuego[opcPausar].estaSeleccionadaConMouse = false;
				}
				if (CheckCollisionPointRec(GetMousePosition(), botonJuego[opcSilenciar].posYTamanio)) {
					botonJuego[opcSilenciar].estaSeleccionadaConMouse = true;
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
						/*if (hayVolumen) {
							SetSoundVolume(sonidoDisparo, 0.0f);
							SetSoundVolume(sonidoExplosionAsteroide, 0.0f);
							SetSoundVolume(sonidoExplosionDisparo, 0.0f);
							hayVolumen = false;
						}else {
							SetSoundVolume(sonidoDisparo, 0.5f);
							SetSoundVolume(sonidoExplosionAsteroide, 0.5f);
							SetSoundVolume(sonidoExplosionDisparo, 0.5f);
							hayVolumen = true;
						}*/
						
					}
				}
				else {
					botonJuego[opcSilenciar].estaSeleccionadaConMouse = false;
				}
			}
			
		}

		void dibujarBotonesJuego() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			//En Pausa-----------------------------------------
			if (pausa) {
				tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
				for (int i = 0; i < cantBotonesPausa; i++) {
					if (botonPausa[i].estaSeleccionadaConMouse) {
						DrawRectangleRec(botonPausa[i].posYTamanio, DARKBLUE);
					}
					else {
						DrawRectangleRec(botonPausa[i].posYTamanio, BLUE);
					}

					DrawText(botonPausa[i].opcion.c_str(), botonPausa[i].centroX - (MeasureText(botonPausa[i].opcion.c_str(), tamanioLetras) / 2), botonPausa[i].centroY, tamanioLetras, BLACK);
				}
			}else {
			//En partida--------------------------------------
				tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0022 / 100;
				for (int i = 0; i < cantBotonesJuego; i++) {
					if (botonJuego[i].estaSeleccionadaConMouse) {
						DrawRectangleRec(botonJuego[i].posYTamanio, DARKBLUE);
					}
					else {
						DrawRectangleRec(botonJuego[i].posYTamanio, BLUE);
					}

					DrawText(botonJuego[i].opcion.c_str(), botonJuego[i].centroX - (MeasureText(botonJuego[i].opcion.c_str(), tamanioLetras) / 2), botonJuego[i].centroY, tamanioLetras, BLACK);
				}
			}
		}

		//CREDITOS-------------------------------
		void inicializarBotonesCreditos() {
			botonCreditos[opcVolverCreditos].posYTamanio.x = GetScreenWidth() *0.3f;
			botonCreditos[opcVolverCreditos].posYTamanio.y = GetScreenHeight() *0.8f;
			botonCreditos[opcVolverCreditos].posYTamanio.width = GetScreenWidth() *0.4f;
			botonCreditos[opcVolverCreditos].posYTamanio.height = GetScreenHeight() *0.15f;
			botonCreditos[opcVolverCreditos].estaSeleccionadaConMouse = false;
			botonCreditos[opcVolverCreditos].estaSeleccionadaConTeclado = false;
			botonCreditos[opcVolverCreditos].centroX = botonCreditos[opcVolverCreditos].posYTamanio.x + botonCreditos[opcVolverCreditos].posYTamanio.width / 2;
			botonCreditos[opcVolverCreditos].centroY = botonCreditos[opcVolverCreditos].posYTamanio.y + botonCreditos[opcVolverCreditos].posYTamanio.height / 2;
			botonCreditos[opcVolverCreditos].opcion = "Volver";
		}

		void actualizarBotonesCreditos() {
			if (CheckCollisionPointRec(GetMousePosition(), botonCreditos[opcVolverCreditos].posYTamanio)) {
				botonCreditos[opcVolverCreditos].estaSeleccionadaConMouse = true;
			}
			else {
				botonCreditos[opcVolverCreditos].estaSeleccionadaConMouse = false;
			}
			
			if (IsKeyReleased(KEY_UP)||IsKeyReleased(KEY_DOWN)) {
				botonCreditos[opcVolverCreditos].estaSeleccionadaConTeclado = true;
			}
			
			if (botonCreditos[opcVolverCreditos].estaSeleccionadaConMouse || botonCreditos[opcVolverCreditos].estaSeleccionadaConTeclado){
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || IsKeyReleased(KEY_ENTER)) {
					estado = menu;
				}
			}
		}

		void dibujarBotonesCreditos() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			if (botonCreditos[opcVolverCreditos].estaSeleccionadaConMouse || botonCreditos[opcVolverCreditos].estaSeleccionadaConTeclado) {
				DrawRectangleRec(botonCreditos[opcVolverCreditos].posYTamanio, DARKBLUE);
			}
			else {
				DrawRectangleRec(botonCreditos[opcVolverCreditos].posYTamanio, BLUE);
			}

			DrawText(botonCreditos[opcVolverCreditos].opcion.c_str(), botonCreditos[opcVolverCreditos].centroX - (MeasureText(botonCreditos[opcVolverCreditos].opcion.c_str(), tamanioLetras) / 2), botonCreditos[opcVolverCreditos].centroY, tamanioLetras, BLACK);
		}

		//GAME OVER------------------------------
		void inicializarBotonesGO() {
			botonGO[opcNuevaPartida].posYTamanio.y = GetScreenHeight()*0.4f;
			botonGO[opcNuevaPartida].opcion = "Volver a Jugar";
			botonGO[opcVolverGO].posYTamanio.y = GetScreenHeight()*0.6f;
			botonGO[opcVolverGO].opcion = "Volver al Menu";
			botonGO[opcSalirGO].posYTamanio.y = GetScreenHeight()*0.8f;
			botonGO[opcSalirGO].opcion = "Salir";

			for (int i = 0; i < cantBotonesGO; i++) {
				botonGO[i].posYTamanio.x = GetScreenWidth() *0.3f;
				botonGO[i].posYTamanio.width = GetScreenWidth() *0.4f;
				botonGO[i].posYTamanio.height = GetScreenHeight() *0.15f;
				botonGO[i].estaSeleccionadaConMouse = false;
				botonGO[i].estaSeleccionadaConTeclado = false;
				botonGO[i].centroX = botonGO[i].posYTamanio.x + botonGO[i].posYTamanio.width / 2;
				botonGO[i].centroY = botonGO[i].posYTamanio.y + botonGO[i].posYTamanio.height / 2;
			}
		}

		void actualizarBotonesGO() {
			static int ultimaSeleccion = 0;
			botonGO[ultimaSeleccion].estaSeleccionadaConTeclado = true;

			if (IsKeyPressed(KEY_UP)) {
				if (ultimaSeleccion <= 0) {
					botonGO[ultimaSeleccion].estaSeleccionadaConTeclado = false;
					ultimaSeleccion = cantBotonesMenu - 1;
					botonGO[ultimaSeleccion].estaSeleccionadaConTeclado = true;
				}
				else {
					botonGO[ultimaSeleccion].estaSeleccionadaConTeclado = false;
					ultimaSeleccion--;
					botonGO[ultimaSeleccion].estaSeleccionadaConTeclado = true;
				}
			}

			if (IsKeyPressed(KEY_DOWN)) {
				if (ultimaSeleccion >= cantBotonesMenu - 1) {
					botonGO[ultimaSeleccion].estaSeleccionadaConTeclado = false;
					ultimaSeleccion = 0;
					botonGO[ultimaSeleccion].estaSeleccionadaConTeclado = true;
				}
				else {
					botonGO[ultimaSeleccion].estaSeleccionadaConTeclado = false;
					ultimaSeleccion++;
					botonGO[ultimaSeleccion].estaSeleccionadaConTeclado = true;
				}
			}

			if (CheckCollisionPointRec(GetMousePosition(), botonGO[opcNuevaPartida].posYTamanio)) {
				botonGO[opcNuevaPartida].estaSeleccionadaConMouse = true;
				ultimaSeleccion = opcNuevaPartida;
			}
			else {
				botonGO[opcNuevaPartida].estaSeleccionadaConMouse = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonGO[opcSalirGO].posYTamanio)) {
				botonGO[opcSalirGO].estaSeleccionadaConMouse = true;
				ultimaSeleccion = opcSalirGO;
			}
			else {
				botonGO[opcSalirGO].estaSeleccionadaConMouse = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonGO[opcVolverGO].posYTamanio)) {
				botonGO[opcVolverGO].estaSeleccionadaConMouse = true;
				ultimaSeleccion = opcVolverGO;
			}
			else {
				botonGO[opcVolverGO].estaSeleccionadaConMouse = false;
			}
			
			if (botonGO[opcNuevaPartida].estaSeleccionadaConMouse || botonGO[opcNuevaPartida].estaSeleccionadaConTeclado) {
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || IsKeyReleased(KEY_ENTER)) {
					estado = partida;
				}
			}
				
			if (botonGO[opcSalirGO].estaSeleccionadaConMouse || botonGO[opcSalirGO].estaSeleccionadaConTeclado) {
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || IsKeyReleased(KEY_ENTER)) {
					enJuego = false;
				}
			}

			if (botonGO[opcVolverGO].estaSeleccionadaConMouse || botonGO[opcVolverGO].estaSeleccionadaConTeclado) {
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) || IsKeyReleased(KEY_ENTER)) {
					estado = menu;
				}
			}	

			for (int i = 0; i < cantBotonesGO; i++) {
				if (botonGO[i].estaSeleccionadaConMouse) {
					for (int j = 0; j < cantBotonesGO; j++) {
						botonGO[j].estaSeleccionadaConTeclado = false;
					}
				}
			}
		}

		void dibujarBotonesGO() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			for (int i = 0; i < cantBotonesGO; i++) {
				if (botonGO[i].estaSeleccionadaConMouse|| botonGO[i].estaSeleccionadaConTeclado) {
					DrawRectangleRec(botonGO[i].posYTamanio, DARKBLUE);
				}
				else {
					DrawRectangleRec(botonGO[i].posYTamanio, BLUE);
				}

				DrawText(botonGO[i].opcion.c_str(), botonGO[i].centroX - (MeasureText(botonGO[i].opcion.c_str(), tamanioLetras) / 2), botonGO[i].centroY, tamanioLetras, BLACK);
			}
		}

		void inicializarBotones() {
			switch (estado) {
			case menu:
				inicializarBotonesMenu();
				break;
			case partida:
				inicializarBotonesJuego();
				break;
			case gameOver:
				inicializarBotonesGO();
				break;
			case creditos:
				inicializarBotonesCreditos();
				break;
			default:break;
			}
		}

		void actualizarBotones() {
			switch (estado) {
			case menu:
				actualizarBotonesMenu();
				break;
			case partida:
				actualizarBotonesJuego();
				break;
			case gameOver:
				actualizarBotonesGO();
				break;
			case creditos:
				actualizarBotonesCreditos();
				break;
			default:break;
			}
		}

		void dibujarBotones() {
			switch (estado) {
			case menu:
				dibujarBotonesMenu();
				break;
			case partida:
				dibujarBotonesJuego();
				break;
			case gameOver:
				dibujarBotonesGO();
				break;
			case creditos:
				dibujarBotonesCreditos();
				break;
			default:break;
			}
		}
	}
}