/*
 * 给出一组区间，请合并所有重叠的区间。
请保证合并后的区间按区间起点升序排列。
输入：
 [[10,30],[20,60],[80,100],[150,180]]
 返回值：
 [[10,60],[80,100],[150,180]]
 */


static bool compare(Interval x, Interval y) {
    return x.start < y.start;
}

/**
 * 思路 1：先排序，再合并区间
 */
vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> newVec;
    if (intervals.size() == 0)
        return newVec;

    // 先对原始数组进行排序
    sort(intervals.begin(), intervals.end(), compare);

    // TODO 合并区间
    for (int i = 0; i < intervals.size(); i++) {
        Interval t = intervals[i];
        while (t.end >= intervals[i+1].start) {
            if (t.end < intervals[i+1].end)
                t.end = intervals[i+1].end;
            i++;
            if (i >= intervals.size()-1)
                break;
        }
        newVec.push_back(t);
        if (i >= intervals.size()-1)
            break;
    }

    return newVec;
}