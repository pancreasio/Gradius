#ifndef DISPARO_H
#define DISPARO_H

#include "raylib.h"

namespace Juego {
	namespace Disparo {
		struct Balas {
			Vector2 pos;
			Vector2 velocidad;
			float radio;
			float rotacion;
			bool activo;
			Color color;
		};

		extern const int cantMaxDisparos;
		Balas disparo[];
		void inicializarDisparos();
		void actualizarDisparos();
		void dibujarDisparos();
	}
}

#endif