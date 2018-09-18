#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

class Shape {
	const std::string name;
	int position_X;
	int position_Y;
	float speed;
	const std::string color;

	std::vector<std::shared_ptr<sf::Shape>> shapes;

	public:
		void setPosition_X(int x) {
			position_X = x;
		}

		void setPosition_Y(int y) {
			position_Y = y;
		}
};

class Circle: public Shape {

};

class Rectangle: public Shape {

};



int main(int argc, char * argv[])
{
    // create a new window of size 400 by 400 pixels
    // top-left of the window is (0,0) and bottom-right is (w,h)
    const int wWidth = 400;
    const int wHeight = 400;
	//sf::Vector2f windowSize(400, 400);
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
	//sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "SFML works!");

    // let's make a shape that we will draw to the screen
    sf::CircleShape circle(50);             // create a circle shape with radius 50
    circle.setFillColor(sf::Color::Green);  // set the circle color to green
    circle.setPosition(300.0f, 300.0f);     // set the top-left position of the circle
    float circleMoveSpeed = 0.01f;          // we will use this to move the circle later

	std::vector<Shape> shapes;

	std::ifstream cin("config.txt");

	std::string token, color;
	int width, height;

	while (cin.good())
	{
		cin >> token;

		if (token == "Window")
		{
			cin >> width >> height;
			std::cout << "\dimension: " << width << "," << height;
			sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
		}
	}


	//struct myShape {
		//shared.ptr<sf::shape>
			//name
			//speed
	//};

	sf::Vector2f velocity;
	velocity.x = 1;
	velocity.y = 1;

    // let's load a font so we can display some text
    sf::Font arial;

    // attempt to load the font from a file
    if (!arial.loadFromFile("fonts/arial.ttf"))
    {
        // if we can't load the font, print an error to the error console and exit
        std::cerr << "Could not load font!\n";
        exit(-1);
    }

    // set up the text object that will be drawn to the screen
    sf::Text text("Sample Text", arial, 24);

    // position the top-left corner of the text so that the text aligns on the bottom
    // text character size is in pixels, so move the text up  from the bottom by its height
    text.setPosition(0, wWidth - (float)text.getCharacterSize());               

    // main loop - continues for each frame while window is open
    while (window.isOpen())
    {
        // event handling 
        sf::Event event;
        while (window.pollEvent(event))
        {
            // this event triggers when the window is closed
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

			

            // this event is triggered when a key is pressed
            if (event.type == sf::Event::KeyPressed)
            {
                // print the key that was pressed to the console
                std::cout << "Key pressed with code = " << event.key.code << "\n";

                // example, what happens when x is pressed
                if (event.key.code == sf::Keyboard::X)
                {
                    // reverse the direction of the circle on the screen
                    circleMoveSpeed *= -1.0f;
                }
            }
			
        }



        // basic animation - move the each frame if it's still in frame
        circle.setPosition(circle.getPosition().x - circleMoveSpeed, circle.getPosition().y - circleMoveSpeed);
        
		if (circle.getPosition().x <= 0 || circle.getPosition().y <= 0 || (circle.getPosition().x + circle.getLocalBounds().width >= wWidth) || (circle.getPosition().y + circle.getLocalBounds().height >= wHeight))
		{
			// reverse the direction of the circle on the screen
			circleMoveSpeed *= -1.0f;
		}
        // basic rendering function calls
        window.clear();         // clear the window of anything previously drawn
        window.draw(circle);    // draw the circle
        window.draw(text);      // draw the text
        window.display();       // call the window display function
    }

    return 0;
}