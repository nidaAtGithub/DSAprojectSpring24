#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "game.h"
#include "score.h"
class Menu
{
private:
    int check;
    Game g;
    //instruction function
    //For font
    Font font;
    Score score;
   
public:
    //add menu attributes here
    //Music m;
    Menu()
    {
        //Menu screen
        //Load text from file
        font.loadFromFile("Fonts/arial.ttf");
      /*  m.openFromFile("backgroundMusic.ogg");
        m.play();*/

    }

    void display_menu()
    {

        //display menu screen here
        // add functionality of all the menu options here

        srand(time(0));

        Clock clock;
        float timer = 0;
        RenderWindow window(VideoMode(800, 800), "Menu Screen");

        //Menu
        Text title("Lybrinth EXplorer", font, 90);
        title.setFillColor(Color::Cyan);
        title.setPosition(70, 10);
        title.setStyle(Text::Bold | Text::Underlined);

        Text titleText("Menu", font, 70);
        titleText.setFillColor(Color::Cyan);
        titleText.setPosition(300, 110);
       
        //Menu option 1
        Text option1("1.Start a New Game", font, 40);
        option1.setFillColor(Color::White);
        option1.setPosition(250, 250);

        //Menu option 2
        Text option2("2.High Score", font, 40);
        option2.setFillColor(Color::White);
        option2.setPosition(250, 350);

        //Option 3
        Text option3("3.Help", font, 40);
        option3.setFillColor(Color::White);
        option3.setPosition(250, 450);

        //Option4
        Text option4("4.Exit", font, 40);
        option4.setFillColor(Color::White);
        option4.setPosition(250, 550);

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
                if (event.key.code == Keyboard::Num1)
                {
                    window.close(); // Close the menu screen and go to main menu
                   
                    // Create a new window for the main game screen
                    RenderWindow mainGameWindow(VideoMode(660, 660), "Game Screen");
                    // mainMenu(mainGameWindow);  //Calling the main function
                    g.start();
                }
                if (Keyboard::isKeyPressed(Keyboard::Num2))
                {
                    RenderWindow scoreWindow(VideoMode(800, 600), "High score");
                    score.createFile(scoreWindow);
                    // window.close();
                     // RenderWindow instructionMenu(VideoMode(800, 600), "Instruction Screen");
                     //instructionFunc();
                }
                if (Keyboard::isKeyPressed(Keyboard::Num3))
                {
                    window.close();
                    // RenderWindow instructionMenu(VideoMode(800, 600), "Instruction Screen");
                    helpFunc();
                }
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    window.close();
                    // RenderWindow instructionMenu(VideoMode(800, 600), "Instruction Screen");
                   // instructionFunc();


                }
            }

            window.clear();

            window.draw(title);
            window.draw(titleText);
            window.draw(option1);
            window.draw(option2);
            window.draw(option3);
            window.draw(option4);
            //objectB.drawContent(window);

            window.display();
        }

    }
    //// add functionality of all the menu options here
    //void mainMenu(RenderWindow& mainGameWindow)
    //{
    //    //Man menu
    //    Text titleText("Main Menu", font, 80);
    //    titleText.setFillColor(Color::Cyan);
    //    titleText.setPosition(250, 30);
    //    titleText.setStyle(Text::Bold | Text::Underlined);
    //    //Level 1
    //    Text level1("1.Level 1", font, 40);
    //    level1.setFillColor(Color::White);
    //    level1.setPosition(250, 200);

    //    //Level 2
    //    Text level2("1.Level 2", font, 40);
    //    level2.setFillColor(Color::White);
    //    level2.setPosition(250, 300);

    //    //Level 3
    //    Text level3("1.Level 3", font, 40);
    //    level3.setFillColor(Color::White);
    //    level3.setPosition(250, 400);

    //    while (mainGameWindow.isOpen())
    //    {
    //        Event event;

    //        while (mainGameWindow.pollEvent(event))
    //        {
    //            if (event.type == Event::Closed) // Close button clicked
    //            {
    //                mainGameWindow.close();
    //            }
    //            if (Keyboard::isKeyPressed(Keyboard::Num1))
    //            {
    //                mainGameWindow.close();
    //                g.start();

    //            }
    //            /* if (Keyboard::isKeyPressed(Keyboard::Num2))
    //             {
    //                 mainGameWindow.close();
    //                 g.start_game2();

    //             }
    //             if (Keyboard::isKeyPressed(Keyboard::Num3))
    //             {
    //                 mainGameWindow.close();
    //                 g.start_game3();

    //             }*/
    //            if (Keyboard::isKeyPressed(Keyboard::Space))
    //            {
    //                mainGameWindow.close();
    //                display_menu();

    //            }

    //            // Handle other events and gameplay logic for the game screen...
    //        }
    //        mainGameWindow.clear();
    //        mainGameWindow.draw(titleText);
    //        mainGameWindow.draw(level1);
    //        mainGameWindow.draw(level2);
    //        mainGameWindow.draw(level3);
    //        mainGameWindow.display();
    //        // Update and render the game screen...
    //    }
    //}

    void helpFunc()
    {
        RenderWindow window(VideoMode(800, 600), "Instruction screen");
        /* Clock clock;
         float timer = 0;*/

        Text titleText("Help", font, 80);
        titleText.setFillColor(Color::Cyan);
        titleText.setPosition(220, 50);
        titleText.setStyle(Text::Bold | Text::Underlined);

        // Menu option 1;
        Text option1("1.To start the game press 1 on menu menu screen.", font, 20);
        option1.setFillColor(Color::White);
        option1.setPosition(150, 200);

        //Menu option 2
        Text option2("2.To move to next first finish the level.", font, 20);
        option2.setFillColor(Color::White);
        option2.setPosition(150, 270);

        Text option3("3.Level will finish when you will collect all awards.", font, 20);
        option3.setFillColor(Color::White);
        option3.setPosition(150, 340);

        Text option4("4.Each award will give you different adavanatge.", font, 20);
        option4.setFillColor(Color::White);
        option4.setPosition(150, 410);

        Text option5("5.If you want to Quit press space.", font, 20);
        option5.setFillColor(Color::White);
        option5.setPosition(150, 480);

        Text option6("6.Press space to go back to menu", font, 20);
        option6.setFillColor(Color::White);
        option6.setPosition(150, 550);
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Space))
                {
                    window.close();
                    display_menu();

                }

            }

            window.clear();
            window.draw(titleText);
            window.draw(option1);
            window.draw(option2);
            window.draw(option3);
            window.draw(option4);
            window.draw(option5);
            window.draw(option6);

            window.display();
        }
    }

};



