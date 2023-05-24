#include "block.h"

block _blk_init(ftype type) {
    assert(type == _DIR || type == _FILE || type == _FREE);
    
    block temp;
    temp.type = type; // <-- should we set this to be _FREE by default
    temp.dir_used = 0;
    temp.max_used = MAXDIR;
    temp.data = "";

    return temp;
}

int _blk_dump(dump *buf, block _blk) {
    if(_blk.type == _FREE) {
        buf->type == _FREE;
        return _FREE;
    } 

    if(_blk.type == _DIR) {
        int i;
        memcpy(buf->entry, _blk.dir_list, sizeof(_blk.dir_list));
        return _DIR;
    }

    if(_blk.type == _FILE) {
        strcpy(buf->data, _blk.data);
        return _FILE;
    }

    return -1;
}

int _blk_set_type(block *_blk, ftype type) {
    assert(_blk->type == _FREE);
    _blk->type = type;
    return 0;
}

int _blk_add_data(block *_blk, char* data) {
    assert(_blk->type == _FILE);
    _blk->data = data;
    return 0;
}

int _blk_get_entries(block *_blk) {
    assert(_blk->type == _DIR);
    return _blk->dir_used;
}

int _blk_add_entry(block *_blk, dir_entry entry) {
    assert(_blk->type == _DIR);
    _blk->dir_list[_blk->dir_used++] = entry;
    return 0;
}

int _blk_del_entry(block *_blk, char *path) {
    assert(_blk->type == _DIR);
    const char *dirname = get_dir_name(path);
    if(dirname == NULL) {
        return -1;
    }

    int i;
    for(i = 0; i < _blk->dir_used; i++) {
        if(strcmp(_blk->dir_list[i].name, dirname) == 0) {
            if(remove_entry(_blk, i) == 0) {
                return 0;
            }
        }
    }
    return -2;
}

int _blk_entry_exists(block *_blk, char *name) {
    assert(_blk->type == _DIR);
    const char *dirname = name;
    int i;
    for(i = 0; i < _blk->dir_used; i++) {
        if(strcmp(_blk->dir_list[i].name, dirname) == 0) {
            return 0;
        }
    }
    return -1;
}

int _blk_free(block *_blk) {
    assert(_blk->type != _FREE);
    if(_blk->type == _DIR) {
        assert(_blk->dir_used == 2);
        _blk->dir_used = 0;
    }
    _blk->data = "";
    _blk->type = _FREE;
    return 0;
}

int remove_entry(block *_blk, _u32 idx) {
    if(idx > _blk->dir_used) 
        return -1;

    int i;
    for(i = idx; i<_blk->dir_used-1; i++) 
        _blk->dir_list[i] = _blk->dir_list[i+1];
    
    _blk->dir_used -= 1;
    return 0;
}

char *get_dir_name(char *path) {
    char *dirname, *token;

    token = strtok(path, "/");
    while(token != NULL) {
        dirname = token;
        token = strtok(NULL, "/");
    }
 
    if(dirname == NULL) {
        return NULL;
    }
    return dirname;
}