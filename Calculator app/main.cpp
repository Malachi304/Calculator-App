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

    void button(sf::Vector2f size) {
       
        shape.setSize(size);
        shape.setFillColor(sf::Color(100, 250, 50));

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

            Buttons button1;
            button1.button({ 300,75 }); 
          
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
                    //button constuctor 
                    // buttons(); 

                default:
                    break;
                }

                button1.draw(window);

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