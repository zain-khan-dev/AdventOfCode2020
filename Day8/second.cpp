#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<pair<string,int> >operations,temp;
    vector<int>search;
    while(getline(cin,s)){
        string op="";
        for(int i=0;i<3;i++){
            op+=s[i];
        }
        if(op=="jmp"||op=="nop"){
            search.push_back(operations.size());
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
    
    for(int i=0;i<search.size();i++){
        int index=0;
        int acc=0;
        vector<int>visited(operations.size(),false);
        bool done=true;
        while(index<operations.size()){
            string op=operations[index].first;
            if(index==i){
                op=op=="nop"?"jmp":"nop";
            }
            if(visited[index]==true){
                done=false;
                break;
            }
            else{
                visited[index]=true;
            }
            if(op=="nop"){
                index++;
            }
            else
            if(op=="acc"){
                acc+=operations[index].second;
                index++;
            }
            else{
                index+=operations[index].second;
            }
        }
        if(done){
            cout<<acc<<"\n";
            break;
        }
    }
}