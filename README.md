# C/C++ 练习
与其看100遍，不如自己亲手做一遍。<br/>
简单事情重复做，重复事情用心做。<br/>
别人的经验，永远没有自己的体会更深刻。<br/>

# 问题
一个文件被多次 include 后会怎样？<br/>


# 环境
编译器（版本特别重要，对不上就出错）：mingw64-x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0<br/>
gtest：1.10.0，libgtest.a 静态库是用 mingw64-x86_64-8.1.0-release-posix-sjlj 编译得到的。

# 易错点
#pragma comment(lib, "ws2_32.lib") 仅对 VC++ 编译器管用，GNU 编译器不认。
