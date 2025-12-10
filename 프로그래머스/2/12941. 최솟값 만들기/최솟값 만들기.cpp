#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    //큰수와 작은수를 곱하는 방향으로 그리디적인 풀이?
    
    sort(A.begin(), A.end());
    
    //내림차순 정렬
    sort(B.begin(), B.end(), greater<int>());

    int Size = (int)A.size();
    
    for(int i = 0; i < Size; ++i)
    {
       answer += A[i]*B[i];       
    }
    
    
    return answer;
}