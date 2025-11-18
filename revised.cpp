#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <unordered_set>
#include <cstdlib>

class enemy{
 public:
    int hp;
    int dmg;
};
std::string rollCharacter(){
    std::string output;
    int character = rand() % 6 + 1;
    if(character == 1){
        output = "Mage";
    }
    else if(character == 2){
        output = "Knight";
    }
    else if(character == 3){
        output = "Healer";
    }
    else if(character == 4){
        output = "Rogue";
    }
    else if(character == 5){
        output = "Assasin";
    }
    else if(character == 6){
        output = "Warrior";
    }
    return output;
}
void startQuiz(std::string character){
    std::string answer = "Ifyouguessthisyouareacheater";
    int phrase;
    for(int i = 0; i < character.size(); i++){
        character[i] = tolower(character[i]);
    }
    std::cout << " I am the gatekeeper. I do not care if you whisper or scream your answer as long as you pronounce it exactly(lower case and upper case is fine)" << std::endl << std:: endl;
    std:: cout << "                  My first question is what is your class? (Mage, Warrior, Assasin, Rogue, Healer, Knight)" << std::endl << std::endl;

    while(answer != character){
        if(answer != "Ifyouguessthisyouareacheater"){
            phrase = rand() % 4 + 1;
            if(phrase == 1){
                std::cout << "Correct" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Just kidding you were so wrong that I couldn't believe my eyes" << std::endl << std::endl;
            }
            else if( phrase == 2){
                std::cout << "Incorrect" << std::endl << std::endl;
            }
            else if(phrase == 3){
                std::cout << "Try again, you were close" << std::endl << std::endl;
            }
            else{
                std::cout << "Nope" << std::endl << std::endl;
            }
        }
        std::cin >> answer;
        for(int i =0; i < answer.size();i++){
            answer[i] = tolower(answer[i]);
        }
    }
    std::cout << "Correct" << std::endl;
    std:: cout << "                                       My second question is what is the year" << std::endl << std::endl;
    answer = "Ifyouguessthisyouareacheater";

    while(answer != "2025"){
        if(answer != "Ifyouguessthisyouareacheater"){
            phrase = rand() % 4 + 1;
            if(phrase == 1){
                std::cout << "Correct" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Just kidding you were so wrong that I couldn't believe my eyes" << std::endl << std::endl;
            }
            else if( phrase == 2){
                std::cout << "Incorrect" << std::endl << std::endl;
            }
            else if(phrase == 3){
                std::cout << "Try again, you were close" << std::endl << std::endl;
            }
            else{
                std::cout << "Nope" << std::endl << std::endl;
            }
        }
        std::cin >> answer;
        for(int i =0; i < answer.size();i++){
            answer[i] = tolower(answer[i]);
        }
        std::cout << answer << std::endl;
    }
    std::cout << "Correct" << std::endl;
    std:: cout << "                                My third question is what is the name of the event where I was created" << std::endl << std::endl;
    answer = "Ifyouguessthisyouareacheater";

    while(answer != "cutiehack"){
        if(answer != "Ifyouguessthisyouareacheater"){
            phrase = rand() % 4 + 1;
            if(phrase == 1){
                std::cout << "Correct" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "Just kidding you were so wrong that I couldn't believe my eyes" << std::endl << std::endl;
            }
            else if( phrase == 2){
                std::cout << "Incorrect" << std::endl << std::endl;
            }
            else if(phrase == 3){
                std::cout << "Try again, you were close" << std::endl << std::endl;
            }
            else{
                std::cout << "Nope" << std::endl << std::endl;
            }
        }
        std::cin >> answer;
        for(int i =0; i < answer.size();i++){
            answer[i] = tolower(answer[i]);
        }
    }
    std::cout << "Correct" << std::endl;
    std::cout << "You have answered all my questions. You have been deemed worthy and I will allow you to pass" << std::endl;
    
}
//This checks for specific events in the game
void eventCheck(int room, bool& battle, bool& quiz, bool& flip, bool& elevator){
    if(room == 2){
        battle = true;
    }
    else if(room == 3){
        quiz = true;
    }
    else if(room == 6){
        flip = true;
    }
    else if(room == 7){
        elevator = true;
    }
}

