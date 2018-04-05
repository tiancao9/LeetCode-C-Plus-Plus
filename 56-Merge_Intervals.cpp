/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//sort the interval with start value
//interate intervals, for each interval (i > 0), if cur.start < res[-1].end, res[-1].end = max(cur.end, res[-1].end), else res.push_back(cur)
class Solution {
public:
    struct CompInterval {
      bool operator() (const Interval& a, const Interval& b) const{
          return a.start<b.start; 
      }  
    };
    vector<Interval> merge(vector<Interval>& intervals) {                
        vector<Interval> res;        
        if(intervals.empty())
            return res;
               
        sort(intervals.begin(), intervals.end(), CompInterval());
    
        for(int i = 0; i < intervals.size(); i++)
        {
            
            Interval cur(intervals[i].start,intervals[i].end);
            int n = res.size();
            if(i != 0 && cur.start <= res[n-1].end)
                res[n-1].end = max(cur.end, res[n-1].end);
            else
                res.push_back(cur);
            
        }
        
        return res;
    }
};
