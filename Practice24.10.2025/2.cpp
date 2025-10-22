#include<bits/stdc++.h>
using namespace std;

#define forn(i, l, r) for(int i = l; i < r; ++i)
#define all(a) (a).begin(), (a).end()
#define f first
#define s second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using db = double;
using vdb = vector<double>;
using vs = vector<string>;

/*
Чтобы сказать да нужно:
* Чтобы массив содержал хотя бы два элемента (иначе условие выполняется автоматически).
* Каждый элемент, начиная со второго, был строго больше предыдущего.
Если хотя бы одно из этих условий нарушено, ответ — нет. 
*/