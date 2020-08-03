class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourHand = (30 * hour) % 360;
        double delta = 30 * ((double)minutes / 60);
        double minuteHand = 360 * ((double)minutes / 60);
        double diff;
        
        hourHand += delta;
        diff = minuteHand - hourHand;
        if (diff < 0)
            diff += 360;
        diff = min(diff, 360 - diff);
        return diff;
    }
};
