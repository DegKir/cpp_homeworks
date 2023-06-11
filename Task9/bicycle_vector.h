#include <exception>
#include <stdexcept>
#include <iostream>

template <typename T>
class bicycle_vector
{
private:
    size_t sz_;
    T* arr_;
public:
    bicycle_vector(size_t size):sz_(size),arr_(new T[size]){};
    ~bicycle_vector(){delete [] arr_;};
    int get_size(){return sz_;}
    int& operator [](int index)
    {
        if(index > sz_ -1)
            throw std::out_of_range(" ERROR !\nOut of range at index "+std::to_string(index));
        return arr_[index];
    }
    
    int& operator [](int index) const
    {
        if(index > sz_ -1)
            throw std::out_of_range("Out of range at index "+std::to_string(index));
        return arr_[index];
    }

    bicycle_vector(const bicycle_vector &other):sz_(other.sz_), arr_(new int[sz_])
    {
        for (int i=0;i<sz_;++i)
            arr_[i]=other.arr_[i];
    }

    bicycle_vector &operator=(const bicycle_vector &other)
    {
        if(this==&other)
        {
            return *this;
        }
        delete []arr_;
        sz_=other.sz_;
        arr_ = new int[sz_];
        for(int i=0;i<sz_;++i)
            arr_[i]=other.arr_[i];
        return (*this);
    }          

    bicycle_vector(bicycle_vector&& other) :arr_(other.arr_), sz_(other.sz_)
    {
        other.arr_=nullptr;
    }
    bicycle_vector& operator=(bicycle_vector&& other)
    {
        if(this==&other)
        {
            return *this;
        }
        delete [] arr_;
        arr_ = other.arr_;
        other.arr_ = nullptr;
        return *this;
    }

    void pushback(T new_elem)
    {
        sz_++;
        T* new_arr_ = new T [sz_];
        for( int i = 0; i<sz_-1;i++)
            new_arr_[i]=arr_[i];
        new_arr_[sz_-1]=new_elem;
        delete [] arr_;
        arr_=new_arr_;
    }

    T* begin()
    {
        return &arr_[0];
    }
    T* end()
    {
        return &arr_[sz_];
    }

    void resize(int new_sz_)
    {
        T* new_arr = new T[new_sz_];
        for( int i = 0; i<new_sz_;i++)
            new_arr[i]=arr_[i];
        delete[] arr_;
        arr_ = new_arr;
        sz_=new_sz_;
    }

};
