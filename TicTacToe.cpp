#include <iostream>
#include <string>
#include <utility>
#include <ctime>

void DrawBoard(std::string ARRAY[9][9]);
void PrintBoard(std::string array[9][9]);
bool EnteringMarkComputer(std::string B[9][9], char x,int &E);
bool EnteringMarkPlayer(std::string B[9][9], char x,int &E);
std::pair<char,char> MarkSelection();
void Game(std::string B[9][9],char P,char C);
bool CheckingWin(std::string B[9][9],char M);

int main(){
    srand(time(nullptr));
    int PlayerWins=0,ComputerWins=0,Draws=0;
    char PlayerMark,ComputerMark;
    std::string Board[9][9];

    std::pair<char,char> result = MarkSelection();

    PlayerMark = result.first;
    ComputerMark = result.second;
    DrawBoard(Board);
    PrintBoard(Board);
    Game(Board,PlayerMark,ComputerMark);

    return 0;
}

void DrawBoard(std::string ARRAY[9][9]){
    std::cout << std::endl;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i == 2 or i == 6){
                ARRAY[i][j] = "==";
            }else if(j==3 || j == 7){
                ARRAY[i][j] = " || ";
            }else{
                ARRAY[i][j] =  " ";
            }
        }
    }

}
void PrintBoard(std::string array[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
}
std::pair<char,char> MarkSelection(){
    char PMark,CMark;

    std::cout << "WOULD YOU LIKE TO PLAY WITH 'X' OR 'O'?\nPLEASE ENTER THE RESPECTIVE CHARACTER!:\n";
    do{
        std::cin >> PMark;
        PMark = toupper(PMark);
        if(PMark != 'X' && PMark != 'O'){
            std::cout << "ERROR!##! INVALID ENTRY!##! ONLY ENTER 'X' OR 'O'!!!!\n";
        }

    }while(PMark != 'X' && PMark != 'O');

    if(PMark == 'X'){
        CMark = 'O';
    }else{
        CMark = 'X';
    }

    return std::make_pair(PMark,CMark);
}
bool EnteringMarkComputer(std::string B[9][9], char x,int &E){
    bool flag = 0;
    int ComputerPosition = (rand() %9) +1;
    do{
            switch(ComputerPosition){
                case 1:
                    if(B[1][1] != "X" && B[1][1] != "O"){
                        B[1][1] = x;
                        flag = 1;
                        E--;
                        break;
                    }
                    break;
                case 2:
                    if(B[1][5] != "X" && B[1][5] != "O"){
                        B[1][5] = x;
                        flag = 1;
                        E--;
                        break;
                    }
                    break;
                case 3:
                    if(B[1][8] != "X" && B[1][8] != "O"){
                        B[1][8] = x;
                        flag = 1;
                        E--;
                        break;
                    }
                    break;
                case 4:
                    if(B[4][1] != "X" && B[4][1] != "O"){
                        B[4][1] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
                case 5:
                    if(B[4][5] != "X" && B[4][5] != "O"){
                        B[4][5] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
                case 6:
                    if(B[4][8] != "X" && B[4][8] != "O"){
                        B[4][8] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
                case 7:
                    if(B[7][1] != "X" && B[7][1] != "O"){
                        B[7][1] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
                case 8:
                    if(B[7][5] != "X" && B[7][5] != "O"){
                        B[7][5] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
                case 9:
                    if(B[7][8] != "X" && B[7][8] != "O"){
                        B[7][8] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
        }




        if(flag == 0){
            ComputerPosition = (rand() %9) +1;
        }
    }while(flag == 0);

    return flag;
}
bool EnteringMarkPlayer(std::string B[9][9], char x,int &E){
    bool flag = 0;
    int PlayerPosition=0;
    do{
        std::cout << "PLEASE ENTER WHERE YOU WOULD LIKE TO PLACE YOUR MARKER!:(1-9)\n";
        std::cin >> PlayerPosition;
            if(PlayerPosition <=0 || PlayerPosition >9){
                std::cout << "INVALID ENTRY!! TRY AGAIN!!!\n";
            }
        }while(PlayerPosition<=0 || PlayerPosition >9);
    do{
            switch(PlayerPosition){
                case 1:
                    if(B[1][1] != "X" && B[1][1] != "O"){
                        B[1][1] = x;
                        flag = 1;
                        E--;
                        break;
                    }
                    break;
                case 2:
                    if(B[1][5] != "X" && B[1][5] != "O"){
                        B[1][5] = x;
                        flag = 1;
                        E--;
                        break;
                    }
                    break;
                case 3:
                    if(B[1][8] != "X" && B[1][8] != "O"){
                        B[1][8] = x;
                        flag = 1;
                        E--;
                        break;
                    }
                    break;
                case 4:
                    if(B[4][1] != "X" && B[4][1] != "O"){
                        B[4][1] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
                case 5:
                    if(B[4][5] != "X" && B[4][5] != "O"){
                        B[4][5] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
                case 6:
                    if(B[4][8] != "X" && B[4][8] != "O"){
                        B[4][8] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
                case 7:
                    if(B[7][1] != "X" && B[7][1] != "O"){
                        B[7][1] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
                case 8:
                    if(B[7][5] != "X" && B[7][5] != "O"){
                        B[7][5] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
                case 9:
                    if(B[7][8] != "X" && B[7][8] != "O"){
                        B[7][8] = x;
                        flag =1;
                        E--;
                        break;
                    }
                    break;
        }




        if(flag == 0){
            std::cout << "POSITION OCCUPIED AT: " << PlayerPosition << " CHOOSE ANOTHER!(1-9)\n";
            std::cin >> PlayerPosition;
        }
    }while(flag == 0);

    return flag;
}

bool CheckingWin(std::string B[9][9],char M){
    bool Won=0;
    std::string MARK;
    MARK+=M;
    if(B[1][1] == MARK && B[1][5] == MARK && B[1][8] == MARK){
        Won = 1;
    }else if(B[4][1] == MARK && B[4][5] == MARK && B[4][8] == MARK){
        Won = 1;
    }else if(B[7][1] == MARK && B[7][5] == MARK && B[7][8] == MARK){
        Won = 1;
    }else if(B[1][1] == MARK && B[4][5] == MARK && B[7][8] == MARK){
        Won = 1;
    }else if(B[7][1] == MARK && B[4][5] == MARK && B[1][8] == MARK){
        Won=1;
    }else if(B[1][1] == MARK && B[4][1] == MARK && B[7][1] == MARK){
        Won=1;
    }else if(B[1][5] == MARK && B[4][5] == MARK && B[7][5] == MARK){
        Won=1;
    }else if(B[1][8] == MARK && B[4][8] == MARK && B[7][8] == MARK){
        Won=1;
    }
    return Won;
}

void Game(std::string B[9][9],char P,char C){
    int EmptySpaces = 9;
    bool ComputerWin=0,PlayerWin=0;

    do{
        EnteringMarkPlayer(B,P,EmptySpaces);
       
        if(EmptySpaces >0){
            EnteringMarkComputer(B,C,EmptySpaces);
        }

        PrintBoard(B);
        PlayerWin = CheckingWin(B,P);
        ComputerWin = CheckingWin(B,C);
        if(PlayerWin){
            std::cout << "\n\n-------------PLAYER WON!-------------\n\n";
            break;
        }else if(ComputerWin){
            std::cout << "\n\n-------------COMPUTER WON!-------------\n\n";
            break;
        }
    }while(EmptySpaces>0);

    if(PlayerWin == 0 && ComputerWin == 0){
        std::cout << "WE HAVE A DRAW!\n";
    }

}
