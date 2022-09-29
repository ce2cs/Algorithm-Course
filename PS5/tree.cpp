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

void dfs(Node* root) {
    if (root == nullptr) return;

    cout << root->ele << " ";

    if (root->left && root->right) {
        if (root->left->ele <= root->right->ele) {
            dfs(root->left);
            dfs(root->right);
        } else {
            dfs(root->right);
            dfs(root->left);
        }
    } else if (root->left) {
        dfs(root->left);
    } else if (root->right) {
        dfs(root->right);
    }
}

void bfs(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        auto curr = q.front();
        cout << curr->ele << " ";
        q.pop();
        if (curr->left && curr->right) {
            if (curr->left->ele <= curr->right->ele) {
                q.push(curr->left);
                q.push(curr->right);
            } else {
                q.push(curr->right);
                q.push(curr->left);
            }
        } else if (curr->left) {
            q.push(curr->left);
        } else if (curr->right) {
            q.push(curr->right);
        }
    }
}

int main() {
    auto root = build_tree();
    cout << "dfs: ";
    dfs(root);
    cout << endl << "bfs: ";
    bfs(root);
}

