/*
implement smart pointer in C++
*/

template <class T> 
class SmartP {
public:
    SmartP(const SmartP<T>& p) { incRef(p); }
    SmartP(T* p) { assign(p); }
    ~SmartP() { decRef(); }
 

    SmartP<T>& operator = (const SmartP<T>& p) {
        if (this != &p)
        {
            decRef();
            incRef(p);
        }
 
        return *this;
    }
 
    T* operator ->() const { return val; }
    T& operator *() const  { return *val; }
 
private:
    void decRef() s{
        (*ref)--;
 
        if (0 == *ref)
        {
            delete val;
            delete ref;
        }
    }
 
    void incRef(const SmartP<T>& ptr) {
        ref = ptr.ref;
        val = ptr.val;
        (*ref)++; 
    }
 
    void assign(T* p) {
        val = p;
        ref = new int(1);
    }

    T* val;
    int* ref;
};

