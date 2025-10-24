#include <string>
#include <vector>

using namespace std;

//x : depth y : depth의 y번째 수의 최대값
int Table[502][502];



int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    Table[0][0] = triangle[0][0];
    Table[1][0] = Table[0][0] + triangle[1][0];
    Table[1][1] = Table[0][0] + triangle[1][1];

    int size = (int)triangle.size();

    for(int i = 2; i < size; ++i)
    {
        Table[i][0] = Table[i-1][0] + triangle[i][0];
        Table[i][i] = Table[i-1][i-1] + triangle[i][i];
        for(int j = 1; j < i; ++j)
        {
            Table[i][j] = max(Table[i-1][j-1] + triangle[i][j], Table[i-1][j] + triangle[i][j]);
        }
    }
    
    for(int i = 0; i < size; ++i)
    {
        answer = max(Table[size-1][i], answer);
    }
    
    return answer;
}