/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        if(intervals.size()==0)
        {
            return 0;
        }

        sort(intervals.begin(),intervals.end(),[](const Interval &a,const Interval &b){
            return a.start<b.start;
        });

        priority_queue<int,vector<int>,greater<int>> minH;

        for(int i=0;i<intervals.size();i++)
        {

            if(!minH.empty() && minH.top()<=intervals[i].start)
            {
                minH.pop();
            }

            minH.push(intervals[i].end);
        }

        return minH.size();
        
    }
};
