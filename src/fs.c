#include "fs.h"

fs _fs_init(_u32 num_inodes, _u32 num_data) {
    fs temp;
    int i;

    temp.num_inodes = num_inodes;
    temp.num_data = num_data;
    temp.ibitmap = _bmap_init(num_inodes);
    temp.dbitmap = _bmap_init(num_data);

    for(i = 0; i < num_inodes; i++) {
        temp.inodes[i] = _inode_init(_FREE, -1, 1);
    }

    for(i = 0; i < num_data; i++) {
        temp.data[i] = _blk_init(_FREE);
    }

    _bmap_markalloc(&temp.ibitmap, FS_ROOT);
    temp.inodes[FS_ROOT] = _inode_init(_DIR, 0, 2);

    _bmap_markalloc(&temp.dbitmap, FS_ROOT);
    _blk_set_type(&temp.data[0], _DIR);

    dir_entry dot = {".", FS_ROOT};
    dir_entry dotdot = {"..", FS_ROOT};

    _blk_add_entry(&temp.data[0], dot);
    _blk_add_entry(&temp.data[0], dotdot);

}