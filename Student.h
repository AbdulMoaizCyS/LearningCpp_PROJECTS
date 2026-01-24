#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include <vector>
#include <string>

class Student{
    private:
        std::string Name;
        std::string StudentID;
        std::vector<Course> Subjects;
        double CGPA;
    public:
        Student(std::string n,std::string id);
        void AddCourse(const Course &c);
        double CalculateCGPA();
        void DisplayStudent() const;
        std::string GetStudentID();
        std::string GetStudentName();
        std::vector<Course> GetStudentSubjects();
        double GetStudentCGPA();

};

#endif //STUDENT_H