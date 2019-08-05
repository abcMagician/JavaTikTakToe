#include "Image.h"


Image::Image() {
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
		cout << "Erreur de l'Initialisation de SDL_image\n"<<IMG_GetError()<<endl; 
		exit(EXIT_FAILURE);
	}
	else{
		texture = nullptr;
		surface = nullptr;
		has_changed = false;
	}
}



void Image::loadFromFile(const char* filename, SDL_Renderer* renderer) {
	surface = IMG_Load(filename);
	if (surface == NULL) {
		string nfn = string("../") + filename;
		cout << "Error: cannot load " << filename << " Trying " << nfn << endl;
		surface = IMG_Load(nfn.c_str());
		if (surface == NULL) {
			nfn = string("../") + nfn;
			surface = IMG_Load(nfn.c_str());
		}
	}
	if (surface == NULL) {
		cout << "Error: cannot load " << filename << endl;
		exit(1);
	}

	SDL_Surface* surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_ARGB8888, 0);
	SDL_FreeSurface(surface);
	surface = surfaceCorrectPixelFormat;

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) {
		cout << "Error: problem to create the texture of " << filename << endl;
		exit(1);
	}
}

void Image::draw(SDL_Renderer* renderer, int x, int y, int w, int h) {
	int ok;
	SDL_Rect r;
	r.x = x;
	r.y = y;
	r.w = (w < 0) ? surface->w : w;
	r.h = (h < 0) ? surface->h : h;

	if (has_changed) {
		ok = SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
		assert(ok == 0);
		has_changed = false;
	}

	ok = SDL_RenderCopy(renderer, texture, NULL, &r);
	assert(ok == 0);
}

SDL_Surface* Image::getSurface()const { return surface; }
SDL_Texture* Image::getTexture()const { return texture; }

void Image::setTexture(SDL_Texture* noveau_texture)
{
	texture = noveau_texture;
}

void Image::setSurface( SDL_Surface* nouveau_surf)
{
	surface = nouveau_surf;
}



