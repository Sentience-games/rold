#define ABS(N) ((N) < 0 ? -(N) : (N))

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))

#define IS_POW2(N) ((N) > 0 && ((N)&((N)-1)) == 0)

#define SQUARED(N) ((N)*(N))
#define CUBED(N) ((N)*(N))

typedef union F32_Bits
{
	f32 flt;
	u32 bits;
} F32_Bits;

typedef union F64_Bits
{
	f64 flt;
	u64 bits;
} F64_Bits;

typedef union V2
{
	struct { f32 x, y; };
	f32 e[2];
} V2;

typedef union V3
{
	struct { f32 x, y, z; };
	struct { V2 xy; f32 _0; };
	struct { f32 _1; V2 yz; };
	f32 e[3];
} V3;

typedef struct V4
{
	struct { f32 x, y, z, w; };
	struct { V2 xy; V2 zw; };
	struct { V3 xyz; f32 _0; };
	struct { f32 _1; V3 yzw; };
	struct { f32 _2; V2 yz; };
	f32 e[4];
} V4;

typedef union V2D
{
	struct { f64 x, y; };
	f64 e[2];
} V2D;

typedef union V3D
{
	struct { f64 x, y, z; };
	struct { V2 xy; f64 _0; };
	struct { f64 _1; V2 yz; };
	f64 e[3];
} V3D;

typedef struct V4D
{
	struct { f64 x, y, z, w; };
	struct { V2 xy; V2 zw; };
	struct { V3 xyz; f64 _0; };
	struct { f64 _1; V3 yzw; };
	struct { f64 _2; V2 yz; };
	f64 e[4];
} V4D;

typedef union V2S
{
	struct { s32 x, y; };
	s32 e[2];
} V2S;

typedef union V3S
{
	struct { s32 x, y, z; };
	struct { V2S xy; s32 _0; };
	struct { s32 _1; V2S yz; };
	s32 e[3];
} V3S;

typedef struct V4S
{
	struct { s32 x, y, z, w; };
	struct { V2S xy; V2S zw; };
	struct { V3S xyz; s32 _0; };
	struct { s32 _1; V3S yzw; };
	struct { s32 _2; V2S yz; };
	s32 e[4];
} V4S;

typedef union V2SD
{
	struct { s64 x, y; };
	s64 e[2];
} V2SD;

typedef union V3SD
{
	struct { s64 x, y, z; };
	struct { V2SD xy; s64 _0; };
	struct { s64 _1; V2SD yz; };
	s64 e[3];
} V3SD;

typedef struct V4SD
{
	struct { s64 x, y, z, w; };
	struct { V2SD xy; V2S zw; };
	struct { V3SD xyz; s64 _0; };
	struct { s64 _1; V3SD yzw; };
	struct { s64 _2; V2SD yz; };
	s64 e[4];
} V4SD;

typedef struct Rect
{
	V2 min;
	V2 max;
} Rect;

typedef struct Cuboid
{
	V3 min;
	V3 max;
} Cuboid;

typedef struct RectD
{
	V2D min;
	V2D max;
} RectD;

typedef struct CuboidD
{
	V3D min;
	V3D max;
} CuboidD;

typedef struct RectS
{
	V2S min;
	V2S max;
} RectS;

typedef struct CuboidS
{
	V3S min;
	V3S max;
} CuboidS;

typedef struct RectSD
{
	V2SD min;
	V2SD max;
} RectSD;

typedef struct CuboidSD
{
	V3SD min;
	V3SD max;
} CuboidSD;

typedef union M2
{
	V2 row[2];
	f32 e[4];
} M2;

typedef union M3
{
	V3 row[3];
	f32 e[9];
} M3;

typedef union M4
{
	V4 row[4];
	f32 e[16];
} M4;

typedef union M2D
{
	V2D row[2];
	f64 e[4];
} M2D;

typedef union M3D
{
	V3D row[3];
	f64 e[9];
} M3D;

typedef union M4D
{
	V4D row[4];
	f64 e[16];
} M4D;

#define V2(X, Y)         (V2){ .x = (X), .y = (Y) }
#define V3(X, Y, Z)      (V3){ .x = (X), .y = (Y), .z = (Z) }
#define V4(X, Y, Z, W)   (V4){ .x = (X), .y = (Y), .z = (Z), .w = (W) }
#define V2D(X, Y)        (V2D){ .x = (X), .y = (Y) }
#define V3D(X, Y, Z)     (V3D){ .x = (X), .y = (Y), .z = (Z) }
#define V4D(X, Y, Z, W)  (V4D){ .x = (X), .y = (Y), .z = (Z), .w = (W) }
#define V2S(X, Y)        (V2S){ .x = (X), .y = (Y) }
#define V3S(X, Y, Z)     (V3S){ .x = (X), .y = (Y), .z = (Z) }
#define V4S(X, Y, Z, W)  (V4S){ .x = (X), .y = (Y), .z = (Z), .w = (W) }
#define V2SD(X, Y)       (V2SD){ .x = (X), .y = (Y) }
#define V3SD(X, Y, Z)    (V3SD){ .x = (X), .y = (Y), .z = (Z) }
#define V4SD(X, Y, Z, W) (V4SD){ .x = (X), .y = (Y), .z = (Z), .w = (W) }

#define Rect(MINV, MAXV)          (Rect)       { .min = (MINV), .max = (MAXV) }
#define Cuboid(MINV, MAXV)        (Cuboid)     { .min = (MINV), .max = (MAXV) }
#define Hypercuboid(MINV, MAXV)   (Hypercuboid){ .min = (MINV), .max = (MAXV) }
#define RectD(MINV, MAXV)         (RectD)       { .min = (MINV), .max = (MAXV) }
#define CuboidD(MINV, MAXV)       (CuboidD)     { .min = (MINV), .max = (MAXV) }
#define HypercuboidD(MINV, MAXV)  (HypercuboidD){ .min = (MINV), .max = (MAXV) }
#define RectS(MINV, MAXV)         (RectS)       { .min = (MINV), .max = (MAXV) }
#define CuboidS(MINV, MAXV)       (CuboidS)     { .min = (MINV), .max = (MAXV) }
#define HypercuboidS(MINV, MAXV)  (HypercuboidS){ .min = (MINV), .max = (MAXV) }
#define RectSD(MINV, MAXV)         (RectSD)       { .min = (MINV), .max = (MAXV) }
#define CuboidSD(MINV, MAXV)       (CuboidSD)     { .min = (MINV), .max = (MAXV) }

