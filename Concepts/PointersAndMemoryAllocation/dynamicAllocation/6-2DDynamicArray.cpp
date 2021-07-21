#include<bits/stdc++.h>
using namespace std;

int main()
{
 int**p = new int*[10];
 for(int i=0; i<10; i++) p[i] = new int[i];

 int n, m; cin>>n>>m;

 int**g = new int*[n];
 for(int i = 0; i<m; i++)
 {
   p[i] = new int[n];
   for(int j =0; j<n; j++)
   {
     cin>>p[i][j];
   }
 }

 //Deallocating memory:
 
 for(int i =0; i<n; i++)
 {
   delete[] p[i];
 }
 delete [] p;

}

