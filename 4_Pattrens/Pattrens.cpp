// step1:- count no of spaces and star in first row for multiple test cases and then assign a general values for nsp and nst.
// Step2:- identify the relation between 1st and 2nd row and write code accordingly.
// step3:- Now increment and decrement the value of nsp and nst and print star and spaces.


#include <bits/stdc++.h>
using namespace std;
#define ll long long

void pattren1234(int n)
{

    int nsp = n - 1;
    int nst = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int cst = 1; cst <= nst; cst++)
        {
            cout << "*\t";
        }
        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << "\t";
        }

        nsp--;
        nst++;
        cout << endl;
    }
}


void pattren5(int n)
{

    int nst = 1;
    int nsp = n / 2;

    for (int i = 1; i <= n; i++)
    {
        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << "\t";
        }

        for (int cst = 1; cst <= nst; cst++)
        {
            cout << "*\t";
        }

        if (i <= n / 2)
        {
            nsp--;
            nst += 2;
        }
        else
        {
            nsp++;
            nst -= 2;
        }
        cout << endl;
    }
}


void pattren6(int n)
{
    int nst = (n / 2 + 1);
    int nsp = 1;
    for (int r = 1; r <= n; r++)
    {
        for (int cst = 1; cst <= nst; cst++)
        {
            cout << "*\t";
        }
        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << "\t";
        }
        for (int cst = 1; cst <= nst; cst++)
        {
            cout << "*\t";
        }

        if (r <= n / 2)
        {
            nst--;
            nsp += 2;
        }
        else
        {
            nst++;
            nsp -= 2;
        }
        cout << endl;
    }
}


//Alternative
//can be done by gap star strategy
void pattren7(int row)
{

    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= row; c++)
        {
            if (r == c)
            {
                cout << "*\t";
            }
            else
                cout << "\t";
        }
        cout << endl;
    }
}


void pattren8(int n)
{

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            if (r + c == n + 1)
            {
                cout << "*\t";
            }
            else
                cout << "\t";
        }
        cout << endl;
    }
}


void pattren9(int n)
{

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            if (r + c == n + 1 || r == c)
            {
                cout << "*\t";
            }
            else
                cout << "\t";
        }
        cout << endl;
    }
}


//alternative approach

void pattren9a(int n)
{

    int nsp = 0;
    int nst = n;
    for (int r = 1; r <= n; r++)
    {

        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << "\t";
        }

        for (int cst = 1; cst <= nst; cst++)
        {
            if (cst == 1 || cst == nst || r == (n / 2 + 1))
            {
                cout << "*\t";
            }
            else
            {
                cout << "\t";
            }
        }

        if (r <= n / 2)
        {
            nsp++;
            nst -= 2;
        }
        else
        {
            nsp--;
            nst += 2;
        }

        cout << endl;
    }
}


void pattren10(int n)
{

    int nsp = n / 2;
    int nst = 1;
    for (int r = 1; r <= n; r++)
    {
        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << "\t";
        }
        for (int cst = 1; cst <= nst; cst++)
        {
            if (cst == 1 || cst == nst)
            {
                cout << "*\t";
            }
            else
            {

                cout << "\t";
            }
        }

        if (r <= n / 2)
        {
            nsp--;
            nst += 2;
        }
        else
        {
            nsp++;
            nst -= 2;
        }

        cout << endl;
    }
}


void pattren12(int n)
{
    int nst = 1, val1 = 0, val2 = 1, val3 = 0;

    for (int r = 1; r <= n; r++)
    {

        for (int cst = 1; cst <= nst; cst++)
        {

            cout << val1 << "\t";
            val3 = val1 + val2;
            val1 = val2;
            val2 = val3;
        }

        nst++;
        cout << endl;
    }
}


void pattren13(int row)
{

    for (int n = 0; n <= row; n++)
    {
        int val = 1;
        for (int r = 0; r <= n; r++)
        {
            cout << val << "\t";
            val = ((n - r) * val) / (r + 1);
        }
        cout << endl;
    }
}


void pattren10a(int n)
{
    int nsp = n / 2, nst = 1;
    int val = 0;
    for (int r = 1; r <= n; r++)
    {
        int val = (r <= n / 2 + 1 ? r : n - r + 1);
        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << "\t";
        }

        for (int cst = 1; cst <= nst; cst++)
        {
            cout << val << "\t";
        }

        if (r <= n / 2)
        {
            nsp--;
            nst += 2;
        }
        else
        {
            nsp++;
            nst -= 2;
        }
        cout << endl;
    }
}

//             1
//         2   2   2
//    3    3   3   3   3
// 4  4    4   4   4   4   4
//    3    3   3   3   3
//         2   2   2
//             1

