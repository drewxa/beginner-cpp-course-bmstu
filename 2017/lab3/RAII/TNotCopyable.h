#ifndef __NOTCOPYABLE_INCLUDED__
#define __NOTCOPYABLE_INCLUDED__

#include <allocators>
#include <memory>
class TNotCopyable
{
	int * Memory;
	const int Size = 10;

	std::allocator<int> Al; // default allocator for ints
	void Init()
	{
		for (int i = 0; i < Size; ++i)
		{
			Memory[i] = rand();
		}
	}
public:
	TNotCopyable()
		: Memory(nullptr)
	{ }

	TNotCopyable(const TNotCopyable&) = delete;
	TNotCopyable& operator = (const TNotCopyable&) = delete;

	void Allocate()
	{
		Memory = Al.allocate(Size); // space for 10 ints
		Init();
	}

	void Deallocate()
	{
		Al.deallocate(Memory, Size);
	}

	int Get()
	{
		return Memory[rand() % Size];
	}
};

#endif // __NOTCOPYABLE_INCLUDED__