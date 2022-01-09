#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    // double x = log(6) / log(2);
    // if (x == (int)x)
    //     cout << "x is an integer";
    // else
    //     cout << "x is not an integer";
    double x = log(n) / log(2);
    double c = x;
    if (x != (int)x)
        cout << 0 << endl;
    cout << x << endl;
    cout << (int)x << endl;
    cout << c << endl;
    return 0;
}

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// class Solution
// {
// public:
//     ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
//     {
//         // ListNode *p = list1;
//         // ListNode *q = NULL;
//         // ListNode *r = NULL;

//         // for (int i = 0; i <= b + 1; i++)
//         // {
//         //     if (i == a - 1)
//         //         q = p;
//         //     if (i == b + 1)
//         //         r = p;
//         //     p = p->next;
//         // }
//         // ListNode *s = NULL;

//         // p = list2;
//         // while (p)
//         // {
//         //     if (p->next == NULL)
//         //         s = p;
//         //     p = p->next;
//         // }
//         // q->next = list2;
//         // s->next = r;
//         // return list1;

//         ListNode *p = list1;
//         ListNode *h = list1;
//         ListNode *l = list1;
//         ListNode *r = list2;
//         int i = 0;

//         while (p != nullptr)
//         {
//             if (i == a - 1)
//                 h = p;
//             if (i == b)
//             {
//                 l = p->next;
//             }
//             i++;
//             p = p->next;
//         }
//         h->next = list2;
//         p = list2;
//         while (h != nullptr)
//         {
//             h = h->next;
//         }
//         h->next = l;

//         return list1;
//     }
// };
