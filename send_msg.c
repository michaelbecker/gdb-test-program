#include <stdio.h>
#include "gdb-test-program.h"



DlNode_t MessageHead;


void SendMessage(int data)
{
    //---------------------------
    MessagePacket_t *message;
    //---------------------------

    message = malloc(sizeof(MessagePacket_t));
    if (!message) {
        printf("Failed malloc!\n");
        exit(-1);
    }

    message->Data = data;

    DlAddNodeToHead(&MessageHead, &message->Node);
}



