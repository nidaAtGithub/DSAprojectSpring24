#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>
#include "maze.h"
#include "collison.h"
#include "inventory.h"
#include "shield.h"
#include "sword.h"
#include "reward.h"
#include "lock.h"
#include "key.h"
#include "score.h"

using namespace std;
using namespace sf;

class Game
{
    Shield* sh[4];// Initialize pointers to nullptr
    Sword* sw[3];// Initialize pointers to nullpt
    Reward* reward[8];

    Locks lock;
    Key key;
    Font font;
    Font f;
    Shield* shield[3];
    Key key2[2];
    Sword* sword[3];
    Text scoreDisplay;

    Score scoreObj;
    static int countClose;

public:
    Game() 
    {
        font.loadFromFile("Fonts/arial.ttf");
        f.loadFromFile("Fonts/arial.ttf");
        scoreDisplay.setFont(f);
        scoreDisplay.setCharacterSize(20);

        //currentPosRect.setFillColor(Color(0, 0, 0));  // Set fill color
        //currentPosRect.setSize(Vector2f(50, 50));  // Set size, adjust as needed
    }
    void start()
    {
        int currentPos = 0;
        Text title("Inventory", font, 20);
        title.setFillColor(Color::White);
        title.setPosition(20, 630);

        Text score("Score", font, 20);
        score.setFillColor(Color::White);
        score.setPosition(480, 630);

        RenderWindow window(VideoMode(660, 660), "LYBRINTH MAZE");
        Clock clock;
        Maze obj;
        Maze* maze = new Maze[obj.getLines() * obj.getLines()];
        window.setFramerateLimit(70);
        window.setVerticalSyncEnabled(true);

        int i = 30;    //Y coordinates
        int k = 0;     //X coordinates
        while (i < obj.getSize() * obj.getLines() + 30)
        {
            int j = 30;
            while (j < obj.getSize() * obj.getLines() + 30)
            {
                maze[k].y = i;       //Assign y coordinates
                maze[k].x = j;       //Assign x coordinates
                maze[k].size = obj.getSize();    //Setting the position too
                maze[k].pos = k;
                //cout << maze[i].pos << endl;

                j = j + obj.getSize();    //incrementing the columns
                k++;        //No of maze lines
            }
            i = i + obj.getSize();
        }
        AVLTree inventory;

        obj.makeMazeGrid(maze, maze->getLines());
        //Setting for the object tht move
        RectangleShape currentPosRect;
        currentPosRect.setFillColor(Color(0, 0, 0));
        currentPosRect.setSize(Vector2f(obj.getSize(), obj.getSize()));
        Objects call;

        //Shield
        sh[0] = new Shield("shield2.png", 113, 153);
        sh[1] = new Shield("shield2.png", 233, 310);
        sh[2] = new Shield("shield2.png", 374, 477);


        /*shield[1] = new Shield("shield2.png", 233, 310);
        shield[2] = new Shield("shield2.png", 374, 477);*/
        //Sword
        sw[0] = new Sword("sword1.png", 614, 100);
        sw[1] = new Sword("sword1.png", 114, 280);
        sw[2] = new Sword("sword1.png", 274, 540);
        //Rewards
        reward[0] = new Reward("treasure2.png", 334, 297);
        reward[1] = new Reward("live.png", 514, 440);
        reward[2] = new Reward("dollar.png", 30, 100);
        reward[3] = new Reward("dollar10.png", 72, 80);
        reward[4] = new Reward("coin100.png", 590, 590);  //100 dollar 
        reward[5] = new Reward("live.png", 40, 590);
        reward[6] = new Reward("dollar10.png", 300, 133);
        reward[7] = new Reward("coin100.png", 550, 340);  //100 dollar 
        //Lock
        lock.setPosition(37, 340);  // Set position if it changes dynamically
        lock.setPositionLine(38.f, 340.f);
        lock.setPositionLine2(45.f, 340.f);
        lock.setPositionLine3(40.f, 333.f);
        lock.setPositionCircle(41, 342.f);

        lock.setPosition2(617, 231);  // Set position if it changes dynamically
        lock.setPositionLine21(618.f, 232.f);
        lock.setPositionLine22(625.f, 232.f);
        lock.setPositionLine23(618.f, 223.f);
        lock.setPositionCircle2(621, 234.f);

        //Key
        key.setPosition11(145, 457);      // Set position if it changes dynamically
        key.setPosition12(149.f, 460.f);
        key.setPositionCircle1(137, 454);
        key.setPosition21(484.f, 257.f);
        key.setPosition22(489.f, 261.f);
        key.setPositionCircle2(477, 255);
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Space) 
                    {
                       // window.close();  // Closes the window when the spacebar is pressed
                        lastScreen();
                    }
                    else {
                        // Handle other movements
                        call.handleMove(event, maze, &currentPos, obj.getLines(), inventory, window);
                    }

