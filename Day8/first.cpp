#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<pair<string,int> >operations;
    while(getline(cin,s)){
        string op="";
        for(int i=0;i<3;i++){
            op+=s[i];
        }
        int index=4;
        bool positive=false;
        if(s[index]=='+'){
            positive=true;
        }
        index++;
        int num=0;
        while(isdigit(s[index])){
            num*=10;
            num+=s[index]-'0';
            index++;
        }
        if(!positive)num*=-1;
        operations.push_back({op,num});
    }
    int index=0;
    int acc=0;
    for(int i=0;i<operations.size();i++){
        cout<<operations[i].first<<" "<<operations[i].second<<endl;
    }
    vector<int>visited(operations.size(),false);
    while(index<operations.size()){
        if(visited[index]==true){
            break;
        }
        else{
            visited[index]=true;
        }
        if(operations[index].first=="nop"){
            index++;
        }
        else
        if(operations[index].first=="acc"){
            acc+=operations[index].second;
            index++;
        }
        else{
            index+=operations[index].second;
        }
    }
    cout<<acc<<"\n";
}