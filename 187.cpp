class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int size = s.length();
        vector<string> results;
        map<string, int> mymap;

        string dna;

        for ( int i = 0; i < size - 9; ++i ) {
            dna = s.substr(i, 10);
            if (mymap.find(dna) == mymap.end()) {
                mymap.insert({dna, 1});
            } else {
                if (mymap[dna] == 1) results.push_back(dna);
                mymap[dna] = 2;
            }
        }

       return results;

    }
};