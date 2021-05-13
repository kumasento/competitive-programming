/**
 * Author: kumasento
 * Date:   2021-05-13T11:47:30.000-05:00
 */

#include <bits/stdc++.h>
using namespace std;

/// ---------- Types   -----------
using LL = long long;
using PII = pair<int, int>; using PIL = pair<int, LL>; using PLI = pair<LL, int>; using PLL = pair<LL, LL>;

/// ---------- Constants ---------
constexpr int INT_INF = 1000000000;
constexpr LL LL_INF = 10000000000000000LL;

/// ---------- Globals   ---------

/// ---------- Solution  ---------

enum class Color { RED, BLACK };

struct Node {
  Node *p, *left, *right;
  Color color;
  int key;

  Node(Color color) : color(color) {}
  Node(Color color, int key) : color(color), key(key) {}
};

struct Tree {
  Node *nil, *root;

  Tree() : nil(new Node(Color::BLACK)) {} 
};

Node *tree_minimum(Tree *T, Node *x);
void rb_insert(Tree *T, Node *z);
void rb_insert_fixup(Tree *T, Node *z);
void left_rotate(Tree *T, Node *x);
void right_rotate(Tree *T, Node *x);
void rb_transplant(Tree *T, Node *u, Node *v);
void rb_delete(Tree *T, Node *z);
void rb_delete_fixup(Tree *T, Node *x);

Node* tree_minimum(Tree *T, Node *x) {
  while (x->left != T->nil) 
    x = x->left;
  return x;
}

void left_rotate(Tree *T, Node *x) {
  Node *y = x->right;
  x->right = y->left;
  if (y->left != T->nil)
    y->left->p = x;
  y->p = x->p;
  if (x->p == T->nil)
    T->root = y;
  else if (x == x->p->left)
    x->p->left = y;
  else
    x->p->right = y;
  y->left = x;
  x->p = y;
}

void right_rotate(Tree *T, Node *y) {
  Node *x = y->left;

  y->left = x->right;

  if (x->right != T->nil)
    x->right->p = y;
  x->p = y->p;

  if (y->p == T->nil)
    T->root = x;
  else if (y->p->left == y)
    y->p->left = x;
  else
    y->p->right = x;

  y->p = x;
  x->right = y;
}

void rb_insert(Tree *T, Node *z) {
  Node *y = T->nil; // parent of x.
  Node *x = T->root;

  while (x != T->nil) {
    y = x;
    if (x->key < z->key)
      x = x->left;
    else 
      x = x->right;
  }

  z->p = y;
  if (y == T->nil)
    T->root = z;
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;

  z->left = T->nil;
  z->right = T->nil;
  z->color = Color::RED;
  rb_insert_fixup(T, z);
}

void rb_insert_fixup(Tree *T, Node *z) {
  while (z->p->color == Color::RED) {
    if (z->p == z->p->p->left) {
      Node *y = z->p->p->right;
      // Case 1: uncle is red
      if (y->color == Color::RED) {
        z->p->color = Color::BLACK;
        y->color = Color::BLACK;
        z->p->p->color = Color::RED;
        z = z->p->p;
      } else {
        // Case 2: uncle is black and z is right child
        if (z == z->p->right) {
          z = z->p; 
          left_rotate(T, z);
        }
        // Case 3: uncle is black and z is left child
        z->p->color = Color::BLACK;
        z->p->p->color = Color::RED;
        right_rotate(T, z->p->p);
      }
    } else {
      Node *y = z->p->p->left; 
      if(y->color == Color::RED) {
        z->p->color = Color::BLACK;
        y->color= Color::BLACK;
        z->p->p->color = Color::RED;
        z = z->p->p;
      } else {
        if (z->p->left == z) {
          z = z->p;
          right_rotate(T, z);
        }

        z->p->color = Color::BLACK;
        z->p->p->color = Color::RED;
        left_rotate(T, z->p->p);
      }
    }
  }

  T->root->color = Color::BLACK;
}

void rb_transplant(Tree *T, Node *u, Node *v) {
  if (u->p == T->nil)
    T->root = v;
  else if (u == u->p->left)
    u->p->left = v;
  else
    u->p->right = v;

  v->p = u->p;
}

void rb_delete(Tree *T, Node *z) {
  Node *y = z, *x;
  Color y_orig_color = y->color;

  if (z->left == T->nil) {
    x = z->right;
    rb_transplant(T, z, z->right);
  } else if (z->right == T->nil) {
    x = z->left;
    rb_transplant(T, z, z->left);
  } else {
    y = tree_minimum(T, z->right);
    y_orig_color = y->color;
    x = y->right;

    if (y->p == z)
      x->p = y; // x could be NIL.
    else {
      rb_transplant(T, y, y->right);
      y->right = z->right;
      y->right->p = y;
    }

    rb_transplant(T, z, y);
    y->left = z->left;
    y->left->p = y;
    y->color = z->color;
  }

  if (y_orig_color == Color::BLACK) 
    rb_delete_fixup(T, x);
}

void rb_delete_fixup(Tree *T, Node *x) {
  Node *w;
  while (x != T->root && x->color == Color::BLACK) {
    if (x == x->p->left) {
      w = x->p->right;
      if (w->color == Color::RED) {
        w->color = Color::BLACK;
        x->p->color = Color::RED;
        left_rotate(T, x->p);
        w = x->p->right;
      }
      // w is still x's sibling, just its color is BLACK.

      if (w->left->color == Color::BLACK &&
          w->right->color == Color::BLACK) {
        w->color = Color::RED;
        x = x->p;
      } else {
        if (w->right->color == Color::BLACK) {
          w->left->color = Color::BLACK;
          w->color = Color::RED;
          right_rotate(T, w);
          w = x->p->right;
        }
        // Now, w is still x's sibling, and w's right child is RED.

        w->color = x->p->color;
        x->p->color = Color::BLACK;
        w->right->color = Color::BLACK;
        left_rotate(T, x->p);
        x = T->root;
      }
    } else {
      w = x->p->left;
      if (w->color == Color::RED) {
        x->p->color = Color::RED;
        w->color = Color::BLACK;
        right_rotate(T, x->p);
        w = x->p->left;
      }

      if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
        w->color = Color::RED;
        x = x->p;
      } else {
        if (w->left->color == Color::BLACK) {
          w->right->color = Color::RED;
          w->color = Color::BLACK;
          left_rotate(T, w);
          w = x->p->left;
        }

        w->color = x->p->color;
        x->p->color = Color::BLACK;
        w->left->color = Color::BLACK;
        right_rotate(T, x->p);
        x = T->root;
      }
    }
  }
  x->color = Color::BLACK;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  Tree *T = new Tree();
}
