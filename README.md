# find-GPA
  A small program that returns a vector of students that are between the jth largest and kth largest, inclusive in the original vector       list. Without actually sorting the original vector.

## Objective
  ### Doing efficiently as possible(idea of this program is to do it in linear time)
    however I did my median of medians in correctly so it runs in 0(n^2) which is really bad.
    after I fix the median of medians it should be 0(n) runtime.
  
 ### The functions must return a vector of all the students that are between the jth largest
    and kth largest inclusive in vector list. j and k start at 0, and run to the size of list
    - 1. Your code must not modify the vector passed in.
   
   #### calling: inbetweenGpa(students, 0, 0, num_compares);
    returns a vecotr with one elmenent. the student with the lowest GPA.
    It must return a vector with one element, the student with the lowest GPA. 
    
  #### calling: inbtweenGpa(studnets, 99, 99, num_compares);
    returns with students containing 100 student records, it must return a vector
    with one element, the student with the highest GPA. 
    
  #### calling: inbetweenGpa(students, 0, 99, num_compares);
    returns a vector of 100 students whose GPAs are next lowest relative to the previous
    call to inbetweenGPA. (So if the list was 100 long then it would return the 100 students in order, lowest gpa to highest).

    
 #### calling: inbetweenAlpha(students, 0, 0, num_compares);
    does the same thing as inbetweenGpa but with names.
