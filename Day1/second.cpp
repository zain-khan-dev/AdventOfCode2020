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
    bool done=false;
    for(int i = 0;i < v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(2020 - v[i] - v[j] >= 0 && hash[2020- v[i] - v[j]] == true){ //check wether the difference of 2020 with other two sum exist
                cout<<v[i] * (2020-v[i]-v[j]) * v[j]<<"\n";
                done=true; //Found the solution now exit
                break;
            }
        }
        if(done)break; //found the solution break from outside loop
    }
}