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

int recur(unordered_map<int,vector<pair<int,int> > >dfump,int element){
    int result=0;
    vector<pair<int,int> >v=dfump[element];
    for(int i=0;i<v.size();i++){
        result+=(v[i].first*(recur(dfump,v[i].second)));
    }
    return result+1;
}


int main(){
    string s;
    unordered_map<string,int>ump;
    unordered_map<int,vector<pair<int,int> > >dfump;
    int index=0;
    while(getline(cin,s)){
        vector<string>token=gettoken(s);
        string temp="";
        int to=-1;
        int i=0;
        int no=-1;
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
                dfump[to].push_back({no,ump[temp]});
                temp="";
                i++;
                if(token[i][0]>='0'&&token[i][0]<='9'){
                    no=token[i][0]-'0';
                }
                if(i<token.size()&&token[i]=="contain")i++;   
                if(token[i][0]>='0'&&token[i][0]<='9'){
                    no=token[i][0]-'0';
                }
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
            if(temp!="other"){

            dfump[to].push_back({no,ump[temp]});
            }
            
        }
    }
    cout<<recur(dfump,ump["shinygold"])-1;
}