/**
 * @param {number[][]} intervals
 * @return {number}
 */
 var eraseOverlapIntervals = function(intervals) {
    intervals.sort((a, b) => {
        if (a[1] > b[1]) return 1;
        else if (a[1] < b[1]) return -1;
        else {
            if (a[0] > b[0]) return 1;
            else if (a[0] < b[0]) return -1;
        }
    });
    console.log({intervals});
    let ans = 1;
    let cur = 1;
    let base = intervals[0];
    while (cur < intervals.length) {
        if (base[1] <= intervals[cur][0]) {
            base = intervals[cur];
            ans++;
        }
        cur++;
    }
    return intervals.length - ans;
};