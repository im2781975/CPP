#include<bits/stdc++.h>
https://codeforces.com/problemset/problem/4/C
// 4C. Registration system
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string str; cin >> str;
        map <string, int> mp;
        if(!mp[str])    cout << "OK" << endl;
        else    cout << str + to_string(mp[str]);
        /*
        if(mp[str] >= 1)    cout << str << mp[str] << endl;
        else    cout << "Ok" << endl;
        if(mp[str] == 0)    cout << "Ok" << endl;
        else    cout << str << mp[str] << endl;    */
        ++mp[str];
    }
}