int generateRoom(){
    return rand() % 8 + 2;
}
void printRoom(int room){
    switch(room){
        case 1:
            std::cout <<"_______________________________________________________________________________________________" << std::endl;
        std::cout <<"|      \\        /\\        /\\                                          /\\                        |" << std::endl;
        std::cout <<"|_______\\      /  \\      / \\          _________________        /\\    / \\                        |" << std::endl;
        std::cout <<"|   \\                               /                  \\       / \\  /   \\                       |" << std::endl;
        std::cout <<"|    \\                             |                    |                                       |" << std::endl;
        std::cout <<"|     \\                           /                      \\                                      |" << std::endl;
        std::cout <<"|      \\                          |                       |                                     |" << std::endl;
        std::cout <<"|       \\                        /                        \\               __________________    |" << std::endl;
        std::cout <<"|________\\                      |                          |            /                  \\    |" << std::endl;
        std::cout <<"|   |                          /                            \\          /                    \\   |" << std::endl;
        std::cout <<"|   |                         |                              |        |                      |  |" << std::endl;
        std::cout <<"|   |        __ __           /                               \\        |                      |  |" << std::endl;
        std::cout <<"|   |       |  |  |         |                                 |       |                      |  |" << std::endl;
        std::cout <<"|   |       | 0   0|       /                                  \\       |                      |  |"<< std::endl;
        std::cout <<"|   |       |     |       |                                    |      \\_____________________/   |" << std::endl;
        std::cout <<"|                                                                                               |" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"                                   You come across a cave                                        " << std::endl;
        std::cout <<"                                        You are a "  "                                           " << std::endl;
        std::cout <<"                                       Move Forward                                              " << std::endl;
        std::cout <<"                                           Yes = 1                                               " << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
    }
} 
void battleRoom(int room, int playerHp, int enemyHp){
    if(room ==2){
        
        std::cout <<"_______________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                           ____________________                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                         /                      \\                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                       |                           |              |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                     |                              |             |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                    |                                 |           |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                   |                                   |          |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                  |                                     |         |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|                  _______________________________________         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"                                    A slime blocks the path                                      " << std::endl;
        std::cout <<"                                      You have " << playerHp << "                                " << std::endl;
        std::cout <<"                                     The slime has " << enemyHp << "                             " << std::endl;
        std::cout <<"                                       Attack or Defend?                                         " << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        
    }
    else{
        std::cout <<"_______________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |"<< std::endl;
        std::cout <<"| __/|_/|-/|                                                                               |" << std::endl;
        std::cout <<"| __/ _/|-/|                                                                               |" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"                                    A slime blocks the path                                      " << std::endl;
        std::cout <<"                                      You have " << playerHp << "                                " << std::endl;
        std::cout <<"                                     The Boss has " << enemyHp << "                             " << std::endl;
        std::cout <<"                                       Attack or Defend?                                         " << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
    }
}
std::string attOrDef(std::string action){
    
}
int main(){
    std::string character;
    character = rollCharacter();
    std::cout << character;
    srand(time(0));
    // These variables help set up the core mechanics of the game for the player

    std::unordered_set<int> visited = {1};
    int room = 1;
    int move;
    bool gameOver = false;
    int playerHp = 20;

    //These bools are the events that the game has to check.
    bool quiz = false;
    bool battle = false;
    bool flip = false;
    bool elevator = false;
    
    printRoom(1);
    std::cin >> move;
    if(move == 1){
    
        while(!gameOver){
                //This generates a new room until it generates a room that the player has not visited
            while(visited.find(room) != visited.end()){
                room = generateRoom();
            }
            visited.insert(room);
            
            // Event Check for Room
            eventCheck(room,battle,quiz,flip,elevator);
            //Activates special situations depending on bool conditions
            if(battle){
                std::string action;
                if(room == 2){
                    enemy slime;
                    slime.hp = 20;
                    slime.dmg = 2;
                    while(slime.hp > 0 && playerHp > 0){
                        battleRoom(2,playerHp,slime.hp);
                       //action = attOrDef();
                       slime.hp = slime.hp - 5;
                       playerHp = playerHp - slime.dmg; 
                    }
                }
                else{
                    enemy boss;
                    boss.hp = 40;
                    boss.dmg = 4;
                    while(boss.hp > 0 && playerHp > 0){
                        battleRoom(10,playerHp,boss.hp);
                        boss.hp = boss.hp - 5;
                        playerHp = playerHp - boss.dmg;
                    }
                }
                // The outcomes of battle
                if(playerHp <= 0){
                    gameOver = true;
                }
                else if(room == 2){
                    room = 3;
                }
                else{
                    room = 11;
                }
            }
            else if(quiz){
                startQuiz(character);
            }
            else if(flip){

            }
            else if(elevator){
                int goIn = 2;
                while(goIn != 1 && goIn != 0){
                    std::cin >> move;
                }
                if(goIn == 1){
                    room = 8;
                    printRoom(8);
                    std::this_thread::sleep_for(std::chrono::seconds(90000));
                }
            }
        }
    }
    else if(move == 0){
        gameOver = true;
        std::cout << std::endl << "This is a hidden ending for those seeking to try and be curious. Congrats." << std::endl << std::endl;
    }
    std::cout << "Game Over" << std::endl;
    
   return 0;
}