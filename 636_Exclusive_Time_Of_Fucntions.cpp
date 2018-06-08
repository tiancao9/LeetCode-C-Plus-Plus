/*
Given the running logs of n functions that are executed in a nonpreemptive single threaded CPU, find the exclusive time of these functions.

Each function has a unique id, start from 0 to n-1. A function may be called recursively or by another function.

A log is a string has this format : function_id:start_or_end:timestamp. For example, "0:start:0" means function 0 starts from the very beginning of time 0. "0:end:0" means function 0 ends to the very end of time 0.

Exclusive time of a function is defined as the time spent within this function, the time spent by calling other functions should not be considered as this function's exclusive time. You should return the exclusive time of each function sorted by their function id.

Example 1:
Input:
n = 2
logs = 
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
Output:[3, 4]
Explanation:
Function 0 starts at time 0, then it executes 2 units of time and reaches the end of time 1. 
Now function 0 calls function 1, function 1 starts at time 2, executes 4 units of time and end at time 5.
Function 0 is running again at time 6, and also end at the time 6, thus executes 1 unit of time. 
So function 0 totally execute 2 + 1 = 3 units of time, and function 1 totally execute 4 units of time.
Note:
Input logs will be sorted by timestamp, NOT log id.
Your output should be sorted by function id, which means the 0th element of your output corresponds to the exclusive time of function 0.
Two functions won't start or end at the same time.
Functions could be called recursively, and will always end.
1 <= n <= 100
*/

// use stack to push {id, time}, when we see 'end', pop top and add time-start_time+1 into res[id], also reduce duration to previous id
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int, int>> s;
        for(string log: logs)
        {
            int pos1 = log.find(':');
            int pos2 = log.find(':', pos1+1);
            int id = stoi(log.substr(0, pos1));
            string status = log.substr(pos1+1, pos2-pos1-1);
            int time = stoi(log.substr(pos2+1));
            if(status == "start")
                s.push(make_pair(id, time));
            else
            {
                int start_time = s.top().second; s.pop();
                int duration = time-start_time+1;
                res[id] += duration; // s.top().first may not be id!
                
                if(!s.empty())
                    res[s.top().first] -= duration;
            }
        }
        return res;
    }
};
