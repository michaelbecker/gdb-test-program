#ifndef GDB_TEST_PROGRAM_H__
#define GDB_TEST_PROGRAM_H__

#include "dlist.h"

typedef struct MessagePacket_t_ {

    DlNode_t Node;
    int Data;

}MessagePacket_t;


extern DlNode_t MessageHead;


#endif

