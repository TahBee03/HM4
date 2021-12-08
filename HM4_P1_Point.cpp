/*
NAME: Talike Bennett
HM4, Part 1, Source File (Point)
*/

#include <iostream>
#include <cmath> //Library needed to use pow(), sqrt(), and isinf().
#include "HM4_P1_Point.h"
using namespace std;

//Print function (definition)
void Point::Print() const {

    cout << "(";

    if (isinf(this->x)) { //Included to check if x is an undefined number.

        cout << "undefined";

    } else {

        cout << this->x;

    }

    cout << ", ";

    if (isinf(this->y)) { //Included to check if y is an undefined number.

        cout << "undefined";

    } else {

        cout << this->y;

    }

    cout << ")";

}

//Function that calculates the distance between a point and the origin using distance formula. Accepts objects as a parameter.
double Distance(Point p) {

    return sqrt(pow(p.GetX(), 2) + pow(p.GetY(), 2));

}

//Function that calculates the distance between a point and the origin using distance formula. Accepts pairs as a parameter.
double Distance(pair <double, double> p) {

    return sqrt(pow(p.first, 2) + pow(p.second, 2));

}

//Operator function for + operator; adds an object to an object (definition)
Point operator+(Point lhp, Point rhp) {

    return Point(lhp.x + rhp.x, lhp.y + rhp.y);

}

//Operator function for + operator; adds a pair to an object (definition)
Point operator+(Point lhp, pair <double, double> rhp) {

    return Point(lhp.x + rhp.first, lhp.y + rhp.second);

}

//Operator function for + operator; adds an object to a pair (definition)
Point operator+(pair <double, double> lhp, Point rhp) {

    return Point(lhp.first + rhp.x, lhp.second + rhp.y);

}

//Operator function for - operator; subtracts an object from an object (definition)
Point operator-(Point lhp, Point rhp) {

    return Point(lhp.x - rhp.x, lhp.y - rhp.y);

}

//Operator function for - operator; subtracts a pair from an object (definition)
Point operator-(Point lhp, pair <double, double> rhp) {

    return Point(lhp.x - rhp.first, lhp.y - rhp.second);

}

//Operator function for - operator; subtracts an object from a pair (definition)
Point operator-(pair <double, double> lhp, Point rhp) {

    return Point(lhp.first - rhp.x, lhp.second - rhp.y);

}

//Operator function for * operator; multiplies an object to an object (definition)
Point operator*(Point lhp, Point rhp) {

    return Point(lhp.x * rhp.x, lhp.y * rhp.y);

}

//Operator function for * operator; multiplies a pair to an object (definition)
Point operator*(Point lhp, pair <double, double> rhp) {

    return Point(lhp.x * rhp.first, lhp.y * rhp.second);

}

//Operator function for * operator; multiplies an object to a pair (definition)
Point operator*(pair <double, double> lhp, Point rhp) {

    return Point(lhp.first * rhp.x, lhp.second * rhp.y);

}

//Operator function for / operator; divides an object by an object (definition)
Point operator/(Point lhp, Point rhp) {

    return Point(lhp.x / rhp.x, lhp.y / rhp.y);

}

//Operator function for / operator; divides an object by a pair (definition)
Point operator/(Point lhp, pair <double, double> rhp) {

    return Point(lhp.x / rhp.first, lhp.y / rhp.second);

}

//Operator function for / operator; divides a pair by an object (definition)
Point operator/(pair <double, double> lhp, Point rhp) {

    return Point(lhp.first / rhp.x, lhp.second / rhp.y);

}

//Operator function for == operator; checks if an object is equal to an object (definition)
bool operator==(Point& lhp, Point& rhp) {

    return (lhp.x == rhp.x && lhp.y == rhp.y);

}

//Operator function for == operator; checks if an object is equal to a pair (definition)
bool operator==(Point lhp, pair <double, double> rhp) {

    return (lhp.x == rhp.first && lhp.y == rhp.second);

}

