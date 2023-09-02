// ----------------
// 2138
// 
// minjeong
// ----------------

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N = 0;
int switch_result = 0;

void pushSwitch(int array[], int index) {

    for (int i = index - 1; i <= index + 1; i++) {
        if (i >= 0 && i < N) {
            array[i] = 1 - array[i];
        }
    }
}

bool enableMakeTarget(int current_array[], int target_array[], int& switch_result) {
    
    int temp = 0;

    // 전등 상태 바꾸기
    for (int i = 1; i < N; i++) {
        if (current_array[i - 1] != target_array[i - 1]) {
            pushSwitch(current_array, i);
            temp++;
        }
    }
    switch_result = temp;

    // 전등 스위치 결과
    for (int i = 0; i < N; i++) {
        if (current_array[i] != target_array[i]) {
            switch_result = -1;
            return false;
        }
    }

    return true;

}

int main(void) {

    cin >> N;
    char temp_first_arr[N], temp_end_arr[N];    
    int first_bulb_arr[N], re_first_bulb_arr[N], end_bulb_arr[N]; // 스위치 배열
    int switch_first_off, switch_first_on;


    for (int i = 0; i < N; i++) {
        cin >> temp_first_arr[i];
        first_bulb_arr[i] = temp_first_arr[i] - '0';
        re_first_bulb_arr[i] = first_bulb_arr[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> temp_end_arr[i];
        end_bulb_arr[i] = temp_end_arr[i] - '0';
    }

// 0번 인덱스 스위치 안 누른 경우
   if (enableMakeTarget(first_bulb_arr, end_bulb_arr, switch_first_off)) {
        if (switch_first_off != -1) cout << endl << "결과1: " << switch_first_off;
        // if (switch_result != -1) switch_first_off = switch_result;
   }


   // 0번 인덱스 스위치 누른 경우
   pushSwitch(re_first_bulb_arr, 0);
   if (enableMakeTarget(re_first_bulb_arr, end_bulb_arr, switch_first_on)) {
        switch_first_on++;
        if (switch_first_on != -1) cout << endl << "결과2: " << switch_first_on << endl;
        // if (switch_result != -1) switch_first_on = switch_result;
   }

}