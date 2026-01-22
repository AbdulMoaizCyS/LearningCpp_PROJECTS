#include <iostream>
#include <utility>
#include <string>


struct Credentials{
    std::string Name;
    std::string RegNum;
    double CGPA;
    double SGPA;
};

struct GRADES{
    std::string CourseName;
    int Grade;
    int CourseCredits;
};

std::pair<double , double> GpaCalculator(GRADES X[],double CGPA,int Num){

    double Earned=0.0;
    double sgpa=0.0;
    double cgpa=0.0;
    double Temp=0.0;
    int TotalCredits=0;
    int OldCredits=0;
    int NewCredits=0;

    for(int i=0;i<Num;i++){
        double Temp=0.0;
        switch(X[i].Grade){
            case 1:
                Temp = 4.00 * X[i].CourseCredits;
                break;
            case 2:
                Temp = 3.67 * X[i].CourseCredits;
                break;
            case 3:
                Temp = 3.33*X[i].CourseCredits;
                break;
            case 4:
                Temp = 3.00*X[i].CourseCredits;
                break;
            case 5:
                Temp = 2.67*X[i].CourseCredits;
                break;
            case 6:
                Temp = 2.33*X[i].CourseCredits;
                break;
            case 7:
                Temp = 2.00*X[i].CourseCredits;
                break;
            case 8:
                Temp = 1.67*X[i].CourseCredits;
                break;
            case 9:
                Temp = 1.33*X[i].CourseCredits;
                break;
            case -1:
                Temp = 1.00*X[i].CourseCredits;
                break;
            case -2:
                Temp = 0;
                break;
        }
        Earned+=Temp;
    }


    for(int j=0;j<Num;j++){
        TotalCredits+=X[j].CourseCredits;
    }

    sgpa = (Earned)/double(TotalCredits);

    if(CGPA == 0){
        cgpa = sgpa;
    }else{
        std::cout << "HOW MANY CREDITS HAVE YOU EARNED?!:(ENTER A POSITIVE INTEGER)\n";
        std::cin >> OldCredits;
        NewCredits=OldCredits+TotalCredits;
        cgpa = ((CGPA*OldCredits) + (sgpa*TotalCredits))/double(NewCredits);
        }

        return std::make_pair(cgpa,sgpa);
}

int main(){

    int NoCourses=0;
    Credentials Student;

    std::cout << "-----WELCOME TO OUR GPA CALCULATOR!:-----\n";
    std::cout << "PLEASE START BY ENTERING YOUR NAME AND REG NUMBER!:\n";
    std::getline(std::cin,Student.Name);
    std::getline(std::cin, Student.RegNum);

    
    do{
        std::cout << "IF YOU ARE NOT A 1ST SEMESTER STUDENT ETNER YOUR CGPA OTHERWISE ENTER 0!:\n";
        std::cin >> Student.CGPA;
        if((Student.CGPA <0.00 || Student.CGPA >4.00)){
            std::cout << "INVALID ENTRY!!!! TRY AGAIN!!!!\n";
        }
    }while(Student.CGPA <0.00 || Student.CGPA >4.00);

    
    do{
        std::cout << "HOW MANY COURSES DID YOU TAKE THIS SEMESTER?!ENTER A INTEGER:\n";
        std::cin >> NoCourses;
        if(NoCourses <=0 || NoCourses>15){
            std::cout << "INVALID ENTRY!!! TRY AGAIN!!!!\n";
        }

    }while(NoCourses <=0 || NoCourses>15);

    GRADES* Array = new GRADES[NoCourses];

    for(int i=0;i<NoCourses;i++){
        int x=i+1;

        std::cout << "ENTER DETAILS FOR COURSE: " << x << '\n';

        std::cout << "ENTER COURSE NAME: \n";
        std::cin >> Array[i].CourseName;

        do{

            std::cout << "ENTER COURSE GRADE: \nPRESS 1 FOR 'A'\nPRESS 2 FOR 'A-'\nPRESS 3 FOR 'B+'\nPRESS 4 FOR 'B'\n";
            std::cout << "PRESS 5 FOR 'B-'\nPRESS 6 FOR 'C+'\nPRESS 7 FOR 'C'\nPRESS 8 'C-'\nPRESS 9 FOR 'D+'\nPRESS -1 FOR 'D'\n";
            std::cout << "PRESS -2 FOR 'F'\n";
            std::cin >> Array[i].Grade;

            if((Array[i].Grade < 1 || Array[i].Grade > 9) &&(Array[i].Grade != -1) && (Array[i].Grade != -2)){
                std::cout << "INVALID ENTRY!!!! TRY AGAIN!!!!!\n";
            }
        }while((Array[i].Grade < 1 || Array[i].Grade > 9) &&(Array[i].Grade != -1) && (Array[i].Grade != -2));

        do{
            std::cout << "ENTER COURSE CREDIT HOURS!: \n";
            std::cin >> Array[i].CourseCredits;
            if(Array[i].CourseCredits <= 0 || Array[i].CourseCredits >4){
                std::cout << "INVALID ENTRY!!!! TRY AGAIN!!!!!\n";
            }
        }while(Array[i].CourseCredits <= 0 || Array[i].CourseCredits >4);
    }
    
    std::pair<double,double> result = GpaCalculator(Array,Student.CGPA,NoCourses);

    Student.CGPA = result.first;
    Student.SGPA = result.second;

    std::cout << "---------------------------------\n";
    std::cout << " | "<< Student.Name << "\n";
    std::cout << " | " << Student.RegNum << "\n";
    std::cout << " | CODE" << "        " << "GRADE" << "     " << "CH\n";

    for(int z=0;z<NoCourses;z++){
        std::cout << " | " <<Array[z].CourseName ;
        
        switch(Array[z].Grade){
            case 1:
                std::cout << "        ";
                std::cout << "A";
                break;
            case 2:
                std::cout << "        ";
                std::cout << "A-";
                break;
            case 3:
                std::cout << "        ";
                std::cout << "B+";
                break;
            case 4:
                std::cout << "        ";
                std::cout << "B";
                break;
            case 5:
                std::cout << "        ";
                std::cout << "B-";
                break;
            case 6:
                std::cout <<  "        ";
                std::cout << "C+";
                break;
            case 7:
                std::cout <<  "        ";
                std::cout << "C";
                break;
            case 8:
                std::cout <<  "        ";
                std::cout << "C-";
                break;
            case 9:
                std::cout << "        ";
                std::cout << "D+";
                break;
            case -1:
                std::cout << "        ";
                std::cout << "D";
                break;
            case -2:
                std::cout << "        ";
                std::cout << "F";
        }
        std::cout << '\t' << Array[z].CourseCredits <<"\n";
    }

    std::cout << " | STUDENT CGPA: " <<  Student.CGPA << '\n' << " | STUDENT SGPA: "<< Student.SGPA << "\n";
    std::cout << "---------------------------------\n";

    delete[] Array;
    Array = nullptr;
    //std::cout << "YOUR CGPA: " << Student.CGPA << std::endl;
    //std::cout << "YOUR SGPA: " << Student.SGPA << std::endl;

    return 0;
}
