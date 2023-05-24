#include "common.h"

typedef struct {
    ftype type;
    _u16 addr;
    _u16 refcnt;
} inode;

inode _inode_init(ftype type, _u16 addr, _u16 refcnt);
int _inode_inc_refcnt(inode *_inode);
int _inode_dec_refcnt(inode *_inode);
int _inode_get_refcnt(inode _inode);
int _inode_set_type(inode *_inode, ftype type);
int _inode_set_addr(inode *_inode, _u16 addr);
int _inode_get_size(inode _inode);
int _inode_get_addr(inode _inode);
int _inode_get_type(inode _inode);
int _inode_free(inode *_inode);