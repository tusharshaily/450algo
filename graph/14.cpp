#include <bits/stdc++.h>

/*

note -> when adjency matrixs is there the use primns 

if edge list is there then use kurskal 
*/

// we are going to use kurskal

using namespace std;

bool comp(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
    return a.first < b.first;
}

// this function is used for getting the leader and compressing the graph

// this is the core of the algo

int findit(int i, vector<int> &phi)
{
    if (phi[i] == i)
        return i;

    else
        return phi[i] = findit(phi[i], phi);
}

pair<int, int> disjoint(int i, int j, vector<int> &phi)
{
    return {findit(i, phi), findit(j, phi)};
}

void unionit(int i, int j, vector<int> &phi, vector<int> &s)
{
    if (s[i] >= s[j])
    {
        phi[j] = i;
        s[i] += s[j];
        s[j] = 0;
    }
    else
    {
        phi[i] = j;
        s[j] += s[i];
        s[i] = 0;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, e;
    cin >> n >> e;

    vector<pair<int, pair<int, int>>> ed(e);
    vector<pair<int, pair<int, int>>> ans;

    int a, b, c;

    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        ed[i] = {a, {b, c}};
    }

    sort(ed.begin(), ed.end(), comp);

    // setting the parent  of node of very node as its parent

    vector<int> phi(n);

    for (int i = 0; i < n; i++)
    {
        phi[i] = i;
    }

    // setting the size of each set as one ;
    vector<int> s(n, 1);

    pair<int, int> k;

    for (auto x : ed)
    {
        k = disjoint(x.second.first, x.second.second, phi);

        if (k.first != k.second)
        {
            ans.push_back(x);

            unionit(k.first, k.second, phi, s);
        }
    }

    int result = 0;

    for (auto x : ans)
    {
        cout << x.first << ' ' << x.second.first << " " << x.second.second << "\n";
    }
    for (auto x : ans)
    {
        result += x.first;
    }

    cout << result << " ";

    return 0;
}