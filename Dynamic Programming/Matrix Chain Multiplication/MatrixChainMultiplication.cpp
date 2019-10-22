#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

int M[N][N];
int K[N][N];

int MatrixChainOrder(int *p, int i, int j)
{
    if(i==j) return M[i][j] = 0;  // Base Case
    if(M[i][j] != -1) return M[i][j]; // Already Defined

    int cost;
    M[i][j]=INT_MAX; // Initialize
    for(int k=i; k<j; k++)  // Try all splits
    {
        cost = MatrixChainOrder(p,i,k) + MatrixChainOrder(p,k+1,j) + p[i-1]*p[k]*p[j];
        if(cost<M[i][j])
        {
            M[i][j] = cost; // Update if better
            K[i][j] = k;
        }
    }
    return M[i][j]; // Return Optimal Cost
}

void initialize(int n)
{
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            M[i][j] = -1;
}

string FindOptimalOrder(int i, int j)
{
    string s;
    if(i==j) s = char('A'+i-1);
    else
    {
        string s1 = FindOptimalOrder(i, K[i][j]);
        string s2 = FindOptimalOrder(K[i][j]+1, j);
        if(s1.size()>1) s1 = '(' + s1 + ')';
        if(s2.size()>1) s2 = '(' + s2 + ')';
        s = s1 + s2;
    }
    return s;
}

int main()
{
    int n = 6;
    int p[] = {30,35,15,5,10,20,25};

    initialize(n);
    MatrixChainOrder(p, 1, n);

    cout<<"Optimal Cost: "<<endl;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=i; j++)
            cout<<M[j][j+n-i]<<" ";
        cout<<endl;
    }

    string s = FindOptimalOrder(1,n);
    cout<<"Optimal Order: "<<s<<endl;

    return 0;
}
