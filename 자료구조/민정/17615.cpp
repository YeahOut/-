// ----------------
// 17615 볼 모으기
// 
// minjeong
// ----------------

#include <iostream>

using namespace std;

int ball_num;

void searchDifferentBall(char array[], char right) {
    for (int i = ball_num - 2; i >= 0; i--) {
        if (array[i] != right) continue;
        else {
            if (array[i] == right && array[i + 1] != right) {
                // cout << endl;
                // cout << "여기 같은: " << i << endl;
            }
        }
    }
}

void changeBall() {

}

int main(void) {
    // int ball_num;
    string cmd;
    

    cin >> ball_num;
    cin >> cmd;

    char ball_array[ball_num];
    char rightMostBall;
    for (int i = 0; i < ball_num; i++) {
        ball_array[i] = cmd[i];
    }
    rightMostBall = ball_array[ball_num - 1];

    // cout << endl;
    // cout << "ri: " << rightMostBall;

    searchDifferentBall(ball_array, rightMostBall);
}