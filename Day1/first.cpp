#include<iostream>
#include<vector>
using namespace std;

int toNumber(string s){
    int num=0;
    for(int i=0;i<s.size();i++){
        num*=10;
        num+=(s[i]-'0');
    }
    return num;
}

int main(){
    int c;
    vector<int>v; 
    string s;
    vector<bool>hash(3000,false);
    while(getline(cin,s)){
        int num=toNumber(s);
        v.emplace_back(num);
        hash[num]=true;
    }
    for(int i = 0;i < v.size();i++){
        if(2020 - v[i] >= 0 && hash[2020- v[i]] == true){
            cout<<v[i] * (2020-v[i]);
            break;
        }
    }
}