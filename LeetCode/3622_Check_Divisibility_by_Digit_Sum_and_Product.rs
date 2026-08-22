impl Solution {
    pub fn check_divisibility(n: i32) -> bool {
        let mut sum = 0;
        let mut mul = 1;
        let mut num: i32 = n;
        while num > 0 {
            let m = num % 10;
            num /= 10;
            sum += m;
            mul *= m;
        }
        return n % (sum + mul) == 0;
    }
}
