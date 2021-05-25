#include<bits/stdc++.h>
using namespace std;

/*
=> Recursion is based on PMI (PrincipleOfMathematicalInduction) :
-> F(n) is true for all natural numbers,
1: Prove F(0) or F(1) is true.
2: Induction Hypothesis: Assume that F(k) is true.
3: Induction step: Using step 2 prove that F(k+1) is true.
 */

int fact(int n)
{
  if(n==0) return 1;
  int output = fact(n-1);
  return n*output;
}
int main()
{

}

