// Approach
// We need to follow two statements. The first is: if the sum of the cost vector is greater than the sum of the gas vector, you will never be able to complete a full lap of the 
// circuit; in other words, you should return -1.

//The second statement is that every time the difference between gas and cost (gas - cost) becomes negative, you must set the starting point to the index immediately 
//after the current one.

// Complexity
// Time complexity: O(n)

//Space complexity: O(1)

impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let mut total = 0;
        let mut tank = 0;
        let mut start = 0;

        for i in 0..gas.len() {
            let diff = gas[i] - cost[i];
            total += diff;
            tank += diff;

            if tank < 0 {
                start = i + 1;
                tank = 0;
            }
        }

        if total >= 0 {
            start as i32
        } else {
            -1
        }
    }    
}