#define M2(R0, R1)           (M2){ .row = { [0] = (R0), [1] = (R1) } }
#define M3(R0, R1, R2)       (M3){ .row = { [0] = (R0), [1] = (R1), [2] = (R2) } }
#define M4(R0, R1, R2, R3)   (M4){ .row = { [0] = (R0), [1] = (R1), [2] = (R2), [3] = (R3) } }
#define M2D(R0, R1)          (M2D){ .row = { [0] = (R0), [1] = (R1) } }
#define M3D(R0, R1, R2)      (M3D){ .row = { [0] = (R0), [1] = (R1), [2] = (R2) } }
#define M4D(R0, R1, R2, R3)  (M4D){ .row = { [0] = (R0), [1] = (R1), [2] = (R2), [3] = (R3) } }

V2   V2_Set1       (f32 n)              { return V2(n, n);                                                                                }
V3   V3_Set1       (f32 n)              { return V3(n, n, n);                                                                             }
V4   V4_Set1       (f32 n)              { return V4(n, n, n, n);                                                                          }
V2D  V2D_Set1      (f64 n)              { return V2D(n, n);                                                                               }
V3D  V3D_Set1      (f64 n)              { return V3D(n, n, n);                                                                            }
V4D  V4D_Set1      (f64 n)              { return V4D(n, n, n, n);                                                                         }
V2S  V2S_Set1      (s32 n)              { return V2S(n, n);                                                                               }
V3S  V3S_Set1      (s32 n)              { return V3S(n, n, n);                                                                            }
V4S  V4S_Set1      (s32 n)              { return V4S(n, n, n, n);                                                                         }
V2SD V2SD_Set1     (s64 n)              { return V2SD(n, n);                                                                              }
V3SD V3SD_Set1     (s64 n)              { return V3SD(n, n, n);                                                                           }
V4SD V4SD_Set1     (s64 n)              { return V4SD(n, n, n, n);                                                                        }
V2   V2_FromV2S    (V2S v)              { return V2((f32)v.x, (f32)v.y);                                                                  }
V3   V3_FromV3S    (V3S v)              { return V3((f32)v.x, (f32)v.y, (f32)v.z);                                                        }
V4   V4_FromV4S    (V4S v)              { return V4((f32)v.x, (f32)v.y, (f32)v.z, (f32)v.w);                                              }
V2D  V2D_FromV2S   (V2S v)              { return V2D((f64)v.x, (f64)v.y);                                                                 }
V3D  V3D_FromV3S   (V3S v)              { return V3D((f64)v.x, (f64)v.y, (f64)v.z);                                                       }
V4D  V4D_FromV4S   (V4S v)              { return V4D((f64)v.x, (f64)v.y, (f64)v.z, (f64)v.w);                                             }
V2D  V2D_FromV2SD  (V2SD v)             { return V2D((f64)v.x, (f64)v.y);                                                                 }
V3D  V3D_FromV3SD  (V3SD v)             { return V3D((f64)v.x, (f64)v.y, (f64)v.z);                                                       }
V4D  V4D_FromV4SD  (V4SD v)             { return V4D((f64)v.x, (f64)v.y, (f64)v.z, (f64)v.w);                                             }
V2S  V2S_FromV2    (V2 v)               { return V2S((s32)v.x, (s32)v.y);                                                                 }
V3S  V3S_FromV3    (V3 v)               { return V3S((s32)v.x, (s32)v.y, (s32)v.z);                                                       }
V4S  V4S_FromV4    (V4 v)               { return V4S((s32)v.x, (s32)v.y, (s32)v.z, (s32)v.w);                                             }
V2SD V2SD_FromV2   (V2 v)               { return V2SD((s64)v.x, (s64)v.y);                                                                }
V3SD V3SD_FromV3   (V3 v)               { return V3SD((s64)v.x, (s64)v.y, (s64)v.z);                                                      }
V4SD V4SD_FromV4   (V4 v)               { return V4SD((s64)v.x, (s64)v.y, (s64)v.z, (s64)v.w);                                            }
V2SD V2SD_FromV2D  (V2D v)              { return V2SD((s64)v.x, (s64)v.y);                                                                }
V3SD V3SD_FromV3D  (V3D v)              { return V3SD((s64)v.x, (s64)v.y, (s64)v.z);                                                      }
V4SD V4SD_FromV4D  (V4D v)              { return V4SD((s64)v.x, (s64)v.y, (s64)v.z, (s64)v.w);                                            }
V2SD V2SD_FromV2S  (V2S v)              { return V2SD((s64)v.x, (s64)v.y);                                                                }
V3SD V3SD_FromV3S  (V3S v)              { return V3SD((s64)v.x, (s64)v.y, (s64)v.z);                                                      }
V4SD V4SD_FromV4S  (V4S v)              { return V4SD((s64)v.x, (s64)v.y, (s64)v.z, (s64)v.w);                                            }
V2   V2_Add        (V2 v0, V2 v1)       { return V2(v0.x + v1.x, v0.y + v1.y);                                                            }
V3   V3_Add        (V3 v0, V3 v1)       { return V3(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z);                                               }
V4   V4_Add        (V4 v0, V4 v1)       { return V4(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z, v0.w + v1.w);                                  }
V2D  V2D_Add       (V2D v0, V2D v1)     { return V2D(v0.x + v1.x, v0.y + v1.y);                                                           }
V3D  V3D_Add       (V3D v0, V3D v1)     { return V3D(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z);                                              }
V4D  V4D_Add       (V4D v0, V4D v1)     { return V4D(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z, v0.w + v1.w);                                 }
V2S  V2S_Add       (V2S v0, V2S v1)     { return V2S(v0.x + v1.x, v0.y + v1.y);                                                           }
V3S  V3S_Add       (V3S v0, V3S v1)     { return V3S(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z);                                              }
V4S  V4S_Add       (V4S v0, V4S v1)     { return V4S(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z, v0.w + v1.w);                                 }
V2SD V2SD_Add      (V2SD v0, V2SD v1)   { return V2SD(v0.x + v1.x, v0.y + v1.y);                                                          }
V3SD V3SD_Add      (V3SD v0, V3SD v1)   { return V3SD(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z);                                             }
V4SD V4SD_Add      (V4SD v0, V4SD v1)   { return V4SD(v0.x + v1.x, v0.y + v1.y, v0.z + v1.z, v0.w + v1.w);                                }
V2   V2_Sub        (V2 v0, V2 v1)       { return V2(v0.x - v1.x, v0.y - v1.y);                                                            }
V3   V3_Sub        (V3 v0, V3 v1)       { return V3(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z);                                               }
V4   V4_Sub        (V4 v0, V4 v1)       { return V4(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z, v0.w - v1.w);                                  }
V2D  V2D_Sub       (V2D v0, V2D v1)     { return V2D(v0.x - v1.x, v0.y - v1.y);                                                           }
V3D  V3D_Sub       (V3D v0, V3D v1)     { return V3D(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z);                                              }
V4D  V4D_Sub       (V4D v0, V4D v1)     { return V4D(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z, v0.w - v1.w);                                 }
V2S  V2S_Sub       (V2S v0, V2S v1)     { return V2S(v0.x - v1.x, v0.y - v1.y);                                                           }
V3S  V3S_Sub       (V3S v0, V3S v1)     { return V3S(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z);                                              }
V4S  V4S_Sub       (V4S v0, V4S v1)     { return V4S(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z, v0.w - v1.w);                                 }
V2SD V2SD_Sub      (V2SD v0, V2SD v1)   { return V2SD(v0.x - v1.x, v0.y - v1.y);                                                          }
V3SD V3SD_Sub      (V3SD v0, V3SD v1)   { return V3SD(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z);                                             }
V4SD V4SD_Sub      (V4SD v0, V4SD v1)   { return V4SD(v0.x - v1.x, v0.y - v1.y, v0.z - v1.z, v0.w - v1.w);                                }
V2   V2_Hadamard   (V2 v0, V2 v1)       { return V2(v0.x*v1.x, v0.y*v1.y);                                                                }
V3   V3_Hadamard   (V3 v0, V3 v1)       { return V3(v0.x*v1.x, v0.y*v1.y, v0.z*v1.z);                                                     }
V4   V4_Hadamard   (V4 v0, V4 v1)       { return V4(v0.x*v1.x, v0.y*v1.y, v0.z*v1.z, v0.w*v1.w);                                          }
V2D  V2D_Hadamard  (V2D v0, V2D v1)     { return V2D(v0.x*v1.x, v0.y*v1.y);                                                               }
V3D  V3D_Hadamard  (V3D v0, V3D v1)     { return V3D(v0.x*v1.x, v0.y*v1.y, v0.z*v1.z);                                                    }
V4D  V4D_Hadamard  (V4D v0, V4D v1)     { return V4D(v0.x*v1.x, v0.y*v1.y, v0.z*v1.z, v0.w*v1.w);                                         }
V2S  V2S_Hadamard  (V2S v0, V2S v1)     { return V2S(v0.x*v1.x, v0.y*v1.y);                                                               }
V3S  V3S_Hadamard  (V3S v0, V3S v1)     { return V3S(v0.x*v1.x, v0.y*v1.y, v0.z*v1.z);                                                    }
V4S  V4S_Hadamard  (V4S v0, V4S v1)     { return V4S(v0.x*v1.x, v0.y*v1.y, v0.z*v1.z, v0.w*v1.w);                                         }
V2SD V2SD_Hadamard (V2SD v0, V2SD v1)   { return V2SD(v0.x*v1.x, v0.y*v1.y);                                                              }
V3SD V3SD_Hadamard (V3SD v0, V3SD v1)   { return V3SD(v0.x*v1.x, v0.y*v1.y, v0.z*v1.z);                                                   }
V4SD V4SD_Hadamard (V4SD v0, V4SD v1)   { return V4SD(v0.x*v1.x, v0.y*v1.y, v0.z*v1.z, v0.w*v1.w);                                        }
V2   V2_Scale      (V2 v0, f32 n)       { return V2(v0.x*n, v0.y*n);                                                                      }
V3   V3_Scale      (V3 v0, f32 n)       { return V3(v0.x*n, v0.y*n, v0.z*n);                                                              }
V4   V4_Scale      (V4 v0, f32 n)       { return V4(v0.x*n, v0.y*n, v0.z*n, v0.w*n);                                                      }
V2D  V2D_Scale     (V2D v0, f64 n)      { return V2D(v0.x*n, v0.y*n);                                                                     }
V3D  V3D_Scale     (V3D v0, f64 n)      { return V3D(v0.x*n, v0.y*n, v0.z*n);                                                             }
V4D  V4D_Scale     (V4D v0, f64 n)      { return V4D(v0.x*n, v0.y*n, v0.z*n, v0.w*n);                                                     }
V2S  V2S_Scale     (V2S v0, s32 n)      { return V2S(v0.x*n, v0.y*n);                                                                     }
V3S  V3S_Scale     (V3S v0, s32 n)      { return V3S(v0.x*n, v0.y*n, v0.z*n);                                                             }
V4S  V4S_Scale     (V4S v0, s32 n)      { return V4S(v0.x*n, v0.y*n, v0.z*n, v0.w*n);                                                     }
V2SD V2SD_Scale    (V2SD v0, s64 n)     { return V2SD(v0.x*n, v0.y*n);                                                                    }
V3SD V3SD_Scale    (V3SD v0, s64 n)     { return V3SD(v0.x*n, v0.y*n, v0.z*n);                                                            }
V4SD V4SD_Scale    (V4SD v0, s64 n)     { return V4SD(v0.x*n, v0.y*n, v0.z*n, v0.w*n);                                                    }
V2S  V2S_InvScale  (V2S v0, s32 n)      { return V2S(v0.x/n, v0.y/n);                                                                     }
V3S  V3S_InvScale  (V3S v0, s32 n)      { return V3S(v0.x/n, v0.y/n, v0.z/n);                                                             }
V4S  V4S_InvScale  (V4S v0, s32 n)      { return V4S(v0.x/n, v0.y/n, v0.z/n, v0.w/n);                                                     }
V2SD V2SD_InvScale (V2SD v0, s64 n)     { return V2SD(v0.x/n, v0.y/n);                                                                    }
V3SD V3SD_InvScale (V3SD v0, s64 n)     { return V3SD(v0.x/n, v0.y/n, v0.z/n);                                                            }
V4SD V4SD_InvScale (V4SD v0, s64 n)     { return V4SD(v0.x/n, v0.y/n, v0.z/n, v0.w/n);                                                    }
f32  V2_Inner    (V2 v0, V2 v1)         { return v0.x*v1.x + v0.y*v1.y;                                                                   }
f32  V3_Inner    (V3 v0, V3 v1)         { return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z;                                                       }
f32  V4_Inner    (V4 v0, V4 v1)         { return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z + v0.w*v1.w;                                           }
f64  V2D_Inner   (V2D v0, V2D v1)       { return v0.x*v1.x + v0.y*v1.y;                                                                   }
f64  V3D_Inner   (V3D v0, V3D v1)       { return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z;                                                       }
f64  V4D_Inner   (V4D v0, V4D v1)       { return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z + v0.w*v1.w;                                           }
s32  V2S_Inner   (V2S v0, V2S v1)       { return v0.x*v1.x + v0.y*v1.y;                                                                   }
s32  V3S_Inner   (V3S v0, V3S v1)       { return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z;                                                       }
s32  V4S_Inner   (V4S v0, V4S v1)       { return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z + v0.w*v1.w;                                           }
s64  V2SD_Inner  (V2SD v0, V2SD v1)     { return v0.x*v1.x + v0.y*v1.y;                                                                   }
s64  V3SD_Inner  (V3SD v0, V3SD v1)     { return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z;                                                       }
s64  V4SD_Inner  (V4SD v0, V4SD v1)     { return v0.x*v1.x + v0.y*v1.y + v0.z*v1.z + v0.w*v1.w;                                           }
V3   V3_Cross    (V3 v0, V3 v1)         { return V3(v0.y*v1.z - v0.z*v1.y, v0.z*v1.x - v0.x*v1.z, v0.x*v1.y - v0.y*v1.x);                 }
V3D  V3D_Cross   (V3D v0, V3D v1)       { return V3D(v0.y*v1.z - v0.z*v1.y, v0.z*v1.x - v0.x*v1.z, v0.x*v1.y - v0.y*v1.x);                }
V3S  V3S_Cross   (V3S v0, V3S v1)       { return V3S(v0.y*v1.z - v0.z*v1.y, v0.z*v1.x - v0.x*v1.z, v0.x*v1.y - v0.y*v1.x);                }
V3SD V3SD_Cross  (V3SD v0, V3SD v1)     { return V3SD(v0.y*v1.z - v0.z*v1.y, v0.z*v1.x - v0.x*v1.z, v0.x*v1.y - v0.y*v1.x);               }
M2   V2_Outer    (V2 v0, V2 v1)         { return M2(V2_Scale(v1, v0.x), V2_Scale(v1, v0.y));                                              }
M3   V3_Outer    (V3 v0, V3 v1)         { return M3(V3_Scale(v1, v0.x), V3_Scale(v1, v0.y), V3_Scale(v1, v0.z));                          }
M4   V4_Outer    (V4 v0, V4 v1)         { return M4(V4_Scale(v1, v0.x), V4_Scale(v1, v0.y), V4_Scale(v1, v0.z), V4_Scale(v1, v0.w));      }
M2D  V2D_Outer   (V2D v0, V2D v1)       { return M2D(V2D_Scale(v1, v0.x), V2D_Scale(v1, v0.y));                                           }
M3D  V3D_Outer   (V3D v0, V3D v1)       { return M3D(V3D_Scale(v1, v0.x), V3D_Scale(v1, v0.y), V3D_Scale(v1, v0.z));                      }
M4D  V4D_Outer   (V4D v0, V4D v1)       { return M4D(V4D_Scale(v1, v0.x), V4D_Scale(v1, v0.y), V4D_Scale(v1, v0.z), V4D_Scale(v1, v0.w)); }
V2   V2_Abs      (V2 v)                 { return V2(ABS(v.x), ABS(v.y));                                                                  }
V3   V3_Abs      (V3 v)                 { return V3(ABS(v.x), ABS(v.y), ABS(v.z));                                                        }
V4   V4_Abs      (V4 v)                 { return V4(ABS(v.x), ABS(v.y), ABS(v.z), ABS(v.w));                                              }
V2D  V2D_Abs     (V2D v)                { return V2D(ABS(v.x), ABS(v.y));                                                                 }
V3D  V3D_Abs     (V3D v)                { return V3D(ABS(v.x), ABS(v.y), ABS(v.z));                                                       }
V4D  V4D_Abs     (V4D v)                { return V4D(ABS(v.x), ABS(v.y), ABS(v.z), ABS(v.w));                                             }
V2S  V2S_Abs     (V2S v)                { return V2S(ABS(v.x), ABS(v.y));                                                                 }
V3S  V3S_Abs     (V3S v)                { return V3S(ABS(v.x), ABS(v.y), ABS(v.z));                                                       }
V4S  V4S_Abs     (V4S v)                { return V4S(ABS(v.x), ABS(v.y), ABS(v.z), ABS(v.w));                                             }
V2SD V2SD_Abs    (V2SD v)               { return V2SD(ABS(v.x), ABS(v.y));                                                                }
V3SD V3SD_Abs    (V3SD v)               { return V3SD(ABS(v.x), ABS(v.y), ABS(v.z));                                                      }
V4SD V4SD_Abs    (V4SD v)               { return V4SD(ABS(v.x), ABS(v.y), ABS(v.z), ABS(v.w));                                            }
V2   V2_Min      (V2 v0, V2 v1)         { return V2(MIN(v0.x, v1.x), MIN(v0.y, v1.y));                                                    }
V3   V3_Min      (V3 v0, V3 v1)         { return V3(MIN(v0.x, v1.x), MIN(v0.y, v1.y), MIN(v0.z, v1.z));                                   }
V4   V4_Min      (V4 v0, V4 v1)         { return V4(MIN(v0.x, v1.x), MIN(v0.y, v1.y), MIN(v0.z, v1.z), MIN(v0.w, v1.w));                  }
V2D  V2D_Min     (V2D v0, V2D v1)       { return V2D(MIN(v0.x, v1.x), MIN(v0.y, v1.y));                                                   }
V3D  V3D_Min     (V3D v0, V3D v1)       { return V3D(MIN(v0.x, v1.x), MIN(v0.y, v1.y), MIN(v0.z, v1.z));                                  }
V4D  V4D_Min     (V4D v0, V4D v1)       { return V4D(MIN(v0.x, v1.x), MIN(v0.y, v1.y), MIN(v0.z, v1.z), MIN(v0.w, v1.w));                 }
V2S  V2S_Min     (V2S v0, V2S v1)       { return V2S(MIN(v0.x, v1.x), MIN(v0.y, v1.y));                                                   }
V3S  V3S_Min     (V3S v0, V3S v1)       { return V3S(MIN(v0.x, v1.x), MIN(v0.y, v1.y), MIN(v0.z, v1.z));                                  }
V4S  V4S_Min     (V4S v0, V4S v1)       { return V4S(MIN(v0.x, v1.x), MIN(v0.y, v1.y), MIN(v0.z, v1.z), MIN(v0.w, v1.w));                 }
V2SD V2SD_Min    (V2SD v0, V2SD v1)     { return V2SD(MIN(v0.x, v1.x), MIN(v0.y, v1.y));                                                  }
V3SD V3SD_Min    (V3SD v0, V3SD v1)     { return V3SD(MIN(v0.x, v1.x), MIN(v0.y, v1.y), MIN(v0.z, v1.z));                                 }
V4SD V4SD_Min    (V4SD v0, V4SD v1)     { return V4SD(MIN(v0.x, v1.x), MIN(v0.y, v1.y), MIN(v0.z, v1.z), MIN(v0.w, v1.w));                }
V2   V2_Max      (V2 v0, V2 v1)         { return V2(MAX(v0.x, v1.x), MAX(v0.y, v1.y));                                                    }
V3   V3_Max      (V3 v0, V3 v1)         { return V3(MAX(v0.x, v1.x), MAX(v0.y, v1.y), MAX(v0.z, v1.z));                                   }
V4   V4_Max      (V4 v0, V4 v1)         { return V4(MAX(v0.x, v1.x), MAX(v0.y, v1.y), MAX(v0.z, v1.z), MAX(v0.w, v1.w));                  }
V2D  V2D_Max     (V2D v0, V2D v1)       { return V2D(MAX(v0.x, v1.x), MAX(v0.y, v1.y));                                                   }
V3D  V3D_Max     (V3D v0, V3D v1)       { return V3D(MAX(v0.x, v1.x), MAX(v0.y, v1.y), MAX(v0.z, v1.z));                                  }
V4D  V4D_Max     (V4D v0, V4D v1)       { return V4D(MAX(v0.x, v1.x), MAX(v0.y, v1.y), MAX(v0.z, v1.z), MAX(v0.w, v1.w));                 }
V2S  V2S_Max     (V2S v0, V2S v1)       { return V2S(MAX(v0.x, v1.x), MAX(v0.y, v1.y));                                                   }
V3S  V3S_Max     (V3S v0, V3S v1)       { return V3S(MAX(v0.x, v1.x), MAX(v0.y, v1.y), MAX(v0.z, v1.z));                                  }
V4S  V4S_Max     (V4S v0, V4S v1)       { return V4S(MAX(v0.x, v1.x), MAX(v0.y, v1.y), MAX(v0.z, v1.z), MAX(v0.w, v1.w));                 }
V2SD V2SD_Max    (V2SD v0, V2SD v1)     { return V2SD(MAX(v0.x, v1.x), MAX(v0.y, v1.y));                                                  }
V3SD V3SD_Max    (V3SD v0, V3SD v1)     { return V3SD(MAX(v0.x, v1.x), MAX(v0.y, v1.y), MAX(v0.z, v1.z));                                 }
V4SD V4SD_Max    (V4SD v0, V4SD v1)     { return V4SD(MAX(v0.x, v1.x), MAX(v0.y, v1.y), MAX(v0.z, v1.z), MAX(v0.w, v1.w));                }

