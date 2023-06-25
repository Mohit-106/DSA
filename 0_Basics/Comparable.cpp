#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int vtx;
    string psf;
    int wt;
    Pair(int vtx, string psf, int wt)
    {
        this->vtx = vtx;
        this->psf = psf;
        this->wt = wt;
    }
};

class comp
{
    public:
    bool operator()(Pair * &a, Pair * &b)
    {
        return a->wt > b->wt;
    }
};

int main()
{

    priority_queue<Pair *, vector<Pair *>, comp> pq;
    pq.push(new Pair(0, "1", 4));
    pq.push(new Pair(0, "2", 4));
    pq.push(new Pair(0, "0", 7));
    pq.push(new Pair(0, "0", 15));
    
    while (!pq.empty())
    {
        Pair *top = pq.top();
        pq.pop();
        cout << top->vtx << " " << top->psf << " " << top->wt << endl;
    }

    vector<int>v={1,245,63,7,8};

    return 0;
}
