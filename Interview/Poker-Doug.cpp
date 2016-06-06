
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <deque>
#include <algorithm>
#include <utility>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <future>
#include <thread>

using namespace std;

bool checkStraight(vector<int> input)
{
    int i;
    vector<bool> flags(13, false);

    for (i = 0; i < (int)input.size(); i++)
    {
        flags[input[i] - 1] = true;
    }

    int count = 0;
    bool found = false;
    for (i = 1; i < 13; i++)
    {
        if (count == 0 && flags[i])
        {
            count = 1;
        }

        count = flags[i] && flags[i - 1] ? count + 1 : 0;

        if (count == 5)
        {
            break;
        }
    }

    if (count == 5 || (count == 4 && flags[0]))
    {
        found = true;
    }

    return found;
}

int Poker_Doug_main()
{
    vector<vector<int>> input
    {
        { 2, 9, 10, 10, 11, 12, 13 },
        { 1, 3, 4, 10, 11, 12, 13 },
        { 1, 2, 3, 4, 5, 12, 13 },
        { 2, 5, 6, 10, 11, 12, 13 },
        { 1, 3, 3, 4, 5, 6, 7 }
    };

    for (int i = 0; i < (int)input.size(); i++)
    {
        for (int j = 0; j < (int)input[i].size(); j++) {
            cout << input[i][j] << " ";
        }

        string check = checkStraight(input[i]) ? "TRUE" : "FALSE";
        cout << check << endl;
    }
    return 0;
}