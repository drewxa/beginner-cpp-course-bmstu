#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__

class TVector
{
public:
	using value_type = int;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;
public:
	TVector()
		: Ptr(nullptr)
		, Count(0)
		, InternalCapacity(0)
	{ }
	
	TVector(size_type capacity)
		: Count(0)
		, InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
	}

	~TVector()
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
		return Ptr;
	}

	iterator end() const throw()
	{
		return Ptr + Count;
	}

	void reserve(size_type size)
	{
		// реализовать
	}

	TVector(const TVector& rhs)
	{
		// реализовать
	}

	TVector& operator=(const TVector& rhs)
	{
		// реализовать
	}

	// Добавляет элемент в массив
	// Если не хватает памяти в Ptr, то выделяет новую
	// Аналог std::vector::push_back
	void push_back(const value_type& value)
	{
		// реализовать		
	}
	
	reference at(size_type index)
	{
		// реализовать	
	}

	value_type at(size_type index) const
	{
		// реализовать	
	}

	reference operator[](size_type index)
	{
		// реализовать
	}

	const_reference operator[](size_type index) const
	{
		// реализовать
	}

	reference front()
	{
		// реализовать	
	}

	const_reference front() const
	{
		// реализовать	
	}

	reference back()
	{
		// реализовать	
	}

	const_reference back() const
	{
		// реализовать	
	}

	void clear()
	{
		// реализовать	
	}

	void pop_back()
	{
		// реализовать
	}

	void swap(TVector& other) throw()
	{
		// реализовать
	}

	void resize(size_type count, value_type value = value_type())
	{
		// реализовать
	}

	iterator insert(iterator pos, const value_type& value)
	{
		// реализовать
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		// реализовать
	}

	iterator erase(iterator pos)
	{
		// реализовать
	}

	iterator erase(iterator first, iterator last)
	{
		// реализовать
	}
};


#endif // __TVECTOR_INCLUDED__