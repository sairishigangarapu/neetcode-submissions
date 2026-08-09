class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vt;

        for (int i = 0; i < position.size(); i++) {
            vt.push_back({position[i], speed[i]});
        }

        sort(vt.rbegin(), vt.rend());

        int fleets = 0;
        double lastTime = 0;

        for (int j = 0; j < vt.size(); j++) {
            double time = (double)(target - vt[j].first) / vt[j].second;

            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
        }

        return fleets;
    }
};