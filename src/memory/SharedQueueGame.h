

#ifndef QRGAME_SHAREDQUEUEGAME_H
#define QRGAME_SHAREDQUEUEGAME_H


#include <mqueue.h>
#include <fcntl.h>
#include "../Common.h"

class SharedQueueGame {
public:
    SharedQueueGame( bool write, bool non_block, long msgNum=1);
    ~SharedQueueGame();

    void sendMsg(GameData* msg) const;

    void receiveMsg(GameData* msg) const;

private:
    mqd_t queue;

};


#endif //QRGAME_SHAREDQUEUEGAME_H