#define CONCAT_4(X, Y) X##Y
#define CONCAT_3(X, Y) CONCAT_4(X, Y)
#define CONCAT_2(X, Y) CONCAT_3(X, Y)
#define CONCAT_1(X, Y) CONCAT_2(X, Y)
#define CONCAT(X, Y) CONCAT_1(X,Y)

#define NUM_ARGS_(N) N
#define NUM_ARGS_10(N, X, ...) TOO_MANY_ARGS
#define NUM_ARGS_9(N, X, ...) CONCAT(NUM_ARGS_, __VA_OPT__(10))(9 __VA_OPT__(,) __VA_ARGS__)
#define NUM_ARGS_8(N, X, ...) CONCAT(NUM_ARGS_, __VA_OPT__(9))(8 __VA_OPT__(,) __VA_ARGS__)
#define NUM_ARGS_7(N, X, ...) CONCAT(NUM_ARGS_, __VA_OPT__(8))(7 __VA_OPT__(,) __VA_ARGS__)
#define NUM_ARGS_6(N, X, ...) CONCAT(NUM_ARGS_, __VA_OPT__(7))(6 __VA_OPT__(,) __VA_ARGS__)
#define NUM_ARGS_5(N, X, ...) CONCAT(NUM_ARGS_, __VA_OPT__(6))(5 __VA_OPT__(,) __VA_ARGS__)
#define NUM_ARGS_4(N, X, ...) CONCAT(NUM_ARGS_, __VA_OPT__(5))(4 __VA_OPT__(,) __VA_ARGS__)
#define NUM_ARGS_3(N, X, ...) CONCAT(NUM_ARGS_, __VA_OPT__(4))(3 __VA_OPT__(,) __VA_ARGS__)
#define NUM_ARGS_2(N, X, ...) CONCAT(NUM_ARGS_, __VA_OPT__(3))(2 __VA_OPT__(,) __VA_ARGS__)
#define NUM_ARGS_1(N, X, ...) CONCAT(NUM_ARGS_, __VA_OPT__(2))(1 __VA_OPT__(,) __VA_ARGS__)
#define NUM_ARGS(...)         CONCAT(NUM_ARGS_, __VA_OPT__(1))(0 __VA_OPT__(,) __VA_ARGS__)

// TODO: check this is not optimized out and traps correctly
#define ASSERT(EX) ((EX) ? 1 : (__debugbreak(), *(volatile int*)0 = 0))
#define NOT_IMPLEMENTED ASSERT(!"NOT_IMPLEMENTED")
#define STATIC_ASSERT(E) static struct { int static_ass : ((E) ? 1 : -1); } CONCAT(StaticAssert_, __LINE__)

#define OFFSETOF(T, E) ((umm)(&((T*)0)->E))
#define ALIGNOF(T) OFFSETOF(struct { char c; T t; }, t)

#define STATIC_ARRAY_SIZE(A) (sizeof(A)/sizeof(0[A]))

#define KB(N) ((umm)(N) << 10)
#define MB(N) ((umm)(N) << 20)
#define GB(N) ((umm)(N) << 30)

typedef signed __int8  s8;
typedef signed __int16 s16;
typedef signed __int32 s32;
typedef signed __int64 s64;

typedef unsigned __int8  u8;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;

// NOTE: for anything that needs to index memory (pointer size)
typedef s64 smm;
typedef u64 umm;

// NOTE: for when bit width is not important
typedef s64 sint;
typedef u64 uint;

#define S8_MIN   (s8)(0x80)
#define S16_MIN (s16)(0x8000)
#define S32_MIN (s32)(0x80000000DL)
#define S64_MIN (s64)(0x8000000000000000DLL)

#define S8_MAX   (s8)(0x7F)
#define S16_MAX (s16)(0x7FFF)
#define S32_MAX (s32)(0x7FFFFFFFDL)
#define S64_MAX (s64)(0x7FFFFFFFFFFFFFFFDLL)

#define U8_MAX   (u8)(0xFF)
#define U16_MAX (u16)(0xFFFF)
#define U32_MAX (u32)(0xFFFFFFFFUL)
#define U64_MAX (u64)(0xFFFFFFFFFFFFFFFFULL)

#define SMM_MIN S64_MIN
#define SMM_MAX S64_MAX
#define UMM_MAX U64_MAX

#define SINT_MIN S64_MIN
#define SINT_MAX S64_MAX
#define UINT_MAX U64_MAX

typedef u8 bool;
#define true 1 // TODO: Maybe change?
#define false 0

typedef float f32;
typedef double f64;

#include "string.h"
#include "math.h"
#include "memory.h"

typedef struct Platform_Link
{
	Arena* persistent_arena;
	Arena* frame_arena;
} Platform_Link;

typedef void Game_Tick_Func(Platform_Link platform_link);
