/**
小美的机器人
时间限制： 3000MS
内存限制： 589824KB
题目描述：
小美在数轴上放置了若干个机器人，这些机器人每到整数时刻，就会检查是否和其他机器人重合。如果重合，它就会原地爆炸。

这些机器人的移动速度均为 1 。举例来说，如果一个机器人初始位于点3，然后它的方向是向右的，则时刻1会位于点4，时刻2会位于点5。

小美现在给小团这样一个任务：小美将给出所有机器人的初始位置和初始朝向。小团的任务是判断每个机器人的爆炸时刻。当然，如果有一些机器人永远不会爆炸，则输出-1。

小团向你求助。你能帮帮小团吗？

注意事项1：一个机器人爆炸了之后，就不会再继续存在在这个数轴上。

举例来说，如果有三个机器人，一个位于位置0，向右，一个位于位置2，向右，一个位于位置4，向左。则时刻1的时候，后两个机器人会在位置3相遇并发生爆炸，此后第一个机器人和第三个机器人不会在时刻2继续爆炸（因为此时已经不存在第三个机器人了）

注意事项2：请注意，只有整数时刻机器人才会检查重合。

举例来说，如果有两个机器人，一个位于位置1，向右，一个位于位置2，向左，则它们并不会在整数时刻重合。因此它们两个不存在相遇爆炸。

注意事项3：保证机器人初始时刻不会重叠。换句话说，不存在在时刻0就立刻爆炸的机器人。



输入描述
第一行一个正整数 n 表示有 n 个机器人。

接下来 n 行，每行一个正整数和一个字符，以空格分隔。正整数代表机器人的坐标，字符为大写字母 L 和 R 的其中一个，分别表示机器人向左运动 和 向右运动。

输出描述
输出 n 行，每行一个数字，对应表示每个机器人的答案：

若该机器人会爆炸，输出爆炸时间；若该机器人不会爆炸，输出-1。


样例输入
10
94 R
74 L
90 L
75 R
37 R
99 R
62 R
4 L
92 L
44 R
样例输出
-1
6
23
-1
-1
-1
6
-1
-1
23

提示
数据范围和说明

对于所有数据都保证机器人的坐标处于[1, 1e9]的正整数范围内。

其中，对于30%的数据，保证机器人数量 n <= 10

对于100%的数据，保证机器人数量 n <= 1,000
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Robert{
    int number;
    int boomTime;
    char direction;
};

/**
 *
 * key 代表位置
 */
bool isOver(unordered_map<int, Robert> &hashTab) {
    for (auto iter_i = hashTab.begin(); iter_i != hashTab.end(); iter_i++) {
        for (auto iter_j = next(iter_i); iter_j != hashTab.end(); iter_j++) {
            if ((iter_i->second.direction == 'L' && iter_j->second.direction == 'R') &&
                    (iter_i->first > iter_j->first)) {
                if (abs(iter_i->first - iter_j->first) % 2 == 0) {
                    return false;
                }
            }
            if ((iter_i->second.direction == 'R' && iter_j->second.direction == 'L') &&
                    (iter_i->first < iter_j->first)){
                if (abs(iter_i->first - iter_j->first) % 2 == 0) {
                    return false;
                }
            }
        }
    }

    return true;
}

/**
 * 【难点】如何判断永远不会爆炸？
 * 1、同向同速
 * 2、背对反向
 *
 * 正确率为 36%！超时
 */
void isBoom(unordered_map<int, Robert> &hashTab) {
    // key 代表机器编号
    unordered_map<int, int> boomTime;

    // key 代表机器位置
    unordered_map<int, Robert> oldTable = hashTab;
    for (int currentTime = 1; ; currentTime++) {
        //cout << "currentTime:" << currentTime << endl;
        unordered_map<int, Robert> newTable;
        for (auto &e:oldTable) {
            if (e.second.boomTime == -1 && e.second.direction == 'L') {
                int newPosition = e.first - 1;
                // 相遇爆炸
                if (newTable.find(newPosition) != newTable.end()) {
                    boomTime[e.second.number] = currentTime;
                    int occurNumber = newTable[newPosition].number;
                    boomTime[occurNumber] = currentTime;

                    newTable.erase(newPosition);
                    newTable.erase(e.first);
                } else {
                    newTable[newPosition] = e.second;
                }

            } else if (e.second.boomTime == -1 && e.second.direction == 'R') {
                int newPosition = e.first + 1;
                // 相遇爆炸
                if (newTable.find(newPosition) != newTable.end()) {
                    boomTime[e.second.number] = currentTime;
                    int occurNumber = newTable[newPosition].number;
                    boomTime[occurNumber] = currentTime;
                    newTable.erase(newPosition);
                    newTable.erase(e.first);
                } else {
                    newTable[newPosition] = e.second;
                }
            }
        }
        if (isOver(newTable)) {
            break;
        }
        oldTable = newTable;
    }

    for (int i = 0; i < hashTab.size(); i++) {
        if (boomTime.find(i) != boomTime.end()) {
            cout << boomTime[i] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    int n;
    unordered_map<int, Robert> hashTab;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int initPos;
        cin >> initPos;

        char cDirection;
        cin >> cDirection;

        Robert robert = {i, -1, cDirection};

        hashTab[initPos] = robert;
    }

    isBoom(hashTab);

    return 0;
}