/**
 * 描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

 示例1
输入："We Are Happy"

返回值："We%20Are%20Happy"
 */


/**
    用 C++ string 就很简单，不用考虑空间的问题。

     * 运行时间：3ms
超过66.83% 用C++提交的代码
占用内存：408KB
超过50.05%用C++提交的代码
     */
string replaceSpace(string s) {
    // write code here
    string newStr;
    for (auto &c:s) {
        if (c == ' ') {
            newStr += "%20";
        } else {
            newStr += c;
        }
    }

    return newStr;
}