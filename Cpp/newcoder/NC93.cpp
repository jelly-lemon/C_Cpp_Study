/**
设计 LRU (最近最少使用)缓存结构，该结构在构造时确定大小，
假设大小为 K，并有如下两个功能
1. set(key, value)：将记录(key, value)插入该结构
2. get(key)：返回key对应的value值

 输入一个二维数组与 K，二维数组每一维有 2 个或者 3 个数字，
 第 1 个数字为 opt，第 2，3 个数字为 key，value
若opt=1，接下来两个整数key, value，表示set(key, value)
若opt=2，接下来一个整数key，表示get(key)，若key未出现过或已被移除，则返回-1
对于每个opt=2，输出一个答案

 输入：
[[1,1,1],[1,2,2],[1,3,2],[2,1],[1,4,4],[2,2]],3

 返回值：
[1,-1]

 说明：
[1,1,1]，第一个1表示opt=1，要set(1,1)，即将(1,1)插入缓存，缓存是{"1"=1}
[1,2,2]，第一个1表示opt=1，要set(2,2)，即将(2,2)插入缓存，缓存是{"1"=1,"2"=2}
[1,3,2]，第一个1表示opt=1，要set(3,2)，即将(3,2)插入缓存，缓存是{"1"=1,"2"=2,"3"=2}
[2,1]，第一个2表示opt=2，要get(1)，返回是[1]，因为get(1)操作，缓存更新，缓存是{"2"=2,"3"=2,"1"=1}
[1,4,4]，第一个1表示opt=1，要set(4,4)，即将(4,4)插入缓存，但是缓存已经达到最大容量3，移除最不经常使用的{"2"=2}，插入{"4"=4}，缓存是{"3"=2,"1"=1,"4"=4}
[2,2]，第一个2表示opt=2，要get(2)，查找不到，返回是[1,-1]
 */


/**
 *
 * 运行时间：1078ms
超过31.70% 用C++提交的代码
占用内存：24104KB
超过16.50%用C++提交的代码
 */
class MyLRU {
    int k;  // 空间大小
    list<pair<int, int>> myList;    // 链表，用来保存页面
    unordered_map<int, list<pair<int,int>>::iterator> hashTable;    // 哈希表，用来记录页面所在链表中的位置

public:
    MyLRU(int k):k(k) {

    }

    /**
     * 调入页面
     */
    void set(int key, int value) {
        //
        // 若调入前不存在
        //
        if (hashTable.find(key) == hashTable.end()) {
            //
            // 缓存容量已满
            //
            if (myList.size() == k) {
                //
                // 先删除 LRU 页面，也就是链表最末尾页面
                //
                key = myList.back().first;
                myList.pop_back();
                hashTable.erase(key);   // 哈表表擦除
            }
        } else {
            //
            // 若调入前已存在
            // 若原本就在最新位置，就不用更新
            //
            if (hashTable[key] == myList.begin()) {
                return;
            } else {
                //
                // 先删除 LRU 页面，也就是链表最末尾页面
                //
                auto iter = hashTable[key];
                myList.erase(iter);
                hashTable.erase(key);
            }
        }

        //
        // 插入新页面到链表头，哈希表记录位置
        //
        this->myList.push_front({key,value});
        this->hashTable[key] = this->myList.begin();

    }

    /**
     * 访问页面，也会引起缓存变化
     */
    int get(int key) {
        //
        // 若不存在该页面
        //
        if (hashTable.find(key) == hashTable.end()) {
            return -1;
        } else {
            auto iter = hashTable[key];
            int value = iter->second;
            //
            // 先删除原 LRU 缓存中的页面
            //
            myList.erase(iter);
            hashTable.erase(key);

            //
            // 再插入该页面到链表头
            //
            myList.push_front({key, value});
            hashTable[key] = myList.begin();

            return value;
        }
    }

};

class Solution {
public:
    /**
     * 思路 1：哈希表存链表节点地址，链表存数据
     *
     * 有一个问题：<key, value>, (3, 2), (3, 1)，冲突怎么处理？
     * 数据是 key-value 的形式，题目应该会保证只会出现唯一 key
     *
     * @param operators 操作
     * @param k LRU 缓存大小
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        vector<int> rt;
        if (operators.size() == 0 or k <= 0) {
            return rt;
        }

        MyLRU myLRU(k);
        for (auto oper : operators) {
            //
            // oper 为 1，表示调入页面
            //
            if (oper[0] == 1) {
                int key = oper[1];
                int value = oper[2];
                myLRU.set(key, value);
            } else if (oper[0] == 2) {
                //
                // oper 为 2，表示访问页面
                //
                int key = oper[1];
                int value = myLRU.get(key);
                rt.push_back(value);
            }
        }

        return rt;
    }
};