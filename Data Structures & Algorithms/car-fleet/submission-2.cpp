class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<pair<int,int>> vt;

        for (int i = 0; i < position.size(); i++) {
            vt.push_back({position[i], speed[i]});
        }

        sort(vt.rbegin(), vt.rend());

        for (int j = 0; j < vt.size(); j++) {
            double time = (double)(target - vt[j].first) / vt[j].second;

            if (st.empty()) {
                st.push(time);
            }
            else {
                double top = st.top();

                if (time > top) {
                    st.push(time);
                }
            }
        }

        return st.size();
    }
};