#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include"raylib.h"

namespace Juego {
	namespace PantallaJuego {
		struct fondo {
			Texture2D textura;
			float velocidadX;
			Rectangle spriteFuente;
			Rectangle posYEscala;
			Vector2 origen;
			float rotacion;
			Color colorBase;
		};
		enum fases { inicio, juego, salirAMenu, fin };
		extern fases fase;
		extern Sound sonidoDisparo;
		extern Sound sonidoExplosionNave;
		extern Sound sonidoExplosionAsteroide;
		extern bool pausa;
		extern bool hayVolumen;

		void actualizarJuego();
		void dibujarJuego();
		void inicializarPantJuego();
		void desinicializarPantJuego();
	}
}

#endif