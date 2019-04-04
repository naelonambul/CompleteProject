#pragma once

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct Address *(__cdecl ADD)(struct Address *head);
struct Address *(__cdecl SCH)(struct Address *head);
struct Address *(__cdecl PRN)(struct Address *head);
struct Address *(__cdecl DEL)(struct Address *head);
struct Address *(__cdecl EXT)(struct Address *head);
