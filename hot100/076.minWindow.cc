/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
*/

#include <string>
#include <iostream>
#include <unordered_map>
#include <limits>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::numeric_limits;
using std::string;
using std::unordered_map;
using std::vector;

/*
    判断 count 中每个字符出现的字符，是否达到 ori 中的需求
*/
bool check(unordered_map<char, int> &ori, unordered_map<char, int> &count)
{
    for (const auto &p : ori)
    {
        if (count[p.first] < p.second) // p.first 表示字符，p.second 表示字符出现的次数
            return false;
    }
    return true;
}

string minWindow(string s, string t)
{
    // t 为空或 s 中字符个数小于 t 中个数
    if (t.empty() || s.size() < t.size())
        return "";

    unordered_map<char, int> ori;   // 用于存储 t 中每个字符个数，键：字符 c，值：字符 c 的个数
    unordered_map<char, int> count; // 用于存储当前滑动窗口中 t 中字符出现的次数

    // ori 初始化
    for (const auto &c : t)
        ++ori[c];

    int left = 0;                         // 滑动窗口左指针
    int right = -1;                       // 滑动窗口右指针
    int len = numeric_limits<int>::max(); // 最小子串长度
    int ansLeft = -1;                     // 最小子串起始索引

    // s.size() 一定要进行类型转换，否则将会发生隐式类型转换
    while (right < int(s.size()))
    {
        // 滑动窗口右指针右移，如果下一个字符是 t 中的字符，count 中对应字符数量 + 1
        if (ori.find(s[++right]) != ori.end())
            ++count[s[right]];

        // 当前滑动窗口包含了 t 中所有字符
        while (check(ori, count) && left <= right)
        {
            if (right - left + 1 < len)
            {
                len = right - left + 1;
                ansLeft = left;
            }

            // 滑动窗口左指针右移，减去最左侧字符
            if (ori.find(s[left]) != ori.end())
                --count[s[left]];

            ++left;
        }
    }

    return ansLeft == -1 ? "" : s.substr(ansLeft, len);
}

// 使用 need 来存储当前窗口中每个字符还需要的数目，若字符在子串中，数目>0、<0、=0都有可能，若不在，只可能<=0
// count 计算滑动窗口总共需要的字符数目
// need 中字符小于0，说明多余的字符个数
string minWindow2(string s, string t)
{
    if (t.empty() || s.size() < t.size())
        return "";

    vector<int> need(128, 0); // 滑动窗口中每个字符需要的数目
    int count = 0;            // 滑动窗口中需要的字符总数目
    int left = 0;             // 滑动窗口左指针
    int right = -1;           //  滑动窗口右指针
    int start = -1;           // 最长子串起始位置
    int length = numeric_limits<int>::max();

    for (char c : t) // 用待匹配字符串初始化 need
        ++need[c];

    count = t.size(); // 当前滑动窗口需要的字符总数

    while (right < int(s.size()))
    {
        char c = s[right]; //当前滑动窗口最右侧字符

        if (need[c] > 0) // 判断是否是需要的字符。对于一直不需要的字符，need 里的值一直会小于等于 0
            count--;
        need[c]--;      // 将字符纳入 need，若该字符 < 0，说明是滑动窗口中多出的
        if (count == 0) // 滑动窗口目前存在子串
        {
            while (need[s[left]] < 0 && left < right) // need[] < 0，说明是多余字符。滑动窗口左侧字符多余，左指针向右滑动
                need[s[left++]]++;

            if (right - left + 1 < length) // 更新最小子串长度
            {
                start = left;
                length = right - left + 1;
            }

            // 当前 s[left] 是 t 中的字符，更新 need 中对应需要的数量
            need[s[left]]++;
            left++;  // 左指针右移
            count++; // 需要总数 +1
        }
        right++; //右指针右移
    }
    return start == -1 ? "" : s.substr(start, length);
}

