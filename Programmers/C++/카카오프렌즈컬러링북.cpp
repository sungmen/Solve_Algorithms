#include <vector>

using namespace std;
int pos[2]= {-1, 1};
int m_, n_, cnt = 0;

void dfs(int row, int col, vector<vector<int> > pic, vector<vector<bool>> &chk) {
    if (chk[row][col]) {
        return;
    }
    chk[row][col] = 1;
    cnt++;
    for (int i = 0; i < 2; i++) {
        if (((row + pos[i]) >= 0 && (row + pos[i]) < m_) && chk[row + pos[i]][col] == 0 && pic[row + pos[i]][col] == pic[row][col]) {
            dfs((row+pos[i]), col, pic, chk);
        }
        if (((col + pos[i]) >= 0 && (col + pos[i]) < n_) && chk[row][col+ pos[i]] == 0 && pic[row][col+ pos[i]] == pic[row][col]) {
            dfs(row, (col+pos[i]), pic, chk);
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    m_ = m;
    n_ = n;
    
    vector <vector <bool> > chk (m, vector <bool> (n, false));
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(!chk[i][j] && picture[i][j] != 0) {
                dfs(i, j, picture, chk);
                max_size_of_one_area = max_size_of_one_area < cnt ? cnt : max_size_of_one_area;
                number_of_area++;
                cnt = 0;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}