int MoreThanHalfNum_Solution(vector<int> numbers) {
	unordered_map<int, int> um;
	for (int i = 0; i < numbers.size(); ++i){
		if (um.find(numbers[i]) == um.end())
			um[numbers[i]] = 1;
		else um[numbers[i]]++;
		if (um[numbers[i]]>numbers.size() >> 1)
			return numbers[i];
	}
	return 0;
}