                    break;
                }
            }

            //  Objects::checkAndHandleCollisions(currentPosRect, sh, sw);
            int liveScore = 0;
            window.clear(Color(128, 128, 128));
            int collision = call.checkCollision(currentPos, window);
            /* cout << collision << endl;*/
            if (collision == 1)
            {

                // //cout << "Shield draw\n";
                sh[0]->updatePositionWithCollide(114, 640);
                countClose++;
            }
            if (collision == 2)
            {
                //cout << "Check\n";
                sh[1]->updatePositionWithCollide(129, 640);
                countClose++;
            }

            if (collision == 3)
            {
                sh[2]->updatePositionWithCollide(144, 640);
                countClose++;
            }

            if (collision == 4)
            {
                sw[0]->updatePositionWithCollide(159, 640);
                countClose++;
            }
            if (collision == 5)
            {
                sw[1]->updatePositionWithCollide(174, 640);
                countClose++;
            }
            if (collision == 6)
            {
                sw[2]->updatePositionWithCollide(189, 640);
                countClose++;
            }
            if (collision == 7)
            {
                liveScore = scoreObj.getScore();
                // scoreDisplay("")
                scoreDisplay.setString(to_string(scoreObj.getScore()));
                scoreDisplay.setPosition(580, 628);


                reward[3]->updatePositionWithCollide(204, 640);
                countClose++;
            }
            if (collision == 8)
            {
                liveScore = scoreObj.getScore();

                scoreDisplay.setString(to_string(scoreObj.getScore()));
                scoreDisplay.setPosition(580, 628);


                reward[6]->updatePositionWithCollide(219, 640);
                countClose++;
            }
            if (collision == 9)
            {
                liveScore = scoreObj.getScore();

                scoreDisplay.setString(to_string(scoreObj.getScore()));
                scoreDisplay.setPosition(580, 628);


                reward[2]->updatePositionWithCollide(231, 640);
                countClose++;
            }
            if (collision == 10)
            {
                key.setPosition11(1450, 4507);      // Set position if it changes dynamically
                key.setPosition12(1490.f, 4600.f);
                key.setPositionCircle1(1370, 4504);
                countClose++;
            }
            if (collision == 12)
            {
                key.setPosition21(1450, 4507);      // Set position if it changes dynamically
                key.setPosition22(1490.f, 4600.f);
                key.setPositionCircle2(1370, 4504);
                countClose++;
            }

            if (collision == 13)
            {
                reward[1]->updatePositionWithCollide(246, 640);
                countClose++;
            }
            if (collision == 14)
            {
                reward[5]->updatePositionWithCollide(261, 640);
                countClose++;
            }
            if (collision == 15)
            {
                liveScore = scoreObj.getScore();

                scoreDisplay.setString(to_string(scoreObj.getScore()));
                scoreDisplay.setPosition(580, 628);


                reward[7]->updatePositionWithCollide(276, 640);
                countClose++;
            }
            if (collision == 16)
            {
                liveScore = scoreObj.getScore();

                scoreDisplay.setString(to_string(scoreObj.getScore()));
                scoreDisplay.setPosition(580, 628);


                reward[4]->updatePositionWithCollide(291, 640);
                countClose++;
            }
            if (collision == 17)
            {
                lock.setPosition(3700, 3400);  // Set position if it changes dynamically
                lock.setPositionLine(3800.f, 3400.f);
                lock.setPositionLine2(4500.f, 3400.f);
                lock.setPositionLine3(4000.f, 3330.f);
                lock.setPositionCircle(4100, 3420.f);
                countClose++;
            }
            if (collision == 18)
            {
                lock.setPosition(3700, 34000);  // Set position if it changes dynamically
                lock.setPositionLine(3800.f, 34000.f);
                lock.setPositionLine2(4500.f, 3400.f);
                lock.setPositionLine3(4000.f, 3330.f);
                lock.setPositionCircle(4100, 34200.f);
                countClose++;
            }
            if (collision == 19)
            {
                liveScore = scoreObj.getScore();

                scoreDisplay.setString(to_string(scoreObj.getScore()));
                scoreDisplay.setPosition(580, 628);


                reward[0]->updatePositionWithCollide(306, 640);
                countClose++;
            }

            window.draw(scoreDisplay);
            // window.draw(shield[0]->sprite);
             ////Shields
            for (int i = 0; i < 3; i++)
            {

                window.draw(sh[i]->sprite);

            }
            //Swords
            for (int i = 0; i < 3; i++)
            {
                window.draw(sw[i]->sprite);
            }
            //Reward
            for (int i = 0; i < 8; i++)
            {
                window.draw(reward[i]->sprite);
            }
            window.draw(lock.getRect());
            window.draw(lock.getLine());
            window.draw(lock.getLine2());
            window.draw(lock.getLine3());
            window.draw(lock.getCircle1());

            window.draw(lock.getRect2());
            window.draw(lock.getLine21());
            window.draw(lock.getLine22());
            window.draw(lock.getLine23());
            window.draw(lock.getCircle2());


            window.draw(key.getRect11());
            window.draw(key.getRect12());
            window.draw(key.getRect21());
            window.draw(key.getRect22());
            window.draw(key.getCircle1());
            window.draw(key.getCircle2());

            window.draw(title);
            window.draw(score);

            Objects object1;
            object1.drawDragon(window, clock);
            // object1.drawKey(window);

            for (int i = 0; i < obj.getLines() * obj.getLines(); i++)
            {
                maze[i].drawStructure(&window);

            }

            currentPosRect.setPosition(maze[currentPos].x, maze[currentPos].y);
            window.draw(currentPosRect);

            if (countClose == 18 || countClose == 17)
            {
                window.close();
            }
            window.display();
        }
	}
    void lastScreen()
    {
        srand(time(0));

        Clock clock;
        float timer = 0;
        RenderWindow window(VideoMode(800, 800), "Game won");

        Font font;
        font.loadFromFile("arial.ttf");

        Text finish("  You Won!   ", font, 100);
        finish.setFillColor(Color::Yellow);
        finish.setPosition(160, 310);

        //Adjust the window timer for transition
        while (window.isOpen() && timer < 2.0)
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
            }

            window.clear();
            window.draw(finish);
            window.display();
        }
    }

    
};

int Game::countClose = 0;

