class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }
        while (!freq.empty()) {
            int start = freq.begin()->first;
            for (int i = 0; i < groupSize; ++i) {
                int card = start + i;
                if (freq[card] == 0) return false;
                if (--freq[card] == 0) {
                    freq.erase(card);
                }
            }
        }

        return true;
    }
};