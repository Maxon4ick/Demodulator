#ifndef MYV_H
#define MYV_H
template <typename t>
class MyVector
{
public:
MyVector()
{
    this->first = nullptr;
    this->size = 0;
}
MyVector (int size)
{
    this->size = size;
    this->first = new t[size];
}
MyVector (int size,const t sim)
{
    this->size = size;
    first = new t[this->size];
    for (int i =0; i<size; i++)
    {
        first[i] = sim;
    }
}
t* GetArr()
{
    return this->first;
}
int GetSize()
{
    return this->size;
}
MyVector Copy()
{
    MyVector out(size);
    for (int i= 0; i<this->size; i++)
    {
        out.first[i] = this->first[i];
    }
    return out;
}
void PushBack(t arg)
{
    t* temp = new t[size+1];
    memmove(temp, first, (size) * sizeof(t));
    delete[] this->first;
    first = temp;
    first[size] = arg;
    size = size +1;
}
void PopBack()
{
    t* temp = new t[size-1];
    memmove(temp, first, (size-1) * sizeof(t));
    delete[] this->first;
    first = temp;
    size = size - 1;
}
private:
t * first;
int size = 0;
};
#endif // MYV_H
