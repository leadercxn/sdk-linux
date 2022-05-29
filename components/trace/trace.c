/* Copyright (c) 2016 SENSORO Co.,Ltd. All Rights Reserved.
 *
 */

#include <stdio.h>
#include <stdint.h>

#ifdef TRACE_ENABLE
#include "trace.h"

uint8_t g_trace_level = TRACE_LEVEL_VERBOSE;

void trace_init(void)
{
}

void trace_dump(void *p_buffer, uint32_t len)
{
    uint8_t *p = (uint8_t *) p_buffer;
    for (uint32_t index = 0; index < len; index++) {
        TRACE_PRINTF("%02X", p[index]);
    }
    TRACE_PRINTF("\r\n");
}

void trace_level_set(uint8_t level)
{
    g_trace_level = level;
}

uint8_t trace_level_get(void)
{
    return g_trace_level;
}

#endif
