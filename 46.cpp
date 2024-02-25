class Solution {
public:

    void prints(vector<vector<int>>& myv) {
        cout << "myv = ";
        for(int i=0; i<myv.size(); ++i) {
            cout << "[";
            for(int j=0; j<myv[i].size(); ++j) {
                cout << myv[i][j] << " ";
            }
            cout << "] ";
        }
        cout << endl;
    }

    void printv(vector<int>& nums) {
        cout << "v = ";
        for(int i=0; i<nums.size(); ++i) cout << nums[i] << " ";
        cout << endl;
    }

    int factorials(int n) {
        int f = 1;
        while(n != 0) {
            f *= n;
            --n;
        }
        return f;
    }

    vector<vector<int>> putter( int n, vector<vector<int>>& v ) {
        
        vector<vector<int>> res;

        for( int p = 0; p < v.size(); ++p ) {

            for( int i = 0; i < v[p].size() + 1; ++i ) {
                vector<int> inner;
                for( int k = 0; k < i; ++k ) {
                    inner.push_back( v[p][k] );
                }

                inner.push_back(n);

                for( int k = i + 1; k < v[p].size() + 1; ++k ) {
                    inner.push_back( v[p][k-1] );
                }
                
                res.push_back(inner);
            }
        }

        return res;
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> temp2;

        if (nums.size() == 1) {
            vector<int> vec;
            vec.push_back(nums[0]);
            temp2.push_back(vec);
            return temp2;
        }

        int val = nums[nums.size() - 1];
        nums.pop_back();

        vector<vector<int>> temp = permute(nums);
        temp2 = putter(val, temp);

        //result.push_back(temp2);
        
        return temp2;

    }
};