/*

Choco, a chocolate lover, has N amount of money with him. He wants to buy as much chocolate as possible. So, he goes to a chocolate shop “Bandyman ”. Mike, the owner of “Bandyman ” has different types of chocolate in his store (represented by a character) placed in a row.

Mike, give an offer to Choco that he can buy a selected type of chocolate for free and need to pay for the other types of chocolates and Choco can only buy consecutive chocolates.

Now, you need to write a code to find the maximum amount of chocolates Choco can get by selecting the chocolates optimally.

Input format :

1st line contains 2 space separated integers A and B denoting the number of chocolates and the amount of money Choco has.

The 2nd line contains A chocolates represented by a string. All chocolates represented by lowercase alphabets.

The 3rd line represents 26 space separated integers representing the cost to buy the chocolates.
[First integer represents the cost of the chocolate of type ‘a’, 2nd integer represents the cost of the chocolates of type ‘b’ and so on]

Output format :
Print the maximum number of chocolates Choco can buy.

Constraints :
1<=A<=10^5
1<=B<=10^9
1<=cost of chocolate<=10^9

Sample input 1 :
6 10
aabcda
5 4 4 5 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

Sample output 1 :
4

Explanation :

Choco can select the chocolate of type ‘a’ for free and start buying from index 0 and if he buys “aabc” then he has to pay less (0+0+4+4=8) than the total money he has.

This is the maximum number of chocolates he can get in this case.

*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    string chocolates;
    cin >> chocolates;
    vector<int> cost(26);
    for (int i = 0; i < 26; i++) {
        cin >> cost[i];
    }

    int maxChocolates = 0;

    for (char freeChocolate = 'a'; freeChocolate <= 'z'; freeChocolate++) {
        int currentCost = 0;
        int left = 0;

        for (int right = 0; right < A; right++) {
            if (chocolates[right] != freeChocolate) {
                currentCost += cost[chocolates[right] - 'a'];
            }

            while (currentCost > B) {
                if (chocolates[left] != freeChocolate) {
                    currentCost -= cost[chocolates[left] - 'a'];
                }
                left++;
            }

            maxChocolates = max(maxChocolates, right - left + 1);
        }
    }

    cout << maxChocolates << endl;

    return 0;
}