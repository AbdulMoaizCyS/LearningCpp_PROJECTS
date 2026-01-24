#include <iostream>
#include "Course.h"

double Course::CalculateGradePoint(){

    if(marks>=90 && marks<=100){
        GradePoint = 4*CreditHours;
    }else if(marks>=80 && marks<90){
        GradePoint = 3.67*CreditHours;
    }else if(marks>=70 && marks<80){
        GradePoint = 3.33*CreditHours;
    }else if(marks>=60 && marks<70){
        GradePoint=3*CreditHours;
    }else if(marks >=50 && marks<60){
        GradePoint=2.67*CreditHours;
    }else if(marks >=40 && marks<50){
        GradePoint=2.33*CreditHours;
    }else if(marks>=30 && marks<40){
        GradePoint=2.00*CreditHours;
    }else if(marks>=20 && marks<30){
        GradePoint=1.67*CreditHours;
    }else{
        GradePoint=0;
    }
    
    return GradePoint;

}

Course::Course(std::string CName,double m,int CH){
    CourseName=CName;
    marks=m;
    CreditHours=CH;
    GradePoint=0.00;
}
void Course::SetCourseName(std::string name){
    CourseName=name;
}
void Course::SetCreditHours(int cred){
    CreditHours = cred;
}
void Course::SetMarks(double MARKS){
    marks=MARKS;
}

std::string Course::GetCourseName() const{
    return CourseName;
}
double Course::GetMarks() const{
    return marks;
}
int Course::GetCreditHours() const{
    return CreditHours;
}
double Course::GetGradePoint() const{
    return GradePoint;
}