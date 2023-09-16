// ----------------
// 17615 볼 모으기
// 
// minjeong
// ----------------

#include <iostream>

using namespace std;

int ball_num;

void changeBall(int index_origin, int index_change, char array[]) {
    char temp;

    temp = array[index_change];
    array[index_change] = array[index_origin];
    array[index_origin] = temp;

    cout << endl;
    cout << "바뀐 배열: ";
    for (int i = 0; i < ball_num; i++) {
        cout << array[i];
    }
}

void searchDifferentBall(char array[], char right) {
    int origin_index, change_index;

    // char new_array[ball_num];

    // for (int i = 0; i < ball_num; i++) {
    //     new_array[i] = array[i];
    // }

    for (int i = ball_num - 2; i >= 0; i--) {
        // if (array[i] != right) continue;
        if (array[i] != right && array[i + 1] == right) {
                change_index = i;
                // cout << endl;
                // cout << "여기 바꿔야: " << change_index << endl;
            }
        else {
            // if (array[i] != right && array[i + 1] == right) {
            //     change_index = i;
            //     cout << endl;
            //     cout << "여기 바꿔야: " << change_index << endl;
            // }
            if (array[i] == right && array[i + 1] != right) {
                // cout << endl;
                // cout << "여기 같은: " << i << endl;
                origin_index = i;
                // changeBall(origin_index, change_index, new_array);
                changeBall(origin_index, change_index, array);
            }
        }
    }
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