int main()
{
    string s = "obzcopzocynyrsgsarijyxnkpnukkrvzuwdjldxndmnvevpgmxrmvfwkutwekrffnloyqnntbdohyfqndhzyoykiripdzwiojyoznbtogjyfpouuxvumtewmmnqnkadvzrvouqfbbdiqremqzgevkbhyoznacqwbhtrcjwfkzpdstpjswnpiqxjhywjanhdwavajrhwtwzlrqwmombxcaijzevbtcfsdcuovckoalcseaesmhrrizcjgxkbartdtotpsefsrjmvksqyahpijsrppdqpvmuocofuunonybjivbjviyftsyiicbzxnwnrmvlgkzticetyfcvqcbjvbufdxgcmesdqnowzpshuwcseenwjqhgsdlxatamysrohfnixfprdsljyyfhrnnjsagtuihuczilgvtfcjwgdhpbixlzmakebszxbhrdibpoxiwztshwczamwnninzmqrmpsviydkptjzpktksrortapgpxwojofxeasoyvyprjoguhqobehugwdvtzlenrcttuitsiijswpogicjolfxhiscjggzzissfcnxnvgftxvbfzkukqrtalvktdjsodmtgzqtuyaqvvrbuexgwqzwduixzrpnvegddyyywaquxjxrnuzlmyipuqotkghfkpknqinoidifnfyczzonxydtqroazxhjnrxfbmtlqcsfhshjrxwqvblovaouxwempdrrplefnxmwrwfjtebrfnfanvvmtbzjesctdgbsfnpxlwihalyiafincfcwgdfkvhebphtxukwgjgplrntsuchyjjuqozakiglangxkttsczhnswjksnuqwflmumpexxrznzwxurrysaokwxxqkrggytvsgkyfjrewrcvntomnoazmzycjrjrqemimyhriyxgrzcfuqtjhvjtuhwfzhwpljzajitrhryaqchnuawbxhxrpvyqcvhpggrpplhychyulijhkglinibedauhvdydkqszdbzfkzbvhldstocgydnbfjkcnkfxcyyfbzmmyojgzmasccaahpdnzproaxnexnkamwmkmwslksfpwirexxtymkmojztgmfhydvlqtddewjvsrmyqjrpycbmndhupmdqqabiuelacuvxnhxgtpvrtwfgzpcrbhhtikbcqpctlxszgpfbgcsbaaiapmtsucocmpecgixshrrnhyrpalralbccnxvjzjllarqhznzghswqsnfuyywmzbopyjyauknxddgdthlabjqtwxpxwljvoxkpjjpfvccyikbbrpdsyvlxscuoofkecwtnfkvcnzbxkeabtdusyhrqklhaqreupakxkfzxgawqfwsaboszvlshwzhosojjotgyagygguzntrouhiweuomqptfjjqsxlbylhwtpssdlltgubczxslqjgxuqnmpynnlwjgmebrpokxjnbiltvbebyytnnjlcwyzignmhedwqbfdepqakrelrdfesqrumptwwgifmmbepiktxavhuavlfaqxqhreznbvvlakzeoomykkzftthoemqwliednfsqcnbexbimrvkdhllcesrlhhjsspvfupxwdybablotibypmjutclgjurbmhztboqatrdwsomnxnmocvixxvfiqwmednahdqhxjkvcyhpxxdmzzuyyqdjibvmfkmonfxmohhshpkhmntnoplphqyprveyfsmsxjfosmicdsjrieeytpnbhlsziwxnpmgoxneqbnufhfwrjbqcsdfarybzwaplmxckkgclvwqdbpumsmqkswmjwnkuqbicykoisqwoootrdpdvcuiuswfqmrkctsgrevcxnyncmivsxbpbxzxpwchiwtkroqisnmrbmefbmatmdknaklpgpyqlsccgunaibsloyqpnsibwuowebomrmcegejozypjzjunjmeygozcjqbnrpakdermjcckartbcppmbtkhkmmtcngteigjnxxyzaibtdcwutkvpwezisskfaeljmxyjwykwglqlnofhycwuivdbnpintuyhtyqpwaoelgpbuwiuyeqhbvkqlsfgmeoheexbhnhutxvnvfjwlzfmvpcghiowocdsjcvqrdmkcizxnivbianfpsnzabxqecinhgfyjrjlbikrrgsbgfgyxtzzwwpayapfgueroncpxogouyrdgzdfucfrywtywjeefkvtzxlwmrniselyeodysirqflpduvibfdvedgcrzpzrunpadvawfsmmddqzaaahfxlifobffbyzqqbtlcpquedzjvykvarayfldvmkapjcfzfbmhscdwhciecsbdledspgpdtsteuafzbrjuvmsfrajtulwirzagiqjdiehefmfifocadxfuxrpsemavncdxuoaetjkavqicgndjkkfhbvbhjdcygfwcwyhpirrfjziqonbyxhibelinpllxsjzoiifscwzlyjdmwhnuovvugfhvquuleuzmehggdfubpzolgbhwyeqekzccuypaspozwuhbzbdqdtejuniuuyagackubauvriwneeqfhtwkocuipcelcfrcjcymcuktegiikyosumeioatfcxrheklookaqekljtvtdwhxsteajevpjviqzudnjnqbucnfvkybggaybebljwcstmktgnipdyrxbgewqczzkaxmeazpzbjsntltjwlmuclxirwytvxgvxscztryubtjweehapvxrguzzsatozzjytnamfyiitreyxmanhzeqwgpoikcjlokebksgkaqetverjegqgkicsyqcktmwjwakivtsxjwrgakphqincqrxqhzbcnxljzwturmsaklhnvyungjrxaonjqomdnxpnvihmwzphkyuhwqwdboabepmwgyatyrgtboiypxfavbjtrgwswyvcqhzwibpisydtmltbkydhznbsvxktyfxopwkxzbftzknnwipghuoijrbgqnzovxckvojvsqqraffwowfvqvfcmiicwitrhxdeombgesxexedlakitfovtydxunqnwqqdeeekiwjnwoshqcsljiicgobbbuqakjdonjawgjlezdnqhfdqnmsuavxdpnfzwipmspiabveaarshzwxmirgkmfncvtdrdvfxkpxlkdokxgtwcskmjryyymcthfnkasinihaunohkxaibtsqelockaefjmsuolebtnepauwmrxutspjwaxbmahsjtkfkxlnszribmeofbkyvbjscjtqjakuwvcgunvnonvqbbggfshauqsyznokqbhowjusypfnecffenojfvlblgzntqzlrgzprvhqnpfrrkzxznieiuivajivzijsqijigtatifmbplzqahuidegfoobpymkputzamzvweiyvvzlwihgmmmrcburbgbsdxrfjsbiylitghgcpqjbevvgypxcybubyoijijrhuzcdijfybqbfowlookqmlnplbxvjjosfqviygqyhgamuwzjklbyzopkrnhbywtfoqomweldmlrhjqswctubiknzzvcztyehouvnyiqnvkufaobehxhrjvtisxjlxoumipzjarwvbsaegdkpbsjmpevjbewzuqnfhoohhmdjgfpmjzdmtmykqvtucptwfidpwtwffzolffzqfdearclkyeecuzabjeqhxpmfodsvisnpxrqowdawheydfyhoexvcmihdlzavtqlshdhdgjzpozvvackebhgqppvcrvymljfvooauxcjnbejdivikcoaugxwzsulgfqdtefpehbrlhaoqxwcancuvbqutnfbuygoemditeagmcveatgaikwflozgdhkyfqmjcruyyuemwbqwxyyfiwnvlmbovlmccaoguieu";
    string t = "cjgamyzjwxrgwedhsexosmswogckohesskteksqgrjonnrwhywxqkqmywqjlxnfrayykqotkzhxmbwvzstrcjfchvluvbaobymlrcgbbqaprwlsqglsrqvynitklvzmvlamqipryqjpmwhdcsxtkutyfoiqljfhxftnnjgmbpdplnuphuksoestuckgopnlwiyltezuwdmhsgzzajtrpnkkswsglhrjprxlvwftbtdtacvclotdcepuahcootzfkwqhtydwrgqrilwvbpadvpzwybmowluikmsfkvbebrxletigjjlealczoqnnejvowptikumnokysfjyoskvsxztnqhcwsamopfzablnrxokdxktrwqjvqfjimneenqvdxufahsshiemfofwlyiionrybfchuucxtyctixlpfrbngiltgtbwivujcyrwutwnuajcxwtfowuuefpnzqljnitpgkobfkqzkzdkwwpksjgzqvoplbzzjuqqgetlojnblslhpatjlzkbuathcuilqzdwfyhwkwxvpicgkxrxweaqevziriwhjzdqanmkljfatjifgaccefukavvsfrbqshhswtchfjkausgaukeapanswimbznstubmswqadckewemzbwdbogogcysfxhzreafwxxwczigwpuvqtathgkpkijqiqrzwugtr";
    // string s = "ADOBECODEBANC";
    // string t = "ABC";
    string ans = minWindow2(s, t);
    cout << ans << endl;
    return 0;
}