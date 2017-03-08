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
		// implement
	}

	TVector(const TVector& rhs)
	{
		// implement
	}

	TVector& operator=(const TVector& rhs)
	{
		// implement
	}

	void push_back(const value_type& value)
	{
		// implement		
	}
	
	reference at(size_type index)
	{
		// implement	
	}

	value_type at(size_type index) const
	{
		// implement
	}

	reference operator[](size_type index)
	{
		// implement
	}

	const_reference operator[](size_type index) const
	{
		// implement
	}

	reference front()
	{
		// implement	
	}

	const_reference front() const
	{
		// implement	
	}

	reference back()
	{
		// implement	
	}

	const_reference back() const
	{
		// implement	
	}

	void clear()
	{
		// implement	
	}

	void pop_back()
	{
		// implement
	}

	void swap(TVector& other) throw()
	{
		// implement
	}

	void resize(size_type count, value_type value = value_type())
	{
		// implement
	}

	iterator insert(iterator pos, const value_type& value)
	{
		// implement
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		// implement
	}

	iterator erase(iterator pos)
	{
		// implement
	}

	iterator erase(iterator first, iterator last)
	{
		// implement
	}
};


#endif // __TVECTOR_INCLUDED__
