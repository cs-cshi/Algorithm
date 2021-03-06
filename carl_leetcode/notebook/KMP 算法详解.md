> 本文内容主要来自于 “carl 的代码随想录” 以及“洛谷网校 阮行止”在知乎上的回答。

KMP 算法是一种字符串匹配算法，可以在 O(n+m) 的时间复杂度内实现两个字符串的匹配。其思想是当出现字符串不匹配时，利用之前已经匹配的文本内容，利用这些信息避免从头再去匹配。

## 1. Brute-Force 算法
先来看下字符串匹配暴力解法，对主串 "AAAAAABC" 和模式串 "AAAB" 做匹配：
![](https://img2022.cnblogs.com/blog/2229250/202204/2229250-20220417144613311-1036987874.png)
对主串与模式串的每个字符逐个匹配：
1. 如果能匹配上，主串和模式串指针同时后移匹配下一个字符，直至模式串匹配完成；
2. 如果不能匹配上，模式串指针回退至模式串头，主串指针移至上一次开始匹配的后一个位置，重新开始匹配。
```cpp
int strStr(string s, string t) {
    int n = s.size(), m = t.size();
    for (int i = 0; i + m <= n; i++) {
       bool flag = true;
       for (int j = 0; j < m; j++) {
           if (s[i + j] != t[j]) {
               flag = false;
               break;
           }
       }
       if (flag)
           return i;
    }
    return -1;
}
```
时间复杂度：O(n*m)。

## 2. KMP 算法思想
### 2.1 什么是前缀表
对于 Brute-Force 算法，很难降低比较的复杂度，只能进行逐个比较，但可以利用一部分已经匹配过的信息来降低比较的趟数。

Brute-Force 算法中，如果从 s[i] 开始的那一趟匹配失败了，算法会直接开始尝试从 s[i+1] 开始与模式串 t 从头逐个比较，也就是回退到模式串的起始位置。

实际上一次失败的匹配会提供一些信息：如果 s[i : i+len(t)] 与 t 的匹配是在第 r 个位置失败的，那么从 s[i] 开始的 (r-1) 个连续字符，一定与 t 的前 (r-1) 个字符一模一样。我们可以对 t 前 r-1 个字符事先处理获取一些信息来降低比较的趟数，这个信息就是前缀表（predix table），也就是 KMP 算法中 next/prefix 数组原型。

举一个例子，在文本串 aabaabaafa 中查找是否出现过一个模式串 aabaaf。
![](https://img2022.cnblogs.com/blog/2229250/202204/2229250-20220417151219542-552820154.png)
可以看出此时文本串中第六个字符 b 和 模式串的第六个字符 f，不匹配了。如果暴力匹配，会发现不匹配，此时就要从头匹配了。如果使用前缀表，会从已经匹配的内容开始匹配，也就是第三个字符 b 开始继续匹配，原因在于 第一、二个字符 aa 与第四五个字符 aa 相等。

前缀表的任务：当前位置匹配失败时，前缀表会告诉你下一步匹配时模式串应该从哪个位置开始（暴力解法从头开始）。

![](https://img2022.cnblogs.com/blog/2229250/202204/2229250-20220417152424991-647875855.png)
直观理解如上图所示，绿色部分是成功匹配，失配于红色部分。深绿色手绘线条标出了相等的前缀和后缀，其长度为next\[右端]。由于手绘线条部分的字符是一样的，所以直接把前面那条移到后面那条的位置。也就是说，next数组为我们如何移动标尺提供了依据。

### 2.2 计算前缀表
先确定一个概念:
- 前缀：指模式串中以第一个字符开头但不包含最后一个字符的连续子字符串。
- 后缀：指模式串中以最后一个字符结尾但不包含第一个字符的连续子字符串。
> - 前后缀不包含最后一个字符和第一个字符很容易理解，如果包含了前缀后缀字符串肯定相等了，没有比较的必要。
> - 前缀其实就是上一张图中前一段深绿色手绘线，后缀就是后一段深绿色手绘线，如果前缀包含了最后一个字符，那么此时前后缀子串就是绿色已经成功匹配的部分了。

前缀表记录的是最长相同前后缀的长度信息。

对于之前的例子，模式串 aabaaf 求得的最长相同前后缀长度就是对应的前缀表的元素，如下图所示：
![](https://img2022.cnblogs.com/blog/2229250/202204/2229250-20220417153553727-1095621262.png)
```shell
#  字串: 最长相同前后缀长度
     a : 0
    aa : 1
   aab : 0
  aaba : 1
 aabaa : 2
aabaaf : 0
```
再来看一下如何利用前缀表找到当字符不匹配时指针应该移动的位置。
![](https://img2022.cnblogs.com/blog/2229250/202204/2229250-20220417154502151-1354891163.png)
当文本串 aabaabaafa 遇到模式串 aabaaf 第一个不匹配字符时，即 s[5] != t[5]，则寻找前一位下标在前缀表中对应的元素 next[4] 为 2，那么模式串跳到下标 2 的位置继续重新匹配。

## 3. 构造 next/prefix 数组
> next 数组生成方法有几种
> - 基于原始前缀表，发生不匹配时，从 next[j-1] 的位置开始找
> - 原始前缀表统一减一，发生不匹配时，从 next[j] 的位置开始找
> - 原始表右移一位，发生不匹配时，从 netxt[j] 的位置开始找
> 下文是以原始前缀表来介绍。

构造 next 数组其实使用动规思想就是计算模式串前缀表的过程，主要有如下四部：
1. 初始化 next 数组
2. 处理前后缀不相同的情况
3. 处理前后缀相同的情况
4. 更新 next 数组

next[x] 实际上就是模式串 P[0]~P[k]这一段字符串中，前缀恰好等于后缀的最大相同字串长度。

如果next[0], next[1], ... next[x-1]均已知，那么如何求出 next[x] 呢？

来分情况讨论。首先，已经知道了 next[x-1]（以下记为now），如果 P[x] 与 P[now] 一样，那最长相等前后缀的长度就可以扩展一位，很明显 next[x] = now + 1. 图示如下。
![](https://img2022.cnblogs.com/blog/2229250/202204/2229250-20220417161743814-1752919288.png)

如果 P[x] 与 P[now] 不相等时，
![](https://img2022.cnblogs.com/blog/2229250/202204/2229250-20220417161850614-1594532597.png)
长度为 now 的子串 A 和子串 B 是 P[0]...P[x-1] 中最长的公共前后缀。可惜 A 右边的字符和 B 右边的那个字符不相等，next[x]不能改成 now+1 了。因此，我们应该缩短这个now，把它改成小一点的值，再来试试 P[x] 是否等于 P[now].　　now该缩小到多少呢？显然，我们不想让now缩小太多。因此我们决定，在保持 “P[0]...P[x-1]的now-前缀仍然等于now-后缀” 的前提下，让这个新的 now 尽可能大一点。 P[0]~P[x-1] 的公共前后缀，前缀一定落在串A里面、后缀一定落在串B里面。换句话讲：接下来now应该改成：使得 A的前缀等于B的后缀 的最大的k.　　您应该已经注意到了一个非常强的性质——串A和串B是相同的！B的后缀等于A的后缀！因此，使得A的前缀等于B的后缀的最大的k，其实就是串A的最长公共前后缀的长度 —— next[now-1]！
![](https://img2022.cnblogs.com/blog/2229250/202204/2229250-20220417162541297-1054900057.png)
来看上面的例子。当P[now]与P[x]不相等的时候，我们需要缩小now——把now变成next[now-1]，直到P[now]=P[x]为止。P[now]=P[x]时，就可以直接向右扩展了。

```cpp
/**
 * i: 后缀末尾
 * j: 前缀末尾
 * next[i]：i（包含i）之前最长相等的前后缀的长度（其实就是 j）
 * 
*/
void getNext(int *next, const string &s)
{
    // 1. 初始化 next 数组
    int j = 0;      // 相当于 上文解释中的 now
    next[0] = j;

    // i 相当于上文解释中的 x
    while(i = 1; i < s.size(); i++)
    {
        // 前后缀不相同的情况
        while( j > 0 && s[i] != s[j] )
            j = next[j - 1];
        // 前后缀相等
        if(s[i] == s[j])
            j++;

        // 更新 next 数组
        next[i] = j;
    }
}
```


## Reference
- https://www.programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html
- https://www.bilibili.com/video/BV1PD4y1o7nd/?spm_id_from=333.788
- 洛谷网校 阮行止, https://www.zhihu.com/question/21923021