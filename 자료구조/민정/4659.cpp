// ----------------
// 4659 비밀번호 발음하기
// 
// minjeong
// ----------------

#include <iostream>

using namespace std;

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

// 조건 1: 모음 하나를 반드시 포함
bool rule1(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            return true;
        }
    }
    return false;
}

bool chechar(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
    return false;
}

// 조건 2: 모음 3개 혹은 자음이 3개 연속으로 오면 안 됨
bool rule2(string s) {
    if (s.length() < 2) return true;

    for (int i = 0; i < s.length() - 2; i++) {
        if (chechar(s[i]) && chechar(s[i + 1]) && chechar(s[i + 2])) {
            return false;
        }
        else if (!chechar(s[i]) && !chechar(s[i + 1]) && !chechar(s[i + 2])) {
            return false;
        }
    }
    return true;
}

// 조건 3: 같은 글자 연속 안 됨 (단, ee와 oo는 허용)
bool rule3(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o') {
            return false;
        }
    }
    return true;
}

int main(void) {
    string cmd;

    while (1) {

        cin >> cmd;

        if (cmd == "end") break;

        if (rule1(cmd) && rule2(cmd) && rule3(cmd)) {
            cout << "<" << cmd << ">" << " is acceptable." << endl;
        } else {
            cout << "<" << cmd << ">" << " is not acceptable." << endl;
        }
        
    }
}