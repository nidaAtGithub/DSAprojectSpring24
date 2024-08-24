#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include "inventory.h"
#include "maze.h"
#include "sword.h";
#include "shield.h"
#include "score.h"

using namespace std;
using namespace sf;

class Objects
{
	int x;
	int y;
	static const int numShields = 3;  // Updated to 3 shields
	static const int numSwords = 2;
	AVLTree inventory;
	Maze obj;
	int scoreCal;
	Score score;
	bool shieldActive[numShields] = { true, true, true };
	// Initialize other game objects similarly...
	ConvexShape shields[numShields];
	Shield objS;
	bool key = false;
	bool key2 = false;
public:
	Objects() {}
	
	void setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	/*int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}*/
	void drawDragon(RenderWindow& window, Clock& clock)
	{
		const int numDragons = 4;
		static Vector2f headPositions[numDragons] = {
			Vector2f(273, 420),
			Vector2f(414, 400),
			Vector2f(174, 140),
			Vector2f(494, 110)
		};

		// Define boundaries and movement speed for each dragon
		const float minY[numDragons] = { 380, 340, 80, 80 };
		const float maxY[numDragons] = { 470, 434, 173, 134 };

		const float speed[numDragons] = { 70, 60, 40, 70 }; // Speed can be adjusted per dragon

		static float targetY[numDragons]; // Keep track of target positions
		static bool initialized = false;

		// Initialize targets once
		if (!initialized) {
			for (int i = 0; i < numDragons; i++)
			{
				targetY[i] = headPositions[i].y;
			}
			initialized = true;
		}

		// Calculate delta time
		float deltaTime = clock.restart().asSeconds();

		CircleShape heads[numDragons];
		ConvexShape leftHorns[numDragons], rightHorns[numDragons];
		CircleShape leftEyes[numDragons], rightEyes[numDragons];

		float hornHeight = 10.0f;
		float hornBaseHalfLength = 5.0f;
		int i = 0;
		while(i < numDragons) 
		{
			// Check if it is time to change target position
			if (fabs(targetY[i] - headPositions[i].y) < 1.0)
			{
				targetY[i] = minY[i] + static_cast<float>(rand() % static_cast<int>(maxY[i] - minY[i] + 1));
			}

			// Move towards the target position
			if (headPositions[i].y < targetY[i])
			{
				headPositions[i].y += speed[i] * deltaTime;
				if (headPositions[i].y > targetY[i])
				{
					headPositions[i].y = targetY[i];
				}
			}
			else {
				headPositions[i].y -= speed[i] * deltaTime;
				if (headPositions[i].y < targetY[i]) {
					headPositions[i].y = targetY[i];
				}
			}

			// Setup head
			heads[i].setRadius(7);
			heads[i].setFillColor(Color(128, 0, 128)); // Purple
			heads[i].setPosition(headPositions[i]);

			// Setup horns
			leftHorns[i].setPointCount(3);
			rightHorns[i].setPointCount(3);
			Vector2f hornTipLeft = Vector2f(headPositions[i].x + 4, headPositions[i].y - hornHeight);
			Vector2f hornTipRight = Vector2f(headPositions[i].x + 10, headPositions[i].y - hornHeight);

			leftHorns[i].setPoint(0, hornTipLeft);
			leftHorns[i].setPoint(1, Vector2f(hornTipLeft.x - hornBaseHalfLength, hornTipLeft.y + hornHeight));
			leftHorns[i].setPoint(2, Vector2f(hornTipLeft.x + hornBaseHalfLength, hornTipLeft.y + hornHeight));
			leftHorns[i].setFillColor(Color::Black);

			rightHorns[i].setPoint(0, hornTipRight);
			rightHorns[i].setPoint(1, Vector2f(hornTipRight.x - hornBaseHalfLength, hornTipRight.y + hornHeight));
			rightHorns[i].setPoint(2, Vector2f(hornTipRight.x + hornBaseHalfLength, hornTipRight.y + hornHeight));
			rightHorns[i].setFillColor(Color::Black);

			// Setup eyes
			leftEyes[i].setRadius(1.7);
			leftEyes[i].setFillColor(Color::Red);
			leftEyes[i].setPosition(headPositions[i].x + 2, headPositions[i].y + 2);

			rightEyes[i].setRadius(1.7);
			rightEyes[i].setFillColor(Color::Red);
			rightEyes[i].setPosition(headPositions[i].x + 9, headPositions[i].y + 2);

			// Draw all parts
			window.draw(heads[i]);
			window.draw(leftHorns[i]);
			window.draw(rightHorns[i]);
			window.draw(leftEyes[i]);
			window.draw(rightEyes[i]);

			i++;
		}
	}
	