Rect
Rect_FromCenterDim(V2 center, V2 dim)
{
	V2 hdim = V2_Scale(dim, 0.5f);
	return Rect(V2_Sub(center, hdim), V2_Add(center, hdim));
}

Cuboid
Cuboid_FromCenterDim(V3 center, V3 dim)
{
	V3 hdim = V3_Scale(dim, 0.5f);
	return Cuboid(V3_Sub(center, hdim), V3_Add(center, hdim));
}

RectD
RectD_FromCenterDim(V2D center, V2D dim)
{
	V2D hdim = V2D_Scale(dim, 0.5f);
	return RectD(V2D_Sub(center, hdim), V2D_Add(center, hdim));
}

CuboidD
CuboidD_FromCenterDim(V3D center, V3D dim)
{
	V3D hdim = V3D_Scale(dim, 0.5f);
	return CuboidD(V3D_Sub(center, hdim), V3D_Add(center, hdim));
}

RectS
RectS_FromCenterDim(V2S center, V2S dim)
{
	V2S hdim = V2S_InvScale(dim, 2);
	return RectS(V2S_Sub(center, hdim), V2S_Add(center, hdim));
}

CuboidS
CuboidS_FromCenterDim(V3S center, V3S dim)
{
	V3S hdim = V3S_InvScale(dim, 2);
	return CuboidS(V3S_Sub(center, hdim), V3S_Add(center, hdim));
}

