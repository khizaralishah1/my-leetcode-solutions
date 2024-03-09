class Solution {
public:
    void removes(int f, int e, vector<vector<int>>& intervals) {
        int smaller = e < intervals.size() ? e: intervals.size() - 1;
        for ( int i = f; i <= smaller; ++i ) {
            intervals.erase(intervals.begin() + f);
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if (intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        //if some interval subsumes it, get out
        int f = 0;
        for ( ; f < intervals.size(); ++f ) {
            if ( intervals[f][0] <= newInterval[0] && intervals[f][1] >= newInterval[1] )
                return intervals;
        }

        //none subsumes it completely, check overlaps, first and last
        f = 0;
        for ( ; f < intervals.size(); ++f ) {
            if ( intervals[f][0] <= newInterval[0] && intervals[f][1] >= newInterval[0] )
                break;
            else if (intervals[f][0] >= newInterval[0] && intervals[f][1] <= newInterval[1])
                break;
            else if ( intervals[f][0] > newInterval[1] ) {
                intervals.insert( intervals.begin() + f, newInterval);
                return intervals;
            }
            // else if ( intervals[f][0] >= newInterval[0] && intervals[f][1] <= newInterval[1] ) {
            //     intervals.erase( intervals.begin() + f);
            //     intervals.insert( intervals.begin() + f, newInterval);
            //     return intervals;
            // }
            else if ( intervals[f][0] >= newInterval[0] && intervals[f][1] > newInterval[1] ) {
                newInterval[1] = intervals[f][1];
                intervals.erase( intervals.begin() + f);
                intervals.insert( intervals.begin() + f, newInterval);
                return intervals;
            } 
        }

        if ( f == intervals.size() ) {
            intervals.push_back(newInterval);
            return intervals;
        }

        int e = f;

        for ( ; e < intervals.size(); ++e ) {
            if ( intervals[e][0] <= newInterval[1] && intervals[e][1] >= newInterval[1] )
                break;
            else if ( intervals[e][0] > newInterval[1] ) {
                --e;
                break;
            } 
        }

        int valf = newInterval[0] < intervals[f][0] ? newInterval[0] : intervals[f][0];

        int vale;
        if ( e != intervals.size() )
            vale = newInterval[1] > intervals[e][1] ? newInterval[1] : intervals[e][1];
        else
            vale = newInterval[1];

        removes(f, e, intervals);

        vector<int> res;
        res.push_back(valf);
        res.push_back(vale);
        intervals.insert( intervals.begin() + f, res);

        cout << f << " and " << e << endl;

        return intervals;
    }
};