/**
 * 标准 std 中只有 map, 没有提供 hash map
 * gnu c++ 提供了 hash_map，是一个 hash map 的实现，查找和添加复杂度均为 O(1)。
 *
 * c++ tr1(C++ Technical Report 1) 作为标准的扩展，实现了 hash map，
 * 提供了和 stl 兼容一致的 api，称为 unorder_map，在头文件 <tr1/unordered_map> 中。
 * 另外 c++ tr1 还提供了正则表达式、智能指针、hash table、随机数生成器的功能。
 */
#include <tr1/unordered_map>
using namespace std;


void test_0() {

}