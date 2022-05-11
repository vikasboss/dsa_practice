/*
1025. Divisor Game
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < n and n % x == 0.
Replacing the number n on the chalkboard with n - x.
Also, if a player cannot make a move, they lose the game.

Return true if and only if Alice wins the game, assuming both players play optimally.



Example 1:

Input: n = 2
Output: true
Explanation: Alice chooses 1, and Bob has no more moves.
Example 2:

Input: n = 3
Output: false
Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.


Constraints:

1 <= n <= 1000








*/
class Solution {
public:
    bool divisorGame(int n) {
        if(n==1)
            return false;                   //If n=1, there exists no x i.e. game lost
        vector<int> dp(n+1, 0);             //dp of size n+1 initialized with 0. For each index j, dp[j] tells if Alice won or not

        for(int j=2; j<=n; j++)             //j = each no that comes within n
            for(int i=1; i<=sqrt(j); i++)   //factors of j lie between 1 and sqrt(j)
                if(j%i==0 && dp[j-i]==0)    //if i is a factor of j, then Bob gets j-i,so we choose this i only if Bob loses at j-i so that Alice wins.
                    dp[j]=1;                //Alice wins

        if(dp[n] == 1)                      //if finally, by atleast one path, Alice wins then dp[n] would be = 1
            return true;                    //hence Alice won
        return false;                       //Else, Alice lost
    }
};
