#include <iostream>
#include <vector>
#include <ctime>

void StoreHangman(std::vector<std::vector<std::string>> &VECTOR); //THIS FUNCTION TAKES A 2D VECTOR AND STORES DIFFERENT STAGES OF THE HANGMAN IN THE VECTOR 
void DisplayHangman(const std::vector<std::vector<std::string>>& VECTOR,int Stage); //THIS FUNCTIONS TAKES THE 2D VECTOR AND THE STAGE DURING GAME ACCORDING TO WHICH THE FIGURE WILL BE DISPLAYED
void ComputerHangman(const std::vector<std::vector<std::string>>& VECTOR); // GAME TO BE PLAYED USING COMPUTER
void UserHangman(const std::vector<std::vector<std::string>>& VECTOR); // GAME TO BE PLAYED BETWEEN USERS

int main(){
    std::string Choice;
    std::vector<std::vector<std::string>> HANGMAN; //A 2D VECTOR TO STORE DIFFERENT STAGES OF THE HANGMAN
    srand(time(nullptr)); //generate seed for radnom number
    StoreHangman(HANGMAN);
    do{
        std::cout << "====================\n";
        std::cout << "    HANGMAN GAME    \n";           //THIS HAGNMAN GAME CAN BE PLAYED TWO WAYS.
        std::cout << "====================\n";          //OPTION 1 IS WHERE THE COMPUTER WILL SELECT A SECRET WORD AND THE USER WILL GUESS AND OPTION 2 IS WHEN USER WILL ENTER A SECRET WORDS AND ANOTHER USER WILL GUESS.
        std::cout << "||====>ENTER '1' IF YOU WANT TO PLAY FROM A PRE-DEFINED WORD LIST!\n";
        std::cout << "||====>ENTER '2' IF YOU WANT TO ENTER A WORD YOURSELF AND SOME OTHER PERSON WILL GUESS!\n";
        std::cout << "||====>ENTER '-1' TO EXIT THE GAME!\n";
        std::cin >> Choice;

        if(Choice == "1"){
            ComputerHangman(HANGMAN);    //DIFFERENT CASES OF USER INPUT WILL LEAD TO DIFFERENT OUTCOMES
        }else if(Choice == "2"){
            UserHangman(HANGMAN);
        }else if(Choice == "-1"){
            std::cout << "||====>THANK YOU FOR PLAYING VADERS HANGMAN SIMULATOR!<====||\n";
        }else{
            std::cout << "||===>INCORRECT CHOICE!<===||\n";
        }

    }while(Choice != "-1");



    return 0;
}

void StoreHangman(std::vector<std::vector<std::string>> &VECTOR){
    VECTOR = { //A 2D VECTOR WHICH STORES VECTORS OF STRING WHICH STORE THE INDIVIDUAL STAGE DURING GAME-PLAY
        {        
            " +======+",
            " |      |",
            "        |",   //BEFORE START
            "        |",
            "        |",
            "       ---",
        },
        {        
            " +======+",
            " |      |",
            " 0      |",   //1ST WRONG GUESS
            "        |",
            "        |",
            "       ---",
        },
        {        
            " +======+",
            " |      |",
            " 0      |",   //2ND WRONG GUESS
            "/       |",
            "        |",
            "       ---",
        },
        {        
            " +======+",
            " |      |",
            " 0      |",   //3RD WRONG GUESS
            "/|      |",
            "        |",
            "       ---",
        },
        {        
            " +======+",
            " |      |",
            " 0      |",   //4TH WRONG GUESS
            "/|\\     |",
            "        |",
            "       ---",
        },
        {        
            " +======+",
            " |      |",
            " 0      |",   //5TH WRONG GEUSS
            "/|\\     |",
            "/       |",
            "       ---",
        },
        {        
            " +======+",
            " |      |",
            " 0      |",   //FINAL STAGE
            "/|\\     |",
            "/ \\     |",
            "       ---",
        }
    };
}

