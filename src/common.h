#define ASSERT(EX) ((EX) ? 1 : (*(volatile int*)0 = 0, 0))
#define NOT_IMPLEMENTED ASSERT(!"NOT_IMPLEMENTED")

#define OFFSETOF(T, E) ((umm)(&((T*)0)->E))
#define ALIGNOF(T) OFFSETOF(struct { char c; T t; }, t)

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))

typedef signed __int8  s8;
typedef signed __int16 s16;
typedef signed __int32 s32;
typedef signed __int64 s64;

typedef unsigned __int8  u8;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;

typedef s64 smm;
typedef u64 umm;

typedef u8 bool;
#define true 1 // TODO: Maybe change?
#define false 0

typedef struct String
{
	u8* data;
	umm size;
} String;

#define STRING(S) (String){ .data = (u8*)(S), .size = sizeof(S) - 1 }
// NOTE: MSF stands for Microsoft Fuckery, used to circumvent the sucky "expression is not constant" bullshittery
#define MSF_STRING(S) { .data = (u8*)(S), .size = sizeof(S) - 1 }

bool
String_Match(String s0, String s1)
{
	bool result = (s0.size == s1.size);

	for (umm i = 0; i < s0.size && result; ++i) result = (s0.data[i] == s1.data[i]);

	return result;
}

String
String_EatN(String s, umm n)
{
	return (String){
		.data = s.data + n,
		.size = s.size - MIN(s.size, n),
	};
}

String
String_ChopN(String s, umm n)
{
	return (String){
		.data = s.data,
		.size = s.size - MIN(s.size, n),
	};
}

typedef struct Platform_Link
{
	bool _stub;
} Platform_Link;

typedef void Tick_Func(Platform_Link platform_link);
