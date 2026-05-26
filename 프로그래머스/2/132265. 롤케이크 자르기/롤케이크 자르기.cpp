#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    
    //결국 반으로 가르게 되면 롤케이크 전체를 어떤 방식으로든 양분하게 되어있음
    //hash map을 두개 생성한 다음, 양분하는 각 방향의 롤케익에 해당한다고 가정
    //map first : 토핑 종류 map second : 해당 영역의 토핑 개수
    
    
    unordered_map<int, int> A;
    unordered_map<int, int> B;
    
    for(int i = 0; i < topping.size(); ++i)
    {
        B[topping[i]] += 1;           
    }
    
    
    
    for(int i = 0; i < topping.size(); ++i)
    {
        A[topping[i]] += 1;
        B[topping[i]] -= 1;
        
        if(B[topping[i]] == 0)
            B.erase(topping[i]);
        
        if(A.size() == B.size())
            answer++;
        
    }
    

    
    return answer;
}