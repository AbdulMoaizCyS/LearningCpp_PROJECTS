#include "Student.h"
#include "Course.h"
#include <vector>
#include <iostream>
#include <string>

Student::Student(std::string n,std::string id){
    Name=n;
    StudentID=id;
    CGPA=0.00;
}

void Student::AddCourse(const Course &c){
    Subjects.push_back(c);
}
double Student::CalculateCGPA(){
    double TotalCreditHours=0;
    double TotalGradePoints=0;

    
        for(auto i=Subjects.begin();i<Subjects.end();i++){
            TotalCreditHours+=(*i).GetCreditHours();
            TotalGradePoints+=(*i).GetGradePoint();
        }
    if(TotalCreditHours!=0){
        CGPA = TotalGradePoints/double(TotalCreditHours);
    }else{
        CGPA =0.00;
    }

    return CGPA;

}

std::string Student::GetStudentName(){
    return Name;
}
std::string Student::GetStudentID(){
    return StudentID;
}
std::vector<Course> Student::GetStudentSubjects(){
    return Subjects;
}
double Student::GetStudentCGPA(){
    return CGPA;
}


void Student::DisplayStudent() const{
    std::cout << "||----SUMMARY----||\n";
    std::cout << "STUDENT NAME: " << Name<<'\n';
    std::cout << "STUDENT ID: " << StudentID<<'\n';
    std::cout << "CGPA: " << CGPA<<'\n';

    for(auto i=Subjects.begin();i<Subjects.end();i++){
        std::cout << (*i).GetCourseName() << ' ' << (*i).GetGradePoint() << ' ' << (*i).GetCreditHours() <<'\n';
    }

}

 
