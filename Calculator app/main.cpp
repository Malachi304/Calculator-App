#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <string>


using namespace std;



class Buttons {
public:

    //void Button();

    void button(sf::Vector2f size, sf::Vector2f position) {
       
        shape.setSize(size);
        shape.setFillColor(sf::Color(30,30,30));
        shape.setOutlineThickness(5); 
        shape.setOutlineColor(sf::Color(135,206,235));
        shape.setPosition(position);         

    }

    void setText(string str, sf::Vector2f position) {

        sf::Font font; 
        if (!font.loadFromFile("C:\Fonts")) {
            cout << "Font load error"; 
            return; 
        }

        text.setFont(font);
        text.setCharacterSize(10); 
        text.setFillColor(sf::Color(30,30,30)); 
        text.setPosition(position); 
    }


    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text); 
    }
    

    
private:

    sf::RectangleShape shape;
    sf::Text text; 
};

//user interface
class Display {

public:
    
    //calculator display
    void mainDisplay() {
        sf::RenderWindow window(sf::VideoMode(300, 425), "Calculator");

        // Set frame rate limit to 60 FPS
        window.setFramerateLimit(60); 

        //each button needs a 75x 
        Buttons button[13], util_button[5], text[11];

        //size of numbered buttons
        float x = 75;
        //minimum y position 
        float posY = 105;

        //main screen
        button[0].button({ 300,100 }, { 0.f, 0.f });
        //first collum
        button[1].button({ x,x }, { 0.f, posY });
        button[2].button({ x,x }, { 0.f, posY + 80 });
        button[3].button({ x,x }, { 0.f, posY + 160 });
        button[4].button({ x,x }, { 0.f, posY + 240 });
        //second collumn
        button[5].button({ x,x }, { 80.f, posY });
        button[6].button({ x,x }, { 80.f, posY + 80 });
        button[7].button({ x,x }, { 80.f, posY + 160 });
        button[8].button({ x,x }, { 80.f, posY + 240 });
        //third collumn
        button[9].button({ x,x }, { 160.f, posY });
        button[10].button({ x,x }, { 160.f, posY + 80 });
        button[11].button({ x,x }, { 160.f, posY + 160 });
        button[12].button({ x,x }, { 160.f, posY + 240 });

        //utilities
        util_button[0].button({ x,45 }, { 240.f, posY });
        util_button[1].button({ x,45 }, { 240.f, posY + 55 });
        util_button[2].button({ x,45 }, { 240.f, posY + 110 });
        util_button[3].button({ x,45 }, { 240.f, posY + 165 });
        util_button[4].button({ x,95 }, { 240.f, posY + 220 });
       


        // Enable anti-aliasing for the square
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8; 

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