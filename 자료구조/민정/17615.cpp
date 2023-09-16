// ----------------
// 17615 볼 모으기
// 
// minjeong
// ----------------

#include <iostream>

using namespace std;

void searchDifferentBall() {

}

void changeBall() {

}

int main(void) {
    int ball_num;
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
}