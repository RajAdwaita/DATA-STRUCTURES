#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int hits = 0;
        int rookPosi = 0;
        int rookPosj = 0;
        int bishi = 0;
        int bishj = 0;
        int pawni = 0;
        int pawnj = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == 'R')
                {
                    rookPosi = i;
                    rookPosj = j;
                    goto add;
                }
            }
        }
    add:

        for (int ki = rookPosi; ki >= 0; ki--)
        {
            if (board[rookPosi][ki] == 'p' && bishi == 0)
            {
                pawni++;
                break;
            }
            if (board[rookPosi][ki] == 'B')
            {
                pawni = 0;
                bishi++;
            }
            // if (board[rookPosi][ki] == 'R')
            //     pawni++;
        }
        if (pawni > 0)
            hits++;
        pawni = 0;
        bishi = 0;
        for (int ki = rookPosi + 1; ki < 8; ki++)
        {
            if (board[rookPosi][ki] == 'p' && bishi == 0)
            {
                pawni++;
                break;
            }
            if (board[rookPosi][ki] == 'B')
            {
                pawni = 0;
                bishi++;
            }
            // if (board[rookPosi][ki] == 'R')
            //     pawni++;
        }
        if (pawni > 0)
            hits++;
        pawni = 0;
        bishi = 0;

        for (int ji = rookPosj; ji >= 0; ji--)
        {
            if (board[ji][rookPosj] == 'p' && bishj == 0)
            {
                pawnj++;
                break;
            }
            if (board[ji][rookPosj] == 'B')
            {
                pawnj = 0;
                bishj++;
            }
        }
        if (pawnj > 0)
            hits++;
        pawnj = 0;
        bishj = 0;
        for (int ji = rookPosj; ji < 8; ji++)
        {
            if (board[ji][rookPosj] == 'p' && bishj == 0)
            {
                pawnj++;
                break;
            }
            if (board[ji][rookPosj] == 'B')
            {
                pawnj = 0;
                bishj++;
            }
        }
        if (pawnj > 0)
            hits++;
        pawnj = 0;
        bishj = 0;

        return hits;
    }
};

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     return 0;
// }