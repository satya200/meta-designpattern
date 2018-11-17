#ifndef _DEBUG_H_
#define _DEBUG_H_

/* Comment below Macro for disable Log */
#define DBG_ENABLE 0

#if DBG_ENABLE

#define   DBG_PRINT(fmt, args...) \
       (fprintf(stdout,"Debug: " fmt, ##args))

#else
#define   DBG_PRINT(fmt, args...) {do{}while(0);}

#endif

#endif // This is For _DEGUG_H
