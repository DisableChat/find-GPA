//******************************************************************
//
//  File Name: inbetween.h
//
//  Author:    Wesley Ryder
//  Email:     wr140815@ohio.edu
//
//  Purpose:  to declare functions that are used in main to calculate
//			  students rankings based on gpa's and their names
//
//******************************************************************

#include "student.h"
#include <deque>
#include <iostream>
#include <cmath>
#include <vector>
#ifndef inbetween_h
#define inbetween_h
using std::vector;

//******************************************************************
//
//  Function:   vectorPartion
//
//  Purpose:    Calculates the right or left subvector of the orinal
//              vector that is passed
//
//  Parameters: list - the past vector that needs to be partioned
//              begin - the begining index location for partition
//              end - the ending index location for partition
//
//******************************************************************
vector <Student> vectorPartition(vector<Student> list, int begin, int end);

//******************************************************************
//
//  Function:   inbetweenGpa
//
//  Purpose:   Calculates the gpa of students in order of
//             of a given range
//
//  Parameters: list - the past vector that contains the students
//              j - the begining index location for student range
//              k - the ending index location for student range
//              num_compares - number of comparisons made
//
//******************************************************************
vector <Student> inbetweenGPA(vector <Student> list,
                              	const size_t j,
                              	const size_t k,
                              	size_t &num_compares);

//******************************************************************
//
//  Function:   selectGpa
//
//  Purpose:   Returns a student at a certain index as if the vector
//             was in order.
//
//  Parameters: list - the vector that contains the students
//              index - the target index
//              num_compares - number of comparisons made
//
//******************************************************************
Student selectGpa(vector <Student> list, int index, size_t &num_compares);

//******************************************************************
//
//  Function:   inbetweenAlpha
//
//  Purpose:   Calculates the alphibetical names of students of
//             of a given range
//
//  Parameters: list - the past vector that contains the students
//              j - the begining index location for student range
//              k - the ending index location for student range
//              num_compares - number of comparisons made
//
//******************************************************************
vector <Student> inbetweenAlpha(vector <Student> list,
								const size_t j,
                                const size_t k,
                                size_t &num_compares);

//******************************************************************
//
//  Function:   selectAlpha
//
//  Purpose:   Returns a student at a certain index as if the vector
//             was in order for names
//
//  Parameters: list - the vector that contains the students
//              index - the target index
//              num_compares - number of comparisons made
//
//******************************************************************
Student selectAlpha(vector <Student> list, int index, size_t &num_compares);

//******************************************************************
//
//  Function:   medianOfMedians
//
//  Purpose:   Calculates the median of medians of a vector
//
//  Parameters: list - which is a passed list of students
//              num_compares - number of comparisons
//
//******************************************************************
Student medianOfMedians(vector<Student> list, size_t &num_compares);

//******************************************************************
//
//  Function:   compareGpa
//
//  Purpose:   Calculates which student is greater than the other in
//             terms of gpa. But returns a bool of the comparison
//
//  Parameters: first and second both of which are of type Student
//
//******************************************************************
bool compareGpa(Student first, Student second);

//******************************************************************
//
//  Function:   compareName
//
//  Purpose:   Calculates which student is greater than the other in
//             terms of their name. But returns a bool of the comparison
//
//  Parameters: first and second both of which are of type Student
//
//******************************************************************
bool compareName(Student first, Student second);

#endif