RectSD
RectSD_FromCenterDim(V2SD center, V2SD dim)
{
	V2SD hdim = V2SD_InvScale(dim, 2);
	return RectSD(V2SD_Sub(center, hdim), V2SD_Add(center, hdim));
}

CuboidSD
CuboidSD_FromCenterDim(V3SD center, V3SD dim)
{
	V3SD hdim = V3SD_InvScale(dim, 2);
	return CuboidSD(V3SD_Sub(center, hdim), V3SD_Add(center, hdim));
}

bool
Rect_ContainsPoint(Rect r, V2 v)
{
	return (v.x >= r.min.x && v.x <= r.max.x &&
					v.y >= r.min.y && v.y <= r.max.y);
}

bool
Cuboid_ContainsPoint(Cuboid c, V3 v)
{
	return (v.x >= c.min.x && v.x <= c.max.x &&
					v.y >= c.min.y && v.y <= c.max.y &&
					v.z >= c.min.z && v.z <= c.max.z);
}

bool
RectD_ContainsPoint(RectD r, V2D v)
{
	return (v.x >= r.min.x && v.x <= r.max.x &&
					v.y >= r.min.y && v.y <= r.max.y);
}

bool
CuboidD_ContainsPoint(CuboidD c, V3D v)
{
	return (v.x >= c.min.x && v.x <= c.max.x &&
					v.y >= c.min.y && v.y <= c.max.y &&
					v.z >= c.min.z && v.z <= c.max.z);
}

