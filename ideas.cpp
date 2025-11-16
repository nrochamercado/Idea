#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

// generateClass generates a class for the player out of the 4 roles: Mage, Warrior, Rogue, and Bear.
// Enemy class helps to create the enemies and assign them hp and their damage
// eventCheck is used to intialize if an enemy has appeared and if to enter battle
//  battle prints the combat actions

class enemy{
 public:
    int hp;
    int dmg;
};
bool eventCheck(int location){
    if(location == 2 || location == 10){
        return true;
    }
    else{
        return false;
    }
}
std::string flip(){
    int flip = rand() % 100 + 1;
    if(flip <= 1){
        return "Your Vitamin C levels increased.";
    }
    else{
        return "You flip the coin and nothing happened, but maybe it could have been different.";
    }
}
void quiz(std::string type){

    int randomPhrase;
    std::string answer;

    std::cout << "What is your class that you started with?(They were Mage, Warrior,Rogue, and Bear)" << std::endl;
    getline(std::cin,answer);

    while(answer != type){
        randomPhrase = rand() % 3 + 1;
        

        if(randomPhrase == 1){
            std::cout << " Seems like you remembered it wrong time again" << std::endl;
        }
        else if(randomPhrase == 2){
            std::cout << "Disappointing, again." << std::endl;
        }
        else{
            std::cout << " You're making me cry. Again." << std::endl;
        }
        std::cin >> answer;
    }
    std::cout << "Correct" << std::endl;
    std::cout << "What is the current year?" << std::endl;
    std::cin >> answer;
    while(answer != "2025"){
        randomPhrase = rand() % 3 + 1;
        
        if(randomPhrase == 1){
            std::cout << " Seems like you remembered it wrong time again" << std::endl;
        }
        else if(randomPhrase == 2){
            std::cout << "Disappointing, again." << std::endl;
        }
        else{
            std::cout << " You're making me cry. Again." << std::endl;
        }
        std::cin >> answer;
    }
    std::cout << "Correct" << std::endl;
    std::cout << "What is this event called?" << std::endl;
    std::cin >> answer;
    while(answer != "Cutiehack" && answer != "cutiehack"){
        randomPhrase = rand() % 3 + 1;
        
        if(randomPhrase == 1){
            std::cout << "Seems like you remembered it wrong time again" << std::endl;
        }
        else if(randomPhrase == 2){
            std::cout << "Disappointing, again." << std::endl;
        }
        else{
            std::cout << " You're making me cry. Again." << std::endl;
        }
        std::cin >> answer;
    }
    std::cout << "Correct" << std::endl;
    std::cout << "You may pass" << std::endl;
}
std::string generateClass(){
    std::string output;
    int random = rand() % 4 + 1;
    switch(random){
        case 1:
            output = "Mage";
            break;
        case 2: 
            output = "Warrior";
            break;
        case 3:
            output = "Rogue";
            break;
        case 4:
            output = "Bear";
            break;
    }
    return output;
}
// printScreen displays the screen to the player
void printScreen(int location, std::string type,int health, int enemyhealth, std::string flip){
    switch(location){
        case 1:
        std::cout <<"_______________________________________________________________________________________________" << std::endl;
        std::cout <<"|      \\        /\\        /\\                                          /\\                        |" << std::endl;
        std::cout <<"|_______\\      /  \\      / \\          _________________         /\\   / \\                        |" << std::endl;
        std::cout <<"|   \\                               /                  \\       / \\  /   \\                       |" << std::endl;
        std::cout <<"|    \\                             |                    |                                       |" << std::endl;
        std::cout <<"|     \\                           /                      \\                                      |" << std::endl;
        std::cout <<"|      \\                          |                       |                                     |" << std::endl;
        std::cout <<"|       \\                        /                        \\               __________________    |" << std::endl;
        std::cout <<"|________\\                      |                          |            /                 \\     |" << std::endl;
        std::cout <<"|   |                          /                            \\           /                   \\   |" << std::endl;
        std::cout <<"|   |                         |                              |        |                      |  |" << std::endl;
        std::cout <<"|   |        __ __           /                               \\        |                      |  |" << std::endl;
        std::cout <<"|   |       |  |  |         |                                 |       |                      |  |" << std::endl;
        std::cout <<"|   |       | 0   0|       /                                  \\       |                      |  |"<< std::endl;
        std::cout <<"|   |       |     |       |                                    |      \\_____________________/   |" << std::endl;
        std::cout <<"|                                                                                               |" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"|                                   You come across a cave                                      |" << std::endl;
        std::cout <<"|                                       You are a " << type << "                                         |" << std::endl;
        std::cout <<"|                                        Move Forward                                           |" << std::endl;
        std::cout <<"|                                           Yes = 1                                             |" << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
    
    case 2:
        std::cout <<"_______________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                              _________________                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                         /                         \\             |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                       |                             |            |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                     |                                |           |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                    |                                  |          |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                   |                                    |         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                  |                                      |        |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|                  _______________________________________         |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"|                                     A slime blocks the path                                  |" << std::endl;
        std::cout <<"|                                     You have " << health << " health                                       |" << std::endl;
        std::cout <<"|                                     The slime has " << enemyhealth << " health                                  |" << std::endl;
        std::cout <<"|                                      Attack or Defend?                                       |" << std::endl;
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
        std::cout <<"|                               You defeat the slime and move forward                          |" << std::endl;
        std::cout <<"|                                  You have " << health << " health                                        |" << std::endl;
        std::cout <<"|                                     You find a coin.                                         |" << std::endl;
        std::cout <<"|                                      Flip the coin?                                          |" << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
    case 4:
        std::cout <<"____________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                           _    _                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                          |\\  |_|                                    |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                            \\ |                                    |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                              |                                    |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                             /\\                                     |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"|"<< flip << "                                                                                " << std::endl;
        std::cout <<"|                               You have " << health << " health                                             |" << std::endl;
        std::cout <<"|                             You notice someone waving at you                                  |" << std::endl;
        std::cout <<"|                                  You feel compelled no?                                       |" << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
    case 5:
        std::cout <<"____________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|         ____________________________________________             |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|        /                                              \\          |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|       /                                                 \\        |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|      /      _______                       _______         \\      |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|     /      |       |                     |       |         \\     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |       |  0    |                     |   0   |            |  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |       |_______|                     |_______|            |  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |                                                          |  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |                                                          |  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |                                                          |  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |                                                          |  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |            \\                            /               |  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|     \\            \\ ________________________/               /    |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|      \\                                                     /     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|        \\ _________________________________________________/      |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"|                                This is Jerry, the skeleton.                                   |" << std::endl;
        std::cout <<"|                        Jerry would give you a treat but it isnt Halloween                     |" << std::endl;
        std::cout <<"|                            Jerry does not even know when Halloween is                         |" << std::endl;
        std::cout <<"|                                         Proceed.                                              |" << std::endl;
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
        std::cout <<"|                         You are on a bridge and a gatekeeper blocks the way                   |" << std::endl;
        std::cout <<"|                              Answer his questions and he will let you pass                    |" << std::endl;
        std::cout <<"|                     He is much stronger than you and you forgot your swimming gear            |" << std::endl;
        std::cout <<"|                                       But he is a pacifist                                    |" << std::endl;
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
        std::cout <<"|                                       You find an elevator in a cave                         |" << std::endl;
        std::cout <<"|                                         it has a sign next to it                             |" << std::endl;
        std::cout <<"|                        (if you enter the elevator you'll be timed out forever)               |" << std::endl;
        std::cout <<"|                                       Go in?(This is not a joke dont do it)                  |" << std::endl;
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
        std::cout <<"|                                     You went in the elevator                                  |" << std::endl;
        std::cout <<"|                           You're stuck here for like 900000000000 seconds                     |" << std::endl;
        std::cout <<"|                                   No music too so this is terrible                            |" << std::endl;
        std::cout <<"|                            You actually have to wait it out or reset                          |" << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
    case 9:
        std::cout <<"____________________________________________________________________________________________" << std::endl;
        std::cout <<"| __/|_/|-/|    |     |          |     |          |     |          |     |     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |     |          |     |    _     |     |          |     |     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |     |          |     |  / | \\   |     |          |     |     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |     |          |     |/   |   \\ |     |          |     |     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    | /\\  |          | /\\  |    |     | /\\  |          | /\\  |     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|    |/  \\ |          |/  \\ |    |     |/  \\ |          |/  \\ |     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                      /         |            \\                     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                     |          |            |                     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|     \\ /             |          |            |             \\ /     |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|      |              |          |            |              |      |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|      |              |          |            |              |      |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|      |              |          |            |              |      |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|     /\\              |          |            |             /\\      |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|                                                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|                                                                   |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"|                          The final room adorned with elegant decorations                      " << std::endl;
        std::cout <<"|                                    You forgot your health.                                    |" << std::endl;
        std::cout <<"|                              Thinking about the choices you made                              |" << std::endl;
        std::cout <<"|                                      Enter? (Demo End)                                        |" << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
    }

}


