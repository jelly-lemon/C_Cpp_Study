//
// Created by lemon local on 2020/7/27.
// 八皇后求解
//
#include <stdio.h>
#include <math.h>


const int N = 8;


/**
 * 检查这八皇后的位置是否可行
 *
 * @param pos 八皇后的当前位置
 * @return 可行返回 1，不可行返回 0
 */
int check(const int pos[]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            //
            // 先检查是否有位于同一列的
            // 这个简单，就找数组里面是否有相同数字
			// 元素的值就代表了第i个皇后在第几列
            //
            if (pos[i] == pos[j]) return 0;

            //
            // 检查是否有主对角线的、副对角线的
            // 如果横纵坐标差距一样，则说明在对角线上
            // i 和 j 都代表了行数
            //
            if (abs(i - j) == abs(pos[i] - pos[j])) return 0;

        }
    }

    return 1;
}


/**
 * 检查当前已放置的皇后是否满足约束条件
 *
 * @param pos 皇后位置数组
 * @param n 检查的个数，或者说已放置的皇后个数
 * @return 满足约束条件返回 1，不满足则返回 0
 */
int check_constraint(const int pos[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            //
            // 先检查是否有位于同一列的
            // 这个简单，就找数组里面是否有相同数字
            //
            if (pos[i] == pos[j]) return 0;

            //
            // 检查是否有主对角线的、是否有副对角线的
            // 如果横纵坐标差距一样，则说明在对角线上
            // i 和 j 代表了行数
            //
            if (abs(i - j) == abs(pos[i] - pos[j])) return 0;

        }
    }

    return 1;
}

/**
 * 打印输出数组
 *
 * @param pos 八皇后的位置数组
 */
void printPos(int pos[]) {
    int i;

    for (i = 0; i < N; i++) {
        printf("%d\t", pos[i]);
    }
    printf("\n");
}

/**
 * for 循环实现的回溯法
 */
void BacktrackByForCircle() {
    int i1, i2, i3, i4, i5, i6, i7, i8;
    int count = 0;

    int pos[N];
    int i;
    for (i = 0; i < N; i++) {
        pos[i] = 0;
    }

    for (i1 = 0; i1 < N; i1++) {
        pos[0] = i1;

        for (i2 = 0; i2 < N; i2++) {
            pos[1] = i2;
            if (!check_constraint(pos, 2)) {
                continue;
            }
            for (i3 = 0; i3 < N; i3++) {
                pos[2] = i3;
                if (!check_constraint(pos, 3)) {
                    continue;
                }
                for (i4 = 0; i4 < N; i4++) {
                    pos[3] = i4;
                    if (!check_constraint(pos, 4)) {
                        continue;
                    }
                    for (i5 = 0; i5 < N; i5++) {
                        pos[4] = i5;
                        if (!check_constraint(pos, 5)) {
                            continue;
                        }
                        for (i6 = 0; i6 < N; i6++) {
                            pos[5] = i6;
                            if (!check_constraint(pos, 6)) {
                                continue;
                            }
                            for (i7 = 0; i7 < N; i7++) {
                                pos[6] = i7;
                                if (!check_constraint(pos, 7)) {
                                    continue;
                                }
                                for (i8 = 0; i8 < N; i8++) {
                                    pos[7] = i8;

                                    //
                                    // 检查是否满足条件
                                    //
                                    if (check(pos)) {
                                        count++;
                                        printPos(pos);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("count=%d\n", count);

}


/**
 * 枚举法求解
 */
void enumeration() {
    int i1, i2, i3, i4, i5, i6, i7, i8;
    int count = 0;

    int pos[N];
    int i;
    for (i = 0; i < N; i++) {
        pos[i] = 0;
    }

    for (i1 = 0; i1 < N; i1++) {
        pos[0] = i1;
        for (i2 = 0; i2 < N; i2++) {
            pos[1] = i2;
            for (i3 = 0; i3 < N; i3++) {
                pos[2] = i3;
                for (i4 = 0; i4 < N; i4++) {
                    pos[3] = i4;
                    for (i5 = 0; i5 < N; i5++) {
                        pos[4] = i5;
                        for (i6 = 0; i6 < N; i6++) {
                            pos[5] = i6;
                            for (i7 = 0; i7 < N; i7++) {
                                pos[6] = i7;
                                for (i8 = 0; i8 < N; i8++) {
                                    pos[7] = i8;

                                    //
                                    // 检查是否满足条件
                                    //
                                    if (check(pos)) {
                                        count++;
                                        printPos(pos);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("count=%d\n", count);
}

/**
 * 递归形式的回溯法
 * 求解八皇后问题
 *
 * @param k 皇后的编号，从 0 开始
 * @param pos 皇后位置数组
 * @param count 计数，有多少合适的排列
 * @param n 总共有多少个皇后进行排列
 */
void BacktrackByRecursion(int k, int pos[], int *count, int n) {
    //
    // 递归退出条件
	// k 是要进行放置位置的那位皇后
	// 肯定不能大于总皇后数量
    //
    if (k >= n) {
        (*count)++;
        printPos(pos);
        return;
    }

    int i;
    for (i = 0; i < n; i++) {
        pos[k] = i;
		
		//
		// 如果当前位置满足约束条件
		// 就看下一个皇后
		// 否则这条路走不通，回溯
		//
        if (check_constraint(pos, k+1)) {
            backtrack(k+1, pos, count, n);
        }
    }
}





int main() {
    //enumeration();
    //iterative();
    int pos[N];
    int count = 0;
    backtrack(0, pos, &count, N);
    printf("count=%d\n", count);
}
