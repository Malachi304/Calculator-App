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

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

   
private:

    sf::RectangleShape shape;
};


//Mathematical procedures
class Claculation {
public:
    void operation(int num) {
        //if string is a number 0-9, convert to type int 
        //else if string it a utlity, do operation
     //   if (isNumber(x)) {
            //int num = stoi(x);
        num_holder.push_back(num);

        int test_ans = 0;

        if (num_holder.size() == 2) {
            for (int i = 0; i < num_holder.size(); i++) {
                test_ans =+ num_holder[i];
            }
        }
        cout << endl << test_ans;

        num_holder.clear();
    }

    

private:
    std::vector <int> num_holder;

    // Helper function to check if a string is a number
    bool isNumber(const string& str) {
        return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
    }
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
            str = { "." };
        }
        else if (num == 11) {
            str = { "0" };
        }
        else if (num == 12) {
            str = { "C" }; 
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
        case 1: str = { "*" }; break;
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

    //main text box display
    void mainText(string x){

       
        if (!font.loadFromFile("C:\\Fonts\\JAi.TTF")) {
            cout << "Font load error";
            return;
        }
        
        sf::Text text;
       // string str = std::to_string(x); 

        //set text
        text.setFont(font);
        text.setString(x);
        text.setCharacterSize(25);
        text.setFillColor(sf::Color::White);
        text.setPosition({ 0.f, 0.f });

        drawMainText = text;

    }

    //draw text
    void draw(sf::RenderWindow& window) {
          window.draw(drawText);
    }
    void drawMain(sf::RenderWindow& window) {
        window.draw(drawMainText);

    }

private: 
    sf::Text drawText;
    sf::Text drawMainText;

    sf::Font font; 
    Claculation calc; 
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
        Text mainText;
        std::string inputNumber; // String to store the digits entered by the user

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
                // 3.) case for button push (keys)
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
                        if (button[i].contains(button[i].getGlobalBounds(), worldPos)) {
                            //match button index with number on dispay
                            if (i >= 0 && i <= 9) {
                                // Append the digit to the inputNumber string
                                inputNumber += std::to_string(i);
                            }
                            else if (i == 11) { // Button 0
                                inputNumber += "0";
                            }
                            else if (i == 12) { // Clear button
                                inputNumber.clear(); // Clear the input
                            }
                            else if (i == 10) { // Clear button
                                inputNumber += "."; // Clear the input
                            }

                            // Update the main text with the current input
                            mainText.mainText(inputNumber);
                        }
                       // else break; 
                     }

                    for (int j = 0; j < 5; j++) {
                        if (util_button[j].contains(util_button[j].getGlobalBounds(), worldPos)) {
                            if (j == 0) {
                                inputNumber += "÷";
                            }
                            else if (j == 1) {
                                inputNumber += "*";
                            }
                            else if (j == 2) {
                                inputNumber += "-";
                            }
                            else if (j == 3) {
                                inputNumber += "+";
                            }
                            else if (j == 4) {
                                inputNumber += "=";
                            }


                            mainText.mainText(inputNumber);

                        }


                  //    else if (util_button[i].contains(button[i].getGlobalBounds(), worldPos)){


                //    }
                                 
                    }
                  //  break; 
                    /*
                case (sf::Event::KeyPressed):
                    
                    // loop through buttons
                    for (int i = 1; i < 13; i++) {

                        //check if mouse click falls within the bounds of a button
                        if (button[1].contains(button[i].getGlobalBounds(), worldPos)) {
                            //match button index with number on dispay
                            if (i >= 0 && i <= 9) {
                                // Append the digit to the inputNumber string
                                inputNumber += std::to_string(i);
                            }
                            else if (i == 11) { // Button 0
                                inputNumber += "0";
                            }
                            else if (i == 12) { // Clear button
                                inputNumber.clear(); // Clear the input
                            }
                            else { // Other utility buttons
                                break;
                            }

                            // Update the main text with the current input
                            mainText.mainText(inputNumber);
                        }

                    }
                    break;*/
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
            mainText.drawMain(window);

            window.display();

        }
    }

private: 
    sf::Event event;

};


int main()
{
    //call display constructor
    Display display; 
    display.mainDisplay(); 

    return 0;
}


