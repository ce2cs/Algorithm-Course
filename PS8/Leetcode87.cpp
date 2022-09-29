class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1.length() == 1 && s1 == s2) return true;
        
        for (int i = 1; i < s1.length(); i++) {
            auto s1_left = s1.substr(0, i);
            auto s1_right = s1.substr(i, s1.length() - i);
            auto s2_left = s2.substr(0, i);
            auto s2_right = s2.substr(i, s1.length() - i);
            if (isScramble(s1_left, s2_left) && isScramble(s1_right, s2_right)) return true;
            s1_left = s1.substr(s1.length() - i, i);
            s1_right = s1.substr(0, s1.length() - i);
            if (isScramble(s1_left, s2_left) && isScramble(s1_right, s2_right)) return true;
        }
        return fase;
    }
};
