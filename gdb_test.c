#include <stdio.h>
#include "dlist.h"
#include "gdb_test.h"


/*
 *  We decided that we are going to receive our messages here.
 */
void ReceiveMessage(void)
{
    /************************/
    MessagePacket_t *message;
    DlNode_t *node;
    /************************/

    node = DlRemoveNodeFromTail(&MessageHead);

    message = CONTAINING_RECORD(node, MessagePacket_t, Node);

    if (node) {
        printf("  data1 = 0x%04x\n", message->Data1);
        printf("  data2 = 0x%04x\n\n", message->Data2);
    }
    else {
        printf("No Message found!\n");
    }
}


/*
 *  Main
 */
int main(void)
{
    printf("GDB Test program running...\n\n");

    DlInitHead(&MessageHead);

    SendMessage(0x1111, 0x2222);
    SendMessage(0x3333, 0x4444);
    SendMessage(0x5555, 0x6666);
    PrintMessageList();

    ReceiveMessage();
    ReceiveMessage();
    ReceiveMessage();
    ReceiveMessage();

    return 0;
}

