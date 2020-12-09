#include<bits/stdc++.h>
typedef long long int lli; 
using namespace std;

lli to_numeric(string s){
    lli result=0;
    for(int i=0;i<s.size();i++){
        result*=10;
        result+=s[i]-'0';
    }
    return result;
}

int main(){
    string s;
    vector<lli>v;
    while(getline(cin,s)){
        long long int k=to_numeric(s);
        v.push_back(k);
    }

    int start=0;
    int end=25;
    unordered_set<lli>us;
    for(int i=0;i<25;i++){
        us.insert(v[i]);
    }
    for(int i=25;i<v.size();i++){
        lli element=v[i];
        bool inside=false;
        for(int j=start;j<end;j++){
            if(us.count(element-v[j])>0&&element!=2*v[j]){
                inside=true;
                break;
            }
        }
        if(!inside){
            cout<<v[i];
            break;
        }
        us.erase(v[start]);
        us.insert(v[end]);
        start++;
        end++;
    }
}