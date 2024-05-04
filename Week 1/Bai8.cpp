// Bai toan tim mien lien thong
#include<iostream>

using namespace std;

void loang(int i, intj) {
        flag[i][j] = true;
        if (j > 0) //Loang sang o ben trai
            if((O[i][j-1] == O[i][j]) && (!flag[i][j-1]))
                loang(i, j -1);
        if (i > 0) //Loang o ben tren
            if((O[i-1][j] == O[i][j]) && (!flag[i-1][j]))
                loang(i -1, j);
        if (j < 5) //Loang o ben phai
            if((O[i][j+1] == O[i][j]) && (!flag[i][j+1]))
                loang(i, j + 1);
        if (i < 4) //Loang o ben duoi
            if((O[i+1][j] == O[i][j]) && (!flag[i+1][j]))
                loang(i + 1, j);
}
