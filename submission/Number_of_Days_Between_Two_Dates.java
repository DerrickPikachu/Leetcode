import java.text.SimpleDateFormat;
import java.util.Date;

class Solution {
    public int daysBetweenDates(String date1, String date2) {
        SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd");
        Date latter = null;
        Date earlier = null;
        try {
            if (date1.compareTo(date2) > 0) {
                latter = format.parse(date1);
                earlier = format.parse(date2);
            } else {
                latter = format.parse(date2);
                earlier = format.parse(date1);
            }
        }
        catch (Exception e) {}
        
        long diff = latter.getTime() - earlier.getTime();
        return (int)(diff / (1000 * 60 * 60 * 24));
    }
}
