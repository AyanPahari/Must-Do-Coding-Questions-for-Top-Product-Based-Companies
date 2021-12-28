// C++ program to calculate maximum sum with equal
// stack sum.
#include <bits/stdc++.h>
using namespace std;

// Returns maximum possible equal sum of three stacks
// with removal of top elements allowed

//time:O(n1+n2+n3)
//we start removing from the stack that has the highest value of sum till either one of the stack becomes empty or sum is same in all the stacks.
//here we are simulating the stack as an array
int maxSum(int stack1[], int stack2[], int stack3[], int n1,
           int n2, int n3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n1; i++)
        sum1 += stack1[i];
    for (int i = 0; i < n2; i++)
        sum2 += stack2[i];
    for (int i = 0; i < n3; i++)
        sum3 += stack3[i];

    int i = 0, j = 0, k = 0;
    while (1)
    {
        if (sum1 == sum2 && sum2 == sum3)
            return sum1;
        if (i == n1 || j == n2 || k == n3) //pointer has reached till the end or stack is empty
            return 0;
        if (sum1 >= sum2 && sum1 >= sum3) //if sum1 is maximum then remove the top element of sum1
            sum1 -= stack1[i++];
        else if (sum2 >= sum1 && sum2 >= sum3)
            sum2 -= stack2[j++];
        else
            sum3 -= stack3[k++];
    }
    return 0;
}

// Driven Program
int main()
{
    int stack1[] = {3, 2, 1, 1, 1};
    int stack2[] = {3, 3, 2};
    int stack3[] = {1, 1, 4, 1};

    int n1 = sizeof(stack1) / sizeof(stack1[0]);
    int n2 = sizeof(stack2) / sizeof(stack2[0]);
    int n3 = sizeof(stack3) / sizeof(stack3[0]);

    cout << maxSum(stack1, stack2, stack3, n1, n2, n3)
         << endl;
    return 0;
}