bool
RectS_ContainsPoint(RectS r, V2S v)
{
	return (v.x >= r.min.x && v.x <= r.max.x &&
					v.y >= r.min.y && v.y <= r.max.y);
}

bool
CuboidS_ContainsPoint(CuboidS c, V3S v)
{
	return (v.x >= c.min.x && v.x <= c.max.x &&
					v.y >= c.min.y && v.y <= c.max.y &&
					v.z >= c.min.z && v.z <= c.max.z);
}

bool
RectSD_ContainsPoint(RectSD r, V2SD v)
{
	return (v.x >= r.min.x && v.x <= r.max.x &&
					v.y >= r.min.y && v.y <= r.max.y);
}

bool
CuboidSD_ContainsPoint(CuboidSD c, V3SD v)
{
	return (v.x >= c.min.x && v.x <= c.max.x &&
					v.y >= c.min.y && v.y <= c.max.y &&
					v.z >= c.min.z && v.z <= c.max.z);
}

#define M2_Row(M, N) ((M).row[N])
#define M3_Row(M, N) ((M).row[N])
#define M4_Row(M, N) ((M).row[N])
#define M2D_Row(M, N) ((M).row[N])
#define M3D_Row(M, N) ((M).row[N])
#define M4D_Row(M, N) ((M).row[N])

