#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Node {
    char ele;
    Node *left;
    Node *right;
    Node *parent;
};

Node* build_tree() {
    auto a = new Node{'a'};
    auto b = new Node{'b'};
    auto c = new Node{'c'};
    auto d = new Node{'d'};
    auto e = new Node{'e'};
    auto f = new Node{'f'};
    auto g = new Node{'g'};
    auto h = new Node{'h'};
    auto i = new Node{'i'};
    auto j = new Node{'j'};
    auto k = new Node{'k'};
    auto l = new Node{'l'};
    auto m = new Node{'m'};
    auto n = new Node{'n'};
    auto o = new Node{'o'};
    auto p = new Node{'p'};
    auto q = new Node{'q'};
    a->parent = nullptr, a->left = b, a->right = c;
    b->parent = a, b->left = d, b->right = e;
    c->parent = a, c->left = f, c->right = g;
    d->parent = b, d->left = nullptr, d->right = nullptr;
    e->parent = b, e->left = nullptr, e->right = nullptr;
    f->parent = c, f->left = h, f->right = i;
    g->parent = c, g->left = j, g->right = k;
    h->parent = f, h->left = l, h->right = m;
    i->parent = f, i->left = nullptr, i->right = nullptr;
    j->parent = g, j->left = n, j->right = o;
    k->parent = g, k->left = nullptr, k->right = p;
    l->parent = h, l->left = nullptr, l->right = nullptr;
    m->parent = h, m->left = q, m->right = nullptr;
    n->parent = j, n->left = nullptr, n->right = nullptr;
    o->parent = j, o->left = nullptr, o->right = nullptr;
    p->parent = k, p->left = nullptr, p->right = nullptr;
    q->parent = m, q->left = nullptr, q->right = nullptr;
    return a;
}

pair<int, int> diameter(Node* root) {
    if (root == nullptr) return {0, 0};
    auto [left_diameter, left_height] = diameter(root->left);
    auto [right_diameter, right_height] = diameter(root->right);
    return {left_height + right_height, max(left_height, right_height) + 1};
}
    

int main() {
    auto root = build_tree();
    cout << diameter(root).first << endl;
}

