#include "common.h"
#include "bitmap.h"
#include "block.h"
#include "inode.h"

#define NUM_INODES 256
#define NUM_DATA 4096
#define FS_ROOT 0

typedef struct {
    _u32 num_inodes;
    _u32 num_data;
    bitmap ibitmap;
    bitmap dbitmap;
    inode inodes[NUM_INODES];
    block data[NUM_DATA];
} fs;

fs _fs_init(_u32 num_inode, _u32 num_data);