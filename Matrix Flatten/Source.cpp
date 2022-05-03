#include <iostream>
#include <vector>
using namespace std;
vector<int> suitable_vector( int n, int m, int p);
int convert_index(int n, int m, int p,int i, int j, int k);
int main()
{
	int n = 0, m = 0, p = 0;		//dimensions for 3D matrix 
	int i = 0, j = 0, k = 0;		//index of 3D matrix 
	int q = 0;						//size of vector
	int y = 0;						//index of vector
    int temp;

	cout << "Please add the 3 dimensions for 3D matrix\n";
	cin >> n >> m >> p;
	while (n < 0 || m < 0 || p < 0)
	{
		cout << "Sorry, but you entered negative values, which is incorrect\n";
		cout << "Please add the 3 dimensions for 3D matrix\n";
		cin >> n >> m >> p;
	}

    // n is no of 2D Arrays from pointers
    // m is no of 1D Arrays from pointers
    int*** matrix = new int** [n];

    for (int i = 0; i < n; i++) {


        matrix[i] = new int* [m];

        for (int j = 0; j < m; j++) {

            // Allocate memory blocks for
            // columns of each 2D array
            matrix[i][j] = new int[q];
        }
    }
    cout << "Matrix is created,but it's empty\n";
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) 
        {
            for (int k = 0; k < p; k++) 
            {

                // Assign values
                cout << "Enter value in[" << i + 1 << "][" << j + 1<<"]["<<k+1<<"]\n";
                cin >> temp;
                matrix[i][j][k] = temp;
            }
        }
    }
    cout << "Matrix is full\n";


    /////////////////////////////////////////////////////////////////////////////////////////////
    //create suitable vector
    vector <int> flattened(suitable_vector( n, m, p));
    cout << "1D vector is created,but it's empty\n";
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < p; k++)
            {
                y = convert_index(n, m, p, i, j, k);
                flattened[y] = matrix[i][j][k];
            }
        }
    }
    cout << "All values have been copied in 1D vector\n";
    cout << "Values  in 1D vector\n";
    for (auto it : flattened)
        cout << it << " ";
    cout << "\n\n";
    return 0;
}

vector<int> suitable_vector( int n, int m, int p)
{
    int q = n * m * p;
    vector <int> flattened(q);
    return flattened;
}

int convert_index(int n, int m, int p,int i, int j, int k)
{
    int y;
    y = i*m*p+j*p+k;
    return y;
}
