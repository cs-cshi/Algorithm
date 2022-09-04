#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int saveDataGame(int n, int m, vector<int> &array)
    {
        int left = 0, right = array.size() - 1;
        int score = 0;
        for (int i = 0; i < 2 * n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i - j) >= 0 && (i - j) < n && j < i / 2 + 1)
                {
                    int num = array[left] > array[right] ? array[right--] : array[left++];
                    score += (num * (j + 1) * ((i - j) + 1));

                    if (j != i - j)
                    {
                        int num = array[left] > array[right] ? array[right--] : array[left++];
                        score += (num * (j + 1) * ((i - j) + 1));
                    }
                }
            }
        }
        return score;
    }
};

int main()
{
    // int n = 2;
    // int count = 1;
    // vector<vector<int>> a(n, vector<int>(n));
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         a[i][j] = count; //数组赋值
    //         count++;
    //     }
    // }

    // int score = 0;

    // // for (int i = 0; i < n; i++)
    // // {
    // //     for (int j = 0; j < n; j++)
    // //     {
    // //         // a[i][j] = count; //数组赋值
    // //         // count++;
    // //         cout << a[i][j] << " ";
    // //     }
    // //     cout << endl;
    // // }

    // for (int i = 0; i < 2 * n - 1; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if ((i - j) >= 0 && (i - j) < n && j < i / 2 + 1)
    //         {
    //             // if(i % 2 == 1)
    //             // cout << 1111 << "  ";
    //             cout << (a[j][i - j]) << " ";
    //             if (j != i - j)
    //                 cout << (a[i - j][j]) << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    Solution solution;
    vector<int> matrix = {1, 1, 1, 2};
    int score = solution.saveDataGame(2, 2, matrix);
    cout << score;
}