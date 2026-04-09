class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp; // val -> index

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        
        int idx = mp[val];
        int last = nums.back();
        
        // swap with last element
        nums[idx] = last;
        mp[last] = idx;
        
        // remove last
        nums.pop_back();
        mp.erase(val);
        
        return true;
    }
    
    int getRandom() {
        int randIndex = rand() % nums.size();
        return nums[randIndex];
    }
};