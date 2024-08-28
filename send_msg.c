#include <stdio.h>
#include <stdlib.h>
#pragma pack (2)
#include "gdb_test.h"

/*
 *  Our Queue
 */
DlNode_t MessageHead;


/*
 *  Send a message via the Queue.
 */
void SendMessage(int data1, int data2)
{
    //---------------------------
    MessagePacket_t *message;
    //---------------------------

    message = malloc(sizeof(MessagePacket_t));
    if (!message) {
        printf("Failed malloc!\n");
        exit(-1);
    }

    message->Data1 = data1;
    message->Data2 = data2;

    DlAddNodeToHead(&MessageHead, &message->Node);
}


/*
 *  Debug, print out the state of the Queue.
 */
void PrintMessageList(void)
{
    /**************************/
    DlNode_t *node;
    MessagePacket_t *message;
    /**************************/

    printf("DBG: ********************************************\n");
    DlForEachNode(&MessageHead, node) {
        message = CONTAINING_RECORD(node, MessagePacket_t, Node);
        printf("DBG: data1 = 0x%04x\n", message->Data1);
        printf("DBG: data2 = 0x%04x\n\n", message->Data2);
    }
    printf("DBG_END: ****************************************\n\n");
}


