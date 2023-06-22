#include <bits/stdc++.h>

using namespace std;

void printState(vector<int> frames)
{
    for (int x: frames)
    {
        if (x != -1) cout << " " << x; 
        else cout << " -";
    }
    cout << "\n";
}

int main()
{
    int size; //... Total number of frames
    cin >> size;
    vector<int> frames(size, -1);
    map<int, int> count;
    int miss = 0;
    
    int page;
    while(cin >> page)
    {
        count[page]++;
        bool found = false;
        for (int x: frames)
        {
            if (x == page)
            {
                found = true;
                break;
            }
        } 
        if (found)
        {
            cout << page << " ->\n";
            continue;
        }
        miss++;
        int out = frames[0];
        for (auto x: frames)
        {
            if (x == -1) 
            {
                out = x;
                break;
            }
            if (count[x] < count[out])
            {
                out = x;
            }
        }
        for (int &x: frames)
        {
            if (x == out)
            {
                x = page;
                cout << page << " ->";
                printState(frames);
                break;
            }
        }
    }
    cout << "Total page fault = " << miss;
}