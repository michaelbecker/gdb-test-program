#include <stdio.h>
#include "dlist.h"
#include "gdb-test-program.h"


int ReceiveMessage(void)
{
    MessagePacket_t *Message;

    Message = DlRemoveNodeFromTail(&MessageHead);
    if (Message)
        return Message->Data;
    else
        return -1;
}


int main(void)
{
    //---------------
    int message; 
    //---------------

    printf("GDB Test program running...\n");

    DlInitHead(&MessageHead);

    SendMessage(123);
    SendMessage(456);
    SendMessage(789);

    message = ReceiveMessage();
    printf("message = %d\n");

    message = ReceiveMessage();
    printf("message = %d\n");

    message = ReceiveMessage();
    printf("message = %d\n");

    return 0;
}
