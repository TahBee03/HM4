/*
NAME: Talike Bennett
EMPLID: 23778852
*/

#ifndef LINE_H
#define LINE_H

#include "HM4_P1_Bennett_23778852_Point.h"
using namespace std;

class Line {

	public:

	    //Constructors
	    Line(); //Default
	    Line(double x1, double y1, double x2, double y2);

	    //The Big 3
	    ~Line(); //Destructor
	    Line(const Line& L); //Copy constructor
	    Line& operator=(const Line& L); //Copy assignment operator

		//Setter functions
		void SetP1(double x, double y);
		void SetP2(double x, double y);

		//Getter functions
		Point* GetP1() const;
		Point* GetP2() const;
		double GetSlope() const;
		double GetLength() const;

		//AreParallel function
		friend bool AreParallel(Line& line1, Line& line2);

		//Operator functions
		friend bool operator==(Line& line1, Line& line2);
		friend bool operator>(Line& line1, Line& line2);
		friend bool operator<(Line& line1, Line& line2);
		friend ostream& operator<<(ostream& out, Line L);
        friend istream& operator>>(istream& in, Line& L);

	private:

		//Data member(s)
		Point* p1;
		Point* p2;
		double slope;
		double length;

		//Setter functions
		void SetSlope();
		void SetLength();

};

#endif
