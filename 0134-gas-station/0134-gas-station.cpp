class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int current_gas = 0;
        int total_cost = 0;
        int totalgas = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            totalgas += gas[i];
            total_cost += cost[i];
            current_gas = current_gas + gas[i] - cost[i];
            if (current_gas < 0) {
                current_gas = 0;
                start = i + 1;
            }
        }
        return totalgas >= total_cost ? start : -1;
    }
};