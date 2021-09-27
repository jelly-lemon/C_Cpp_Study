# C/C++ 练习
与其看 100 遍，不如自己亲手做一遍。

简单事情重复做，重复事情用心做。

别人的经验，永远没有自己的实践体会更深刻。



# 目录说明
```
----C_Cpp_Study     根目录
    |----include    第三方头文件
    |----lib        第三方库文件
```


# 问题
Q: 一个文件被多次 include 后会怎样？

A: include 是预处理指令，编译器在编译之前会替换 include 文件内容到此处。所以就相当于重复写了多次。


# 环境
编译器（版本特别重要，对不上就很容易出错）：mingw64-x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0

gtest：1.10.0，libgtest.a 静态库是用 mingw64-x86_64-8.1.0-release-posix-sjlj 编译得到的。

# 易错点
`#pragma comment(lib, "ws2_32.lib")` 仅对 VC++ 编译器管用，GNU 编译器不认。

