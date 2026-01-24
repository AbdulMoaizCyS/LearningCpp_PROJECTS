#include <iostream>
#include <vector>
#include <fstream>

#include "Student.h"
#include "StudentManager.h"

void StudentManager::addStudent(const Student &stdnt){
    Pupils.push_back(stdnt);
}

Student* StudentManager::FindStudentByID(const std::string id){
    Student* FoundStudent;
    bool flag = false;
    for(auto i=Pupils.begin();i<Pupils.end();i++){
        if((*i).GetStudentID() == id){
            FoundStudent=&(*i);
            flag = true;
            break;
        }
    }

    if(flag == false){
        FoundStudent = nullptr;
    }

    return FoundStudent;

}

void StudentManager::DisplayAllStudents() const{
    for(auto i=Pupils.begin();i<Pupils.end();i++){
        (*i).DisplayStudent();
    }
}

void StudentManager::SaveToFile(std::string path){
    std::vector<Course> sub;
    std::ofstream file(path);

    if(!file){
        std::cout << "ERROR!! INVALID PATH!!!\n";
    }else{


        for(auto i=Pupils.begin();i<Pupils.end();i++){
            file << (*i).GetStudentName()<<'\t';
            file << (*i).GetStudentID()<<'\n';
            sub=(*i).GetStudentSubjects();
            for(auto it=sub.begin();it<sub.end();it++){
                file << (*it).GetCourseName()<< ' ';
                file << (*it).GetCreditHours()<< ' ';
                file << (*it).GetGradePoint()<< ' ';
                file << (*it).GetMarks()<< '\n';
            }
            file << "||==========||\n";
        }

        file.close();
    }

}
