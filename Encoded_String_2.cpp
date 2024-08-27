#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> encodedstring(string s){
    vector<int> ans(26, 0);
    int i = 0;
    while(i<s.size()){
        if(s[i]=='#' && s[i+1]=='('){
            int occ = s[i+2]-'0';
            int first = s[i-2]-'0';
            int second = s[i-1]-'0';
            string temp = "";
            temp += to_string(first);
            temp += to_string(second);
            int num = stoi(temp);
            ans[first-1]--, ans[second-1]--;
            ans[num-1] += occ;
            i = i+4;
        }else if(s[i]=='#'){
            int first = s[i-2]-'0';
            int second = s[i-1]-'0';
            string temp = "";
            temp += to_string(first);
            temp += to_string(second);
            int num = stoi(temp);
            ans[first-1]--, ans[second-1]--;
            ans[num-1]++;
            i++;
        }else if(s[i]=='('){
            int occ = s[i+1]-'0';
            int num = s[i-1]-'0';

            ans[num-1]+=occ-1;
            i+=3;
        }else{
            int num = s[i]-'0';
            ans[num-1]++;
            i++;
        }
    }
    return ans;
}

int main(){
    vector<string> str = {"23#(2)24#25#26#23#(3)", "1226#24#", "1(2)23(2)", "2110#(2)"};
    for(auto i: str){
        vector<int> ans = encodedstring(i);
        cout<<"-->";
        for(auto i: ans){
            cout<<i<<" ";
        }cout<<endl;
    }
    return 0;
}