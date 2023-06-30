#include <bits/stdc++.h>

using namespace std;

void printFrame(vector<int> frames)
{
    for (int x: frames)
    {
        if (x != -1) cout << x <<  " "; 
    }
    cout << "\n";
}

int main()
{
    int size;// = 3;
    cout<<"Enter Frame Size: ";
    cin>>size;
    
    vector<int> frames(size, -1);
    queue<int> q;
    int miss = 0;
    int n;
    vector<int> seq;// = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2};
    cout<<"Enter no of Pages: ";
    cin>>n;
    cout<<"Enter Pages: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        seq.push_back(value);
    }
    for (int x: seq)
    {
        cout << x << " -> ";
        bool found = false;
        for (int i = 0; i < size; i++)
        {
            if (frames[i] == x)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            cout << "\n";
            continue;
        }
        //if found is false page fault occured
        miss++;
        int out = -1;
        if (q.size() >= size) 
        {
            out = q.front();
            q.pop();
        }
        q.push(x);
        
        for (int i = 0; i < size; i++)
        {
            if (frames[i] == out)
            {
                frames[i] = x;
                printFrame(frames);
                break;
            }
        }
    }
    cout << "Total page fault = " << miss;
}

/*
frame size = 3
enter no of pages: 15

7 0 1 2 0 3 0 4 2 3 0 3 2 1 2

*/
