#ifndef JEUSDL_H
#define JEUSDL_H
#include <iostream>

#include "src/Image/Image.h"

class JeuSDL{
public:
	JeuSDL();
	~JeuSDL();

	void init(const char* titre, int xpos, int ypos, int width, int length, bool fullscreen);
	void handlevent();
	void update();
	void render();
	void clean();
	SDL_Renderer* getRenderer()const;
	bool running();
private:
	Image img;
	bool isRunning;
	SDL_Window* Window;
	SDL_Renderer* renderer;

};
#endif