// ----------------
// 2309
// 
// minjeong
// ----------------

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void writeHeight(int array[9]) {

    for (int i=0; i < 9; i++) {
        cin >> array[i];
    }
    
}

void searchNoDwarf(int array[], int sum2, int &index1, int &index2) {
    int temp_sum2;

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            temp_sum2 = array[i] + array[j];
            if (temp_sum2 == sum2) {
                index1 = array[i];
                index2 = array[j];
                break;
            }
        }
    }
}

int main(void) {

    int height_array[9];        // 9명의 키 배열
    int height_dwarf_array[7];  // 난쟁이의 키 배열
    int height_sum9;            // 9명의 키 합
    int sum_no_dwarf;           // 난쟁이가 아닌 2명의 키 합

    writeHeight(height_array);
    
    for (int i = 0; i < 9; i++) {
        height_sum9 += height_array[i];
    }

    sum_no_dwarf = height_sum9 - 100;   // 난쟁이가 아닌 2명의 키 합 구하기

    int index1, index2;
    searchNoDwarf(height_array, sum_no_dwarf, index1, index2);

    list<int> list_height_array(begin(height_array), end(height_array));
    list_height_array.remove(index1);
    list_height_array.remove(index2);
    copy(list_height_array.begin(), list_height_array.end(), height_dwarf_array);

    sort(begin(height_dwarf_array), end(height_dwarf_array));

    for (int i = 0; i < 7; i++) {
        cout << height_dwarf_array[i] << endl;
    }
}
