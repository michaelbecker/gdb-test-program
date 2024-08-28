#ifndef GDB_TEST_PROGRAM_H__
#define GDB_TEST_PROGRAM_H__

#include "dlist.h"

/*
 *  This is the message structure we are sending.
 */
typedef struct MessagePacket_t_ {
    
    short int Data1;
    DlNode_t Node;
    short int Data2;

}MessagePacket_t;


extern DlNode_t MessageHead;
void SendMessage(int data1, int data2);
void PrintMessageList(void);


#endif