void pattren15(int n)
{
    int nsp = n / 2, nst = 1;
    int val = 0;
    for (int r = 1; r <= n; r++)
    {

        int val = (r <= n / 2 + 1 ? r : n - r + 1);

        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << "\t";
        }

        for (int cst = 1; cst <= nst; cst++)
        {
            if (cst <= nst / 2)
            {
                cout << val << "\t";
                val++;
            }
            else
            {
                cout << val << "\t";
                val--;
            }
            //int val = (r <= n / 2 + 1 ? val++ : val--);
        }

        if (r <= n / 2)
        {
            nsp--;
            nst += 2;
        }
        else
        {
            nsp++;
            nst -= 2;
        }
        cout << endl;
    }
}
//             1
//         2   3   2
//    3    4   5   4   3
// 4  5    6   7   6   5   4
//    3    4   5   4   3
//         2   3   2
//             1

void pattren15b(int n)
{
    int nsp = n / 2, nst = 1;
    int val = 0;
    for (int r = 1; r <= n; r++)
    {

        int val = (r <= n / 2 + 1 ? r : n - r + 1); //this will decide our start digit of row

        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << "\t";
        }

        for (int cst = 1; cst <= nst; cst++) // this loop will decide our no in a perticular row
        {
            if (cst <= nst / 2)
            {
                cout << val << "\t";
                val--;
            }
            else
            {
                cout << val << "\t";
                val++;
            }
        }

        if (r <= n / 2)
        {
            nsp--;
            nst += 2;
        }
        else
        {
            nsp++;
            nst -= 2;
        }
        cout << endl;
    }
}
//             1
//         2   1   2
//    3    2   1   2   3
// 4  3    2   1   2   3   4
//    3    2   1   2   3
//         2   1   2
//             1

void pattren16a(int n)
{
    int nsp = (2 * n - 3), nst = 1;

    for (int r = 1; r <= n; r++)
    {

        for (int cst = 1; cst <= nst; cst++)
        {
            cout << "*\t";
        }
        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << "\t";
        }

        if (r == n)
        {
            nst--;
        }

        for (int cst = 1; cst <= nst; cst++)
        {
            cout << "*\t";
        }

        nst++;
        nsp -= 2;

        cout << endl;
    }
}
// *                                                                                               *
// *       *                                                                               *       *
// *       *       *                                                               *       *       *
// *       *       *       *                                               *       *       *       *
// *       *       *       *       *                               *       *       *       *       *
// *       *       *       *       *       *               *       *       *       *       *       *
// *       *       *       *       *       *       *       *       *       *       *       *       *
void pattren16(int n)
{

    int nsp = (2 * n - 3), nst = 1, val = 1;

    for (int r = 1; r <= n; r++)
    {

        for (int cst = 1; cst <= nst; cst++)
        {
            cout << val << "\t";
            if (r != 1)
            {
                if (cst < nst)
                {
                    val++;
                }
            }
        }
        for (int csp = 1; csp <= nsp; csp++)
        {
            cout << "\t";
        }

        if (r == n)
        {
            nst--;
            val--;
        }

        for (int cst = 1; cst <= nst; cst++)
        {
            cout << val << "\t";
            if (r != 1)
            {
                if (cst < nst)
                {
                    val--;
                }
            }
        }

        nst++;
        nsp -= 2;

        cout << endl;
    }
}
// 4
// 1                                               1
// 1       2                               2       1
// 1       2       3               3       2       1
// 1       2       3       4       3       2       1

void pattren17(int n)
{

    int nst = (n / 2 + 1), nsp = 0;
    for (int r = 1; r <= n; r++)
    {

        for (int cst = 1; cst <= nst; cst++)
        {
            if (cst > n / 2 || r == n / 2 + 1)
            {
                cout << "*\t";
            }
            else
            {
                cout << "\t";
            }
        }

        if (r <= n / 2)
        {
            nst++;
        }
        else
        {
            nst--;
        }
        cout << endl;
    }
}

// 7
//                         *
//                         *       *
//                         *       *       *
// *       *       *       *       *       *       *
//                         *       *       *
//                         *       *
//                         *

void pattrenSwastik(int n)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i==1){
                if(j<=n/2+1){
                    cout<<"*\t";
                }

            }else if(i>1 && i<n/2+1){

            }else if(i==n/2+1){

            }else if(i>n/2+1 && i<n){
                
            }else if(i==n){

            }else{
                cout<<"\t";
            }

        }
        cout<<endl;
    }
}

void pattrenM(int n)
{

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {

            if (j == 1 || j == n || (i == j && i <= n / 2 + 1) || (i + j == n + 1 && i <= n / 2 + 1))
            {
                cout << "*\t";
            }
            else
            {

                cout << "\t";
            }
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cin >> n;
    pattren7(n);

    return 0;
}
