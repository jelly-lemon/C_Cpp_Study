/*
 * 请实现支持'?'and'*'.的通配符模式匹配
'?' 可以匹配任何单个字符。
'*' 可以匹配任何字符序列（包括空序列）。
返回两个字符串是否匹配
函数声明为：
bool isMatch(const char *s, const char *p)
下面给出一些样例：
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "d*a*b") → false
 输入："ab","?*"
 返回值：true
 */