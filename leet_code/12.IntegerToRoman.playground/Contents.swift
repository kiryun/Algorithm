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