#define M2_Col(M, N) (V2((M).row[0].e[N], (M).row[1].e[N]))
#define M3_Col(M, N) (V3((M).row[0].e[N], (M).row[1].e[N], (M).row[2].e[N]))
#define M4_Col(M, N) (V4((M).row[0].e[N], (M).row[1].e[N], (M).row[2].e[N], (M).row[3].e[N]))
#define M2D_Col(M, N) (V2D((M).row[0].e[N], (M).row[1].e[N]))
#define M3D_Col(M, N) (V3D((M).row[0].e[N], (M).row[1].e[N], (M).row[2].e[N]))
#define M4D_Col(M, N) (V4D((M).row[0].e[N], (M).row[1].e[N], (M).row[2].e[N], (M).row[3].e[N]))

#define M2_E(M, R, C) ((M).row[R].e[C])
#define M3_E(M, R, C) ((M).row[R].e[C])
#define M4_E(M, R, C) ((M).row[R].e[C])
#define M2D_E(M, R, C) ((M).row[R].e[C])
#define M3D_E(M, R, C) ((M).row[R].e[C])
#define M4D_E(M, R, C) ((M).row[R].e[C])

M2
M2_FromCols(V2 c0, V2 c1)
{
	return M2(V2(c0.x, c1.x),
						V2(c0.y, c1.y));
}

M3
M3_FromCols(V3 c0, V3 c1, V3 c2)
{
	return M3(V3(c0.x, c1.x, c2.x),
						V3(c0.y, c1.y, c2.y),
						V3(c0.z, c1.z, c2.z));
}

M4
M4_FromCols(V4 c0, V4 c1, V4 c2, V4 c3)
{
	return M4(V4(c0.x, c1.x, c2.x, c3.x),
						V4(c0.y, c1.y, c2.y, c3.y),
						V4(c0.z, c1.z, c2.z, c3.z),
						V4(c0.w, c1.w, c2.w, c3.w));
}

M2D
M2D_FromCols(V2D c0, V2D c1)
{
	return M2D(V2D(c0.x, c1.x),
						 V2D(c0.y, c1.y));
}

M3D
M3D_FromCols(V3D c0, V3D c1, V3D c2)
{
	return M3D(V3D(c0.x, c1.x, c2.x),
						 V3D(c0.y, c1.y, c2.y),
						 V3D(c0.z, c1.z, c2.z));
}

M4D
M4D_FromCols(V4D c0, V4D c1, V4D c2, V4D c3)
{
	return M4D(V4D(c0.x, c1.x, c2.x, c3.x),
						 V4D(c0.y, c1.y, c2.y, c3.y),
						 V4D(c0.z, c1.z, c2.z, c3.z),
						 V4D(c0.w, c1.w, c2.w, c3.w));
}

M2
M2_Transpose(M2 m)
{
	return M2(M2_Col(m, 0),
						M2_Col(m, 1));
}

M3
M3_Transpose(M3 m)
{
	return M3(M3_Col(m, 0),
						M3_Col(m, 1),
						M3_Col(m, 2));
}

M4
M4_Transpose(M4 m)
{
	return M4(M4_Col(m, 0),
						M4_Col(m, 1),
						M4_Col(m, 2),
						M4_Col(m, 3));
}

M2D
M2D_Transpose(M2D m)
{
	return M2D(M2D_Col(m, 0),
						 M2D_Col(m, 1));
}

M3D
M3D_Transpose(M3D m)
{
	return M3D(M3D_Col(m, 0),
						 M3D_Col(m, 1),
						 M3D_Col(m, 2));
}

M4D
M4D_Transpose(M4D m)
{
	return M4D(M4D_Col(m, 0),
						 M4D_Col(m, 1),
						 M4D_Col(m, 2),
						 M4D_Col(m, 3));
}

M2
M2_Add(M2 m0, M2 m1)
{
	return M2(V2_Add(M2_Row(m0, 0), M2_Row(m1, 0)),
						V2_Add(M2_Row(m0, 1), M2_Row(m1, 1)));
}

M3
M3_Add(M3 m0, M3 m1)
{
	return M3(V3_Add(M3_Row(m0, 0), M3_Row(m1, 0)),
						V3_Add(M3_Row(m0, 1), M3_Row(m1, 1)),
						V3_Add(M3_Row(m0, 2), M3_Row(m1, 2)));
}

M4
M4_Add(M4 m0, M4 m1)
{
	return M4(V4_Add(M4_Row(m0, 0), M4_Row(m1, 0)),
						V4_Add(M4_Row(m0, 1), M4_Row(m1, 1)),
						V4_Add(M4_Row(m0, 2), M4_Row(m1, 2)),
						V4_Add(M4_Row(m0, 3), M4_Row(m1, 3)));
}

M2D
M2D_Add(M2D m0, M2D m1)
{
	return M2D(V2D_Add(M2D_Row(m0, 0), M2D_Row(m1, 0)),
						 V2D_Add(M2D_Row(m0, 1), M2D_Row(m1, 1)));
}

M3D
M3D_Add(M3D m0, M3D m1)
{
	return M3D(V3D_Add(M3D_Row(m0, 0), M3D_Row(m1, 0)),
						 V3D_Add(M3D_Row(m0, 1), M3D_Row(m1, 1)),
						 V3D_Add(M3D_Row(m0, 2), M3D_Row(m1, 2)));
}

