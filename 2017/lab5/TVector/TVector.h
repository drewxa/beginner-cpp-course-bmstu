#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__

#include <xutility>

template<typename T>
class TPsevdoVector
{
public:

	class TIterator:
		public std::iterator<std::random_access_iterator_tag, T>
	{
		T * Ptr = nullptr;

		TIterator(T * p) :
			Ptr(p)
		{ }

		friend class TPsevdoVector<T>;
			 
	public:
		TIterator() = default;
		TIterator& operator=(const TIterator&) = default;

		T& operator*() const
		{
			return *Ptr;
		}

		T* operator->() const
		{
			return Ptr;
		}

		bool operator != (const TIterator& r)
		{
			return Ptr != r.Ptr;
		}

		bool operator < (const TIterator& r)
		{
			return Ptr < r.Ptr;
		}

		bool operator == (const TIterator& r)
		{
			return !(*this != r);
		}

		TIterator& operator ++ ()
		{
			++Ptr;
			return *this;
		}

		TIterator& operator -- ()
		{
			--Ptr;
			return *this;
		}

		TIterator& operator + (size_t cnt)
		{
			Ptr += cnt;
			return *this;
		}

		TIterator& operator - (size_t cnt)
		{
			Ptr -= cnt;
			return *this;
		}
	};


	using value_type = T;
	using size_type = size_t;
	using iterator = TIterator;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;
public:
	TPsevdoVector()
		: Ptr(nullptr)
		, Count(0)
		, InternalCapacity(0)
	{ }
	
	TPsevdoVector(size_type capacity)
		: Count(0)
		, InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
	}

	~TPsevdoVector()
	{
		delete[] Ptr;
	}
	
	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type capacity() const throw()
	{
		return InternalCapacity;
	}

	iterator begin() const throw()
	{
		return TIterator(Ptr);
	}

	iterator end() const throw()
	{
		return TIterator(Ptr + Count);
	}
	
	void push_back(const value_type& value)
	{
		if (Count < InternalCapacity)
		{
			Ptr[Count] = value;
			++Count;
		}
		else
			throw std::logic_error("ups");
	}
};


#endif // __TVECTOR_INCLUDED__
