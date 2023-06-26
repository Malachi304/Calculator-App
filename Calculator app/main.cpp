#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <string>


using namespace std;

//user display class
class Display {

public:
    
    //calculator display
    void mainDisplay() {
        sf::RenderWindow window(sf::VideoMode(300, 450), "My Window");

        //window loop
        while (window.isOpen())
        {

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

                ButtonDisplay(window);
                window.display();


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
               // return; 
            }

        }
    }

private: 
   // sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
    sf::Event event;
    
    void ButtonDisplay(sf::RenderWindow& window) {

        ////////////////////////////
        //
        // Function for Button diplay ontop of calculator display
        // Called inside display function to show buttons 
        //
        ////////////////////////////

        //main text box
        sf::RectangleShape rectangle(sf::Vector2f(100, 50));
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(100, 100);
        window.draw(rectangle);
       // window.draw(rec1);

       
    }
};


//SFML interface for calculator
class buttons {
public:


private:


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