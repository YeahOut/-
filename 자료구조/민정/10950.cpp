// ----------------
// 10950 A + B - 3
// 
// minjeong
// ----------------

#include <iostream>

using namespace std;

int main(void) {
    int line, A, B;

    cin >> line;

    for (int i = 0; i < line; i++) {
        cin >> A >> B;
        cout << A + B << endl;
    }
}