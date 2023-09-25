#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "LTexture.h"

class TextureHelper
{
public:
	TextureHelper();

	bool loadMedia(SDL_Renderer* gRenderer, LTexture gSpriteSheetTexture, SDL_Rect gSpriteClips[]);

	LTexture GetTexture(SDL_Renderer* gRenderer);

	SDL_Rect GetSpriteClips();

	bool LoadSpriteClips(SDL_Rect gSpriteClips[]);
};
