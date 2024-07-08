#include <stdio.h>
#include <stdlib.h>

int minSteps(int x, int y) {
    int diff = y - x;
    if (diff < 0) {
        diff = -diff;
    }
    if (diff == 0) {
        return 0;
    }
    int dp[diff + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= diff; i++) {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0) {
            dp[i] = (dp[i] < dp[i / 2] + 1) ? dp[i] : dp[i / 2] + 1;
        }
    }

    return dp[diff];
}
int main() {
    int x, y;
    printf("Enter x and y (0 <= x <= y < 2^31): ");
    scanf("%d %d", &x, &y);
    if (x < 0 || y < x || y >= 2147483648) {
        printf("Invalid input. Please ensure 0 <= x <= y < 2^31.\n");
        return 1;
    }
    int min_steps = minSteps(x, y);
    printf("Minimum number of steps required: %d\n", min_steps);

    return 0;
}
















