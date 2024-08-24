#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;
using namespace sf;


class Maze
{
public:
    const int noOfLines = 30;
    const int cellSize = 20;
    float size = 20.f;
    float thickness = 1.f;
	int x; 
	int y;
    int pos;
    bool boundary[4] = { true,true,true,true };
    bool visited;
    bool hasDragon = false;
    RectangleShape rect;
    bool hasShield;      // Array to indicate if a cell has a shield
    bool hasSword;
    int* shieldPositions = NULL; // Array to store shield positions
    int* swordPositions = NULL;;  // Array to store sword positions

	Maze()
	{
		x = 0;
		y = 0;
        visited = false;
	}
	Maze(int x, int y)
	{
		this->x = x;
		this->y = y;
        visited = false;
	}
    int getLines()
    {
        return noOfLines;
    }
    int getSize()
    {
        return cellSize;
    }
    Vector2f getPosition(int index)
    {
        // Calculate the x, y position of the top-left corner of the cell
        int col = index % noOfLines;  // Column number
        int row = index / noOfLines;  // Row number
        float xPos = col * size;      // x position in pixels
        float yPos = row * size;      // y position in pixels

        return Vector2f(xPos, yPos);
    }
    void drawStructure(RenderWindow* window)
    {
        srand(time(0));
        //Top
        if (boundary[0])
        {
            rect.setSize(Vector2f(size, thickness));
            rect.setPosition(x, y);
            window->draw(rect);
        }
        //// right
        if (boundary[1])
        {
            rect.setSize(Vector2f(thickness, size));
            rect.setPosition(x + size, y);
            window->draw(rect);
        }
        // bottom
        if (boundary[2])
        {
            rect.setSize(Vector2f(size + thickness, thickness));
            rect.setPosition(x, y + size);
            window->draw(rect);
        } 
        // left
        if (boundary[3])
        {
            rect.setSize(Vector2f(thickness, size));
            rect.setPosition(x, y);
            window->draw(rect);
        }
    }

    void resetMaze(Maze* maze, int size)
    {
        for (int i = 0; i < size * size; i++)
        {
            maze[i].boundary[0] = true;  // top
            maze[i].boundary[1] = true;  // right
            maze[i].boundary[2] = true;  // bottom
            maze[i].boundary[3] = true;  // left
            maze[i].visited = false;
        }

        // Calculate middle index for left and right sides
        //To make exits 
        int middleIndexLeft = (size / 2) * size; 
        int middleIndexRight = (size / 3) * size + (size - 1); 

        // Set exit at the middle of the left side
        maze[middleIndexLeft].boundary[3] = false; // No left wall for the middle-left cell

        // Set exit at the middle of the right side
        maze[middleIndexRight].boundary[1] = false; // No right wall for the middle-right cell
    }

    void makeMazeGrid(Maze* mazeLayout, int dimension)
    {
        resetMaze(mazeLayout, dimension); // Assume this resets the maze
        stack<Maze> track;
        mazeLayout[0].visited = true;
        track.push(mazeLayout[0]);

        while (!track.empty())
        {
            Maze currentCell = track.top();
            track.pop();
            int currentIndex = currentCell.pos;
            int adjacent[4];
            int availneigh = 0;

            // Identify adjacent cells
            if (currentIndex % dimension != 0 && !mazeLayout[currentIndex - 1].visited)
            {
                adjacent[availneigh++] = currentIndex - 1;
            }
            if ((currentIndex + 1) % dimension != 0 && !mazeLayout[currentIndex + 1].visited)
            {
                adjacent[availneigh++] = currentIndex + 1;
            }
            if (currentIndex + dimension < dimension * dimension && !mazeLayout[currentIndex + dimension].visited)
            {
                adjacent[availneigh++] = currentIndex + dimension;
            }
            if (currentIndex - dimension >= 0 && !mazeLayout[currentIndex - dimension].visited)
            {
                adjacent[availneigh++] = currentIndex - dimension;
            }

            // If there are unvisited neighbours, choose one at random
            if (availneigh > 0)
            {
                int chosenIndex = adjacent[rand() % availneigh];

                track.push(currentCell);
                
                Maze* currentMazeCell = &mazeLayout[currentIndex];
                Maze* chosenMazeCell = &mazeLayout[chosenIndex];

               
                if (currentIndex - dimension == chosenIndex)
                {
                    currentMazeCell->boundary[0] = false;
                    chosenMazeCell->boundary[2] = false;
                }
                else if (currentIndex + 1 == chosenIndex)
                {
                    currentMazeCell->boundary[1] = false;
                    chosenMazeCell->boundary[3] = false;
                }
                else if (currentIndex + dimension == chosenIndex)
                {
                    currentMazeCell->boundary[2] = false;
                    chosenMazeCell->boundary[0] = false;
                }
                else if (currentIndex - 1 == chosenIndex)
                {
                    currentMazeCell->boundary[3] = false;
                    chosenMazeCell->boundary[1] = false;
                }
                mazeLayout[chosenIndex].visited = true;
                track.push(mazeLayout[chosenIndex]);
            }
        }
    }

  
};



