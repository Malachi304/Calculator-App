#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <string>


using namespace std;


//SFML interface for calculator
class Buttons {
public:

    //void Button();

    void button(sf::Vector2f size, sf::Vector2f position) {
       
        shape.setSize(size);
        shape.setFillColor(sf::Color::White);
        shape.setOutlineThickness(5); 
        shape.setOutlineColor(sf::Color(0, 0, 0));

        shape.setPosition(position); 
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
private:

    sf::RectangleShape shape;
    sf::Vector2f size;
};

//user display class
class Display {

public:
    
    //calculator display
    void mainDisplay() {
        sf::RenderWindow window(sf::VideoMode(300, 450), "My Window");

        // Set frame rate limit to 60 FPS
        window.setFramerateLimit(60); 


        //window loop
        while (window.isOpen())
        {

            Buttons button0 ,button1,  button2, button3, button4, button5, button6, button7, button8, button9;
            button0.button({ 300,75 }, {0.f, 0.f});
            button1.button({ 50,50 }, {});
            //button2.button({ 50,50 }, {});
            //button3.button({ 50,50 }, {});
            //button4.button({ 50,50 }, {});
            //button5.button({ 50,50 }, {});
            //button6.button({ 50,50 }, {});
            //button7.button({ 50,50 }, {});
            //button8.button({ 50,50 }, {});
           // button9.button({ 50,50 }, {});

          
            // check all the window's events that 
            //were triggered since the last iteration of the loop
            while (window.pollEvent(event))
            {

                ///////////////////////////////////////
                // 
                //switch case check two possible events
                //
                // 1.) "close requested" event: we close the window
                //
                // 2.) Case for button push(left mouse click)
                //
                ///////////////////////////////////////

                // ButtonDisplay(window);

                switch (event.type) {

                case sf::Event::Closed:
                    window.close();
                    break;

                case (sf::Event::MouseButtonPressed):
               

                default:
                    break;
                }

                button0.draw(window);

                window.display();

            }

        }
    }

private: 
    sf::Event event;

};


//Mathematical procedures
class claculator {

};

int main()
{
    //call display constructor
    Display display; 
    display.mainDisplay(); 


   

    return 0;
}