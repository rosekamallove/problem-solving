#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long

vector<bool> pred;

bool predicate(vector<int> &v, int h, int m){
    int temp(0);
    for(int i=0; i<v.size(); i++){
        if(v[i] - h > 0)
            temp += v[i] - h;
    }
    return temp >= m;
}

void itr(vector<int> &v, int n, int m ){
    vector<int> z = v;
    sort(z.begin(), z.end());
    for(int h=0; h<z[z.size()-1]; h++){
        pred.push_back(predicate(v, h, m));
    }
    int ans = *(lower_bound(pred.begin(),pred.end(), 0));
    for(int i=0; i<pred.size(); i++){
        if(!pred[i]){
            ans = i-1;
            break;
        }
    }
    cout<<ans<<endl;
}

void bnrySrch(vector<int> &v, int n, int m){
    int hi(1e9), lo(0);
    //Find the Last True:
    while(hi - lo > 1){
        int mid = (hi+lo) / 2;
        if(predicate(v,mid,m)){
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    if(predicate(v,hi,m)){
        cout<<hi<<endl;
    } else {
        cout<<lo<<endl;
    }
}


signed main(){
    //Predicate Function:
    int n, m; cin>>n>>m;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    bnrySrch(v, n, m);
}
/**************************************************************************************/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int maxElement(vector<int> &v){
//    int mx(0);
//    for(int i=0; i<v.size(); i++){
//        mx = max(mx, v[i]);
//    }
//    return mx;
//}
//
//int minElement(vector<int> &v){
//    int mx(0);
//    for(int i=0; i<v.size(); i++){
//        mx = min(mx, v[i]);
//    }
//    return mx;
//}
//
//vector<int> sumhsh(1e5, 0);
//
//int solveB(vector<int> &v, int n, int m){
//    int sum(0);
//    for(int i=maxElement(v); i > 0; i--){
//        for(int j=0; j<n; j++){
//            if(v[j] - i > 0)
//                sum += v[j] - i;
//        }
//        if(sum >= m){
//            sumhsh[i] = sum;
//        }
//    }
//    //sort(sumhsh.begin(), sumhsh.end());
//    for(int i=0; i<sumhsh.size(); i++){
//        if(sumhsh[i] >= m){
//            cout<<sumhsh[i]<<endl;
//            return i;
//        }
//    }
//    return -1;
//}
//
//int main(){
//    int n,m; cin>>n>>m;
//    vector<int> v(n);
//    for(int i=0; i<n; i++){
//        cin>>v[i];
//    }
//    cout<<solveB(v, n, m)<<endl;
//}
