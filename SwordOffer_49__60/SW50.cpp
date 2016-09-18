class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length < 2) return false;
        int *a = new int[length];
        for (int i = 0; i < length; ++i) a[i] = 0;
        for (int i = 0; i < length; ++i){
            if (numbers[i]<0 || numbers[i]>length - 1)
                return false;
            else{
                a[numbers[i]]++;
                if (a[numbers[i]]>1){
                    *duplication = numbers[i];
                    return true;
                }
            }			
        }
        for (int i = 0; i < length; ++i) cout<<a[i]<<endl;
        return false;
    }
};