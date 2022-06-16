#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort012(vector<int> &arr)
{
    int i = 0;
    int j = 0;
    int k = arr.size() - 1;
    while (i <= k)
    {
        if (arr[i] == 0)
        {
            swap(arr, i, j);
            i++;
            j++;
        }
        else if (arr[i] == 1)
        {
            i++;
        }
        else
        {
            swap(arr, i, k);
            k--;
        }
    }
}

void sort012_Alternative(vector<int> &arr)
{
    int i = 0;
    int j = 0;
    int k = arr.size() - 1;
    while (i <= k)
    {

        if (arr[i] == 0)
        {

            int check = arr[j];
            swap(arr, i, j);
            j++;
            if (check == 1 || check == 0)
            {        // i need to confirm from j brfore ++/--
                i++; // arr[j] will give value zero only when
                     //arr[i]==arr[j]==0 && i and j on same index
            }
        }
        else if (arr[i] == 2)
        {
            int check = arr[k];
            swap(arr, i, k);
            k--;
            if (check == 1)
            {
                i++;
            }
        }
        else
        {

            i++;
        }
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    sort012_Alternative(A);
    print(A);
    return 0;
}