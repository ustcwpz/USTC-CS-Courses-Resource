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
    work_m_00000000000225340969_3037777339_init();
    xilinxcorelib_ver_m_00000000001184809869_3179119762_init();
    xilinxcorelib_ver_m_00000000001036818086_1530692395_init();
    xilinxcorelib_ver_m_00000000000414557669_1431215541_init();
    xilinxcorelib_ver_m_00000000002216354146_2503625811_init();
    work_m_00000000003645434707_1774216237_init();
    work_m_00000000003062947860_3783644070_init();
    work_m_00000000003219014410_2725559894_init();
    work_m_00000000003322221736_3823007873_init();
    work_m_00000000000096677982_1985558087_init();
    work_m_00000000002013452923_2073120511_init();


    xsi_register_tops("work_m_00000000000096677982_1985558087");
    xsi_register_tops("work_m_00000000002013452923_2073120511");


    return xsi_run_simulation(argc, argv);

}
