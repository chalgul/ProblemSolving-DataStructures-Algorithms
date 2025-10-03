#include <iostream>

using namespace std;

int heap[100005];
int sz = 0; //heap에 들어있는 원소의 수

void push(int x)
{
    if (sz == 0)
    {
        heap[1] = x;
        sz++;
        return;
    }


    heap[sz + 1] = x;
    int CurLoc = sz + 1;
    while (CurLoc > 1)
    {
        if (x < heap[CurLoc / 2])
        {
            int Temp = heap[CurLoc / 2];
            heap[CurLoc / 2] = x;
            heap[CurLoc] = Temp;
            CurLoc = CurLoc / 2;
        }
        else
        {
            break;
        }

    }
    sz++;
}

int top()
{
    return heap[1];
}

void pop()
{
    heap[1] = heap[sz];
    int CurLoc = 1;
    sz--;
    while (true)
    {
        //자식이 둘다 있는 경우
        if (sz >= CurLoc * 2 + 1)
        {
            //왼쪽 자식이 더 작은 값이면서 그 왼쪽 자식이 오른쪽 자식보다도 작거나 같은 경우
            if (heap[CurLoc] > heap[CurLoc * 2] && heap[CurLoc * 2] <= heap[CurLoc * 2 + 1])
            {
                int Temp = heap[CurLoc * 2];
                heap[CurLoc * 2] = heap[CurLoc];
                heap[CurLoc] = Temp;
                CurLoc = CurLoc * 2;
            }
            else if (heap[CurLoc] > heap[CurLoc * 2 + 1] && heap[CurLoc * 2 + 1] < heap[CurLoc * 2])
            {
                int Temp = heap[CurLoc * 2 + 1];
                heap[CurLoc * 2 + 1] = heap[CurLoc];
                heap[CurLoc] = Temp;
                CurLoc = CurLoc * 2 + 1;
            }
            else
            {
                break;
            }
        }
        //왼쪽 자식이 마지막인 경우
        else if (sz == CurLoc * 2)
        {
            if (sz >= CurLoc * 2 && heap[CurLoc] > heap[CurLoc * 2])
            {
                int Temp = heap[CurLoc * 2];
                heap[CurLoc * 2] = heap[CurLoc];
                heap[CurLoc] = Temp;
                CurLoc = CurLoc * 2;
            }
            break;
        }
        else
        {
            break;
        }
    }
}


int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int Input = 0;
    for (int i = 0; i < N; ++i)
    {

        cin >> Input;

        if (Input == 0)
        {
            if (sz != 0)
            {
                cout << top() << "\n";
                pop();
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            push(Input);
        }
    }
    return 0;
}


