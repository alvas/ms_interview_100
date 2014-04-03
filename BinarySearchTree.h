class BST
{
    public:
        int GetKey();
        void SetKey(int);
        BST *GetParent();
        void SetParent(BST *);
        BST *GetLeft();
        void SetLeft(BST *);
        BST *GetRight();
        void SetRight(BST *);

        int key;
        BST *p;
        BST *left;
        BST *right;
};

int binarySearchRecursive(int A[], int p, int r, int x);
int binarySearch(int A[], int p, int r, int x);
