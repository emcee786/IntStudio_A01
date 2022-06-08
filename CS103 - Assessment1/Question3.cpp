#include <iostream>
using namespace std;

// CS103 Assessment 1, Emma Corkery - Question 3.

// Struct for creating 3 x 3 matrices
struct matrix {      
    int value[3][3];
};

//Function to create a matrix with user input
matrix create_matrix() {  
    matrix mat;
    int p1, p2, p3, p4, p5, p6, p7, p8, p9;
    cout << "Let's create a 3 X 3 matrices: " <<endl;
    cout << "Please enter 9 values for your matrix" << endl;
    cin >> p1 >> p2 >> p3 >> p4 >> p5 >> p6 >> p7 >> p8 >> p9;
    mat.value[0][0] = p1; mat.value[1][0] = p2; mat.value[2][0] = p3;  //Assigns integers to each array.
    mat.value[0][1] = p4; mat.value[1][1] = p5; mat.value[2][1] = p6;
    mat.value[0][2] = p7; mat.value[1][2] = p8; mat.value[2][2] = p9;   
    return mat;
}


// Function that adds two matrix structs
// INPUT: Two matrix structs
// OUTPUT: Resultant matrix struct
matrix add_matrix(matrix a, matrix b){  
    matrix c;
    for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++)
            {
                c.value[i][j] = a.value[i][j] + b.value[i][j];
            }
        }
    return c;
}


// Function that scales a matrix struct
// INPUT: matrix struct, scalar integer
// OUTPUT: Resultant matrix
matrix scale_matrix (matrix c, int scalar) {  // Rather than only scaling this matric by 3 as the question directed,
    matrix d;                                 // This function can take any user specified integer and use it to multiply the matrix
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++)
            {
                d.value[i][j] = c.value[i][j] * scalar;
            }
        }
    return d;
}

// Prints matrix when called
// INPUT: matrix struct
void print_matrix(matrix mat) {    
    cout << "[ " << mat.value[0][0] << ", " << mat.value[1][0] << ", " << mat.value[2][0] << " ]" << endl;
    cout << "[ " << mat.value[0][1] << ", " << mat.value[1][1] << ", " << mat.value[2][1] << " ]" << endl;
    cout << "[ " << mat.value[0][2] << ", " << mat.value[1][2] << ", " << mat.value[2][2] << " ]" << endl;

}


// Has user input two matrices, then generates required matrices and print statements
int main() {
    matrix a = create_matrix();
    matrix b = create_matrix();
    matrix c = add_matrix(a, b);
    
    // Question 3 asks that Matrix C be multiplied by 3. Code below allows Matrix C to be multiplied by any integer the user inputs.
    int scalar;
    cout << "Matrix D will be created by scaling Matrix C. What number would you like to multiply Matrix C by (suggestion: 3)" << endl;
    cin >> scalar;
    matrix d = scale_matrix(c, scalar);
    
    cout << "\nMatrix A" << endl;
    print_matrix(a);
    cout << "\nMatrix B" << endl;
    print_matrix(b);
    cout << "\nMatrix C" << endl;
    print_matrix(c);
    cout << "\nMatrix D" << endl;
    print_matrix(d);

    return 0;
}
    