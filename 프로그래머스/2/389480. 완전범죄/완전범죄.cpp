#include <string>
#include <vector>
#include <algorithm>


using namespace std;


int cmp(const vector<int>& a, const vector<int>& b)
{
    if(a[0] - a[1] == b[0] - b[1])
    {
        return a[0]/a[1] > b[0]/b[1];
    }
    else
    {
        return a[0] - a[1] > b[0] - b[1];
    }
}



int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;


    sort(info.begin(), info.end(), cmp);
    
    int A_sum = 0;
    int B_sum = 0;
    
    for(int i = 0; i < info.size(); i++)
    {
        if(B_sum + info[i][1] < m)
        {
            B_sum += info[i][1];
        }
        else if(A_sum + info[i][0] < n)
        {
             A_sum += info[i][0];
        }
        else
        {
            return -1;
        }
    }
    
    return A_sum;
}