M4D
M4D_Add(M4D m0, M4D m1)
{
	return M4D(V4D_Add(M4D_Row(m0, 0), M4D_Row(m1, 0)),
						 V4D_Add(M4D_Row(m0, 1), M4D_Row(m1, 1)),
						 V4D_Add(M4D_Row(m0, 2), M4D_Row(m1, 2)),
						 V4D_Add(M4D_Row(m0, 3), M4D_Row(m1, 3)));
}

M2
M2_Sub(M2 m0, M2 m1)
{
	return M2(V2_Sub(M2_Row(m0, 0), M2_Row(m1, 0)),
						V2_Sub(M2_Row(m0, 1), M2_Row(m1, 1)));
}

M3
M3_Sub(M3 m0, M3 m1)
{
	return M3(V3_Sub(M3_Row(m0, 0), M3_Row(m1, 0)),
						V3_Sub(M3_Row(m0, 1), M3_Row(m1, 1)),
						V3_Sub(M3_Row(m0, 2), M3_Row(m1, 2)));
}

M4
M4_Sub(M4 m0, M4 m1)
{
	return M4(V4_Sub(M4_Row(m0, 0), M4_Row(m1, 0)),
						V4_Sub(M4_Row(m0, 1), M4_Row(m1, 1)),
						V4_Sub(M4_Row(m0, 2), M4_Row(m1, 2)),
						V4_Sub(M4_Row(m0, 3), M4_Row(m1, 3)));
}

M2D
M2D_Sub(M2D m0, M2D m1)
{
	return M2D(V2D_Sub(M2D_Row(m0, 0), M2D_Row(m1, 0)),
						 V2D_Sub(M2D_Row(m0, 1), M2D_Row(m1, 1)));
}

M3D
M3D_Sub(M3D m0, M3D m1)
{
	return M3D(V3D_Sub(M3D_Row(m0, 0), M3D_Row(m1, 0)),
						 V3D_Sub(M3D_Row(m0, 1), M3D_Row(m1, 1)),
						 V3D_Sub(M3D_Row(m0, 2), M3D_Row(m1, 2)));
}

M4D
M4D_Sub(M4D m0, M4D m1)
{
	return M4D(V4D_Sub(M4D_Row(m0, 0), M4D_Row(m1, 0)),
						 V4D_Sub(M4D_Row(m0, 1), M4D_Row(m1, 1)),
						 V4D_Sub(M4D_Row(m0, 2), M4D_Row(m1, 2)),
						 V4D_Sub(M4D_Row(m0, 3), M4D_Row(m1, 3)));
}

M2
M2_Hadamard(M2 m0, M2 m1)
{
	return M2(V2_Hadamard(M2_Row(m0, 0), M2_Row(m1, 0)),
						V2_Hadamard(M2_Row(m0, 1), M2_Row(m1, 1)));
}

M3
M3_Hadamard(M3 m0, M3 m1)
{
	return M3(V3_Hadamard(M3_Row(m0, 0), M3_Row(m1, 0)),
						V3_Hadamard(M3_Row(m0, 1), M3_Row(m1, 1)),
						V3_Hadamard(M3_Row(m0, 2), M3_Row(m1, 2)));
}

M4
M4_Hadamard(M4 m0, M4 m1)
{
	return M4(V4_Hadamard(M4_Row(m0, 0), M4_Row(m1, 0)),
						V4_Hadamard(M4_Row(m0, 1), M4_Row(m1, 1)),
						V4_Hadamard(M4_Row(m0, 2), M4_Row(m1, 2)),
						V4_Hadamard(M4_Row(m0, 3), M4_Row(m1, 3)));
}

M2D
M2D_Hadamard(M2D m0, M2D m1)
{
	return M2D(V2D_Hadamard(M2D_Row(m0, 0), M2D_Row(m1, 0)),
						 V2D_Hadamard(M2D_Row(m0, 1), M2D_Row(m1, 1)));
}

M3D
M3D_Hadamard(M3D m0, M3D m1)
{
	return M3D(V3D_Hadamard(M3D_Row(m0, 0), M3D_Row(m1, 0)),
						 V3D_Hadamard(M3D_Row(m0, 1), M3D_Row(m1, 1)),
						 V3D_Hadamard(M3D_Row(m0, 2), M3D_Row(m1, 2)));
}

M4D
M4D_Hadamard(M4D m0, M4D m1)
{
	return M4D(V4D_Hadamard(M4D_Row(m0, 0), M4D_Row(m1, 0)),
						 V4D_Hadamard(M4D_Row(m0, 1), M4D_Row(m1, 1)),
						 V4D_Hadamard(M4D_Row(m0, 2), M4D_Row(m1, 2)),
						 V4D_Hadamard(M4D_Row(m0, 3), M4D_Row(m1, 3)));
}

M2
M2_Scale(M2 m0, f32 n)
{
	return M2(V2_Scale(M2_Row(m0, 0), n),
						V2_Scale(M2_Row(m0, 1), n));
}

M3
M3_Scale(M3 m0, f32 n)
{
	return M3(V3_Scale(M3_Row(m0, 0), n),
						V3_Scale(M3_Row(m0, 1), n),
						V3_Scale(M3_Row(m0, 2), n));
}

M4
M4_Scale(M4 m0, f32 n)
{
	return M4(V4_Scale(M4_Row(m0, 0), n),
						V4_Scale(M4_Row(m0, 1), n),
						V4_Scale(M4_Row(m0, 2), n),
						V4_Scale(M4_Row(m0, 3), n));
}

M2D
M2D_Scale(M2D m0, f64 n)
{
	return M2D(V2D_Scale(M2D_Row(m0, 0), n),
						 V2D_Scale(M2D_Row(m0, 1), n));
}

M3D
M3D_Scale(M3D m0, f64 n)
{
	return M3D(V3D_Scale(M3D_Row(m0, 0), n),
						 V3D_Scale(M3D_Row(m0, 1), n),
						 V3D_Scale(M3D_Row(m0, 2), n));
}

M4D
M4D_Scale(M4D m0, f64 n)
{
	return M4D(V4D_Scale(M4D_Row(m0, 0), n),
						 V4D_Scale(M4D_Row(m0, 1), n),
						 V4D_Scale(M4D_Row(m0, 2), n),
						 V4D_Scale(M4D_Row(m0, 3), n));
}

V2
M2_Mul(M2 m, V2 v)
{
	return V2(V2_Inner(v, M2_Row(m, 0)), V2_Inner(v, M2_Row(m, 1)));
}

