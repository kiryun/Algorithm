# LeetCode_11_ContainerWithMostWater

## Problem

> https://leetcode.com/problems/container-with-most-water/

Given `n` non-negative integers `a1, a2, ..., an` , where each represents a point at coordinate `(i, ai)`. `n` vertical lines are drawn such that the two endpoints of the line `i` is at `(i, ai)` and `(i, 0)`. Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

**Notice** that you may not slant the container.

**Example 1:**

![img](LC_11_ContainerWithMostWater.assets/question_11.jpg)

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```

**Example 2:**

```
Input: height = [1,1]
Output: 1
```

**Example 3:**

```
Input: height = [4,3,2,1,4]
Output: 16
```

**Example 4:**

```
Input: height = [1,2,1]
Output: 2
```

 

**Constraints:**

- `n == height.length`
- `2 <= n <= 3 * 10^4`
- `0 <= height[i] <= 3 * 10^4`



## Solution

### 문제 해석

* Input배열에는 height의 값이 들어있다.
* index 사이를 가로, input배열의 값을 세로로 할 때 가장 넓은 직사각형의 넓이를 구하는 문제
* Constraints에 n의 값과 input 배열의 길이와 같다고 했다. index가 0부터 시작이 아니라는 얘기



### 방법1

brute force를 이용해 각 index 기준으로 나올 수 있는 넓이를 모두 구한 후 가장 큰 값을 리턴한다.

예를 들면 input이 `[1,8,6,2,5,4,8,3,7]` 이라 가정했을 때

index = 0을 기준으로 가장 넓게 나올 수 있는 넓이는 1 * (8 - 0) = 8이다. 

`min(input[0], input[8]) * (index 8 - index 0)`

index = 1을 기준으로 가장 넓게 나올 수 있는 넓이는 7 * (8 - 1) = 49이다.

`min(input[1], input[8]) * (index 8 - index 1)`

```swift
class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var maxS: Int = 0
        
        for i in 0 ..< height.count{
            for j in i+1 ..< height.count{
                maxS = max(maxS, min(height[i], height[j]) * (j - i))
            }
        }
        
        return maxS
    }
}

let solution = Solution()
let input: [Int] = [1,8,6,2,5,4,8,3,7]
print(solution.maxArea(input))
```



### 방법 2

순차적으로 순회하는 것보다는 index가 left와 right로 나뉘어서 height 값을 비교해 넓이를 계산할 수 있다.

* left는 배열의 시작 지점에서 부터 시작한다.
* right는 배열의 끝 부분에서 차례로 감소한다.
* left의 height보다 right의 height이 더 높다면 left를 증가한다.
* 반대로 right의 height보다 left의 height이 더 높다면 right를 감소해준다.
* left와 right값이 만나는 지점 까지 계속 반복한다.

```swift
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
```



