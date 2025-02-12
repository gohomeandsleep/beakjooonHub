#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    int result[26];
        for (int i = 0; i < 26; i++){
        result[i] = 0;
    }
    
    for (int i = 0; i < s.size(); i++){
        int k = s[i] - 'a';
        result[k] += 1;
    }
    
    for (int i = 0; i < 26; i++){
        cout << result[i] << " ";
    }
    
    return 0;
}