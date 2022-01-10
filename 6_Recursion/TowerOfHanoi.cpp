#include <iostream>
using namespace std;

void TOH(int n, int S, int D, int H)
{

    if (n == 0)
    {
        return;
    }

    TOH(n - 1, S, H, D);
    cout << n << "[" << S << "->" << D << "]" << endl;
    TOH(n - 1, H, D, S);
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    TOH(n, a, b, c);
}
