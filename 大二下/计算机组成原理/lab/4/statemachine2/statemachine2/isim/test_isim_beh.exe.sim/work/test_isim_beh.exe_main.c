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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_00000000001649072342_0886308060_init();
    work_m_00000000000745735562_3783644070_init();
    xilinxcorelib_ver_m_00000000001184809869_0153913454_init();
    xilinxcorelib_ver_m_00000000001036818086_3680357725_init();
    xilinxcorelib_ver_m_00000000002194637086_1261012529_init();
    xilinxcorelib_ver_m_00000000002216354146_3675061481_init();
    work_m_00000000001664380267_0450250084_init();
    work_m_00000000000003407997_3037777339_init();
    work_m_00000000004088700851_3823007873_init();
    work_m_00000000002630772315_1985558087_init();
    work_m_00000000002013452923_2073120511_init();


    xsi_register_tops("work_m_00000000002630772315_1985558087");
    xsi_register_tops("work_m_00000000002013452923_2073120511");


    return xsi_run_simulation(argc, argv);

}
