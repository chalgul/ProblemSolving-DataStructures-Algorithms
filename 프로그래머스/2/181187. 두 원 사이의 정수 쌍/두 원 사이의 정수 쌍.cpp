#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    
    //x^2 + y^2 = r^2 원의 방정식 형태
    
    //원점으로부터 정수 좌표의 거리 값이 r1의 반지름보다 크거나 같으면서 r2의 반지름보다 작으면 될 듯
    
    //반지름이 최대 백만
    
    //20 40 72 104 140
    
    long long R2 = r2;
    
    int a,b;
    for(int i = 1; i <= r1; ++i)
    {
       a = floor(sqrt(R2 * R2 - (long long)i * i));
       //a = floor(sqrt(pow(r2,2) - pow(i,2)));
       b = ceil(sqrt(pow(r1,2) - pow(i,2)));
    
       answer += (a - b + 1);
    }
    
    for(int i=r1+1; i<=r2; i++)
    {
        a = floor(sqrt(pow(r2,2)-pow(i,2)));
        answer += (a+1);
    }
    
    
   
    answer *= 4;    
    
    return answer;
}
