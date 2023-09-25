#include "TextureHelper.h"

const int WALKING_ANIMATION_FRAMES = 4;

TextureHelper::TextureHelper()
{

}

//Loads media
bool TextureHelper::loadMedia(SDL_Renderer* gRenderer, LTexture gSpriteSheetTexture, SDL_Rect gSpriteClips[])
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!gSpriteSheetTexture.loadFromFile("images/foo.png", gRenderer))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 64;
		gSpriteClips[0].h = 205;

		gSpriteClips[1].x = 64;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 64;
		gSpriteClips[1].h = 205;

		gSpriteClips[2].x = 128;
		gSpriteClips[2].y = 0;
		gSpriteClips[2].w = 64;
		gSpriteClips[2].h = 205;

		gSpriteClips[3].x = 192;
		gSpriteClips[3].y = 0;
		gSpriteClips[3].w = 64;
		gSpriteClips[3].h = 205;
	}

	return success;
}

// TODO - Pass in the file location we are loading. 
LTexture TextureHelper::GetTexture(SDL_Renderer* gRenderer)
{
	LTexture gSpriteSheetTexture;

	if (!gSpriteSheetTexture.loadFromFile("images/foo2.png", gRenderer))
	{
		printf("Failed to load walking animation texture!\n");
	}

	return gSpriteSheetTexture;
}

// TODO - Do this in a better way!
SDL_Rect TextureHelper::GetSpriteClips()
{
	SDL_Rect gSpriteClips[WALKING_ANIMATION_FRAMES];

	//Set sprite clips
	gSpriteClips[0].x = 0;
	gSpriteClips[0].y = 0;
	gSpriteClips[0].w = 64;
	gSpriteClips[0].h = 205;

	gSpriteClips[1].x = 64;
	gSpriteClips[1].y = 0;
	gSpriteClips[1].w = 64;
	gSpriteClips[1].h = 205;

	gSpriteClips[2].x = 128;
	gSpriteClips[2].y = 0;
	gSpriteClips[2].w = 64;
	gSpriteClips[2].h = 205;

	gSpriteClips[3].x = 192;
	gSpriteClips[3].y = 0;
	gSpriteClips[3].w = 64;
	gSpriteClips[3].h = 205;

	return gSpriteClips[WALKING_ANIMATION_FRAMES];
}

bool TextureHelper::LoadSpriteClips(SDL_Rect gSpriteClips[])
{
	//Set sprite clips
	gSpriteClips[0].x = 0;
	gSpriteClips[0].y = 0;
	gSpriteClips[0].w = 64;
	gSpriteClips[0].h = 205;

	gSpriteClips[1].x = 64;
	gSpriteClips[1].y = 0;
	gSpriteClips[1].w = 64;
	gSpriteClips[1].h = 205;

	gSpriteClips[2].x = 128;
	gSpriteClips[2].y = 0;
	gSpriteClips[2].w = 64;
	gSpriteClips[2].h = 205;

	gSpriteClips[3].x = 192;
	gSpriteClips[3].y = 0;
	gSpriteClips[3].w = 64;
	gSpriteClips[3].h = 205;

	return true;
}