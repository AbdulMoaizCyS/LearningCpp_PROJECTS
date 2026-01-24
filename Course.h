#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course{
    private:
        std::string CourseName;
        double marks;
        int CreditHours;
        double GradePoint;
    public:
        double CalculateGradePoint();
        Course(std::string CName,double m,int CH);
        void SetCourseName(std::string name);
        void SetMarks(double MARKS);
        void SetCreditHours(int cred);
        std::string GetCourseName() const;
        double GetMarks() const;
        int GetCreditHours() const;
        double GetGradePoint() const;
        

};


#endif //COURSE_H