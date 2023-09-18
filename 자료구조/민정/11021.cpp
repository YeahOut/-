// ----------------
// 11021 A + B -7
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

        cout << "Case #" << i + 1 << ": " << A + B << endl;
    }
}