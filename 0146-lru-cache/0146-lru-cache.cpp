class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        // dummy head and tail
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail; 
        tail->prev = head;
    }

    // remove a node from DLL
    void deleteNode(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        n->prev = p;
    }

    // insert node right after head (most recently used position)
    void insertAfterHead(Node* node) {
        Node* first = head->next;

        head->next = node;
        node->prev = head;

        node->next = first;
        first->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        int val = node->value;

        // move this node to front (recently used)
        deleteNode(node);
        insertAfterHead(node);

        return val;
    }

    void put(int key, int value) {
        // if key already exists, remove old node
        if (mp.find(key) != mp.end()) {
            Node* existing = mp[key];
            deleteNode(existing);
            mp.erase(key);
            delete existing;
        }

        // if capacity full, remove LRU node (before tail)
        if (mp.size() == capacity) {
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        // insert new node at front
        Node* newNode = new Node(key, value);
        insertAfterHead(newNode);
        mp[key] = newNode;
    }
};
