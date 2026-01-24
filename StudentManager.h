#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include "Course.h"
#include <vector>
#include <string>


class StudentManager{
    private:
        std::vector<Student> Pupils;

    public:
        void addStudent(const Student &stdnt);
        Student* FindStudentByID(const std::string id);
        void DisplayAllStudents() const;
        void SaveToFile(std::string path);
        //void LoadFromFile(std::string path);

};




#endif //STUDENT_MANAGER_H