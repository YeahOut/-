// ----------------
// 1157 단어 공부
// 
// minjeong
// ----------------

#include <iostream>

using namespace std;

void checkMax(string s) {
    int use_num[26] = {};
    int s_index;

    for (int i = 0; i < s.length(); i++) {
        s_index = s[i] - 65;
        use_num[s_index]++;
    }

    for (int i=0; i<26; i++) {
        cout << use_num[i] << " / ";
    }
}

int main(void) {
    string cmd;

    cin >> cmd;

    cout << endl;
    for (int i = 0; i < cmd.length(); i++) {
        cmd[i] = toupper(cmd[i]);
    }

    checkMax(cmd);
    
}