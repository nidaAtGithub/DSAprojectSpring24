#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>


using namespace std;
using namespace sf;

class Locks
{
	int x;
	int y;

	RectangleShape rect;
	RectangleShape line1;
	RectangleShape line2;
	RectangleShape line3; 
	CircleShape circle;
	
	RectangleShape rect2;
	RectangleShape line21;
	RectangleShape line22;
	RectangleShape line23;
	CircleShape circle2;

public:
	Locks()
	{
		rect.setSize(Vector2f(11.f, 11.f));  // Example size
		rect.setFillColor(Color::Yellow);

		line1.setSize(Vector2f(7.f, 2.f));  // Example size
		line1.setFillColor(Color::Yellow);
		line1.rotate(-90);

		line2.setSize(Vector2f(7.f, 2.f));  // Example size
		line2.setFillColor(Color::Yellow);
		line2.rotate(-90);

		line3.setSize(Vector2f(7.f, 2.f));  // Example size
		line3.setFillColor(Color::Yellow);
		line3.rotate(0);

		circle.setRadius(2);
		circle.setFillColor(Color::Black);

		rect2.setSize(Vector2f(11.f, 11.f));  // Example size
		rect2.setFillColor(Color::Yellow);

		line21.setSize(Vector2f(7.f, 2.f));  // Example size
		line21.setFillColor(Color::Yellow);
		line21.rotate(-90);

		line22.setSize(Vector2f(9.f, 2.f));  // Example size
		line22.setFillColor(Color::Yellow);
		line22.rotate(-90);

		line23.setSize(Vector2f(7.f, 2.f));  // Example size
		line23.setFillColor(Color::Yellow);
		line23.rotate(0);

		circle2.setRadius(2);
		circle2.setFillColor(Color::Black);
	}

	// Update position when needed
	void setPosition(int x, int y)
	{
		rect.setPosition(static_cast<float>(x), static_cast<float>(y));
	}
	// Accessor to get the RectangleShape
	RectangleShape& getRect()
	{
		return rect;
	}
	void setPositionLine(int x, int y)
	{
		line1.setPosition(static_cast<float>(x), static_cast<float>(y));
		
	}
	void setPositionLine2(int x, int y)
	{
		line2.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	void setPositionLine3(int x, int y)
	{
		line3.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	void setPositionCircle(int x, int y)
	{
		circle.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	RectangleShape& getLine()
	{
		return line1;
	}
	RectangleShape& getLine2()
	{
		return line2;
	}
	RectangleShape& getLine3()
	{
		return line3;
	}
	CircleShape& getCircle1()
	{
		return circle;
	}




	void setPosition2(int x, int y)
	{
		rect2.setPosition(static_cast<float>(x), static_cast<float>(y));
	}
	// Accessor to get the RectangleShape
	RectangleShape& getRect2()
	{
		return rect2;
	}
	void setPositionLine21(int x, int y)
	{
		line21.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	void setPositionLine22(int x, int y)
	{
		line22.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	void setPositionLine23(int x, int y)
	{
		line23.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	void setPositionCircle2(int x, int y)
	{
		circle2.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	RectangleShape& getLine21()
	{
		return line21;
	}
	RectangleShape& getLine22()
	{
		return line22;
	}
	RectangleShape& getLine23()
	{
		return line23;
	}
	CircleShape& getCircle2()
	{
		return circle2;
	}
};