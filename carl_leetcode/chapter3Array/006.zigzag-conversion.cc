/**
 * 6. Z 字形变换
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列.
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size() <= numRows || numRows == 1)
            return s;
        int n = s.size();
        int col = n;
        vector<vector<char>> vec(numRows, vector<char>(col, ' '));
        // cout << vec.size() << " " << vec[0].size();
        bool flag = false;
        int i = 1, j = 0;
        int index = 0;
        vec[0][0] = s[index];
        index++;
        while(index < s.size()) {
            vec[i][j] = s[index];
            // cout << i << "," << j << ":" << s[index] << endl;
            if(i == 0 || i == numRows - 1) {
                flag = !flag;   // 转向
            }
            
            if(!flag)   // 下
                i++;
            else{       // 斜上
                i--;
                j++;
            };
            index++;
        }

        string res = "";
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < col; j++) {
                if(vec[i][j] != ' ')
                    res+= vec[i][j];
            }
        }
        return res;
    }
};