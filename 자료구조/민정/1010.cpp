// ----------------
// 1010 다리 놓기
// 
// 
// 문제 조건에서 동쪽의 다리는 서쪽의 다리 개수보다 항상 많음 & 겹쳐지면 안됨(순서가 존재함)
// (동쪽에서 서쪽으로 연결할 수 있는 경우의 수 / 겹쳐지는 경우의 수) -> 조합(combination) 이용!!
// 동쪽 개수: M, 서쪽 개수: N -> mCn = m!/n!(m-n)! = ( m*(m-1)*...*(m-n+1) )/n!
// 
// minjeong
// ----------------

#include <iostream>

using namespace std;

long long factorial(int start, int end) {
    long long result = 1;
    for (int i = start; i >= end; i--) {
        result *= i;
    }
    return result;
}

int main(void) {
    int line, east_bridge, west_bridge;
    int bridge_case_num;

    cin >> line;

    for (int i = 0; i < line; i++) {
        cin >> west_bridge >> east_bridge;

        bridge_case_num = factorial(east_bridge, east_bridge - west_bridge + 1) / factorial(west_bridge, 1);

        cout << bridge_case_num << endl;
    }
}