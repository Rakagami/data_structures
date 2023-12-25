struct LLNode {
    int value;
    struct node *next;
};

struct LinkedListNode* LLaddValue(int value);

struct LinkedListNode* LLdeleteValue(int value);
