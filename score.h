#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;
using namespace sf;
class Score
{
	static int totalscore;
	const int size = 4;
public:
	Score()
	{
		totalscore = 0;
	}
	void setScore(static int score)
	{
		this->totalscore = score;
	}
	static int getScore()
	{
		return totalscore;
	}
	void createFile(RenderWindow& window)
	{
		

		ifstream inputfile("HighScore.txt");
		int score[5] = { 0 };;
		string title = "High Scores\n";
		if (inputfile.is_open())
		{
			//for (int i = 0; i < 5 && file >> score[i]; ++i);
			//This condition will check wether to read data or not
			int i = 0;
			while (i < size)
			{
				if (inputfile >> score[i])
				{
				}
				else
				{
					break;
				}
				i++;
			}
			inputfile.close();
			Font font;
			font.loadFromFile("Fonts/arial.ttf");
			Text highScore;
			highScore.setFont(font);
			highScore.setCharacterSize(40);
			highScore.setFillColor(Color::Yellow);
			highScore.setPosition(320, 100);

			srand(time(0));

			Clock clock;
			float timer = 0;
			//I use tie so when the 4 seconds will pass the high screen will automatically close
			while (window.isOpen() && timer < 4.0)
			{
				Event event;
				//This will calculate time
				float time = clock.getElapsedTime().asSeconds();
				clock.restart();
				timer += time;
				while (window.pollEvent(event))
				{

					if (event.type == Event::Closed) // Close button clicked
					{
						window.close();
					}
					/*if (Keyboard::isKeyPressed(Keyboard::Escape))
					{
						window.close();
					}*/
					//Display score on screen
					for (int i = 0; i < size; ++i)
					{
						title = title + to_string(i + 1) + "-   " + to_string(score[i]) + "\n";
					}
					highScore.setString(title);
				}

				// Draw the text on the window
				window.clear(Color::Black);
				window.draw(highScore);
				window.display();

			}
			return;
			//window.close();
			/*cout << "Scores read from file: ";
			for (int i = 0; i < 5; ++i)
			{
				cout << score[i] << " " << endl;
			}			*/
			bool scoreCheck = false;
			//this is here i am checking if current scoe is greater tahn the score in file
			for (int i = 0; i < size; ++i)
			{
				//This condition will check if the totalScore is greater thn the score in array if greater that will set in the first inde
				//And then the rest will store accordingly
				if (totalscore > score[i])
				{
					for (int j = size - 1; j > i; --j)
					{

						score[j] = score[j - 1];
					}
					//This will insert at current index
					score[i] = totalscore;
					scoreCheck = true;
					break;
				}
			}
			//This will check for the size and scoreChekc is true or false 
			if (scoreCheck == false && size > 0)
			{
				score[size - 1] = totalscore;
			}
			//Opening file for writing
			ofstream outputfile("HighScore.txt");

			if (!outputfile.is_open())
			{

				cout << "Unable to open file for writing " << endl;
			}
			else
			{

				for (int i = 0; i < size; ++i)
				{
					outputfile << score[i] << endl;
				}

				outputfile.close();
			}
		}
		else
		{
			cout << "Unable to open file reading " << endl;
		}
	}
};
int Score::totalscore = 0;



