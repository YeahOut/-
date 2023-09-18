// ----------------
// 20365 블로그2
// 
//
// R과 B의 각각 연속된 수를 구함 -> 수가 더 많은 색으로 모든 블로그를 칠함 -> 칠하지 않은 색의 연속된 수 + 처음에 모두 칠한 횟수 1
// minjeong
// ----------------

#include <iostream>

using namespace std;

int countBlog(char array[], char color, int arr_num, int color_num) {
    for (int i = 0; i < arr_num; i++) {
        if (array[i] == color) {
            color_num++;
            for (int j = i; j < arr_num; j++) {
                if (array[j] == color && array[j + 1] == color) continue;
                else if (array[j + 1] != color) {
                    i = j;
                    break;
                }
            }
        }
    }

    return color_num;
}

int main(void) {
    int blog_num, r_num = 0, b_num = 0;
    int min, work_num;
    string blog;
    char R = 'R';
    char B = 'B';

    cin >> blog_num;
    cin >> blog;
    
    char blog_arr[blog_num];
    for (int i = 0; i < blog_num; i++) {
        blog_arr[i] = blog[i];
    }

    r_num = countBlog(blog_arr, R, blog_num, r_num);
    b_num = countBlog(blog_arr, B, blog_num, b_num);

    min = (r_num < b_num) ? r_num : b_num;
    work_num = min + 1;
    
    cout << work_num;
}