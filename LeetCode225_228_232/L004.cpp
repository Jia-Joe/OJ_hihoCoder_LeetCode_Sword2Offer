class Solution {
public:
double find(vector<int>& v1, vector<int>& v2, int p1, int q1, int p2, int q2){
	//for (int i = p1; i <= q1; i++)
	//	cout << v1[i] << " ";
	//cout << endl;
	//for (int i = p2; i <= q2; i++)
	//	cout << v2[i] << " ";
	//cout << endl;
	if (p1 == q1&&p2 == q2) return (v1[p1] + v2[p2])/2.0;
	int n1 = q1 - p1 + 1, n2 = q2 - p2 + 1;
	int m1 = p1 + ((q1 - p1) >> 1), m2 = p2 + ((q2 - p2) >> 1);
	if (p1 == q1){
		if (n2 % 2 == 0){
			if (v1[p1] <= v2[m2]) return v2[m2];
			else return v1[p1] < v2[m2 + 1] ? v1[p1] : v2[m2 + 1];
		}
		else{
			if (v1[p1] < v2[m2 - 1]) return (v2[m2 - 1] + v2[m2]) / 2.0;
			if (v1[p1] > v2[m2 + 1]) return (v2[m2 + 1] + v2[m2]) / 2.0;
			return (v1[p1] + v2[m2]) / 2.0;
		}
	}
	if (p2 == q2){
		if (n1 % 2 == 0){
			if (v2[p2] <= v1[m1]) return v1[m1];
			else return v2[p2] < v1[m1 + 1] ? v2[p2] : v1[m1 + 1];
		}
		else{
			if (v2[p2] < v1[m1 - 1]) return (v1[m1 - 1] + v1[m1]) / 2.0;
			if (v2[p2] > v1[m1 + 1]) return (v1[m1 + 1] + v1[m1]) / 2.0;
			return (v2[p2] + v1[m1]) / 2.0;
		}
	}

	
	if (v1[m1] < v2[m2]){
		if (n1 == 2){
			int vyt = v1[q1];
			if (n2 % 2 == 0){				
				if (n2 == 2) return vyt>v2[q2] ? (v2[p2] + v2[q2]) / 2.0 : (vyt + v2[p2]) / 2.0;
				if (vyt < v2[m2 - 1]) return (v2[m2 - 1] + v2[m2]) / 2.0;
				if (vyt>v2[m2 + 1]) return (v2[m2 + 1] + v2[m2]) / 2.0;
				return (v2[m2] + vyt) / 2.0;
			}
			else{
				if (vyt < v2[m2 - 1]) return v2[m2 - 1];
				if (vyt>v2[m2]) return v2[m2];
				return vyt;
			}
		}
		if (n2%2 == 0 && n1 % 2 == 0 && v2[m2+1] < v1[m1 + 1]) return (v2[m2]+v2[m2+1]) / 2.0;
		//v1 first-half v2 last-half delete
		int d1 = n1 % 2 == 0 ? n1 / 2 - 1 : n1 / 2, d2 = n2 / 2, md=min(d1,d2);
		//int t1 = min(m1 + 1, int(v1.size()-1)), t2 = max(m2 - 1, 0);
		return find(v1, v2, p1+md, q1, p2, q2-md);
	}
		
	else if (v1[m1]>v2[m2]){
		if (n2 == 2){
			int vyt = v2[q2];
			if (n1 % 2 == 0){
				if (n1 == 2) return vyt>v1[q1] ? (v1[p1] + v1[q1]) / 2.0 : (vyt + v1[p1]) / 2.0;
				if (vyt < v1[m1 - 1]) return (v1[m1 - 1] + v1[m1]) / 2.0;
				if (vyt>v1[m1 + 1]) return (v1[m1 + 1] + v1[m1]) / 2.0;
				return (v1[m1] + vyt) / 2.0;
			}
			else{
				if (vyt < v1[m1 - 1]) return v1[m1 - 1];
				if (vyt>v1[m1]) return v1[m1];
				return vyt;
			}
		}
		if (n1%2==0 && n2 % 2 == 0 && v1[m1+1] < v2[m2 + 1]) return (v1[m1] + v1[m1+1]) / 2.0;

		int d2 = n2 % 2 == 0 ? n2 / 2 - 1 : n2 / 2, d1 = n1 / 2, md = min(d1, d2);
		//int t1 = max(m1 - 1, 0), t2 = (m2 + 1, int(v2.size() - 1));
		return find(v1, v2, p1, q1-md, p2+md, q2);
	}
		
	else{
		if (n1 % 2 == 0 && n2 % 2 == 0){
			return (min(v1[m1 + 1], v2[m2 + 1]) + v1[m1]) / 2.0;
		}
		else{
			return v1[m1];
		}
	}

		
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int n1 = nums1.size(), n2 = nums2.size();
    	if (n1 == 0) 
    		if (n2 % 2 == 0) return (nums2[n2 / 2] + nums2[n2 / 2 - 1]) / 2.0;
    		else return nums2[n2 / 2];
    	if (n2 == 0)
    		if (n1 % 2 == 0) return (nums1[n1 / 2] + nums1[n1 / 2 - 1]) / 2.0;
    		else return nums1[n1 / 2];
    		return find(nums1, nums2, 0, n1 - 1, 0, n2 - 1);
    
    }
};