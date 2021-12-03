#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    // int n,k,d;
    vector<string> v;

    while(t--){
        int len;
        cin>>len;
        string s;
        cin.ignore();
        //PROBLEM WAS TO AD THIS LINE SO THAT YOUR CODE CAN DIFFRENTIATE
        //BETWEEN NEW LINE AND START TAKING INPUT FROM NEXT LINE........
        getline(cin, s);
        // for( int i=0; i<len; i++){
        //     char c;
        //     cin>>c;
        //     s.push_back(c);
        // }
        // int len = s.length();
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
        // t--;
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
    
  return 0;
}