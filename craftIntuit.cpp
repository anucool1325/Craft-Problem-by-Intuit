#include<bits/stdc++.h>
using namespace std;
int minDeletions(string s) {
    map<char,int> freq_map;       //for storing the freq of each letter

    for(int i=0;i<s.size();i++)   //updating the frequency of the letters
        freq_map[s[i]]++;

    vector<int> freq;
    for(auto x:freq_map)
        freq.push_back(x.second);

    sort(freq.begin(),freq.end());

    int delete_count=0;                                             //for keeping track of the count of deleting letters
    int current_max_frequency_allowed=freq[freq.size()-1]-1;        //for keeping track of max allowed freq at this time

    for(int i=freq.size()-2;i>=0;i--){
        if(current_max_frequency_allowed<=0){                       //max freq allowed is zero :(
            delete_count+=freq[i];
            continue;
        }
        
        while(freq[i]>current_max_frequency_allowed){               // providing max available freq
            delete_count++;
            freq[i]--;
        }

        current_max_frequency_allowed=freq[i]-1;
    }

    return delete_count;
}

bool checkString(string s){
    for(int i=0;i<s.size();i++)
        if(s[i]-'a'>25 || s[i]-'a'<0)
            return false;

    return true;
}

int main(){
    string s;
    cout<<"Enter the string\n";
    cin>>s;
    if(checkString(s))
        cout<<"Minimum number of character needs to be deleted to make s good is "<<minDeletions(s)<<"\n";
    else
        cout<<"Invalid Input";

    return 0;
}