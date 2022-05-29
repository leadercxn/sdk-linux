/* Copyright (c) 2016 SENSORO Co.,Ltd. All Rights Reserved.
 *
 */

#ifndef __TRACE_H_
#define __TRACE_H_

#include <stdint.h>
#include <stdio.h>

#ifdef TRACE_ENABLE

#define TRACE_LEVEL_ASSERT                      0
#define TRACE_LEVEL_ERROR                       1
#define TRACE_LEVEL_WARN                        2
#define TRACE_LEVEL_NOTICE                      3
#define TRACE_LEVEL_INFO                        4
#define TRACE_LEVEL_DEBUG                       5
#define TRACE_LEVEL_VERBOSE                     6

#ifndef FILENAME
#define FILENAME(x) strrchr(x,'/')?strrchr(x,'/')+1:x
#endif

#ifndef __MODULE__
#define __MODULE__ FILENAME(__FILE__)
#endif

#ifndef TRACE_ASSERT_FORMAT
#define TRACE_ASSERT_FORMAT                     "%-10s\t%4d [A] ", __MODULE__, __LINE__
#endif

#ifndef TRACE_ERROR_FORMAT
#define TRACE_ERROR_FORMAT                      "%-10s\t%4d [E] ", __MODULE__, __LINE__
#endif

#ifndef TRACE_WARN_FORMAT
#define TRACE_WARN_FORMAT                       "%-10s\t%4d [W] ", __MODULE__, __LINE__
#endif

#ifndef TRACE_NOTICE_FORMAT
#define TRACE_NOTICE_FORMAT                     "%-10s\t%4d [N] ", __MODULE__, __LINE__
#endif

#ifndef TRACE_INFO_FORMAT
#define TRACE_INFO_FORMAT                       "%-10s\t%4d [I] ", __MODULE__, __LINE__
#endif

#ifndef TRACE_DEBUG_FORMAT
#define TRACE_DEBUG_FORMAT                      "%-10s\t%4d [D] ", __MODULE__, __LINE__
#endif

#ifndef TRACE_VERBOSE_FORMAT
#define TRACE_VERBOSE_FORMAT                    "%-10s\t%4d [V] ", __MODULE__, __LINE__
#endif

#define TRACE_PRINTF    printf

#define trace_assert(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_ASSERT){\
            TRACE_PRINTF(TRACE_ASSERT_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);}\
    }while(0)
#define trace_assertln(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_ASSERT){\
            TRACE_PRINTF(TRACE_ASSERT_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);TRACE_PRINTF("\n");}\
    }while(0)
#define trace_dump_a(p_buffer,len)    do{\
        if(g_trace_level >= TRACE_LEVEL_ASSERT){\
            trace_dump(p_buffer,len);}\
    }while(0)

#define trace_error(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_ERROR){\
            TRACE_PRINTF(TRACE_ERROR_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);}\
    }while(0)
#define trace_errorln(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_ERROR){\
            TRACE_PRINTF(TRACE_ERROR_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);TRACE_PRINTF("\n");}\
    }while(0)
#define trace_dump_e(p_buffer,len)    do{\
        if(g_trace_level >= TRACE_LEVEL_ERROR){\
            trace_dump(p_buffer,len);}\
    }while(0)

#define trace_warn(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_WARN){\
            TRACE_PRINTF(TRACE_WARN_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);}\
    }while(0)
#define trace_warnln(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_WARN){\
            TRACE_PRINTF(TRACE_WARN_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);TRACE_PRINTF("\n");}\
    }while(0)
#define trace_dump_w(p_buffer,len)    do{\
        if(g_trace_level >= TRACE_LEVEL_WARN){\
            trace_dump(p_buffer,len);}\
    }while(0)

#define trace_notice(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_NOTICE){\
            TRACE_PRINTF(TRACE_NOTICE_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);}\
    }while(0)
#define trace_noticeln(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_NOTICE){\
            TRACE_PRINTF(TRACE_NOTICE_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);TRACE_PRINTF("\n");}\
    }while(0)
#define trace_dump_n(p_buffer,len)    do{\
        if(g_trace_level >= TRACE_LEVEL_NOTICE){\
            trace_dump(p_buffer,len);}\
    }while(0)

#define trace_info(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_INFO){\
            TRACE_PRINTF(TRACE_INFO_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);}\
    }while(0)
#define trace_infoln(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_INFO){\
            TRACE_PRINTF(TRACE_INFO_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);TRACE_PRINTF("\n");}\
    }while(0)
#define trace_dump_i(p_buffer,len)    do{\
        if(g_trace_level >= TRACE_LEVEL_INFO){\
            trace_dump(p_buffer,len);}\
    }while(0)

#define trace_debug(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_DEBUG){\
            TRACE_PRINTF(TRACE_DEBUG_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);}\
    }while(0)
#define trace_debugln(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_DEBUG){\
            TRACE_PRINTF(TRACE_DEBUG_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);TRACE_PRINTF("\n");}\
    }while(0)
#define trace_dump_d(p_buffer,len)    do{\
        if(g_trace_level >= TRACE_LEVEL_DEBUG){\
            trace_dump(p_buffer,len);}\
    }while(0)

#define trace_verbose(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_VERBOSE){\
            TRACE_PRINTF(TRACE_VERBOSE_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);}\
    }while(0)
#define trace_verboseln(msg, ...)   do{\
        if(g_trace_level >= TRACE_LEVEL_VERBOSE){\
            TRACE_PRINTF(TRACE_VERBOSE_FORMAT);TRACE_PRINTF(msg, ##__VA_ARGS__);TRACE_PRINTF("\n");}\
    }while(0)
#define trace_dump_v(p_buffer,len)    do{\
        if(g_trace_level >= TRACE_LEVEL_VERBOSE){\
            trace_dump(p_buffer,len);}\
    }while(0)

#define trace_printf(msg, ...)   do{\
            TRACE_PRINTF(msg, ##__VA_ARGS__);\
    }while(0)

/**
 * Globle trace level variable.
 */
extern uint8_t g_trace_level;

/**
 * Function for initializing trace module.
 */
void trace_init(void);

/**
 * Funciton for dumping data in hexstring format.
 *
 * @param    p_buffer    Data to dump.
 * @param    len         Length of data.
 */
void trace_dump(void * p_buffer, uint32_t len);

/**
 * Function for setting trace level.
 *
 * @param    level    Trace level.
 */
void trace_level_set(uint8_t level);

/**
 * Function for getting trace level.
 *
 * @return        Trace level.
 */
uint8_t trace_level_get(void);

#else

#define trace_init(...)
#define trace_dump(...)
#define trace_level_set(...)
#define trace_level_get(...)

#define trace_assert(...)
#define trace_assertln(...)
#define trace_dump_a(...)

#define trace_error(...)
#define trace_errorln(...)
#define trace_dump_e(...)

#define trace_warn(...)
#define trace_warnln(...)
#define trace_dump_w(...)

#define trace_notice(...)
#define trace_noticeln(...)
#define trace_dump_n(...)

#define trace_info(...)
#define trace_infoln(...)
#define trace_dump_i(...)

#define trace_debug(...)
#define trace_debugln(...)
#define trace_dump_d(...)

#define trace_verbose(...)
#define trace_verboseln(...)
#define trace_dump_v(...)

#endif

#endif
