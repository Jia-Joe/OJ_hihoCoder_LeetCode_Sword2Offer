class Solution {
public:
    void reOrderArray(vector<int> &array) {
        list <int> nd;
        bool fi = true;
        list<int>::iterator it=nd.begin();
        int sz = array.size();
        for (int i = 0; i < sz; i++){
            if (array[i] % 2 == 0){
                nd.push_back(array[i]);
            }
            else{
                if (fi){
                    fi = false;
                    it = nd.insert(nd.begin(), array[i]);
                }
                else it=nd.insert(++it, array[i]);
            }
        }
        it = nd.begin();
        for (int i = 0; i < sz; i++){
            array[i] = *it;
            ++it;
            cout << array[i];
        }
    }
};