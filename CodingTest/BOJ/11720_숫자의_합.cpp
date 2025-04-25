#include <iostream>

using namespace std;
typedef long long ll;
double a = 1.234556778899;
int b = 12;
int c = 2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();

    printf("%.6lf\n", a);
    printf("%02d\n", b);
    printf("%02d\n", c);
    return 0;
}