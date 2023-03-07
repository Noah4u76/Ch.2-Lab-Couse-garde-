//
// File: main.cpp
// Description: Course Grade
// Created: Sun. Feb 26, 2023
// Author: Noah Sanderson
// mail: Noahs6423@student.vvc.edu
//
/*2.12 LAB: Course Grade
Write a program that reads the student information from a tab separated values (tsv) file. The program then creates a text file that records the course grades of the students. Each row of the tsv file contains the Last Name, First Name, Midterm1 score, Midterm2 score, and the Final score of a student. A sample of the student information is provided in StudentInfo.tsv. Assume the number of students is at least 1 and at most 20. Assume also the last names and first names do not contain whitespaces.

The program performs the following tasks:

Read the file name of the tsv file from the user.
Open the tsv file and read the student information.
Compute the average exam score of each student.
Assign a letter grade to each student based on the average exam score in the following scale:
A: 90 =< x
B: 80 =< x < 90
C: 70 =< x < 80
D: 60 =< x < 70
F: x < 60
Compute the average of each exam.
Output the last names, first names, exam scores, and letter grades of the students into a text file named report.txt. Output one student per row and separate the values with a tab character.
Output the average of each exam, with two digits after the decimal point, at the end of report.txt. Hint: Use the setprecision manipulator to format the output.
Ex: If the input of the program is:

StudentInfo.tsv
and the contents of StudentInfo.tsv are:

Barrett    Edan    70  45  59
Bradshaw    Reagan  96  97  88
Charlton    Caius   73  94  80
Mayo    Tyrese  88  61  36
Stern    Brenda  90  86  45
the file report.txt should contain:

Barrett    Edan    70  45  59  F
Bradshaw    Reagan  96  97  88  A
Charlton    Caius   73  94  80  B
Mayo    Tyrese  88  61  36  D
Stern    Brenda  90  86  45  C

Averages: midterm1 83.40, midterm2 76.60, final 61.60 */

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using std::string;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;

char letterGrade(int avgScore){
  char grade;
  if (avgScore >= 90) {
    grade = 'A';
  } 
  else if (avgScore >= 80) {
    grade = 'B';
  } 
  else if (avgScore >= 70) {
    grade = 'C';
  } 
  else if (avgScore >= 60) {
    grade = 'D';
  } 
  else {
    grade = 'F';
  }
  return  grade;
}

int main() {
  ifstream inFS;
  ofstream outFS;
  string filename = "";
  string lastName = "";
  string firstName = "";
  int midterm1 = 0;
  int midterm2 = 0;
  int final = 0;
  double students = 0;
  int midtermTotal1 = 0;
  int midtermTotal2 = 0;
  int finalTotal = 0;
  double midterm1Avg = 0;
  double midterm2Avg = 0;
  double finalAvg = 0;
  double avgScore = 0;
  char grade;

  cin >> filename;
  inFS.open(filename);

  outFS.open("report.txt");

  while (inFS >> lastName >> firstName >> midterm1 >> midterm2 >> final) {
    
    avgScore = (midterm1 + midterm2 + final) / 3.0;
    grade = letterGrade(avgScore);
    midtermTotal1 += midterm1;
    midtermTotal2 += midterm2;
    finalTotal += final;
  
    outFS << lastName << "\t" << firstName << "\t";
    outFS << midterm1 << "\t" << midterm2 << "\t" << final;
    outFS << "\t" <<  grade << endl;

    students++;
    }
  inFS.close();

  midterm1Avg = (midtermTotal1 / students);
  midterm2Avg = (midtermTotal2 / students);
  finalAvg = (finalTotal / students);

  outFS << "\n" << "Averages: midterm1 " << std::fixed << std::setprecision(2); 
  outFS << midterm1Avg << ", midterm2 " << midterm2Avg << ", final " << finalAvg << endl;

  outFS.close();

  return 0;
}
