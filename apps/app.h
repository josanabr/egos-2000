#pragma once

#include "egos.h"
#include "memory.h"
#include "syscall.h"
#include "servers.h"

struct grass *grass = (void*)APPS_STACK_TOP;
struct earth *earth = (void*)GRASS_STACK_TOP;