	int checkCollision(int nextPos, RenderWindow& window)
	{
		static bool collectedItems[19] = { false };

		// Collision with shields
		cout << nextPos << endl;
		if (nextPos == 184)   //Shield 1
		{
			if (!collectedItems[0]) 
			{
				collectedItems[0] = true;
				inventory.insert(1);
				return 1;
			}
		}
		else if (nextPos == 430 )    //Shield 2
		{
			if (!collectedItems[1]) {
				collectedItems[1] = true;
				inventory.insert(2);
				return 2;
			}
		}
		else if (nextPos == 677 )    //Shield 3
		{
			if (!collectedItems[2]) {
				collectedItems[2] = true;
				inventory.insert(3);
				return 3;
			}
		}
		else if (nextPos == 119)   //Sword 1
		{
			if (!collectedItems[3]) {
				collectedItems[3] = true;
				inventory.insert(4);
				return 4;
			}
		}
		else if (nextPos == 364)   //Sword 2
		{
			if (!collectedItems[4]) {
				collectedItems[4] = true;
				inventory.insert(5);
				return 5;
			}
		}
		else if (nextPos == 762)      //Sword 3
		{
			if (!collectedItems[5]) {
				collectedItems[5] = true;
				inventory.insert(6);
				return 6;
			}
		}
		else if (nextPos == 92) //Dollar 10 1
		{

			if (!collectedItems[6]) {
				collectedItems[6] = true;
				scoreCal = scoreCal + 10;
				score.setScore(scoreCal);

				inventory.insert(7);
				return 7;
			}
		}
		else if (nextPos == 164)   //Dollar 10  2
		{

			if (!collectedItems[7])
			{
				collectedItems[7] = true;
				scoreCal = scoreCal + 10;
				score.setScore(scoreCal);

				inventory.insert(8);
				return 8;
			}
		}
		else if (nextPos == 120)  //1000 dollar
		{

			if (!collectedItems[8]) {
				collectedItems[8] = true;
				scoreCal = scoreCal + 1000;
				score.setScore(scoreCal);

				inventory.insert(9);
				return 9;
			}
		}
		else if (nextPos == 636)   //Key 2
		{
			key2 = true;

			if (!collectedItems[9]) {
				collectedItems[9] = true;
				inventory.insert(10);
				return 10;
			}
		}
		else if (nextPos == 553)   //Key 1
		{
			key = true;
			if (!collectedItems[10])
			{
				collectedItems[10] = true;
				inventory.insert(11);
				return 11;
			}
		}
		//else if (nextPos == 352)   //Key 3
		//{
		//	inventory.insert(12);
		//	return 12;
		//}
		if (nextPos == 654)     //Heart 1
		{  
			if (!collectedItems[11]) {
				collectedItems[11] = true;
				inventory.insert(13);
				return 13;
			}
		}
		if (nextPos == 810)   //Heart 2
		{
			if (!collectedItems[12]) {
				collectedItems[12] = true;
				inventory.insert(14);
				return 14;
			}
		}
		if (nextPos == 506)    //100 coin 2
 		{
			
			if (!collectedItems[14])
			{
				collectedItems[14] = true;
				scoreCal = scoreCal + 100;
				score.setScore(scoreCal);
				inventory.insert(15);
				return 15;
			}
			
		}  
		if (nextPos == 867)    //100 coin 1 
		{
			if (!collectedItems[15])
			{
				collectedItems[15] = true;
				scoreCal = scoreCal + 100;
				score.setScore(scoreCal);
				inventory.insert(16);
				return 16;
			}
			
		}
		if (key2 == true || key == true) 
		{
			if (nextPos == 299)    //Lock 2
			{
				if (!collectedItems[16])
				{
					collectedItems[16] = true;
					
					inventory.insert(17);
					return 17;
				}

			}
		}
		if (key2 == true || key == true)
		{
			if (nextPos == 480)    //Lock 1
			{
				if (!collectedItems[17])
				{
					collectedItems[17] = true;

					inventory.insert(18);
					return 18;
				}
			}
		}
		if (nextPos == 405)    //Treasure
		{
			
			if (!collectedItems[18])
			{
				collectedItems[18] = true;
				scoreCal = scoreCal + 10000;
				score.setScore(scoreCal);
				inventory.insert(19);
				return 19;
			}
		}
		return 0;
	}
	
	void handleMove(Event event, Maze* maze, int* currentPos, int size, AVLTree& inventory, RenderWindow& window)
	{
		int nextPos = *currentPos; // Initialize with the current position
		bool moveValid = false;    // Flag to determine if a move is valid

		// Determine the potential next position based on the key pressed
		switch (event.key.code)
		{
		case Keyboard::Left:
			nextPos = *currentPos - 1; // Move left
			if (*currentPos % size != 0)
			{ // Check if not on the left edge
				moveValid = !maze[*currentPos].boundary[3] && !maze[nextPos].boundary[1];
			}
			break;
		case Keyboard::Right:
			nextPos = *currentPos + 1; // Move right
			if ((*currentPos + 1) % size != 0)
			{ // Check if not on the right edge
				moveValid = !maze[*currentPos].boundary[1] && !maze[nextPos].boundary[3];
			}
			break;
		case Keyboard::Up:
			nextPos = *currentPos - size; // Move up
			if (*currentPos >= size)
			{ // Check if not on the top edge
				moveValid = !maze[*currentPos].boundary[0] && !maze[nextPos].boundary[2];
			}
			break;
		case Keyboard::Down:
			nextPos = *currentPos + size; // Move down
			if (*currentPos < size * (size - 1))
			{ // Check if not on the bottom edge
				moveValid = !maze[*currentPos].boundary[2] && !maze[nextPos].boundary[0];
			}
			break;
		}

		// Update the current position if the move is valid
		if (moveValid)
		{
			*currentPos = nextPos;
		}
	}
};
//int Objects::scoreCal = 0;


