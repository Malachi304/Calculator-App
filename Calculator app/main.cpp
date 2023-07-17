#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <string>


using namespace std;

class Buttons {
public:


    /*

    void setShapes(std::vector<sf::RectangleShape>& shapes) {
        shapesRef = &shapes;
    }
    */
    Buttons() {
    };

    void button(sf::Vector2f size, sf::Vector2f position) {
       
        shape.setSize(size);
        shape.setFillColor(sf::Color(30,30,30));
        shape.setOutlineThickness(5); 
        shape.setOutlineColor(sf::Color(48,0,48));
        shape.setPosition(position);      

    }

    //get position of button
    sf::Vector2f getPosition() {
        return shape.getPosition(); 
    }

    sf::FloatRect getGlobalBounds() {
        return shape.getGlobalBounds(); 
    }

    bool contains(const sf::FloatRect& rect, const sf::Vector2f& position) {
        return rect.contains(position);
    }
    void button_press(int index) {

        if (index == 1) {
            cout << "1";
            
        }
        else if(index == 2) {
            cout << "2";
        }
        else
            cout << "invalid"; 
    }

    /*
    void button_press(sf::Vector2f& position) {
        // Access the shapes vector here and perform necessary checks
        for (auto& shape : *shapesRef) {

            sf::FloatRect shapeBounds = shape.getGlobalBounds();

            // Perform shape position checks
            if (shapeBounds.contains(position))
            {
                // Clicked position is within the bounds of the current shape
                // Perform the desired action for this shape
            }
        }
    }
    */
    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

   
private:

    sf::RectangleShape shape;
};


class Text {
public:


    void setText(int num,  sf::Vector2f position) {


        if (!font.loadFromFile("C:\\Fonts\\JAi.TTF")) {
            cout << "Font load error";
            return;
        }

        sf::Text text;

        string str; 

        if (num == 10) {
            str = { "" };
        }
        else if (num == 11) {
            str = { "0" };
        }
        else if (num == 12) {
            str = { "" }; 
        }
        else {
             str = std::to_string(num); // Convert integer back to string
        }

        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::White);
        text.setPosition(position);

        drawText = text;


    }
    void setText_util(int num, sf::Vector2f position) {
    
        if (!font.loadFromFile("C:\\Fonts\\JAi.TTF")) {
            cout << "Font load error";
            return;
        }

        sf::Text text;

        string str;


        switch (num) {
        case 0:
            str = { "÷" }; 
            break; 
        case 1:
            str = { "X" };
            break;
        case 2:
            str = { "-" };
            break;
        case 3:
            str = { "+" };
            break;
        case 4:
            str = { "=" };
            break;

        }


        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(25);
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
        std::vector<Text> numTxt(13), util_Txt(5);

        //main screen
        button[0].button({ 300,100 }, { 0.f, 0.f });

        float posY = 105.f, posX = 0.f, x = 75.f;
        //initalizing button size and position
        for (int i = 1; i < 13; i++) {

            button[i].button({ x,x }, { posX, posY });

            if (i < 13) {
                numTxt[i].setText(i, {posX,  posY });
            }

            posX += 80;

            //every 3th number button in a row is the is followed by a new row
            //this is true for collums also
            if (i % 3 == 0) {
                posX = 0;
                posY += 80;
            }

        }

        posY = 105.f; 
        //initalizing utility buttons
        for (int i = 0; i < 5; i++) {
        
            // Equal size button
            if (i < 4) {
                util_button[i].button({ x, 45 }, { 240, posY });
                util_Txt[i].setText_util(i, { 240,  posY });

            }
            // Arithmetic buttons
            else {
                util_button[i].button({ x, 95 }, { 240.f, 325.f });
                util_Txt[i].setText_util(i, {240.f, 325.f});

            }
                posY += 55;

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
                //Buttons pos;

                switch (event.type) {

                case sf::Event::Closed:
                    window.close();
                    break; 

                case (sf::Event::MouseButtonPressed):
                    //get mouse position
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window); 
                    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                   // cout << worldPos.x,  worldPos.y;
                    // Check for button press
                    for (int i = 1; i < 13; i++) {
                        if (button[i].getPosition() == worldPos) {
                            button[i].button_press(i);
                        }
                    }

                   // cout << "Mouse Position (World): x = " << worldPos.x << ", y = " << worldPos.y << std::endl;

                   // pos.setShapes(button[13]); 

                  //  pos.button_press(worldPos); 

             //   default:
                    break;
                }
               

            }


            for (int i = 0; i < 13; i++) {
                if (i < 5) {
                    util_button[i].draw(window);
                    util_Txt[i].draw(window); 
                        
                }
                button[i].draw(window);
                numTxt[i].draw(window);
            }

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