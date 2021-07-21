/*
 * 编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址

IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1；
同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。

IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。

然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。
同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。

说明: 你可以认为给定的字符串里没有空格或者其他特殊字符。
 */


/**
 * 思路 1：正则表达式
 */
string solve(string IP) {
    // write code here
}

/**
 * 思路 2：字符串分割
 * 运行时间：3ms
超过9.82% 用C++提交的代码
占用内存：400KB
超过31.74%用C++提交的代码
 */
string solve(string IP) {
    vector<string> v = split(IP);
    int n = v.size();
    if (n == 4) {
        if (isIPv4(v))
            return "IPv4";
    } else if (n == 8) {
        if (isIPv6(v))
            return "IPv6";
    }
    return "Neither";
}

bool isIPv6(vector<string> v) {
    for(auto s : v) {
        if (s.length() <= 0 or s.length() >4)
            return false;
        try {
            long n = strtol(s.c_str(), NULL, 16);
            if (n < 0x0000 or n > 0xFFFF)
                return false;
        } catch(...) {
            return false;
        }
    }
    return true;
}

bool isIPv4(vector<string> v) {
    for(auto s : v) {
        if (s.length() >= 2) {
            if (s[0] == '0')
                return false;
        }
        if (s.length() <= 0 or s.length() > 3)
            return false;
        try {
            int n = atoi(&s[0]);
            if (n < 0 or n > 255)
                return false;
        } catch (...) {
            return false;
        }

    }
    return true;
}

vector<string> split(string ip) {
    vector<string> v;
    if (ip.find('.') != -1) {
        int p = 0;
        while (1) {
            int start = p;
            p = ip.find('.', p);
            if (p != -1) {
                int end = p;
                string s(ip, start, end-start);
                v.push_back(s);
            } else {
                string s = ip.substr(start);
                v.push_back(s);
                break;
            }
            p++;
        }
    } else if (ip.find(':') != -1) {
        int p = 0;
        while (1) {
            int start = p;
            p = ip.find(':', p);
            if (p != -1) {
                int end = p;
                string s(ip, start, end-start);
                v.push_back(s);
            } else {
                string s = ip.substr(start);
                v.push_back(s);
                break;
            }
            p++;
        }
    }
//         for (auto s:v) {
//             cout << s << endl;
//         }
    return v;
}
