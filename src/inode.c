#include "inode.h"

inode _inode_init(ftype type, _u16 addr, _u16 refcnt) {
    assert(type == _DIR || type == _FILE || type == _FREE);

    inode temp;
    temp.type = type;
    temp.addr = addr;
    temp.refcnt = refcnt;

    return temp;
}

int _inode_inc_refcnt(inode *_inode) { 
    _inode->refcnt++; //check error?
    return 0;
}

int _inode_dec_refcnt(inode *_inode) {
    _inode->refcnt--; //check error?
    return 0;
}

int _inode_get_refcnt(inode _inode) {
    return _inode.refcnt;
}

int _inode_set_type(inode *_inode, ftype type) {
    assert(type == _DIR || type == _FILE || type == _FREE);
    _inode->type = type;
    return 0;
}

int _inode_set_addr(inode *_inode, _u16 addr) {
    _inode->addr = addr; //check error?
    return 0;
}

int _inode_get_size(inode _inode) {
    if(_inode.addr == -1) 
        return 0;
    else
        return 1;
}

int _inode_get_addr(inode _inode) {
    return _inode.addr;
}

int _inode_get_type(inode _inode) {
    return _inode.type;
}

int _inode_free(inode *_inode) {
    _inode->type = _FREE;
    _inode->addr = -1;
    return 0;
}