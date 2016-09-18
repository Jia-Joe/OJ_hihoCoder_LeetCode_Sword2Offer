/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL) return NULL;
        unordered_map<RandomListNode*, int> mp;
        RandomListNode *hd = pHead;
        int n = 0;
        while (hd){
            mp[hd] = n++;
            hd = hd->next;
        }
        RandomListNode** cp = new RandomListNode*[n];
        cp[0] = new RandomListNode(pHead->label);
        hd = pHead->next;
        for (int i = 1; i < n; i++){
            cp[i] = new RandomListNode(hd->label);
            cp[i - 1]->next=cp[i];
            hd = hd->next;
        }
        hd = pHead;
        for (int i = 0; i < n; i++){
            if (hd->random)
            	cp[i]->random = cp[mp[hd->random]];
            hd = hd->next;
        }	
        return cp[0];
    }
};