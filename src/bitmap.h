#include "common.h"

#define MAXSIZE 4096

typedef struct {
    unsigned short size;
    char bmap[80];
} bitmap;

bitmap _bmap_init(int size);
int _bmap_alloc(bitmap *_b);
int _bmap_free(bitmap *_b, int idx);
int _bmap_markalloc(bitmap *_b, int idx);
char *_bmap_dump(bitmap *_b);