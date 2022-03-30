/*
 * (C) 2022, Cornell University
 * All rights reserved.
 */

/* Author: Yunhao Zhang
 * Description: a program corrupting the memory of other processes;
 * Students are asked to modify the grass kernel so that this 
 * program fails and crashes without harming other processes
 */

#include "app.h"
#include <string.h>

int main() {
    memset((void*)FRAME_CACHE_START, 0, DTIM_END - FRAME_CACHE_START);
    SUCCESS("Crash2 succeeds in corrupting the memory of other processes");
}
