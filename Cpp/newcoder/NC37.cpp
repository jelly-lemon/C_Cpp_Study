/*
 * 给出一组区间，请合并所有重叠的区间。
请保证合并后的区间按区间起点升序排列。
输入：
 [[10,30],[20,60],[80,100],[150,180]]
 返回值：
 [[10,60],[80,100],[150,180]]
 */


static bool compare(Interval &x, Interval &y) {
    return x.start < y.start;
}

/**
 * 思路 1：先排序，再合并区间

 [0,2],[[1,4],[3,5]]，存在二次合并的情况

 运行时间：4ms
超过53.56% 用C++提交的代码
占用内存：604KB
超过18.80%用C++提交的代码
 */
vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() == 0 || intervals.size() == 1) {
        return intervals;
    }
    vector<Interval> newVec;

    //
    // 先对原始数组进行升序排序
    //
    sort(intervals.begin(), intervals.end(), compare);

    //
    // 合并区间
    //
    for (int i = 0; i < intervals.size(); i++) {
        Interval t = intervals[i];

        //
        // 后面还有区间
        //
        while (i+1 < intervals.size()) {
            bool isMerged = false;
            //
            // 完全包含的情况
            //
            if (t.start <= intervals[i+1].start && t.end >= intervals[i+1].end) {
                isMerged = true;
                i++;
            } else if (t.end >= intervals[i+1].start) {
                //
                // 部分重叠的情况
                //
                isMerged = true;
                t.end = intervals[i+1].end;
                i++;
            } else {
                //
                // 没有重叠
                //
                if (isMerged) {
                    i--;
                }
                break;
            }
        }
        newVec.push_back(t);
    }

    return newVec;
}