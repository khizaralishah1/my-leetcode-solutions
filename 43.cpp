class Solution {
public:

    string adder(string a, string b) {
        
        int small_size = a.length() < b.length() ? a.length() : b.length();
        int smaller = 0; // a is smaller
        
        if ( a.length() == b.length() )
            smaller = 2;
        else if ( small_size == b.length() )
            smaller = 1; // b is smaller

        string results;
        int carry = 0;
        int added = 0;

        for ( int count = 0; count < small_size; ++count ) {
            added = a[ a.length() - 1 - count ] + b[ b.length() - 1 - count ] + carry - 96;
            
            results.push_back(char(added % 10 + 48));
            carry = (added - added % 10) / 10;
        }

        if ( smaller != 2 ) {
            for ( int i = smaller * ( a.length() - b.length() ) + (1 - smaller) * ( b.length() - a.length() ) - 1; i >= 0; --i ) {
                if ( smaller == 0 ) { // a is smaller
                    added = b[i] + carry - 48;
                    results.push_back(char(added % 10 + 48));
                    carry = (added - added % 10) / 10;
                } else {
                    added = a[i] + carry - 48;
                    results.push_back(char(added % 10 + 48));
                    carry = (added - added % 10) / 10;
                }
            }
        }

        if ( carry != 0 )
            results.push_back(char(carry + 48));

        reverse(results.begin(), results.end());

        return results;
    }

    string multiply(string num1, string num2) {

        string check = "0";
        if (num2 == "0" || num1 == "0") return check;
        
        int large_size = num1.length() > num2.length() ? num1.length() : num2.length();
        string results;
        int carry = 0;
        int window;

        string temp;

        if (large_size == num2.length()) {
            temp = num2;
            num2 = num1;
            num1 = temp;
        }

        for ( window = 1; window <= large_size; ++window ) {

            if ( num1.length() == large_size ) {

                int number = carry;
                for ( int k = 1; k <= window; ++k ) {
                   int first  = num1[ num1.length() - 1 - window + k ] - 48;
                   //cout << "f = " << first << " ";
                   int len2 = num2.length();
                   int second = 0;
                   if ( len2 < k ) {
                        break;
                   } else {
                        second = num2[ num2.length() - k ] - 48;
                   }
                        
                   //cout << " s = " << second << " ww " << len2 - k << endl;

                   number += first * second;
                   //cout << " n = " << number << endl;
                   
                }

                carry = (number - number % 10) / 10;
                //cout << "\n n = " << number % 10 << " c = " << carry << endl;

                results.push_back(char(number % 10 + 48));
                

            } else {
                
            }
            
        }

        //cout << "hello";

            for ( int p = 1; p < large_size; ++p) {
                int number = carry;
                for ( int k = 0; k <= large_size - 1  - p; ++k ) {
                    int first  = num1[ k ] - 48;
                    int len2 = num2.length() - 1;
                    int second = 0;
                    if ( len2 - p - k >= 0 )
                        second = num2[ len2 - p - k ] - 48;
                    else
                        break;

                    //cout << "f = " << first << " s = " << second << endl;

                    number += first * second;
                    //cout << " n = " << number << endl;

                }

                if(number == 0 && carry == 0) break;
                results.push_back(char(number % 10 + 48));
                carry = (number - number % 10) / 10;
                //cout << "\n n = " << number % 10 << " c = " << carry << endl;
                
            }


        if ( carry != 0 )
            results.push_back(char(carry + 48));
            

        reverse(results.begin(), results.end());

        return results;
    }
};