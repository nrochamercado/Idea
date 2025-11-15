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
        std::cout <<"|                                  You have " << health << " health                                     |" << std::endl;
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
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|"<< std::endl;
        std::cout <<"| __/|_/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"| __/ _/|-/|                                                                  |\\-|\\_|\\__|" << std::endl;
        std::cout <<"|_______________________________________________________________________________________________|" << std::endl;
        std::cout <<"|"<< flip << "                                                                                " << std::endl;
        std::cout <<"|                               You have " << health << " health                                     |" << std::endl;
        std::cout <<"|                         You notice                                                                |" << std::endl;
        std::cout <<"|                                                                                               |" << std::endl;
        std::cout<< " _______________________________________________________________________________________________ " << std::endl;
        break;
    case 5:
        
        break;
    case 10:
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
    slime.dmg = 20;
// what could be
    enemy boss;
    boss.hp = 40;
    boss.dmg = 4;

    std::string type = generateClass();

    // int arr[10] = {1,2,3,4,5,6,7,8,9,10} this is basically how the map looks like.

    int playerPosition = 1;
    int playerhealth = 20;
    bool GameOver = false;
    bool battleMode = false;
    int enemyhealth = 20;
    std::string flipOutcome = "You did not flip the coin";
    

    
    while(!GameOver && playerPosition <= 10){
        
        battleMode = eventCheck(playerPosition);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        printScreen(playerPosition,type,playerhealth,enemyhealth,flipOutcome);
        std::cout << std::endl << std::endl << "Choose 1 for Yes or 0 for No, else \"attack\" and \"defend\"." << std::endl;
        if(battleMode){
           std::string action;
           std::cin >> action;
           // action = validateAction()
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
            else if(move = 1){
               playerPosition++; 
            }
            
        }
    }

    
    std:: cout << "The End" << std::endl;
    return 0;
}
