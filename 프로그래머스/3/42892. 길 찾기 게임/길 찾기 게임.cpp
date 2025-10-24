#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

//y값을 기준으로 내림차순으로 정렬
//y값이 동일할 경우 x값을 기준으로 오름차순으로 정렬

//1.y값 2.x값 3.노드 번호 순으로 입력 받을 예정
vector<tuple<int,int,int>> Node;

vector<tuple<int,int,int>> LC;
vector<tuple<int,int,int>> RC;


bool cmp(const tuple<int,int,int>& A, const tuple<int,int,int>& B)
{
    auto [AY, AX, NodeA] = A;
    auto [BY, BX, NodeB] = B;
    
    if(AY != BY)
    {
        return AY > BY;
    }
    else
    {
        return AX < BX;
    }
}

void SetTree(const tuple<int,int,int>& A, const tuple<int,int,int>& B)
{
    auto [AY, AX, NodeA] = A;
    auto [BY, BX, NodeB] = B;
    
    //B노드가 A노드의 왼쪽 서브트리에 속함
    if(BX < AX)
    {
       auto [TempY, TempX, TempNode] = LC[NodeA];
       if(TempNode == -1)
       {
           LC[NodeA] = B;
       }
       else
       {
           SetTree(LC[NodeA] , B);
       }
    }
    //B노드가 A노드의 오른쪽 서브트리에 속함
    else
    {
        auto [TempY, TempX, TempNode] = RC[NodeA];
        if(TempNode == -1)
        {
            RC[NodeA] = B;
        }
        else
        {
            SetTree(RC[NodeA], B);
        }
    }
}

 vector<vector<int>> Answer;

//전위 순회
//root - left - right
void Preorder(tuple<int,int,int> R)
{
    
    auto [Y,X,Num] = R;
    
    if(Num == -1)
        return;
    
    Answer[0].push_back(Num);
    Preorder(LC[Num]);
    Preorder(RC[Num]);
}

//후위 순회
//left - right - root
void Postorder(tuple<int,int,int> R)
{
    auto [Y,X,Num] = R;
    
    if(Num == -1)
        return;
    
    Postorder(LC[Num]);
    Postorder(RC[Num]);
    Answer[1].push_back(Num);
}



vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    
    Answer.resize(2);
    
    int size = (int)nodeinfo.size();
    for(int i = 0; i < size; ++i)
    {
        //y축 좌표 값, x축 좌표 값, 노드 번호 순으로 입력
        Node.push_back({nodeinfo[i][1], nodeinfo[i][0],i+1});
    }
    
    sort(Node.begin(), Node.end(), cmp);
    
    tuple<int,int,int> Temp = {-1,-1,-1};
    LC.resize(size+1,Temp);
    RC.resize(size+1,Temp);
    
    for(int i = 1; i < size; ++i)
    {
        SetTree(Node[0], Node[i]);
    }
    
    
    Preorder(Node[0]);
    Postorder(Node[0]);
    
    
    
    return Answer;
}