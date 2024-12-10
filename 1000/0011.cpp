const int MAX_SIZE = 100;
void fillMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size)
{
    int counter = 0, groupSize = 0, column = 0;
    for (int i = size - 1; i >= 0; i--, counter = 0, column++)
    {
        while (counter < pow(3, size))
        {
            for (groupSize = 0; groupSize < pow(3, column) && counter < pow(3, size); groupSize++)
                matrix[counter++][i] = 1;
            for (groupSize = 0; groupSize < pow(3, column) && counter < pow(3, size); groupSize++)
                matrix[counter++][i] = 2;
            for (groupSize = 0; groupSize < pow(3, column) && counter < pow(3, size); groupSize++)
                matrix[counter++][i] = 3;
        }
    }
}

main()
{
    int x, y;
    cin >> x >> y;

    int matrix[MAX_SIZE][MAX_SIZE];
    fillMatrix(matrix, y);

    int n = 0;
    while (cin >> n)
    {
        int dimension = pow(3, n);
        int **dynamicMatrix = new int *[dimension];
        for (int row = 0; row < dimension; ++row)
        {
            dynamicMatrix[row] = new int[n];
            fillMatrix(dynamicMatrix, n);
            for (int r = 0; r < pow(3, n); r++)
            {
                for (int c = 0; c < n; c++)
                    cout << dynamicMatrix[r][c];
                cout << "\n";
            }
        }
        for (int q = 0; q < dimension; ++q)
            delete[] dynamicMatrix[q];
        delete[] dynamicMatrix;
        cout << endl;
    }
    return 0;
}
// Function to calculate 3^m using integer arithmetic
int pow3(int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= 3;
    }
    return result;
}

// Function to fill the array according to the pattern
void fillArray(int **array, int size) {
    int rowIndex = 0, groupIndex = 0, segmentIndex = 0;
    int totalRows = pow3(size);
    for (int colIndex = size - 1; colIndex >= 0; colIndex--, rowIndex = 0, segmentIndex++) {
        while (rowIndex < totalRows) {
            for (groupIndex = 0; groupIndex < pow3(segmentIndex); groupIndex++) array[rowIndex++][colIndex] = 1;
            for (groupIndex = 0; groupIndex < pow3(segmentIndex); groupIndex++) array[rowIndex++][colIndex] = 2;
            for (groupIndex = 0; groupIndex < pow3(segmentIndex); groupIndex++) array[rowIndex++][colIndex] = 3;
        }
    }
}

int main() {
    int size = 0;
    while (cin >> size) {
        if (size <= 0) {
            cout << "Please enter a positive integer.\n";
            continue;
        }

        int totalRows = pow3(size);
        // Allocate memory for the 2D array
        int **array = new int*[totalRows];
        for (int i = 0; i < totalRows; ++i)
            array[i] = new int[size];
        
        // Fill the array with the pattern
        fillArray(array, size);
        
        // Print the array
        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < size; j++)
                cout << array[i][j];
            cout << "\n";
        }
        
        // Deallocate memory
        for (int i = 0; i < totalRows; ++i)
            delete[] array[i];
        delete[] array;
        
        cout << endl;
    }
    return 0;
}


//calculates the sum of the integers a for which the corresponding string r starts with the character ch and prints this sum.
struct X{
    char r[100], int a;
}
main(){
    int n; cin >> n;
    struct X arr[100];
    //reads a character & integer from the array
    for(int i = 0; i < n; i++)
        cin >> arr[i].r >> arr[i].a;
    char ch; cin >> ch;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].r[0] == ch)
            cnt += arr[i].a;
    }
    cout << cnt;
}

#include<iostream>
using namespace std;
//manipulate the values of x and y through a series of recursive calls.
int cnt = 0, odd = 0;
int request(int x, int y){
    if(y == 1)
        return x;
    if(x + y + 1 == y)
        return (pow(2, cnt - 1) + odd);
    if(x + odd == y)
        return pow(2, cnt);
    if(x == y)
        return pow(pow(2, cnt) + odd);
    if(x <= y && odd > y)
         return (pow(2, cnt) + odd / y + (odd % y));
    if(x <= y && odd > y)
        return (pow(2, cnt) + 1);
    if(x % 2 == 0){
        x /= 2;
        cnt++;
    }
    else {
        x = (x + 1)/2;
        cnt++; odd++;
    }
    return request(x, y);
}
main(){
    int x, y;
    cin >> x >> y;
    cout << request(x, y);
}
