/*


It is a very good concept in which we only focus on moving forward untill the diff %2!=0 

*/
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);

        long long sum = 0;
        int k = 0;

        while (sum < target || (sum - target) % 2) {
            k++;
            sum += k;
        }

        return k;
    }
};