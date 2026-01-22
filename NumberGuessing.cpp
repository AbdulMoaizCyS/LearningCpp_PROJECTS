#include <iostream>
#include <string>
#include <ctime>
#include <limits>

class Player{
    private:
        std::string Name;
        int Number=0;
        double Pouch=0.00;
        double Bet=0.00;
        double Won=0.00;
        double Lost=0.00;
    public:
        std::string getName(){
            return Name;
        }
        int getNumber(){
            return Number;
        }
        double getPouch(){
            return Pouch;
        }
        double getBet(){
            return Bet;
        }
        double getWon(){
            return Won;
        }
        double getLost(){
            return Lost;
        }

        void setName(){
            std::string name;
            std::cin >> std::ws;
            std::getline(std::cin , name);
            Name = name;
        }
        void setNumber(){
            int num=0;
            std::cout << "----PLEASE ENTER THE NUMBER YOU WOULD LIKE TO BET ON!(1-10):----\n";
            do{
                if(std::cin >> num){
                    if(num<=0 || num>10){
                        std::cout << "----ERROR!!! INVALID ENTRY!!! TRY AGAIN!!!----\n";
                    }else{
                        break;
                    }
                }else{
                    std::cout << "----ERROR!!! INVALID ENTRY!!! TRY AGAIN!!!----\n";
                }
            }while((num<=0 || num>10) || std::cin.good());
            Number = num;
        }
        void setPouch(){
            double N=0.00;
            do{
                if(std::cin>>N){
                    if(N<=0.00){
                        std::cout << "----ERROR!!! INVALID ENTRY!!! TRY AGAIN!!!----\n";
                    }else{
                        break;
                    }
                }else{
                    std::cout << "----ERROR!!! INVALID ENTRY!!! TRY AGAIN!!!----\n";
                    std::cin.clear();
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }while(N<=0.00 || std::cin.good());
            Pouch+=N;
        }
        void setBet(){
            double B=0.00;
            std::cout << "----YOU CURRENTLY HAVE: " << Pouch << " $ IN YOUR ACCOUNT!----\n";
            std::cout << "----PLACE A BET!----\n";
            do{
                if(std::cin >> B){
                    if(B<=0.00 || B >Pouch){
                        std::cout << "----ERROR!!! INVALID ENTRY!!! TRY AGAIN!!!----\n";
                    }else if(B>Pouch){
                        std::cout << "----ERROR!!! BET HAS EXCEEDED YOUR POUCH LIMIT!!! TRY AGAIN!!!----\n";
                    }else{
                        break;
                    }
                }else{
                    std::cout << "----ERROR!!! INVALID ENTRY!!! TRY AGAIN!!!----\n";
                    std::cin.clear();
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }while((B<=0.00 || B>Pouch) || std::cin.good());
            Bet=B;
            //Pouch-=Bet;
        }
        void setWon(double W){
            Won+=W;
            Pouch+=W;
        }
        void setLost(double L){
            Lost+=L;
            Pouch-=L;
        }
};

class Casino{
    private:
        double Pool=1000.00;
        double Gained=0.00;
        double Given=0.00;
    public:
        double getPool(){
            return Pool;
        }
        double getGained(){
            return Gained;
        }
        double getGiven(){
            return Given;
        }
        void setGained(double m){
            Gained =m;
            Pool+=m;
        }
        void setGiven(double n){
            Given = n;
            Pool-=n;
        }
};

class Guesser{
    private:
        int NUMBER=0;
    public:
        int GetNumber(){
            NUMBER = (rand() %10)+1;
            return NUMBER;
        }
};

void Summary(Player &P,Casino &C,Guesser &G){

    std::cout << "----GAME SUMMARY!----\n";
    std::cout << "| THE TOTAL AMMOUNT IN THE POOL IS: " << C.getPool()<<"$\n";
    std::cout << "| THE TOTAL AMMOUNT GAINED BY THE CASINO IS: " << C.getGained() << "$\n";
    std::cout << "| THE TOTAL AMMOUNT DISTRIBUTED AS WININGS BY THE CASINO  IS: " << C.getGiven() << "$\n";

    std::cout << "| "<<P.getName() <<" CURRENTL HAVE: "<< P.getPouch() << " $ IN THEIR POUCH!\n";
    std::cout << "| " << P.getName() << " WON " << P.getWon() << "$ IN TOTAL!\n";
    std::cout << "| " << P.getName() << " LOST " << P.getLost() << " $ IN TOTAL!\n";
    std::cout << "----THANK YOU FOR PLAYING!----\n";

}

void Game(Player &p,Casino &c,Guesser &g){
    double w =0.0;
    double l=0.0;
    int Cho=0;
    int F=1;
    do{
        p.setBet();
                p.setNumber();
                int num =  g.GetNumber();
                if(p.getNumber() == num){
                    w = p.getBet()*10;
                    p.setWon(w);
                    c.setGiven(w);
                    std::cout << "----CONGRATULATIONS! THE DICE HAS LANDED ON: " << num << " AND YOU HAVE WON!: ";
                    std::cout << w << " $!----\n";
                }else{
                    l = p.getBet()/2.00;
                    p.setLost(l);
                    c.setGained(l);
                    std::cout << "----BETTER LUCK NEXT TIME! THE DICE LANDED ON: " << num << " AND YOU HAVE LOST!: ";
                    std::cout << l << " $!----\n";
                }
        std::cout << "----PRESS 0 TO END THE GAME!----\n";
        std::cin >> F;
        if(p.getPouch() <=0){
            std::cout << "----PLEASE ENTER 1 IF YOU WISH TO ADD MORE MONEY TO YOUR ACCOUNT!OTHERWISE ENTER ANY NUMBER TO EXIT!----\n";
            std::cin >> Cho;
            if(Cho==1){
                p.setPouch();
                continue;
            }else{
            Summary(p,c,g);
            break;}
        }else if(c.getPool()<=0){
            Summary(p,c,g);
            break;
        }
    }while(F!=0);
    Summary(p, c, g);
}

int main(){
    srand(time(nullptr));
    Player Gameplayer;
    Casino Management;
    Guesser Computer;
    int Choice1=-1;

    std::cout << "----WELCOME TO VADERS CASINO!----\n";
    std::cout << "----YOU ARE CURRENTLY PLAYING THE NUMBER GUESSER!----\n";
    std::cout << "----PLEASE ENTER YOUR NAME FOR FUTURE REFERENCE!----\n";
    Gameplayer.setName();

    std::cout << "----PLEASE ENTER HOW MUCH $ DO YOU WANT INITIALLY IN YOUR POUCH?:----\n";
    Gameplayer.setPouch();

    Game(Gameplayer,Management,Computer);
    
    
    //std::cout << "----THE CURRENT POOL IS: " << Management.getPool() << " $!----\n";
    
    
    return 0;
}