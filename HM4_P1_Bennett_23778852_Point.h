/*
NAME: Talike Bennett
EMPLID: 23778852
*/

#ifndef POINT_H
#define POINT_H

using namespace std;

class Point {

	public:

	    //Constructor function (initializer list format)
	    Point(double x = 0, double y = 0): x(x), y(y) {} //MOVE TO SOURCE FILE

	    //Setter and getter functions
	    void SetX(double x) {this->x = x;} //MOVE TO SOURCE FILE
	    double GetX() const {return this->x;} //MOVE TO SOURCE FILE
	    void SetY(double y) {this->y = y;} //MOVE TO SOURCE FILE
	    double GetY() const {return this->y;} //MOVE TO SOURCE FILE

	    //Print function (prototype)
	    void Print() const;

	    //Operator functions for + operator (prototype)
	    friend Point operator+(Point lhp, Point rhp);
	    friend Point operator+(Point lhp, pair <double, double> rhp);
	    friend Point operator+(pair <double, double> lhp, Point rhp);

	    //Operator functions for - operator (prototype)
	    friend Point operator-(Point lhp, Point rhp);
	    friend Point operator-(Point lhp, pair <double, double> rhp);
	    friend Point operator-(pair <double, double> lhp, Point rhp);

	    //Operator functions for * operator (prototype)
	    friend Point operator*(Point lhp, Point rhp);
	    friend Point operator*(Point lhp, pair <double, double> rhp);
	    friend Point operator*(pair <double, double> lhp, Point rhp);

	    //Operator functions for / operator (prototype)
	    friend Point operator/(Point lhp, Point rhp);
	    friend Point operator/(Point lhp, pair <double, double> rhp);
	    friend Point operator/(pair <double, double> lhp, Point rhp);

	    //Operator functions for == operator (prototype)
	    friend bool operator==(Point& lhp, Point& rhp);
	    friend bool operator==(Point lhp, pair <double, double> rhp);
	    friend bool operator==(pair <double, double> lhp, Point rhp);

	    //Operator functions for != operator (prototype)
	    friend bool operator!=(Point& lhp, Point& rhp);
	    friend bool operator!=(Point lhp, pair <double, double> rhp);
	    friend bool operator!=(pair <double, double> lhp, Point rhp);

	    //Operator functions for > operator (prototype)
	    friend bool operator>(Point& lhp, Point& rhp);
	    friend bool operator>(Point lhp, pair <double, double> rhp);
	    friend bool operator>(pair <double, double> lhp, Point rhp);

	    //Operator functions for < operator (prototype)
	    friend bool operator<(Point& lhp, Point& rhp);
	    friend bool operator<(Point lhp, pair <double, double> rhp);
	    friend bool operator<(pair <double, double> lhp, Point rhp);

	    //Operator functions for >= operator (prototype)
	    friend bool operator>=(Point& lhp, Point& rhp);
	    friend bool operator>=(Point lhp, pair <double, double> rhp);
	    friend bool operator>=(pair <double, double> lhp, Point rhp);

	    //Operator functions for <= operator (prototype)
	    friend bool operator<=(Point& lhp, Point& rhp);
	    friend bool operator<=(Point lhp, pair <double, double> rhp);
	    friend bool operator<=(pair <double, double> lhp, Point rhp);

	    //Operator functions for ++ operator (prototype)
	    Point operator++();
	    Point operator++(int dummy);

	    //Operator functions for -- operator (prototype)
	    Point operator--();
	    Point operator--(int dummy);

	private:

	    //Data member(s)
	    double x;
	    double y;

};

#endif
