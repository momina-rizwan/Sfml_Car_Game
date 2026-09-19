#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

int main()
{
    Vector2f velocity1(0, 0.1f);
    RenderWindow wndo(VideoMode(840, 650), "Collecting Ball Game");
    CircleShape circle1(20), circle2(20), circle3(20), circle4(20); 

    circle1.setPosition(Vector2f(200, 0));
    circle2.setPosition(Vector2f(605, -250));
    circle3.setPosition(Vector2f(345, -180));
    circle4.setPosition(Vector2f(480, -100));
   
    circle1.setFillColor(Color::Green);
    circle2.setFillColor(Color::Green);
    circle3.setFillColor(Color::Green);
    circle4.setFillColor(Color::Green);

    Event e;
    Texture texture, texture1, texture2;
    texture.loadFromFile("pr.png");
    texture1.loadFromFile("pr3.png");
    texture2.loadFromFile("END.png");
    Sprite sprite, sprite1, sprite2;

    sprite.setTexture(texture);
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    sprite1.rotate(90);
    sprite1.scale(Vector2f(0.2, 0.2));
    sprite1.setPosition(Vector2f(250, 500));
    float speed = 0.4f;
    Vector2f velocity(0, 0);

    RectangleShape collectedBox(Vector2f(50, 50));
    collectedBox.setFillColor(Color::Black);

    Font font;
    font.loadFromFile("Hibo.otf"); 

    Text countText;
    countText.setFont(font);
    countText.setCharacterSize(20);
    countText.setFillColor(Color::White);
    countText.setPosition(10, 10); 

    int ballsCollected = 0;

    bool gameOver = false;

    while (wndo.isOpen())
    {
        while (wndo.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                wndo.close();
            }
            if (!gameOver)
            {
                if (e.type == Event::KeyPressed)
                {
                    if (Keyboard::isKeyPressed(Keyboard::W))
                    {
                        velocity.y = -speed;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::A))
                    {
                        velocity.x = -speed;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::D))
                    {
                        velocity.x = speed;
                    }
                    if (Keyboard::isKeyPressed(Keyboard::S))
                    {
                        velocity.y = speed;
                    }
                }
                else if (e.type == Event::KeyReleased)
                {
                    velocity.x = 0;
                    velocity.y = 0;
                }
            }
        }

        
        circle1.move(velocity1);
        circle2.move(velocity1);
        circle3.move(velocity1);
        circle4.move(velocity1);

        
        sprite1.move(velocity);
        if (sprite1.getPosition().x < 220)
            sprite1.setPosition(220, sprite1.getPosition().y);
        if (sprite1.getPosition().x > wndo.getSize().x - sprite1.getGlobalBounds().width)
            sprite1.setPosition(wndo.getSize().x - sprite1.getGlobalBounds().width, sprite1.getPosition().y);
        if (sprite1.getPosition().y < 0)
            sprite1.setPosition(sprite1.getPosition().x, 0);
        if (sprite1.getPosition().y > wndo.getSize().y - sprite1.getGlobalBounds().height)
            sprite1.setPosition(sprite1.getPosition().x, wndo.getSize().y - sprite1.getGlobalBounds().height);

       
        if (!gameOver)
        {
            if (circle1.getGlobalBounds().intersects(sprite1.getGlobalBounds()))
            {
                ballsCollected++;
                circle1.setPosition(Vector2f(200, -50));
            }

            if (circle2.getGlobalBounds().intersects(sprite1.getGlobalBounds()))
            {
                ballsCollected++;
                circle2.setPosition(Vector2f(605, -300));
            }

            if (circle3.getGlobalBounds().intersects(sprite1.getGlobalBounds()))
            {
                ballsCollected++;
                circle3.setPosition(Vector2f(345, -170));
            }
            if (circle4.getGlobalBounds().intersects(sprite1.getGlobalBounds()))
            {
                ballsCollected++;
                circle4.setPosition(Vector2f(480, -100));
            }

            
            if (circle1.getPosition().y > wndo.getSize().y || circle2.getPosition().y > wndo.getSize().y || circle3.getPosition().y > wndo.getSize().y || circle4.getPosition().y > wndo.getSize().y)
            {
                cout << "Game Over! Balls missed. You collected " << ballsCollected << " balls." << endl;
                gameOver = true;
            }
        }

        
        countText.setString(" " + to_string(ballsCollected));

        
        wndo.clear();
        wndo.draw(sprite);
        sprite1.move(velocity);
        wndo.draw(sprite1);
        wndo.draw(circle1);
        wndo.draw(circle2);
        wndo.draw(circle3);
        wndo.draw(circle4);
        collectedBox.setPosition(Vector2f(0, 0));
        wndo.draw(collectedBox);
        wndo.draw(countText); 
        if (gameOver)
        {
            wndo.draw(sprite2);
        }
        wndo.display();
    }

    return 0;
}
