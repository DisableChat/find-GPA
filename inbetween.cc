//*******************************************************************
//
//	File Name: inbetween.cc
//
//  Author:      Wesley Ryder
//  Email:       wr140815@ohio.edu 
//               wr140815
//
//  Description: ibetween.cc is the implmentation file of inbetween.h
//               where inbetween.cc has the two main functions
//               inbetweenGPA and inbetweenAlpha where it finds
//               the highest gpa's based on a range of the vector.
//               It also does the same thing but for names when
//               inbetweenAlpha is called.
//
//  Date:        8-24-18
//
//*******************************************************************

#include "inbetween.h"
#include <vector>
#include <deque>
using namespace std;

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
vector <Student> vectorPartition(vector<Student> list, int begin, int end){
    vector <Student> tmp;
    // If it is size of 1
    if(begin == end)
    {
    	tmp.push_back(list[begin]);
    }
    // Else we have to loop through from the begining and end points
    else
    {
    	for(int j = begin; j <= end; ++j)
    	{
            // push to the end of vector the student at that current index
    		tmp.push_back(list[j]);
    	}
    }
    return tmp;
}


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
vector <Student> inbetweenGPA(vector <Student> list, const size_t j, const size_t k, size_t &num_compares){
    // If the list has no students case
    if(list.empty())
    {
    	cout << "Student List is empty!" << endl;
    }

  	// If the list has one student case
    else if(list.size() == 1){return list;}

    // Not the two above cases then we make new vector is made
    else{
        vector<Student> tmp;
        for(int i = j; i <= k; ++i)
        {
            tmp.push_back(selectGpa(list, i, num_compares));
        }
        return tmp;
    }
}

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
Student selectGpa(vector <Student> list, int index, size_t &num_compares){
    // Return List[0] if list.size() is only one element
    if(list.size() == 1){return list[0];}

    else{
	   	// Using deque of type student so that way we are able to insert items to the left
    	// and the right of a pivot
        deque <Student> tmp;
        // Pivot Index in the new list
        int pivIndex = 0;
    	// Creating size because we need the size of list before we begin mainpulating
        int size = list.size();

        // Pivot is set to the median of medians, so the selectGpa function can pivot better
        // and amount of elements of both the right and left side.
        Student pivot = medianOfMedians(list, num_compares);

        // Push the student that is pivot into the deque
        tmp.push_back(pivot);

        // Loop to push values less of pivot to the left and values greater to the right
        for(int i = size - 1; i >= 0 ; --i)
        {

            // Keeps the pivot from being dublicated
            if(pivot.gpa == list[i].gpa && pivot.last_name == list[i].last_name && pivot.SSN == list[i].SSN){}

            // If the gpa at the pivot is greater than the gpa at list[i], then we push the student of list[i]
            // to the front of the deque. This causes the pivot index value to shift right so we increment the pivIndex
            else if(compareGpa(pivot,list[i])){
                tmp.push_front(list[i]);
                num_compares++;
                pivIndex++;
            }
            // Else this means the student is greater than the pivot so its pushed to the back of deque
            else
            {
            	tmp.push_back(list[i]);
            }

            // Since the fuction is pass by value we pop off values from original list
            list.pop_back();
        }
        // Using for-loop to refill the original vector with the newly created list
        for(int k = 0; k < size; ++k)
       	{
        	list.push_back(tmp[k]);
    	}

    	// Now we have to recursivly call selectGpa on the left or right sublist of the vector if
    	// the index does not equal the pivotIndex because that means we have not found the what we
    	// were looking for

        // If the index is less than the pivot index, then we call the selectGpa recursivly on
        // the vector to the left of the pivot in this case
        if (index < pivIndex)
       	{
        	return(selectGpa(vectorPartition(list, 0, pivIndex - 1),
        			index,
        			num_compares));
       	}
        // Else if the index  is greater than pivIndex then we recursivly call selectGpa on
        // the the vector right of the pivot
        else if(index > pivIndex)
       	{
        	return(selectGpa(vectorPartition(list, pivIndex + 1, (list.size() - 1)),
        			(index - pivIndex - 1),
        			num_compares));
        }
        // if The index equals pivotIndex then we found what we were looking for
        else return(list[index]);
    }
}

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
vector <Student> inbetweenAlpha(vector <Student> list, const size_t j, const size_t k, size_t &num_compares){
    // If the list has no students case
    if(list.empty())
    {
     	cout << "Student List is empty!" << endl;
    }

    // If the list has one student case
    else if(list.size() == 1){return list;}

    // Not the two above cases then we make new vector is made
    else{
        vector<Student> new_list;
        for(int i = j; i <= k; i++)
        {
            new_list.push_back(selectAlpha(list, i, num_compares));
        }
        return new_list;
    }
}

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
Student selectAlpha(vector <Student> list, int index, size_t &num_compares){
    // Case if Vector is size one
    if(list.size() == 1){return list[0];}

    else{
      // Using deque of type student so that way we are able to insert items to the left
      // and the right of a pivot
      deque<Student> tmp;
      // Pivot Index in the new list
      int pivIndex = 0;
    	// Creating size because we need the size of list before we begin mainpulating
      int size = list.size();

      // Pivot is set to the median of medians, so the selectAlpha function can pivot better
      // and amount of elements of both the right and left side.
      Student pivot = medianOfMedians(list, num_compares);

        // Pushing the student that is pivot into the empty deque
        tmp.push_back(pivot);

        // Loop to push values less of pivot to the left and values greater to the right
        for(int i = size - 1; i >= 0; --i){

            // Prevents the pivot from duplicated
            if(pivot.gpa == list[i].gpa && pivot.last_name == list[i].last_name && pivot.SSN == list[i].SSN){}

            // If the gpa at the pivot is greater than the gpa at list[i], then we push the student of list[i]
            // to the front of the deque. This causes the pivot index value to shift right so we increment the pivIndex
            else if(compareName(pivot,list[i]))
            {
                tmp.push_front(list[i]);
                num_compares++;
                pivIndex++;
            }

            // Else this means the student is greater than the pivot so its pushed to the back of deque
            else
            {
              tmp.push_back(list[i]);
            }

            // Since the fuction is pass by value we pop off values from original list
            list.pop_back();
        }

        // Using for-loop to refill the original vector with the newly created list
        for(int i = 0; i < size; ++i)
        {
          list.push_back(tmp[i]);
        }

        // Now we have to recursivly call selectAlpha on the left or right sublist of the vector if
      	// the index does not equal the pivotIndex because that means we have not found the what we
      	// were looking for

        // If the index is less than the pivot index, then we call the selectAlpa recursivly on
        // the vector to the left of the pivot in this case
        if (index < pivIndex)
        {
          return(selectAlpha(vectorPartition(list, 0, pivIndex - 1),
                          index,
                          num_compares));
        }

        // Else if the index  is greater than pivIndex then we recursivly call selectAlpha on
        // the the vector right of the pivot
        else if(index > pivIndex)
        {
          return(selectAlpha(vectorPartition(list, pivIndex + 1, (list.size() - 1)),
                          (index-pivIndex - 1),
                          num_compares));
        }
        // if The index equals pivotIndex then we found what we were looking for
        else return(list[index]);
    }
}

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
Student medianOfMedians(vector<Student> list, size_t &num_compares)
{
    if(list.size()){return (list[0]);}
}

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
bool compareGpa(Student first, Student second)
{
    // comparing the first students gap to second students gpa. if bool
    // statmment is true then we know that first student greater than second
    // students gpa
    if(first.gpa > second.gpa)
    {
      return true;
    }
    // else the gpas are equal so we must now compare the first student to second
    // students last name
    else if(first.gpa==second.gpa)
    {
        return (first.last_name > second.last_name);
    }
    // else their last names are also eqaul so we now compare their first names
    else if(first.last_name == second.last_name)
    {
        return(first.first_name > second.first_name);
    }
    // if first names are equal then we just compare their SSN because everyone
    // has unique SSN's
    else if(first.first_name == second.first_name)
    {
        return(first.SSN > second.SSN);
    }
    else {return false;}
}

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
bool compareName(Student first, Student second)
{
    // compare the student first name to second student and if true return
    if(first.last_name > second.last_name)
    {
      return true;
    }
    // if theyre equal then you compare the firstnames of the students
    else if(first.last_name==second.last_name)
    {
      return(first.first_name > second.first_name);
    }
    // if their first names were same then compare their SSN and we know this
    // will return a which student is greater because you can't have matching
    // SSN's
    else if(first.first_name == second.first_name)
    {
      return(first.SSN > second.SSN);
    }
    else{return(false);}
}
