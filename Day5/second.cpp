#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

int getPosition(int low,int high,char up,char down,int start,int end,string s){
    for(int i=start;i<end;i++){
        int mid=(low+high)/2;
        if(s[i]==up){
            high=mid;
        }
        else
        if(s[i]==down){
            low=mid;
        }
    }
    return high;
}

int main(){
    string s;
    unordered_map<int,bool>ump;
    int max_id=INT_MIN;
    while(getline(cin,s)){
        int low=0;
        int high=127;
        int a=getPosition(0,127,'F','B',0,7,s);
        int b=getPosition(0,7,'L','R',7,10,s);
        ump[a*8+b]=true;
        max_id=max(max_id,a*8+b);
    }
    for(int i=0;i<max_id;i++){
        if(ump[i]==false){
            if(ump[i-1]==true&&ump[i+1]==true){
                cout<<i<<"\n";
                break;
            }
        }
    }
}