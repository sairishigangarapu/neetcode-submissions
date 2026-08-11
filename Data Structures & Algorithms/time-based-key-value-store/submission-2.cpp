class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> a;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        a[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (a.find(key) == a.end()) {
            return "";
        }

        vector<pair<int, string>>& v = a[key];

        int l = 0;
        int r = v.size() - 1;

        string ans = "";

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (v[m].first == timestamp) {
                return v[m].second;
            }
            else if (v[m].first < timestamp) {
                ans = v[m].second;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        return ans;
    }
};