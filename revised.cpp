#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <unordered_set>
#include <cstdlib>
#include <Unordered_map>

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
//This is for room 3: flip room
std::string coin(){
    int flip = rand() % 100 + 1;
    if(flip <= 1){
        return "Your Vitamin C levels increased.";
    }
    else{
        return "You flip the coin and nothing happened, but maybe it could have been different.";
    }
}
//This is for room number 6: gatekeeper room
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
    if(room == 2 || room == 10){
        battle = true;
    }
    else if(room == 6){
        quiz = true;
    }
    else if(room == 3){
        flip = true;
    }
    else if(room == 7){
        elevator = true;
    }
}

int generateRoom(){
    return rand() % 5 + 1;
}
//This function makes it so that if the input is 'a' it would direct it to attack or 'd' for defend
std::string attOrDef(std::string s){

    std::unordered_map<char,int> attack = {{'a',2}, {'t',2}, {'c',1},{'k',1}};
    std::unordered_map<char,int> defend = {{'d',2}, {'e',2}, {'f',1},{'n',1}};
    std::string output;

    for(int i = 0; i < s.size(); i++ ){
        s[i] = tolower(s[i]);
        if(attack.find(s[i]) != attack.end()){
            if(attack[s[i]] == 0){
                attack.erase(s[i]);
            }
            else{
                attack[s[i]] = attack[s[i]] - 1;
            }
        }
        if(defend.find(s[i]) != defend.end()){
            if(defend[s[i]] == 0){
                defend.erase(s[i]);
            }
            else{
                defend[s[i]] = defend[s[i]] - 1;
            }
        }
    }
    
    if(attack.size() >= defend.size()){
        output = "attack";
    }
    else{
        output = "defend";
    }
    return output;
}   
// most of the screens are printed by this function
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
    case 2:std::cout <<"_______________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|                          ____________                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |          |                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |          |                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |          |                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |          |                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |          |                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |          |                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |          |                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |__________|                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                           ___________                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |          |                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |          |                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |          |                                   |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|                          |__________|                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"                                    You have defeated the slime                                  " << std::endl;
        std::cout <<"                  You gained exp, unfortunately in this build, exp does not matter               " << std::endl;
        std::cout <<"                                      You will continue forward                                  " << std::endl;
        std::cout <<"                                       Any number to continue                                    " << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
    case 3:
    std::cout <<"____________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                       _______________________                    |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                      /                       \\                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                     /      ________           \\                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                    /     /         \\           \\                |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                   |     |       0   \\           |                |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                   |     |         __/           |                |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                   |     \\         \\             |                |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                   \\      \\         \\           /                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                    \\      \\         \\         /                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                     \\      \\         \\       /                   |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|                      \\ _____________________/                    |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"                               You defeat the slime and move forward                          " << std::endl;
        std::cout <<"                              It has a 1 percent for something special                      " << std::endl;
        std::cout <<"                                        You find a coin.                                         " << std::endl;
        std::cout <<"                                         Flip the coin?                                          " << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
        case 6:
        std::cout <<"____________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|                |          ___                  |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                |         |    |                |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                |         |____|                |   -_-__-        |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                |             \\                |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|   _-_--_       |    /\\ ____/ / \\              |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                |   /|_|\\        \\            |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                |     V          / \\           |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                |               /    \\         |     -_-_-_      |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                |                               |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    _-_-_-      |                               |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                |                               |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                |                               |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                |                               |   -_--__-       |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|                |                               |                 |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"                          You are on a bridge and a gatekeeper blocks the way                   |" << std::endl;
        std::cout <<"                               Answer his questions and he will let you pass                    |" << std::endl;
        std::cout <<"                      He is much stronger than you and you forgot your swimming gear            |" << std::endl;
        std::cout <<"                                        But he is a pacifist                                    |" << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
            break;
        case 7:
        std::cout <<"____________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                       |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                       |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                       |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                               ____________________                    |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                              |          |          |                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/| _______________________      |          |          |                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/||                       |     |          |          |                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/||                       |     |          |          |                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/||    PLEASE DONT        |     |          |          |                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/||                       |     |          |          |                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|________________________      |          |          |                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|          |                   |          |          |                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|          |                   |          |          |                  |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|          |                   |          |          |                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|          |                                                            |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"                                       You find an elevator in a cave                            " << std::endl;
        std::cout <<"                                         it has a sign next to it                                " << std::endl;
        std::cout <<"                        (if you enter the elevator you'll be timed out forever)                  " << std::endl;
        std::cout <<"                                       Go in?(This is not a joke dont do it)                     " << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
        case 8:
        std::cout <<"________________________________________________________________________________________________" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |"<< std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|                |                              |                           |                   |" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"                                     You went in the elevator                                  " << std::endl;
        std::cout <<"                           You're stuck here for like 900000000000 seconds                     " << std::endl;
        std::cout <<"                                   No music too so this is terrible                            " << std::endl;
        std::cout <<"                            You actually have to wait it out or reset                          " << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
    case 11:
        std::cout <<"_______________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                The end                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|                                                                         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"                                    Thanks for Playing my Game                                  " << std::endl;
        std::cout <<"                                       Hope you had some fun                                    " << std::endl;
        std::cout <<"                             I had fun making this and thinking about it                        " << std::endl;
        std::cout <<"                                       Any number to continue                                   " << std::endl;
        std::cout<< " ______________________________________________________________________________________________ " << std::endl;
        break;
        
    }
} 
//These screens are used for battles because here your hp and enemy hp is displayed.
void battleRoom(int room, int playerHp, int enemyHp){
    if(room == 2){
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
        std::cout <<"                                      You have " << playerHp << " hp                                " << std::endl;
        std::cout <<"                                     The slime has " << enemyHp << " hp                             " << std::endl;
        std::cout <<"                                       Attack or Defend?                                         " << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        
    }
    else{
        std::cout <<"_______________________________________________________________________________________________" << std::endl;
        std::cout <<"|                                                                \\    \\                         |" << std::endl;
        std::cout <<"|                                                                 /    \\                        |" << std::endl;
        std::cout <<"|                                          ______                 \\    /                        |" << std::endl;
        std::cout <<"|                                        /       \\    /\\          /   \\                         |" << std::endl;
        std::cout <<"|                                        | 0    0 |   \\/           \\    \\                       |" << std::endl;
        std::cout <<"|                                        \\_______/  _  |           \\   /                        |" << std::endl;
        std::cout <<"|                                        /        \\/   |            /   \\                       |" << std::endl;
        std::cout <<"|                                        |         |   |             \\  /                       |" << std::endl;
        std::cout <<"|                  /\\                    |         |   |              \\/                        |" << std::endl;
        std::cout <<"|                _/  \\                   |         |   |                                        |" << std::endl;
        std::cout <<"|               /     /                  |         |   |                                        |" << std::endl;
        std::cout <<"|              /  fire\\                                                                         |"<< std::endl;
        std::cout <<"|              |       \\                                                                        |" << std::endl;
        std::cout <<"|  /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\ |" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"                                       \"You'll die for this\"                                                 " << std::endl;
        std::cout <<"                                      You have " << playerHp << " hp                               " << std::endl;
        std::cout <<"                                     The Boss has " << enemyHp << " hp                             " << std::endl;
        std::cout <<"                                        Attack or Defend?                                         " << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
    }
}

