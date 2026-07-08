/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n, m;
        while(1) {
            m = l + (r-l)/2;
            int check = guess(m);
            if(check == 0) {
                return m;
            } else if(check == -1){
                r  = m-1;
            } else {
                l = m+1;
            }
        }
        return m;
    }
};