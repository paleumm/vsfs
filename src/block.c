#include "utils.c"

#define BLOCKSIZE 4096
#define MAXDIR 32

typedef enum {_DIR, _FILE, _FREE} ftype;
typedef unsigned int uint_32;

typedef struct {
    char *name;
    uint_32 inum;
} dir_entry;

typedef struct {
    ftype type;
    uint_32 dir_used;
    uint_32 max_used;
    dir_entry dir_list[MAXDIR];
    char *data;
} block;


block _blk_init(ftype type) {
    // if(type > _FREE || type < _DIR)
    //     return;
    
    block temp;
    temp.type = type;
    temp.dir_used = 0;
    temp.max_used = MAXDIR;
    temp.data = "";

    return temp;
}

dir_entry *_blk_dump(block _blk) {
    dir_entry entries[_blk.dir_used]; 
    if(_blk.type == _FREE) {
        return entries;
    } 

    if(_blk.type == _DIR) {
        int i;
        for(i = 0; i < _blk.dir_used; i++) {
            entries[i] = _blk.dir_list[i];
        }
        return entries;
    }
}

int _blk_set_type(block *_blk, ftype type) {
    if(_blk->type != _FREE) {
        return -1;
    }

    _blk->type = type;
    return 0;
}

int _blk_add_data(block *_blk, char* data) {
    if(_blk->type != _FILE) {
        return -1;
    }

    _blk->data = data;
    return 0;
}

int _blk_get_entries(block *_blk) {
    if(_blk->type != _DIR) {
        return -1;
    }

    return _blk->dir_used;
}

int _blk_add_entry(block *_blk, dir_entry entry) {
    if(_blk->type != _DIR) {
        return -1;
    }
    _blk->dir_list[_blk->dir_used++] = entry;
    return 0;
}

int _blk_del_entry(block *_blk, char* path) {
    char *dirname = get_dir_name(path);
    if(dirname == NULL) {
        return -1;
    }

    int i;
    for(i = 0; i < _blk->dir_used; i++) {
        if(strcmp(_blk->dir_list[i].name, dirname) == 0) {

        }
    }

}

/*

Data structure for DIR block; stack or LL

*/