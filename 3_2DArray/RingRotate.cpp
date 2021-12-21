#include <bits/stdc++.h>
using namespace std;

void Display(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> Mattoarray(vector<vector<int>> &mat, int sr, int sc, int er, int ec)
{
    int sz = 2 * (er - sr + 1) + 2 * (ec - sc + 1) - 4;
    vector<int> v(sz);
    int count = 0;

    for (int i = sr; i <= er; i++)
    {

        v[count] = mat[i][sc];
        count++;
    }
    sc++;
    for (int j = sc; j <= ec; j++)
    {
        v[count] == mat[er][j];
        count++;
    }
    er--;

    for (int k = er; k >= sr; k--)
    {
        v[count] = mat[k][ec];
        count++;
    }
    ec--;
    for (int l = ec; l >= sc; l--)
    {
        v[count] = mat[sr][l];
    }

    return v;
}

int swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Reverse(vector<int> &arr, int i, int j)
{

    while (i <= j)
    {
        swap(arr, i, j);
        i++, j--;
    }
}

void Rotate(vector<int> &arr, int k)
{
    int n = arr.size();
    k = k % n;
    if (k < 0)
    {
        k += n;
    }

    int i = 0, j = n - k - 1, l = n - k, m = n - 1;

    Reverse(arr, i, j);
    Reverse(arr, l, m);
    Reverse(arr, 0, n - 1);
}

void ArraytoMat(vector<vector<int>> &mat, vector<int> &v, int sr, int sc, int er, int ec)
{

    int sz = v.size();
    int count = 0;

    for (int i = sr; i <= er && count <= sz; i++)
    {

        mat[i][sc] = v[count];
        count++;
    }
    sc++;
    for (int j = sc; j <= ec && count <= sz; j++)
    {
        mat[er][j] = v[count];
        count++;
    }
    er--;

    for (int k = er; k >= sr && count <= sz; k--)
    {
        mat[k][ec] = v[count];
        count++;
    }
    ec--;
    for (int l = ec; l >= sc && count <= sz; l--)
    {
        mat[sr][l] = v[count];
    }
}

void RingRotate(vector<vector<int>> &mat, int s, int r)
{
    int n = mat.size()-1;
    int m = mat[0].size()-1;

    int sr = s - 1, sc = s - 1, er = n - s, ec = m - s;

    vector<int> v = Mattoarray(mat, sr, sc, er, ec);
    for (int val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    Rotate(v, r);
    for (int val : v)
    {
        cout << val << " ";
    }
    // ArraytoMat(mat,v,sr,sc,er,ec);
    // Display(mat);
}

int main()
{

    int n, m, s, r;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cin >> s >> r;
    RingRotate(mat, s, r);
    return 0;
}