class Solution {
public:
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    deque<int> dq;
    vector<int> out;
    if (num.size()<size||size==0)
        return out;
    int outn = num.size() - size + 1;
    dq.push_back(num[0]);
 
    for (int i = 1; i < size; i++)
    {
        while (!dq.empty()&&num[i] > dq.front())
        {
            dq.pop_front();
        }
        dq.push_front(num[i]);
    }
 
    for (int i = 0; i <outn-1; i++)
    {
        out.push_back(dq.back());
        if (dq.back() == num[i])
            dq.pop_back();
        while (!dq.empty() && num[i+size] > dq.front())
        {
            dq.pop_front();
        }
        dq.push_front(num[i+size]);
    }
    out.push_back(dq.back());
    return out;
}
 
};