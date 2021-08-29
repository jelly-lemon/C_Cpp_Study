/**
volatile 是给编译器的指示来说明对它所修饰的对象不应该执行优化。

- 易变的
假设有读、写两条语句，依次对同一个 volatile 变量进行操作，
 那么后一条的读操作不会直接使用前一条的写操作
 对应的 volatile 变量的寄存器内容，
 而是重新从内存中读取该 volatile 变量的值。

     volatile int nNum = 0;  // 将nNum声明为volatile
    int nSum = 0;

    nNum = FunA();      // nNum被写入的新内容，其值会缓存在寄存器中

    nSum = nNum + 1;    // 此处会从内存（而非寄存器）中读取nNum的值

- 不可优化性
 volatile 会告诉编译器，不要对 volatile 声明的变量进行各种激进的优化
 （甚至将变量直接消除），从而保证程序员写在代码中的指令一定会被执行。


 - 顺序执行的
即能够保证 volatile 变量间的顺序性，不会被编译器进行乱序优化。

 */


/**
 如果变量 nNum 没有声明为 volatile 类型，
 则编译器在编译过程中就会对其进行优化，
 直接使用常量“1”进行替换
 （这样优化之后，生成的汇编代码很简介，执行时效率很高）。
 而当我们使用 volatile 进行声明后，
 编译器则不会对其进行优化，nNum 变量仍旧存在，
 编译器会将该变量从内存中取出，
 放入寄存器之中，然后再调用 printf() 函数进行打印。
 */
void test_0() {
    volatile int nNum;  // 将nNum声明为volatile
    nNum = 1;

    printf("nNum is: %d", nNum);
}