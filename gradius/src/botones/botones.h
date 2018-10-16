#ifndef BOTONES_H
#define BOTONES_H

#include <string>

#include "raylib.h"

namespace Juego {
	namespace Botones {
		enum opcionesMenu { opcJugar, opcCreditos, opcSalirMenu };
		enum opcionesJuego { opcPausar, opcSilenciar};
		enum opcionesPausa {opcDespausar,opcVolverPausa,opcReiniciar};
		enum opcionesGO { opcVolverGO, opcNuevaPartida, opcSalirGO };
		enum opcionesCreditos {opcVolverCreditos};
		struct Botones {
			Rectangle posYTamanio;
			bool estaSeleccionada;
			std::string opcion;
			float centroX;
			float centroY;
		};

		void inicializarBotones();
		void actualizarBotones();
		void dibujarBotones();
	}
}

#endif