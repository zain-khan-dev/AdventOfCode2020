#include<iostream>
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
    int max_id=INT_MIN;
    while(getline(cin,s)){
        int low=0;
        int high=127;
        int a=getPosition(0,127,'F','B',0,7,s);
        int b=getPosition(0,7,'L','R',7,10,s);
        max_id=max(max_id,a*8+b);
    }
    cout<<max_id<<"\n";
}