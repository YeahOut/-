// ----------------
// 17615 볼 모으기
// 
// minjeong
// ----------------

#include <iostream>

using namespace std;

int ball_num;

void changeBall(int index_origin, int index_change, char array[], int& num) {
    char temp;

    temp = array[index_change];
    array[index_change] = array[index_origin];
    array[index_origin] = temp;
    num++;
}

void searchDifferentBall(char array[], char right, int& num) {
    int origin_index, change_index;

    for (int i = ball_num - 2; i >= 0; i--) {
        if (array[i] != right && array[i + 1] == right) {
                change_index = i;
            }
        else {
            if (array[i] == right && array[i + 1] != right) {
                origin_index = i;
                changeBall(origin_index, change_index, array, num);
                i = change_index;
            }
        }
    }
}

int main(void) {
    string cmd;
    int change_num = 0;

    cin >> ball_num;
    cin >> cmd;

    char ball_array[ball_num];
    char rightMostBall;
    for (int i = 0; i < ball_num; i++) {
        ball_array[i] = cmd[i];
    }
    rightMostBall = ball_array[ball_num - 1];

    searchDifferentBall(ball_array, rightMostBall, change_num);

    cout << change_num;
}