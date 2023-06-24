#include <iostream>
#include "sfml/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <string>


using namespace std;

//user display class
class Display {

public:
    
    //calculator display
    void mainDisplay() {
        window.create(sf::VideoMode(300, 400), "My window"); 

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