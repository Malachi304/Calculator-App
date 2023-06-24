#include <iostream>
#include "sfml/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <string>


using namespace std;


//user prompt for calculations
class Display {

public:
    
    //calculator display
    void mainDisplay() {
        window.create(sf::VideoMode(300, 400), "My window"); 

        //window loop
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            while (window.pollEvent(event))
            {

             //   window.clear(sf::Color::Black);


                //switch case check two possible events
                switch (event.type) {
                    // "close requested" event: we close the window
                case sf::Event::Closed:
                    window.close();
                    break;
                    //case for button push(left mouse click)
                case (sf::Event::MouseButtonPressed):
                    //button constuctor 
                    // buttons(); 

                default:
                    break;


                }
               // window.display();
                return; 

            }
        }
    }

private: 
    sf::RenderWindow window;
    sf::Event event;

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