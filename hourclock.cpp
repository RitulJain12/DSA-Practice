class Solution {
public:
    double angleClock(int hour, int m) {

        double minangl=6.0*m;
        double hrangl=30.0*(hour % 12)+0.5*m;

        double ans=abs(minangl-hrangl);

        return min(ans,360.0-ans);
        
    }
};