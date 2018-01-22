/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif



static void Always_1930_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    t1 = (t0 + 4808U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 5128);
    *((int *)t2) = 1;
    t3 = (t0 + 4840);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 1888U);
    t5 = *((char **)t4);
    t4 = (t0 + 2768);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 32);
    t2 = (t0 + 2368U);
    t3 = *((char **)t2);
    t2 = (t0 + 3248);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 8);
    t2 = (t0 + 2048U);
    t3 = *((char **)t2);
    t2 = (t0 + 2928);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    t2 = (t0 + 2208U);
    t3 = *((char **)t2);
    t2 = (t0 + 3088);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 1);
    goto LAB2;

}


extern void xilinxcorelib_ver_m_00000000001687936702_3218604958_init()
{
	static char *pe[] = {(void *)Always_1930_0};
	xsi_register_didat("xilinxcorelib_ver_m_00000000001687936702_3218604958", "isim/test_isim_beh.exe.sim/xilinxcorelib_ver/m_00000000001687936702_3218604958.didat");
	xsi_register_executes(pe);
}
