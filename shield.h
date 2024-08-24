#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>
#include <ctime>
#include "inventory.h"

class Shield
{
private:
public:
	Texture sh;
	Sprite sprite;
	int x, y;
	int width;
	int height;
	bool isCollided;
	Shield() {  }
	Shield(string png_path, int x, int y)
	{
		//cout << "Now in shield constructor\n";
		sh.loadFromFile(png_path);
		sprite.setTexture(sh);
		sprite.setPosition(x, y);
		sprite.getPosition();
		sprite.setScale(0.75, 0.75);

		this->isCollided = false;

		width = static_cast<int>(sh.getSize().x * 0.75);
		height = static_cast<int>(sh.getSize().y * 0.75);
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}

	bool getCollided() {
		return isCollided;
	}

	void setCollided(bool isCollide) {
		this->isCollided = isCollide;
	}

	void updatePositionWithCollide(float x, float y) {
		this->setCollided(true);
		this->setPosition(x, y);
	}

	void setPosition(float x, float y)
	{
		this->x = x;
		this->y = y;
		sprite.setPosition(this->x, this->y);
	}

	void spritMove(float offsetX, float offsetY) {
		this->sprite.move(offsetX, offsetY);

	}
};
