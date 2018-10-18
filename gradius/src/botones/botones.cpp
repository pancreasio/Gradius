#include "botones.h"

#include "juego/juego.h"
#include "Pantallas/pantallaJuego.h"

namespace Juego {
	namespace Botones {
		using namespace PantallaJuego;

		static const int cantBotonesMenu = 3;
		static Botones botonMenu[cantBotonesMenu];
		static const int cantBotonesJuego = 2;
		static Botones botonJuego[cantBotonesJuego];
		static const int cantBotonesPausa = 3;
		static Botones botonPausa[cantBotonesPausa];
		static const int cantBotonesCreditos = 1;
		static Botones botonCreditos[cantBotonesCreditos];
		static const int cantBotonesGO = 3;
		static Botones botonGO[cantBotonesGO];
		
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
				botonMenu[i].estaSeleccionada = false;
				botonMenu[i].centroX = botonMenu[i].posYTamanio.x + botonMenu[i].posYTamanio.width / 2;
				botonMenu[i].centroY = botonMenu[i].posYTamanio.y + botonMenu[i].posYTamanio.height / 2;
			}
		}

		void actualizarBotonesMenu() {
			if (CheckCollisionPointRec(GetMousePosition(), botonMenu[opcJugar].posYTamanio)) {
				botonMenu[opcJugar].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = partida;
				}
			}
			else {
				botonMenu[opcJugar].estaSeleccionada = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonMenu[opcSalirMenu].posYTamanio)) {
				botonMenu[opcSalirMenu].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					enJuego = false;
				}
			}
			else {
				botonMenu[opcSalirMenu].estaSeleccionada = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonMenu[opcCreditos].posYTamanio)) {
				botonMenu[opcCreditos].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = creditos;
				}
			}
			else {
				botonMenu[opcCreditos].estaSeleccionada = false;
			}
		}

		void dibujarBotonesMenu() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			for (int i = 0; i < cantBotonesMenu; i++) {
				if (botonMenu[i].estaSeleccionada) {
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
				botonJuego[i].estaSeleccionada = false;
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
				botonPausa[i].estaSeleccionada = false;
				botonPausa[i].centroX = botonPausa[i].posYTamanio.x + botonPausa[i].posYTamanio.width / 2;
				botonPausa[i].centroY = botonPausa[i].posYTamanio.y + botonPausa[i].posYTamanio.height / 2;
			}
		}

		void actualizarBotonesJuego(){
			//En Pausa---------------------------------
			if (pausa) {
				if (CheckCollisionPointRec(GetMousePosition(), botonPausa[opcDespausar].posYTamanio)) {
					botonPausa[opcDespausar].estaSeleccionada = true;
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
						pausa = false;
					}
				}
				else {
					botonPausa[opcDespausar].estaSeleccionada = false;
				}
				if (CheckCollisionPointRec(GetMousePosition(), botonPausa[opcReiniciar].posYTamanio)) {
					botonPausa[opcReiniciar].estaSeleccionada = true;
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
						fase = inicio;
					}
				}
				else {
					botonPausa[opcReiniciar].estaSeleccionada = false;
				}
				if (CheckCollisionPointRec(GetMousePosition(), botonPausa[opcVolverPausa].posYTamanio)) {
					botonPausa[opcVolverPausa].estaSeleccionada = true;
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
						fase = salirAMenu;
					}
				}
				else {
					botonPausa[opcVolverPausa].estaSeleccionada = false;
				}
			}else {
			//En partida------------------------------------
				if (CheckCollisionPointRec(GetMousePosition(), botonJuego[opcPausar].posYTamanio)) {
					botonJuego[opcPausar].estaSeleccionada = true;
					if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
						pausa = true;
					}
				}
				else {
					botonJuego[opcPausar].estaSeleccionada = false;
				}
				if (CheckCollisionPointRec(GetMousePosition(), botonJuego[opcSilenciar].posYTamanio)) {
					botonJuego[opcSilenciar].estaSeleccionada = true;
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
					botonJuego[opcSilenciar].estaSeleccionada = false;
				}
			}
			
		}

		void dibujarBotonesJuego() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			//En Pausa-----------------------------------------
			if (pausa) {
				tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
				for (int i = 0; i < cantBotonesPausa; i++) {
					if (botonPausa[i].estaSeleccionada) {
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
					if (botonJuego[i].estaSeleccionada) {
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
			botonCreditos[opcVolverCreditos].estaSeleccionada = false;
			botonCreditos[opcVolverCreditos].centroX = botonCreditos[opcVolverCreditos].posYTamanio.x + botonCreditos[opcVolverCreditos].posYTamanio.width / 2;
			botonCreditos[opcVolverCreditos].centroY = botonCreditos[opcVolverCreditos].posYTamanio.y + botonCreditos[opcVolverCreditos].posYTamanio.height / 2;
			botonCreditos[opcVolverCreditos].opcion = "Volver";
		}

		void actualizarBotonesCreditos() {
			if (CheckCollisionPointRec(GetMousePosition(), botonCreditos[opcVolverCreditos].posYTamanio)) {
				botonCreditos[opcVolverCreditos].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = menu;
				}
			}
			else {
				botonCreditos[opcVolverCreditos].estaSeleccionada = false;
			}
		}

		void dibujarBotonesCreditos() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			if (botonCreditos[opcVolverCreditos].estaSeleccionada) {
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
				botonGO[i].estaSeleccionada = false;
				botonGO[i].centroX = botonGO[i].posYTamanio.x + botonGO[i].posYTamanio.width / 2;
				botonGO[i].centroY = botonGO[i].posYTamanio.y + botonGO[i].posYTamanio.height / 2;
			}
		}

		void actualizarBotonesGO() {
			if (CheckCollisionPointRec(GetMousePosition(), botonGO[opcNuevaPartida].posYTamanio)) {
				botonGO[opcNuevaPartida].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = partida;
				}
			}
			else {
				botonGO[opcNuevaPartida].estaSeleccionada = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonGO[opcSalirGO].posYTamanio)) {
				botonGO[opcSalirGO].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					enJuego = false;
				}
			}
			else {
				botonGO[opcSalirGO].estaSeleccionada = false;
			}
			if (CheckCollisionPointRec(GetMousePosition(), botonGO[opcVolverGO].posYTamanio)) {
				botonGO[opcVolverGO].estaSeleccionada = true;
				if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
					estado = menu;
				}
			}
			else {
				botonGO[opcVolverGO].estaSeleccionada = false;
			}
		}

		void dibujarBotonesGO() {
			double tamanioLetras = (GetScreenHeight()*GetScreenWidth())*0.0052 / 100;
			for (int i = 0; i < cantBotonesGO; i++) {
				if (botonGO[i].estaSeleccionada) {
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