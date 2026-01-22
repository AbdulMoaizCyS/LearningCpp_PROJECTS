#include <iostream>
#include <ctime>
#include <utility>
#include <limits>

std::pair <int,int> Game(int C,int P){

    int PWins=0,CWins=0;


        switch(C){
            case 1:{
                switch(P){
                    case 1:
                        std::cout << "COMPUTERS CHOICE WAS ROCK!\n";
                        std::cout << "PLAYERS CHOICE WAS ROCK!\n";
                        std::cout << "WE HAVE A TIE!\n";
                        break;
                    case 2:
                        std::cout << "COMPUTERS CHOICE WAS ROCK!\n";
                        std::cout << "PLAYERS CHOICE WAS PAPER!\n";
                        std::cout << "PLAYER HAS WON!\n";
                        PWins++;
                        break;
                    case 3:
                        std::cout << "COMPUTERS CHOICE WAS ROCK!\n";
                        std::cout << "PLAYERS CHOICE WAS SCISSORS!\n";
                        std::cout << "COMPUTER HAS WON!\n";
                        CWins++;
                        break;
                }
                break;}
            case 2:{
                switch(P){
                    case 1:
                        std::cout << "COMPUTERS CHOICE WAS PAPERS!\n";
                        std::cout << "PLAYERS CHOICE WAS ROCK!\n";
                        std::cout << "COMPUTER HAS WON!\n";
                        CWins++;
                        break;
                    case 2:
                        std::cout << "COMPUTERS CHOICE WAS PAPERS!\n";
                        std::cout << "PLAYERS CHOICE WAS PAPERS!\n";
                        std::cout << "WE HAVE A TIE!\n";
                        break;
                    case 3:
                        std::cout << "COMPUTERS CHOICE WAS PAPERS!\n";
                        std::cout << "PLAYERS CHOICE WAS SCISSORS!\n";
                        std::cout << "PLAYER HAS WON!\n";
                        PWins++;
                        break;
                }
                break;}
            case 3:{
                switch(P){
                    case 1:
                        std::cout << "COMPUTERS CHOICE WAS SCISSORS!\n";
                        std::cout << "PLAYERS CHOICE WAS ROCK!\n";
                        std::cout << "PLAYER HAS WON!\n";
                        PWins++;
                        break;
                    case 2:
                        std::cout << "COMPUTERS CHOICE WAS SCISSORS!\n";
                        std::cout << "PLAYERS CHOICE WAS PAPERS!\n";
                        std::cout << "COMPUTER HAS WON!\n";
                        CWins++;
                        break;
                    case 3:
                        std::cout << "COMPUTERS CHOICE WAS SCISSORS!\n";
                        std::cout << "PLAYERS CHOICE WAS SCISSORS!\n";
                        std::cout << "WE HAVE A TIE!\n";
                        break;
                }
                break;}
        }


    return std::make_pair(PWins,CWins);
}


int main(){

    srand(0);

    int ComputersChoice = 0;
    int PlayersChoice =0;
    int Pw=0,Cw=0;

    std::cout << "----WELCOME TO THIS ROCK, PAPER & SCISSORS GAME!----\n";
    
    for(int i=0;i<3;i++){
        ComputersChoice = (rand() % 3)+1;
        do{
            
            std::cout << "PLEASE ENTER 1 FOR ROCK\nENTER 2 FOR PAPERS\nENTER 3 FOR SCISSORS\n";
            if(std::cin >> PlayersChoice){
                if(PlayersChoice<=0 || PlayersChoice>3){
                    std::cout << "INVALID ENTRY!!! TRY AGAIN!!!!!\n";
                }else{
                    break;
                }
            }else{
                std::cout << "IVALID ENTRY!!! TRY AGAIN!!!\n";
                std::cin.clear();
                std::cin >>std::ws;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        }while((PlayersChoice <=0 || PlayersChoice>3) || std::cin.good());

        std::pair result = Game(ComputersChoice,PlayersChoice);
        Pw+=result.first;
        Cw+=result.second;
    }
    
    std::cout << "----THE GAME WAS PLAYED FOR BEST OF THREE!----\n";
    std::cout << "THE COMPUTER WON: " << Cw<< "TIMES!\n";
    std::cout << "THE PLAYER WON: " <<  Pw<< "TIMES!\n";
    std::cout << "----THANK YOU FOR PLAYING THIS GAME----\n";

    return 0;
}