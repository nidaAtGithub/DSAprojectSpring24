#pragma once
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>


using namespace std;
using namespace sf;

class Key
{
	int x;
	int y;

	RectangleShape rect11;
	RectangleShape rect12;
	CircleShape circle1;

	RectangleShape rect21;
	RectangleShape rect22;
	CircleShape circle2;

public:
	Key()
	{
		rect11.setSize(Vector2f(12.f, 4.f));  // Example size
		rect11.setFillColor(Color::Yellow);

		rect12.setSize(Vector2f(4.f,8.f));  // Example size
		rect12.setFillColor(Color::Yellow);


		rect21.setSize(Vector2f(12.f, 4.f));  // Example size
		rect21.setFillColor(Color::Yellow);

		rect22.setSize(Vector2f(4.f, 8.f));  // Example size
		rect22.setFillColor(Color::Yellow);

		
		circle1.setRadius(5);
		circle1.setFillColor(Color::Yellow);

		circle2.setRadius(5);
		circle2.setFillColor(Color::Yellow);
	}

	// Update position when needed
	void setPosition11(int x, int y)
	{
		rect11.setPosition(static_cast<float>(x), static_cast<float>(y));
	}
	// Accessor to get the RectangleShape
	RectangleShape& getRect11()
	{
		return rect11;
	}
	void setPosition12(int x, int y)
	{
		rect12.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	RectangleShape& getRect12()
	{
		return rect12;
	}
	void setPosition21(int x, int y)
	{
		rect21.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	RectangleShape& getRect21()
	{
		return rect21;
	}
	void setPosition22(int x, int y)
	{
		rect22.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	RectangleShape& getRect22()
	{
		return rect22;
	}
	void setPositionCircle2(int x, int y)
	{
		circle2.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	void setPositionCircle1(int x, int y)
	{
		circle1.setPosition(static_cast<float>(x), static_cast<float>(y));

	}
	CircleShape& getCircle1()
	{
		return circle1;
	}

	CircleShape& getCircle2()
	{
		return circle2;
	}
};