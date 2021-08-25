/*
NAME: Talike Bennett
HM2, Part 2, Main File
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct Product {

    Product();
    Product(string d, int p, double c);

    void Print() const;

    string description;
    int partNum;
    double cost;

};

//Constructor (default)
Product::Product() {

    description = "";
    partNum = 0;
    cost = 0;

}

//Constructor (Accepts values for the part description, number, and cost)
Product::Product(string d, int p, double c) {

    description = d;
    partNum = p;
    cost = c;

}

//Print function. Prints the details of a Product.
void Product::Print() const {

    cout << fixed << setprecision(2);
    cout << "Description: " << description << endl;
    cout << "Number: " << partNum << endl;
    cout << "Part Cost: $" << cost << endl;

}

void PrintAM(Product** itemsPtr); //Print function. Prints the details of an array of Products.
Product* Max(Product* items); //Returns the Product with the highest cost in a given Product array.
void PrintAM(ostream& output, Product* itemsM_Row); //Print function. Prints the details of a row of a matrix of Products.
void WriteMatrix(Product** itemsM); //Copies the output of PrintAM() to a text file.

int main() {

    /* BASIC STRUCT OBJECTS */
    cout << setfill('=') << setw(50) << "" << endl;
    cout << left << setw(50) << "Product OBJECTS " << endl;
    cout << setfill('=') << setw(50) << "" << endl;

    cout << "INPUT" << endl << endl;
    cout << "Sample Item 1:" << endl;
    cout << "   description = \"light bulb\"" << endl;
    cout << "   partNum = 57" << endl;
    cout << "   cost = 3.5" << endl;
    cout << endl;
    cout << "Sample Item 2:" << endl;
    cout << "   description = \"wrench\"" << endl;
    cout << "   partNum = 18" << endl;
    cout << "   cost = 1" << endl;

    cout << setfill('-') << setw(50) << "" << endl;

    Product sampleItem1("light bulb", 57, 3.5);
    Product sampleItem2("wrench", 18, 1);

    cout << "PRINT VALUES" << endl << endl;
    cout << "Sample Item 1:" << endl;
    sampleItem1.Print();
    cout << endl;
    cout << "Sample Item 2:" << endl;
    sampleItem2.Print();

    cout << setfill('=') << setw(50) << "" << endl << endl;

    /* ARRAY OF STRUCT OBJECTS */
    cout << setfill('=') << setw(50) << "" << endl;
    cout << left << setw(50) << "Product ARRAY " << endl;
    cout << setfill('=') << setw(50) << "" << endl;

    Product* items = new Product[5]; //Declaration of dynamic array of Products.

    cout << "USER INPUT" << endl << endl;
    for (int i = 0; i < 5; i++) { //Stores user input in items array.

        cout << "Item " << i + 1 << ":" << endl;
        cout << "Enter a new item description: ";
        getline(cin, items[i].description);

        cout << "Enter the item number: ";
        cin >> items[i].partNum;

        cout << "Enter the item price: ";
        cin >> items[i].cost;

        if (i != 4) { cout << endl; }

        cin.ignore(); //Clears input buffer to accept values into next getline().

    }

    cout << setfill('-') << setw(50) << "" << endl;
    cout << "PRINT VALUES" << endl << endl;

    PrintAM(&items); //The address of the dynamic array items (&items) is a pointer to the array.

    cout << endl;
    cout << "MAX ITEM: " << endl;
    Max(items)->Print();

    cout << setfill('=') << setw(50) << "" << endl << endl;

    /* 2D DYNAMIC ARRAY */
    cout << setfill('=') << setw(50) << "" << endl;
    cout << left << setw(50) << "Product MATRIX " << endl;
    cout << setfill('=') << setw(50) << "" << endl;

    Product** itemsM = new Product*[3]; //Declaration of dynamic 2D array of Products.
    itemsM[0] = new Product[3];
    itemsM[1] = new Product[3];
    itemsM[2] = new Product[3];

    cout << "USER INPUT" << endl << endl;
    for (int i = 0; i < 3; i++) { //Stores user input in itemsM 2D array.

        for (int j = 0; j < 3; j++) {

        	switch (i) {

        		case 0:
        			cout << "Item " << (i + j) + 1 << ":" << endl;
        			break;
        		case 1:
        			cout << "Item " << (i + j) + 3 << ":" << endl;
        			break;
        		case 2:
        			cout << "Item " << (i + j) + 5 << ":" << endl;
        			break;
        	}

            cout << "Enter a new item description: ";
            getline(cin, itemsM[i][j].description);

            cout << "Enter the item number: ";
            cin >> itemsM[i][j].partNum;

            cout << "Enter the item price: ";
            cin >> itemsM[i][j].cost;

            if (i != 2 || j != 2) { cout << endl; }

            cin.ignore(); //Clears input buffer to accept values into next getline().

        }

    }

    cout << setfill('-') << setw(50) << "" << endl;
    cout << "PRINT VALUES" << endl << endl;

    cout << setfill('-') << setw(91) << "" << endl;
    PrintAM(cout, itemsM[0]);
    cout << setfill('-') << setw(91) << "" << endl;
    PrintAM(cout, itemsM[1]);
    cout << setfill('-') << setw(91) << "" << endl;
    PrintAM(cout, itemsM[2]);
    cout << setfill('-') << setw(91) << "" << endl;

    cout << setfill('=') << setw(50) << "" << endl << endl;

    WriteMatrix(itemsM);

	return 0;

}

