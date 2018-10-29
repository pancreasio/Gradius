#ifndef JUEGO_H
#define JUEGO_H

namespace Juego {
	enum estados { menu, partida, gameOver, creditos, ayuda };
	extern estados estado;
	extern int anchoPantalla;
	extern int altoPantalla;
	extern bool enJuego;

	void ejecutar();
}
#endif