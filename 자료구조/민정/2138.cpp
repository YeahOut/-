// -------------------------------
// 2138 전구와 스위치
// 
// 
// "0번 인덱스의 스위치를 '누른다/누르지 않는다'가 이미 정해져 있다면, 0번 전구에 영향을 주는 스위치는 1번 뿐. 
//  따라서 만들고자 하는 상태가 주어졌을 때, 0번 전구의 상태에 따라 1번(과 그 이상) 전구 스위치 상태를 결정할 수 있음"
// ex) 만들고자 하는 전구 상태 예시: 0 0 0 0 -> 0 1 1 1 ...
// 1) 0번 스위치를 누르는 경우
// - 1 1 0 0 ... (1)
// - 0 0 1 0 ... (2)
// - 0 1 0 1 ... (3)
// - 0 1 1 0 ... (4)
// ...
// 
// 2) 0번 스위치를 누르지 않는 경우
// - 0 0 0 0 ... (0)
// - 0 0 0 0 ... (0)
// - 0 1 1 1 ... (1)
//
// 3) 최소 시간 비교
// 
//
// minjeong
// -------------------------------

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N = 0;              // 전등 개수
int switch_result = 0;  // 스위치 입력 횟수

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

int searchMin(int result1, int result2) {

    if (result1 != -1 && result2 != -1) {
        return min(result1, result2);
    } else if (result1 == -1 && result2 == -1){
        return -1;  // 불가능할 경우 -1 출력
    } else {
        return (result1 > 0) ? result1 : result2;
    }

}


int main(void) {

    cin >> N;
    char temp_first_arr[N], temp_end_arr[N];    
    int first_bulb_arr[N], re_first_bulb_arr[N], end_bulb_arr[N];   // 전구 배열
    int switch_first_off, switch_first_on;                          // 0번 전구 누를/안 누를 경우 스위치 횟수


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
    enableMakeTarget(first_bulb_arr, end_bulb_arr, switch_first_off);


   // 0번 인덱스 스위치 누른 경우
   pushSwitch(re_first_bulb_arr, 0);
   if (enableMakeTarget(re_first_bulb_arr, end_bulb_arr, switch_first_on)) {
        switch_first_on++;
   }

   cout << searchMin(switch_first_off, switch_first_on) ;
}