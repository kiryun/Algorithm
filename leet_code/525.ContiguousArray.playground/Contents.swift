// https://leetcode.com/problems/contiguous-array/

class Solution {

    func findMaxLength(_ nums: [Int]) -> Int {
        var dict = [Int: Int]()
        dict[0] = -1
        var maxL = 0
        var cnt = 0
        for i in 0 ..< nums.count{
            cnt = cnt + (nums[i] == 1 ? 1 : -1)
            if let contain = dict[cnt]{
                maxL = max(maxL, i - contain)
            }else{
                dict[cnt] = i
            }
        }
         
        return maxL
    }
}


let sol = Solution()
let input: [Int] = [1,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,0,1,0,1,0,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,0]//[0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0]//[0,1,0]
print(sol.findMaxLength(input))



