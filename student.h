#ifndef student_h
#define student_h
#include <string>

using std::string;



//******************************************************************
//                                                                  
//  Class: Student
//                                                                  
//  Purpose:  To allow programmer to use a type of student which holds
//			  a students info, that info being SSN, First name, last
//			  name, major and gpa.
//            
//******************************************************************
class Student {
public:
    string SSN;
    string first_name;
    string last_name;
    string major;
    float  gpa;
};

#endif

