#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<string> token(string s){
    int start=0;
    string temp = "";
    vector<string>result;
    for( int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            result.emplace_back(temp);
            temp = "";
        }
        else{
            temp += s[i];
        }
    }
    return result;
}

bool parse_passport(string s){
    vector<string> v = token(s);
    unordered_map <string, bool> ump;
    vector<string> required = {"byr","iyr","eyr","hgt","ecl","pid","hcl"};
    for(int i = 0; i < required.size(); i++){
        ump[required[i]] = false;
    }
    for(int i = 0; i < v.size(); i++){
        ump[v[i].substr(0,3)] = true;
    }
    for(auto it = ump.begin(); it != ump.end(); it++){
        if(it->second == false)
        return false;
    }
    return true;
}

int main(){
    string s;
    int count=0;
    string passport = "";
    while(getline(cin,s)){
        if(s.empty()){
            if(parse_passport(passport)){
                count++;
            }
            passport = "";
        }
        else{
            passport.append(s + " ");
        }
    }
    if(parse_passport(passport)){
        count++;
    }
    cout<<count<<"\n";   
}