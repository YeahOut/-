// ----------------
// 17615 볼 모으기
// 
// minjeong
// ----------------

#include <iostream>

using namespace std;


void changeBall(int index_origin, int index_change, char array[], int& num) {
    char temp;

    temp = array[index_change];
    array[index_change] = array[index_origin];
    array[index_origin] = temp;
    num++;
}

void searchDifferentBall(char array[], char right, int& num, int start_index) {
    int origin_index, change_index;

    for (int i = start_index; i >= 0; i--) {
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
    int ball_num, ball_num_2;
    string cmd;
    int change_num = 0, change_num_2 = 0;
    int min, second_ball_index;

    cin >> ball_num;
    cin >> cmd;

    char ball_array[ball_num], ball_array2[ball_num];
    char right_ball_1, right_ball_2;
    for (int i = 0; i < ball_num; i++) {
        ball_array[i] = cmd[i];
        ball_array2[i] = cmd[i];
    }
    right_ball_1 = ball_array[ball_num - 1];

    searchDifferentBall(ball_array, right_ball_1, change_num, ball_num - 2);


    min = change_num;

    change_num = 0;
    for (int i = ball_num - 1; i >= 0; i--) {
        if (ball_array2[i] != right_ball_1) {

            changeBall(i, ball_num - 1, ball_array2, change_num);
            right_ball_2 = ball_array2[ball_num - 1];
            break;
        }
    }

    searchDifferentBall(ball_array2, right_ball_2, change_num, ball_num - 2);

    min = (min < change_num) ? min : change_num;

    cout << min;
}