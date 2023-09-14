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

// 조건 2: 모음 3개 혹은 자음이 3개 연속으로 오면 안 됨
void rule2() {

}

// 조건 3: 같은 글자 연속 안 됨 (단, ee와 oo는 허용)
void rule3() {

}

int main(void) {
    string cmd;

    while (1) {

        cin >> cmd;

        if (cmd == "end") break;

        if (rule1(cmd)) cout << cmd << ": " << rule1(cmd) << endl;   
        
    }
}