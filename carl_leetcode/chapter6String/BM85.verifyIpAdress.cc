/**
 * BM85 验证IP地址
 * 编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址
 * IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；
 * 同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。
 * IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。
 * 然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。
 * 同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。
 * 链接：https://www.nowcoder.com/practice/55fb3c68d08d46119f76ae2df7566880?tpId=295&tqId=1024725&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Ftab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
 */

// #include "bits/stdc++.h"
// /*
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

// using std::string;
// using std::stringstream;
// using std::vector;
// */
using namespace std;

class Solution
{
public:
    /**
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串:IPv4,   IPv6,   Neither
     */

    string solve(string IP)
    {
        // write code here
        // cout << int('0') << endl;
        // cout << int('9') << endl;
        // cout << int('A') << endl;
        // cout << "F: " << int('F') << endl;
        // cout << int('Z') << endl;
        // cout << int('a') << endl;
        // cout << "f: " << int('f') << endl;
        // cout << int('z') << endl;
        if (IP.find('.') != string::npos)
        {
            if (isIPv4(IP))
                return "IPv4";
        }
        else if (IP.find(':') != string::npos)
        {
            cout << "IPv6 verify.." << endl;
            if (isIPv6(IP))
                return "IPv6";
        }
        // cout << int(IP.find('.')) << endl;
        return "Neither";
    }

    bool isIPv4(string &IP)
    {
        // 首尾为 .
        if (IP[0] == '.' || IP[IP.size() - 1] == '.')
            return false;
        const char pattern = '.';
        vector<string> numsStrs = split(IP, pattern);

        // 不是 4 段
        if (numsStrs.size() != 4)
            return false;

        for (string numsStr : numsStrs)
        {
            // 字符不是 0~9
            for (char num : numsStr)
                if (num < '0' || num > '9')
                    return false;
            int num = stoi(numsStr); // 1a1 会转换成 1

            // 转换成数字超范围
            if (num > 255 || num < 0)
                return false;

            // 以0开头情况
            if (numsStr.size() > 1 && numsStr[0] == '0')
                return false;
        }
        return true;
    }

    bool isIPv6(string &IP)
    {
        // 首尾 :
        if (IP[0] == ':' || IP[IP.size() - 1] == ':')
            return false;
        const char pattern = ':';
        vector<string> numsStrs = split(IP, pattern);

        // 不是8段
        if (numsStrs.size() != 8)
            return false;
        for (string numsStr : numsStrs)
        {
            cout << numsStr << "  ";
            if (numsStr == "")
                return false;

            // if (numsStrs.size() > 1 && numsStr[0] == '0')
            // return false;

            // 全 0 的情况
            int count0 = 0;
            int i = 0;
            while (i < numsStr.size())
            {
                if (numsStr[i] == '0')
                    count0++;
                
                // 非 16进制字符
                if (!((numsStr[i] >= 48 && numsStr[i] <= 57) || (numsStr[i] >= 65 && numsStr[i] <= 70) || (numsStr[i] >= 97 && numsStr[i] <= 102)))
                    return false;
                i++;
            }

            if (numsStr.size() > 1 && count0 == numsStr.size())
                return false;

            
        }
        return true;
    }

    vector<string> split(const string &str, const char &pattern)
    {
        vector<string> res;
        stringstream input(str);
        string temp;
        while (getline(input, temp, pattern))
            res.push_back(temp);
        return res;
    }
};
