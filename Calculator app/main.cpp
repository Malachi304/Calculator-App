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

        //each button needs a 75x 
        Buttons button[13], util_button[5];

        //main screen
        button[0].button({ 300,100 }, { 0.f, 0.f });
        //first collum
        button[1].button({ 75,75 }, { 0.f, 105.f });
        button[2].button({ 75,75 }, { 0.f, 185.f });
        button[3].button({ 75,75 }, { 0.f, 265.f });
        button[4].button({ 75,75 }, { 0.f, 345.f });
        //second collumn
        button[5].button({ 75,75 }, { 80.f,105.f });
        button[6].button({ 75,75 }, { 80.f, 185.f });
        button[7].button({ 75,75 }, { 80.f, 265.f });
        button[8].button({ 75,75 }, { 80.f, 345.f });
        //third collumn
        button[9].button({ 75,75 }, { 160.f, 105.f });
        button[10].button({ 75,75 }, { 160.f, 185.f });
        button[11].button({ 75,75 }, { 160.f, 265.f });
        button[12].button({ 75,75 }, { 160.f, 345.f });

        util_button[0].button({ 75,45 }, { 240.f, 105.f });
        util_button[1].button({ 75,45 }, { 240.f, 160.f });
        util_button[2].button({ 75,45 }, { 240.f, 215.f });
        util_button[3].button({ 75,45 }, { 240.f, 270.f });
        util_button[4].button({ 75,95 }, { 240.f, 325.f });



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

                // ButtonDisplay(window);

                switch (event.type) {

                case sf::Event::Closed:
                    window.close();
                    break;

                case (sf::Event::MouseButtonPressed):
               

                default:
                    break;
                }

                
                for (int i = 0; i < 13; i++) {
                    button[i].draw(window); 
            }
                for (int i = 0; i < 5; i++) {
                    util_button[i].draw(window);
                }
               


                window.display();

            }

        }
    }

private: 
    sf::Event event;

};


//Mathematical procedures
class claculator {

    
    void operation() {

    }
};

int main()
{
    //call display constructor
    Display display; 
    display.mainDisplay(); 


   

    return 0;
}