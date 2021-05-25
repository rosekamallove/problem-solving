#include "bits/stdc++.h"
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define endl "\n"

#ifndef ONLINE_JUDGE
#define tdeb(x,y)
#define deb(x)
#else
#define tdeb(x,y)     cout <<'('<< #x<<','<<#y<<") ++> "; print(x,y)
#define deb(x)        cout << #x << " ++> "; print(x)
#endif

#define rep(i,n)      for (int i(0); i<n ;  i++)
#define rip(i,n)      for (int i(1); i<=n;  i++)
#define rap(i,a,n)    for (int i(a); i<n ;  i++)

template<typename T> void print(vector<T> v);
template<typename T> void print(T n);
template<typename T, typename Tt> void print(T n, Tt m);

int win[8][3] = {{0, 1, 2}, 
                {3, 4, 5}, 
                {6, 7, 8}, 
                {0, 3, 6}, 
                {1, 4, 7},
                {2, 5, 8}, 
                {0, 4, 8}, 
                {2, 4, 6}}; 

bool isCWin(char *board, char c)
{
    for (int i=0; i<8; i++)
        if (board[win[i][0]] == c &&
            board[win[i][1]] == c &&
            board[win[i][2]] == c )
            return true;
    return false;
}

bool isValid(char board[9])
{
    int xCount=0, oCount=0;
    for (int i=0; i<9; i++)
    {
    if (board[i]=='X') xCount++;
    if (board[i]=='O') oCount++;
    }

    if (xCount==oCount || xCount==oCount+1)
    {
        if (isCWin(board, 'O'))
        {
            if (isCWin(board, 'X'))
                return false;

            return (xCount == oCount);
        }

        if (isCWin(board, 'X') && xCount != oCount + 1)
        return false;

        return true;
    }
    return false;
}


void solve()
{
    char board[9];

    int row(0), column(0);
    bool d1(0), d2(0), is_(0);

    
    rep(i,9)
        cin>>board[i];

    bool reachable = isValid(board);

    char arr[3][3];

    arr[0][0] = board[0];
    arr[0][1] = board[1];
    arr[0][2] = board[2];
    arr[1][0] = board[3];
    arr[1][1] = board[4];
    arr[1][2] = board[5];
    arr[2][0] = board[6];
    arr[2][1] = board[7];
    arr[2][2] = board[8];

    /*
     * Calculations
     */

    rep(i,3)
        rep(j,3)
            if(arr[i][j] == '_')
                is_ = 1;

    rep(i,3)
        if((arr[i][0]=='X' and arr[i][1]=='X' and arr[i][2]=='X') or (arr[i][0]=='O' and arr[i][1] =='O' and arr[i][2]=='O'))
            row++;

    rep(i,3)
        if((arr[0][i]=='X' and arr[1][i]=='X' and arr[2][i]=='X'))
            column++;
        else if(arr[0][i]=='O' and arr[1][i]=='O' and arr[2][i]=='O')
            column++;

    if((arr[0][0]=='X' and  arr[1][1]=='X' and  arr[2][2]=='X'))
        d1=1;

    else if(arr[0][0]=='O' and  arr[1][1]=='O' and  arr[2][2]=='O')
        d1=1;

    if((arr[0][2]=='X' and  arr[1][1]=='X' and  arr[2][0]=='X'))
        d2=1;

    else if(arr[0][2]=='O' and  arr[1][1]=='O' and  arr[2][0]=='O')
        d2=1;

    /*
     * OutPut
     */

    if(!reachable)
        cout<<3<<endl;
    else if((row+column+d1+d2)==0 and is_)
        cout<<2<<endl;
    else
        cout<<1<<endl;


}

signed main()
{
    fastIO();
    int T;
    cin >> T;
    while (T--)
        solve();
}

template<typename T, typename Tt> void print(T n, Tt m){
    cout<<'{'<<n<<','<<m<<'}'<<endl;
}

template<typename T> void print(T n){
    cout<<n<<endl;
}

template<typename T> void print(vector<T> v) {
    cout<<'[';
    for(auto val : v){
        cout<<val;
        cout<<' ';
    }
    cout<<']'<<endl;
}
