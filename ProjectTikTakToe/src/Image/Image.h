#ifndef IMAGE_H
#define IMAGE_H

#include <assert.h>
#include <iostream>
#include <string>
#include <SDL.h>

#include <SDL_image.h>

using namespace std;

class Image
{
public:
	Image();
	void loadFromFile(const char* filename, SDL_Renderer* renderer);
	void draw(SDL_Renderer* renderer, int x, int y, int w, int h);
	SDL_Texture* getTexture()const;
	SDL_Surface* getSurface()const;
	void setTexture(SDL_Texture * noveau_texture);
	void setSurface(SDL_Surface* nouveau_surf);

private:
	//SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Surface* surface;
	bool has_changed;
};




#endif // !IMAGE_H
