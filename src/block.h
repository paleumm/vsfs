#include "common.h"

#define BLOCKSIZE 4096
#define MAXDIR 32

typedef struct {
    const char *name;
    _u32 inum;
} dir_entry;

typedef struct {
    ftype type;
    dir_entry entry[MAXDIR];
    char *data;
} dump;

typedef struct {
    ftype type;
    _u32 dir_used;
    _u32 max_used;
    dir_entry dir_list[MAXDIR];
    char *data;
} block;

block _blk_init(ftype);
int _blk_dump(dump *, block);
int _blk_set_type(block *, ftype);
int _blk_add_data(block *, char *);
int _blk_get_entries(block *);
int _blk_add_entry(block *, dir_entry);
int _blk_del_entry(block *, char *);
int _blk_entry_exists(block *, char *);
int _blk_free(block *);
char *get_dir_name(char *);
int remove_entry(block *, _u32);