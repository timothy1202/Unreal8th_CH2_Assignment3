#pragma once
#include<iostream>
#include<algorithm>

class Item; // Item 클래스가 있음을 알림
bool compareItemsByPrice(const Item& item1, const Item& item2);

template <typename T>
class Inventory
{
private:
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity = 10) : size_(0)
	{
		if (capacity <= 0)
		{
			capacity_ = 1;
		}
		else
		{
			capacity_ = capacity;
		}
		pItems_ = new T[capacity_];
	}

    Inventory(const Inventory<T>& other)
    {
        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];

        for (int i = 0; i < size_; ++i)
        {
            pItems_[i] = other.pItems_[i];
        }

        std::cout << "인벤토리 복사 완료" << std::endl;
    }

	~Inventory()
	{	
		if (pItems_ != nullptr)
		{
			delete[] pItems_;
			pItems_ = nullptr;
		}
	}
	
    void Assign(const Inventory<T>& other)
    {
        if (this == &other) { return; }

        delete[] pItems_;

        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];
        
        for (int i = 0; i < size_; ++i)
        {
            pItems_[i] = other.pItems_[i];
        }
        
    }

    void AddItem(const T& item) 
    {
        if (size_ >= capacity_)
        {
            int newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            Resize(newCapacity);
        }

        pItems_[size_] = item;
        ++size_;
    }

    void Resize(int newCapacity)
    {
        T* pItems_new = new T[newCapacity];

        for (int i = 0; i < size_; ++i)
        {
            pItems_new[i] = pItems_[i];
        }

        delete[] pItems_;
        
        pItems_ = pItems_new;
        capacity_ = newCapacity;

    }

    void RemoveLastItem() 
    {
        if (size_ > 0)
        {
            --size_;
        }
        else
        {
            std::cout << "인벤토리가 비었습니다" << std::endl;
        }
    }

    int GetSize() const 
    {
        return size_;
    }

    int GetCapacity() const 
    {
        return capacity_;
    }

    void PrintAllItems() const 
    {
        if (size_ == 0)
        {
            std::cout << "비어있음" << std::endl;
            return;
        }

        for (int i = 0; i < size_; ++i) 
        {
            pItems_[i].PrintInfo();
        }
    }

    void SortItems()
    {
        std::sort(pItems_, pItems_ + size_, compareItemsByPrice);
    }

};