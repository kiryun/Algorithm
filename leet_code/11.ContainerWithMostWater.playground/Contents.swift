class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var maxS: Int = 0
        var left: Int = 0
        var right: Int = height.count - 1
        while left < right{
            maxS = max(maxS, min(height[left], height[right]) * (right - left))
            if height[left] < height[right]{
                left += 1
            }else{
                right -= 1
            }
        }
        
        return maxS
    }
}

let solution = Solution()
let input: [Int] = [1,8,6,2,5,4,8,3,7]
print(solution.maxArea(input))


