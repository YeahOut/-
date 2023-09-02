// ----------------
// 2138
// 
// minjeong
// ----------------

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void pushSwitch() {

}


int main(void) {

    int N = 0;  // 전구 개수
    cin >> N;
    char temp_first_arr[N], temp_end_arr[N];    
    int first_bulb_arr[N], end_bulb_arr[N]; // 스위치 배열
    int push_switch = 0;


    for (int i = 0; i < N; i++) {
        cin >> temp_first_arr[i];
        first_bulb_arr[i] = temp_first_arr[i] - '0';
    }
    for (int i = 0; i < N; i++) {
        cin >> temp_end_arr[i];
        end_bulb_arr[i] = temp_end_arr[i] - '0';
    }

    
}