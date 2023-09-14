// ----------------
// 1157 단어 공부
// 
// minjeong
// ----------------

#include <iostream>
#include <algorithm>

using namespace std;

void checkMax(string s) {
    int use_num[26] = {};
    int use_index, max_index;
    char max_word;

    for (int i = 0; i < s.length(); i++) {
        use_index = s[i] - 65;
        use_num[use_index]++;
    }

    max_index = max_element(begin(use_num), end(use_num)) - begin(use_num);
    max_word = max_index + 65;

    // 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ? 출력
    for (int i = 0; i < 26; i++) {
        if (i == max_index) continue;
        if (use_num[i] == use_num[max_index]) max_word = '?';
    }

    cout << max_word;
    
}

int main(void) {
    string cmd;

    cin >> cmd;

    for (int i = 0; i < cmd.length(); i++) {
        cmd[i] = toupper(cmd[i]);
    }

    checkMax(cmd);
    
}