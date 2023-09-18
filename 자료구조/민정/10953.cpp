// ----------------
// 10953 A + B - 6
// 
// minjeong
// ----------------

#include <iostream>

using namespace std;

int main(void) {
    int line, A, B;
    char comma;

    cin >> line;

    for (int i = 0; i < line; i++) {
        cin >> A >> comma >> B;

        cout << A + B << endl;
    }
}