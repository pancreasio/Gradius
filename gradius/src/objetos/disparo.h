#ifndef DISPARO_H
#define DISPARO_H

#include "raylib.h"

namespace Juego {
	namespace Disparo {
		struct Bala {
			Vector2 pos;
			Vector2 velocidad;
			float rotacion;
			bool activo;
			Texture2D textura;
			Rectangle spriteFuente;
			Rectangle posYEscala;
			Vector2 origen;
			Color color;
		};

		extern const int cantMaxDisparos;
		extern Bala disparo[];
		extern Texture2D spriteDisparo;
		void inicializarDisparos();
		void actualizarDisparos();
		void dibujarDisparos();
		void desinicializarDisparos();
	}
}

#endif