void DisplayHangman(const std::vector<std::vector<std::string>>& VECTOR,int Stage){
    if(Stage<0){
        Stage = 0;  //ENSURE NEGTAIVE NUMBERS ARE NOT INDEXED BELOW IN THE LOOP BELOW
    }else if(Stage>6){
        Stage = 6; //ENSURES NUMBERS OUTSIDE THE MAX SIZE OF VECTOR ARE NOT INDEXED IN THE LLOP BELOW
    }
    for(auto line: VECTOR[Stage]){
        std::cout << line << "\n";   //RANGE BASED FOR LOOP THAT ITERATES OVER EACH LINE OF A SPECIFIC STAGE(VECTOR) IN THE GNERAL "VECTOR"(2D VECTOR)
    }
}

void ComputerHangman(const std::vector<std::vector<std::string>>& VECTOR){
    std::string SecretWords[5] = {"secret","hangman","stages","frame","vector"}; //AN ARRAY OF STRING WHICH STORES SOME PRE-DEFINED SECRET WORDS
    std::string Word;//THE SECRET WORD THAT IS RANDOMLY PICKED BY COMPUTER!
    int ComputerPick = rand()%5;//RANDOM NUMBER GENERATION
    Word=SecretWords[ComputerPick];//RANDOM WORD SELECTION!
    int WrongGuesses=0,WordLength=Word.length();//WrongGuesses COUNTS HOW MANY INCORRECT INPUTS THE USER ENTERED AND WordLength IS USED TO STORE LENGTH OF SECRET WORD!
    char CorrectlyGuessed[WordLength],IncorrectlyGuessed[20];//TWO ARRAYS TO STORE USER INCORRECT AND CORRECT INPUTS!!!
    char UserGuess;//THIS STORES THE CHARACTER INUT BY USER WHICH IS THEIR GUESS;

    for(int i=0;i<WordLength;i++){
        CorrectlyGuessed[i] = '_'; //INITIALIZES THE CorrectlyGuessed TO ALL UNDERSCORES
        IncorrectlyGuessed[i] = ' ';//INTITIALIZES THE IncorrectlyGuessed TO ALL SPACES
    }

    bool flag=false;//THIS FLAG CHECKS IF USER INPUT APPEARED ANYWHERE INSIDE THE SECRET WORD!
    bool WinFlag=true;//THIS FLAG CHECKS IF USER GUESSED ALL CHARACTERS CORRECTLY!!!
    do{
        WinFlag=true;//RESET FALG EACH TIME LOOP IS RUN
        flag = false;//RESET FLAG EACH TIME LOOP IS RUN

        switch(ComputerPick){//GIVE USER HINTS SO THEY WON'T BE PLAYING BLIND!
        case 0:
            std::cout << "||HINT:What is hidden?||\n";
            break;
        case 1:
            std::cout << "||HINT:What can you see?||\n";
            break;
        case 2:
            std::cout << "||HINT:PARTS||\n";
            break;
        case 3:
            std::cout << "||HINT:THINGS CAN BE FIXED INSIDE IT!||\n";
            break;
        case 4:
            std::cout << "||HINT:AN ARRAY BUT BETTER!||\n";
            break;
    }

        DisplayHangman(VECTOR,WrongGuesses);//DISPLAY THE HANGMAN FIGURE DURING DIFFERENT STAGES

        for(int j=0;j<WordLength;j++){
            std::cout << CorrectlyGuessed[j]; //OUTPUTTING HOW MANY USER HAS GUESSED CORRECT!
        }
        std::cout  << "\t" << "INCORRECT GUESSES: ";
        for(int x=0;x<WordLength;x++){
            std::cout << IncorrectlyGuessed[x]; //OUTPUTTING HOW MANY THE USER GUESSED INCORRECTLY!
        }
        std::cout << std::endl;

        std::cout << "||====>PLEASE ENTER A CHARACTER!(YOU HAVE 6 WRONG GUESSES!!!)\n";
        std::cin >> UserGuess;
        for(int k=0;k<WordLength;k++){
            if(UserGuess == Word[k]){
                CorrectlyGuessed[k] = UserGuess;     //THIS LOOP CHECKS THE WHOLE WORD FOR ANY OCURRENCE OF USER INPUT AND IF FOUND ADDS THEM TO CorrectlyGuessed ARRAY!
                flag = true;
            }
        }
        if(flag == false){
            WrongGuesses++; //THIS AREA DEALS WITH INCORRECT USER INPUTS!
            IncorrectlyGuessed[WrongGuesses] = UserGuess;
        }
        for(int m=0;m<WordLength;m++){
            if(CorrectlyGuessed[m]=='_'){
                WinFlag=false;  //THIS PART CHECKS IF USER GUESSED ALL CHARACTERS CORRECTLY!
            }
        }
        if(WinFlag == true){
            std::cout << "||====>CONGRATULATIONS!!! YOU WON!!!!<====||\n";  //WIN CHECL
            break;
        }
        
    }while(WrongGuesses<6);

    if(WrongGuesses ==6){
        DisplayHangman(VECTOR,WrongGuesses);
        std::cout << "||====>YOU HAVE EXCEEDED THE LIMIT FOR GUESSES!<====||\n"; //LOSS CHECK!
    }


}

