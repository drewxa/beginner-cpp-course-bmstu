#ifndef __SCOPED_PTR__
#define __SCOPED_PTR__

template<class T>
class TScopedPtr
{
public:
	TScopedPtr(TScopedPtr const &) = delete;
	TScopedPtr & operator=(TScopedPtr const &) = delete;
	
	explicit TScopedPtr(T * p = nullptr);

	~TScopedPtr();

	void reset(T * p = nullptr);

	T & operator*() const;

	T * operator->() const;

	T * get() const throw();

	void swap(TScopedPtr & b) throw();

	bool operator! () const throw();

	explicit operator bool() const throw();
};

template<class T> 
inline bool operator==(TScopedPtr<T> const & p, std::nullptr_t) throw();

template<class T> 
inline bool operator==(std::nullptr_t, TScopedPtr<T> const & p) throw();

template<class T>
inline bool operator!=(TScopedPtr<T> const & p, std::nullptr_t) throw();

template<class T> 
inline bool operator!=(std::nullptr_t, TScopedPtr<T> const & p) throw();

template<class T> 
inline void swap(TScopedPtr<T> & a, TScopedPtr<T> & b) throw();

// get_pointer(p) is a generic way to say p.get()
template<class T> 
inline T * get_pointer(TScopedPtr<T> const & p) throw();

#endif // __SCOPED_PTR__