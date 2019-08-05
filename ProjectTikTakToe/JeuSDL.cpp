#include "JeuSDL.h"

JeuSDL::JeuSDL() {
	Window = NULL;
	renderer = NULL;
	isRunning = false;
}

JeuSDL::~JeuSDL() {
	Window = NULL;
	renderer = NULL;
	isRunning = false;
}

void JeuSDL::init(const char* titre, int xpos, int ypos, int width, int length, bool fullscreen) {
	Uint32 flags = 0;
	if (fullscreen)flags = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL has Been successfully initilaized...\n";

		Window = SDL_CreateWindow(titre, xpos, ypos, width, length, flags);
		if (Window)std::cout << "The window has benn succesfuly created...\n";

		renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer)std::cout << "The renderer has been succesfuly created...\n";
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

		isRunning = true;
	}
	else {
		std::cout << "Rien n'a été initialisé.\n";
		isRunning = false;
		exit(EXIT_FAILURE);	
	}
	SDL_Surface* tmpSurface = IMG_Load("Grille.png");
	img.setTexture(SDL_CreateTextureFromSurface(renderer, tmpSurface));
	SDL_FreeSurface(tmpSurface);
	
}

void JeuSDL::update() {

}
SDL_Renderer* JeuSDL::getRenderer()const {
	return renderer;
}
void JeuSDL::handlevent() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type){
		case SDL_QUIT:
		isRunning = false;
			break;
		default:
			break;
	}
}

void JeuSDL::render() { // here where we render all our objects on the screen
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, img.getTexture(), NULL, NULL);
	SDL_RenderPresent(renderer);
}

void JeuSDL::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
	std::cout << "jeu est netoyee...\n";
}

bool JeuSDL::running() {
	return isRunning;
}