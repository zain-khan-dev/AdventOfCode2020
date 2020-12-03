#include<bits/stdc++.h>
using namespace std;

long long int find_trees(const vector<vector<char> >&v,int r_incr,int c_incr){
    int row=0,col=0;
    long long int count=0;
    while(row < v.size()){
        if(v[row][col] == '#'){
            count++;
        }
        row += r_incr;
        col += c_incr;
        col %= v[0].size();
    }
    return count;
}

int main(){
    int c;
    vector<vector<char> >v;
    vector<char>temp;
    while((c = getchar()) != EOF){
        if(c == '\n'){
            v.emplace_back(temp);
            temp.clear();
            continue;
        }
        temp.emplace_back(c);
    }
    long long int prod = 1;
    vector<int>r_incr = {1,1,1,1,2};
    vector<int>c_incr = {1,3,5,7,1};
    for(int i = 0;i < r_incr.size();i++){
        prod *= find_trees(v,r_incr[i],c_incr[i]);
    }
    cout<<prod<<"\n";
}