void UserHangman(const std::vector<std::vector<std::string>>& VECTOR){
    std::string SECRET_WORD, Hint;//SECRET_WORD is the word 1 user wants 2nd user to guess AND Hint is the hint 1 user will give 2nd user
    int Word_Length=0,IncorrectGuesses=0; //TO STORE SECRET_WORD LENGTH AND COUNT HOW MANY INCORRECT GUESSES USER MADE

    char UserInput;//USER GUESS

    std::cout << "||===>PLEASE ENTER YOUR SECRET WORD FOR OTHER PLAYER!<===||\n";
    std::cin >> SECRET_WORD;
    std::cout << "||===>PLEASE ENTER A HINT!<====||\n";
    std::getline(std::cin>>std::ws, Hint);

    Word_Length = SECRET_WORD.length();
    char Correct[Word_Length],Incorrect[50]; //ARRAYS TO STORE USERS CORRECT GUESSES AND INCORRECT GUESSES
    for(int i=0;i<Word_Length;i++){
        Correct[i] = '_';    //INITIALIZES THE ARRAYS
        Incorrect[i] = ' ';
    }

    bool flag=false,WinFlag=true;//flag TO CHECK EACH GUESS AND Flag TO CHECK WHOLE GAME PROGESS
    for(int p=0;p<100;p++){
        std::cout << std::endl; //ENSURES USER 2 DOESN'T SEE WHAT USER 1 ENTERED!
    }
    do{
        flag = false; 
        WinFlag = true;
        std::cout << Hint;
        std::cout << std::endl;
        DisplayHangman(VECTOR,IncorrectGuesses);
        for(int j=0;j<Word_Length;j++){
            std::cout << Correct[j];
        }
        std::cout << '\t' << "INCORRECT GUESSES!: ";
        for(int x=0;x<Word_Length;x++){
            std::cout << Incorrect[x];
        }
        std::cout <<std::endl;
        std::cout << "||====>PLEASE ENTER YOUR GUESS!:<====||\n";
        std::cin >> UserInput;

        for(int h=0;h<Word_Length;h++){
            if(UserInput == SECRET_WORD[h]){
                Correct[h] = UserInput;
                flag = true;
            }
        }
        if(flag == false){
            Incorrect[IncorrectGuesses] = UserInput;
            IncorrectGuesses++;
        }

        for(int s=0;s<Word_Length;s++){
            if(Correct[s]=='_'){
                WinFlag = false;
            }
        }

        if(WinFlag == true){
            std::cout << "||====>CONGRATULATIONS! YOU GUESSED THE WORD CORRECTLY!<====||\n";
            break;
        }

    }while(IncorrectGuesses<6);

    if(IncorrectGuesses == 6){
        DisplayHangman(VECTOR,IncorrectGuesses);
        std::cout << "||====>YOU HAVE EXCEDED THE LIMIT FOR INCORRECT GUESSES!<====||\n";
    }

}