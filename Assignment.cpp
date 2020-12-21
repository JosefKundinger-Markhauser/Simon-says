/*
Name				: Josef Kundinger-Markhauser
Student number		: 040824003
Course				: CST8219 - C++
Professor's Name	: Eric Torunski
Assignment due date	: December 11 2020
submission date		: December 9 2020
File				: Assignmet.cpp
*/

#include "Assignment.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace nana;

/*Global variables*/
const int R_NUM = 0;
const int B_NUM = 1;
const int Y_NUM = 2;
const int G_NUM = 3;

//colours
color RED = color(255, 0, 0);
color B_RED = color(255, 128, 128);

color GREEN = color(0, 255, 0);
color B_GREEN = color(0, 255, 128);

color YELLOW = color(255, 255, 0);
color B_YELLOW = color(255, 255, 128);

color BLUE = color(0, 0, 255);
color B_BLUE = color(128, 128, 255);

//Lists
std::vector<int> expected;
std::vector<int> userInput;

int main()
{   
    //Declare form
    form fm;

    int i = 0;
    int randNum;
    bool isPlaying = false;

    //timers
    timer buttonTimer{ std::chrono::milliseconds(500) };
    timer userTimer{ std::chrono::milliseconds(5000) };

    //Define a label and display a text.
    label title{ fm, "<bold size=14>Simon Says</>" };
    title.format(true);
    label result{ fm };
    result.format(true);

    //sounds
    nana::audio::player redSound("Do_Piano.wav");
    nana::audio::player blueSound("Re_Piano.wav");
    nana::audio::player yellowSound("Mi_Piano.wav");
    nana::audio::player greenSound("Fa_Piano.wav");
    nana::audio::player gameOver("game_over.wav");
    nana::threads::pool pool(1);

    // buttons
    button redBtn{ fm };
    button blueBtn{ fm };
    button yellowBtn{ fm };
    button greenBtn{ fm };
    button start{ fm, "START" };

    // timers for user to input
    userTimer.elapse([&] {
        result.caption("You Took too long, you made it to round " + std::to_string(expected.size()) + " of the game\nPress start to play again!");
        gameOver.play();
        isPlaying = false;
        
    });

    //Create buttons
    //red
    redBtn.bgcolor(RED);
    redBtn.events().click([&] {
        redBtn.bgcolor(B_RED);
        redBtn.bgcolor(RED);
        if (isPlaying) {
            userInput.push_back(R_NUM);
            if (expected[i] != userInput[i]) {
                userTimer.stop();
                result.caption("Sorry wrong colour, you made it to round " + std::to_string(expected.size()) + " of the game\nPress start to play again!");
                
                gameOver.play();
                isPlaying = false;
                
            }
            else {
                if (i == expected.size() - 1) {
                    userTimer.stop();
                    randNum = rand() % 4;
                    expected.push_back(randNum);
                    i = 0;
                    userInput.clear();
                    redSound.play();
                    Sleep(350);
                    buttonTimer.start();
                }
                else {
                    userTimer.stop();
                    redSound.play();
                    userTimer.start();
                    i++;
                }
            }
        }
        else {
            redSound.play();
        }
        });

    //blue
    blueBtn.bgcolor(BLUE);
    blueBtn.events().click([&] {
        blueBtn.bgcolor(B_BLUE);
        blueBtn.bgcolor(BLUE);
        if (isPlaying) {
            userInput.push_back(B_NUM);
            if (expected[i] != userInput[i]) {
                userTimer.stop();
                result.caption("Sorry wrong colour, you made it to round " + std::to_string(expected.size()) + " of the game\nPress start to play again!");
                
                gameOver.play();
                isPlaying = false;
                
            }
            else {
                if (i == expected.size() - 1) {
                    userTimer.stop();
                    randNum = rand() % 4;
                    expected.push_back(randNum);
                    i = 0;
                    userInput.clear();
                    blueSound.play();
                    Sleep(350);
                    buttonTimer.start();
                }
                else {
                    userTimer.stop();
                    blueSound.play();
                    userTimer.start();
                    i++;
                }
            }
        }
        else {
            blueSound.play();
        }
        });

    //yellow
    yellowBtn.bgcolor(YELLOW);
    yellowBtn.events().click([&] {
        yellowBtn.bgcolor(B_YELLOW);
        yellowBtn.bgcolor(YELLOW);
        if (isPlaying) {
            userInput.push_back(Y_NUM);
            if (expected[i] != userInput[i]) {
                userTimer.stop();
                result.caption("Sorry wrong colour, you made it to round " + std::to_string(expected.size()) + " of the game\nPress start to play again!");
                
                gameOver.play();
                isPlaying = false;
                
            }
            else {
                if (i == expected.size() - 1) {
                    userTimer.stop();
                    randNum = rand() % 4;
                    expected.push_back(randNum);
                    i = 0;
                    userInput.clear();
                    yellowSound.play();
                    Sleep(350);
                    buttonTimer.start();
                }
                else {
                    userTimer.stop();
                    yellowSound.play();
                    userTimer.start();
                    i++;
                }
            }
        }
        else {
            yellowSound.play();
        }
        });

    //green
    greenBtn.bgcolor(GREEN);
    greenBtn.events().click([&] {
        greenBtn.bgcolor(B_GREEN);
        greenBtn.bgcolor(GREEN);
        if (isPlaying) {
            userInput.push_back(G_NUM);
            if (expected[i] != userInput[i]) {
                userTimer.stop();
                result.caption("Sorry wrong colour, you made it to round " + std::to_string(expected.size()) + " of the game\nPress start to play again!");
                
                gameOver.play();
                isPlaying = false;
                
            }
            else {
                if (i == expected.size() - 1) {
                    userTimer.stop();
                    randNum = rand() % 4;
                    expected.push_back(randNum);
                    i = 0;
                    userInput.clear();
                    greenSound.play();
                    Sleep(350);
                    buttonTimer.start();
                }
                else {
                    userTimer.stop();
                    greenSound.play();
                    userTimer.start();
                    i++;
                }
            }
        }
        else {
            greenSound.play();
        }

        });

    //timer to play all expected buttons
    buttonTimer.elapse([&] {
        
        int temp = expected[i];
        switch (temp) {
        case R_NUM:
            redBtn.bgcolor(B_RED);
            redSound.play();
            redBtn.bgcolor(RED);
            break;
        
        case Y_NUM:
            yellowBtn.bgcolor(B_YELLOW);
            yellowSound.play();
            yellowBtn.bgcolor(YELLOW);
            break;
        
        case G_NUM:
            greenBtn.bgcolor(B_GREEN);
            greenSound.play();
            greenBtn.bgcolor(GREEN);
            break;
        
        case B_NUM:
            blueBtn.bgcolor(B_BLUE);
            blueSound.play();
            blueBtn.bgcolor(BLUE);
            break;
        }

        i++;

        if (i == expected.size()) {
            buttonTimer.stop();
            i = 0;
            userTimer.start();
        }
    });

    //start
    start.events().click([&]{
        
        userInput.clear();
        expected.clear();
        result.caption("");
        isPlaying = true;

        i = 0;
        randNum = rand() % 4;
        expected.push_back(randNum);
        
        buttonTimer.start();
    });

    //Layout management
    fm.div("vert < <> <TITLE> <> > < <RESULT> > < <GREEN> <> <RED> > < <> <START> <> > < <YELLOW> <> <BLUE> >");
    fm["TITLE"]<<title;
    fm["RESULT"] << result;
    fm["START"] << start;
    fm["GREEN"] << greenBtn;
    fm["RED"] << redBtn;
    fm["YELLOW"] << yellowBtn;
    fm["BLUE"] << blueBtn;
    fm.collocate();

    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    nana::exec();
}