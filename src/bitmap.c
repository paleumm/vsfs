#include "bitmap.h"

bitmap _bmap_init(int size) {
    bitmap temp;
    int i = 0;

    temp.size = size;
    for(i = 0; i < temp.size; i++) {
        temp.bmap[i] = 0;
    }

    return temp;
}

int _bmap_alloc(bitmap *_b) {
    int i;

    for(i = 0; i < _b->size; i++) {
        if(_b->bmap[i] == 0) {
            _b->bmap[i] = 1;
            return i;
        }
    }
    return -1;
}

int _bmap_free(bitmap *_b, int idx) {
    assert(_b->bmap[idx] == 1);
    _b->bmap[idx] = 0;
}

int _bmap_markalloc(bitmap *_b, int idx) {
    assert(_b->bmap[idx] == 0);
    _b->bmap[idx] = 1;
    return 0;
}

char *_bmap_dump(bitmap *_b) {
    return _b->bmap;
}