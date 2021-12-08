/*
NAME: Talike Bennett
HM4, Part 1, Main File
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "HM4_P1_Point.h"
#include "HM4_P1_Line.h"
using namespace std;

void PrintLines(Line& line1, Line& line2, Line& line3) {

    cout << "Line 1:" << endl;
    cout << line1 << endl;
    cout << "Line 2:" << endl;
    cout << line2 << endl;
    cout << "Line 3:" << endl;
    cout << line3;

}

void LoadLines(vector<Line>& Lines) {

    ifstream inFS;
    inFS.open("Lines.txt");

    if (!inFS.is_open()) {

        cout << "Could not open the file." << endl;
        return;

    }

    char d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16;
    double line1_p1x, line1_p1y, line1_p2x, line1_p2y;

    inFS >> d1 >> d2 >> d3 >> d4 >> d5 >> d6; //Parses "lines:"
    inFS >> d1; //Parses "{"

    while (!inFS.eof()) { //Parses each line that contains the values for every Line

        inFS >> d1 >> d2 >> d3 >> d4 >> d5 >> d6 >> d7 //Parses "[line1:" / "[line2:" / "[line3:" / "[line4:"
             >> d8 >> line1_p1x >> d9 >> line1_p1y >> d10 >> d11 //Parses "[double,double],"
             >> d12 >> line1_p2x >> d13 >> line1_p2y >> d14 >> d15 //Parses "[double,double]]"
             >> d16; //Parses "," / "}"

        if (!inFS.fail() && d1 == '[' && d2 == 'l' && d3 == 'i' && d4 == 'n' && d5 == 'e'
            && (d6 == '1' || d6 == '2' || d6 == '3' || d6 == '4') && d7 == ':' && d8 == '['
            && d9 == ',' && d10 == ']' && d11 == ',' && d12 == '[' && d13 == ',' && d14 == ']'
            && d15 == ']' && (d16 == ',' || d16 == '}')) {

            Lines.push_back(Line(line1_p1x, line1_p1y, line1_p2x, line1_p2y));

        }

    }

    inFS.close();

}

void SortVector(vector<Line>& Lines) { //Based on selection sort from LA3.

    Line temp; //Temporary variable for swapping.
    int minIndex; //Stores index of shortest line.

    for (int i = 0; i < Lines.size() - 1; i++) { //Included (- 1) to avoid out of range error.

        minIndex = i;

        for (int j = i; j < Lines.size(); j++) {

            if (Lines.at(j) < Lines.at(minIndex)) { //Checks if current line (Lines.at(j)) is shorter than the shortest line (Lines.at(minIndex)).

                minIndex = j; //Updates value of index with shortest line.

            }

        }

        //The shortest line (Lines.at(minIndex)) is swapped with the line at the current index (Line.at(i)).
        temp = Lines.at(i);
        Lines.at(i) = Lines.at(minIndex);
        Lines.at(minIndex) = temp;

    }

}

int main() {

    /* WORKING WITH VECTOR OF LINES */
    vector<Line> Lines;

    cout << setfill('=') << setw(50) << "" << endl;
    cout << left << setw(50) << "PARSING VALUES FROM Lines.txt" << endl;
    cout << setfill('=') << setw(50) << "" << endl;

    LoadLines(Lines);

    cout << "UNSORTED VECTOR" << endl << endl;
    for (int i = 0; i < Lines.size(); i++) {

        cout << "Line " << i + 1 << ":" << endl;
        cout << Lines.at(i);

        if (i != 3) { cout << endl; }

    }

    SortVector(Lines);
    cout << setfill('-') << setw(50) << "" << endl;

    cout << "SORTED VECTOR" << endl;
    cout << "(Lines sorted from shortest length" << endl << "to longest length.)" << endl << endl;
    for (int i = 0; i < Lines.size(); i++) {

        cout << "Line " << i + 1 << ":" << endl;
        cout << Lines.at(i);

        if (i != 3) { cout << endl; }

    }

    cout << setfill('=') << setw(50) << "" << endl;

    cout << endl;

    /* WORKING WITH LINES */
    Line line1; //Calls default constructor.
    Line line2(1, 2, 3, 4); //Calls constructor with double arguments.
    Line line3 = line2; //Calls copy constructor.

    cout << setfill('=') << setw(50) << "" << endl;
    cout << left << setw(50) << "LINE OPERATIONS" << endl;
    cout << setfill('=') << setw(50) << "" << endl;

    cout << "INITIALIZATION" << endl << endl;
    PrintLines(line1, line2, line3);

    cout << setfill('-') << setw(50) << "" << endl;

    cout << "COPY LINES" << endl;
    cout << "(CHANGE: line1 = line2)" << endl << endl;
    line1 = line2; //Calls copy assignment operator.
    PrintLines(line1, line2, line3);

    cout << setfill('-') << setw(50) << "" << endl;

    cout << "ASSIGN VALUES" << endl;
    cout << "(CHANGE: LINE 1: P1 = (1, -4.25), P2 = (-2, 2.3))" << endl;
    cout << "(CHANGE: LINE 2: P1 = (2, 4), P2 = (6, 8))" << endl << endl;

    line1.SetP1(1, -4.25);
    line1.SetP2(-2, 2.3);

    line2.SetP1(2, 4);
    line2.SetP2(6, 8);

    PrintLines(line1, line2, line3);

    cout << setfill('-') << setw(50) << "" << endl;

    cout << "PARALLEL CHECK" << endl << endl;

    cout << "line1 || line2 ?" << endl;
    if (AreParallel(line1, line2)) {

        cout << "The lines are parallel." << endl;

    } else {

        cout << "The lines are not parallel." << endl;

    }

    cout << endl;

    cout << "line1 || line3 ?" << endl;
    if (AreParallel(line1, line3)) {

        cout << "The lines are parallel." << endl;

    } else {

        cout << "The lines are not parallel." << endl;

    }

    cout << endl;

    cout << "line2 || line3 ?" << endl;
    if (AreParallel(line2, line3)) {

        cout << "The lines are parallel." << endl;

    } else {

        cout << "The lines are not parallel." << endl;

    }

    cout << setfill('-') << setw(50) << "" << endl;

    cout << "LENGTH COMPARISONS" << endl << endl;

    cout << "line1 == line2 ?" << endl;
    if (line1 == line2) {

        cout << "line1 and line2 are the same length." << endl;

    } else {

        cout << "line1 and line2 are not the same length." << endl;

    }

    cout << endl;

    cout << "line1 > line2 ?" << endl;
    if (line1 > line2) {

        cout << "line1 is longer than line2." << endl;

    } else {

        cout << "line1 is not longer than line2." << endl;

    }

    cout << endl;

    cout << "line1 < line 2 ?" << endl;
    if (line1 < line2) {

        cout << "line1 is shorter than line2." << endl;

    } else {

        cout << "line1 is not shorter than line2." << endl;

    }

    cout << setfill('-') << setw(50) << "" << endl;

    cout << "USER INPUT" << endl << endl;
    Line userLine;

    cout << "Enter values for the final line." << endl;
    cout << "(Valid Input: (p1x,p1y),(p2x,p2y))" << endl;
    cin >> userLine;

    cout << endl;

    if (isnan(userLine.GetLength()) || isinf(userLine.GetLength())) { //Made possible with custom validation check.

        cout << "Invalid input. Failed to print your line." << endl;

    } else {

        cout << "Your Line:" << endl;
        cout << userLine;

    }

    cout << setfill('=') << setw(50) << "" << endl;

	return 0; //The Line destructor is automatically called for each Line when the program ends.

}
