class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int h=stoi(startTime.substr(0,2));
        int m=stoi(startTime.substr(3,2));
        int s=stoi(startTime.substr(6,2));

        int sec1=(s+m*60+h*60*60);

        int h1=stoi(endTime.substr(0,2));
        int m1=stoi(endTime.substr(3,2));
        int s1=stoi(endTime.substr(6,2));

        int sec2=(s1+m1*60+h1*60*60);

        return abs(sec2-sec1);
    }
};