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
       // shape.setOutlineThickness(5); 
      //  shape.setOutlineColor(sf::Color(0, 0, 0));

        shape.setPosition(position); 
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }
private:

    sf::RectangleShape shape;
};

//user display class
class Display {

public:
    
    //calculator display
    void mainDisplay() {
        sf::RenderWindow window(sf::VideoMode(300, 425), "My Window");

        // Set frame rate limit to 60 FPS
        window.setFramerateLimit(60); 


        //window loop
        while (window.isOpen())
        {
            //each button needs a 75x 
            Buttons button0 ,button1,  button2, button3, button4, button5, button6, button7, button8, button9;
            button0.button({ 300,100 }, {0.f, 0.f});
            button1.button({ 75,75 }, {0.f, 105.f});
            button2.button({ 75,75 }, {0.f, 185.f});
            button3.button({ 75,75 }, {0.f, 265.f});
            button4.button({ 75,75 }, {0.f, 345.f});
            button5.button({ 75,75 }, {80.f,105.f});
            button6.button({ 75,75 }, {80.f, 185.f});
            button7.button({ 75,75 }, {80.f, 265.f});
            button8.button({ 75,75 }, {80.f, 345.f});
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

                //head
                button0.draw(window);
                //first collumn
                button1.draw(window); 
                button2.draw(window);
                button3.draw(window); 
                button4.draw(window);
                //second collumn
                button5.draw(window); 
                button6.draw(window);
                button7.draw(window); 
                button8.draw(window);
                //thirst collumn
                //button9.draw(window);

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