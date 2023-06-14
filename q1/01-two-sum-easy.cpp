#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ids;
		
		// Finding subsets of nums
		ull subset_amount = 1 << nums.size(); // 2^nums.lenght
		
		for(ull subset_i = 1; subset_i < subset_amount; subset_i++){
			
			unsigned int limit = (int)std::log2(subset_i) + 1;
			ids.resize(2);
			int out_array_index = 0;
			
			for(int j = 0; j < limit; j++){
				if((subset_i & (1 << j)) != 0){
					if (out_array_index < 2)
						ids[out_array_index++] = j;
					else
						break;
					//std::cout << nums[j] << " ";
				}
			}
			
			int sum = 0;
			if(out_array_index == 2){
				for(vector<int>::iterator it = ids.begin(); it != ids.end(); it++){
					sum += nums[*it];
				}
				if(sum == target){
					//cout << "The target found!\n";
					return ids;
				}
			}
			
			//std::cout << std::endl;
			ids.clear();
		}
		
		return vector<int>(-1);
    }
};

int main(){
	Solution sol;
	
	vector<int> numbers = {8, 1, 5, 6, 7, 2, 1};
	
	//vector<int> numbers = {8, 1, 5};
	sol.twoSum(numbers, 13);
	
	std::cin.get();
}