int main(){
    std::string character;
    character = rollCharacter();

    srand(time(0));
    // These variables help set up the core mechanics of the game for the player

    std::unordered_set<int> visited = {1};
    int room = 1;
    int move;
    bool gameOver = false;
    int playerHp = 30;

    enemy boss;
    boss.hp = 40;
    boss.dmg = 4;

    enemy slime;
    slime.hp = 20;
    slime.dmg = 2;
    //These bools are the events that the game has to check.
    bool quiz = false;
    bool battle = false;
    bool flip = false;
    bool elevator = false;
    
    printRoom(1);
    std::cin >> move;
    if(move == 1){
    
        while(!gameOver){
            // fix this because the rooms has become different
                //This generates a new room until it generates a room that the player has not visited
            while(visited.find(room) != visited.end()){
                room = generateRoom();
                if(room == 1){
                    room = 2;
                }
                else if(room == 2){
                    room = 3;
                }
                else if(room == 3){
                    room = 6;
                }
                else if(room == 4){
                    room = 7;
                }
                else{
                    room = 10;
                }
            }
            visited.insert(room);
            

            // Event Check for Room
            eventCheck(room,battle,quiz,flip,elevator);
            
            //Activates special situations depending on bool conditions
            if(battle){
                std::string action;
                if(room == 2){
                    

                    while(slime.hp > 0 && playerHp > 0){
                        battleRoom(2, playerHp, slime.hp);
                        std::cin >> action;
                        action = attOrDef(action);

                       if(action == "attack"){
                            playerHp = playerHp - 4;
                            slime.hp = slime.hp - 10;
                        }
                        else{
                            playerHp = playerHp - slime.dmg * 0.65;
                        }
                    }
                }
                else{
                    

                    while(boss.hp > 0 && playerHp > 0){
                        battleRoom(10, playerHp, boss.hp);
                        std::cin >> action;
                        action = attOrDef(action);
                        

                        if(action == "attack"){
                            playerHp = playerHp - 4;
                            boss.hp = boss.hp - 10;
                        }
                        else{
                            playerHp = playerHp - boss.dmg * 0.65;
                        }
                    }
                }

                // The outcomes of battle
                if(playerHp <= 0){
                    gameOver = true;
                }
                else if(room == 2){
                    printRoom(2);
                    int defeatRoom = -9999999;
                    while(defeatRoom == -9999999){
                        std::cin >> defeatRoom;
                        
                    }
                }
                else{
                    printRoom(11);
                    int ending = -9999999;
                    while(ending == -9999999){
                        std::cin >> ending;
                    }
                    gameOver = true;
                }
                battle = false;

            }
            else if(quiz){
                // This is the gatekeeper room
                printRoom(6);
                std::this_thread::sleep_for(std::chrono::seconds(3));
                startQuiz(character);
                std::this_thread::sleep_for(std::chrono::seconds(3));
                quiz = false;
            }
            else if(flip){
                std::string outcome = "You have not flipped yet" ;
                printRoom(3);
                int yesOrNo = 2;
                while(yesOrNo != 1 && yesOrNo != 0){
                    std::cin >> yesOrNo;
                }
                if(yesOrNo == 1){
                    outcome = coin();
                }
                else{
                    outcome = "You did not flip the coin";
                }
                std::cout << outcome << std::endl;
                std::cout << "You will proceed in 3 seconds" << std::endl;
                
                std::this_thread::sleep_for(std::chrono::seconds(3));
                flip = false;
            }
            else if(elevator){
                // If you go into the elevator then you are timed out if not you move onto another room
                printRoom(room);
                int goIn = 2;

                while(goIn != 1 && goIn != 0){
                    std::cin >> goIn;
                }

                if(goIn == 1){
                    printRoom(8);
                    std::this_thread::sleep_for(std::chrono::seconds(90000));
                }
                elevator = false;
            }
        }
    }
    else if(move == 0){

        gameOver = true;

        std::cout << std::endl << "This is a hidden ending for those seeking to try and be curious. Congrats." << std::endl << std::endl;
    }

    std::cout << "Game End" << std::endl;
    
   return 0;
}
  
