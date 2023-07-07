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


    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

    
private:

    sf::RectangleShape shape;
};


class Text {
public:


    void setText(string str,  sf::Vector2f position) {


        if (!font.loadFromFile("C:\\Fonts\\JAi.TTF")) {
            cout << "Font load error";
            return;
        }

        sf::Text text;

        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::White);
        text.setPosition(position);

        drawText = text;


    }

    void draw(sf::RenderWindow& window) {
          window.draw(drawText);
    }

private: 
    sf::Text drawText;
    sf::Font font;


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
        std::vector<Buttons> button(13), util_button(5);
        std::vector<Text> textBox(12);

        //main screen
        button[0].button({ 300,100 }, { 0.f, 0.f });
        
        //  textBox[1].setText("1", { (x/2) - 25,  posY });
        
        int count = 0; 
        float posY = 105.f, posX = 0.f, x = 75.f;

        //initalizing button size and position
        for (int i = 1; i < 13; i++) {

         
            button[i].button({ x,x }, { posX, posY });

            posY += 80;
            count++; 

            //every 4th button in a row is the is followed by a new row
            //this is true for collums also
            if (count % 4 == 0) {
                posX += 80;
                posY = 105;
            }

        }
        for (int i = 0; i < 5; i++) {

            //equal size button
            if (i == 4) {
                util_button[i].button({ x, 95 }, { 240.f, 325.f });
                
            }
            //arithmatic buttons
            else {

                util_button[i].button({ x,45 }, { 240, posY });
                posY += 55;

            }

        }

        // Enable anti-aliasing for the square
        //smooth edges
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8; 

        //window loop
        while (window.isOpen())
        {
            window.clear(); 

       
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
               

            }


            for (int i = 0; i < 13; i++) {
                button[i].draw(window);
            }
            
            for (int i = 0; i < 5; i++) {
                util_button[i].draw(window);
            }
            
            textBox[1].draw(window);


            window.display();


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