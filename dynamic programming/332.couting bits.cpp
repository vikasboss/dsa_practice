/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101


Constraints:

0 <= n <= 105


Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
Accepted
574,543
Submissions
773,245






KNOCKCAT

1. Easy C++
2. Using Stl Vectors Only.
3. Detailed Explanation ✅
4. Both O(nlogn) and O(n) Solution are Explained.
5. Please Upvote if it helps⬆️
6. Link to my Github Profile contains a repository of Leetcode with all my Solutions. ⬇️
	// 😉If you Like the repository don't foget to star & fork the repository😉
LeetCode (Link to Leetcode Repository)
EXPLANATION

 1. we are iterating till n;
	for every i, we have to count 1's bits in its binary form.
	0 --> 0
	1 --> 1
	2 --> 10
	3 --> 11
	4 --> 100
	5 --> 101

	Output: [0,1,1,2,1,2]

2.  Iterating till i becomes  zero and adding it remainder to sum on division by 2
	& reducing i by 2;

3.Add sum to the ans vector.
CODE (Onlogn)

				// 😉😉😉😉Please upvote if it helps 😉😉😉😉
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

		// iterating fromt 0 to n
        for(int i = 0; i<=n; i++)
        {
			// sum is initialised as 0
            int sum = 0;
            int num = i;
			// while num not equals zero
            while(num != 0)
            {
				// we have to count 1's in binary representation of i, therefore % 2
                sum += num%2;
                num = num/2;
            }
			// add sum to ans vector
            ans.push_back(sum);
        }
		// return
        return ans;
    }
};
In O(N) Time
Let if we have X and Y in Such a way that,
X/2 = Y
then Number of set bits in X - Number of set bit in Y <= 1

eg let X = 7and Y = 3
then 7 / 2 = 3;

7 -> 1 1 1 number of set bit are 3
3 -> 0 1 1 number of set bit are 2

there difference is 3 - 2 <= 1

another eg
X = 12 and y = 6
then 12 / 2 = 6;

12 -> 1100 number of set bit are 2
6 -> 0110 number of set bit are 2

there difference is 2 - 2 <= 1

There can be 2 cases
whether X is Odd or Even

if X is ODD

then the (LSB) Least Significant Bit will always be set and dividing by 2 means right shifting the number by 1 bit.
so if last bit is set and right shift it by 1 bit than the last set bit will be lost.
therfore the new number Y has 1 set bit less than in compare to X
But if X is Even

then LSB will be equal to 0, therefore even we do right shift by1 bit then only this 0 bit will be lost and no set bit got lost
so When we have X has Even,

no of set bit in X = no of set bit in Y
and When X is ODD

no of set bit in X = 1 + no of set bit in Y
CODE
*/
class Solution {
public:
    vector<int> countBits(int n) {

        // n+1 as we are going to count from 0 to n
        vector<int> t(n+1);

        // t[0] will be 0 beacuse 0 has count of set bit is 0;
        t[0] = 0;

        // we can compute current set bit count using previous count
        // as x/2 in O(1) time

        // i%2 will be 0 for even number ans 1 for odd number

        for(int i = 1; i<=n; ++i)
            t[i] = t[i/2] + i%2;

        return t;
    }
};
