/**
 * HJ29 字符串加解密
 * 对输入的字符串进行加解密，并输出。
 * 加密方法为：
 *   当内容是英文字母时则用该英文字母的后一个字母替换，同时字母变换大小写,如字母a时则替换为B；字母Z时则替换为a；
 *   当内容是数字时则把该数字加1，如0替换1，1替换2，9替换0；
 *   其他字符不做变化。
 * 解密方法为加密的逆过程。
 * 链接：https://www.nowcoder.com/practice/2aa32b378a024755a3f251e75cbf233a?tpId=37&tqId=21252&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3Fdifficulty%3D3%26page%3D1%26pageSize%3D100%26search%3D%26tpId%3D37%26type%3D37&difficulty=3&judgeStatus=undefined&tags=&title=
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// void decryption(const string& str) {

// }

// /**
//  * 对 str 加密
//  */
// void encryption(string& str) {
//     for(int i = 0; i < str.size(); i++) {
//         if(isalpha(str[i])) {
//             if(str[i] == 'Z')
//                 str[i] = 'a';
//             else
//                 str[i] = str[i] + ('a' - 'A' + 1);
//         }
//     }
// }


/**
 * abcdefghijklmnopqrstuvwxyz
 * ABCDEFGHIJKLMNOPQRSTUVWXYZ
 */


int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    unordered_map<char, char> encryptionMap;
    unordered_map<char, char> decryptionMap;

//     string strlist1 =
//         "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";//加密前的字符list

//     string strlist2 =
//         "BCDEFGHIJKLMNOPQRSTUVWXYZAbcdefghijklmnopqrstuvwxyza1234567890";//加密后的字符list，和list1一一对应


    // 英文字母 25 个英文字母
    for (int i = 0; i < 25; i++) {
        encryptionMap['a' + i] = 'A' + 1 + i;
        encryptionMap['A' + i] = 'a' + 1 + i;
        decryptionMap['b' + i] = 'A' + i;
        decryptionMap['B' + i] = 'a' + i;
    }
    encryptionMap['z'] = 'A';
    encryptionMap['Z'] = 'a';
    decryptionMap['A'] = 'z';
    decryptionMap['a'] = 'Z';

    // 数字
    for (int i = 0; i < 9; i++) {
        encryptionMap['0' + i] = '0' + i + 1;
        decryptionMap['1' + i] = '1' + i - 1;
    }
    encryptionMap['9'] = '0';
    decryptionMap['0'] = '9';

    for (int i = 0; i < str1.size(); i++) {
        if (encryptionMap.find(str1[i]) != encryptionMap.end())
            cout << encryptionMap[str1[i]];
    }
    cout << endl;

    for (int i = 0; i < str2.size(); i++) {
        if (decryptionMap.find(str2[i]) != decryptionMap.end())
            cout << decryptionMap[str2[i]];
    }
    cout << endl;

//     encryption(str1);
//     decryption(str2);
    return 0;
}