#include <iostream>
#include <string>

bool AlphabetCheck(std::string pass);
bool NumberCheck(std::string passw);
bool SpecialCharactersCheck(std::string passwo);
bool RepeatingCharactersCheck(std::string pas);
bool LengthCheck(std::string pass);

int main(){

    std::string password;

    bool Flag0 = 0;
    bool Flag1 = 0;
    bool Flag2 = 0;
    bool Flag3 = 0;
    bool Flag4 = 0;

    
    std::cout << "ENTER YOUR PASSWORD!\nYOUR PASSWORD MUST BE MORE THAN 6 CHARACTERS!\n";
    std::cout << "IT SHOULD CONTAIN BOTH ALPHABETICAL AND NUMERIC CHARACTERS ASWELL AS SPECIAL CHARACTERS!\n";
    std::cout << "ALLOWED SPECIAL CHARACTERS ARE: '#' , '&' , '*' , '@' , '!' \n";
    std::cout << "NO REPEATING CHARACTERS ARE ALLOWED i.e NO TWO SAME CHARACTERS SHOULD BE NEXT TO EACH OTHER!\n";
    std::cin >> password;

    Flag0 = LengthCheck(password);
    Flag1 = AlphabetCheck(password);
    Flag2 = NumberCheck(password);
    Flag3 = SpecialCharactersCheck(password);
    Flag4 = RepeatingCharactersCheck(password);

    while(Flag0 == 0 || Flag1 == 0 || Flag2 == 0 || Flag3 == 0 || Flag4 == 1){
        if(Flag0 == 0){
            std::cout << "PASSOWRD IS TOO SHORT!MUST NOT BE LESS THAN 7 CHARACTERS!\n";
        }else if(Flag1 == 0){
            std::cout << "YOUR PASSWORD CONTAINS NO ALPHABETS!\n";
        }else if(Flag2 == 0){
            std::cout << "YOUR PASSWORD CONTAINS NO NUMBERS!\n";
        }else if(Flag3 == 0){
            std::cout << "YOUR PASSWORD CONTAINS NO SPECIAL CHARACTERS!\n";
        }else if(Flag4 == 1){
            std::cout << "YOUR PASSWORD CONTAINS REPEATING CHARACTERS!\n";
        }
        std::cout << "RE-INPUT A VALID PASSOWRD!\n";
        std::cin >> password;

        Flag0 = LengthCheck(password);
        Flag1 = AlphabetCheck(password);
        Flag2 = NumberCheck(password);
        Flag3 = SpecialCharactersCheck(password);
        Flag4 = RepeatingCharactersCheck(password);


    }

    if((Flag1 == 1 && Flag2 == 1 && Flag3 == 1 && Flag4 == 0)){
        std::cout << "STRONG PASSWORD SET SUCCESFULLY!\n";
    }


    return 0;
}

bool AlphabetCheck(std::string pass){

    bool Flag = 0;

    for(int i=0;i<pass.length();i++){
        if(pass[i] >= 'a' && pass[i] <= 'z'){
            Flag = 1;
            break;
        }
    }

    return Flag;
}

bool NumberCheck(std::string passw){
    bool flag =0;

    for(int x=0;x<passw.length();x++){
        if(passw[x] >= '0' && passw[x] <= '9'){
            flag = 1;
            break;
        }   
    }

    return flag;
}

bool SpecialCharactersCheck(std::string passwo){
    bool FLAG = 0;
    for(int j=0;j<passwo.length();j++){
        if(passwo[j]== '#' || passwo[j] == '&' || passwo[j] == '*' || passwo[j] == '@' || passwo[j] == '!'){
            FLAG = 1;
            break;
        }
    }

    return FLAG;
}

bool RepeatingCharactersCheck(std::string pas){
    bool flag =0;

    char* mainptr;
    char* ptr;

    mainptr = &pas[0];
    ptr = mainptr;

    char* behindptr;
    while(*ptr != '\0'){
        behindptr = ptr;
        ptr++;
        if(*ptr == '\0'){
            break;
        }

        if(*behindptr == *ptr){
            flag = 1;
            break;
        }
    }

    return flag;
}

bool LengthCheck(std::string pass){
    bool flag=0;

    if(pass.length() > 6){
        flag = 1;
    }

    return flag;
}