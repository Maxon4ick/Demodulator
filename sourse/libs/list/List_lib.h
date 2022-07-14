#ifndef LIST_H
#define LIST_H

struct Node
{
public:
    Node *p_next;
    Node *p_prev;
    int data;
    Node(int data = 0,Node *p_next = nullptr,Node *p_prev = nullptr)
    {
        this->data = data;
        this->p_next = p_next;
        this->p_prev = p_prev;
    }

};

class MyList
{
public:

MyList()
{
    si = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

void PushBack(int data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        tail = head;
    }
    else
    {
        Node *current = new Node(data);

        current->p_next = nullptr;
        current->p_prev = tail;
        tail->p_next = current;
        tail = current;
    }
    si++;
}

void PushFront(int data)
{
    if (head == nullptr)
    {
        head = new Node(data);
        tail = head;
    }
    else
    {
        Node *current = new Node(data);

        current->p_next = head;
        current->p_prev = nullptr;
        head = current;
    }
    si++;
}
int & operator [](const int index)
{
    Node *current = this->head;
    int count = 0;
    while (current!= nullptr)
    {
        if (count == index)
        {
            return current->data;
        }
        current = current->p_next;
        count++;
    }
}
int Size()
{
    return this->si;
}
void PopFront ()
{
    Node *temp = head;
    head = head->p_next;
    delete temp;
    si--;
}

void PopBack()
{
    Node *temp = tail;
    tail = tail->p_prev;
    delete temp;
    si--;
}

void clean()
{
    while(si!=1)
    {
        PopBack();
        PopFront();
    }
    Node *temp = head;
    delete temp;
    si--;
}
bool IsEmpety()
{
    if (si == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Insert(int pos,int data)
{
    Node *current = head;
    for (int i =0; i<pos-1; i++)
    {
        current = current->p_next;
    }
    Node *temp = new Node(data);
    temp->p_next = current->p_next;
    temp->p_prev = current;
    current->p_next = temp;

    si++;
}

void Erase(int pos)
{
    Node *current = head;
    for (int i =0; i<pos; i++)
    {
        current = current->p_next;
    }
    Node *temp = current;
    current->p_prev->p_next = current->p_next;
    current->p_next->p_prev = current->p_prev;
    delete temp;
    si--;
}
void Resize(int n)
{
    if (n<si)
    {
        while (si>n)
        {
            PopBack();
        }
    }
    else
    {
        while (si<n)
        {
            PushBack(0);
        }
    }
}

void Resize(int n,int data)
{
    if (n<si)
    {
        while (si>n)
        {
            PopBack();
        }
    }
    else
    {
        while (si<n)
        {
            PushBack(data);
        }
    }
}

int Front()
{
    return head->data;
}

Node* Begin()
{
    return head;
}

int Back()
{
    return tail->data;
}

Node* End()
{
    return tail;
}

void Swap(const MyList &ohter)
{
    Node *tempA = this->head;
    Node *tempB = ohter.head;
    int fval = this->head->data;
    swapNode(tempA,tempB);
    PopFront();
    PushFront(ohter.head->data);
    ohter.head->data =fval;
}

void Unique()
{
    Node* previous = head;
    Node* current = previous->p_next;
    while (current != nullptr)
    {
        Node* var = head;
        while (var != current)
        {
            if (var->data == current->data)
            {
                Node* tmp = current->p_next;
                previous->p_next = tmp;
                current = tmp;
                si--;
            }
            var = var->p_next;
        }
        if (var == current) {
            previous = current;
            current = current->p_next;
        }
    }
}

private:
int si;
Node *head;
Node *tail;
void swapNode (Node*a,Node*b)
{
    Node*temp;
    temp = a->p_prev;
    a->p_prev= b->p_prev;
    b->p_prev = temp;
    temp = a->p_next;
    a->p_next = b->p_next;
    b->p_next = temp;
}
};
#endif // LIST_H
