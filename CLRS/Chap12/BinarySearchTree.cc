#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class BinarySearchTree {
  struct Node {
    T val;
    Node* parent;  // parent should have longer life-cycle than children.
    unique_ptr<Node> left, right;

    Node(const T& val) : val(val) {}
    Node(const T& val, Node* parent) : val(val), parent(parent) {}

    friend ostream& operator<<(ostream& os, const Node& node) {
      os << node.val << "(";
      if (node.left != nullptr)
        os << *(node.left);
      else
        os << "*";
      os << ",";
      if (node.right != nullptr)
        os << *(node.right);
      else
        os << "*";
      os << ")";
      return os;
    }
  };

  unique_ptr<Node> root;

 public:
  void insert(const T& val);
  bool search(const T& val) const;
  void remove(const T& val);

  friend ostream& operator<<(ostream& os, const BinarySearchTree<T>& bst) {
    if (bst.root == nullptr)
      os << "NULL";
    else
      os << *(bst.root);
    return os;
  }

  /// Find the minimum tree node starting from the given node.
  // No ownership changed in the process.
  auto& treeMinimum(unique_ptr<Node>& node);
  auto& treeMinimum() { return treeMinimum(root); }

 private:
  /// The ownership of v will be transferred here.
  // and u will be destroyed.
  void transplant(unique_ptr<Node>& u, unique_ptr<Node> v) {
    Node* parent = u->parent;

    // NOTE: vital important to update the parent node here.
    if (v != nullptr) v->parent = parent;

    if (parent == nullptr) {
      cerr << "--> Transplant root\n";

      root = move(v);  // u is root;
    } else if (parent->left == u) {
      cerr << "--> Transplant parent's right child\n";

      parent->left = move(v);
    } else if (parent->right == u) {
      cerr << "--> Transplant parent's right child\n";

      parent->right = move(v);
    } else {
      cerr << "--> Transplant failed\n";
      cerr << "--- Parent: " << *parent << endl;
      cerr << "--- v:      " << *v << endl;

      assert(false);
    }
  }
};

template <typename T>
auto& BinarySearchTree<T>::treeMinimum(unique_ptr<Node>& node) {
  assert(node != nullptr);

  unique_ptr<Node>* curr = &node;
  while ((*curr)->left != nullptr) curr = &((*curr)->left);

  // Now, curr will be a node without left child.
  return *curr;
}

template <typename T>
bool BinarySearchTree<T>::search(const T& val) const {
  if (root == nullptr) return false;

  Node* curr = root.get();
  while (curr != nullptr) {
    if (curr->val == val) return true;

    if (val < curr->val)
      curr = curr->left.get();
    else
      curr = curr->right.get();
  }
  return false;
}

template <typename T>
void BinarySearchTree<T>::insert(const T& val) {
  cerr << " -- Insert value " << val << " in to the tree ...\n";

  if (root == nullptr) {
    root = make_unique<Node>(val, nullptr);
  } else {
    unique_ptr<Node>* curr = &root;
    while ((*curr) != nullptr) {
      if (val < (*curr)->val) {
        if ((*curr)->left == nullptr) {
          (*curr)->left = make_unique<Node>(val, curr->get());
          break;
        }

        curr = &((*curr)->left);
      } else {
        if ((*curr)->right == nullptr) {
          (*curr)->right = make_unique<Node>(val, curr->get());
          break;
        }

        curr = &((*curr)->right);
      }
    }
  }

  cerr << "Result: " << *root << endl;
}

template <typename T>
void BinarySearchTree<T>::remove(const T& val) {
  cerr << " -- Removing value: " << val << endl;
  if (root == nullptr) return;

  unique_ptr<Node>* curr = &root;
  while ((*curr) != nullptr) {
    if ((*curr)->val == val) {
      cerr << "Curr: " << *(*curr) << endl;
      // case #1
      if (!(*curr)->left) {
        cerr << ">>> Case #1" << endl;
        transplant(*curr, move((*curr)->right));
      } else {
        // case #2
        if ((*curr)->right == nullptr) {
          cerr << ">>> Case #2" << endl;
          transplant(*curr, move((*curr)->left));
        } else {
          auto& next = treeMinimum((*curr)->right);
          // case #3
          if (next == (*curr)->right) {
            cerr << ">>> Case #3" << endl;
            next->left = move((*curr)->left);
            next->left->parent = next.get();
            transplant(*curr, move(next));
          } else {
            // case #4
            cerr << ">>> Case #4" << endl;
            unique_ptr<Node> temp = move(next);
            temp->parent->left = move(temp->right);
            temp->left = move((*curr)->left);
            temp->left->parent = temp.get();
            temp->right = move((*curr)->right);
            temp->right->parent = temp.get();
            transplant(*curr, move(temp));
          }
        }
      }

      break;
    } else if ((*curr)->val < val) {
      curr = &((*curr)->right);
    } else {
      curr = &((*curr)->left);
    }
  }

  cerr << "Result: " << *this << endl;
}

int main() {
  BinarySearchTree<int> bst;
  cerr << bst << endl;

  cerr << "\n=== Test insert:\n";
  bst.insert(6);
  bst.insert(3);
  bst.insert(1);
  bst.insert(4);
  bst.insert(8);
  bst.insert(11);
  bst.insert(12);
  bst.insert(10);
  bst.insert(9);

  // Shouldn't be NULL.
  cerr << *bst.treeMinimum() << endl;

  cerr << "\n=== Test search:\n";
  cerr << " -- Has value 6? " << bst.search(6) << endl;
  cerr << " -- Has value 3? " << bst.search(3) << endl;
  cerr << " -- Has value 1? " << bst.search(1) << endl;
  cerr << " -- Has value 8? " << bst.search(8) << endl;
  cerr << " -- Has value 9? " << bst.search(9) << endl;
  cerr << " -- Has value 0? " << bst.search(0) << endl;
  cerr << " -- Has value 5? " << bst.search(5) << endl;
  cerr << " -- Has value 2? " << bst.search(2) << endl;

  cerr << "\n=== Test remove:\n";
  bst.remove(6);
  bst.remove(8);
  bst.remove(9);
  bst.remove(11);
  bst.remove(4);
  bst.remove(1);
  bst.remove(3);
  bst.remove(12);
  bst.remove(10);
}
