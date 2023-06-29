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
            Buttons button0, button1, button2, button3, button4, button5, button6,
                button7, button8, button9, button10, button11, button12,
                button_del, button_div, button_mul, button_add, button_sub, button_ans;


            //main screen
            button0.button({ 300,100 }, {0.f, 0.f});
            //first collum
            button1.button({ 75,75 }, {0.f, 105.f});
            button2.button({ 75,75 }, {0.f, 185.f});
            button3.button({ 75,75 }, {0.f, 265.f});
            button4.button({ 75,75 }, {0.f, 345.f});
            //second collumn
            button5.button({ 75,75 }, {80.f,105.f});
            button6.button({ 75,75 }, {80.f, 185.f});
            button7.button({ 75,75 }, {80.f, 265.f});
            button8.button({ 75,75 }, {80.f, 345.f});
            //third collumn
            button9.button({ 75,75 }, {160.f, 105.f});
            button10.button({ 75,75 }, {160.f, 185.f});
            button11.button({ 75,75 }, {160.f, 265.f});
            button12.button({ 75,75 }, { 160.f, 345.f });

           //utilities
            int x_space = 5; 
            int y_space = 105.f;
            int max_y = 345.f; 

            button_del.button({ 75,45 }, {240.f, 105.f});
            button_div.button({ 75,45 }, { 240.f, 160.f });
            button_mul.button({ 75,45 }, { 240.f, 215.f });
            button_add.button({ 75,45 }, { 240.f, 270.f });
            button_sub.button({ 75,45 }, { 240.f, 325.f });
            button_ans.button({ 75,45 }, { 240.f, 380.f });

          
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
                button1.draw(window); 
                button2.draw(window);
                button3.draw(window); 
                button4.draw(window);
                button5.draw(window); 
                button6.draw(window);
                button7.draw(window); 
                button8.draw(window);
                button9.draw(window);
                button10.draw(window);
                button11.draw(window);
                button12.draw(window);
                button_del.draw(window); 
                button_div.draw(window);
                button_mul.draw(window);
                button_add.draw(window);
                button_sub.draw(window);
                button_ans.draw(window);


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