V3
M3_Mul(M3 m, V3 v)
{
	return V3(V3_Inner(v, M3_Row(m, 0)), V3_Inner(v, M3_Row(m, 1)), V3_Inner(v, M3_Row(m, 2)));
}

V4
M4_Mul(M4 m, V4 v)
{
	return V4(V4_Inner(v, M4_Row(m, 0)), V4_Inner(v, M4_Row(m, 1)), V4_Inner(v, M4_Row(m, 2)), V4_Inner(v, M4_Row(m, 3)));
}

V2D
M2D_Mul(M2D m, V2D v)
{
	return V2D(V2D_Inner(v, M2D_Row(m, 0)), V2D_Inner(v, M2D_Row(m, 1)));
}

V3D
M3D_Mul(M3D m, V3D v)
{
	return V3D(V3D_Inner(v, M3D_Row(m, 0)), V3D_Inner(v, M3D_Row(m, 1)), V3D_Inner(v, M3D_Row(m, 2)));
}

V4D
M4D_Mul(M4D m, V4D v)
{
	return V4D(V4D_Inner(v, M4D_Row(m, 0)), V4D_Inner(v, M4D_Row(m, 1)), V4D_Inner(v, M4D_Row(m, 2)), V4D_Inner(v, M4D_Row(m, 3)));
}

M2
M2_Matmul(M2 m0, M2 m1)
{
	V2 c0 = M2_Col(m1, 0);
	V2 c1 = M2_Col(m1, 1);

	return M2(V2(V2_Inner(M2_Row(m0, 0), c0), V2_Inner(M2_Row(m0, 0), c1)),
						V2(V2_Inner(M2_Row(m0, 1), c0), V2_Inner(M2_Row(m0, 1), c1)));
}

M3
M3_Matmul(M3 m0, M3 m1)
{
	V3 c0 = M3_Col(m1, 0);
	V3 c1 = M3_Col(m1, 1);
	V3 c2 = M3_Col(m1, 2);

	return M3(V3(V3_Inner(M3_Row(m0, 0), c0), V3_Inner(M3_Row(m0, 0), c1), V3_Inner(M3_Row(m0, 0), c2)),
						V3(V3_Inner(M3_Row(m0, 1), c0), V3_Inner(M3_Row(m0, 1), c1), V3_Inner(M3_Row(m0, 1), c2)),
						V3(V3_Inner(M3_Row(m0, 2), c0), V3_Inner(M3_Row(m0, 2), c1), V3_Inner(M3_Row(m0, 2), c2)));
}

M4
M4_Matmul(M4 m0, M4 m1)
{
	V4 c0 = M4_Col(m1, 0);
	V4 c1 = M4_Col(m1, 1);
	V4 c2 = M4_Col(m1, 2);
	V4 c3 = M4_Col(m1, 3);

	return M4(V4(V4_Inner(M4_Row(m0, 0), c0), V4_Inner(M4_Row(m0, 0), c1), V4_Inner(M4_Row(m0, 0), c2), V4_Inner(M4_Row(m0, 0), c3)),
						V4(V4_Inner(M4_Row(m0, 1), c0), V4_Inner(M4_Row(m0, 1), c1), V4_Inner(M4_Row(m0, 1), c2), V4_Inner(M4_Row(m0, 1), c3)),
						V4(V4_Inner(M4_Row(m0, 2), c0), V4_Inner(M4_Row(m0, 2), c1), V4_Inner(M4_Row(m0, 2), c2), V4_Inner(M4_Row(m0, 2), c3)),
						V4(V4_Inner(M4_Row(m0, 3), c0), V4_Inner(M4_Row(m0, 3), c1), V4_Inner(M4_Row(m0, 3), c2), V4_Inner(M4_Row(m0, 3), c3)));
}

M2D
M2D_Matmul(M2D m0, M2D m1)
{
	V2D c0 = M2D_Col(m1, 0);
	V2D c1 = M2D_Col(m1, 1);

	return M2D(V2D(V2D_Inner(M2D_Row(m0, 0), c0), V2D_Inner(M2D_Row(m0, 0), c1)),
						 V2D(V2D_Inner(M2D_Row(m0, 1), c0), V2D_Inner(M2D_Row(m0, 1), c1)));
}

M3D
M3D_Matmul(M3D m0, M3D m1)
{
	V3D c0 = M3D_Col(m1, 0);
	V3D c1 = M3D_Col(m1, 1);
	V3D c2 = M3D_Col(m1, 2);

	return M3D(V3D(V3D_Inner(M3D_Row(m0, 0), c0), V3D_Inner(M3D_Row(m0, 0), c1), V3D_Inner(M3D_Row(m0, 0), c2)),
						 V3D(V3D_Inner(M3D_Row(m0, 1), c0), V3D_Inner(M3D_Row(m0, 1), c1), V3D_Inner(M3D_Row(m0, 1), c2)),
						 V3D(V3D_Inner(M3D_Row(m0, 2), c0), V3D_Inner(M3D_Row(m0, 2), c1), V3D_Inner(M3D_Row(m0, 2), c2)));
}

M4D
M4D_Matmul(M4D m0, M4D m1)
{
	V4D c0 = M4D_Col(m1, 0);
	V4D c1 = M4D_Col(m1, 1);
	V4D c2 = M4D_Col(m1, 2);
	V4D c3 = M4D_Col(m1, 3);

	return M4D(V4D(V4D_Inner(M4D_Row(m0,0), c0), V4D_Inner(M4D_Row(m0,0), c1), V4D_Inner(M4D_Row(m0,0), c2), V4D_Inner(M4D_Row(m0,0), c3)),
						 V4D(V4D_Inner(M4D_Row(m0,1), c0), V4D_Inner(M4D_Row(m0,1), c1), V4D_Inner(M4D_Row(m0,1), c2), V4D_Inner(M4D_Row(m0,1), c3)),
						 V4D(V4D_Inner(M4D_Row(m0,2), c0), V4D_Inner(M4D_Row(m0,2), c1), V4D_Inner(M4D_Row(m0,2), c2), V4D_Inner(M4D_Row(m0,2), c3)),
						 V4D(V4D_Inner(M4D_Row(m0,3), c0), V4D_Inner(M4D_Row(m0,3), c1), V4D_Inner(M4D_Row(m0,3), c2), V4D_Inner(M4D_Row(m0,3), c3)));
}
