//This program dynamically allocates memory for two 2D arrays of the same size, takes user input to 
// fill them, adds the values of the array together, storing the result in another 2-D array, 
//and displays the result.
//The input is from user and the output is to the console.
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int row, col;
    int i, j;
    int** array1, ** array2, ** array3;

    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    
    array1 = new int*[row];
    array2 = new int*[row];
    array3 = new int*[row];

    for (i = 0; i < row; i++) {
        array1[i] = new int[col];
        array2[i] = new int[col];
        array3[i] = new int[col];
    }

    //Taking inputs for array 1 and array 2
    cout << "\nEnter " << row*col << " elements for Matrix A:" << endl;
    for (i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> array1[i][j];
        }
    }

    cout << "Enter " << row * col << " elements for Matrix B:" << endl;
    for (i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> array2[i][j];
        }
    }

    //Adding array 1 and array 2 and storing the result in array 3
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            array3[i][j] = array1[i][j] + array2[i][j];
        }
    }

    //Displaying arrays 1 and 2, and array 3 which is the result of addition
    cout << left;
    cout << "\nMatrix A:" << endl;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            cout << setw(5) << array1[i][j];
        cout << endl;
    }

    cout << "\nMatrix B:" << endl;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++)
            cout << setw(5) << array2[i][j];
        cout << endl;
    }

    cout << "\nMatrix A+B:" << endl;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cout << setw(5) << array3[i][j] << " ";
        }
        cout << endl;
    }

    //Deallocating memory
    for (i = 0; i < row; i++) {
        delete[] array1[i];
        delete[] array2[i];
        delete[] array3[i];
    }
    delete[] array1;
    delete[] array2;
    delete[] array3;

    return 0;
}

//40 41 42 43 44 45
//50 51 52 53 54 55