int main(){

    srand(time(0));

    enemy slime;
    slime.hp = 20;
    slime.dmg = 2;
// what could be
    enemy boss;
    boss.hp = 40;
    boss.dmg = 4;

    std::string type = generateClass();

    // int arr[10] = {1,2,3,4,5,6,7,8,9} this is basically how the map looks like.

    int playerPosition = 5;
    int playerhealth = 20;
    bool GameOver = false;
    bool battleMode = false;
    int enemyhealth = 20;
    std::string flipOutcome = "You did not flip the coin";
    

    
    
    while(!GameOver && playerPosition <= 9){
        
        battleMode = eventCheck(playerPosition);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        printScreen(playerPosition,type,playerhealth,enemyhealth,flipOutcome);
        if(playerPosition != 6){
            std::cout << std::endl << std::endl << "Choose 1 for Yes or 0 for No, else \"attack\" and \"defend\"." << std::endl;
        }
        if(battleMode){
           std::string action;
           std::cin >> action;
        
           if(playerPosition == 2){
                if(action == "attack"){
                    playerhealth = playerhealth - slime.dmg;
                    slime.hp = slime.hp - 10;
                    enemyhealth = slime.hp;
                }
                else{
                    playerhealth = playerhealth - slime.dmg * 0.75;
                }
                if(playerhealth <= 0){
                    GameOver = true;
                }
                if(slime.hp <= 0){
                    battleMode = false;
                    playerPosition++;
                }
            }
        }
        else if(playerPosition == 7){
            int move = 0;
            std::cin >> move;
            if(move == 1){
                playerPosition++;
            }
            else{
                playerPosition = playerPosition + 2;
            }
        }
        else if(playerPosition == 8){
             std::this_thread::sleep_for(std::chrono::seconds(9000000));
             playerPosition++;
        }
        else if(playerPosition == 6){
            quiz(type);
            playerPosition++;
        }
        else{
            int move = 0;
            std::cin >> move;
            if(playerPosition == 3){
                if(move == 1){
                    flipOutcome = flip();
                    playerPosition++;
                }
                else{
                    playerPosition++;
                }
            }
            else if(move == 1){
               playerPosition++; 
            }
            
            
        }
    }

    
    std::cout << "The End" << std::endl;
    return 0;
}

