class Solution {
public:
    // Helper function to compute character frequency for a word
    vector<int> getFrequency(const string& word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        return freq;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Step 1: Compute the maximum frequency count for words2
        vector<int> maxCount(26, 0);
        for (const string& word : words2) {
            vector<int> freq = getFrequency(word);
            for (int i = 0; i < 26; ++i) {
                maxCount[i] = max(maxCount[i], freq[i]);
            }
        }

        // Step 2: Check each word in words1
        vector<string> result;
        for (const string& word : words1) {
            vector<int> freq = getFrequency(word);
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxCount[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};
