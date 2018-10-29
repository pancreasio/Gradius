#ifndef ASTEROIDES_H
#define ASTEROIDES_H

#include "raylib.h"

namespace Juego {
	namespace Asteroides {
		struct Asteroide {
			Vector2 pos;
			Vector2 velocidad;
			float radio;
			bool activo;
			Texture2D textura;
			Rectangle posYEscala;
			Rectangle spriteFuente;
			Vector2 origen;
		};

		extern int asteroidesDestruidos;
		extern Asteroide asteroide;
		extern int asteroidesDestruidos;
		void inicializarAsteroides();
		void desinicializarAsteroides();
		void actualizarAsteroides();
		void dibujarAsteroides();
	}
}

#endif