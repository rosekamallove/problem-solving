#include<iostream>
using namespace std;

int main(){
    string s; 
    while(getline(cin,s)){
        if(s.empty()){
            break;
        } else {
            cout<<"NO"<<endl;
        }
    }
}
