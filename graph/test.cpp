#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;

    int a;

    Node *ans = NULL;

    Node *p;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cout << a << "<-";
        if (ans == NULL)
        {
            ans = new Node(a);
            p = ans;
        }
        else
        {
            p->next = new Node(a);
            p = p->next;
        }
    }

    int count = 0;

    p = ans;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }

    // Node *q = p->next;

    // cout << q->data << " " << p->next->data << " ";
    // q = nullptr;

    // p = ans;
    // while (p != NULL)
    // {
    //     cout << p->data << " ";
    //     p = p->next;
    // }

    // cout << q->data << " " << p->next->data << " ";
    // stack
    return 0;
}

/*
<div id =1 >
<row>
<elem col = >
<row>
<div>


<div id = 4 >
<row>
<elem col = >
<row>
<div>

ele rw 1 col x

ele rw 1 col y

ele rw 4 col y

ele rw 1 col z

1> ----  [  x   ]    [   y  ]                                           ---------
1> ----  [  x   ]    [   y]                                           ---------
1> ----  [  x   ]    [   y]                                           ---------
4> ----  [  x   ]    [   y]                                           ---------



*/