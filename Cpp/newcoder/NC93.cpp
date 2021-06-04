/**
 * 运行时间：1078ms
超过31.70% 用C++提交的代码
        占用内存：24104KB
超过16.50%用C++提交的代码
 */
class MyLRU {
    int k;
    list<pair<int, int>> myList;
    unordered_map<int, list<pair<int,int>>::iterator> hashTable;

public:
    MyLRU(int k):k(k) {

    }

    void set(int key, int value) {
        // 不存在
        if (hashTable.find(key) == hashTable.end()) {
            // 容量已满
            if (myList.size() == k) {
                // 先删除
                int key = myList.back().first;
                myList.pop_back();
                hashTable.erase(key);
            }
        } else {
            // 已存在
            // 若原本就在最新位置，就不用更新
            if (hashTable[key] == myList.begin())
                return;
            else {
                // 先删除
                auto iter = hashTable[key];
                myList.erase(iter);
                hashTable.erase(key);
            }
        }
        // 插入
        this->myList.push_front({key,value});
        this->hashTable[key] = this->myList.begin();

    }

    int get(int key) {
        if (hashTable.find(key) == hashTable.end()) {
            return -1;
        } else {
            auto iter = hashTable[key];
            int value = iter->second;
            // 先删除
            myList.erase(iter);
            hashTable.erase(key);

            // 再插入
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
     *
     * 有一个问题：<key, value>, (3, 2), (3, 1)，冲突怎么处理？
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> rt;
        if (operators.size() == 0 or k <= 0) {
            return rt;
        }
        MyLRU myLRU(k);

        for (auto oper : operators) {
            // set(key, value)
            if (oper[0] == 1) {
                int key = oper[1];
                int value = oper[2];
                myLRU.set(key, value);
            } else if (oper[0] == 2) {
                // get(x)
                int key = oper[1];
                int value = myLRU.get(key);
                rt.push_back(value);
            }
        }

        return rt;
    }
};