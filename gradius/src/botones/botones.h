#ifndef BOTONES_H
#define BOTONES_H

#include <string>

#include "raylib.h"

namespace Juego {
	namespace Botones {
		enum opcionesMenu { opcJugar, opcCreditos, opcSalirMenu };
		enum opcionesJuego { opcPausar};
		enum opcionesPausa {opcDespausar, opcSilenciar,opcVolverPausa,opcReiniciar};
		enum opcionesGO { opcNuevaPartida, opcVolverGO, opcSalirGO };
		enum opcionesCreditos {opcVolverCreditos};
		struct Boton {
			Rectangle posYTamanio;
			bool estaSeleccionadaConMouse;
			bool estaSeleccionadaConTeclado;	//distingue si el usuario esta usando el mouse o el teclado para desplazarse por los botones
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