//Operator function for == operator; checks if a pair is equal to an object (definition)
bool operator==(pair <double, double> lhp, Point rhp) {

    return (lhp.first == rhp.x && lhp.second == rhp.y);

}

//Operator function for != operator; checks if an object is not equal to an object (definition)
bool operator!=(Point& lhp, Point& rhp) {

    return !(lhp.x == rhp.x && lhp.y == rhp.y);

}

//Operator function for != operator; checks if an object is not equal to a pair (definition)
bool operator!=(Point lhp, pair <double, double> rhp) {

    return !(lhp.x == rhp.first && lhp.y == rhp.second);

}

//Operator function for != operator; checks if a pair is not equal to an object (definition)
bool operator!=(pair <double, double> lhp, Point rhp) {

    return !(lhp.first == rhp.x && lhp.second == rhp.y);

}

//Operator function for > operator; checks if an object is greater than an object (definition)
bool operator>(Point& lhp, Point& rhp) {

    return Distance(lhp) > Distance(rhp);

}

//Operator function for > operator; checks if an object is greater than a pair (definition)
bool operator>(Point lhp, pair <double, double> rhp) {

    return Distance(lhp) > Distance(rhp);

}

//Operator function for > operator; checks if a pair is greater than an object (definition)
bool operator>(pair <double, double> lhp, Point rhp) {

    return Distance(lhp) > Distance(rhp);

}

//Operator function for < operator; checks if an object is less than an object (definition)
bool operator<(Point& lhp, Point& rhp) {

    return Distance(lhp) < Distance(rhp);

}

//Operator function for < operator; checks if an object is less than a pair (definition)
bool operator<(Point lhp, pair <double, double> rhp) {

    return Distance(lhp) < Distance(rhp);

}

//Operator function for < operator; checks if a pair is less than an object (definition)
bool operator<(pair <double, double> lhp, Point rhp) {

    return Distance(lhp) < Distance(rhp);

}

//Operator function for >= operator; checks if an object is greater than or equal to an object (definition)
bool operator>=(Point& lhp, Point& rhp) {

    return Distance(lhp) >= Distance(rhp);

}

//Operator function for >= operator; checks if an object is greater than or equal to a pair (definition)
bool operator>=(Point lhp, pair <double, double> rhp) {

    return Distance(lhp) >= Distance(rhp);

}

//Operator function for >= operator; checks if a pair is greater than or equal to an object (definition)
bool operator>=(pair <double, double> lhp, Point rhp) {

    return Distance(lhp) >= Distance(rhp);

}

//Operator function for <= operator; checks if an object is less than or equal to an object (definition)
bool operator<=(Point& lhp, Point& rhp) {

    return Distance(lhp) <= Distance(rhp);

}

//Operator function for <= operator; checks if an object is less than or equal to a pair (definition)
bool operator<=(Point lhp, pair <double, double> rhp) {

    return Distance(lhp) <= Distance(rhp);

}

//Operator function for <= operator; checks if a pair is less than or equal to an object (definition)
bool operator<=(pair <double, double> lhp, Point rhp) {

    return Distance(lhp) <= Distance(rhp);

}

//Operator function for prefix ++ operator; increments object values by 1 (definition) (Source: 4/9/21 Recitation)
Point Point::operator++() {

    x++;
    y++;
    return *this;

}

//Operator function for postfix ++ operator; increments object values by 1 (definition) (Source: 4/9/21 Recitation)
Point Point::operator++(int dummy) {

    Point temp = *this;
    x++;
    y++;
    return temp;

}

//Operator function for prefix -- operator; decrements object values by 1 (definition) (Source: 4/9/21 Recitation)
Point Point::operator--() {

    x--;
    y--;
    return *this;

}

//Operator function for postfix -- operator; decrements object values by 1 (definition) (Source: 4/9/21 Recitation)
Point Point::operator--(int dummy) {

    Point temp = *this;
    x--;
    y--;
    return temp;

}
