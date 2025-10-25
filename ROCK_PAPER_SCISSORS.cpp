#include <iostream>
#include <ctime>
#include <string>
#include <tuple>

void ShowChoice(char choice){
    
    switch(choice){
        case 'r':
            std::cout << "ROCK!\n";
            break;
        case 'p':
            std::cout << "PAPERS!\n";
            break;
        case 's':
            std::cout << "SCISSORS!\n";
            break;
    }
    

}
char getPlayerchoice(){
    char choice;

    do{
        std::cout << "*****WELCOME TO THIS SHORT GAME*****\nPress 'r' to choose rock.\nPress 'p' to choose papers.\nPress 's' to choose scissors.\n";
        std::cout << "THIS CHOICE IS CASE SENSITIVE!!!\n";
        std::cin >> choice;
    }while(choice != 'r' && choice != 'p' && choice != 's');

    return choice;
}

char getComputerChoice(){
    int rnum=0;
    char choice;
    srand(time(0));

    rnum = rand() % 3 + 1;

    switch(rnum){
        case 1:
            choice = 'r';
            break;
        case 2:
            choice = 'p';
            break;
        case 3:
            choice = 's';
            break;

    }

    return choice;
}

std::tuple<int,int,int> Game(char playerchoice, char computerchoice){
    
    int Pcount=0,Ccount =0,TieC=0;
    switch(playerchoice){
        case 'r':
            if(computerchoice == 'r'){
                std::cout << "LADIES AND GENTLEMEN.\n WE HAVE A TIE!\n";
                TieC++;
            }else if(computerchoice == 'p'){
                std::cout << "LADIES AND GENTLEMEN.\nTHE COMPUTER WON!\n";
                Ccount++;
            }else{
                std::cout << "LADIES AND GENTLEMEN.\nTHE PLAYER WON!\n";
                Pcount++;
            }
            break;
        case 'p':
            if(computerchoice == 'r'){
                std::cout << "LADIES AND GENTLEMEN.\n THE PLAYER WON!\n";
                Pcount++;
            }else if(computerchoice == 'p'){
                std::cout << "LADIES AND GENTLEMEN.\nWE HAVE A TIE!\n";
                TieC++;
            }else{
                std::cout << "LADIES AND GENTLEMEN.\nTHE COMPUTER WON!\n";
                Ccount++;
            }
            break;
        case 's':
            if(computerchoice == 'r'){
                std::cout << "LADIES AND GENTLEMEN.\n THE COMPUTER WON!\n";
                Ccount++;
            }else if(computerchoice == 'p'){
                std::cout << "LADIES AND GENTLEMEN.\nTHE PLAYER WON!\n";
                Pcount++;
            }else{
                std::cout << "LADIES AND GENTLEMEN.\nWE HAVE A TIE!\n";
                TieC++;
            }
            break;
    }

    return std::make_tuple(Pcount, Ccount, TieC);


}


int main(){
    
    char playerChoice;
    char ComputerChoice;

    int PlayerWins=0,ComputerWins=0,Ties=0;

    do{
    playerChoice = getPlayerchoice();
    ComputerChoice = getComputerChoice();

    std::cout << "YOUR CHOICE WAS!!!\n";
    ShowChoice(playerChoice);

    std::cout << "THE COMPUTERS CHOICE WAS!!!\n";
    ShowChoice(ComputerChoice);
    auto result = Game(playerChoice,ComputerChoice);
    PlayerWins += std::get<0>(result);
    ComputerWins += std::get<1>(result);
    Ties += std::get<2>(result);

    }while(PlayerWins !=3 && ComputerWins!=3 && Ties!=3);

    if(Ties==3){
        std::cout << "THREE TIES AND THATS GAME OVER FOLKS!!!\n";
    }else if(PlayerWins>ComputerWins){
        std::cout << "AFTER A CLOSE CONTEST, THE PLAYER HAS WON!!!";
    }else{
        std::cout << "EVEN AFTER RELENTLESS EFFORTS FROM THE PLAYER, THE MACHINE CAME OUT ON TOP!!";
    }



    return 0;
}