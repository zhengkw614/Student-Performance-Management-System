# Student Performance Management System

[中文](README.md) | [English](README_EN.md)

## Experiment Objectives:
1. Master basic programming algorithms and simple data structure fundamentals; be able to comprehensively apply basic control statements, algorithms, and data structures, as well as top-down, stepwise refinement modular design methods; be capable of designing system-level C language programs of a certain scale to improve system programming skills.
2. For complex engineering problems related to computation, be able to use appropriate algorithms and data structures to complete the construction, testing, and implementation of software systems related to calculation, statistics, sorting, retrieval, matching, etc.

## Experiment Requirements:
1. Master common program debugging and testing methods.
2. Adopt top-down, stepwise refinement modular design thinking to design a simple grade management system.
3. The report requires an explanation of what data structures and algorithms were adopted, why this data structure or algorithm was chosen (system design description), what problems were encountered during system implementation and how they were resolved, what problems remain unresolved, what aspects are planned for future improvement, what are the highlights and difficulties of this design, experimental results, and gains and learning experiences (major assignment reflection).
4. Write a program to complete the following experiment (major assignment) content and complete the experiment report.

## Experiment Content:
A class has a maximum of 30 students (the exact number depends on actual input) taking the final exam, with a maximum of 6 subjects (the exact number depends on actual input). The student performance management system is a very practical program. If you can learn character file read/write operations in advance, saving user-input data as character files and reading them back on the next run makes it even more useful. That is, program and implement the following menu-driven student performance management system:

Enter student ID, name, and exam scores for each subject:
1. Calculate the total score and average score of each course.
2. Calculate the total score and average score of each student.
3. Rank students in descending order by total score.
4. Rank students in ascending order by total score.
5. Rank students in ascending order by student ID.
6. Rank students in dictionary order by name.
7. Search for a student's ranking and exam scores by student ID.
8. Search for a student's ranking and exam scores by name.
9. For each course, count the number of students and the percentage in each of the five categories: Excellent (90-100), Good (80-89), Medium (70-79), Pass (60-69), Fail (0-59).
10. Output each student's ID, name, exam scores for each subject, as well as the total score and average score of each course.
11. Write each student's record information to a file (optional implementation).
12. Read each student's record information from a file and display it (optional implementation).

The program should first display the following menu after inputting the number of courses and all course names, and prompt the user to enter an option:
> 1. Input record  
> 2. Calculate total and average score of every course  
> 3. Calculate total and average score of every student  
> 4. Sort in descending order by total score of every student  
> 5. Sort in ascending order by total score of every student  
> 6. Sort in ascending order by number  
> 7. Sort in dictionary order by name  
> 8. Search by number  
> 9. Search by name  
> 10. Statistic analysis for every course  
> 11. List record  
> 12. Write to a file  
> 13. Read from a file  
> 0. Exit  
> Please enter your choice:  

*Note: Since the data input volume is relatively large and file operations have not yet been systematically studied by students at this stage of the experiment (major assignment), in the case where menu items 12 and 13 are not implemented, it is recommended to provide 6-10 students' data in the source code using array element initialization to facilitate program debugging:*
*a. Use string arrays (character pointer arrays) initialized with element values for m course names;*
*b. Use array element initialization in the source code to provide all information for 6-10 students, each student's information including name, student ID, and scores for m courses (e.g., array length 30, initialize the first 10 element values when defining the array);*
*c. When the program runs, after selecting the first menu item to input a student's scores, the number of students increases by 1;*
*d. If a linked list is chosen to implement student information storage, the program should first copy the initialized array elements to the linked list for chained storage, then start the menu.*
