/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

*/

// use map to save start count and end count
// for item in map, if item.second == 1, room++, else room--, max_r = max(max_r, room)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        map<int, int> m;
        for(Interval interval: intervals)
        {
            m[interval.start]++;
            m[interval.end]--;
        }
        // a interval begin, needed room++
        // a interval end, needed room--
        // track the max room number needed
        int max_room = 0;
        int room = 0;
        for(auto item: m)
        {    
            room += item.second;
            max_room = max(max_room, room);
        }    
        return max_room;
            
            
        
    }
}; 
