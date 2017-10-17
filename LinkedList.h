typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next;
    struct LinkedListNode* prev;
} LinkedListNode;

typedef struct
{
    LinkedListNode* head;
    LinkedListNode* tail;
    int size;
} LinkedList;


LinkedList* construct(void);
void insertFirst(LinkedList*, void*);
void insertLast(LinkedList*, void*);
LinkedListNode* removeFirst(LinkedList*);
LinkedListNode* removeLast(LinkedList*);
LinkedListNode* find(LinkedList*, int);
void print(LinkedList*);
void freeLinkedList(LinkedList*);
void freeNode(LinkedListNode*);