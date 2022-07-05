/**
 * HJ20 密码验证合格程序
 * 密码要求:
 *      1.长度超过8位
 *      2.包括大小写字母.数字.其它符号,以上四种至少三种\
 *      3.不能有长度大于2的包含公共元素的子串重复 （注：其他符号不含空格或换行）
 * 链接：https://www.nowcoder.com/practice/184edec193864f0985ad2684fbc86841?tpId=37&tqId=21243&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D100%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


bool isValidPassword(const string &str) {
    // 1.长度超过 8 位
    if(str.size() <= 8)
        return false;
    
    // 2. 包括大小写字母、数字、其他符号中的三种
    int supperChar = 0;   // 大写字母
    int lowChar = 0;      // 小写字母
    int numChar = 0;     //  数字
    int otherChar = 0;   //  其他字符
    for(int i = 0; i < str.size(); i++) {
        if(isupper(str[i])){
            supperChar = 1;
        }else if (islower(str[i])) {
            lowChar = 1;
        }else if (isdigit(str[i])) {
            numChar = 1;
        }else {
            otherChar = 1;
        }
    }
    if ( supperChar + lowChar + numChar + otherChar < 3)
        return false;
        
    // 3. 不能有长度大于2的包含公共元素的子串重复
    /**
     * 动规
     * dp[i][j]， 以 i 结尾和以 j 结尾的最长公共子串, i < j
     * dp[i][j] = dp[i-1][j-1] + 1, ==
     * dp[i][j] = 0 !=
     */
    /*
    vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1, 0));
    int result = 0;
    for(int i = 1; i <= str.size(); i++) {
        for(int j = 1; j < i; j++) {
            if(str[i] == str[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;
            result = max(result, dp[i][j]);
        }
    }
    
    
    if(result > 2)
        return false;
    */
    // 非动规
    for(int i = 0; i < str.size(); i++) {
        for ( int j = i + 3; j < str.size() - 2; j++) {
            if(str[i] == str[j] && str[i + 1] == str[j + 1] && str[i + 2] == str[j + 2])
                return false;
        }
    }
    
    return true;   
}


int main() {
    string str;
    while(getline(cin, str)) {
        if(isValidPassword(str))
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }
}