class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalcost=0;
        int totalgas=0;
        for(int i=0;i<n;i++){
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalcost>totalgas){
            return -1;
        }
        int current_fuel=0;
        int start=0;
        for(int i=0;i<n-1;i++){
            current_fuel+=(gas[i]-cost[i]);
            if(current_fuel<0){
                start=i+1;
                current_fuel=0;
            }
        }
        return start;
    }
};