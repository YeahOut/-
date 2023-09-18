// ----------------
// 1010 다리 놓기
// 
// 
// 문제 조건에서 동쪽의 다리는 서쪽의 다리 개수보다 항상 많음 & 겹쳐지면 안됨(순서가 존재함)
// (동쪽에서 서쪽으로 연결할 수 있는 경우의 수 / 겹쳐지는 경우의 수) -> 조합(combination) 이용!!
// 동쪽 개수: M, 서쪽 개수: N -> mCn = m!/n!(m-n)! = ( m*(m-1)*...*(m-n+1) )/n!
// 
// 29!, 30! 에서는 int의 범위를 넘어감 -> 조합의 결과 범위가 int를 넘어가지 않도록 함수를 구현해야함 (단순하게 factorial로 계산하면 안됨)
// 
//
// minjeong
// ----------------

#include <iostream>

using namespace std;

int combination(int m, int n) {
    int result = 1;

    for (int i = 1; i <= n; i++) {
        result *= m - n + i;
        result /= i;
    }

    return result;
}

int main(void) {
    int line, east_bridge, west_bridge;
    int bridge_case_num;

    cin >> line;

    for (int i = 0; i < line; i++) {    
        cin >> west_bridge >> east_bridge;

        bridge_case_num = combination(east_bridge, west_bridge);

        cout << bridge_case_num << endl;
    }
}