//Print function. Prints the details of an array of Products.
void PrintAM(Product** itemsPtr) {

    for (int i = 0; i < 5; i++) {

        cout << "Item " << i + 1 << ":" << endl;
        (*itemsPtr)[i].Print(); //Dereference itemsPtr to access the actual items array.
        if (i != 4) { cout << endl; }

    }

}

//Returns the Product with the highest cost in a given Product array.
Product* Max(Product* items) {

    //Algorithm similar to finding the maximum number in
    //an array of numbers.

    Product* maxProduct = &(items[0]);
    double costTemp = items[0].cost;

    for (int i = 1; i < 5; i++) {

        if (items[i].cost > costTemp) {

            costTemp = items[i].cost; //Stores cost of the current element.
            maxProduct = &(items[i]); //Stores address of the current element.

        }

    }

    return maxProduct;

}

//Print function. Prints the details of a row of a matrix of Products.
void PrintAM(ostream& output, Product* itemsM_Row) {

    int width = 15;
    output << fixed << setprecision(2);
    output << setfill(' ');

    for (int i = 0; i < 3; i++) {

        output << left << setw(width) << "| Description:" << setw(width) << itemsM_Row[i].description;

    }

    output << "|" << endl;

    for (int i = 0; i < 3; i++) {

        output << left << setw(width) << "| Number: " << setw(width) << itemsM_Row[i].partNum;

    }

    output << "|" << endl;

    for (int i = 0; i < 3; i++) {

        output << left << setw(width) << "| Part Cost: "  << "$" << setw(width - 1) << itemsM_Row[i].cost;

    }

    output << "|" << endl;

}

//Copies the output of PrintAM() to a text file.
void WriteMatrix(Product** itemsM) {

    ofstream outFS;
    outFS.open("ProductMatrix.txt");

    if (!outFS.is_open()) {

        cout << "Could not open the file." << endl;
        return;

    }

    outFS << setfill('-') << setw(91) << "" << endl;
    PrintAM(outFS, itemsM[0]);
    outFS << setfill('-') << setw(91) << "" << endl;
    PrintAM(outFS, itemsM[1]);
    outFS << setfill('-') << setw(91) << "" << endl;
    PrintAM(outFS, itemsM[2]);
    outFS << setfill('-') << setw(91) << "" << endl;

    outFS.close();

}
