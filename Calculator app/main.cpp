#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <string>


using namespace std;

class Buttons {
public:

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


        switch (index) {
        case 1: cout << "1"; break; 
        case 2: cout << "2"; break; 
        case 3: cout << "3"; break; 
        case 4: cout << "4"; break; 
        case 5: cout << "5"; break; 
        case 6: cout << "6"; break;
        case 7: cout << "7"; break;
        case 8: cout << "8"; break;
        case 9: cout << "9"; break; 
        case 11: cout << "0"; break;

        default: cout << "INVALID"; break; 

        }

    }
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

        //utility text
        switch (num) {
        case 0: str = { "÷" }; break; 
        case 1: str = { "X" }; break;
        case 2: str = { "-" }; break;
        case 3: str = { "+" }; break;
        case 4: str = { "=" }; break;

        default: break; 

        }

        //set text
        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(25);
        text.setFillColor(sf::Color::White);
        text.setPosition(position);

        drawText = text;
    }

    //draw text
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

            //every 3 shapes in a row is the is followed by a new row
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

       
            //check all the window's events that 
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
                    //get mouse position (pixel coordinates)
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window); 
                    //convert to pixles to world coordinates
                    sf::Vector2f worldPos = window.mapPixelToCoords(mousePos);

                    // loop through buttons
                    for (int i = 1; i < 13; i++) {
                        
                        //check if mouse click falls within the bounds of a button
                        if (button[1].contains(button[i].getGlobalBounds(), worldPos)) {

                            //match button index with number on dispay
                            button[i].button_press(i);
                        }
                    }
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