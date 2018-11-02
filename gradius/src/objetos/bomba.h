#ifndef BOMBA_H
#define BOMBA_H

#include "raylib.h"

namespace Juego {
	namespace Bomba {
		struct Bomba {
			Vector2 pos;
			Vector2 velocidad;
			float rotacion;
			bool activa;
			Texture2D textura;
			Rectangle spriteFuente;
			Rectangle posYEscala;
			Vector2 origen;
			Color color;
		};

		extern const double cooldownBomba;
		extern double ultimaBomba;
		extern Texture2D spriteBomba;
		extern Bomba moab;
		void inicializarBomba();
		void actualizarBomba();
		void dibujarBomba();
		void desinicializarBomba();
	}
}

#endif