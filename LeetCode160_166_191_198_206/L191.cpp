class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret=0;
        while(n){
            ret+=n&0x00000001;
            n>>=1;
        }
        return ret;
    }
};

//Slower but tricky
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret=0;
        while(n){
            ret++;
            n &= (n - 1);;
        }
        return ret;
    }
};

