//
// Created by asia on 19.01.2021.
//

#ifndef QRGAME_SHAREDMEMORYVIDEO_H
#define QRGAME_SHAREDMEMORYVIDEO_H

#include <cstdint>
#include <chrono>
#include <semaphore.h>
#include "../Common.h"
#include <sys/mman.h>
#include <fcntl.h>

class SharedMemoryVideo {
public:
    SharedMemoryVideo();
    ~SharedMemoryVideo();

    template<typename Func, typename... Args>
    void getData(Func f, Args&&... args);

    template<typename Func, typename... Args>
    void sendData(Func f, Args&&... args);

    VideoData * data;
private:
    int sh_memory;
    sem_t* consumer;
    sem_t* producer;
    size_t size;
};


#endif //QRGAME_SHAREDMEMORYVIDEO_H
