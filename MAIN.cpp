#include "Course.h"
#include "Student.h"
#include "StudentManager.h"
#include <iostream>
#include <vector>
#include <string>

void StudentMenu(StudentManager &manager);
void StudentManagerMenu(StudentManager &manager);





int main(){

    StudentManager Manager;
    int Choice;
    

    do{
        std::cout << "----STUDENT MANAGEMENT SYSTEM----\n";
        std::cout << "----PRESS 1 TO GO TO THE STUDENT MENU!\n";
        std::cout << "----PRESS 2 TO GO TO THE STUDENT MANAGER MENU!\n";
        std::cout << "----PRESS -1 TO EXIT THE PROGRAM!\n";
        std::cout << "--------------------------------------------\n";
        std::cin >> Choice;

        switch(Choice){
            case 1:
                StudentMenu(Manager);
                break;
            case 2:
                StudentManagerMenu(Manager);
                break;
            case -1:
                std::cout << "----'-1' DETECTED! EXITING PROGRAM!\n";
                break;
        }
        if(Choice == -1){
            break;
        }


    }while(1);



    return 0;
}

void StudentManagerMenu(StudentManager &manager){

    std::string name,id;
    std::string choice;
    std::string FilePath;
    std::cout << "----WELCOME TO STUDENT MANAGER MENU----\n";
    do{
    std::cout << "----ENTER '1' FOR NEW ENTRIES!\n----ENTER '2' TO DISPLAY ALL CURRENT STUDENTS!\n----ENTER '3' TO SAVE ALL DATA IN A FILE!\n----ENRER '-1' TO EXIT MANAGER MENU!\n";
    std::cin >> choice;

    if(choice == "1"){
        do{
            //std::cin >> std::ws;
            std::cout << "----IF YOU WISH TO STOP ADDING STUDENTS! ENTER '-1' TO GO BACK TO MAIN!\n";
            std::cout << "----ENTER STUDENT ID!\n";
            std::cin >> id;
            if(id == "-1"){
                std::cout << "----'-1' DETECTED! EXITING STUDENT MENU!\n";
                break;
            }
            std::cout << "----PLEASE ENTER STUDENT NAME!\n";
            std::cin >> std::ws;
            std::getline(std::cin, name);

            Student s(name,id);
            manager.addStudent(s);
            std::cout << "----Student Added!\n";
        }while(1);

        }else if(choice == "2"){
            manager.DisplayAllStudents();
        }else if(choice == "3"){
            std::cout << "----PLEASE ENTER A FILE PATH!\n";
            std::cin >> FilePath;
            manager.SaveToFile(FilePath);
        }else if(choice == "-1"){
            std::cout << "----EXITING STUDENT MANAGER MENU!\n";
            break;
        }
        else{
            std::cout << "----INVAID INPUT!!\n";
        }
    }while(1);

}

void StudentMenu(StudentManager &manager){
    std::string studentid,studentname;
    std::string mainchoice,subchoice;
    std::string coursename;double marks;int credithours;

    do{
        std::cout << "----WELCOME TO THE STUDENT MENU!----\n";
        std::cout << "----ENTER 1 TO PERFORM ACTIONS ON AN EXISTING ENTRY!\n----YOU CAN ENTER -1 TO EXIT THE STUDENT MENU!\n";
        std::cin >> mainchoice;
        if(mainchoice=="-1"){
            std::cout << "----EXITING STUDENT MENU!\n";
            break;
        }
        else if( mainchoice== "1"){
            std::cout << "----PLEASE ENTER EXISTING STUDENT ID!\n";
            std::cin >> studentid;
            Student* ptr = manager.FindStudentByID(studentid);
            if(ptr == nullptr){
                std::cout << "----STUDENT NOT FOUND!\n";
            }else{

                std::cout << "----WHAT ACTION WOULD YOU LIKE TO PERFORM ON THE STUDENT INSTANCE?:----\n";
                do{
                    std::cout << "----ENTER 1 TO ASSIGN A COURSE TO THIS STUDENT!\n----ENTER 2 TO DISPLAY STUDENT DATA!\n----ENTER 3 TO CALCULATE STUDENT CGPA!\n----ENTER '-1' TO EXIT!\n";
                    std::cin >> subchoice;
                        if(subchoice == "1"){
                            std::cout << "----PLEASE ENTER COURSE NAME!\n";
                            std::cin>>std::ws;
                            std::getline(std::cin,coursename);
                            std::cout << "----PLEASE ENTER MARKS OBTAINED BY STUDENT IN THIS COURSE!\n";
                            std::cin >> marks;
                            std::cout << "----PLEASE ENTER CREDIT HOURS OF THIS COURSE!\n";
                            std::cin >> credithours;

                        Course c(coursename,marks,credithours);
                        c.CalculateGradePoint();
                        (*ptr).AddCourse(c);
                        (*ptr).CalculateCGPA();
                    }else if(subchoice == "2"){
                        (*ptr).DisplayStudent();
                    }else if(subchoice == "3"){
                        std::cout << "CURRENT CGPA OF: " << (*ptr).GetStudentID() <<" "<< (*ptr).CalculateCGPA() <<'\n';
                    }else if(subchoice == "-1"){
                        break;
                    }else{
                        std::cout << "----INVALID INPUT!\n";
                    }
                }while(1);
            }

        }else{
            std::cout << "----INVALID INPUT!\n";
        }

    }while(1);

}