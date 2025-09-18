#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <functional>
#include <unordered_map>
#include <set>
using namespace std;

int TestCase;

string FunctionWorld;

string NumberArray;

int Length;



int main() {
   
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> TestCase;

    int Start = 0, End = 0;

    
    for (int i = 0; i < TestCase; i++)
    {
        cin >> FunctionWorld;


        cin >> Length;

        vector<int> NumVec;

        cin >> NumberArray;


        string CacheNumber;
        //O(N)
        for (char A : NumberArray)
        {
            if (isdigit(A))
            {
                CacheNumber += A;
            }
            else
            {
                if (!CacheNumber.empty())
                {
                    int InputNum = 0;
                    int Dis = 1;
                    for (int i = CacheNumber.size() - 1; i > 0; i--)
                    {
                        Dis *= 10;
                    }
                    for (char C : CacheNumber)
                    {
                        InputNum += Dis * (C - '0');
                        Dis = Dis / 10;
                    }
                    NumVec.push_back(InputNum);
                    CacheNumber.clear();
                }
            }
        }
        bool IsEmpty = false;
        bool AlreadyPrintError = false;
        Start = 0;
        if ((int)NumVec.size() != 0)
        {
            End = (int)NumVec.size() - 1;
        }
        else
        {
            IsEmpty = true;
            End = 0;
        }
        //O(N)
        for (char B : FunctionWorld)
        {
            if (B == 'R')
            {
                swap(Start, End);
            }
            else if (B == 'D')
            {
                if (Start < End)
                {
                    Start++;
                }
                else if(Start > End)
                {
                    Start--;
                }
                else
                {
                    if (IsEmpty)
                    {
                        cout << "error" << "\n";
                        AlreadyPrintError = true;

                        break;
                    }

                    IsEmpty = true;
                }
            }
        }


        if (IsEmpty)
        {
            if (!AlreadyPrintError)
            {
                cout << "[" << "]" << "\n";
                continue;
            }
        }
        else
        {
            if (Start < End)
            {
                cout << "[";
                for (int i = Start; i < End; i++)
                {
                    cout << NumVec[i] << ",";
                }
                cout << NumVec[End] << "]" << "\n";
            }
            else if (Start > End)
            {
                cout << "[";
                for (int i = Start; i > End; i--)
                {
                    cout << NumVec[i] << ",";
                }
                cout << NumVec[End] << "]" << "\n";
            }
            else
            {
                cout << "[" << NumVec[Start] << "]" << "\n";
            }
        }


    }


    return 0;
}

