class Solution {
public:
    bool canWinNim(int n) {
        return n&0x00000003;
    }
};