#include <iostream>

#include <vector>
using namespace std;

char a[8][8];
int main(void) {
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'F' && (i+j)%2==0 ) cnt++;
        }
    }
    cout << cnt;
    
}