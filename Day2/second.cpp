#include<iostream>
using namespace std;

bool isDigit(int a){
    if(a>='0'&&a<='9'){
        return true;
    }
    return false;
}

int main(){
    string s;
    int final_count=0;
    while(getline(cin,s)){
        int startindex=0;
        int u_bound=0;
        int l_bound=0;
        while(isDigit(s[startindex])){
            l_bound*=10;
            l_bound+=(s[startindex]-'0');
            startindex++;
        }
        startindex++; //to skip the - in input
        while(isDigit(s[startindex])){
            u_bound*=10;
            u_bound+=(s[startindex]-'0');
            startindex++;
        }
        startindex++; //to skip the space in input
        char c=s[startindex];
        startindex+=2; //skip the : and space
        int count=0;
        if(s[startindex+l_bound]==c){
            count++;
        }
        if(s[startindex+u_bound]==c){
            count++;
        }
        if(count==1){ //check if one of them equal to c and increment the final count
            final_count++;
        }
    }
    cout<<final_count<<"\n";
}