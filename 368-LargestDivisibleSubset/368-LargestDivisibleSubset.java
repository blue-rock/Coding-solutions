// Last updated: 11/2/2025, 10:32:07 PM
class Solution {

    public List<Integer> largestDivisibleSubset(int[] nums) {
        List<Integer> result = new ArrayList<>();
        Integer dp[] = new Integer[nums.length];

        Arrays.sort(nums);
        findSubSets(new ArrayList<>() ,result, -1, nums, 0, dp);
        return result;
    }

    public void findSubSets(List<Integer> curr, List<Integer> result, int prev, int[] nums, int i, Integer dp[]){
        if(i>=nums.length){
            if(curr.size() > result.size()){   
                result.clear();
                result.addAll(curr);
            }
            return;
        }

        if(dp[i]==null){
            dp[i] = -1;
        }
        
        
        
        if((prev ==-1 ||  nums[i]%prev==0) && curr.size()>dp[i]){
            dp[i] = curr.size();
            curr.add(nums[i]);
            findSubSets(curr, result, nums[i], nums, i+1, dp);
            curr.remove(curr.size()-1);
        }
        findSubSets(curr, result, prev, nums, i+1, dp);
    }
}