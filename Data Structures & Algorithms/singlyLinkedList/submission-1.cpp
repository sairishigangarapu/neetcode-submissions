class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};
class LinkedList {
private:
    Node* head;
    int size;
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        Node* cur = head;

        for (int i = 0; i< index;i++)
            cur = cur->next;
        return cur->val;
    }

    void insertHead(int val) {
        Node *newNode = new Node(val);

        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void insertTail(int val) {
        Node *newNode = new Node(val);

        if ( head == nullptr)
            head = newNode;
        else{
            Node* cur = head;
            while (cur->next != nullptr)
            {
                cur = cur->next;
            }
            cur->next = newNode;
        }
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size)
            return false;
        if (index==0)
        {
            Node *temp = head;
            head = head-> next;
            delete temp;
        }
        else{
            Node* cur = head;
            for (int i=0;i<index-1;i++)
            {
                cur=cur->next;
            }
            Node *temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> result;
        Node *cur = head;
        while (cur != nullptr)
        {
            result.push_back(cur->val);
            cur = cur -> next;
        }
        return result;
    }
};
