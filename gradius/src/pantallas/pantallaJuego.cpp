#include "pantallaJuego.h"

#include "raylib.h"
#include "Juego/juego.h"
#include "objetos/nave.h"
#include "objetos/asteroides.h"
#include "objetos/disparo.h"
#include "colisiones/colisiones.h"
#include "botones/botones.h"

namespace Juego {
	namespace PantallaJuego {
		using namespace Asteroides;
		using namespace Nave;
		using namespace Disparo;
		using namespace Colisiones;
		using namespace Botones;

		using namespace Juego;
		static bool estaInicializado = false;
		fases fase = inicio;
		static bool desinicializar = false;
		Sound sonidoDisparo;
		Sound sonidoExplosionNave;
		Sound sonidoExplosionAsteroide;
		bool pausa = false;
		bool hayVolumen = true;
		static fondo estrellasLejos;
		static fondo estrellasCerca;

		static bool jugadorPerdio();
		static void actualizarFondo();
		static void inicializarFondo();

		bool jugadorPerdio() {
			if (nave.perdio||nave.gano){
				return true;
			}
			else {
				return false;
			}	
		}

		void actualizarFondo() {
			estrellasLejos.posYEscala.x -= estrellasLejos.velocidadX*GetFrameTime();
			if (estrellasLejos.posYEscala.x <= 0) {
				estrellasLejos.posYEscala.x =GetScreenWidth();
			}
			estrellasCerca.posYEscala.x -= estrellasCerca.velocidadX*GetFrameTime();
			if (estrellasCerca.posYEscala.x <= 0) {
				estrellasCerca.posYEscala.x = GetScreenWidth();
			}
		}

		void actualizarJuego() {
			actualizarBotones();
			if (!pausa && fase==juego) {
				actualizarFondo();
				actualizarNave();
				actualizarDisparos();
				actualizarAsteroides();
				actualizarColisiones();
			}
			if (jugadorPerdio()) {
				if (!desinicializar) {
					desinicializar = true;
					fase = fin;
				}
			}
			if (fase==salirAMenu) {
				if (!desinicializar) {
					desinicializar = true;
				}
				else {
					estado = menu;
					estaInicializado = false;
					desinicializar = false;
				}
			}
				
		}

		void dibujarJuego() {
			if (!desinicializar&&estaInicializado) {
				DrawTexturePro(estrellasLejos.textura, estrellasLejos.spriteFuente, estrellasLejos.posYEscala, estrellasLejos.origen, estrellasLejos.rotacion, estrellasLejos.colorBase);
				DrawTexturePro(estrellasCerca.textura, estrellasCerca.spriteFuente, estrellasCerca.posYEscala, estrellasCerca.origen, estrellasCerca.rotacion, estrellasCerca.colorBase);
				dibujarDisparos();
				dibujarNave();
				dibujarAsteroides();
				dibujarBotones();
			}
		}

		void inicializarFondo() {
			estrellasLejos.textura = LoadTexture("res/estrellasLejos.png");
			estrellasLejos.velocidadX=300.0f;
			estrellasLejos.spriteFuente= { 0.0f,0.0f,(float)estrellasLejos.textura.width,(float)estrellasLejos.textura.height };
			estrellasLejos.posYEscala= {(float)GetScreenWidth(),(float)GetScreenHeight()/2 ,(float)GetScreenWidth()*2,(float)GetScreenHeight() };
			estrellasLejos.origen= { (float)GetScreenWidth(), (float)GetScreenHeight() / 2 };
			estrellasLejos.rotacion=0.0f;
			estrellasLejos.colorBase = WHITE;

			estrellasCerca.textura = LoadTexture("res/estrellasCerca.png");
			estrellasCerca.velocidadX = 500.0f;
			estrellasCerca.spriteFuente = { 0.0f,0.0f,(float)estrellasLejos.textura.width,(float)estrellasLejos.textura.height };
			estrellasCerca.posYEscala = { (float)GetScreenWidth(),(float)GetScreenHeight() / 2 ,(float)GetScreenWidth() * 2,(float)GetScreenHeight() };
			estrellasCerca.origen = { (float)GetScreenWidth(), (float)GetScreenHeight() / 2 };
			estrellasCerca.rotacion = 0.0f;
			estrellasCerca.colorBase = WHITE;
		}

		void inicializarPantJuego() {
			if (!estaInicializado || fase == inicio) {
				inicializarNave();
				inicializarAsteroides();
				inicializarDisparos();
				inicializarBotones();
				fase = juego;
				pausa = false;
				inicializarFondo();
				sonidoDisparo = LoadSound("res/disparo.wav");
				sonidoExplosionNave = LoadSound("res/explosionNave.wav");
				sonidoExplosionAsteroide = LoadSound("res/explosionAsteroide.wav");
			}
			estaInicializado = true;
		}

		void desinicializarPantJuego() {
			if (desinicializar && !IsSoundPlaying(sonidoExplosionAsteroide) && !IsSoundPlaying(sonidoExplosionNave)) {
				desinicializarNave();
				desinicializarAsteroides();
				UnloadTexture(estrellasLejos.textura);
				UnloadTexture(estrellasCerca.textura);
				UnloadSound(sonidoDisparo);
				UnloadSound(sonidoExplosionNave);
				UnloadSound(sonidoExplosionAsteroide);
			
				if (jugadorPerdio()) {
					estado = gameOver;
					desinicializar = false;
					estaInicializado = false;
				}	
			}
		}
	}
}