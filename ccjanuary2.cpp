#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<string> v;

    while(t--){
        int len;
        cin>>len;
        string s;
        cin.ignore();
        getline(cin, s);
        string res;
        for(int i=0; i<len; i+=4){
            string sub;
            sub.push_back(s[i]);
            sub.push_back(s[i+1]);
            sub.push_back(s[i+2]);
            sub.push_back(s[i+3]);
            int bin = stoi(sub, nullptr, 2);
            char c = (char) ((int)'a' + bin);
            res+=c;
        }
        v.push_back(res);
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
    
  return 0;
}