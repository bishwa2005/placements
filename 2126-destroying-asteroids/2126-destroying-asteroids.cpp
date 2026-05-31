class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long new_mass=mass;
        for(int i : asteroids){
            if(i>new_mass) return false;
            else new_mass+=i;
        }

        return true;

    }
};