# LeetCode_12_IntegerToRoman

## Problem

> https://leetcode.com/problems/integer-to-roman/

Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D`and `M`.

```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, `2` is written as `II` in Roman numeral, just two one's added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

- `I` can be placed before `V` (5) and `X` (10) to make 4 and 9. 
- `X` can be placed before `L` (50) and `C` (100) to make 40 and 90. 
- `C` can be placed before `D` (500) and `M` (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral.

 

**Example 1:**

```
Input: num = 3
Output: "III"
```

**Example 2:**

```
Input: num = 4
Output: "IV"
```

**Example 3:**

```
Input: num = 9
Output: "IX"
```

**Example 4:**

```
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
```

**Example 5:**

```
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

 

**Constraints:**

- `1 <= num <= 3999`



## Solution

### 문제 해석

* 아라비아 숫자에서 로마 숫자로 변형하는 문제

* `I` 는 `V` 나 `X` 앞에 오게 된다면 4 과 9를 만들 수 있다.

* `X` 는 `L` 나 `C` 앞에 오게 된다면 40 과 90을 만들 수 있다.

* `C` 는 `D` 나 `M` 앞에 오게 된다면 400 과 900을 만들 수 있다.

* 각각 변환 표는 아래와 같다.

  ```
  Symbol       Value
  I             1
  V             5
  X             10
  L             50
  C             100
  D             500
  M             1000
  ```

* 단, input되는 값인  `num`  의 범위: `1 <= num <= 3999`

### 방법 1

각각 자리수를 나눠서(단 1000의 자리를 넘어가면 안됨) 몫을 구한 뒤 각 자리 수에서 심볼을 정하는게 우선일 듯 하다.

각 자리수의 숫자마다 table을 만들어서 [key: value]를 이용해 값을 가져오는 방식으로 한다.

어차피 주어진 범위가 `1 <= num <= 3999` 뿐이라 대입으로 하면 쉽다.

* 주어진 값 num을 배열로 변경한다. ex) 1994  -> `arr` = [1, 9, 9, 4]
* 각 자리수가 의미하는 수를 `table` 에서 찾는다. `arr[0]` 의 경우 1000을 의미하므로 "M"을 찾는다.
* result에 값을 넣어서 return 한다.

```swift
class Solution {
    let table: [Int: String] = [
        0: "",
        1: "I",
        2: "II",
        3: "III",
        4: "IV",
        5: "V",
        6: "VI",
        7: "VII",
        8: "VIII",
        9: "IX",
        10: "X",
        20: "XX",
        30: "XXX",
        40: "XL",
        50: "L",
        60: "LX",
        70: "LXX",
        80: "LXXX",
        90: "XC",
        100: "C",
        200: "CC",
        300: "CCC",
        400: "CD",
        500: "D",
        600: "DC",
        700: "DCC",
        800: "DCCC",
        900: "CM",
        1000: "M",
        2000: "MM",
        3000: "MMM"
    ]
    
    private func digitCount(_ num: Int) -> Int{
        var n = num
        var cnt = 0
        while n >= 10{
            n = n / 10
            cnt += 1
        }
        
        return cnt
    }
    
    private func digits(_ num: Int) -> [Int]{
        var digits: [Int] = []
        var n = num
        digits.append(n % 10)
        while n >= 10 {
            n = n / 10
            digits.append(n % 10)
        }
        return digits.reversed()
    }
    
    private func pow(_ base: Int, _ exponent: Int) -> Int{
        var result = 1
        
        for _ in 0 ..< exponent{
            result = result * base
        }
        
        return result
    }
    
    func intToRoman(_ num: Int) -> String {
        var result: String = ""
        
        let arr = digits(num)
        for i in 0 ..< arr.count{
            let k = arr[i] * pow(10, arr.count-i-1)
            result += table[k]!
        }
        
        return result
    }
}

let solution = Solution()
print(solution.intToRoman(10))
```





