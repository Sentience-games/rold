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
	return (void*)(((umm)ptr + (alignment-1)) & ~(alignment-1));
}

u8
AlignOffset(void* ptr, u8 alignment)
{
	ASSERT(IS_POW2(alignment));
	return (u8)(1 + ~((umm)ptr & (umm)(alignment-1)));
}

typedef struct Arena_Internal
{
	void (*commit_more_memory)(struct Arena_Internal* arena);
	umm cursor;
	umm committed;
	umm reserved;
	u8* memory;
} Arena_Internal;

typedef void Arena;
typedef void Arena_Marker;

void*
Arena_Push(Arena* arena_handle, umm size, u8 alignment)
{
	Arena_Internal* arena = (Arena_Internal*)arena_handle;

	umm aligned_cursor = (arena->cursor + (alignment-1)) & ~(alignment-1);

	// NOTE: check for overflow. Not done for aligning cursor, since that should be caught by windows dying
	ASSERT(size < UMM_MAX - aligned_cursor);
	arena->cursor = aligned_cursor + size;

	if (arena->cursor > arena->committed) arena->commit_more_memory(arena);

	return &arena->memory[aligned_cursor];
}

void
Arena_Pop(Arena* arena_handle, umm size)
{
	Arena_Internal* arena = (Arena_Internal*)arena_handle;

	ASSERT(arena->cursor >= size);
	arena->cursor -= size;
}

void
Arena_Clear(Arena* arena_handle)
{
	Arena_Internal* arena = (Arena_Internal*)arena_handle;

	arena->cursor = 0;
}

Arena_Marker*
Arena_GetMarker(Arena* arena_handle)
{
	Arena_Internal* arena = (Arena_Internal*)arena_handle;

	return (Arena_Marker*)arena->cursor;
}

void
Arena_PopToMarker(Arena* arena_handle, Arena_Marker* marker)
{
	Arena_Internal* arena = (Arena_Internal*)arena_handle;

	ASSERT(arena->cursor >= (umm)marker);
	arena->cursor = (umm)marker;
}
