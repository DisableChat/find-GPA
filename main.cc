//******************************************************************
//
//  File Name: main.cc
//
//  Author:      Wesley Ryder
//  Email:       wr140815@ohio.edu
//
//  Purpose:  to run the main of the program for testing
//
//******************************************************************


#include <iostream>     // cin, cout, dec, hex, oct, showbase
#include <cstdlib>      // EXIT_SUCCESS
#include <string>       // strings for descriptions
#include <sys/time.h>   // Timing
#include "student.h"
#include "inbetween.h"
using namespace std;

//*******************************************************************
//  Function: timeval2Sec
//    
//  Description: Computes the number of seconds from a timeval in 
//                 microseconds.
//*******************************************************************
double timeval2sec(const timeval& T) {
  // Constant for time unit conversion
  const double USEC_TO_SEC = 1000000.0;

  return ((double) T.tv_sec + (double) (T.tv_usec / USEC_TO_SEC));
}

//******************************************************************
// Function: timeofday
//  
// Description: Computes the time of day in seconds.
//    
// Side effects: Gets the time of day and stores it in T.
//
// return timeval2sec(T) The time of day in seconds.
//******************************************************************
double timeofday() {
  timeval T;
  gettimeofday(&T, NULL);
  return (timeval2sec(T));
}


//******************************************************************
//
//  Function:   createStudents
//
//  Purpose:   create a vector of randomized info students
//
//  Parameters: list - the past vector that contains the students
//							num - number of students you want created
//
//******************************************************************
void createStudents(vector<Student> &list, const size_t num);

//******************************************************************
//
//  Function:   printGPA
//
//  Purpose:   print the vector of students
//
//  Parameters: list - the past vector that contains the students
//
//******************************************************************
void printGPA(vector<Student> list);

//******************************************************************
//
//  Function:   random_string
//
//  Purpose:   create a random string of length that is specfied
//
//  Parameters: length - of string you want
//
//******************************************************************
string random_string(size_t length);


// Char array of possible letters that can be used
static const char alphanum[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

// Char array for the possible values that can be used in SSN
static const char alphanum2[] =
"0123456789";

// string Length used for randomized strings
int stringLength = sizeof(alphanum) - 1;

// string Length2 used for randomized strings
int stringLength2 = sizeof(alphanum2) - 1;

//******************************************************************
//
//  Function:   genRandom()
//
//  Purpose:   generate random char from alphibet
//
//  Parameters: none
//
//******************************************************************
char genRandom(){return alphanum[rand() % stringLength];}

//******************************************************************
//
//  Function:   genRandom2()
//
//  Purpose:   generate random char of 1-9
//
//  Parameters: none
//
//******************************************************************
char genRandom2(){return alphanum2[rand() % stringLength2];}

//******************************************************************
//
//  Function:   main
//
//  Purpose:   run the main of the program
//
//  Parameters: none
//
//******************************************************************
int main()
{
	srand(time(0));
  // tested this with multiple values 0-n
	const size_t num = 20;
	vector <Student> students;

    // tested this with multiple values
    const size_t j = 0;
    const size_t k = 19;
    size_t num_compares = 0;


    createStudents(students, num);

    // Show original list for name
    cout << "Original List For sort by GPA:" << endl;
    printGPA(students);

    cout << "New List(" << j << "," << k << ")\n";

    // starting time
    double start=timeofday();
    
    // Print the list based on gpa
    printGPA(inbetweenGPA(students, j, k, num_compares));
    // cout info for time and num of compars and inputsize
    cout << "inbetweenGPA took " << timeofday() - start << " seconds" << endl;;
    cout << "Number of Comparisons: " << num_compares << endl;
    cout << "on input size " << num << endl;
    
    // reset num_compares to 0
    num_compares = 0;
    // Show original list for name
    cout << "Original List For sort by NAME:" << endl;
    printGPA(students);
    
    // print new list in order of alpha
    cout << "New List Is Alpha(" << j << "," << k << ")\n";  
    //start new time
    start = timeofday();

    // print the list based on alpha
    printGPA(inbetweenAlpha(students, j, k, num_compares));
    // cout info for time and num of compars and inputsize
    cout << "inbetweenGPA took " << timeofday() - start << " seconds" << endl;
    cout << "Number of Comparisons: " << num_compares << endl;
    cout << "on input size " << num << endl;

    return EXIT_SUCCESS;
}


//******************************************************************
//
//  Function:   createStudents
//
//  Purpose:   create a vector of randomized info students
//
//  Parameters: list - the past vector that contains the students
//							num - number of students you want created
//
//******************************************************************
void createStudents(vector<Student> &list, const size_t num)
{
	for(int i = 0; i < num; ++i)
	{
		Student tmp;

		string first;
		for(int k = 0; k < 6; k++){
			tmp.first_name += genRandom();
		}
		//cout << tmp.first_name << " ";

		string last;
		for(int k = 0; k < 6; k++){
			tmp.last_name += genRandom();
		}
		//cout << tmp.last_name << endl;

		int ones = rand()%5;
        int tenths = rand()%10;
        int hundredths = rand()%9+1;
        float real_gpa = ones+((float)tenths/10)+((float)hundredths/100);
        tmp.gpa = real_gpa;
        //cout << tmp.gpa << endl;

        for(int k = 0; k <= 9; ++k){
        	tmp.SSN += genRandom2();
        }
        //cout << tmp.SSN << endl;
        list.push_back(tmp);
	}
}


//******************************************************************
//
//  Function:   printGPA
//
//  Purpose:   print the vector of students
//
//  Parameters: list - the past vector that contains the students
//
//******************************************************************
void printGPA(vector<Student> list)
{
	size_t size = list.size();

	cout << "index" << "\t GPA" << "   Last name" << "  First Name" <<  "\tSSN" << endl;
	cout << "------------------------------------------------------------------" << endl;
	for(int j = 0; j  < size; ++j)
	{
		cout << j << "\t|" << list[j].gpa <<
		" | "<< list[j].last_name << "   |  " << list[j].first_name <<
		"   | " << list[j].SSN << endl;
	}
}

