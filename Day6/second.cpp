#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    vector<int>hash(26,0);
    int sum=0;
    int index=0;
    while(getline(cin,s)){
        if(s.empty()){
            for(int i=0;i<hash.size();i++){
                sum+=(hash[i]==index)?1:0;
            }
            for(int i=0;i<26;i++){
                hash[i]=0;
            }
            index=0;
        }
        else{
            for(int i=0;i<s.size();i++){
                hash[s[i]-'a']++;
            }
        index++;
        }
    }
    if(!s.empty()){
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']++;
        }
        index++;
        for(int i=0;i<hash.size();i++)
        {
            sum+=(hash[i]==index)?1:0;
        }
    }
    cout<<sum<<"\n";
}