void
Zero(void* ptr, umm size)
{
	for (umm i = 0; i < size; ++i) ((u8*)ptr)[i] = 0;
}

#define ZeroStruct(S) Zero((S), sizeof(0[S]))
#define ZeroArray(A, C) Zero((A), sizeof(0[A])*(C))

void
Copy(void* src, void* dst, umm size)
{
	for (umm i = 0; i < size; ++i) ((u8*)dst)[i] = ((u8*)src)[i];
}

void
Move(void* src, void* dst, umm size)
{
	u8* bsrc = (u8*)src;
	u8* bdst = (u8*)dst;

	if (bsrc < bdst) for (umm i = size-1; i < size; --i) bdst[i] = bsrc[i];
	else             for (umm i =      0; i < size; ++i) bdst[i] = bsrc[i];
}

void*
Align(void* ptr, u8 alignment)
{
	ASSERT(IS_POW2(alignment));
	return ((umm)ptr + (alignment-1)) & ~(alignment-1);
}

u8
AlignOffset(void* ptr, u8 alignment)
{
	ASSERT(IS_POW2(alignment));
	return (u8)(-((umm)ptr & (umm)(alignment-1)));
}

typedef struct Arena
{
	void* (*commit_more_memory)(struct Arena* arena);
	umm cursor;
	umm committed;
	umm reserved;
	u8 commit_pace;
	u8 memory[]; // NOTE: C zero width array, shortcut for (u8*)arena + sizeof(arena)
} Arena;

// NOTE: This is a struct to avoid accidentally doing stuff like marker + 1
//       (it is more obviously wrong when you have to do marker._value + 1)
typedef struct Arena_Marker
{
	umm _value;
} Arena_Marker;

// NOTE: No Arena_Create or Arena_Destroy, this is done exclusively by the platform layer. The game layer is not
//       allowed to make new arenas, or delete old ones.

void*
Arena_Push(Arena* arena, umm size, u8 alignment)
{
	ASSERT(size < U64_MAX - arena->cursor && alignment < U64_MAX - (arena->cursor + size)); // NOTE: Assert nothing will overflow
	ASSERT(IS_POW2(alignment));

	umm aligned_cursor = (arena->cursor + (alignment-1)) & ~(alignment-1);
	arena->cursor = aligned_cursor + size;

	if (arena->cursor > arena->committed) arena->commit_more_memory(arena);

	return &arena->memory[aligned_cursor];
}

// NOTE: Only use Arena_Pop when you are absolutely confident in what you are doing, use Arena_PopToMarker otherwise
void
Arena_Pop(Arena* arena, umm amount)
{
	ASSERT(arena->cursor > amount);
	arena->cursor -= amount;
}

void
Arena_PopToMarker(Arena* arena, Arena_Marker marker)
{
	ASSERT(arena->cursor > marker._value);
	arena->cursor = marker._value;
}

Arena_Marker
Arena_GetMarker(Arena* arena)
{
	return (Arena_Marker){ ._value = arena->cursor };
}

void
Arena_Clear(Arena* arena)
{
	arena->cursor = 0;
}
