#include<bits/stdc++.h>
#include<string.h>
using namespace std;

vector<string>gettoken(string s){
    int index=0;
    vector<string>result;
    string temp="";
    while(index<s.size()){
        if(s[index]==' '){
            result.push_back(temp);
            temp="";
        }
        if(s[index]!=' ')
        temp+=s[index];
        index++;
    }
    return result;
}

int main(){
    string s;
    unordered_map<string,int>ump;
    unordered_map<int,vector<int> >dfump;
    int index=0;
    while(getline(cin,s)){
        vector<string>token=gettoken(s);
        string temp="";
        int to=-1;
        int i=0;
        while(i<token.size()){
            if(token[i]=="bags"||token[i]=="bag"||token[i]=="bag,"||token[i]=="bags,"){                
                if(temp=="other")continue;
                if(ump.find(temp)==ump.end()){
                    ump[temp]=index;
                    index++;       
                }
                if(to==-1)
                    to=ump[temp];
                if(ump[temp]!=to)
                dfump[ump[temp]].push_back(to);
                temp="";
                i++;
                if(i<token.size()&&token[i]=="contain")i++;   
            }
            else{
                temp+=token[i];
            }
            i++;
        }
        if(temp!=""){
            if(ump.find(temp)==ump.end()&&temp!="other"){
                ump[temp]=index;
                index++;                    
            }
            if(temp!="other")
            dfump[ump[temp]].push_back(to);
        }
    }
    int start=ump["shinygold"]; //start dfs from here
    stack<int>st;
    unordered_set<int>visited;
    vector<int>k=dfump[start];
    st.push(start);
    int count=0;
    while(!st.empty()){
        int element=st.top();
        visited.insert(element);
        st.pop();
        count++;
        vector<int>adf=dfump[element];
        for(int i=0;i<adf.size();i++){
            if(visited.count(adf[i])==0){
                visited.insert(adf[i]);
                st.push(adf[i]);
            }
        }
    }
    cout<<count-1;
}