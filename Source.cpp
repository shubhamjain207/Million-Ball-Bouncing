#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color().Red);
    shape.setPosition(1280/2, 720/2);
    float posX = 1280/2, posY = 720/2;
    float val = 0.1f;
    float val1 = 0.1f;
    float val3 = 0.1f;

    bool flag = false;

    float distanceTraveled = 0.f;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);

        if (posY + 20.f > 720) {
            val = -0.1f;
            flag = true;
        }

        if (posY < 600 && flag) {
            val = 0.1f;
        }

        if (flag) {
            val -= 0.00001f * -1;
        }

        posY+=val;

        shape.setPosition(posX, posY);
        window.display();
    }

    return 0;
}