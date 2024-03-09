class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if ( intervals.size() == 1 ) return intervals;

        //sort
        // cout << "\nSTART\n";

        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size(); ++i) {
            cout << "[" << intervals[i][0] << "," << intervals[i][1] << "] ";
        }

        cout << "\nEND\n";

        int prev = 0, cur = 1;

        vector<vector<int>> results;

        for ( ; cur < intervals.size() + 1; ) {
            if ( prev == intervals.size() - 1 || cur > intervals.size() - 1) {
                results.push_back(intervals[prev]);
                break;
            }
            else if ( intervals[prev][1] >= intervals[cur][0] ) {

                int smallest = intervals[prev][0] < intervals[cur][0] ? intervals[prev][0] : intervals[cur][0];
                int largest  = intervals[prev][1] > intervals[cur][1] ? intervals[prev][1] : intervals[cur][1];

                bool op = false;
                while ( cur < intervals.size() && ( intervals[prev][0] <= intervals[cur][0] && intervals[prev][1] >= intervals[cur][1] ) ) {
                    ++cur;
                    op = true;
                }

                if ( op ) continue;
                //if ( cur < intervals.size() && intervals[prev][1] < intervals[cur][0] ) continue;

                //largest = intervals[cur][1];
                largest = largest > intervals[cur][1] ? largest : intervals[cur][1];

                while ( cur < intervals.size() - 1 && (largest >= intervals[cur+1][0]) ) {
                    ++cur;
                    if ( intervals[cur][0] < smallest ) smallest = intervals[cur][0];
                    else if ( intervals[cur][1] > largest ) largest = intervals[cur][1];
                    //else if ( intervals[cur+1][1] > largest ) largest = intervals[cur+1][1];
                }
   
                vector<int> myinterval;
                myinterval.push_back(smallest);
                myinterval.push_back(largest);
                results.push_back(myinterval);
                if ( cur == intervals.size() - 1 ) { break; }
                prev = ++cur;
                ++cur;
            } 
            else {
                results.push_back(intervals[prev]);
                if ( cur == intervals.size() - 1 ) { results.push_back(intervals[cur]); break; }

                //prev = ++cur;
                //++cur;
                prev = cur;
                ++cur;
            }
        }

        return results;
    }
};