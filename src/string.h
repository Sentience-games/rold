typedef struct String
{
	u8* data;
	umm size;
} String;

#define STRING(S) (String){ .data = (u8*)(S), .size = sizeof(S) - 1 }
// NOTE: MSF stands for Microsoft Fuckery, used to circumvent the sucky "expression is not constant" bullshittery
#define MSF_STRING(S) { .data = (u8*)(S), .size = sizeof(S) - 1 }

bool
Char_IsAlpha(u8 c)
{
	return (u8)((c&0xDF) - 'A') <= (u8)('Z'-'A');
}

bool
Char_IsHexAlpha(u8 c)
{
	return (u8)((c&0xDF) - 'A') <= (u8)('F'-'A');
}

bool
Char_IsDigit(u8 c)
{
	return (u8)(c - '0') < (u8)(10);
}

umm
Strlen(u8* cstring)
{
	umm result = 0;

	if (cstring) for (; cstring[result] != 0; ++result);

	return result;
}

String
String_FromCString(u8* cstring)
{
	return (String){
		.data = cstring,
		.size = Strlen(cstring),
	};
}

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
	if (n >= s.size) return (String){0};
	else             return (String){ .data = s.data + n, .size = s.size - n };
}

String
String_ChopN(String s, umm n)
{
	if (n >= s.size) return (String){0};
	else             return (String){ .data = s.data, .size = s.size - n };
}
