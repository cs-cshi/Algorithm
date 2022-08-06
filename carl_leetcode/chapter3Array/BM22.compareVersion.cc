/**
 * BM22 比较版本号
 * 牛客项目发布项目版本时会有版本号，比如1.02.11，2.14.4等等
 * 现在给你2个版本号version1和version2，请你比较他们的大小
 * 版本号是由修订号组成，修订号与修订号之间由一个"."连接。1个修订号可能有多位数字组成，修订号可能包含前导0，且是合法的。例如，1.02.11，0.1，0.2都是合法的版本号
 * 每个版本号至少包含1个修订号。
 * 修订号从左到右编号，下标从0开始，最左边的修订号下标为0，下一个修订号下标为1，以此类推。
 *
 * 比较规则：
 * 一. 比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较忽略任何前导零后的整数值。比如"0.1"和"0.01"的版本号是相等的
 * 二. 如果版本号没有指定某个下标处的修订号，则该修订号视为0。例如，"1.1"的版本号小于"1.1.1"。因为"1.1"的版本号相当于"1.1.0"，第3位修订号的下标为0，小于1
 * 三.  version1 > version2 返回1，如果 version1 < version2 返回-1，不然返回0.
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace ::std;
// using std::string;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串
     * @param version2 string字符串
     * @return int整型
     */
    int compare(string version1, string version2)
    {
        vector<string> version1Vec = split(version1, ".");
        vector<string> version2Vec = split(version2, ".");
        int len = min(version1Vec.size(), version2Vec.size());
        int i = 0;
        for (; i < len; i++)
        {
            int version1Num = atoi(version1Vec[i].c_str());
            int version2Num = atoi(version2Vec[i].c_str());
            if (version1Num < version2Num)
                return -1;
            else if (version1Num > version2Num)
                return 1;
        }

        // version1 长
        while (i < version1Vec.size())
        {
            if (atoi(version1Vec[i++].c_str()) != 0)
                return 1;
        }

        while (i < version2Vec.size())
        {
            if (atoi(version2Vec[i++].c_str()) != 0)
                return -1;
        }

        return 0;
    }

    /**
     * @param str 待分割的字符串
     * @param pattern 以 pattern 来分割字符串
     * @return 分割后的 vector<string> 容器
     */
    vector<string> split(const string &str, const string &pattern)
    {
        vector<string> result;
        if (str == "")
            return result;
        string strs = str + pattern;     // 尾部加分割符，统一尾部操作
        size_t pos = strs.find(pattern); // 第一个分隔符位置
        while (pos != strs.npos)         // find 函数若未在字符串中找到，返回 npos
        {
            string temp = strs.substr(0, pos); // 分割
            result.push_back(temp);
            strs = strs.substr(pos + 1, strs.size()); // 去掉已分割字符
            pos = strs.find(pattern);
        }
        return result;
    }

    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 比较版本号
     * @param version1 string字符串
     * @param version2 string字符串
     * @return int整型
     */
    int compare2(string version1, string version2)
    {
        int ver1 = 0, ver2 = 0;
        int len1 = version1.size(), len2 = version2.size();
        int i = 0, j = 0;
        while (i < len1 || j < len2)
        {
            while (i < len1 && version1[i] != '.')
            {
                ver1 = ver1 * 10 + (version1[i] - '0');
                i++;
            }

            while (j < len2 && version2[j] != '.')
            {
                ver2 = ver2 * 10 + (version2[j] - '0');
                j++;
            }

            if (ver1 < ver2)
                return -1;
            if (ver1 > ver2)
                return 1;

            i++;
            j++;
            ver1 = 0;
            ver2 = 0;
        }
        return 0;
    }
};

int main() {
    return 0;
}