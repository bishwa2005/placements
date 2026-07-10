class Solution {
public:
    // Comparator to sort items by value-to-weight ratio in descending order
    static bool cmp(const vector<double>& a, const vector<double>& b) {
        return a[0] > b[0];
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<double>> items;

        // Store {ratio, value, weight}
        for (int i = 0; i < n; i++) {
            items.push_back({(double)val[i] / wt[i], (double)val[i], (double)wt[i]});
        }

        // Sort based on ratio
        sort(items.begin(), items.end(), cmp);

        double totalValue = 0.0;

        for (const auto& item : items) {
            double ratio = item[0];
            double value = item[1];
            double weight = item[2];

            if (capacity <= 0) break;

            if (weight <= capacity) {
                totalValue += value;
                capacity -= weight;
            } else {
                totalValue += (ratio * capacity);
                capacity = 0; // Knapsack is now full
            }
        }
        return totalValue;
    }
};
