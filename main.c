#include <stdio.h>

#define MOD 12345

int count_sequences(int n) {
if (n == 1) return 2;
if (n == 2) return 4;
if (n == 3) return 7;

int a[n+1], b[n+1], c[n+1], f[n+1];

    // Початкові умови
a[1] = 1;
a[2] = 2;
a[3] = 4;

b[2] = 1;
b[3] = 2;

c[3] = 1;

f[1] = 2;
f[2] = 4;
f[3] = 7;

    // Обчислення для кожного значення від 4 до n
for (int i = 4; i <= n; ++i) {
    a[i] = f[i-1] % MOD;
    b[i] = a[i-1] % MOD;
    c[i] = b[i-1] % MOD;
    f[i] = (a[i] + b[i] + c[i]) % MOD;
    }

return f[n];
}

int main() {
int n;
printf("\nEnter lenth n (1 < n < 10000): ");
scanf("%d", &n);

if (n <= 1 || n >= 10000) {
    printf("\n n must be 1 < n < 10000.\n");
    return 1;
}

int result = count_sequences(n);
printf("\nKilkist poslidovnosteu z %d: %d\n", n, result);

return 0;
}
