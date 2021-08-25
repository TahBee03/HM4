/*
NAME: Talike Bennett
HM4, Part 1, Source File (Line)
*/

#include <iostream>
#include <cmath>
#include "HM4_P1_Bennett_23778852_Line.h"

//Constructor (default)
Line::Line() {

    p1 = new Point;
    p2 = new Point;

    p1->SetX(0);
    p1->SetY(0);
    p2->SetX(0);
    p2->SetY(0);

    slope = (p2->GetY() - p1->GetY())/(p2->GetX() - p1->GetX()); //Based on slope formula.
    length = sqrt(pow((p2->GetX() - p1->GetX()), 2) + pow((p2->GetY() - p1->GetY()), 2)); //Based on distance formula.

}

//Constructor (Accepts values for points and calculates the slope and length of the line accordingly)
Line::Line(double x1, double y1, double x2, double y2) {

    p1 = new Point;
    p2 = new Point;

    p1->SetX(x1);
    p1->SetY(y1);
    p2->SetX(x2);
    p2->SetY(y2);

    slope = (p2->GetY() - p1->GetY())/(p2->GetX() - p1->GetX());
    length = sqrt(pow((p2->GetX() - p1->GetX()), 2) + pow((p2->GetY() - p1->GetY()), 2));

}

//Destructor
Line::~Line() {

    delete p1;
    delete p2;

}

//Copy constructor
Line::Line(const Line& L) {

    this->p1 = new Point;
    this->p2 = new Point;

    *p1 = *(L.p1);
    *p2 = *(L.p2);

    this->slope = (p2->GetY() - p1->GetY())/(p2->GetX() - p1->GetX());
    this->length = sqrt(pow((p2->GetX() - p1->GetX()), 2) + pow((p2->GetY() - p1->GetY()), 2));

}

//Copy assignment operator
Line& Line::operator=(const Line& L) {

    if (this != &L) {

        delete this->p1;
        delete this->p2;

        this->p1 = new Point;
        this->p2 = new Point;

        *p1 = *(L.p1);
        *p2 = *(L.p2);

        this->slope = (p2->GetY() - p1->GetY())/(p2->GetX() - p1->GetX());
        this->length = sqrt(pow((p2->GetX() - p1->GetX()), 2) + pow((p2->GetY() - p1->GetY()), 2));

    }

    return *this;

}

//Setter function. Sets value for slope.
void Line::SetSlope() { slope = (p2->GetY() - p1->GetY())/(p2->GetX() - p1->GetX()); }

//Setter function. Sets value for length.
void Line::SetLength() { length = sqrt(pow((p2->GetX() - p1->GetX()), 2) + pow((p2->GetY() - p1->GetY()), 2)); }

//Setter function. Sets values for first point.
void Line::SetP1(double x, double y) { p1->SetX(x); p1->SetY(y); this->SetSlope(); this->SetLength(); }

//Setter function. Sets values for second point.
void Line::SetP2(double x, double y) { p2->SetX(x); p2->SetY(y); this->SetSlope(); this->SetLength(); }

//Getter function. Returns the first point of the line.
Point* Line::GetP1() const { return p1; }

//Getter function. Returns the second point of the line.
Point* Line::GetP2() const { return p2; }

//Getter function. Returns the slope of the line.
double Line::GetSlope() const { return slope; }

//Getter function. Returns the length of the line.
double Line::GetLength() const { return length; }

//AreParallel function. Uses the slope of two Lines to determine whether or not they are parallel.
bool AreParallel(Line& line1, Line& line2) {

    if (line1.slope == line2.slope) {

        return true;

    } else {

        return false;

    }

}

//Operator function for == operator
bool operator==(Line& line1, Line& line2) { return (line1.length == line2.length); }

//Operator function for > operator
bool operator>(Line& line1, Line& line2) { return (line1.length > line2.length); }

//Operator function for the < operator
bool operator<(Line& line1, Line& line2) { return (line1.length < line2.length); }

//Operator function for << operator
ostream& operator<<(ostream& out, Line L) {

    out << "   Start Point: (" << L.GetP1()->GetX() << ", " << L.GetP1()->GetY() << ")" << endl
        << "   End Point: (" << L.GetP2()->GetX() << ", " << L.GetP2()->GetY() << ")" << endl;

    if(isnan(L.GetSlope()) || isinf(L.GetSlope())) {

        out << "   Slope: undefined" << endl
            << "   Length: " << L.GetLength() << endl;

    } else {

        out << "   Slope: " << L.GetSlope() << endl
            << "   Length: " << L.GetLength() << endl;

    }

    return out;

}

//Operator function for >> operator
istream& operator>>(istream& in, Line& L) {

    char d1, d2, d3, d4, d5, d6, d7;
    double line_p1x, line_p1y, line_p2x, line_p2y;

    in >> d1 >> line_p1x >> d2 >> line_p1y >> d3 //Parses "(double,double)"
       >> d4 //Parses ","
       >> d5 >> line_p2x >> d6 >> line_p2y >> d7; //Parses "(double,double)"

    if (d1 == '(' && d2 == ',' && d3 == ')' && d4 == ','
        && d5 == '(' && d6 == ',' && d7 == ')') {

        L.SetP1(line_p1x, line_p1y);
        L.SetP2(line_p2x, line_p2y);

    } else {

        //Custom validation check. Enters undefined values in order to print error message.

        L.SetP1(0.0/0.0, 0.0/0.0);
        L.SetP2(0.0/0.0, 0.0/0.0);

    }

    return in;

}
