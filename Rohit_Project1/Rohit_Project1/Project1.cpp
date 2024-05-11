#include <iostream>
#include <climits>

using namespace std;
int sum(int A[], int start, int end) 
{
    int total = 0;
    for (int i = start; i <= end; i++) 
    { 
        total += A[i];
    }
    return total;
}
void max_min_grouping(int A[], int N, int M) 
{
    int B[N][M];
    int P[N][M];
    int C;
    for (int i = 0; i < N; i++) 
    {
        B[i][0] = sum(A, 0, i);
    }
    for (int j = 1; j < M; j++) 
    {
        for (int i = j; i < N; i++) 
        { 
            B[i][j] = 0;
            for (int k = j - 1; k < i; k++) 
            {
                C = min(B[k][j - 1], sum(A, k + 1, i));
                if (C > B[i][j]) 
                {
                    B[i][j] = C;
                    P[i][j] = k;
                    
                }

            }
        }
        
    }
    
    // Construct the grouping
    int i = N - 1 ;
    int j = M - 1 ;
    int groupSizes[M];
    while (i >= 0 && j >= 0) 
    {
        groupSizes[j] = i - P[i][j];
        if(j !=0 )
            i = P[i][j];
        if (j == 0) 
        {
            groupSizes[j] = i + 1;
            
        }
        --j;
       
    }
    // Print group sizes
    for (int k = 0; k < M; k++) 
    {
        cout << "Group " << k + 1 << " size: " << groupSizes[k] << endl;
    }
    cout << "MAX MIN Sum: " << B[N - 1][M - 1] <<endl;
}

int main() 
{
    int N, M;
    cout<< "Enter the size of array A: ";
    cin >> N;
    int * A = new int[N];
    cout << "Enter the elements of array A: ";
    for (int i = 0; i < N; i++) 
    {
        cin >> A[i];
    }
    cout << "Enter the number of groups (M): ";
    cin >> M;
    max_min_grouping(A, N, M);
    return 0;
}