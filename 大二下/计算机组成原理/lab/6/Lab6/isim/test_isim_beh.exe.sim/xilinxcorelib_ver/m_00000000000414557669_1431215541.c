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

/* This file is designed for use with ISim build 0x16fbe694 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static unsigned int ng0[] = {2147483649U, 0U};
static const char *ng1 = "%0s WARNING: Address %0h is outside range for A Write";
static int ng2[] = {1983143731, 0, 1734700639, 0, 1835363679, 0, 1651272543, 0};
static int ng3[] = {1, 0};
static int ng4[] = {0, 0};
static int ng5[] = {32, 0};
static int ng6[] = {9, 0};
static int ng7[] = {2, 0};
static int ng8[] = {3, 0};
static unsigned int ng9[] = {1U, 0U};
static int ng10[] = {38, 0};
static int ng11[] = {1952542262, 0, 1936744818, 0};
static int ng12[] = {1952806966, 0, 7760242, 0};
static const char *ng13 = "%0s WARNING: Address %0h is outside range for B Write";
static const char *ng14 = "%0s WARNING: Address %0h is outside range for A Read";
static unsigned int ng15[] = {4294967295U, 4294967295U};
static unsigned int ng16[] = {0U, 0U};
static const char *ng17 = "%0s WARNING: Address %0h is outside range for B Read";
static unsigned int ng18[] = {1U, 1U};
static const char *ng19 = " Block Memory Generator CORE Generator module loading initial data...";
static int ng20[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng21 = "%0s ERROR: C_DEFAULT_DATA is empty!";
static const char *ng22 = "%h";
static const char *ng23 = "";
static int ng24[] = {539308147, 0, 1096040762, 0, 1280597828, 0, 1162232149, 0, 541286212, 0, 1718775661, 0, 1919246692, 0, 1835101216, 0, 1684366185, 0, 1751480417, 0, 1718971424, 0, 1667593075, 0, 1853060451, 0, 1379541077, 0, 1163022927, 0, 623932192, 0};
static int ng25[] = {48, 0};
static int ng26[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const char *ng27 = "%0s ERROR: C_INIT_FILE_NAME is empty!";
static const char *ng28 = "r";
static int ng29[] = {623932193, 0, 1296382496, 0, 1163873857, 0, 1598441804, 0, 1229867348, 0, 1852261215, 0, 1885695593, 0, 1701650543, 0, 1919902316, 0, 1379541072, 0, 1163022927, 0, 812854304, 0, 37, 0};
static const char *ng30 = "%b";
static const char *ng31 = " Block Memory Generator data initialization complete.";
static const char *ng32 = "Block Memory Generator CORE Generator module %m is using a behavioral model for simulation which will not precisely model memory collision behavior.";
static int ng33[] = {17221, 0};
static int ng34[] = {21330, 0};
static const char *ng35 = "%0s collision detected at time: %0d, ";
static const char *ng36 = "A %0s address: %0h, B write address: %0h\n";
static int ng37[] = {1919513701, 0, 119, 0};
static int ng38[] = {1919246692, 0, 0, 0};
static const char *ng39 = "A write address: %0h, B %s address: %0h\n";



static int sp_write_a(char *t1, char *t2)
{
    char t10[8];
    char t18[8];
    char t40[8];
    char t43[8];
    char t45[8];
    char t46[8];
    char t47[8];
    char t55[8];
    char t117[8];
    char t123[8];
    char t153[8];
    char t154[8];
    char t171[8];
    char t178[16];
    char t199[8];
    char t207[8];
    char t237[8];
    char t253[8];
    char t269[8];
    char t277[8];
    char t307[8];
    char t315[8];
    char t349[8];
    char t350[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t41;
    char *t42;
    char *t44;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t56;
    char *t57;
    int t58;
    char *t59;
    int t60;
    int t61;
    char *t62;
    int t63;
    int t64;
    int t65;
    int t66;
    int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    char *t155;
    char *t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    char *t163;
    unsigned int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    char *t169;
    char *t170;
    char *t172;
    char *t173;
    char *t174;
    char *t175;
    char *t176;
    unsigned int t177;
    int t179;
    int t180;
    int t181;
    int t182;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    unsigned int t189;
    unsigned int t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    unsigned int t194;
    unsigned int t195;
    unsigned int t196;
    unsigned int t197;
    char *t198;
    char *t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    unsigned int t204;
    unsigned int t205;
    char *t206;
    unsigned int t208;
    unsigned int t209;
    unsigned int t210;
    char *t211;
    char *t212;
    char *t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    unsigned int t218;
    unsigned int t219;
    unsigned int t220;
    char *t221;
    char *t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    unsigned int t229;
    unsigned int t230;
    unsigned int t231;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    char *t238;
    unsigned int t239;
    unsigned int t240;
    unsigned int t241;
    unsigned int t242;
    unsigned int t243;
    char *t244;
    char *t245;
    unsigned int t246;
    unsigned int t247;
    unsigned int t248;
    char *t249;
    char *t250;
    char *t251;
    char *t252;
    char *t254;
    char *t255;
    unsigned int t256;
    unsigned int t257;
    unsigned int t258;
    unsigned int t259;
    unsigned int t260;
    unsigned int t261;
    unsigned int t262;
    unsigned int t263;
    unsigned int t264;
    unsigned int t265;
    unsigned int t266;
    unsigned int t267;
    char *t268;
    char *t270;
    unsigned int t271;
    unsigned int t272;
    unsigned int t273;
    unsigned int t274;
    unsigned int t275;
    char *t276;
    unsigned int t278;
    unsigned int t279;
    unsigned int t280;
    char *t281;
    char *t282;
    char *t283;
    unsigned int t284;
    unsigned int t285;
    unsigned int t286;
    unsigned int t287;
    unsigned int t288;
    unsigned int t289;
    unsigned int t290;
    char *t291;
    char *t292;
    unsigned int t293;
    unsigned int t294;
    unsigned int t295;
    unsigned int t296;
    unsigned int t297;
    unsigned int t298;
    unsigned int t299;
    unsigned int t300;
    unsigned int t301;
    unsigned int t302;
    unsigned int t303;
    unsigned int t304;
    unsigned int t305;
    unsigned int t306;
    char *t308;
    unsigned int t309;
    unsigned int t310;
    unsigned int t311;
    unsigned int t312;
    unsigned int t313;
    char *t314;
    unsigned int t316;
    unsigned int t317;
    unsigned int t318;
    char *t319;
    char *t320;
    char *t321;
    unsigned int t322;
    unsigned int t323;
    unsigned int t324;
    unsigned int t325;
    unsigned int t326;
    unsigned int t327;
    unsigned int t328;
    char *t329;
    char *t330;
    unsigned int t331;
    unsigned int t332;
    unsigned int t333;
    unsigned int t334;
    unsigned int t335;
    unsigned int t336;
    unsigned int t337;
    unsigned int t338;
    unsigned int t339;
    unsigned int t340;
    char *t341;
    unsigned int t342;
    unsigned int t343;
    unsigned int t344;
    unsigned int t345;
    unsigned int t346;
    char *t347;
    char *t348;
    char *t351;
    char *t352;
    char *t353;
    char *t354;
    char *t355;
    char *t356;
    char *t357;
    char *t358;
    char *t359;
    char *t360;
    unsigned int t361;
    char *t362;
    unsigned int t363;
    int t364;
    unsigned int t365;
    unsigned int t366;
    int t367;
    int t368;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 12544);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 28872);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 9992);
    t9 = *((char **)t8);
    memset(t10, 0, 8);
    xsi_vlog_unsigned_divide(t10, 32, t7, 7, t9, 32);
    t8 = (t1 + 29832);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 7);
    t4 = (t1 + 29832);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3600);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB7;

LAB6:    t9 = (t8 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB7;

LAB10:    if (*((unsigned int *)t6) < *((unsigned int *)t8))
        goto LAB9;

LAB8:    *((unsigned int *)t10) = 1;

LAB9:    t12 = (t10 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB11;

LAB12:
LAB23:    t4 = (t1 + 2920);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t13 = *((unsigned int *)t4);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB24;

LAB25:
LAB58:    t4 = (t1 + 29192);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 29672);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);

LAB26:    t4 = (t1 + 7000);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB59;

LAB60:
LAB61:    t4 = (t1 + 6864);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB111;

LAB112:
LAB113:    t4 = (t1 + 9448);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB160;

LAB161:
LAB166:    t4 = ((char*)((ng4)));
    t5 = (t1 + 29992);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB167:    t4 = (t1 + 29992);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9448);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB168;

LAB169:
LAB162:    t4 = ((char*)((ng11)));
    t5 = ((char*)((ng12)));
    xsi_vlog_unsigned_equal(t178, 64, t4, 64, t5, 64);
    memset(t10, 0, 8);
    t6 = (t178 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t178);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB173;

LAB174:    if (*((unsigned int *)t6) != 0)
        goto LAB175;

LAB176:    t8 = (t10 + 4);
    t21 = *((unsigned int *)t10);
    t22 = *((unsigned int *)t8);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB177;

LAB178:    memcpy(t43, t10, 8);

LAB179:    t35 = (t43 + 4);
    t95 = *((unsigned int *)t35);
    t96 = (~(t95));
    t97 = *((unsigned int *)t43);
    t98 = (t97 & t96);
    t99 = (t98 != 0);
    if (t99 > 0)
        goto LAB187;

LAB188:
LAB189:    t4 = (t1 + 6864);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB309;

LAB310:
LAB311:
LAB13:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB7:    t11 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB9;

LAB11:
LAB14:    t19 = (t1 + 7816);
    t20 = *((char **)t19);
    memset(t18, 0, 8);
    t19 = (t20 + 4);
    t21 = *((unsigned int *)t19);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB18;

LAB16:    if (*((unsigned int *)t19) == 0)
        goto LAB15;

LAB17:    t26 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t26) = 1;

LAB18:    t27 = (t18 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t18);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB19;

LAB20:
LAB21:    goto LAB13;

LAB15:    *((unsigned int *)t18) = 1;
    goto LAB18;

LAB19:
LAB22:    t33 = ((char*)((ng0)));
    t34 = ((char*)((ng2)));
    t35 = (t1 + 28872);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 12544);
    xsi_vlogfile_fwrite(*((unsigned int *)t33), 1, 0, 0, ng1, 3, t38, (char)118, t34, 128, (char)118, t37, 7);
    goto LAB21;

LAB24:
LAB27:    t6 = (t1 + 9448);
    t7 = *((char **)t6);
    t6 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t7, 32, t6, 32);
    t8 = (t10 + 4);
    t21 = *((unsigned int *)t8);
    t22 = (~(t21));
    t23 = *((unsigned int *)t10);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB28;

LAB29:
LAB32:    t4 = ((char*)((ng4)));
    t5 = (t1 + 29992);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB33:    t4 = (t1 + 29992);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9448);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB34;

LAB35:
LAB30:    t4 = (t1 + 3056);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB39;

LAB40:
LAB47:    t4 = ((char*)((ng4)));
    t5 = (t1 + 29992);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB48:    t4 = (t1 + 29992);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3056);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB49;

LAB50:
LAB41:    goto LAB26;

LAB28:
LAB31:    t9 = (t1 + 24072);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 24072);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 24072);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 29832);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    xsi_vlog_generic_get_array_select_value(t18, 32, t12, t26, t34, 2, 1, t37, 7, 2);
    t38 = (t1 + 29672);
    xsi_vlogvar_assign_value(t38, t18, 0, 0, 32);
    goto LAB30;

LAB34:
LAB36:    t9 = (t1 + 24072);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 24072);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 24072);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 29832);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 9448);
    t39 = *((char **)t38);
    memset(t40, 0, 8);
    xsi_vlog_unsigned_multiply(t40, 32, t37, 7, t39, 32);
    t38 = (t1 + 29992);
    t41 = (t38 + 56U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    xsi_vlog_unsigned_add(t43, 32, t40, 32, t42, 32);
    xsi_vlog_generic_get_array_select_value(t18, 32, t12, t26, t34, 2, 1, t43, 32, 2);
    t44 = (t1 + 29672);
    t48 = (t1 + 29672);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t1 + 8904);
    t52 = *((char **)t51);
    t51 = (t1 + 29992);
    t53 = (t51 + 56U);
    t54 = *((char **)t53);
    memset(t55, 0, 8);
    xsi_vlog_signed_multiply(t55, 32, t52, 32, t54, 32);
    t56 = ((char*)((ng5)));
    xsi_vlog_convert_indexed_partindices(t45, t46, t47, ((int*)(t50)), 2, t55, 32, 1, t56, 32, 1, 1);
    t57 = (t45 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t46 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    t62 = (t47 + 4);
    t23 = *((unsigned int *)t62);
    t63 = (!(t23));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB37;

LAB38:    t4 = (t1 + 29992);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 29992);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB33;

LAB37:    t24 = *((unsigned int *)t47);
    t65 = (t24 + 0);
    t25 = *((unsigned int *)t45);
    t28 = *((unsigned int *)t46);
    t66 = (t25 - t28);
    t67 = (t66 + 1);
    xsi_vlogvar_assign_value(t44, t18, t65, *((unsigned int *)t46), t67);
    goto LAB38;

LAB39:
LAB42:    t7 = (t1 + 29032);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t18, 0, 8);
    t11 = (t18 + 4);
    t12 = (t9 + 4);
    t21 = *((unsigned int *)t9);
    t22 = (t21 >> 0);
    t23 = (t22 & 1);
    *((unsigned int *)t18) = t23;
    t24 = *((unsigned int *)t12);
    t25 = (t24 >> 0);
    t28 = (t25 & 1);
    *((unsigned int *)t11) = t28;
    t19 = (t18 + 4);
    t29 = *((unsigned int *)t19);
    t30 = (~(t29));
    t31 = *((unsigned int *)t18);
    t32 = (t31 & t30);
    t68 = (t32 != 0);
    if (t68 > 0)
        goto LAB43;

LAB44:
LAB45:    goto LAB41;

LAB43:
LAB46:    t20 = (t1 + 29192);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    t33 = (t1 + 29672);
    xsi_vlogvar_assign_value(t33, t27, 0, 0, 32);
    goto LAB45;

LAB49:
LAB51:    t9 = (t1 + 29032);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 29032);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 29992);
    t33 = (t27 + 56U);
    t34 = *((char **)t33);
    xsi_vlog_generic_get_index_select_value(t18, 1, t12, t26, 2, t34, 32, 1);
    t35 = (t18 + 4);
    t21 = *((unsigned int *)t35);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB52;

LAB53:
LAB54:    t4 = (t1 + 29992);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 29992);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB48;

LAB52:
LAB55:    t36 = (t1 + 29192);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    t39 = (t1 + 29192);
    t41 = (t39 + 72U);
    t42 = *((char **)t41);
    t44 = (t1 + 10536);
    t48 = *((char **)t44);
    t44 = (t1 + 29992);
    t49 = (t44 + 56U);
    t50 = *((char **)t49);
    memset(t43, 0, 8);
    xsi_vlog_signed_multiply(t43, 32, t48, 32, t50, 32);
    t51 = ((char*)((ng6)));
    xsi_vlog_get_indexed_partselect(t40, 9, t38, ((int*)(t42)), 2, t43, 32, 1, t51, 32, 1, 1);
    t52 = (t1 + 29672);
    t53 = (t1 + 29672);
    t54 = (t53 + 72U);
    t56 = *((char **)t54);
    t57 = (t1 + 10536);
    t59 = *((char **)t57);
    t57 = (t1 + 29992);
    t62 = (t57 + 56U);
    t69 = *((char **)t62);
    memset(t55, 0, 8);
    xsi_vlog_signed_multiply(t55, 32, t59, 32, t69, 32);
    t70 = ((char*)((ng6)));
    xsi_vlog_convert_indexed_partindices(t45, t46, t47, ((int*)(t56)), 2, t55, 32, 1, t70, 32, 1, 1);
    t71 = (t45 + 4);
    t28 = *((unsigned int *)t71);
    t58 = (!(t28));
    t72 = (t46 + 4);
    t29 = *((unsigned int *)t72);
    t60 = (!(t29));
    t61 = (t58 && t60);
    t73 = (t47 + 4);
    t30 = *((unsigned int *)t73);
    t63 = (!(t30));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB56;

LAB57:    goto LAB54;

LAB56:    t31 = *((unsigned int *)t47);
    t65 = (t31 + 0);
    t32 = *((unsigned int *)t45);
    t68 = *((unsigned int *)t46);
    t66 = (t32 - t68);
    t67 = (t66 + 1);
    xsi_vlogvar_assign_value(t52, t40, t65, *((unsigned int *)t46), t67);
    goto LAB57;

LAB59:
LAB62:    t7 = (t1 + 7136);
    t8 = *((char **)t7);
    t7 = ((char*)((ng7)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t8, 32, t7, 32);
    memset(t40, 0, 8);
    t9 = (t18 + 4);
    t21 = *((unsigned int *)t9);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB63;

LAB64:    if (*((unsigned int *)t9) != 0)
        goto LAB65;

LAB66:    t12 = (t40 + 4);
    t28 = *((unsigned int *)t40);
    t29 = (!(t28));
    t30 = *((unsigned int *)t12);
    t31 = (t29 || t30);
    if (t31 > 0)
        goto LAB67;

LAB68:    memcpy(t46, t40, 8);

LAB69:    memset(t47, 0, 8);
    t38 = (t46 + 4);
    t97 = *((unsigned int *)t38);
    t98 = (~(t97));
    t99 = *((unsigned int *)t46);
    t100 = (t99 & t98);
    t101 = (t100 & 1U);
    if (t101 != 0)
        goto LAB77;

LAB78:    if (*((unsigned int *)t38) != 0)
        goto LAB79;

LAB80:    t41 = (t47 + 4);
    t102 = *((unsigned int *)t47);
    t103 = *((unsigned int *)t41);
    t104 = (t102 || t103);
    if (t104 > 0)
        goto LAB81;

LAB82:    memcpy(t123, t47, 8);

LAB83:    t70 = (t123 + 4);
    t148 = *((unsigned int *)t70);
    t149 = (~(t148));
    t150 = *((unsigned int *)t123);
    t151 = (t150 & t149);
    t152 = (t151 != 0);
    if (t152 > 0)
        goto LAB95;

LAB96:
LAB97:    goto LAB61;

LAB63:    *((unsigned int *)t40) = 1;
    goto LAB66;

LAB65:    t11 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB66;

LAB67:    t19 = (t1 + 7136);
    t20 = *((char **)t19);
    t19 = ((char*)((ng8)));
    memset(t43, 0, 8);
    xsi_vlog_signed_equal(t43, 32, t20, 32, t19, 32);
    memset(t45, 0, 8);
    t26 = (t43 + 4);
    t32 = *((unsigned int *)t26);
    t68 = (~(t32));
    t74 = *((unsigned int *)t43);
    t75 = (t74 & t68);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB70;

LAB71:    if (*((unsigned int *)t26) != 0)
        goto LAB72;

LAB73:    t77 = *((unsigned int *)t40);
    t78 = *((unsigned int *)t45);
    t79 = (t77 | t78);
    *((unsigned int *)t46) = t79;
    t33 = (t40 + 4);
    t34 = (t45 + 4);
    t35 = (t46 + 4);
    t80 = *((unsigned int *)t33);
    t81 = *((unsigned int *)t34);
    t82 = (t80 | t81);
    *((unsigned int *)t35) = t82;
    t83 = *((unsigned int *)t35);
    t84 = (t83 != 0);
    if (t84 == 1)
        goto LAB74;

LAB75:
LAB76:    goto LAB69;

LAB70:    *((unsigned int *)t45) = 1;
    goto LAB73;

LAB72:    t27 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB73;

LAB74:    t85 = *((unsigned int *)t46);
    t86 = *((unsigned int *)t35);
    *((unsigned int *)t46) = (t85 | t86);
    t36 = (t40 + 4);
    t37 = (t45 + 4);
    t87 = *((unsigned int *)t36);
    t88 = (~(t87));
    t89 = *((unsigned int *)t40);
    t58 = (t89 & t88);
    t90 = *((unsigned int *)t37);
    t91 = (~(t90));
    t92 = *((unsigned int *)t45);
    t60 = (t92 & t91);
    t93 = (~(t58));
    t94 = (~(t60));
    t95 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t95 & t93);
    t96 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t96 & t94);
    goto LAB76;

LAB77:    *((unsigned int *)t47) = 1;
    goto LAB80;

LAB79:    t39 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB80;

LAB81:    t42 = (t1 + 29512);
    t44 = (t42 + 56U);
    t48 = *((char **)t44);
    t49 = ((char*)((ng9)));
    memset(t55, 0, 8);
    t50 = (t48 + 4);
    t51 = (t49 + 4);
    t105 = *((unsigned int *)t48);
    t106 = *((unsigned int *)t49);
    t107 = (t105 ^ t106);
    t108 = *((unsigned int *)t50);
    t109 = *((unsigned int *)t51);
    t110 = (t108 ^ t109);
    t111 = (t107 | t110);
    t112 = *((unsigned int *)t50);
    t113 = *((unsigned int *)t51);
    t114 = (t112 | t113);
    t115 = (~(t114));
    t116 = (t111 & t115);
    if (t116 != 0)
        goto LAB87;

LAB84:    if (t114 != 0)
        goto LAB86;

LAB85:    *((unsigned int *)t55) = 1;

LAB87:    memset(t117, 0, 8);
    t53 = (t55 + 4);
    t118 = *((unsigned int *)t53);
    t119 = (~(t118));
    t120 = *((unsigned int *)t55);
    t121 = (t120 & t119);
    t122 = (t121 & 1U);
    if (t122 != 0)
        goto LAB88;

LAB89:    if (*((unsigned int *)t53) != 0)
        goto LAB90;

LAB91:    t124 = *((unsigned int *)t47);
    t125 = *((unsigned int *)t117);
    t126 = (t124 & t125);
    *((unsigned int *)t123) = t126;
    t56 = (t47 + 4);
    t57 = (t117 + 4);
    t59 = (t123 + 4);
    t127 = *((unsigned int *)t56);
    t128 = *((unsigned int *)t57);
    t129 = (t127 | t128);
    *((unsigned int *)t59) = t129;
    t130 = *((unsigned int *)t59);
    t131 = (t130 != 0);
    if (t131 == 1)
        goto LAB92;

LAB93:
LAB94:    goto LAB83;

LAB86:    t52 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB87;

LAB88:    *((unsigned int *)t117) = 1;
    goto LAB91;

LAB90:    t54 = (t117 + 4);
    *((unsigned int *)t117) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB91;

LAB92:    t132 = *((unsigned int *)t123);
    t133 = *((unsigned int *)t59);
    *((unsigned int *)t123) = (t132 | t133);
    t62 = (t47 + 4);
    t69 = (t117 + 4);
    t134 = *((unsigned int *)t47);
    t135 = (~(t134));
    t136 = *((unsigned int *)t62);
    t137 = (~(t136));
    t138 = *((unsigned int *)t117);
    t139 = (~(t138));
    t140 = *((unsigned int *)t69);
    t141 = (~(t140));
    t61 = (t135 & t137);
    t63 = (t139 & t141);
    t142 = (~(t61));
    t143 = (~(t63));
    t144 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t144 & t142);
    t145 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t145 & t143);
    t146 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t146 & t142);
    t147 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t147 & t143);
    goto LAB94;

LAB95:
LAB98:    t71 = (t1 + 29672);
    t72 = (t71 + 56U);
    t73 = *((char **)t72);
    memset(t154, 0, 8);
    t155 = (t154 + 4);
    t156 = (t73 + 4);
    t157 = *((unsigned int *)t73);
    t158 = (t157 >> 0);
    t159 = (t158 & 1);
    *((unsigned int *)t154) = t159;
    t160 = *((unsigned int *)t156);
    t161 = (t160 >> 0);
    t162 = (t161 & 1);
    *((unsigned int *)t155) = t162;
    memset(t153, 0, 8);
    t163 = (t154 + 4);
    t164 = *((unsigned int *)t163);
    t165 = (~(t164));
    t166 = *((unsigned int *)t154);
    t167 = (t166 & t165);
    t168 = (t167 & 1U);
    if (t168 != 0)
        goto LAB102;

LAB100:    if (*((unsigned int *)t163) == 0)
        goto LAB99;

LAB101:    t169 = (t153 + 4);
    *((unsigned int *)t153) = 1;
    *((unsigned int *)t169) = 1;

LAB102:    t170 = (t1 + 29672);
    t172 = (t1 + 29672);
    t173 = (t172 + 72U);
    t174 = *((char **)t173);
    t175 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t171, t174, 2, t175, 32, 1);
    t176 = (t171 + 4);
    t177 = *((unsigned int *)t176);
    t64 = (!(t177));
    if (t64 == 1)
        goto LAB103;

LAB104:    t4 = (t1 + 29672);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t18, 0, 8);
    t7 = (t18 + 4);
    t8 = (t6 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (t13 >> 1);
    t15 = (t14 & 1);
    *((unsigned int *)t18) = t15;
    t16 = *((unsigned int *)t8);
    t17 = (t16 >> 1);
    t21 = (t17 & 1);
    *((unsigned int *)t7) = t21;
    memset(t10, 0, 8);
    t9 = (t18 + 4);
    t22 = *((unsigned int *)t9);
    t23 = (~(t22));
    t24 = *((unsigned int *)t18);
    t25 = (t24 & t23);
    t28 = (t25 & 1U);
    if (t28 != 0)
        goto LAB108;

LAB106:    if (*((unsigned int *)t9) == 0)
        goto LAB105;

LAB107:    t11 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t11) = 1;

LAB108:    t12 = (t1 + 29672);
    t19 = (t1 + 29672);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t40, t26, 2, t27, 32, 1);
    t33 = (t40 + 4);
    t29 = *((unsigned int *)t33);
    t58 = (!(t29));
    if (t58 == 1)
        goto LAB109;

LAB110:    goto LAB97;

LAB99:    *((unsigned int *)t153) = 1;
    goto LAB102;

LAB103:    xsi_vlogvar_assign_value(t170, t153, 0, *((unsigned int *)t171), 1);
    goto LAB104;

LAB105:    *((unsigned int *)t10) = 1;
    goto LAB108;

LAB109:    xsi_vlogvar_assign_value(t12, t10, 0, *((unsigned int *)t40), 1);
    goto LAB110;

LAB111:
LAB114:    t7 = (t1 + 7136);
    t8 = *((char **)t7);
    t7 = ((char*)((ng7)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t8, 32, t7, 32);
    memset(t40, 0, 8);
    t9 = (t18 + 4);
    t21 = *((unsigned int *)t9);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB115;

LAB116:    if (*((unsigned int *)t9) != 0)
        goto LAB117;

LAB118:    t12 = (t40 + 4);
    t28 = *((unsigned int *)t40);
    t29 = (!(t28));
    t30 = *((unsigned int *)t12);
    t31 = (t29 || t30);
    if (t31 > 0)
        goto LAB119;

LAB120:    memcpy(t46, t40, 8);

LAB121:    memset(t47, 0, 8);
    t38 = (t46 + 4);
    t97 = *((unsigned int *)t38);
    t98 = (~(t97));
    t99 = *((unsigned int *)t46);
    t100 = (t99 & t98);
    t101 = (t100 & 1U);
    if (t101 != 0)
        goto LAB129;

LAB130:    if (*((unsigned int *)t38) != 0)
        goto LAB131;

LAB132:    t41 = (t47 + 4);
    t102 = *((unsigned int *)t47);
    t103 = *((unsigned int *)t41);
    t104 = (t102 || t103);
    if (t104 > 0)
        goto LAB133;

LAB134:    memcpy(t123, t47, 8);

LAB135:    t70 = (t123 + 4);
    t148 = *((unsigned int *)t70);
    t149 = (~(t148));
    t150 = *((unsigned int *)t123);
    t151 = (t150 & t149);
    t152 = (t151 != 0);
    if (t152 > 0)
        goto LAB147;

LAB148:
LAB149:    goto LAB113;

LAB115:    *((unsigned int *)t40) = 1;
    goto LAB118;

LAB117:    t11 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB118;

LAB119:    t19 = (t1 + 7136);
    t20 = *((char **)t19);
    t19 = ((char*)((ng8)));
    memset(t43, 0, 8);
    xsi_vlog_signed_equal(t43, 32, t20, 32, t19, 32);
    memset(t45, 0, 8);
    t26 = (t43 + 4);
    t32 = *((unsigned int *)t26);
    t68 = (~(t32));
    t74 = *((unsigned int *)t43);
    t75 = (t74 & t68);
    t76 = (t75 & 1U);
    if (t76 != 0)
        goto LAB122;

LAB123:    if (*((unsigned int *)t26) != 0)
        goto LAB124;

LAB125:    t77 = *((unsigned int *)t40);
    t78 = *((unsigned int *)t45);
    t79 = (t77 | t78);
    *((unsigned int *)t46) = t79;
    t33 = (t40 + 4);
    t34 = (t45 + 4);
    t35 = (t46 + 4);
    t80 = *((unsigned int *)t33);
    t81 = *((unsigned int *)t34);
    t82 = (t80 | t81);
    *((unsigned int *)t35) = t82;
    t83 = *((unsigned int *)t35);
    t84 = (t83 != 0);
    if (t84 == 1)
        goto LAB126;

LAB127:
LAB128:    goto LAB121;

LAB122:    *((unsigned int *)t45) = 1;
    goto LAB125;

LAB124:    t27 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB125;

LAB126:    t85 = *((unsigned int *)t46);
    t86 = *((unsigned int *)t35);
    *((unsigned int *)t46) = (t85 | t86);
    t36 = (t40 + 4);
    t37 = (t45 + 4);
    t87 = *((unsigned int *)t36);
    t88 = (~(t87));
    t89 = *((unsigned int *)t40);
    t58 = (t89 & t88);
    t90 = *((unsigned int *)t37);
    t91 = (~(t90));
    t92 = *((unsigned int *)t45);
    t60 = (t92 & t91);
    t93 = (~(t58));
    t94 = (~(t60));
    t95 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t95 & t93);
    t96 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t96 & t94);
    goto LAB128;

LAB129:    *((unsigned int *)t47) = 1;
    goto LAB132;

LAB131:    t39 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB132;

LAB133:    t42 = (t1 + 29512);
    t44 = (t42 + 56U);
    t48 = *((char **)t44);
    t49 = ((char*)((ng9)));
    memset(t55, 0, 8);
    t50 = (t48 + 4);
    t51 = (t49 + 4);
    t105 = *((unsigned int *)t48);
    t106 = *((unsigned int *)t49);
    t107 = (t105 ^ t106);
    t108 = *((unsigned int *)t50);
    t109 = *((unsigned int *)t51);
    t110 = (t108 ^ t109);
    t111 = (t107 | t110);
    t112 = *((unsigned int *)t50);
    t113 = *((unsigned int *)t51);
    t114 = (t112 | t113);
    t115 = (~(t114));
    t116 = (t111 & t115);
    if (t116 != 0)
        goto LAB139;

LAB136:    if (t114 != 0)
        goto LAB138;

LAB137:    *((unsigned int *)t55) = 1;

LAB139:    memset(t117, 0, 8);
    t53 = (t55 + 4);
    t118 = *((unsigned int *)t53);
    t119 = (~(t118));
    t120 = *((unsigned int *)t55);
    t121 = (t120 & t119);
    t122 = (t121 & 1U);
    if (t122 != 0)
        goto LAB140;

LAB141:    if (*((unsigned int *)t53) != 0)
        goto LAB142;

LAB143:    t124 = *((unsigned int *)t47);
    t125 = *((unsigned int *)t117);
    t126 = (t124 & t125);
    *((unsigned int *)t123) = t126;
    t56 = (t47 + 4);
    t57 = (t117 + 4);
    t59 = (t123 + 4);
    t127 = *((unsigned int *)t56);
    t128 = *((unsigned int *)t57);
    t129 = (t127 | t128);
    *((unsigned int *)t59) = t129;
    t130 = *((unsigned int *)t59);
    t131 = (t130 != 0);
    if (t131 == 1)
        goto LAB144;

LAB145:
LAB146:    goto LAB135;

LAB138:    t52 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB139;

LAB140:    *((unsigned int *)t117) = 1;
    goto LAB143;

LAB142:    t54 = (t117 + 4);
    *((unsigned int *)t117) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB143;

LAB144:    t132 = *((unsigned int *)t123);
    t133 = *((unsigned int *)t59);
    *((unsigned int *)t123) = (t132 | t133);
    t62 = (t47 + 4);
    t69 = (t117 + 4);
    t134 = *((unsigned int *)t47);
    t135 = (~(t134));
    t136 = *((unsigned int *)t62);
    t137 = (~(t136));
    t138 = *((unsigned int *)t117);
    t139 = (~(t138));
    t140 = *((unsigned int *)t69);
    t141 = (~(t140));
    t61 = (t135 & t137);
    t63 = (t139 & t141);
    t142 = (~(t61));
    t143 = (~(t63));
    t144 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t144 & t142);
    t145 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t145 & t143);
    t146 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t146 & t142);
    t147 = *((unsigned int *)t123);
    *((unsigned int *)t123) = (t147 & t143);
    goto LAB146;

LAB147:
LAB150:    t71 = (t1 + 24232);
    t72 = (t71 + 56U);
    t73 = *((char **)t72);
    xsi_vlog_get_part_select_value(t178, 37, t73, 36, 0);
    t155 = (t1 + 24232);
    t156 = (t1 + 24232);
    t163 = (t156 + 72U);
    t169 = *((char **)t163);
    t170 = ((char*)((ng10)));
    t172 = ((char*)((ng7)));
    xsi_vlog_convert_partindices(t153, t154, t171, ((int*)(t169)), 2, t170, 32, 1, t172, 32, 1);
    t173 = (t153 + 4);
    t157 = *((unsigned int *)t173);
    t64 = (!(t157));
    t174 = (t154 + 4);
    t158 = *((unsigned int *)t174);
    t65 = (!(t158));
    t66 = (t64 && t65);
    t175 = (t171 + 4);
    t159 = *((unsigned int *)t175);
    t67 = (!(t159));
    t179 = (t66 && t67);
    if (t179 == 1)
        goto LAB151;

LAB152:    t4 = (t1 + 24232);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t10, 0, 8);
    t7 = (t10 + 4);
    t8 = (t6 + 8);
    t9 = (t6 + 12);
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 6);
    t15 = (t14 & 1);
    *((unsigned int *)t10) = t15;
    t16 = *((unsigned int *)t9);
    t17 = (t16 >> 6);
    t21 = (t17 & 1);
    *((unsigned int *)t7) = t21;
    t11 = (t1 + 24232);
    t12 = (t1 + 24232);
    t19 = (t12 + 72U);
    t20 = *((char **)t19);
    t26 = ((char*)((ng4)));
    xsi_vlog_generic_convert_bit_index(t18, t20, 2, t26, 32, 1);
    t27 = (t18 + 4);
    t22 = *((unsigned int *)t27);
    t58 = (!(t22));
    if (t58 == 1)
        goto LAB153;

LAB154:    t4 = (t1 + 24232);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t10, 0, 8);
    t7 = (t10 + 4);
    t8 = (t6 + 8);
    t9 = (t6 + 12);
    t13 = *((unsigned int *)t8);
    t14 = (t13 >> 5);
    t15 = (t14 & 1);
    *((unsigned int *)t10) = t15;
    t16 = *((unsigned int *)t9);
    t17 = (t16 >> 5);
    t21 = (t17 & 1);
    *((unsigned int *)t7) = t21;
    t11 = (t1 + 24232);
    t12 = (t1 + 24232);
    t19 = (t12 + 72U);
    t20 = *((char **)t19);
    t26 = ((char*)((ng3)));
    xsi_vlog_generic_convert_bit_index(t18, t20, 2, t26, 32, 1);
    t27 = (t18 + 4);
    t22 = *((unsigned int *)t27);
    t58 = (!(t22));
    if (t58 == 1)
        goto LAB155;

LAB156:    t4 = (t1 + 29672);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 24232);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t10, 0, 8);
    t11 = (t10 + 4);
    t12 = (t9 + 4);
    t13 = *((unsigned int *)t9);
    t14 = (t13 >> 0);
    *((unsigned int *)t10) = t14;
    t15 = *((unsigned int *)t12);
    t16 = (t15 >> 0);
    *((unsigned int *)t11) = t16;
    t17 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t17 & 4294967295U);
    t21 = *((unsigned int *)t11);
    *((unsigned int *)t11) = (t21 & 4294967295U);
    t22 = *((unsigned int *)t6);
    t23 = *((unsigned int *)t10);
    t24 = (t22 ^ t23);
    *((unsigned int *)t18) = t24;
    t19 = (t6 + 4);
    t20 = (t10 + 4);
    t26 = (t18 + 4);
    t25 = *((unsigned int *)t19);
    t28 = *((unsigned int *)t20);
    t29 = (t25 | t28);
    *((unsigned int *)t26) = t29;
    t30 = *((unsigned int *)t26);
    t31 = (t30 != 0);
    if (t31 == 1)
        goto LAB157;

LAB158:
LAB159:    t27 = (t1 + 29672);
    xsi_vlogvar_assign_value(t27, t18, 0, 0, 32);
    goto LAB149;

LAB151:    t160 = *((unsigned int *)t171);
    t180 = (t160 + 0);
    t161 = *((unsigned int *)t153);
    t162 = *((unsigned int *)t154);
    t181 = (t161 - t162);
    t182 = (t181 + 1);
    xsi_vlogvar_assign_value(t155, t178, t180, *((unsigned int *)t154), t182);
    goto LAB152;

LAB153:    xsi_vlogvar_assign_value(t11, t10, 0, *((unsigned int *)t18), 1);
    goto LAB154;

LAB155:    xsi_vlogvar_assign_value(t11, t10, 0, *((unsigned int *)t18), 1);
    goto LAB156;

LAB157:    t32 = *((unsigned int *)t18);
    t68 = *((unsigned int *)t26);
    *((unsigned int *)t18) = (t32 | t68);
    goto LAB159;

LAB160:
LAB163:    t7 = (t1 + 29672);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t11 = (t1 + 24072);
    t12 = (t1 + 24072);
    t19 = (t12 + 72U);
    t20 = *((char **)t19);
    t26 = (t1 + 24072);
    t27 = (t26 + 64U);
    t33 = *((char **)t27);
    t34 = (t1 + 29832);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    t37 = (t1 + 9448);
    t38 = *((char **)t37);
    memset(t43, 0, 8);
    xsi_vlog_unsigned_multiply(t43, 32, t36, 7, t38, 32);
    xsi_vlog_generic_convert_array_indices(t18, t40, t20, t33, 2, 1, t43, 32, 2);
    t37 = (t18 + 4);
    t21 = *((unsigned int *)t37);
    t58 = (!(t21));
    t39 = (t40 + 4);
    t22 = *((unsigned int *)t39);
    t60 = (!(t22));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB164;

LAB165:    goto LAB162;

LAB164:    t23 = *((unsigned int *)t18);
    t24 = *((unsigned int *)t40);
    t63 = (t23 - t24);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t11, t9, 0, *((unsigned int *)t40), t64);
    goto LAB165;

LAB168:
LAB170:    t9 = (t1 + 29672);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 29672);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 8904);
    t33 = *((char **)t27);
    t27 = (t1 + 29992);
    t34 = (t27 + 56U);
    t35 = *((char **)t34);
    memset(t40, 0, 8);
    xsi_vlog_signed_multiply(t40, 32, t33, 32, t35, 32);
    t36 = ((char*)((ng5)));
    xsi_vlog_get_indexed_partselect(t18, 32, t12, ((int*)(t26)), 2, t40, 32, 1, t36, 32, 1, 1);
    t37 = (t1 + 24072);
    t38 = (t1 + 24072);
    t39 = (t38 + 72U);
    t41 = *((char **)t39);
    t42 = (t1 + 24072);
    t44 = (t42 + 64U);
    t48 = *((char **)t44);
    t49 = (t1 + 29832);
    t50 = (t49 + 56U);
    t51 = *((char **)t50);
    t52 = (t1 + 9448);
    t53 = *((char **)t52);
    memset(t46, 0, 8);
    xsi_vlog_unsigned_multiply(t46, 32, t51, 7, t53, 32);
    t52 = (t1 + 29992);
    t54 = (t52 + 56U);
    t56 = *((char **)t54);
    memset(t47, 0, 8);
    xsi_vlog_unsigned_add(t47, 32, t46, 32, t56, 32);
    xsi_vlog_generic_convert_array_indices(t43, t45, t41, t48, 2, 1, t47, 32, 2);
    t57 = (t43 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t45 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB171;

LAB172:    t4 = (t1 + 29992);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 29992);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB167;

LAB171:    t23 = *((unsigned int *)t43);
    t24 = *((unsigned int *)t45);
    t63 = (t23 - t24);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t37, t18, 0, *((unsigned int *)t45), t64);
    goto LAB172;

LAB173:    *((unsigned int *)t10) = 1;
    goto LAB176;

LAB175:    t7 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB176;

LAB177:    t9 = (t1 + 7000);
    t11 = *((char **)t9);
    t9 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t11, 32, t9, 32);
    memset(t40, 0, 8);
    t12 = (t18 + 4);
    t24 = *((unsigned int *)t12);
    t25 = (~(t24));
    t28 = *((unsigned int *)t18);
    t29 = (t28 & t25);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB180;

LAB181:    if (*((unsigned int *)t12) != 0)
        goto LAB182;

LAB183:    t31 = *((unsigned int *)t10);
    t32 = *((unsigned int *)t40);
    t68 = (t31 & t32);
    *((unsigned int *)t43) = t68;
    t20 = (t10 + 4);
    t26 = (t40 + 4);
    t27 = (t43 + 4);
    t74 = *((unsigned int *)t20);
    t75 = *((unsigned int *)t26);
    t76 = (t74 | t75);
    *((unsigned int *)t27) = t76;
    t77 = *((unsigned int *)t27);
    t78 = (t77 != 0);
    if (t78 == 1)
        goto LAB184;

LAB185:
LAB186:    goto LAB179;

LAB180:    *((unsigned int *)t40) = 1;
    goto LAB183;

LAB182:    t19 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB183;

LAB184:    t79 = *((unsigned int *)t43);
    t80 = *((unsigned int *)t27);
    *((unsigned int *)t43) = (t79 | t80);
    t33 = (t10 + 4);
    t34 = (t40 + 4);
    t81 = *((unsigned int *)t10);
    t82 = (~(t81));
    t83 = *((unsigned int *)t33);
    t84 = (~(t83));
    t85 = *((unsigned int *)t40);
    t86 = (~(t85));
    t87 = *((unsigned int *)t34);
    t88 = (~(t87));
    t58 = (t82 & t84);
    t60 = (t86 & t88);
    t89 = (~(t58));
    t90 = (~(t60));
    t91 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t91 & t89);
    t92 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t92 & t90);
    t93 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t93 & t89);
    t94 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t94 & t90);
    goto LAB186;

LAB187:
LAB190:    t36 = (t1 + 7136);
    t37 = *((char **)t36);
    t36 = ((char*)((ng3)));
    memset(t45, 0, 8);
    xsi_vlog_signed_equal(t45, 32, t37, 32, t36, 32);
    memset(t46, 0, 8);
    t38 = (t45 + 4);
    t100 = *((unsigned int *)t38);
    t101 = (~(t100));
    t102 = *((unsigned int *)t45);
    t103 = (t102 & t101);
    t104 = (t103 & 1U);
    if (t104 != 0)
        goto LAB191;

LAB192:    if (*((unsigned int *)t38) != 0)
        goto LAB193;

LAB194:    t41 = (t46 + 4);
    t105 = *((unsigned int *)t46);
    t106 = *((unsigned int *)t41);
    t107 = (t105 || t106);
    if (t107 > 0)
        goto LAB195;

LAB196:    memcpy(t117, t46, 8);

LAB197:    memset(t123, 0, 8);
    t70 = (t117 + 4);
    t151 = *((unsigned int *)t70);
    t152 = (~(t151));
    t157 = *((unsigned int *)t117);
    t158 = (t157 & t152);
    t159 = (t158 & 1U);
    if (t159 != 0)
        goto LAB209;

LAB210:    if (*((unsigned int *)t70) != 0)
        goto LAB211;

LAB212:    t72 = (t123 + 4);
    t160 = *((unsigned int *)t123);
    t161 = (!(t160));
    t162 = *((unsigned int *)t72);
    t164 = (t161 || t162);
    if (t164 > 0)
        goto LAB213;

LAB214:    memcpy(t315, t123, 8);

LAB215:    t341 = (t315 + 4);
    t342 = *((unsigned int *)t341);
    t343 = (~(t342));
    t344 = *((unsigned int *)t315);
    t345 = (t344 & t343);
    t346 = (t345 != 0);
    if (t346 > 0)
        goto LAB259;

LAB260:
LAB265:    t4 = ((char*)((ng4)));
    t5 = (t1 + 24392);
    t6 = (t1 + 24392);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t1 + 24392);
    t11 = (t9 + 64U);
    t12 = *((char **)t11);
    t19 = (t1 + 28872);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    xsi_vlog_generic_convert_array_indices(t10, t18, t8, t12, 2, 1, t26, 7, 2);
    t27 = (t10 + 4);
    t13 = *((unsigned int *)t27);
    t58 = (!(t13));
    t33 = (t18 + 4);
    t14 = *((unsigned int *)t33);
    t60 = (!(t14));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB266;

LAB267:
LAB261:    t4 = (t1 + 7136);
    t5 = *((char **)t4);
    t4 = ((char*)((ng7)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    memset(t18, 0, 8);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB268;

LAB269:    if (*((unsigned int *)t6) != 0)
        goto LAB270;

LAB271:    t8 = (t18 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (!(t21));
    t23 = *((unsigned int *)t8);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB272;

LAB273:    memcpy(t45, t18, 8);

LAB274:    memset(t46, 0, 8);
    t35 = (t45 + 4);
    t92 = *((unsigned int *)t35);
    t93 = (~(t92));
    t94 = *((unsigned int *)t45);
    t95 = (t94 & t93);
    t96 = (t95 & 1U);
    if (t96 != 0)
        goto LAB282;

LAB283:    if (*((unsigned int *)t35) != 0)
        goto LAB284;

LAB285:    t37 = (t46 + 4);
    t97 = *((unsigned int *)t46);
    t98 = *((unsigned int *)t37);
    t99 = (t97 || t98);
    if (t99 > 0)
        goto LAB286;

LAB287:    memcpy(t117, t46, 8);

LAB288:    t59 = (t117 + 4);
    t143 = *((unsigned int *)t59);
    t144 = (~(t143));
    t145 = *((unsigned int *)t117);
    t146 = (t145 & t144);
    t147 = (t146 != 0);
    if (t147 > 0)
        goto LAB300;

LAB301:
LAB306:    t4 = ((char*)((ng4)));
    t5 = (t1 + 24552);
    t6 = (t1 + 24552);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t1 + 24552);
    t11 = (t9 + 64U);
    t12 = *((char **)t11);
    t19 = (t1 + 28872);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    xsi_vlog_generic_convert_array_indices(t10, t18, t8, t12, 2, 1, t26, 7, 2);
    t27 = (t10 + 4);
    t13 = *((unsigned int *)t27);
    t58 = (!(t13));
    t33 = (t18 + 4);
    t14 = *((unsigned int *)t33);
    t60 = (!(t14));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB307;

LAB308:
LAB302:    goto LAB189;

LAB191:    *((unsigned int *)t46) = 1;
    goto LAB194;

LAB193:    t39 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB194;

LAB195:    t42 = (t1 + 29352);
    t44 = (t42 + 56U);
    t48 = *((char **)t44);
    t49 = ((char*)((ng9)));
    memset(t47, 0, 8);
    t50 = (t48 + 4);
    t51 = (t49 + 4);
    t108 = *((unsigned int *)t48);
    t109 = *((unsigned int *)t49);
    t110 = (t108 ^ t109);
    t111 = *((unsigned int *)t50);
    t112 = *((unsigned int *)t51);
    t113 = (t111 ^ t112);
    t114 = (t110 | t113);
    t115 = *((unsigned int *)t50);
    t116 = *((unsigned int *)t51);
    t118 = (t115 | t116);
    t119 = (~(t118));
    t120 = (t114 & t119);
    if (t120 != 0)
        goto LAB201;

LAB198:    if (t118 != 0)
        goto LAB200;

LAB199:    *((unsigned int *)t47) = 1;

LAB201:    memset(t55, 0, 8);
    t53 = (t47 + 4);
    t121 = *((unsigned int *)t53);
    t122 = (~(t121));
    t124 = *((unsigned int *)t47);
    t125 = (t124 & t122);
    t126 = (t125 & 1U);
    if (t126 != 0)
        goto LAB202;

LAB203:    if (*((unsigned int *)t53) != 0)
        goto LAB204;

LAB205:    t127 = *((unsigned int *)t46);
    t128 = *((unsigned int *)t55);
    t129 = (t127 & t128);
    *((unsigned int *)t117) = t129;
    t56 = (t46 + 4);
    t57 = (t55 + 4);
    t59 = (t117 + 4);
    t130 = *((unsigned int *)t56);
    t131 = *((unsigned int *)t57);
    t132 = (t130 | t131);
    *((unsigned int *)t59) = t132;
    t133 = *((unsigned int *)t59);
    t134 = (t133 != 0);
    if (t134 == 1)
        goto LAB206;

LAB207:
LAB208:    goto LAB197;

LAB200:    t52 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB201;

LAB202:    *((unsigned int *)t55) = 1;
    goto LAB205;

LAB204:    t54 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB205;

LAB206:    t135 = *((unsigned int *)t117);
    t136 = *((unsigned int *)t59);
    *((unsigned int *)t117) = (t135 | t136);
    t62 = (t46 + 4);
    t69 = (t55 + 4);
    t137 = *((unsigned int *)t46);
    t138 = (~(t137));
    t139 = *((unsigned int *)t62);
    t140 = (~(t139));
    t141 = *((unsigned int *)t55);
    t142 = (~(t141));
    t143 = *((unsigned int *)t69);
    t144 = (~(t143));
    t61 = (t138 & t140);
    t63 = (t142 & t144);
    t145 = (~(t61));
    t146 = (~(t63));
    t147 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t147 & t145);
    t148 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t148 & t146);
    t149 = *((unsigned int *)t117);
    *((unsigned int *)t117) = (t149 & t145);
    t150 = *((unsigned int *)t117);
    *((unsigned int *)t117) = (t150 & t146);
    goto LAB208;

LAB209:    *((unsigned int *)t123) = 1;
    goto LAB212;

LAB211:    t71 = (t123 + 4);
    *((unsigned int *)t123) = 1;
    *((unsigned int *)t71) = 1;
    goto LAB212;

LAB213:    t73 = (t1 + 7136);
    t155 = *((char **)t73);
    t73 = ((char*)((ng8)));
    memset(t153, 0, 8);
    xsi_vlog_signed_equal(t153, 32, t155, 32, t73, 32);
    memset(t154, 0, 8);
    t156 = (t153 + 4);
    t165 = *((unsigned int *)t156);
    t166 = (~(t165));
    t167 = *((unsigned int *)t153);
    t168 = (t167 & t166);
    t177 = (t168 & 1U);
    if (t177 != 0)
        goto LAB216;

LAB217:    if (*((unsigned int *)t156) != 0)
        goto LAB218;

LAB219:    t169 = (t154 + 4);
    t183 = *((unsigned int *)t154);
    t184 = *((unsigned int *)t169);
    t185 = (t183 || t184);
    if (t185 > 0)
        goto LAB220;

LAB221:    memcpy(t207, t154, 8);

LAB222:    memset(t237, 0, 8);
    t238 = (t207 + 4);
    t239 = *((unsigned int *)t238);
    t240 = (~(t239));
    t241 = *((unsigned int *)t207);
    t242 = (t241 & t240);
    t243 = (t242 & 1U);
    if (t243 != 0)
        goto LAB234;

LAB235:    if (*((unsigned int *)t238) != 0)
        goto LAB236;

LAB237:    t245 = (t237 + 4);
    t246 = *((unsigned int *)t237);
    t247 = *((unsigned int *)t245);
    t248 = (t246 || t247);
    if (t248 > 0)
        goto LAB238;

LAB239:    memcpy(t277, t237, 8);

LAB240:    memset(t307, 0, 8);
    t308 = (t277 + 4);
    t309 = *((unsigned int *)t308);
    t310 = (~(t309));
    t311 = *((unsigned int *)t277);
    t312 = (t311 & t310);
    t313 = (t312 & 1U);
    if (t313 != 0)
        goto LAB252;

LAB253:    if (*((unsigned int *)t308) != 0)
        goto LAB254;

LAB255:    t316 = *((unsigned int *)t123);
    t317 = *((unsigned int *)t307);
    t318 = (t316 | t317);
    *((unsigned int *)t315) = t318;
    t319 = (t123 + 4);
    t320 = (t307 + 4);
    t321 = (t315 + 4);
    t322 = *((unsigned int *)t319);
    t323 = *((unsigned int *)t320);
    t324 = (t322 | t323);
    *((unsigned int *)t321) = t324;
    t325 = *((unsigned int *)t321);
    t326 = (t325 != 0);
    if (t326 == 1)
        goto LAB256;

LAB257:
LAB258:    goto LAB215;

LAB216:    *((unsigned int *)t154) = 1;
    goto LAB219;

LAB218:    t163 = (t154 + 4);
    *((unsigned int *)t154) = 1;
    *((unsigned int *)t163) = 1;
    goto LAB219;

LAB220:    t170 = (t1 + 29352);
    t172 = (t170 + 56U);
    t173 = *((char **)t172);
    t174 = ((char*)((ng9)));
    memset(t171, 0, 8);
    t175 = (t173 + 4);
    t176 = (t174 + 4);
    t186 = *((unsigned int *)t173);
    t187 = *((unsigned int *)t174);
    t188 = (t186 ^ t187);
    t189 = *((unsigned int *)t175);
    t190 = *((unsigned int *)t176);
    t191 = (t189 ^ t190);
    t192 = (t188 | t191);
    t193 = *((unsigned int *)t175);
    t194 = *((unsigned int *)t176);
    t195 = (t193 | t194);
    t196 = (~(t195));
    t197 = (t192 & t196);
    if (t197 != 0)
        goto LAB226;

LAB223:    if (t195 != 0)
        goto LAB225;

LAB224:    *((unsigned int *)t171) = 1;

LAB226:    memset(t199, 0, 8);
    t200 = (t171 + 4);
    t201 = *((unsigned int *)t200);
    t202 = (~(t201));
    t203 = *((unsigned int *)t171);
    t204 = (t203 & t202);
    t205 = (t204 & 1U);
    if (t205 != 0)
        goto LAB227;

LAB228:    if (*((unsigned int *)t200) != 0)
        goto LAB229;

LAB230:    t208 = *((unsigned int *)t154);
    t209 = *((unsigned int *)t199);
    t210 = (t208 & t209);
    *((unsigned int *)t207) = t210;
    t211 = (t154 + 4);
    t212 = (t199 + 4);
    t213 = (t207 + 4);
    t214 = *((unsigned int *)t211);
    t215 = *((unsigned int *)t212);
    t216 = (t214 | t215);
    *((unsigned int *)t213) = t216;
    t217 = *((unsigned int *)t213);
    t218 = (t217 != 0);
    if (t218 == 1)
        goto LAB231;

LAB232:
LAB233:    goto LAB222;

LAB225:    t198 = (t171 + 4);
    *((unsigned int *)t171) = 1;
    *((unsigned int *)t198) = 1;
    goto LAB226;

LAB227:    *((unsigned int *)t199) = 1;
    goto LAB230;

LAB229:    t206 = (t199 + 4);
    *((unsigned int *)t199) = 1;
    *((unsigned int *)t206) = 1;
    goto LAB230;

LAB231:    t219 = *((unsigned int *)t207);
    t220 = *((unsigned int *)t213);
    *((unsigned int *)t207) = (t219 | t220);
    t221 = (t154 + 4);
    t222 = (t199 + 4);
    t223 = *((unsigned int *)t154);
    t224 = (~(t223));
    t225 = *((unsigned int *)t221);
    t226 = (~(t225));
    t227 = *((unsigned int *)t199);
    t228 = (~(t227));
    t229 = *((unsigned int *)t222);
    t230 = (~(t229));
    t64 = (t224 & t226);
    t65 = (t228 & t230);
    t231 = (~(t64));
    t232 = (~(t65));
    t233 = *((unsigned int *)t213);
    *((unsigned int *)t213) = (t233 & t231);
    t234 = *((unsigned int *)t213);
    *((unsigned int *)t213) = (t234 & t232);
    t235 = *((unsigned int *)t207);
    *((unsigned int *)t207) = (t235 & t231);
    t236 = *((unsigned int *)t207);
    *((unsigned int *)t207) = (t236 & t232);
    goto LAB233;

LAB234:    *((unsigned int *)t237) = 1;
    goto LAB237;

LAB236:    t244 = (t237 + 4);
    *((unsigned int *)t237) = 1;
    *((unsigned int *)t244) = 1;
    goto LAB237;

LAB238:    t249 = (t1 + 29512);
    t250 = (t249 + 56U);
    t251 = *((char **)t250);
    t252 = ((char*)((ng9)));
    memset(t253, 0, 8);
    t254 = (t251 + 4);
    t255 = (t252 + 4);
    t256 = *((unsigned int *)t251);
    t257 = *((unsigned int *)t252);
    t258 = (t256 ^ t257);
    t259 = *((unsigned int *)t254);
    t260 = *((unsigned int *)t255);
    t261 = (t259 ^ t260);
    t262 = (t258 | t261);
    t263 = *((unsigned int *)t254);
    t264 = *((unsigned int *)t255);
    t265 = (t263 | t264);
    t266 = (~(t265));
    t267 = (t262 & t266);
    if (t267 != 0)
        goto LAB242;

LAB241:    if (t265 != 0)
        goto LAB243;

LAB244:    memset(t269, 0, 8);
    t270 = (t253 + 4);
    t271 = *((unsigned int *)t270);
    t272 = (~(t271));
    t273 = *((unsigned int *)t253);
    t274 = (t273 & t272);
    t275 = (t274 & 1U);
    if (t275 != 0)
        goto LAB245;

LAB246:    if (*((unsigned int *)t270) != 0)
        goto LAB247;

LAB248:    t278 = *((unsigned int *)t237);
    t279 = *((unsigned int *)t269);
    t280 = (t278 & t279);
    *((unsigned int *)t277) = t280;
    t281 = (t237 + 4);
    t282 = (t269 + 4);
    t283 = (t277 + 4);
    t284 = *((unsigned int *)t281);
    t285 = *((unsigned int *)t282);
    t286 = (t284 | t285);
    *((unsigned int *)t283) = t286;
    t287 = *((unsigned int *)t283);
    t288 = (t287 != 0);
    if (t288 == 1)
        goto LAB249;

LAB250:
LAB251:    goto LAB240;

LAB242:    *((unsigned int *)t253) = 1;
    goto LAB244;

LAB243:    t268 = (t253 + 4);
    *((unsigned int *)t253) = 1;
    *((unsigned int *)t268) = 1;
    goto LAB244;

LAB245:    *((unsigned int *)t269) = 1;
    goto LAB248;

LAB247:    t276 = (t269 + 4);
    *((unsigned int *)t269) = 1;
    *((unsigned int *)t276) = 1;
    goto LAB248;

LAB249:    t289 = *((unsigned int *)t277);
    t290 = *((unsigned int *)t283);
    *((unsigned int *)t277) = (t289 | t290);
    t291 = (t237 + 4);
    t292 = (t269 + 4);
    t293 = *((unsigned int *)t237);
    t294 = (~(t293));
    t295 = *((unsigned int *)t291);
    t296 = (~(t295));
    t297 = *((unsigned int *)t269);
    t298 = (~(t297));
    t299 = *((unsigned int *)t292);
    t300 = (~(t299));
    t66 = (t294 & t296);
    t67 = (t298 & t300);
    t301 = (~(t66));
    t302 = (~(t67));
    t303 = *((unsigned int *)t283);
    *((unsigned int *)t283) = (t303 & t301);
    t304 = *((unsigned int *)t283);
    *((unsigned int *)t283) = (t304 & t302);
    t305 = *((unsigned int *)t277);
    *((unsigned int *)t277) = (t305 & t301);
    t306 = *((unsigned int *)t277);
    *((unsigned int *)t277) = (t306 & t302);
    goto LAB251;

LAB252:    *((unsigned int *)t307) = 1;
    goto LAB255;

LAB254:    t314 = (t307 + 4);
    *((unsigned int *)t307) = 1;
    *((unsigned int *)t314) = 1;
    goto LAB255;

LAB256:    t327 = *((unsigned int *)t315);
    t328 = *((unsigned int *)t321);
    *((unsigned int *)t315) = (t327 | t328);
    t329 = (t123 + 4);
    t330 = (t307 + 4);
    t331 = *((unsigned int *)t329);
    t332 = (~(t331));
    t333 = *((unsigned int *)t123);
    t179 = (t333 & t332);
    t334 = *((unsigned int *)t330);
    t335 = (~(t334));
    t336 = *((unsigned int *)t307);
    t180 = (t336 & t335);
    t337 = (~(t179));
    t338 = (~(t180));
    t339 = *((unsigned int *)t321);
    *((unsigned int *)t321) = (t339 & t337);
    t340 = *((unsigned int *)t321);
    *((unsigned int *)t321) = (t340 & t338);
    goto LAB258;

LAB259:
LAB262:    t347 = ((char*)((ng3)));
    t348 = (t1 + 24392);
    t351 = (t1 + 24392);
    t352 = (t351 + 72U);
    t353 = *((char **)t352);
    t354 = (t1 + 24392);
    t355 = (t354 + 64U);
    t356 = *((char **)t355);
    t357 = (t1 + 28872);
    t358 = (t357 + 56U);
    t359 = *((char **)t358);
    xsi_vlog_generic_convert_array_indices(t349, t350, t353, t356, 2, 1, t359, 7, 2);
    t360 = (t349 + 4);
    t361 = *((unsigned int *)t360);
    t181 = (!(t361));
    t362 = (t350 + 4);
    t363 = *((unsigned int *)t362);
    t182 = (!(t363));
    t364 = (t181 && t182);
    if (t364 == 1)
        goto LAB263;

LAB264:    goto LAB261;

LAB263:    t365 = *((unsigned int *)t349);
    t366 = *((unsigned int *)t350);
    t367 = (t365 - t366);
    t368 = (t367 + 1);
    xsi_vlogvar_assign_value(t348, t347, 0, *((unsigned int *)t350), t368);
    goto LAB264;

LAB266:    t15 = *((unsigned int *)t10);
    t16 = *((unsigned int *)t18);
    t63 = (t15 - t16);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t18), t64);
    goto LAB267;

LAB268:    *((unsigned int *)t18) = 1;
    goto LAB271;

LAB270:    t7 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB271;

LAB272:    t9 = (t1 + 7136);
    t11 = *((char **)t9);
    t9 = ((char*)((ng8)));
    memset(t40, 0, 8);
    xsi_vlog_signed_equal(t40, 32, t11, 32, t9, 32);
    memset(t43, 0, 8);
    t12 = (t40 + 4);
    t25 = *((unsigned int *)t12);
    t28 = (~(t25));
    t29 = *((unsigned int *)t40);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB275;

LAB276:    if (*((unsigned int *)t12) != 0)
        goto LAB277;

LAB278:    t32 = *((unsigned int *)t18);
    t68 = *((unsigned int *)t43);
    t74 = (t32 | t68);
    *((unsigned int *)t45) = t74;
    t20 = (t18 + 4);
    t26 = (t43 + 4);
    t27 = (t45 + 4);
    t75 = *((unsigned int *)t20);
    t76 = *((unsigned int *)t26);
    t77 = (t75 | t76);
    *((unsigned int *)t27) = t77;
    t78 = *((unsigned int *)t27);
    t79 = (t78 != 0);
    if (t79 == 1)
        goto LAB279;

LAB280:
LAB281:    goto LAB274;

LAB275:    *((unsigned int *)t43) = 1;
    goto LAB278;

LAB277:    t19 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB278;

LAB279:    t80 = *((unsigned int *)t45);
    t81 = *((unsigned int *)t27);
    *((unsigned int *)t45) = (t80 | t81);
    t33 = (t18 + 4);
    t34 = (t43 + 4);
    t82 = *((unsigned int *)t33);
    t83 = (~(t82));
    t84 = *((unsigned int *)t18);
    t58 = (t84 & t83);
    t85 = *((unsigned int *)t34);
    t86 = (~(t85));
    t87 = *((unsigned int *)t43);
    t60 = (t87 & t86);
    t88 = (~(t58));
    t89 = (~(t60));
    t90 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t90 & t88);
    t91 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t91 & t89);
    goto LAB281;

LAB282:    *((unsigned int *)t46) = 1;
    goto LAB285;

LAB284:    t36 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB285;

LAB286:    t38 = (t1 + 29512);
    t39 = (t38 + 56U);
    t41 = *((char **)t39);
    t42 = ((char*)((ng9)));
    memset(t47, 0, 8);
    t44 = (t41 + 4);
    t48 = (t42 + 4);
    t100 = *((unsigned int *)t41);
    t101 = *((unsigned int *)t42);
    t102 = (t100 ^ t101);
    t103 = *((unsigned int *)t44);
    t104 = *((unsigned int *)t48);
    t105 = (t103 ^ t104);
    t106 = (t102 | t105);
    t107 = *((unsigned int *)t44);
    t108 = *((unsigned int *)t48);
    t109 = (t107 | t108);
    t110 = (~(t109));
    t111 = (t106 & t110);
    if (t111 != 0)
        goto LAB292;

LAB289:    if (t109 != 0)
        goto LAB291;

LAB290:    *((unsigned int *)t47) = 1;

LAB292:    memset(t55, 0, 8);
    t50 = (t47 + 4);
    t112 = *((unsigned int *)t50);
    t113 = (~(t112));
    t114 = *((unsigned int *)t47);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB293;

LAB294:    if (*((unsigned int *)t50) != 0)
        goto LAB295;

LAB296:    t118 = *((unsigned int *)t46);
    t119 = *((unsigned int *)t55);
    t120 = (t118 & t119);
    *((unsigned int *)t117) = t120;
    t52 = (t46 + 4);
    t53 = (t55 + 4);
    t54 = (t117 + 4);
    t121 = *((unsigned int *)t52);
    t122 = *((unsigned int *)t53);
    t124 = (t121 | t122);
    *((unsigned int *)t54) = t124;
    t125 = *((unsigned int *)t54);
    t126 = (t125 != 0);
    if (t126 == 1)
        goto LAB297;

LAB298:
LAB299:    goto LAB288;

LAB291:    t49 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB292;

LAB293:    *((unsigned int *)t55) = 1;
    goto LAB296;

LAB295:    t51 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB296;

LAB297:    t127 = *((unsigned int *)t117);
    t128 = *((unsigned int *)t54);
    *((unsigned int *)t117) = (t127 | t128);
    t56 = (t46 + 4);
    t57 = (t55 + 4);
    t129 = *((unsigned int *)t46);
    t130 = (~(t129));
    t131 = *((unsigned int *)t56);
    t132 = (~(t131));
    t133 = *((unsigned int *)t55);
    t134 = (~(t133));
    t135 = *((unsigned int *)t57);
    t136 = (~(t135));
    t61 = (t130 & t132);
    t63 = (t134 & t136);
    t137 = (~(t61));
    t138 = (~(t63));
    t139 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t139 & t137);
    t140 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t140 & t138);
    t141 = *((unsigned int *)t117);
    *((unsigned int *)t117) = (t141 & t137);
    t142 = *((unsigned int *)t117);
    *((unsigned int *)t117) = (t142 & t138);
    goto LAB299;

LAB300:
LAB303:    t62 = ((char*)((ng3)));
    t69 = (t1 + 24552);
    t70 = (t1 + 24552);
    t71 = (t70 + 72U);
    t72 = *((char **)t71);
    t73 = (t1 + 24552);
    t155 = (t73 + 64U);
    t156 = *((char **)t155);
    t163 = (t1 + 28872);
    t169 = (t163 + 56U);
    t170 = *((char **)t169);
    xsi_vlog_generic_convert_array_indices(t123, t153, t72, t156, 2, 1, t170, 7, 2);
    t172 = (t123 + 4);
    t148 = *((unsigned int *)t172);
    t64 = (!(t148));
    t173 = (t153 + 4);
    t149 = *((unsigned int *)t173);
    t65 = (!(t149));
    t66 = (t64 && t65);
    if (t66 == 1)
        goto LAB304;

LAB305:    goto LAB302;

LAB304:    t150 = *((unsigned int *)t123);
    t151 = *((unsigned int *)t153);
    t67 = (t150 - t151);
    t179 = (t67 + 1);
    xsi_vlogvar_assign_value(t69, t62, 0, *((unsigned int *)t153), t179);
    goto LAB305;

LAB307:    t15 = *((unsigned int *)t10);
    t16 = *((unsigned int *)t18);
    t63 = (t15 - t16);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t18), t64);
    goto LAB308;

LAB309:
LAB312:    t7 = (t1 + 7136);
    t8 = *((char **)t7);
    t7 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t8, 32, t7, 32);
    memset(t40, 0, 8);
    t9 = (t18 + 4);
    t21 = *((unsigned int *)t9);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB313;

LAB314:    if (*((unsigned int *)t9) != 0)
        goto LAB315;

LAB316:    t12 = (t40 + 4);
    t28 = *((unsigned int *)t40);
    t29 = *((unsigned int *)t12);
    t30 = (t28 || t29);
    if (t30 > 0)
        goto LAB317;

LAB318:    memcpy(t46, t40, 8);

LAB319:    memset(t47, 0, 8);
    t48 = (t46 + 4);
    t112 = *((unsigned int *)t48);
    t113 = (~(t112));
    t114 = *((unsigned int *)t46);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB331;

LAB332:    if (*((unsigned int *)t48) != 0)
        goto LAB333;

LAB334:    t50 = (t47 + 4);
    t118 = *((unsigned int *)t47);
    t119 = (!(t118));
    t120 = *((unsigned int *)t50);
    t121 = (t119 || t120);
    if (t121 > 0)
        goto LAB335;

LAB336:    memcpy(t269, t47, 8);

LAB337:    t281 = (t269 + 4);
    t295 = *((unsigned int *)t281);
    t296 = (~(t295));
    t297 = *((unsigned int *)t269);
    t298 = (t297 & t296);
    t299 = (t298 != 0);
    if (t299 > 0)
        goto LAB381;

LAB382:
LAB387:    t4 = ((char*)((ng4)));
    t5 = (t1 + 24712);
    t6 = (t1 + 24712);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t1 + 24712);
    t11 = (t9 + 64U);
    t12 = *((char **)t11);
    t19 = (t1 + 28872);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    xsi_vlog_generic_convert_array_indices(t10, t18, t8, t12, 2, 1, t26, 7, 2);
    t27 = (t10 + 4);
    t13 = *((unsigned int *)t27);
    t58 = (!(t13));
    t33 = (t18 + 4);
    t14 = *((unsigned int *)t33);
    t60 = (!(t14));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB388;

LAB389:
LAB383:    t4 = (t1 + 7136);
    t5 = *((char **)t4);
    t4 = ((char*)((ng7)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    memset(t18, 0, 8);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB390;

LAB391:    if (*((unsigned int *)t6) != 0)
        goto LAB392;

LAB393:    t8 = (t18 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (!(t21));
    t23 = *((unsigned int *)t8);
    t24 = (t22 || t23);
    if (t24 > 0)
        goto LAB394;

LAB395:    memcpy(t45, t18, 8);

LAB396:    memset(t46, 0, 8);
    t35 = (t45 + 4);
    t92 = *((unsigned int *)t35);
    t93 = (~(t92));
    t94 = *((unsigned int *)t45);
    t95 = (t94 & t93);
    t96 = (t95 & 1U);
    if (t96 != 0)
        goto LAB404;

LAB405:    if (*((unsigned int *)t35) != 0)
        goto LAB406;

LAB407:    t37 = (t46 + 4);
    t97 = *((unsigned int *)t46);
    t98 = *((unsigned int *)t37);
    t99 = (t97 || t98);
    if (t99 > 0)
        goto LAB408;

LAB409:    memcpy(t117, t46, 8);

LAB410:    t59 = (t117 + 4);
    t143 = *((unsigned int *)t59);
    t144 = (~(t143));
    t145 = *((unsigned int *)t117);
    t146 = (t145 & t144);
    t147 = (t146 != 0);
    if (t147 > 0)
        goto LAB422;

LAB423:
LAB428:    t4 = ((char*)((ng4)));
    t5 = (t1 + 24872);
    t6 = (t1 + 24872);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t1 + 24872);
    t11 = (t9 + 64U);
    t12 = *((char **)t11);
    t19 = (t1 + 28872);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    xsi_vlog_generic_convert_array_indices(t10, t18, t8, t12, 2, 1, t26, 7, 2);
    t27 = (t10 + 4);
    t13 = *((unsigned int *)t27);
    t58 = (!(t13));
    t33 = (t18 + 4);
    t14 = *((unsigned int *)t33);
    t60 = (!(t14));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB429;

LAB430:
LAB424:    goto LAB311;

LAB313:    *((unsigned int *)t40) = 1;
    goto LAB316;

LAB315:    t11 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB316;

LAB317:    t19 = (t1 + 29352);
    t20 = (t19 + 56U);
    t26 = *((char **)t20);
    t27 = ((char*)((ng9)));
    memset(t43, 0, 8);
    t33 = (t26 + 4);
    t34 = (t27 + 4);
    t31 = *((unsigned int *)t26);
    t32 = *((unsigned int *)t27);
    t68 = (t31 ^ t32);
    t74 = *((unsigned int *)t33);
    t75 = *((unsigned int *)t34);
    t76 = (t74 ^ t75);
    t77 = (t68 | t76);
    t78 = *((unsigned int *)t33);
    t79 = *((unsigned int *)t34);
    t80 = (t78 | t79);
    t81 = (~(t80));
    t82 = (t77 & t81);
    if (t82 != 0)
        goto LAB323;

LAB320:    if (t80 != 0)
        goto LAB322;

LAB321:    *((unsigned int *)t43) = 1;

LAB323:    memset(t45, 0, 8);
    t36 = (t43 + 4);
    t83 = *((unsigned int *)t36);
    t84 = (~(t83));
    t85 = *((unsigned int *)t43);
    t86 = (t85 & t84);
    t87 = (t86 & 1U);
    if (t87 != 0)
        goto LAB324;

LAB325:    if (*((unsigned int *)t36) != 0)
        goto LAB326;

LAB327:    t88 = *((unsigned int *)t40);
    t89 = *((unsigned int *)t45);
    t90 = (t88 & t89);
    *((unsigned int *)t46) = t90;
    t38 = (t40 + 4);
    t39 = (t45 + 4);
    t41 = (t46 + 4);
    t91 = *((unsigned int *)t38);
    t92 = *((unsigned int *)t39);
    t93 = (t91 | t92);
    *((unsigned int *)t41) = t93;
    t94 = *((unsigned int *)t41);
    t95 = (t94 != 0);
    if (t95 == 1)
        goto LAB328;

LAB329:
LAB330:    goto LAB319;

LAB322:    t35 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB323;

LAB324:    *((unsigned int *)t45) = 1;
    goto LAB327;

LAB326:    t37 = (t45 + 4);
    *((unsigned int *)t45) = 1;
    *((unsigned int *)t37) = 1;
    goto LAB327;

LAB328:    t96 = *((unsigned int *)t46);
    t97 = *((unsigned int *)t41);
    *((unsigned int *)t46) = (t96 | t97);
    t42 = (t40 + 4);
    t44 = (t45 + 4);
    t98 = *((unsigned int *)t40);
    t99 = (~(t98));
    t100 = *((unsigned int *)t42);
    t101 = (~(t100));
    t102 = *((unsigned int *)t45);
    t103 = (~(t102));
    t104 = *((unsigned int *)t44);
    t105 = (~(t104));
    t58 = (t99 & t101);
    t60 = (t103 & t105);
    t106 = (~(t58));
    t107 = (~(t60));
    t108 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t108 & t106);
    t109 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t109 & t107);
    t110 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t110 & t106);
    t111 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t111 & t107);
    goto LAB330;

LAB331:    *((unsigned int *)t47) = 1;
    goto LAB334;

LAB333:    t49 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB334;

LAB335:    t51 = (t1 + 7136);
    t52 = *((char **)t51);
    t51 = ((char*)((ng8)));
    memset(t55, 0, 8);
    xsi_vlog_signed_equal(t55, 32, t52, 32, t51, 32);
    memset(t117, 0, 8);
    t53 = (t55 + 4);
    t122 = *((unsigned int *)t53);
    t124 = (~(t122));
    t125 = *((unsigned int *)t55);
    t126 = (t125 & t124);
    t127 = (t126 & 1U);
    if (t127 != 0)
        goto LAB338;

LAB339:    if (*((unsigned int *)t53) != 0)
        goto LAB340;

LAB341:    t56 = (t117 + 4);
    t128 = *((unsigned int *)t117);
    t129 = *((unsigned int *)t56);
    t130 = (t128 || t129);
    if (t130 > 0)
        goto LAB342;

LAB343:    memcpy(t154, t117, 8);

LAB344:    memset(t171, 0, 8);
    t173 = (t154 + 4);
    t190 = *((unsigned int *)t173);
    t191 = (~(t190));
    t192 = *((unsigned int *)t154);
    t193 = (t192 & t191);
    t194 = (t193 & 1U);
    if (t194 != 0)
        goto LAB356;

LAB357:    if (*((unsigned int *)t173) != 0)
        goto LAB358;

LAB359:    t175 = (t171 + 4);
    t195 = *((unsigned int *)t171);
    t196 = *((unsigned int *)t175);
    t197 = (t195 || t196);
    if (t197 > 0)
        goto LAB360;

LAB361:    memcpy(t237, t171, 8);

LAB362:    memset(t253, 0, 8);
    t251 = (t237 + 4);
    t260 = *((unsigned int *)t251);
    t261 = (~(t260));
    t262 = *((unsigned int *)t237);
    t263 = (t262 & t261);
    t264 = (t263 & 1U);
    if (t264 != 0)
        goto LAB374;

LAB375:    if (*((unsigned int *)t251) != 0)
        goto LAB376;

LAB377:    t265 = *((unsigned int *)t47);
    t266 = *((unsigned int *)t253);
    t267 = (t265 | t266);
    *((unsigned int *)t269) = t267;
    t254 = (t47 + 4);
    t255 = (t253 + 4);
    t268 = (t269 + 4);
    t271 = *((unsigned int *)t254);
    t272 = *((unsigned int *)t255);
    t273 = (t271 | t272);
    *((unsigned int *)t268) = t273;
    t274 = *((unsigned int *)t268);
    t275 = (t274 != 0);
    if (t275 == 1)
        goto LAB378;

LAB379:
LAB380:    goto LAB337;

LAB338:    *((unsigned int *)t117) = 1;
    goto LAB341;

LAB340:    t54 = (t117 + 4);
    *((unsigned int *)t117) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB341;

LAB342:    t57 = (t1 + 29352);
    t59 = (t57 + 56U);
    t62 = *((char **)t59);
    t69 = ((char*)((ng9)));
    memset(t123, 0, 8);
    t70 = (t62 + 4);
    t71 = (t69 + 4);
    t131 = *((unsigned int *)t62);
    t132 = *((unsigned int *)t69);
    t133 = (t131 ^ t132);
    t134 = *((unsigned int *)t70);
    t135 = *((unsigned int *)t71);
    t136 = (t134 ^ t135);
    t137 = (t133 | t136);
    t138 = *((unsigned int *)t70);
    t139 = *((unsigned int *)t71);
    t140 = (t138 | t139);
    t141 = (~(t140));
    t142 = (t137 & t141);
    if (t142 != 0)
        goto LAB348;

LAB345:    if (t140 != 0)
        goto LAB347;

LAB346:    *((unsigned int *)t123) = 1;

LAB348:    memset(t153, 0, 8);
    t73 = (t123 + 4);
    t143 = *((unsigned int *)t73);
    t144 = (~(t143));
    t145 = *((unsigned int *)t123);
    t146 = (t145 & t144);
    t147 = (t146 & 1U);
    if (t147 != 0)
        goto LAB349;

LAB350:    if (*((unsigned int *)t73) != 0)
        goto LAB351;

LAB352:    t148 = *((unsigned int *)t117);
    t149 = *((unsigned int *)t153);
    t150 = (t148 & t149);
    *((unsigned int *)t154) = t150;
    t156 = (t117 + 4);
    t163 = (t153 + 4);
    t169 = (t154 + 4);
    t151 = *((unsigned int *)t156);
    t152 = *((unsigned int *)t163);
    t157 = (t151 | t152);
    *((unsigned int *)t169) = t157;
    t158 = *((unsigned int *)t169);
    t159 = (t158 != 0);
    if (t159 == 1)
        goto LAB353;

LAB354:
LAB355:    goto LAB344;

LAB347:    t72 = (t123 + 4);
    *((unsigned int *)t123) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB348;

LAB349:    *((unsigned int *)t153) = 1;
    goto LAB352;

LAB351:    t155 = (t153 + 4);
    *((unsigned int *)t153) = 1;
    *((unsigned int *)t155) = 1;
    goto LAB352;

LAB353:    t160 = *((unsigned int *)t154);
    t161 = *((unsigned int *)t169);
    *((unsigned int *)t154) = (t160 | t161);
    t170 = (t117 + 4);
    t172 = (t153 + 4);
    t162 = *((unsigned int *)t117);
    t164 = (~(t162));
    t165 = *((unsigned int *)t170);
    t166 = (~(t165));
    t167 = *((unsigned int *)t153);
    t168 = (~(t167));
    t177 = *((unsigned int *)t172);
    t183 = (~(t177));
    t61 = (t164 & t166);
    t63 = (t168 & t183);
    t184 = (~(t61));
    t185 = (~(t63));
    t186 = *((unsigned int *)t169);
    *((unsigned int *)t169) = (t186 & t184);
    t187 = *((unsigned int *)t169);
    *((unsigned int *)t169) = (t187 & t185);
    t188 = *((unsigned int *)t154);
    *((unsigned int *)t154) = (t188 & t184);
    t189 = *((unsigned int *)t154);
    *((unsigned int *)t154) = (t189 & t185);
    goto LAB355;

LAB356:    *((unsigned int *)t171) = 1;
    goto LAB359;

LAB358:    t174 = (t171 + 4);
    *((unsigned int *)t171) = 1;
    *((unsigned int *)t174) = 1;
    goto LAB359;

LAB360:    t176 = (t1 + 29512);
    t198 = (t176 + 56U);
    t200 = *((char **)t198);
    t206 = ((char*)((ng9)));
    memset(t199, 0, 8);
    t211 = (t200 + 4);
    t212 = (t206 + 4);
    t201 = *((unsigned int *)t200);
    t202 = *((unsigned int *)t206);
    t203 = (t201 ^ t202);
    t204 = *((unsigned int *)t211);
    t205 = *((unsigned int *)t212);
    t208 = (t204 ^ t205);
    t209 = (t203 | t208);
    t210 = *((unsigned int *)t211);
    t214 = *((unsigned int *)t212);
    t215 = (t210 | t214);
    t216 = (~(t215));
    t217 = (t209 & t216);
    if (t217 != 0)
        goto LAB364;

LAB363:    if (t215 != 0)
        goto LAB365;

LAB366:    memset(t207, 0, 8);
    t221 = (t199 + 4);
    t218 = *((unsigned int *)t221);
    t219 = (~(t218));
    t220 = *((unsigned int *)t199);
    t223 = (t220 & t219);
    t224 = (t223 & 1U);
    if (t224 != 0)
        goto LAB367;

LAB368:    if (*((unsigned int *)t221) != 0)
        goto LAB369;

LAB370:    t225 = *((unsigned int *)t171);
    t226 = *((unsigned int *)t207);
    t227 = (t225 & t226);
    *((unsigned int *)t237) = t227;
    t238 = (t171 + 4);
    t244 = (t207 + 4);
    t245 = (t237 + 4);
    t228 = *((unsigned int *)t238);
    t229 = *((unsigned int *)t244);
    t230 = (t228 | t229);
    *((unsigned int *)t245) = t230;
    t231 = *((unsigned int *)t245);
    t232 = (t231 != 0);
    if (t232 == 1)
        goto LAB371;

LAB372:
LAB373:    goto LAB362;

LAB364:    *((unsigned int *)t199) = 1;
    goto LAB366;

LAB365:    t213 = (t199 + 4);
    *((unsigned int *)t199) = 1;
    *((unsigned int *)t213) = 1;
    goto LAB366;

LAB367:    *((unsigned int *)t207) = 1;
    goto LAB370;

LAB369:    t222 = (t207 + 4);
    *((unsigned int *)t207) = 1;
    *((unsigned int *)t222) = 1;
    goto LAB370;

LAB371:    t233 = *((unsigned int *)t237);
    t234 = *((unsigned int *)t245);
    *((unsigned int *)t237) = (t233 | t234);
    t249 = (t171 + 4);
    t250 = (t207 + 4);
    t235 = *((unsigned int *)t171);
    t236 = (~(t235));
    t239 = *((unsigned int *)t249);
    t240 = (~(t239));
    t241 = *((unsigned int *)t207);
    t242 = (~(t241));
    t243 = *((unsigned int *)t250);
    t246 = (~(t243));
    t64 = (t236 & t240);
    t65 = (t242 & t246);
    t247 = (~(t64));
    t248 = (~(t65));
    t256 = *((unsigned int *)t245);
    *((unsigned int *)t245) = (t256 & t247);
    t257 = *((unsigned int *)t245);
    *((unsigned int *)t245) = (t257 & t248);
    t258 = *((unsigned int *)t237);
    *((unsigned int *)t237) = (t258 & t247);
    t259 = *((unsigned int *)t237);
    *((unsigned int *)t237) = (t259 & t248);
    goto LAB373;

LAB374:    *((unsigned int *)t253) = 1;
    goto LAB377;

LAB376:    t252 = (t253 + 4);
    *((unsigned int *)t253) = 1;
    *((unsigned int *)t252) = 1;
    goto LAB377;

LAB378:    t278 = *((unsigned int *)t269);
    t279 = *((unsigned int *)t268);
    *((unsigned int *)t269) = (t278 | t279);
    t270 = (t47 + 4);
    t276 = (t253 + 4);
    t280 = *((unsigned int *)t270);
    t284 = (~(t280));
    t285 = *((unsigned int *)t47);
    t66 = (t285 & t284);
    t286 = *((unsigned int *)t276);
    t287 = (~(t286));
    t288 = *((unsigned int *)t253);
    t67 = (t288 & t287);
    t289 = (~(t66));
    t290 = (~(t67));
    t293 = *((unsigned int *)t268);
    *((unsigned int *)t268) = (t293 & t289);
    t294 = *((unsigned int *)t268);
    *((unsigned int *)t268) = (t294 & t290);
    goto LAB380;

LAB381:
LAB384:    t282 = ((char*)((ng3)));
    t283 = (t1 + 24712);
    t291 = (t1 + 24712);
    t292 = (t291 + 72U);
    t308 = *((char **)t292);
    t314 = (t1 + 24712);
    t319 = (t314 + 64U);
    t320 = *((char **)t319);
    t321 = (t1 + 28872);
    t329 = (t321 + 56U);
    t330 = *((char **)t329);
    xsi_vlog_generic_convert_array_indices(t277, t307, t308, t320, 2, 1, t330, 7, 2);
    t341 = (t277 + 4);
    t300 = *((unsigned int *)t341);
    t179 = (!(t300));
    t347 = (t307 + 4);
    t301 = *((unsigned int *)t347);
    t180 = (!(t301));
    t181 = (t179 && t180);
    if (t181 == 1)
        goto LAB385;

LAB386:    goto LAB383;

LAB385:    t302 = *((unsigned int *)t277);
    t303 = *((unsigned int *)t307);
    t182 = (t302 - t303);
    t364 = (t182 + 1);
    xsi_vlogvar_assign_value(t283, t282, 0, *((unsigned int *)t307), t364);
    goto LAB386;

LAB388:    t15 = *((unsigned int *)t10);
    t16 = *((unsigned int *)t18);
    t63 = (t15 - t16);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t18), t64);
    goto LAB389;

LAB390:    *((unsigned int *)t18) = 1;
    goto LAB393;

LAB392:    t7 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB393;

LAB394:    t9 = (t1 + 7136);
    t11 = *((char **)t9);
    t9 = ((char*)((ng8)));
    memset(t40, 0, 8);
    xsi_vlog_signed_equal(t40, 32, t11, 32, t9, 32);
    memset(t43, 0, 8);
    t12 = (t40 + 4);
    t25 = *((unsigned int *)t12);
    t28 = (~(t25));
    t29 = *((unsigned int *)t40);
    t30 = (t29 & t28);
    t31 = (t30 & 1U);
    if (t31 != 0)
        goto LAB397;

LAB398:    if (*((unsigned int *)t12) != 0)
        goto LAB399;

LAB400:    t32 = *((unsigned int *)t18);
    t68 = *((unsigned int *)t43);
    t74 = (t32 | t68);
    *((unsigned int *)t45) = t74;
    t20 = (t18 + 4);
    t26 = (t43 + 4);
    t27 = (t45 + 4);
    t75 = *((unsigned int *)t20);
    t76 = *((unsigned int *)t26);
    t77 = (t75 | t76);
    *((unsigned int *)t27) = t77;
    t78 = *((unsigned int *)t27);
    t79 = (t78 != 0);
    if (t79 == 1)
        goto LAB401;

LAB402:
LAB403:    goto LAB396;

LAB397:    *((unsigned int *)t43) = 1;
    goto LAB400;

LAB399:    t19 = (t43 + 4);
    *((unsigned int *)t43) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB400;

LAB401:    t80 = *((unsigned int *)t45);
    t81 = *((unsigned int *)t27);
    *((unsigned int *)t45) = (t80 | t81);
    t33 = (t18 + 4);
    t34 = (t43 + 4);
    t82 = *((unsigned int *)t33);
    t83 = (~(t82));
    t84 = *((unsigned int *)t18);
    t58 = (t84 & t83);
    t85 = *((unsigned int *)t34);
    t86 = (~(t85));
    t87 = *((unsigned int *)t43);
    t60 = (t87 & t86);
    t88 = (~(t58));
    t89 = (~(t60));
    t90 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t90 & t88);
    t91 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t91 & t89);
    goto LAB403;

LAB404:    *((unsigned int *)t46) = 1;
    goto LAB407;

LAB406:    t36 = (t46 + 4);
    *((unsigned int *)t46) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB407;

LAB408:    t38 = (t1 + 29512);
    t39 = (t38 + 56U);
    t41 = *((char **)t39);
    t42 = ((char*)((ng9)));
    memset(t47, 0, 8);
    t44 = (t41 + 4);
    t48 = (t42 + 4);
    t100 = *((unsigned int *)t41);
    t101 = *((unsigned int *)t42);
    t102 = (t100 ^ t101);
    t103 = *((unsigned int *)t44);
    t104 = *((unsigned int *)t48);
    t105 = (t103 ^ t104);
    t106 = (t102 | t105);
    t107 = *((unsigned int *)t44);
    t108 = *((unsigned int *)t48);
    t109 = (t107 | t108);
    t110 = (~(t109));
    t111 = (t106 & t110);
    if (t111 != 0)
        goto LAB414;

LAB411:    if (t109 != 0)
        goto LAB413;

LAB412:    *((unsigned int *)t47) = 1;

LAB414:    memset(t55, 0, 8);
    t50 = (t47 + 4);
    t112 = *((unsigned int *)t50);
    t113 = (~(t112));
    t114 = *((unsigned int *)t47);
    t115 = (t114 & t113);
    t116 = (t115 & 1U);
    if (t116 != 0)
        goto LAB415;

LAB416:    if (*((unsigned int *)t50) != 0)
        goto LAB417;

LAB418:    t118 = *((unsigned int *)t46);
    t119 = *((unsigned int *)t55);
    t120 = (t118 & t119);
    *((unsigned int *)t117) = t120;
    t52 = (t46 + 4);
    t53 = (t55 + 4);
    t54 = (t117 + 4);
    t121 = *((unsigned int *)t52);
    t122 = *((unsigned int *)t53);
    t124 = (t121 | t122);
    *((unsigned int *)t54) = t124;
    t125 = *((unsigned int *)t54);
    t126 = (t125 != 0);
    if (t126 == 1)
        goto LAB419;

LAB420:
LAB421:    goto LAB410;

LAB413:    t49 = (t47 + 4);
    *((unsigned int *)t47) = 1;
    *((unsigned int *)t49) = 1;
    goto LAB414;

LAB415:    *((unsigned int *)t55) = 1;
    goto LAB418;

LAB417:    t51 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t51) = 1;
    goto LAB418;

LAB419:    t127 = *((unsigned int *)t117);
    t128 = *((unsigned int *)t54);
    *((unsigned int *)t117) = (t127 | t128);
    t56 = (t46 + 4);
    t57 = (t55 + 4);
    t129 = *((unsigned int *)t46);
    t130 = (~(t129));
    t131 = *((unsigned int *)t56);
    t132 = (~(t131));
    t133 = *((unsigned int *)t55);
    t134 = (~(t133));
    t135 = *((unsigned int *)t57);
    t136 = (~(t135));
    t61 = (t130 & t132);
    t63 = (t134 & t136);
    t137 = (~(t61));
    t138 = (~(t63));
    t139 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t139 & t137);
    t140 = *((unsigned int *)t54);
    *((unsigned int *)t54) = (t140 & t138);
    t141 = *((unsigned int *)t117);
    *((unsigned int *)t117) = (t141 & t137);
    t142 = *((unsigned int *)t117);
    *((unsigned int *)t117) = (t142 & t138);
    goto LAB421;

LAB422:
LAB425:    t62 = ((char*)((ng3)));
    t69 = (t1 + 24872);
    t70 = (t1 + 24872);
    t71 = (t70 + 72U);
    t72 = *((char **)t71);
    t73 = (t1 + 24872);
    t155 = (t73 + 64U);
    t156 = *((char **)t155);
    t163 = (t1 + 28872);
    t169 = (t163 + 56U);
    t170 = *((char **)t169);
    xsi_vlog_generic_convert_array_indices(t123, t153, t72, t156, 2, 1, t170, 7, 2);
    t172 = (t123 + 4);
    t148 = *((unsigned int *)t172);
    t64 = (!(t148));
    t173 = (t153 + 4);
    t149 = *((unsigned int *)t173);
    t65 = (!(t149));
    t66 = (t64 && t65);
    if (t66 == 1)
        goto LAB426;

LAB427:    goto LAB424;

LAB426:    t150 = *((unsigned int *)t123);
    t151 = *((unsigned int *)t153);
    t67 = (t150 - t151);
    t179 = (t67 + 1);
    xsi_vlogvar_assign_value(t69, t62, 0, *((unsigned int *)t153), t179);
    goto LAB427;

LAB429:    t15 = *((unsigned int *)t10);
    t16 = *((unsigned int *)t18);
    t63 = (t15 - t16);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t5, t4, 0, *((unsigned int *)t18), t64);
    goto LAB430;

}

static int sp_write_b(char *t1, char *t2)
{
    char t10[8];
    char t18[8];
    char t40[8];
    char t43[8];
    char t45[8];
    char t46[8];
    char t47[8];
    char t55[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t41;
    char *t42;
    char *t44;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t56;
    char *t57;
    int t58;
    char *t59;
    int t60;
    int t61;
    char *t62;
    int t63;
    int t64;
    int t65;
    int t66;
    int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 12976);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 30152);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t1 + 10264);
    t9 = *((char **)t8);
    memset(t10, 0, 8);
    xsi_vlog_unsigned_divide(t10, 32, t7, 7, t9, 32);
    t8 = (t1 + 30792);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 7);
    t4 = (t1 + 30792);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5504);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB7;

LAB6:    t9 = (t8 + 4);
    if (*((unsigned int *)t9) != 0)
        goto LAB7;

LAB10:    if (*((unsigned int *)t6) < *((unsigned int *)t8))
        goto LAB9;

LAB8:    *((unsigned int *)t10) = 1;

LAB9:    t12 = (t10 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB11;

LAB12:
LAB23:    t4 = (t1 + 4824);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t13 = *((unsigned int *)t4);
    t14 = (~(t13));
    t15 = *((unsigned int *)t5);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB24;

LAB25:
LAB58:    t4 = (t1 + 30472);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 30632);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);

LAB26:    t4 = (t1 + 9720);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB59;

LAB60:
LAB65:    t4 = ((char*)((ng4)));
    t5 = (t1 + 30952);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB66:    t4 = (t1 + 30952);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9720);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB67;

LAB68:
LAB61:
LAB13:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB7:    t11 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB9;

LAB11:
LAB14:    t19 = (t1 + 7816);
    t20 = *((char **)t19);
    memset(t18, 0, 8);
    t19 = (t20 + 4);
    t21 = *((unsigned int *)t19);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB18;

LAB16:    if (*((unsigned int *)t19) == 0)
        goto LAB15;

LAB17:    t26 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t26) = 1;

LAB18:    t27 = (t18 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t18);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB19;

LAB20:
LAB21:    goto LAB13;

LAB15:    *((unsigned int *)t18) = 1;
    goto LAB18;

LAB19:
LAB22:    t33 = ((char*)((ng0)));
    t34 = ((char*)((ng2)));
    t35 = (t1 + 30152);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 12976);
    xsi_vlogfile_fwrite(*((unsigned int *)t33), 1, 0, 0, ng13, 3, t38, (char)118, t34, 128, (char)118, t37, 7);
    goto LAB21;

LAB24:
LAB27:    t6 = (t1 + 9720);
    t7 = *((char **)t6);
    t6 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t7, 32, t6, 32);
    t8 = (t10 + 4);
    t21 = *((unsigned int *)t8);
    t22 = (~(t21));
    t23 = *((unsigned int *)t10);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB28;

LAB29:
LAB32:    t4 = ((char*)((ng4)));
    t5 = (t1 + 30952);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB33:    t4 = (t1 + 30952);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9720);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB34;

LAB35:
LAB30:    t4 = (t1 + 4960);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_equal(t10, 32, t5, 32, t4, 32);
    t6 = (t10 + 4);
    t13 = *((unsigned int *)t6);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB39;

LAB40:
LAB47:    t4 = ((char*)((ng4)));
    t5 = (t1 + 30952);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB48:    t4 = (t1 + 30952);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 4960);
    t8 = *((char **)t7);
    memset(t10, 0, 8);
    xsi_vlog_signed_less(t10, 32, t6, 32, t8, 32);
    t7 = (t10 + 4);
    t13 = *((unsigned int *)t7);
    t14 = (~(t13));
    t15 = *((unsigned int *)t10);
    t16 = (t15 & t14);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB49;

LAB50:
LAB41:    goto LAB26;

LAB28:
LAB31:    t9 = (t1 + 24072);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 24072);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 24072);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 30792);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    xsi_vlog_generic_get_array_select_value(t18, 32, t12, t26, t34, 2, 1, t37, 7, 2);
    t38 = (t1 + 30632);
    xsi_vlogvar_assign_value(t38, t18, 0, 0, 32);
    goto LAB30;

LAB34:
LAB36:    t9 = (t1 + 24072);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 24072);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 24072);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 30792);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 9720);
    t39 = *((char **)t38);
    memset(t40, 0, 8);
    xsi_vlog_unsigned_multiply(t40, 32, t37, 7, t39, 32);
    t38 = (t1 + 30952);
    t41 = (t38 + 56U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    xsi_vlog_unsigned_add(t43, 32, t40, 32, t42, 32);
    xsi_vlog_generic_get_array_select_value(t18, 32, t12, t26, t34, 2, 1, t43, 32, 2);
    t44 = (t1 + 30632);
    t48 = (t1 + 30632);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t1 + 8904);
    t52 = *((char **)t51);
    t51 = (t1 + 30952);
    t53 = (t51 + 56U);
    t54 = *((char **)t53);
    memset(t55, 0, 8);
    xsi_vlog_signed_multiply(t55, 32, t52, 32, t54, 32);
    t56 = ((char*)((ng5)));
    xsi_vlog_convert_indexed_partindices(t45, t46, t47, ((int*)(t50)), 2, t55, 32, 1, t56, 32, 1, 1);
    t57 = (t45 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t46 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    t62 = (t47 + 4);
    t23 = *((unsigned int *)t62);
    t63 = (!(t23));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB37;

LAB38:    t4 = (t1 + 30952);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 30952);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB33;

LAB37:    t24 = *((unsigned int *)t47);
    t65 = (t24 + 0);
    t25 = *((unsigned int *)t45);
    t28 = *((unsigned int *)t46);
    t66 = (t25 - t28);
    t67 = (t66 + 1);
    xsi_vlogvar_assign_value(t44, t18, t65, *((unsigned int *)t46), t67);
    goto LAB38;

LAB39:
LAB42:    t7 = (t1 + 30312);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t18, 0, 8);
    t11 = (t18 + 4);
    t12 = (t9 + 4);
    t21 = *((unsigned int *)t9);
    t22 = (t21 >> 0);
    t23 = (t22 & 1);
    *((unsigned int *)t18) = t23;
    t24 = *((unsigned int *)t12);
    t25 = (t24 >> 0);
    t28 = (t25 & 1);
    *((unsigned int *)t11) = t28;
    t19 = (t18 + 4);
    t29 = *((unsigned int *)t19);
    t30 = (~(t29));
    t31 = *((unsigned int *)t18);
    t32 = (t31 & t30);
    t68 = (t32 != 0);
    if (t68 > 0)
        goto LAB43;

LAB44:
LAB45:    goto LAB41;

LAB43:
LAB46:    t20 = (t1 + 30472);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    t33 = (t1 + 30632);
    xsi_vlogvar_assign_value(t33, t27, 0, 0, 32);
    goto LAB45;

LAB49:
LAB51:    t9 = (t1 + 30312);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 30312);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 30952);
    t33 = (t27 + 56U);
    t34 = *((char **)t33);
    xsi_vlog_generic_get_index_select_value(t18, 1, t12, t26, 2, t34, 32, 1);
    t35 = (t18 + 4);
    t21 = *((unsigned int *)t35);
    t22 = (~(t21));
    t23 = *((unsigned int *)t18);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB52;

LAB53:
LAB54:    t4 = (t1 + 30952);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 30952);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB48;

LAB52:
LAB55:    t36 = (t1 + 30472);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    t39 = (t1 + 30472);
    t41 = (t39 + 72U);
    t42 = *((char **)t41);
    t44 = (t1 + 10536);
    t48 = *((char **)t44);
    t44 = (t1 + 30952);
    t49 = (t44 + 56U);
    t50 = *((char **)t49);
    memset(t43, 0, 8);
    xsi_vlog_signed_multiply(t43, 32, t48, 32, t50, 32);
    t51 = ((char*)((ng6)));
    xsi_vlog_get_indexed_partselect(t40, 9, t38, ((int*)(t42)), 2, t43, 32, 1, t51, 32, 1, 1);
    t52 = (t1 + 30632);
    t53 = (t1 + 30632);
    t54 = (t53 + 72U);
    t56 = *((char **)t54);
    t57 = (t1 + 10536);
    t59 = *((char **)t57);
    t57 = (t1 + 30952);
    t62 = (t57 + 56U);
    t69 = *((char **)t62);
    memset(t55, 0, 8);
    xsi_vlog_signed_multiply(t55, 32, t59, 32, t69, 32);
    t70 = ((char*)((ng6)));
    xsi_vlog_convert_indexed_partindices(t45, t46, t47, ((int*)(t56)), 2, t55, 32, 1, t70, 32, 1, 1);
    t71 = (t45 + 4);
    t28 = *((unsigned int *)t71);
    t58 = (!(t28));
    t72 = (t46 + 4);
    t29 = *((unsigned int *)t72);
    t60 = (!(t29));
    t61 = (t58 && t60);
    t73 = (t47 + 4);
    t30 = *((unsigned int *)t73);
    t63 = (!(t30));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB56;

LAB57:    goto LAB54;

LAB56:    t31 = *((unsigned int *)t47);
    t65 = (t31 + 0);
    t32 = *((unsigned int *)t45);
    t68 = *((unsigned int *)t46);
    t66 = (t32 - t68);
    t67 = (t66 + 1);
    xsi_vlogvar_assign_value(t52, t40, t65, *((unsigned int *)t46), t67);
    goto LAB57;

LAB59:
LAB62:    t7 = (t1 + 30632);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t11 = (t1 + 24072);
    t12 = (t1 + 24072);
    t19 = (t12 + 72U);
    t20 = *((char **)t19);
    t26 = (t1 + 24072);
    t27 = (t26 + 64U);
    t33 = *((char **)t27);
    t34 = (t1 + 30792);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    t37 = (t1 + 9720);
    t38 = *((char **)t37);
    memset(t43, 0, 8);
    xsi_vlog_unsigned_multiply(t43, 32, t36, 7, t38, 32);
    xsi_vlog_generic_convert_array_indices(t18, t40, t20, t33, 2, 1, t43, 32, 2);
    t37 = (t18 + 4);
    t21 = *((unsigned int *)t37);
    t58 = (!(t21));
    t39 = (t40 + 4);
    t22 = *((unsigned int *)t39);
    t60 = (!(t22));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB63;

LAB64:    goto LAB61;

LAB63:    t23 = *((unsigned int *)t18);
    t24 = *((unsigned int *)t40);
    t63 = (t23 - t24);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t11, t9, 0, *((unsigned int *)t40), t64);
    goto LAB64;

LAB67:
LAB69:    t9 = (t1 + 30632);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t19 = (t1 + 30632);
    t20 = (t19 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 8904);
    t33 = *((char **)t27);
    t27 = (t1 + 30952);
    t34 = (t27 + 56U);
    t35 = *((char **)t34);
    memset(t40, 0, 8);
    xsi_vlog_signed_multiply(t40, 32, t33, 32, t35, 32);
    t36 = ((char*)((ng5)));
    xsi_vlog_get_indexed_partselect(t18, 32, t12, ((int*)(t26)), 2, t40, 32, 1, t36, 32, 1, 1);
    t37 = (t1 + 24072);
    t38 = (t1 + 24072);
    t39 = (t38 + 72U);
    t41 = *((char **)t39);
    t42 = (t1 + 24072);
    t44 = (t42 + 64U);
    t48 = *((char **)t44);
    t49 = (t1 + 30792);
    t50 = (t49 + 56U);
    t51 = *((char **)t50);
    t52 = (t1 + 9720);
    t53 = *((char **)t52);
    memset(t46, 0, 8);
    xsi_vlog_unsigned_multiply(t46, 32, t51, 7, t53, 32);
    t52 = (t1 + 30952);
    t54 = (t52 + 56U);
    t56 = *((char **)t54);
    memset(t47, 0, 8);
    xsi_vlog_unsigned_add(t47, 32, t46, 32, t56, 32);
    xsi_vlog_generic_convert_array_indices(t43, t45, t41, t48, 2, 1, t47, 32, 2);
    t57 = (t43 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t45 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    if (t61 == 1)
        goto LAB70;

LAB71:    t4 = (t1 + 30952);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 32, t6, 32, t7, 32);
    t8 = (t1 + 30952);
    xsi_vlogvar_assign_value(t8, t10, 0, 0, 32);
    goto LAB66;

LAB70:    t23 = *((unsigned int *)t43);
    t24 = *((unsigned int *)t45);
    t63 = (t23 - t24);
    t64 = (t63 + 1);
    xsi_vlogvar_assign_value(t37, t18, 0, *((unsigned int *)t45), t64);
    goto LAB71;

}

static int sp_read_a(char *t1, char *t2)
{
    char t18[8];
    char t19[8];
    char t39[8];
    char t43[8];
    char t45[8];
    char t46[8];
    char t47[8];
    char t55[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t40;
    char *t41;
    char *t42;
    char *t44;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t56;
    char *t57;
    int t58;
    char *t59;
    int t60;
    int t61;
    char *t62;
    int t63;
    int t64;
    int t65;
    int t66;
    int t67;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 13408);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 31272);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB6;

LAB7:
LAB10:    t4 = (t1 + 31112);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 10128);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    xsi_vlog_unsigned_divide(t18, 32, t6, 7, t8, 32);
    t7 = (t1 + 31432);
    xsi_vlogvar_assign_value(t7, t18, 0, 0, 7);
    t4 = (t1 + 31432);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 3736);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB12;

LAB11:    t14 = (t8 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB12;

LAB15:    if (*((unsigned int *)t6) < *((unsigned int *)t8))
        goto LAB14;

LAB13:    *((unsigned int *)t18) = 1;

LAB14:    t16 = (t18 + 4);
    t9 = *((unsigned int *)t16);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB16;

LAB17:
LAB28:    t4 = (t1 + 9584);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t5, 32, t4, 32);
    t6 = (t18 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB29;

LAB30:
LAB33:    t4 = ((char*)((ng4)));
    t5 = (t1 + 31592);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB34:    t4 = (t1 + 31592);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9584);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    xsi_vlog_signed_less(t18, 32, t6, 32, t8, 32);
    t7 = (t18 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB35;

LAB36:
LAB31:
LAB18:
LAB8:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:
LAB9:    t14 = (t1 + 25832);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 25032);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, 0, 32, 100LL);
    goto LAB8;

LAB12:    t15 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB14;

LAB16:
LAB19:    t17 = (t1 + 7816);
    t20 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t20 + 4);
    t21 = *((unsigned int *)t17);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB23;

LAB21:    if (*((unsigned int *)t17) == 0)
        goto LAB20;

LAB22:    t26 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t26) = 1;

LAB23:    t27 = (t19 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t19);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB24;

LAB25:
LAB26:    t4 = ((char*)((ng15)));
    t5 = (t1 + 25032);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 32, 100LL);
    goto LAB18;

LAB20:    *((unsigned int *)t19) = 1;
    goto LAB23;

LAB24:
LAB27:    t33 = ((char*)((ng0)));
    t34 = ((char*)((ng2)));
    t35 = (t1 + 31112);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 13408);
    xsi_vlogfile_fwrite(*((unsigned int *)t33), 1, 0, 0, ng14, 3, t38, (char)118, t34, 128, (char)118, t37, 7);
    goto LAB26;

LAB29:
LAB32:    t7 = (t1 + 24072);
    t8 = (t7 + 56U);
    t14 = *((char **)t8);
    t15 = (t1 + 24072);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t20 = (t1 + 24072);
    t26 = (t20 + 64U);
    t27 = *((char **)t26);
    t33 = (t1 + 31432);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t36 = (t1 + 9584);
    t37 = *((char **)t36);
    memset(t39, 0, 8);
    xsi_vlog_unsigned_multiply(t39, 32, t35, 7, t37, 32);
    xsi_vlog_generic_get_array_select_value(t19, 32, t14, t17, t27, 2, 1, t39, 32, 2);
    t36 = (t1 + 25032);
    xsi_vlogvar_wait_assign_value(t36, t19, 0, 0, 32, 100LL);
    goto LAB31;

LAB35:
LAB37:    t14 = (t1 + 24072);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 24072);
    t20 = (t17 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 24072);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 31432);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 9584);
    t40 = *((char **)t38);
    memset(t39, 0, 8);
    xsi_vlog_unsigned_multiply(t39, 32, t37, 7, t40, 32);
    t38 = (t1 + 31592);
    t41 = (t38 + 56U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    xsi_vlog_unsigned_add(t43, 32, t39, 32, t42, 32);
    xsi_vlog_generic_get_array_select_value(t19, 32, t16, t26, t34, 2, 1, t43, 32, 2);
    t44 = (t1 + 25032);
    t48 = (t1 + 25032);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t1 + 8904);
    t52 = *((char **)t51);
    t51 = (t1 + 31592);
    t53 = (t51 + 56U);
    t54 = *((char **)t53);
    memset(t55, 0, 8);
    xsi_vlog_signed_multiply(t55, 32, t52, 32, t54, 32);
    t56 = ((char*)((ng5)));
    xsi_vlog_convert_indexed_partindices(t45, t46, t47, ((int*)(t50)), 2, t55, 32, 1, t56, 32, 1, 1);
    t57 = (t45 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t46 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    t62 = (t47 + 4);
    t23 = *((unsigned int *)t62);
    t63 = (!(t23));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB38;

LAB39:    t4 = (t1 + 31592);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_add(t18, 32, t6, 32, t7, 32);
    t8 = (t1 + 31592);
    xsi_vlogvar_assign_value(t8, t18, 0, 0, 32);
    goto LAB34;

LAB38:    t24 = *((unsigned int *)t47);
    t65 = (t24 + 0);
    t25 = *((unsigned int *)t45);
    t28 = *((unsigned int *)t46);
    t66 = (t25 - t28);
    t67 = (t66 + 1);
    xsi_vlogvar_wait_assign_value(t44, t19, t65, *((unsigned int *)t46), t67, 100LL);
    goto LAB39;

}

static int sp_read_b(char *t1, char *t2)
{
    char t18[8];
    char t19[8];
    char t39[8];
    char t43[8];
    char t45[8];
    char t46[8];
    char t47[8];
    char t55[8];
    char t68[16];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t40;
    char *t41;
    char *t42;
    char *t44;
    char *t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    char *t53;
    char *t54;
    char *t56;
    char *t57;
    int t58;
    char *t59;
    int t60;
    int t61;
    char *t62;
    int t63;
    int t64;
    int t65;
    int t66;
    int t67;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 13840);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 31912);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB6;

LAB7:
LAB10:    t4 = (t1 + 31752);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 10400);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    xsi_vlog_unsigned_divide(t18, 32, t6, 7, t8, 32);
    t7 = (t1 + 32072);
    xsi_vlogvar_assign_value(t7, t18, 0, 0, 7);
    t4 = (t1 + 32072);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 5640);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    t7 = (t6 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB12;

LAB11:    t14 = (t8 + 4);
    if (*((unsigned int *)t14) != 0)
        goto LAB12;

LAB15:    if (*((unsigned int *)t6) < *((unsigned int *)t8))
        goto LAB14;

LAB13:    *((unsigned int *)t18) = 1;

LAB14:    t16 = (t18 + 4);
    t9 = *((unsigned int *)t16);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB16;

LAB17:
LAB28:    t4 = (t1 + 9856);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t5, 32, t4, 32);
    t6 = (t18 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB29;

LAB30:
LAB33:    t4 = ((char*)((ng4)));
    t5 = (t1 + 32232);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB34:    t4 = (t1 + 32232);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 9856);
    t8 = *((char **)t7);
    memset(t18, 0, 8);
    xsi_vlog_signed_less(t18, 32, t6, 32, t8, 32);
    t7 = (t18 + 4);
    t9 = *((unsigned int *)t7);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB35;

LAB36:
LAB31:    t4 = ((char*)((ng11)));
    t5 = ((char*)((ng12)));
    xsi_vlog_unsigned_equal(t68, 64, t4, 64, t5, 64);
    memset(t18, 0, 8);
    t6 = (t68 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t68);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t6) != 0)
        goto LAB42;

LAB43:    t8 = (t18 + 4);
    t21 = *((unsigned int *)t18);
    t22 = *((unsigned int *)t8);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB44;

LAB45:    memcpy(t43, t18, 8);

LAB46:    t35 = (t43 + 4);
    t91 = *((unsigned int *)t35);
    t92 = (~(t91));
    t93 = *((unsigned int *)t43);
    t94 = (t93 & t92);
    t95 = (t94 != 0);
    if (t95 > 0)
        goto LAB54;

LAB55:    t4 = (t1 + 6864);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_equal(t18, 32, t5, 32, t4, 32);
    t6 = (t18 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t18);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB76;

LAB77:
LAB98:    t4 = ((char*)((ng4)));
    t5 = (t1 + 25672);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 7, 100LL);
    t4 = ((char*)((ng16)));
    t5 = (t1 + 25512);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);
    t4 = ((char*)((ng16)));
    t5 = (t1 + 25352);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);

LAB78:
LAB56:
LAB18:
LAB8:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:
LAB9:    t14 = (t1 + 25992);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 25192);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, 0, 32, 100LL);
    t4 = ((char*)((ng16)));
    t5 = (t1 + 25352);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);
    t4 = ((char*)((ng16)));
    t5 = (t1 + 25512);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 25672);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 7, 100LL);
    goto LAB8;

LAB12:    t15 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t15) = 1;
    goto LAB14;

LAB16:
LAB19:    t17 = (t1 + 7816);
    t20 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t20 + 4);
    t21 = *((unsigned int *)t17);
    t22 = (~(t21));
    t23 = *((unsigned int *)t20);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB23;

LAB21:    if (*((unsigned int *)t17) == 0)
        goto LAB20;

LAB22:    t26 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t26) = 1;

LAB23:    t27 = (t19 + 4);
    t28 = *((unsigned int *)t27);
    t29 = (~(t28));
    t30 = *((unsigned int *)t19);
    t31 = (t30 & t29);
    t32 = (t31 != 0);
    if (t32 > 0)
        goto LAB24;

LAB25:
LAB26:    t4 = ((char*)((ng15)));
    t5 = (t1 + 25192);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 32, 100LL);
    t4 = ((char*)((ng18)));
    t5 = (t1 + 25352);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);
    t4 = ((char*)((ng18)));
    t5 = (t1 + 25512);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);
    t4 = ((char*)((ng15)));
    t5 = (t1 + 25672);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 7, 100LL);
    goto LAB18;

LAB20:    *((unsigned int *)t19) = 1;
    goto LAB23;

LAB24:
LAB27:    t33 = ((char*)((ng0)));
    t34 = ((char*)((ng2)));
    t35 = (t1 + 31752);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 13840);
    xsi_vlogfile_fwrite(*((unsigned int *)t33), 1, 0, 0, ng17, 3, t38, (char)118, t34, 128, (char)118, t37, 7);
    goto LAB26;

LAB29:
LAB32:    t7 = (t1 + 24072);
    t8 = (t7 + 56U);
    t14 = *((char **)t8);
    t15 = (t1 + 24072);
    t16 = (t15 + 72U);
    t17 = *((char **)t16);
    t20 = (t1 + 24072);
    t26 = (t20 + 64U);
    t27 = *((char **)t26);
    t33 = (t1 + 32072);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t36 = (t1 + 9856);
    t37 = *((char **)t36);
    memset(t39, 0, 8);
    xsi_vlog_unsigned_multiply(t39, 32, t35, 7, t37, 32);
    xsi_vlog_generic_get_array_select_value(t19, 32, t14, t17, t27, 2, 1, t39, 32, 2);
    t36 = (t1 + 25192);
    xsi_vlogvar_wait_assign_value(t36, t19, 0, 0, 32, 100LL);
    goto LAB31;

LAB35:
LAB37:    t14 = (t1 + 24072);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 24072);
    t20 = (t17 + 72U);
    t26 = *((char **)t20);
    t27 = (t1 + 24072);
    t33 = (t27 + 64U);
    t34 = *((char **)t33);
    t35 = (t1 + 32072);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t1 + 9856);
    t40 = *((char **)t38);
    memset(t39, 0, 8);
    xsi_vlog_unsigned_multiply(t39, 32, t37, 7, t40, 32);
    t38 = (t1 + 32232);
    t41 = (t38 + 56U);
    t42 = *((char **)t41);
    memset(t43, 0, 8);
    xsi_vlog_unsigned_add(t43, 32, t39, 32, t42, 32);
    xsi_vlog_generic_get_array_select_value(t19, 32, t16, t26, t34, 2, 1, t43, 32, 2);
    t44 = (t1 + 25192);
    t48 = (t1 + 25192);
    t49 = (t48 + 72U);
    t50 = *((char **)t49);
    t51 = (t1 + 8904);
    t52 = *((char **)t51);
    t51 = (t1 + 32232);
    t53 = (t51 + 56U);
    t54 = *((char **)t53);
    memset(t55, 0, 8);
    xsi_vlog_signed_multiply(t55, 32, t52, 32, t54, 32);
    t56 = ((char*)((ng5)));
    xsi_vlog_convert_indexed_partindices(t45, t46, t47, ((int*)(t50)), 2, t55, 32, 1, t56, 32, 1, 1);
    t57 = (t45 + 4);
    t21 = *((unsigned int *)t57);
    t58 = (!(t21));
    t59 = (t46 + 4);
    t22 = *((unsigned int *)t59);
    t60 = (!(t22));
    t61 = (t58 && t60);
    t62 = (t47 + 4);
    t23 = *((unsigned int *)t62);
    t63 = (!(t23));
    t64 = (t61 && t63);
    if (t64 == 1)
        goto LAB38;

LAB39:    t4 = (t1 + 32232);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t18, 0, 8);
    xsi_vlog_signed_add(t18, 32, t6, 32, t7, 32);
    t8 = (t1 + 32232);
    xsi_vlogvar_assign_value(t8, t18, 0, 0, 32);
    goto LAB34;

LAB38:    t24 = *((unsigned int *)t47);
    t65 = (t24 + 0);
    t25 = *((unsigned int *)t45);
    t28 = *((unsigned int *)t46);
    t66 = (t25 - t28);
    t67 = (t66 + 1);
    xsi_vlogvar_wait_assign_value(t44, t19, t65, *((unsigned int *)t46), t67, 100LL);
    goto LAB39;

LAB40:    *((unsigned int *)t18) = 1;
    goto LAB43;

LAB42:    t7 = (t18 + 4);
    *((unsigned int *)t18) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB43;

LAB44:    t14 = (t1 + 7000);
    t15 = *((char **)t14);
    t14 = ((char*)((ng3)));
    memset(t19, 0, 8);
    xsi_vlog_signed_equal(t19, 32, t15, 32, t14, 32);
    memset(t39, 0, 8);
    t16 = (t19 + 4);
    t24 = *((unsigned int *)t16);
    t25 = (~(t24));
    t28 = *((unsigned int *)t19);
    t29 = (t28 & t25);
    t30 = (t29 & 1U);
    if (t30 != 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t16) != 0)
        goto LAB49;

LAB50:    t31 = *((unsigned int *)t18);
    t32 = *((unsigned int *)t39);
    t69 = (t31 & t32);
    *((unsigned int *)t43) = t69;
    t20 = (t18 + 4);
    t26 = (t39 + 4);
    t27 = (t43 + 4);
    t70 = *((unsigned int *)t20);
    t71 = *((unsigned int *)t26);
    t72 = (t70 | t71);
    *((unsigned int *)t27) = t72;
    t73 = *((unsigned int *)t27);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB51;

LAB52:
LAB53:    goto LAB46;

LAB47:    *((unsigned int *)t39) = 1;
    goto LAB50;

LAB49:    t17 = (t39 + 4);
    *((unsigned int *)t39) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB50;

LAB51:    t75 = *((unsigned int *)t43);
    t76 = *((unsigned int *)t27);
    *((unsigned int *)t43) = (t75 | t76);
    t33 = (t18 + 4);
    t34 = (t39 + 4);
    t77 = *((unsigned int *)t18);
    t78 = (~(t77));
    t79 = *((unsigned int *)t33);
    t80 = (~(t79));
    t81 = *((unsigned int *)t39);
    t82 = (~(t81));
    t83 = *((unsigned int *)t34);
    t84 = (~(t83));
    t58 = (t78 & t80);
    t60 = (t82 & t84);
    t85 = (~(t58));
    t86 = (~(t60));
    t87 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t87 & t85);
    t88 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t88 & t86);
    t89 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t89 & t85);
    t90 = *((unsigned int *)t43);
    *((unsigned int *)t43) = (t90 & t86);
    goto LAB53;

LAB54:
LAB57:    t36 = (t1 + 31752);
    t37 = (t36 + 56U);
    t38 = *((char **)t37);
    t40 = (t1 + 25672);
    xsi_vlogvar_wait_assign_value(t40, t38, 0, 0, 7, 100LL);
    t4 = (t1 + 24392);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 24392);
    t8 = (t7 + 72U);
    t14 = *((char **)t8);
    t15 = (t1 + 24392);
    t16 = (t15 + 64U);
    t17 = *((char **)t16);
    t20 = (t1 + 31752);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    xsi_vlog_generic_get_array_select_value(t18, 32, t6, t14, t17, 2, 1, t27, 7, 2);
    t33 = ((char*)((ng3)));
    memset(t19, 0, 8);
    t34 = (t18 + 4);
    t35 = (t33 + 4);
    t9 = *((unsigned int *)t18);
    t10 = *((unsigned int *)t33);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t34);
    t13 = *((unsigned int *)t35);
    t21 = (t12 ^ t13);
    t22 = (t11 | t21);
    t23 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t23 | t24);
    t28 = (~(t25));
    t29 = (t22 & t28);
    if (t29 != 0)
        goto LAB61;

LAB58:    if (t25 != 0)
        goto LAB60;

LAB59:    *((unsigned int *)t19) = 1;

LAB61:    t37 = (t19 + 4);
    t30 = *((unsigned int *)t37);
    t31 = (~(t30));
    t32 = *((unsigned int *)t19);
    t69 = (t32 & t31);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB62;

LAB63:
LAB66:    t4 = ((char*)((ng16)));
    t5 = (t1 + 25352);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);

LAB64:    t4 = (t1 + 24552);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 24552);
    t8 = (t7 + 72U);
    t14 = *((char **)t8);
    t15 = (t1 + 24552);
    t16 = (t15 + 64U);
    t17 = *((char **)t16);
    t20 = (t1 + 31752);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    xsi_vlog_generic_get_array_select_value(t18, 32, t6, t14, t17, 2, 1, t27, 7, 2);
    t33 = ((char*)((ng3)));
    memset(t19, 0, 8);
    t34 = (t18 + 4);
    t35 = (t33 + 4);
    t9 = *((unsigned int *)t18);
    t10 = *((unsigned int *)t33);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t34);
    t13 = *((unsigned int *)t35);
    t21 = (t12 ^ t13);
    t22 = (t11 | t21);
    t23 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t23 | t24);
    t28 = (~(t25));
    t29 = (t22 & t28);
    if (t29 != 0)
        goto LAB70;

LAB67:    if (t25 != 0)
        goto LAB69;

LAB68:    *((unsigned int *)t19) = 1;

LAB70:    t37 = (t19 + 4);
    t30 = *((unsigned int *)t37);
    t31 = (~(t30));
    t32 = *((unsigned int *)t19);
    t69 = (t32 & t31);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB71;

LAB72:
LAB75:    t4 = ((char*)((ng16)));
    t5 = (t1 + 25512);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);

LAB73:    goto LAB56;

LAB60:    t36 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB61;

LAB62:
LAB65:    t38 = ((char*)((ng9)));
    t40 = (t1 + 25352);
    xsi_vlogvar_wait_assign_value(t40, t38, 0, 0, 1, 100LL);
    goto LAB64;

LAB69:    t36 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB70;

LAB71:
LAB74:    t38 = ((char*)((ng9)));
    t40 = (t1 + 25512);
    xsi_vlogvar_wait_assign_value(t40, t38, 0, 0, 1, 100LL);
    goto LAB73;

LAB76:
LAB79:    t7 = (t1 + 31752);
    t8 = (t7 + 56U);
    t14 = *((char **)t8);
    t15 = (t1 + 25672);
    xsi_vlogvar_wait_assign_value(t15, t14, 0, 0, 7, 100LL);
    t4 = (t1 + 24712);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 24712);
    t8 = (t7 + 72U);
    t14 = *((char **)t8);
    t15 = (t1 + 24712);
    t16 = (t15 + 64U);
    t17 = *((char **)t16);
    t20 = (t1 + 31752);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    xsi_vlog_generic_get_array_select_value(t18, 32, t6, t14, t17, 2, 1, t27, 7, 2);
    t33 = ((char*)((ng3)));
    memset(t19, 0, 8);
    t34 = (t18 + 4);
    t35 = (t33 + 4);
    t9 = *((unsigned int *)t18);
    t10 = *((unsigned int *)t33);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t34);
    t13 = *((unsigned int *)t35);
    t21 = (t12 ^ t13);
    t22 = (t11 | t21);
    t23 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t23 | t24);
    t28 = (~(t25));
    t29 = (t22 & t28);
    if (t29 != 0)
        goto LAB83;

LAB80:    if (t25 != 0)
        goto LAB82;

LAB81:    *((unsigned int *)t19) = 1;

LAB83:    t37 = (t19 + 4);
    t30 = *((unsigned int *)t37);
    t31 = (~(t30));
    t32 = *((unsigned int *)t19);
    t69 = (t32 & t31);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB84;

LAB85:
LAB88:    t4 = ((char*)((ng16)));
    t5 = (t1 + 25352);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);

LAB86:    t4 = (t1 + 24872);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t1 + 24872);
    t8 = (t7 + 72U);
    t14 = *((char **)t8);
    t15 = (t1 + 24872);
    t16 = (t15 + 64U);
    t17 = *((char **)t16);
    t20 = (t1 + 31752);
    t26 = (t20 + 56U);
    t27 = *((char **)t26);
    xsi_vlog_generic_get_array_select_value(t18, 32, t6, t14, t17, 2, 1, t27, 7, 2);
    t33 = ((char*)((ng3)));
    memset(t19, 0, 8);
    t34 = (t18 + 4);
    t35 = (t33 + 4);
    t9 = *((unsigned int *)t18);
    t10 = *((unsigned int *)t33);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t34);
    t13 = *((unsigned int *)t35);
    t21 = (t12 ^ t13);
    t22 = (t11 | t21);
    t23 = *((unsigned int *)t34);
    t24 = *((unsigned int *)t35);
    t25 = (t23 | t24);
    t28 = (~(t25));
    t29 = (t22 & t28);
    if (t29 != 0)
        goto LAB92;

LAB89:    if (t25 != 0)
        goto LAB91;

LAB90:    *((unsigned int *)t19) = 1;

LAB92:    t37 = (t19 + 4);
    t30 = *((unsigned int *)t37);
    t31 = (~(t30));
    t32 = *((unsigned int *)t19);
    t69 = (t32 & t31);
    t70 = (t69 != 0);
    if (t70 > 0)
        goto LAB93;

LAB94:
LAB97:    t4 = ((char*)((ng16)));
    t5 = (t1 + 25512);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 100LL);

LAB95:    goto LAB78;

LAB82:    t36 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB83;

LAB84:
LAB87:    t38 = ((char*)((ng9)));
    t40 = (t1 + 25352);
    xsi_vlogvar_wait_assign_value(t40, t38, 0, 0, 1, 100LL);
    goto LAB86;

LAB91:    t36 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB92;

LAB93:
LAB96:    t38 = ((char*)((ng9)));
    t40 = (t1 + 25512);
    xsi_vlogvar_wait_assign_value(t40, t38, 0, 0, 1, 100LL);
    goto LAB95;

}

static int sp_reset_a(char *t1, char *t2)
{
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 14272);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 32392);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB6;

LAB7:
LAB8:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:    t14 = (t1 + 25832);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 25032);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, 0, 32, 100LL);
    goto LAB8;

}

static int sp_reset_b(char *t1, char *t2)
{
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 14704);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = (t1 + 32552);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB6;

LAB7:
LAB8:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:    t14 = (t1 + 25992);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    t17 = (t1 + 25192);
    xsi_vlogvar_wait_assign_value(t17, t16, 0, 0, 32, 100LL);
    goto LAB8;

}

static int sp_init_memory(char *t1, char *t2)
{
    char t7[8];
    char t20[8];
    char t27[8];
    char t62[64];
    char t91[2048];
    char t92[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t63;
    char *t64;
    char *t65;
    char *t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t90;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 15136);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);

LAB5:    t5 = ((char*)((ng4)));
    t6 = (t1 + 33192);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);
    t4 = (t1 + 1696);
    t5 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t5);
    t11 = (t10 & t9);
    t12 = (t11 & 4294967295U);
    if (t12 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    memcpy(t27, t7, 8);

LAB12:    t55 = (t27 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t27);
    t59 = (t58 & t57);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB20;

LAB21:
LAB22:    t4 = (t1 + 1696);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t5);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB23;

LAB24:
LAB25:    t4 = (t1 + 9992);
    t5 = *((char **)t4);
    t4 = (t1 + 32872);
    xsi_vlogvar_assign_value(t4, t5, 0, 0, 32);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 32712);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB36:    t4 = (t1 + 32712);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = (t1 + 3600);
    t18 = *((char **)t13);
    t13 = (t1 + 32872);
    t19 = (t13 + 56U);
    t26 = *((char **)t19);
    memset(t7, 0, 8);
    xsi_vlog_signed_multiply(t7, 32, t18, 32, t26, 32);
    memset(t20, 0, 8);
    xsi_vlog_signed_less(t20, 32, t6, 32, t7, 32);
    t31 = (t20 + 4);
    t8 = *((unsigned int *)t31);
    t9 = (~(t8));
    t10 = *((unsigned int *)t20);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB37;

LAB38:    t4 = (t1 + 1424);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t5);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB46;

LAB47:
LAB48:    t4 = (t1 + 1696);
    t5 = *((char **)t4);
    memset(t7, 0, 8);
    t4 = (t5 + 4);
    t8 = *((unsigned int *)t4);
    t9 = (~(t8));
    t10 = *((unsigned int *)t5);
    t11 = (t10 & t9);
    t12 = (t11 & 4294967295U);
    if (t12 != 0)
        goto LAB74;

LAB75:    if (*((unsigned int *)t4) != 0)
        goto LAB76;

LAB77:    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB78;

LAB79:    memcpy(t27, t7, 8);

LAB80:    t55 = (t27 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t27);
    t59 = (t58 & t57);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB88;

LAB89:
LAB90:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB6:    *((unsigned int *)t7) = 1;
    goto LAB9;

LAB8:    t6 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB10:    t18 = (t1 + 1424);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t18) != 0)
        goto LAB15;

LAB16:    t28 = *((unsigned int *)t7);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t7 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t20) = 1;
    goto LAB16;

LAB15:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB16;

LAB17:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t7 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t7);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB19;

LAB20:    t61 = (t1 + 15136);
    xsi_vlogfile_write(1, 0, 0, ng19, 1, t61);
    goto LAB22;

LAB23:
LAB26:    t6 = (t1 + 27752);
    t13 = (t6 + 56U);
    t18 = *((char **)t13);
    t19 = ((char*)((ng20)));
    xsi_vlog_unsigned_equal(t62, 256, t18, 256, t19, 256);
    t26 = (t62 + 4);
    t14 = *((unsigned int *)t26);
    t15 = (~(t14));
    t16 = *((unsigned int *)t62);
    t17 = (t16 & t15);
    t21 = (t17 != 0);
    if (t21 > 0)
        goto LAB27;

LAB28:
LAB31:    t4 = (t1 + 27752);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = (t1 + 33192);
    t18 = (t13 + 56U);
    t19 = *((char **)t18);
    xsi_vlog_bit_copy(t7, 0, t19, 0, 32);
    *((int *)t20) = xsi_vlogfile_sscanf(t6, 256, ng22, 2, t1, (char)118, t7, 32);
    t26 = (t20 + 4);
    *((int *)t26) = 0;
    t31 = (t1 + 33192);
    xsi_vlogvar_assign_value(t31, t7, 0, 0, 32);
    t32 = (t1 + 33032);
    xsi_vlogvar_assign_value(t32, t20, 0, 0, 32);
    t4 = (t1 + 33032);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = ((char*)((ng4)));
    memset(t7, 0, 8);
    xsi_vlog_signed_equal(t7, 32, t6, 32, t13, 32);
    t18 = (t7 + 4);
    t8 = *((unsigned int *)t18);
    t9 = (~(t8));
    t10 = *((unsigned int *)t7);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB32;

LAB33:
LAB34:
LAB29:    goto LAB25;

LAB27:
LAB30:    t31 = ((char*)((ng0)));
    t32 = ((char*)((ng2)));
    t33 = (t1 + 15136);
    xsi_vlogfile_fwrite(*((unsigned int *)t31), 1, 0, 0, ng21, 2, t33, (char)118, t32, 128);
    xsi_vlog_finish(1);
    goto LAB29;

LAB32:
LAB35:    t19 = ((char*)((ng0)));
    t26 = ((char*)((ng24)));
    t31 = ((char*)((ng2)));
    t32 = ((char*)((ng25)));
    t33 = (t1 + 15136);
    xsi_vlogfile_fwrite(*((unsigned int *)t19), 1, 0, 0, ng23, 4, t33, (char)118, t26, 512, (char)118, t31, 128, (char)118, t32, 8);
    xsi_vlog_finish(1);
    goto LAB34;

LAB37:
LAB39:    t32 = (t1 + 32712);
    t33 = (t32 + 56U);
    t41 = *((char **)t33);
    t42 = ((char*)((ng9)));
    t55 = (t1 + 33192);
    t61 = (t55 + 56U);
    t63 = *((char **)t61);
    t64 = ((char*)((ng16)));
    t65 = ((char*)((ng16)));
    t66 = (t2 + 56U);
    t67 = *((char **)t66);
    t68 = (t2 + 56U);
    t69 = *((char **)t68);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t69, &&LAB40);
    t70 = (t2 + 56U);
    t71 = *((char **)t70);
    t72 = (t1 + 12544);
    t73 = xsi_create_subprogram_invocation(t71, 0, t1, t72, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t72, t73);
    t74 = (t1 + 28872);
    xsi_vlogvar_assign_value(t74, t41, 0, 0, 7);
    t75 = (t1 + 29032);
    xsi_vlogvar_assign_value(t75, t42, 0, 0, 1);
    t76 = (t1 + 29192);
    xsi_vlogvar_assign_value(t76, t63, 0, 0, 32);
    t77 = (t1 + 29352);
    xsi_vlogvar_assign_value(t77, t64, 0, 0, 1);
    t78 = (t1 + 29512);
    xsi_vlogvar_assign_value(t78, t65, 0, 0, 1);

LAB42:    t79 = (t2 + 64U);
    t80 = *((char **)t79);
    t81 = (t80 + 80U);
    t82 = *((char **)t81);
    t83 = (t82 + 272U);
    t84 = *((char **)t83);
    t85 = (t84 + 0U);
    t86 = *((char **)t85);
    t46 = ((int  (*)(char *, char *))t86)(t1, t80);
    if (t46 == -1)
        goto LAB43;

LAB44:    if (t46 != 0)
        goto LAB45;

LAB40:    t80 = (t1 + 12544);
    xsi_vlog_subprogram_popinvocation(t80);

LAB41:    t87 = (t2 + 64U);
    t88 = *((char **)t87);
    t87 = (t1 + 12544);
    t89 = (t2 + 56U);
    t90 = *((char **)t89);
    xsi_delete_subprogram_invocation(t87, t88, t1, t90, t2);
    t4 = (t1 + 32712);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = (t1 + 32872);
    t18 = (t13 + 56U);
    t19 = *((char **)t18);
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t6, 32, t19, 32);
    t26 = (t1 + 32712);
    xsi_vlogvar_assign_value(t26, t7, 0, 0, 32);
    goto LAB36;

LAB43:    t0 = -1;
    goto LAB1;

LAB45:    t79 = (t2 + 48U);
    *((char **)t79) = &&LAB42;
    goto LAB1;

LAB46:
LAB49:    t6 = (t1 + 27912);
    t13 = (t6 + 56U);
    t18 = *((char **)t13);
    t19 = ((char*)((ng26)));
    xsi_vlog_unsigned_equal(t91, 8184, t18, 8184, t19, 8184);
    t26 = (t91 + 4);
    t14 = *((unsigned int *)t26);
    t15 = (~(t14));
    t16 = *((unsigned int *)t91);
    t17 = (t16 & t15);
    t21 = (t17 != 0);
    if (t21 > 0)
        goto LAB50;

LAB51:
LAB54:    t4 = (t1 + 27912);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((int *)t7) = xsi_vlogfile_file_open_of_valname_ctype(t6, 8184, ng28);
    t13 = (t7 + 4);
    *((int *)t13) = 0;
    t18 = (t1 + 27112);
    xsi_vlogvar_assign_value(t18, t7, 0, 0, 32);
    t4 = (t1 + 27112);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = ((char*)((ng4)));
    memset(t7, 0, 8);
    xsi_vlog_signed_equal(t7, 32, t6, 32, t13, 32);
    t18 = (t7 + 4);
    t8 = *((unsigned int *)t18);
    t9 = (~(t8));
    t10 = *((unsigned int *)t7);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB55;

LAB56:
LAB59:    t4 = ((char*)((ng4)));
    t5 = (t1 + 32712);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB60:    t4 = (t1 + 32712);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = (t1 + 3600);
    t18 = *((char **)t13);
    t13 = (t1 + 32872);
    t19 = (t13 + 56U);
    t26 = *((char **)t19);
    memset(t7, 0, 8);
    xsi_vlog_signed_multiply(t7, 32, t18, 32, t26, 32);
    memset(t20, 0, 8);
    xsi_vlog_signed_less(t20, 32, t6, 32, t7, 32);
    t31 = (t20 + 4);
    t8 = *((unsigned int *)t31);
    t9 = (~(t8));
    t10 = *((unsigned int *)t20);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB61;

LAB62:    t4 = (t1 + 27112);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    xsi_vlogfile_fclose(*((unsigned int *)t6));

LAB57:
LAB52:    goto LAB48;

LAB50:
LAB53:    t31 = ((char*)((ng0)));
    t32 = ((char*)((ng2)));
    t33 = (t1 + 15136);
    xsi_vlogfile_fwrite(*((unsigned int *)t31), 1, 0, 0, ng27, 2, t33, (char)118, t32, 128);
    xsi_vlog_finish(1);
    goto LAB52;

LAB55:
LAB58:    t19 = ((char*)((ng0)));
    t26 = ((char*)((ng29)));
    t31 = ((char*)((ng2)));
    t32 = (t1 + 27912);
    t33 = (t32 + 56U);
    t41 = *((char **)t33);
    t42 = (t1 + 15136);
    xsi_vlogfile_fwrite(*((unsigned int *)t19), 1, 0, 0, ng23, 4, t42, (char)118, t26, 392, (char)118, t31, 128, (char)118, t41, 8184);
    xsi_vlog_finish(1);
    goto LAB57;

LAB61:
LAB63:    t32 = (t1 + 27112);
    t33 = (t32 + 56U);
    t41 = *((char **)t33);
    t42 = (t1 + 27272);
    t55 = (t42 + 56U);
    t61 = *((char **)t55);
    xsi_vlog_bit_copy(t27, 0, t61, 0, 32);
    *((int *)t92) = xsi_vlogfile_fscanf(*((unsigned int *)t41), ng30, 2, t1, (char)118, t27, 32);
    t63 = (t92 + 4);
    *((int *)t63) = 0;
    t64 = (t1 + 27272);
    xsi_vlogvar_assign_value(t64, t27, 0, 0, 32);
    t65 = (t1 + 33032);
    xsi_vlogvar_assign_value(t65, t92, 0, 0, 32);
    t4 = (t1 + 33032);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = ((char*)((ng4)));
    memset(t7, 0, 8);
    xsi_vlog_signed_greater(t7, 32, t6, 32, t13, 32);
    t18 = (t7 + 4);
    t8 = *((unsigned int *)t18);
    t9 = (~(t8));
    t10 = *((unsigned int *)t7);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB64;

LAB65:
LAB66:    t4 = (t1 + 32712);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t13 = (t1 + 32872);
    t18 = (t13 + 56U);
    t19 = *((char **)t18);
    memset(t7, 0, 8);
    xsi_vlog_signed_add(t7, 32, t6, 32, t19, 32);
    t26 = (t1 + 32712);
    xsi_vlogvar_assign_value(t26, t7, 0, 0, 32);
    goto LAB60;

LAB64:
LAB67:    t19 = (t1 + 32712);
    t26 = (t19 + 56U);
    t31 = *((char **)t26);
    t32 = ((char*)((ng9)));
    t33 = (t1 + 27272);
    t41 = (t33 + 56U);
    t42 = *((char **)t41);
    t55 = ((char*)((ng16)));
    t61 = ((char*)((ng16)));
    t63 = (t2 + 56U);
    t64 = *((char **)t63);
    t65 = (t2 + 56U);
    t66 = *((char **)t65);
    xsi_vlog_subprograminvocation_setJumpstate(t2, t66, &&LAB68);
    t67 = (t2 + 56U);
    t68 = *((char **)t67);
    t69 = (t1 + 12544);
    t70 = xsi_create_subprogram_invocation(t68, 0, t1, t69, 0, t2);
    xsi_vlog_subprogram_pushinvocation(t69, t70);
    t71 = (t1 + 28872);
    xsi_vlogvar_assign_value(t71, t31, 0, 0, 7);
    t72 = (t1 + 29032);
    xsi_vlogvar_assign_value(t72, t32, 0, 0, 1);
    t73 = (t1 + 29192);
    xsi_vlogvar_assign_value(t73, t42, 0, 0, 32);
    t74 = (t1 + 29352);
    xsi_vlogvar_assign_value(t74, t55, 0, 0, 1);
    t75 = (t1 + 29512);
    xsi_vlogvar_assign_value(t75, t61, 0, 0, 1);

LAB70:    t76 = (t2 + 64U);
    t77 = *((char **)t76);
    t78 = (t77 + 80U);
    t79 = *((char **)t78);
    t80 = (t79 + 272U);
    t81 = *((char **)t80);
    t82 = (t81 + 0U);
    t83 = *((char **)t82);
    t46 = ((int  (*)(char *, char *))t83)(t1, t77);
    if (t46 == -1)
        goto LAB71;

LAB72:    if (t46 != 0)
        goto LAB73;

LAB68:    t77 = (t1 + 12544);
    xsi_vlog_subprogram_popinvocation(t77);

LAB69:    t84 = (t2 + 64U);
    t85 = *((char **)t84);
    t84 = (t1 + 12544);
    t86 = (t2 + 56U);
    t87 = *((char **)t86);
    xsi_delete_subprogram_invocation(t84, t85, t1, t87, t2);
    goto LAB66;

LAB71:    t0 = -1;
    goto LAB1;

LAB73:    t76 = (t2 + 48U);
    *((char **)t76) = &&LAB70;
    goto LAB1;

LAB74:    *((unsigned int *)t7) = 1;
    goto LAB77;

LAB76:    t6 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t6) = 1;
    goto LAB77;

LAB78:    t18 = (t1 + 1424);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 4294967295U);
    if (t25 != 0)
        goto LAB81;

LAB82:    if (*((unsigned int *)t18) != 0)
        goto LAB83;

LAB84:    t28 = *((unsigned int *)t7);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t7 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB85;

LAB86:
LAB87:    goto LAB80;

LAB81:    *((unsigned int *)t20) = 1;
    goto LAB84;

LAB83:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB84;

LAB85:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t7 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t7);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB87;

LAB88:    t61 = (t1 + 15136);
    xsi_vlogfile_write(1, 0, 0, ng31, 1, t61);
    goto LAB90;

}

static int sp_log2roundup(char *t1, char *t2)
{
    char t7[8];
    char t20[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t21;

LAB0:    t0 = 1;

LAB2:    t3 = ((char*)((ng4)));
    t4 = (t1 + 33672);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    t3 = (t1 + 33352);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng3)));
    memset(t7, 0, 8);
    xsi_vlog_signed_greater(t7, 32, t5, 32, t6, 32);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB3;

LAB4:
LAB5:    t3 = (t1 + 33672);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 33512);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 32);
    t0 = 0;

LAB1:    return t0;
LAB3:
LAB6:    t14 = ((char*)((ng3)));
    t15 = (t1 + 33832);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 32);

LAB7:    t3 = (t1 + 33832);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 33352);
    t8 = (t6 + 56U);
    t14 = *((char **)t8);
    memset(t7, 0, 8);
    xsi_vlog_signed_less(t7, 32, t5, 32, t14, 32);
    t15 = (t7 + 4);
    t9 = *((unsigned int *)t15);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 != 0);
    if (t13 > 0)
        goto LAB8;

LAB9:    goto LAB5;

LAB8:
LAB10:    t16 = (t1 + 33672);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = ((char*)((ng3)));
    memset(t20, 0, 8);
    xsi_vlog_signed_add(t20, 32, t18, 32, t19, 32);
    t21 = (t1 + 33672);
    xsi_vlogvar_assign_value(t21, t20, 0, 0, 32);
    t3 = (t1 + 33832);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    memset(t7, 0, 8);
    xsi_vlog_signed_multiply(t7, 32, t5, 32, t6, 32);
    t8 = (t1 + 33832);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    goto LAB7;

}

static int sp_collision_check(char *t1, char *t2)
{
    char t11[8];
    char t12[8];
    char t13[8];
    char t73[8];
    char t86[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    int t53;
    int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    char *t81;
    char *t82;
    char *t83;
    char *t84;
    char *t85;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    char *t93;
    char *t94;
    int t95;
    int t96;

LAB0:    t0 = 1;

LAB2:    t3 = ((char*)((ng4)));
    t4 = (t1 + 34792);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t3 = ((char*)((ng4)));
    t4 = (t1 + 34952);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t3 = ((char*)((ng4)));
    t4 = (t1 + 35112);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    t3 = (t1 + 33992);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 3872);
    t8 = *((char **)t7);
    t7 = (t1 + 28552);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 7, t12, 32);
    t14 = (t1 + 35272);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 34312);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 5776);
    t8 = *((char **)t7);
    t7 = (t1 + 28552);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 7, t12, 32);
    t14 = (t1 + 35432);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33992);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 3872);
    t8 = *((char **)t7);
    t7 = (t1 + 28232);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 7, t12, 32);
    t14 = (t1 + 35592);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 34312);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 5776);
    t8 = *((char **)t7);
    t7 = (t1 + 28232);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 7, t12, 32);
    t14 = (t1 + 35752);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33992);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 3872);
    t8 = *((char **)t7);
    t7 = (t1 + 28712);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 7, t12, 32);
    t14 = (t1 + 35912);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 34312);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 5776);
    t8 = *((char **)t7);
    t7 = (t1 + 28712);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 7, t12, 32);
    t14 = (t1 + 36072);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 33992);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 3872);
    t8 = *((char **)t7);
    t7 = (t1 + 28392);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 7, t12, 32);
    t14 = (t1 + 36232);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 34312);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = ((char*)((ng7)));
    t7 = (t1 + 5776);
    t8 = *((char **)t7);
    t7 = (t1 + 28392);
    t9 = (t7 + 56U);
    t10 = *((char **)t9);
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t8, 32, t10, 32);
    memset(t12, 0, 8);
    xsi_vlog_unsigned_power(t12, 32, t6, 32, t11, 32, 1);
    memset(t13, 0, 8);
    xsi_vlog_unsigned_divide(t13, 32, t5, 7, t12, 32);
    t14 = (t1 + 36392);
    xsi_vlogvar_assign_value(t14, t13, 0, 0, 32);
    t3 = (t1 + 34152);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    memset(t11, 0, 8);
    t6 = (t5 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    t17 = *((unsigned int *)t5);
    t18 = (t17 & t16);
    t19 = (t18 & 4294967295U);
    if (t19 != 0)
        goto LAB3;

LAB4:    if (*((unsigned int *)t6) != 0)
        goto LAB5;

LAB6:    t8 = (t11 + 4);
    t20 = *((unsigned int *)t11);
    t21 = *((unsigned int *)t8);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB7;

LAB8:    memcpy(t13, t11, 8);

LAB9:    t61 = (t13 + 4);
    t62 = *((unsigned int *)t61);
    t63 = (~(t62));
    t64 = *((unsigned int *)t13);
    t65 = (t64 & t63);
    t66 = (t65 != 0);
    if (t66 > 0)
        goto LAB17;

LAB18:
LAB19:    t3 = (t1 + 34152);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    t17 = *((unsigned int *)t5);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB36;

LAB37:
LAB38:    t3 = (t1 + 34472);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 4);
    t15 = *((unsigned int *)t6);
    t16 = (~(t15));
    t17 = *((unsigned int *)t5);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB55;

LAB56:
LAB57:    t3 = (t1 + 34792);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 34952);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t15 = *((unsigned int *)t5);
    t16 = *((unsigned int *)t8);
    t17 = (t15 | t16);
    *((unsigned int *)t11) = t17;
    t9 = (t5 + 4);
    t10 = (t8 + 4);
    t14 = (t11 + 4);
    t18 = *((unsigned int *)t9);
    t19 = *((unsigned int *)t10);
    t20 = (t18 | t19);
    *((unsigned int *)t14) = t20;
    t21 = *((unsigned int *)t14);
    t22 = (t21 != 0);
    if (t22 == 1)
        goto LAB74;

LAB75:
LAB76:    t33 = (t1 + 35112);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t40 = *((unsigned int *)t11);
    t41 = *((unsigned int *)t35);
    t42 = (t40 | t41);
    *((unsigned int *)t12) = t42;
    t43 = (t11 + 4);
    t44 = (t35 + 4);
    t61 = (t12 + 4);
    t45 = *((unsigned int *)t43);
    t46 = *((unsigned int *)t44);
    t47 = (t45 | t46);
    *((unsigned int *)t61) = t47;
    t48 = *((unsigned int *)t61);
    t49 = (t48 != 0);
    if (t49 == 1)
        goto LAB77;

LAB78:
LAB79:    t69 = (t1 + 34632);
    xsi_vlogvar_assign_value(t69, t12, 0, 0, 32);
    t0 = 0;

LAB1:    return t0;
LAB3:    *((unsigned int *)t11) = 1;
    goto LAB6;

LAB5:    t7 = (t11 + 4);
    *((unsigned int *)t11) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB6;

LAB7:    t9 = (t1 + 34472);
    t10 = (t9 + 56U);
    t14 = *((char **)t10);
    memset(t12, 0, 8);
    t23 = (t14 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t14);
    t27 = (t26 & t25);
    t28 = (t27 & 4294967295U);
    if (t28 != 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t23) != 0)
        goto LAB12;

LAB13:    t30 = *((unsigned int *)t11);
    t31 = *((unsigned int *)t12);
    t32 = (t30 & t31);
    *((unsigned int *)t13) = t32;
    t33 = (t11 + 4);
    t34 = (t12 + 4);
    t35 = (t13 + 4);
    t36 = *((unsigned int *)t33);
    t37 = *((unsigned int *)t34);
    t38 = (t36 | t37);
    *((unsigned int *)t35) = t38;
    t39 = *((unsigned int *)t35);
    t40 = (t39 != 0);
    if (t40 == 1)
        goto LAB14;

LAB15:
LAB16:    goto LAB9;

LAB10:    *((unsigned int *)t12) = 1;
    goto LAB13;

LAB12:    t29 = (t12 + 4);
    *((unsigned int *)t12) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB13;

LAB14:    t41 = *((unsigned int *)t13);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t13) = (t41 | t42);
    t43 = (t11 + 4);
    t44 = (t12 + 4);
    t45 = *((unsigned int *)t11);
    t46 = (~(t45));
    t47 = *((unsigned int *)t43);
    t48 = (~(t47));
    t49 = *((unsigned int *)t12);
    t50 = (~(t49));
    t51 = *((unsigned int *)t44);
    t52 = (~(t51));
    t53 = (t46 & t48);
    t54 = (t50 & t52);
    t55 = (~(t53));
    t56 = (~(t54));
    t57 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t57 & t55);
    t58 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t58 & t56);
    t59 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t59 & t55);
    t60 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t60 & t56);
    goto LAB16;

LAB17:
LAB20:    t67 = (t1 + 28232);
    t68 = (t67 + 56U);
    t69 = *((char **)t68);
    t70 = (t1 + 28552);
    t71 = (t70 + 56U);
    t72 = *((char **)t71);
    memset(t73, 0, 8);
    xsi_vlog_signed_greater(t73, 32, t69, 32, t72, 32);
    t74 = (t73 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t73);
    t78 = (t77 & t76);
    t79 = (t78 != 0);
    if (t79 > 0)
        goto LAB21;

LAB22:
LAB30:    t3 = (t1 + 35752);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 35592);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t11, 0, 8);
    xsi_vlog_signed_equal(t11, 32, t5, 32, t8, 32);
    t9 = (t11 + 4);
    t15 = *((unsigned int *)t9);
    t16 = (~(t15));
    t17 = *((unsigned int *)t11);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB31;

LAB32:
LAB35:    t3 = ((char*)((ng4)));
    t4 = (t1 + 34792);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB33:
LAB23:    goto LAB19;

LAB21:
LAB24:    t80 = (t1 + 35272);
    t81 = (t80 + 56U);
    t82 = *((char **)t81);
    t83 = (t1 + 35432);
    t84 = (t83 + 56U);
    t85 = *((char **)t84);
    memset(t86, 0, 8);
    xsi_vlog_signed_equal(t86, 32, t82, 32, t85, 32);
    t87 = (t86 + 4);
    t88 = *((unsigned int *)t87);
    t89 = (~(t88));
    t90 = *((unsigned int *)t86);
    t91 = (t90 & t89);
    t92 = (t91 != 0);
    if (t92 > 0)
        goto LAB25;

LAB26:
LAB29:    t3 = ((char*)((ng4)));
    t4 = (t1 + 34792);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB27:    goto LAB23;

LAB25:
LAB28:    t93 = ((char*)((ng3)));
    t94 = (t1 + 34792);
    xsi_vlogvar_assign_value(t94, t93, 0, 0, 1);
    goto LAB27;

LAB31:
LAB34:    t10 = ((char*)((ng3)));
    t14 = (t1 + 34792);
    xsi_vlogvar_assign_value(t14, t10, 0, 0, 1);
    goto LAB33;

LAB36:
LAB39:    t7 = (t1 + 28232);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t1 + 28712);
    t14 = (t10 + 56U);
    t23 = *((char **)t14);
    memset(t11, 0, 8);
    xsi_vlog_signed_greater(t11, 32, t9, 32, t23, 32);
    t29 = (t11 + 4);
    t20 = *((unsigned int *)t29);
    t21 = (~(t20));
    t22 = *((unsigned int *)t11);
    t24 = (t22 & t21);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB40;

LAB41:
LAB49:    t3 = (t1 + 35752);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 35592);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t11, 0, 8);
    xsi_vlog_signed_equal(t11, 32, t5, 32, t8, 32);
    t9 = (t11 + 4);
    t15 = *((unsigned int *)t9);
    t16 = (~(t15));
    t17 = *((unsigned int *)t11);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB50;

LAB51:
LAB54:    t3 = ((char*)((ng4)));
    t4 = (t1 + 34952);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB52:
LAB42:    goto LAB38;

LAB40:
LAB43:    t33 = (t1 + 35912);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t43 = (t1 + 36072);
    t44 = (t43 + 56U);
    t61 = *((char **)t44);
    memset(t12, 0, 8);
    xsi_vlog_signed_equal(t12, 32, t35, 32, t61, 32);
    t67 = (t12 + 4);
    t26 = *((unsigned int *)t67);
    t27 = (~(t26));
    t28 = *((unsigned int *)t12);
    t30 = (t28 & t27);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB44;

LAB45:
LAB48:    t3 = ((char*)((ng4)));
    t4 = (t1 + 34952);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB46:    goto LAB42;

LAB44:
LAB47:    t68 = ((char*)((ng3)));
    t69 = (t1 + 34952);
    xsi_vlogvar_assign_value(t69, t68, 0, 0, 1);
    goto LAB46;

LAB50:
LAB53:    t10 = ((char*)((ng3)));
    t14 = (t1 + 34952);
    xsi_vlogvar_assign_value(t14, t10, 0, 0, 1);
    goto LAB52;

LAB55:
LAB58:    t7 = (t1 + 28392);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t1 + 28552);
    t14 = (t10 + 56U);
    t23 = *((char **)t14);
    memset(t11, 0, 8);
    xsi_vlog_signed_greater(t11, 32, t9, 32, t23, 32);
    t29 = (t11 + 4);
    t20 = *((unsigned int *)t29);
    t21 = (~(t20));
    t22 = *((unsigned int *)t11);
    t24 = (t22 & t21);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB59;

LAB60:
LAB68:    t3 = (t1 + 36392);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t1 + 36232);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memset(t11, 0, 8);
    xsi_vlog_signed_equal(t11, 32, t5, 32, t8, 32);
    t9 = (t11 + 4);
    t15 = *((unsigned int *)t9);
    t16 = (~(t15));
    t17 = *((unsigned int *)t11);
    t18 = (t17 & t16);
    t19 = (t18 != 0);
    if (t19 > 0)
        goto LAB69;

LAB70:
LAB73:    t3 = ((char*)((ng4)));
    t4 = (t1 + 35112);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB71:
LAB61:    goto LAB57;

LAB59:
LAB62:    t33 = (t1 + 35272);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t43 = (t1 + 35432);
    t44 = (t43 + 56U);
    t61 = *((char **)t44);
    memset(t12, 0, 8);
    xsi_vlog_signed_equal(t12, 32, t35, 32, t61, 32);
    t67 = (t12 + 4);
    t26 = *((unsigned int *)t67);
    t27 = (~(t26));
    t28 = *((unsigned int *)t12);
    t30 = (t28 & t27);
    t31 = (t30 != 0);
    if (t31 > 0)
        goto LAB63;

LAB64:
LAB67:    t3 = ((char*)((ng4)));
    t4 = (t1 + 35112);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);

LAB65:    goto LAB61;

LAB63:
LAB66:    t68 = ((char*)((ng3)));
    t69 = (t1 + 35112);
    xsi_vlogvar_assign_value(t69, t68, 0, 0, 1);
    goto LAB65;

LAB69:
LAB72:    t10 = ((char*)((ng3)));
    t14 = (t1 + 35112);
    xsi_vlogvar_assign_value(t14, t10, 0, 0, 1);
    goto LAB71;

LAB74:    t24 = *((unsigned int *)t11);
    t25 = *((unsigned int *)t14);
    *((unsigned int *)t11) = (t24 | t25);
    t23 = (t5 + 4);
    t29 = (t8 + 4);
    t26 = *((unsigned int *)t23);
    t27 = (~(t26));
    t28 = *((unsigned int *)t5);
    t53 = (t28 & t27);
    t30 = *((unsigned int *)t29);
    t31 = (~(t30));
    t32 = *((unsigned int *)t8);
    t54 = (t32 & t31);
    t36 = (~(t53));
    t37 = (~(t54));
    t38 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t38 & t36);
    t39 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t39 & t37);
    goto LAB76;

LAB77:    t50 = *((unsigned int *)t12);
    t51 = *((unsigned int *)t61);
    *((unsigned int *)t12) = (t50 | t51);
    t67 = (t11 + 4);
    t68 = (t35 + 4);
    t52 = *((unsigned int *)t67);
    t55 = (~(t52));
    t56 = *((unsigned int *)t11);
    t95 = (t56 & t55);
    t57 = *((unsigned int *)t68);
    t58 = (~(t57));
    t59 = *((unsigned int *)t35);
    t96 = (t59 & t58);
    t60 = (~(t95));
    t62 = (~(t96));
    t63 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t63 & t60);
    t64 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t64 & t62);
    goto LAB79;

}

static void Cont_840_0(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t7[8];
    char t21[8];
    char t22[8];
    char t30[8];
    char t62[8];
    char t77[8];
    char t78[8];
    char t86[8];
    char t127[8];
    char *t1;
    char *t2;
    char *t5;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    int t54;
    int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    char *t100;
    char *t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    char *t125;
    char *t126;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;
    char *t133;
    char *t134;
    char *t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    char *t139;
    unsigned int t140;
    unsigned int t141;
    char *t142;
    unsigned int t143;
    unsigned int t144;
    char *t145;

LAB0:    t1 = (t0 + 37312U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 880);
    t5 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_equal(t6, 32, t5, 32, t2, 32);
    memset(t7, 0, 8);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t8) != 0)
        goto LAB6;

LAB7:    t15 = (t7 + 4);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t15);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB8;

LAB9:    memcpy(t30, t7, 8);

LAB10:    memset(t62, 0, 8);
    t63 = (t30 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t30);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t63) != 0)
        goto LAB20;

LAB21:    t70 = (t62 + 4);
    t71 = *((unsigned int *)t62);
    t72 = (!(t71));
    t73 = *((unsigned int *)t70);
    t74 = (t72 || t73);
    if (t74 > 0)
        goto LAB22;

LAB23:    memcpy(t86, t62, 8);

LAB24:    memset(t4, 0, 8);
    t114 = (t86 + 4);
    t115 = *((unsigned int *)t114);
    t116 = (~(t115));
    t117 = *((unsigned int *)t86);
    t118 = (t117 & t116);
    t119 = (t118 & 1U);
    if (t119 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t114) != 0)
        goto LAB34;

LAB35:    t121 = (t4 + 4);
    t122 = *((unsigned int *)t4);
    t123 = *((unsigned int *)t121);
    t124 = (t122 || t123);
    if (t124 > 0)
        goto LAB36;

LAB37:    t128 = *((unsigned int *)t4);
    t129 = (~(t128));
    t130 = *((unsigned int *)t121);
    t131 = (t129 || t130);
    if (t131 > 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t121) > 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t4) > 0)
        goto LAB42;

LAB43:    memcpy(t3, t125, 8);

LAB44:    t132 = (t0 + 43984);
    t133 = (t132 + 56U);
    t134 = *((char **)t133);
    t135 = (t134 + 56U);
    t136 = *((char **)t135);
    memset(t136, 0, 8);
    t137 = 1U;
    t138 = t137;
    t139 = (t3 + 4);
    t140 = *((unsigned int *)t3);
    t137 = (t137 & t140);
    t141 = *((unsigned int *)t139);
    t138 = (t138 & t141);
    t142 = (t136 + 4);
    t143 = *((unsigned int *)t136);
    *((unsigned int *)t136) = (t143 | t137);
    t144 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t144 | t138);
    xsi_driver_vfirst_trans(t132, 0, 0);
    t145 = (t0 + 43584);
    *((int *)t145) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t7) = 1;
    goto LAB7;

LAB6:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB7;

LAB8:    t19 = (t0 + 7000);
    t20 = *((char **)t19);
    t19 = ((char*)((ng3)));
    memset(t21, 0, 8);
    xsi_vlog_signed_equal(t21, 32, t20, 32, t19, 32);
    memset(t22, 0, 8);
    t23 = (t21 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t21);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t23) != 0)
        goto LAB13;

LAB14:    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t22);
    t33 = (t31 & t32);
    *((unsigned int *)t30) = t33;
    t34 = (t7 + 4);
    t35 = (t22 + 4);
    t36 = (t30 + 4);
    t37 = *((unsigned int *)t34);
    t38 = *((unsigned int *)t35);
    t39 = (t37 | t38);
    *((unsigned int *)t36) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 != 0);
    if (t41 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t22) = 1;
    goto LAB14;

LAB13:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB14;

LAB15:    t42 = *((unsigned int *)t30);
    t43 = *((unsigned int *)t36);
    *((unsigned int *)t30) = (t42 | t43);
    t44 = (t7 + 4);
    t45 = (t22 + 4);
    t46 = *((unsigned int *)t7);
    t47 = (~(t46));
    t48 = *((unsigned int *)t44);
    t49 = (~(t48));
    t50 = *((unsigned int *)t22);
    t51 = (~(t50));
    t52 = *((unsigned int *)t45);
    t53 = (~(t52));
    t54 = (t47 & t49);
    t55 = (t51 & t53);
    t56 = (~(t54));
    t57 = (~(t55));
    t58 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t58 & t56);
    t59 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t59 & t57);
    t60 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t60 & t56);
    t61 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t61 & t57);
    goto LAB17;

LAB18:    *((unsigned int *)t62) = 1;
    goto LAB21;

LAB20:    t69 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB21;

LAB22:    t75 = (t0 + 6864);
    t76 = *((char **)t75);
    t75 = ((char*)((ng3)));
    memset(t77, 0, 8);
    xsi_vlog_signed_equal(t77, 32, t76, 32, t75, 32);
    memset(t78, 0, 8);
    t79 = (t77 + 4);
    t80 = *((unsigned int *)t79);
    t81 = (~(t80));
    t82 = *((unsigned int *)t77);
    t83 = (t82 & t81);
    t84 = (t83 & 1U);
    if (t84 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t79) != 0)
        goto LAB27;

LAB28:    t87 = *((unsigned int *)t62);
    t88 = *((unsigned int *)t78);
    t89 = (t87 | t88);
    *((unsigned int *)t86) = t89;
    t90 = (t62 + 4);
    t91 = (t78 + 4);
    t92 = (t86 + 4);
    t93 = *((unsigned int *)t90);
    t94 = *((unsigned int *)t91);
    t95 = (t93 | t94);
    *((unsigned int *)t92) = t95;
    t96 = *((unsigned int *)t92);
    t97 = (t96 != 0);
    if (t97 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t78) = 1;
    goto LAB28;

LAB27:    t85 = (t78 + 4);
    *((unsigned int *)t78) = 1;
    *((unsigned int *)t85) = 1;
    goto LAB28;

LAB29:    t98 = *((unsigned int *)t86);
    t99 = *((unsigned int *)t92);
    *((unsigned int *)t86) = (t98 | t99);
    t100 = (t62 + 4);
    t101 = (t78 + 4);
    t102 = *((unsigned int *)t100);
    t103 = (~(t102));
    t104 = *((unsigned int *)t62);
    t105 = (t104 & t103);
    t106 = *((unsigned int *)t101);
    t107 = (~(t106));
    t108 = *((unsigned int *)t78);
    t109 = (t108 & t107);
    t110 = (~(t105));
    t111 = (~(t109));
    t112 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t112 & t110);
    t113 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t113 & t111);
    goto LAB31;

LAB32:    *((unsigned int *)t4) = 1;
    goto LAB35;

LAB34:    t120 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t120) = 1;
    goto LAB35;

LAB36:    t125 = (t0 + 19992U);
    t126 = *((char **)t125);
    memcpy(t127, t126, 8);
    goto LAB37;

LAB38:    t125 = ((char*)((ng4)));
    goto LAB39;

LAB40:    xsi_vlog_unsigned_bit_combine(t3, 32, t127, 32, t125, 32);
    goto LAB44;

LAB42:    memcpy(t3, t127, 8);
    goto LAB44;

}

static void Cont_841_1(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t7[8];
    char t21[8];
    char t22[8];
    char t30[8];
    char t62[8];
    char t77[8];
    char t78[8];
    char t86[8];
    char t127[8];
    char *t1;
    char *t2;
    char *t5;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    int t54;
    int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    char *t100;
    char *t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    char *t125;
    char *t126;
    unsigned int t128;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;
    char *t133;
    char *t134;
    char *t135;
    char *t136;
    unsigned int t137;
    unsigned int t138;
    char *t139;
    unsigned int t140;
    unsigned int t141;
    char *t142;
    unsigned int t143;
    unsigned int t144;
    char *t145;

LAB0:    t1 = (t0 + 37560U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 880);
    t5 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_equal(t6, 32, t5, 32, t2, 32);
    memset(t7, 0, 8);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t8) != 0)
        goto LAB6;

LAB7:    t15 = (t7 + 4);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t15);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB8;

LAB9:    memcpy(t30, t7, 8);

LAB10:    memset(t62, 0, 8);
    t63 = (t30 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t30);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t63) != 0)
        goto LAB20;

LAB21:    t70 = (t62 + 4);
    t71 = *((unsigned int *)t62);
    t72 = (!(t71));
    t73 = *((unsigned int *)t70);
    t74 = (t72 || t73);
    if (t74 > 0)
        goto LAB22;

LAB23:    memcpy(t86, t62, 8);

LAB24:    memset(t4, 0, 8);
    t114 = (t86 + 4);
    t115 = *((unsigned int *)t114);
    t116 = (~(t115));
    t117 = *((unsigned int *)t86);
    t118 = (t117 & t116);
    t119 = (t118 & 1U);
    if (t119 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t114) != 0)
        goto LAB34;

LAB35:    t121 = (t4 + 4);
    t122 = *((unsigned int *)t4);
    t123 = *((unsigned int *)t121);
    t124 = (t122 || t123);
    if (t124 > 0)
        goto LAB36;

LAB37:    t128 = *((unsigned int *)t4);
    t129 = (~(t128));
    t130 = *((unsigned int *)t121);
    t131 = (t129 || t130);
    if (t131 > 0)
        goto LAB38;

LAB39:    if (*((unsigned int *)t121) > 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t4) > 0)
        goto LAB42;

LAB43:    memcpy(t3, t125, 8);

LAB44:    t132 = (t0 + 44048);
    t133 = (t132 + 56U);
    t134 = *((char **)t133);
    t135 = (t134 + 56U);
    t136 = *((char **)t135);
    memset(t136, 0, 8);
    t137 = 1U;
    t138 = t137;
    t139 = (t3 + 4);
    t140 = *((unsigned int *)t3);
    t137 = (t137 & t140);
    t141 = *((unsigned int *)t139);
    t138 = (t138 & t141);
    t142 = (t136 + 4);
    t143 = *((unsigned int *)t136);
    *((unsigned int *)t136) = (t143 | t137);
    t144 = *((unsigned int *)t142);
    *((unsigned int *)t142) = (t144 | t138);
    xsi_driver_vfirst_trans(t132, 0, 0);
    t145 = (t0 + 43600);
    *((int *)t145) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t7) = 1;
    goto LAB7;

LAB6:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB7;

LAB8:    t19 = (t0 + 7000);
    t20 = *((char **)t19);
    t19 = ((char*)((ng3)));
    memset(t21, 0, 8);
    xsi_vlog_signed_equal(t21, 32, t20, 32, t19, 32);
    memset(t22, 0, 8);
    t23 = (t21 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t21);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t23) != 0)
        goto LAB13;

LAB14:    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t22);
    t33 = (t31 & t32);
    *((unsigned int *)t30) = t33;
    t34 = (t7 + 4);
    t35 = (t22 + 4);
    t36 = (t30 + 4);
    t37 = *((unsigned int *)t34);
    t38 = *((unsigned int *)t35);
    t39 = (t37 | t38);
    *((unsigned int *)t36) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 != 0);
    if (t41 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t22) = 1;
    goto LAB14;

LAB13:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB14;

LAB15:    t42 = *((unsigned int *)t30);
    t43 = *((unsigned int *)t36);
    *((unsigned int *)t30) = (t42 | t43);
    t44 = (t7 + 4);
    t45 = (t22 + 4);
    t46 = *((unsigned int *)t7);
    t47 = (~(t46));
    t48 = *((unsigned int *)t44);
    t49 = (~(t48));
    t50 = *((unsigned int *)t22);
    t51 = (~(t50));
    t52 = *((unsigned int *)t45);
    t53 = (~(t52));
    t54 = (t47 & t49);
    t55 = (t51 & t53);
    t56 = (~(t54));
    t57 = (~(t55));
    t58 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t58 & t56);
    t59 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t59 & t57);
    t60 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t60 & t56);
    t61 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t61 & t57);
    goto LAB17;

LAB18:    *((unsigned int *)t62) = 1;
    goto LAB21;

LAB20:    t69 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB21;

LAB22:    t75 = (t0 + 6864);
    t76 = *((char **)t75);
    t75 = ((char*)((ng3)));
    memset(t77, 0, 8);
    xsi_vlog_signed_equal(t77, 32, t76, 32, t75, 32);
    memset(t78, 0, 8);
    t79 = (t77 + 4);
    t80 = *((unsigned int *)t79);
    t81 = (~(t80));
    t82 = *((unsigned int *)t77);
    t83 = (t82 & t81);
    t84 = (t83 & 1U);
    if (t84 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t79) != 0)
        goto LAB27;

LAB28:    t87 = *((unsigned int *)t62);
    t88 = *((unsigned int *)t78);
    t89 = (t87 | t88);
    *((unsigned int *)t86) = t89;
    t90 = (t62 + 4);
    t91 = (t78 + 4);
    t92 = (t86 + 4);
    t93 = *((unsigned int *)t90);
    t94 = *((unsigned int *)t91);
    t95 = (t93 | t94);
    *((unsigned int *)t92) = t95;
    t96 = *((unsigned int *)t92);
    t97 = (t96 != 0);
    if (t97 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t78) = 1;
    goto LAB28;

LAB27:    t85 = (t78 + 4);
    *((unsigned int *)t78) = 1;
    *((unsigned int *)t85) = 1;
    goto LAB28;

LAB29:    t98 = *((unsigned int *)t86);
    t99 = *((unsigned int *)t92);
    *((unsigned int *)t86) = (t98 | t99);
    t100 = (t62 + 4);
    t101 = (t78 + 4);
    t102 = *((unsigned int *)t100);
    t103 = (~(t102));
    t104 = *((unsigned int *)t62);
    t105 = (t104 & t103);
    t106 = *((unsigned int *)t101);
    t107 = (~(t106));
    t108 = *((unsigned int *)t78);
    t109 = (t108 & t107);
    t110 = (~(t105));
    t111 = (~(t109));
    t112 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t112 & t110);
    t113 = *((unsigned int *)t92);
    *((unsigned int *)t92) = (t113 & t111);
    goto LAB31;

LAB32:    *((unsigned int *)t4) = 1;
    goto LAB35;

LAB34:    t120 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t120) = 1;
    goto LAB35;

LAB36:    t125 = (t0 + 20152U);
    t126 = *((char **)t125);
    memcpy(t127, t126, 8);
    goto LAB37;

LAB38:    t125 = ((char*)((ng4)));
    goto LAB39;

LAB40:    xsi_vlog_unsigned_bit_combine(t3, 32, t127, 32, t125, 32);
    goto LAB44;

LAB42:    memcpy(t3, t127, 8);
    goto LAB44;

}

static void Cont_842_2(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[16];
    char t7[8];
    char t21[8];
    char t22[8];
    char t30[8];
    char t62[8];
    char t76[8];
    char t77[8];
    char t85[8];
    char t117[8];
    char t132[8];
    char t133[8];
    char t141[8];
    char t182[8];
    char *t1;
    char *t2;
    char *t5;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    int t54;
    int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    char *t74;
    char *t75;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;
    char *t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    char *t99;
    char *t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    unsigned int t108;
    int t109;
    int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    char *t124;
    char *t125;
    unsigned int t126;
    unsigned int t127;
    unsigned int t128;
    unsigned int t129;
    char *t130;
    char *t131;
    char *t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    char *t140;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    char *t145;
    char *t146;
    char *t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    unsigned int t154;
    char *t155;
    char *t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    int t164;
    unsigned int t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    char *t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    unsigned int t174;
    char *t175;
    char *t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    char *t180;
    char *t181;
    unsigned int t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    char *t187;
    char *t188;
    char *t189;
    char *t190;
    char *t191;
    unsigned int t192;
    unsigned int t193;
    char *t194;
    unsigned int t195;
    unsigned int t196;
    char *t197;
    unsigned int t198;
    unsigned int t199;
    char *t200;

LAB0:    t1 = (t0 + 37808U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng11)));
    t5 = ((char*)((ng12)));
    xsi_vlog_unsigned_equal(t6, 64, t2, 64, t5, 64);
    memset(t7, 0, 8);
    t8 = (t6 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t8) != 0)
        goto LAB6;

LAB7:    t15 = (t7 + 4);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t15);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB8;

LAB9:    memcpy(t30, t7, 8);

LAB10:    memset(t62, 0, 8);
    t63 = (t30 + 4);
    t64 = *((unsigned int *)t63);
    t65 = (~(t64));
    t66 = *((unsigned int *)t30);
    t67 = (t66 & t65);
    t68 = (t67 & 1U);
    if (t68 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t63) != 0)
        goto LAB20;

LAB21:    t70 = (t62 + 4);
    t71 = *((unsigned int *)t62);
    t72 = *((unsigned int *)t70);
    t73 = (t71 || t72);
    if (t73 > 0)
        goto LAB22;

LAB23:    memcpy(t85, t62, 8);

LAB24:    memset(t117, 0, 8);
    t118 = (t85 + 4);
    t119 = *((unsigned int *)t118);
    t120 = (~(t119));
    t121 = *((unsigned int *)t85);
    t122 = (t121 & t120);
    t123 = (t122 & 1U);
    if (t123 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t118) != 0)
        goto LAB34;

LAB35:    t125 = (t117 + 4);
    t126 = *((unsigned int *)t117);
    t127 = (!(t126));
    t128 = *((unsigned int *)t125);
    t129 = (t127 || t128);
    if (t129 > 0)
        goto LAB36;

LAB37:    memcpy(t141, t117, 8);

LAB38:    memset(t4, 0, 8);
    t169 = (t141 + 4);
    t170 = *((unsigned int *)t169);
    t171 = (~(t170));
    t172 = *((unsigned int *)t141);
    t173 = (t172 & t171);
    t174 = (t173 & 1U);
    if (t174 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t169) != 0)
        goto LAB48;

LAB49:    t176 = (t4 + 4);
    t177 = *((unsigned int *)t4);
    t178 = *((unsigned int *)t176);
    t179 = (t177 || t178);
    if (t179 > 0)
        goto LAB50;

LAB51:    t183 = *((unsigned int *)t4);
    t184 = (~(t183));
    t185 = *((unsigned int *)t176);
    t186 = (t184 || t185);
    if (t186 > 0)
        goto LAB52;

LAB53:    if (*((unsigned int *)t176) > 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t4) > 0)
        goto LAB56;

LAB57:    memcpy(t3, t180, 8);

LAB58:    t187 = (t0 + 44112);
    t188 = (t187 + 56U);
    t189 = *((char **)t188);
    t190 = (t189 + 56U);
    t191 = *((char **)t190);
    memset(t191, 0, 8);
    t192 = 127U;
    t193 = t192;
    t194 = (t3 + 4);
    t195 = *((unsigned int *)t3);
    t192 = (t192 & t195);
    t196 = *((unsigned int *)t194);
    t193 = (t193 & t196);
    t197 = (t191 + 4);
    t198 = *((unsigned int *)t191);
    *((unsigned int *)t191) = (t198 | t192);
    t199 = *((unsigned int *)t197);
    *((unsigned int *)t197) = (t199 | t193);
    xsi_driver_vfirst_trans(t187, 0, 6);
    t200 = (t0 + 43616);
    *((int *)t200) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t7) = 1;
    goto LAB7;

LAB6:    t14 = (t7 + 4);
    *((unsigned int *)t7) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB7;

LAB8:    t19 = (t0 + 880);
    t20 = *((char **)t19);
    t19 = ((char*)((ng3)));
    memset(t21, 0, 8);
    xsi_vlog_signed_equal(t21, 32, t20, 32, t19, 32);
    memset(t22, 0, 8);
    t23 = (t21 + 4);
    t24 = *((unsigned int *)t23);
    t25 = (~(t24));
    t26 = *((unsigned int *)t21);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t23) != 0)
        goto LAB13;

LAB14:    t31 = *((unsigned int *)t7);
    t32 = *((unsigned int *)t22);
    t33 = (t31 & t32);
    *((unsigned int *)t30) = t33;
    t34 = (t7 + 4);
    t35 = (t22 + 4);
    t36 = (t30 + 4);
    t37 = *((unsigned int *)t34);
    t38 = *((unsigned int *)t35);
    t39 = (t37 | t38);
    *((unsigned int *)t36) = t39;
    t40 = *((unsigned int *)t36);
    t41 = (t40 != 0);
    if (t41 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t22) = 1;
    goto LAB14;

LAB13:    t29 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB14;

LAB15:    t42 = *((unsigned int *)t30);
    t43 = *((unsigned int *)t36);
    *((unsigned int *)t30) = (t42 | t43);
    t44 = (t7 + 4);
    t45 = (t22 + 4);
    t46 = *((unsigned int *)t7);
    t47 = (~(t46));
    t48 = *((unsigned int *)t44);
    t49 = (~(t48));
    t50 = *((unsigned int *)t22);
    t51 = (~(t50));
    t52 = *((unsigned int *)t45);
    t53 = (~(t52));
    t54 = (t47 & t49);
    t55 = (t51 & t53);
    t56 = (~(t54));
    t57 = (~(t55));
    t58 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t58 & t56);
    t59 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t59 & t57);
    t60 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t60 & t56);
    t61 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t61 & t57);
    goto LAB17;

LAB18:    *((unsigned int *)t62) = 1;
    goto LAB21;

LAB20:    t69 = (t62 + 4);
    *((unsigned int *)t62) = 1;
    *((unsigned int *)t69) = 1;
    goto LAB21;

LAB22:    t74 = (t0 + 7000);
    t75 = *((char **)t74);
    t74 = ((char*)((ng3)));
    memset(t76, 0, 8);
    xsi_vlog_signed_equal(t76, 32, t75, 32, t74, 32);
    memset(t77, 0, 8);
    t78 = (t76 + 4);
    t79 = *((unsigned int *)t78);
    t80 = (~(t79));
    t81 = *((unsigned int *)t76);
    t82 = (t81 & t80);
    t83 = (t82 & 1U);
    if (t83 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t78) != 0)
        goto LAB27;

LAB28:    t86 = *((unsigned int *)t62);
    t87 = *((unsigned int *)t77);
    t88 = (t86 & t87);
    *((unsigned int *)t85) = t88;
    t89 = (t62 + 4);
    t90 = (t77 + 4);
    t91 = (t85 + 4);
    t92 = *((unsigned int *)t89);
    t93 = *((unsigned int *)t90);
    t94 = (t92 | t93);
    *((unsigned int *)t91) = t94;
    t95 = *((unsigned int *)t91);
    t96 = (t95 != 0);
    if (t96 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t77) = 1;
    goto LAB28;

LAB27:    t84 = (t77 + 4);
    *((unsigned int *)t77) = 1;
    *((unsigned int *)t84) = 1;
    goto LAB28;

LAB29:    t97 = *((unsigned int *)t85);
    t98 = *((unsigned int *)t91);
    *((unsigned int *)t85) = (t97 | t98);
    t99 = (t62 + 4);
    t100 = (t77 + 4);
    t101 = *((unsigned int *)t62);
    t102 = (~(t101));
    t103 = *((unsigned int *)t99);
    t104 = (~(t103));
    t105 = *((unsigned int *)t77);
    t106 = (~(t105));
    t107 = *((unsigned int *)t100);
    t108 = (~(t107));
    t109 = (t102 & t104);
    t110 = (t106 & t108);
    t111 = (~(t109));
    t112 = (~(t110));
    t113 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t113 & t111);
    t114 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t114 & t112);
    t115 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t115 & t111);
    t116 = *((unsigned int *)t85);
    *((unsigned int *)t85) = (t116 & t112);
    goto LAB31;

LAB32:    *((unsigned int *)t117) = 1;
    goto LAB35;

LAB34:    t124 = (t117 + 4);
    *((unsigned int *)t117) = 1;
    *((unsigned int *)t124) = 1;
    goto LAB35;

LAB36:    t130 = (t0 + 6864);
    t131 = *((char **)t130);
    t130 = ((char*)((ng3)));
    memset(t132, 0, 8);
    xsi_vlog_signed_equal(t132, 32, t131, 32, t130, 32);
    memset(t133, 0, 8);
    t134 = (t132 + 4);
    t135 = *((unsigned int *)t134);
    t136 = (~(t135));
    t137 = *((unsigned int *)t132);
    t138 = (t137 & t136);
    t139 = (t138 & 1U);
    if (t139 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t134) != 0)
        goto LAB41;

LAB42:    t142 = *((unsigned int *)t117);
    t143 = *((unsigned int *)t133);
    t144 = (t142 | t143);
    *((unsigned int *)t141) = t144;
    t145 = (t117 + 4);
    t146 = (t133 + 4);
    t147 = (t141 + 4);
    t148 = *((unsigned int *)t145);
    t149 = *((unsigned int *)t146);
    t150 = (t148 | t149);
    *((unsigned int *)t147) = t150;
    t151 = *((unsigned int *)t147);
    t152 = (t151 != 0);
    if (t152 == 1)
        goto LAB43;

LAB44:
LAB45:    goto LAB38;

LAB39:    *((unsigned int *)t133) = 1;
    goto LAB42;

LAB41:    t140 = (t133 + 4);
    *((unsigned int *)t133) = 1;
    *((unsigned int *)t140) = 1;
    goto LAB42;

LAB43:    t153 = *((unsigned int *)t141);
    t154 = *((unsigned int *)t147);
    *((unsigned int *)t141) = (t153 | t154);
    t155 = (t117 + 4);
    t156 = (t133 + 4);
    t157 = *((unsigned int *)t155);
    t158 = (~(t157));
    t159 = *((unsigned int *)t117);
    t160 = (t159 & t158);
    t161 = *((unsigned int *)t156);
    t162 = (~(t161));
    t163 = *((unsigned int *)t133);
    t164 = (t163 & t162);
    t165 = (~(t160));
    t166 = (~(t164));
    t167 = *((unsigned int *)t147);
    *((unsigned int *)t147) = (t167 & t165);
    t168 = *((unsigned int *)t147);
    *((unsigned int *)t147) = (t168 & t166);
    goto LAB45;

LAB46:    *((unsigned int *)t4) = 1;
    goto LAB49;

LAB48:    t175 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t175) = 1;
    goto LAB49;

LAB50:    t180 = (t0 + 20952U);
    t181 = *((char **)t180);
    memcpy(t182, t181, 8);
    goto LAB51;

LAB52:    t180 = ((char*)((ng4)));
    goto LAB53;

LAB54:    xsi_vlog_unsigned_bit_combine(t3, 32, t182, 32, t180, 32);
    goto LAB58;

LAB56:    memcpy(t3, t182, 8);
    goto LAB58;

}

static void Cont_846_3(char *t0)
{
    char t4[8];
    char t5[8];
    char t20[8];
    char t27[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;

LAB0:    t1 = (t0 + 38056U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2648);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_equal(t4, 32, t3, 32, t2, 32);
    memset(t5, 0, 8);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    memcpy(t27, t5, 8);

LAB10:    t55 = (t0 + 44176);
    t56 = (t55 + 56U);
    t57 = *((char **)t56);
    t58 = (t57 + 56U);
    t59 = *((char **)t58);
    memset(t59, 0, 8);
    t60 = 1U;
    t61 = t60;
    t62 = (t27 + 4);
    t63 = *((unsigned int *)t27);
    t60 = (t60 & t63);
    t64 = *((unsigned int *)t62);
    t61 = (t61 & t64);
    t65 = (t59 + 4);
    t66 = *((unsigned int *)t59);
    *((unsigned int *)t59) = (t66 | t60);
    t67 = *((unsigned int *)t65);
    *((unsigned int *)t65) = (t67 | t61);
    xsi_driver_vfirst_trans(t55, 0, 0);
    t68 = (t0 + 43632);
    *((int *)t68) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 16952U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t18) != 0)
        goto LAB13;

LAB14:    t28 = *((unsigned int *)t5);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t5 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t20) = 1;
    goto LAB14;

LAB13:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB14;

LAB15:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t5 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t5);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB17;

}

static void Cont_847_4(char *t0)
{
    char t4[8];
    char t5[8];
    char t20[8];
    char t27[8];
    char t55[8];
    char t68[8];
    char t76[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    char *t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    char *t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    char *t81;
    char *t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    int t100;
    int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    char *t108;
    char *t109;
    char *t110;
    char *t111;
    char *t112;
    unsigned int t113;
    unsigned int t114;
    char *t115;
    unsigned int t116;
    unsigned int t117;
    char *t118;
    unsigned int t119;
    unsigned int t120;
    char *t121;

LAB0:    t1 = (t0 + 38304U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 4552);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t4, 0, 8);
    xsi_vlog_signed_equal(t4, 32, t3, 32, t2, 32);
    memset(t5, 0, 8);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB8;

LAB9:    memcpy(t27, t5, 8);

LAB10:    memset(t55, 0, 8);
    t56 = (t27 + 4);
    t57 = *((unsigned int *)t56);
    t58 = (~(t57));
    t59 = *((unsigned int *)t27);
    t60 = (t59 & t58);
    t61 = (t60 & 1U);
    if (t61 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t56) != 0)
        goto LAB20;

LAB21:    t63 = (t55 + 4);
    t64 = *((unsigned int *)t55);
    t65 = *((unsigned int *)t63);
    t66 = (t64 || t65);
    if (t66 > 0)
        goto LAB22;

LAB23:    memcpy(t76, t55, 8);

LAB24:    t108 = (t0 + 44240);
    t109 = (t108 + 56U);
    t110 = *((char **)t109);
    t111 = (t110 + 56U);
    t112 = *((char **)t111);
    memset(t112, 0, 8);
    t113 = 1U;
    t114 = t113;
    t115 = (t76 + 4);
    t116 = *((unsigned int *)t76);
    t113 = (t113 & t116);
    t117 = *((unsigned int *)t115);
    t114 = (t114 & t117);
    t118 = (t112 + 4);
    t119 = *((unsigned int *)t112);
    *((unsigned int *)t112) = (t119 | t113);
    t120 = *((unsigned int *)t118);
    *((unsigned int *)t118) = (t120 | t114);
    xsi_driver_vfirst_trans(t108, 0, 0);
    t121 = (t0 + 43648);
    *((int *)t121) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t18 = (t0 + 18232U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t18) != 0)
        goto LAB13;

LAB14:    t28 = *((unsigned int *)t5);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t5 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t20) = 1;
    goto LAB14;

LAB13:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB14;

LAB15:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t5 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t5);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB17;

LAB18:    *((unsigned int *)t55) = 1;
    goto LAB21;

LAB20:    t62 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB21;

LAB22:    t67 = ((char*)((ng16)));
    memset(t68, 0, 8);
    t69 = (t67 + 4);
    t70 = *((unsigned int *)t69);
    t71 = (~(t70));
    t72 = *((unsigned int *)t67);
    t73 = (t72 & t71);
    t74 = (t73 & 1U);
    if (t74 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t69) != 0)
        goto LAB27;

LAB28:    t77 = *((unsigned int *)t55);
    t78 = *((unsigned int *)t68);
    t79 = (t77 & t78);
    *((unsigned int *)t76) = t79;
    t80 = (t55 + 4);
    t81 = (t68 + 4);
    t82 = (t76 + 4);
    t83 = *((unsigned int *)t80);
    t84 = *((unsigned int *)t81);
    t85 = (t83 | t84);
    *((unsigned int *)t82) = t85;
    t86 = *((unsigned int *)t82);
    t87 = (t86 != 0);
    if (t87 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t68) = 1;
    goto LAB28;

LAB27:    t75 = (t68 + 4);
    *((unsigned int *)t68) = 1;
    *((unsigned int *)t75) = 1;
    goto LAB28;

LAB29:    t88 = *((unsigned int *)t76);
    t89 = *((unsigned int *)t82);
    *((unsigned int *)t76) = (t88 | t89);
    t90 = (t55 + 4);
    t91 = (t68 + 4);
    t92 = *((unsigned int *)t55);
    t93 = (~(t92));
    t94 = *((unsigned int *)t90);
    t95 = (~(t94));
    t96 = *((unsigned int *)t68);
    t97 = (~(t96));
    t98 = *((unsigned int *)t91);
    t99 = (~(t98));
    t100 = (t93 & t95);
    t101 = (t97 & t99);
    t102 = (~(t100));
    t103 = (~(t101));
    t104 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t104 & t102);
    t105 = *((unsigned int *)t82);
    *((unsigned int *)t82) = (t105 & t103);
    t106 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t106 & t102);
    t107 = *((unsigned int *)t76);
    *((unsigned int *)t76) = (t107 & t103);
    goto LAB31;

}

static void Cont_848_5(char *t0)
{
    char t3[8];
    char t4[8];
    char t5[8];
    char t19[8];
    char t26[8];
    char t71[8];
    char *t1;
    char *t2;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;

LAB0:    t1 = (t0 + 38552U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng9)));
    memset(t5, 0, 8);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t2);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB8;

LAB9:    memcpy(t26, t5, 8);

LAB10:    memset(t4, 0, 8);
    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 & 1U);
    if (t63 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t58) != 0)
        goto LAB20;

LAB21:    t65 = (t4 + 4);
    t66 = *((unsigned int *)t4);
    t67 = *((unsigned int *)t65);
    t68 = (t66 || t67);
    if (t68 > 0)
        goto LAB22;

LAB23:    t72 = *((unsigned int *)t4);
    t73 = (~(t72));
    t74 = *((unsigned int *)t65);
    t75 = (t73 || t74);
    if (t75 > 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t65) > 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t4) > 0)
        goto LAB28;

LAB29:    memcpy(t3, t69, 8);

LAB30:    t76 = (t0 + 44304);
    t77 = (t76 + 56U);
    t78 = *((char **)t77);
    t79 = (t78 + 56U);
    t80 = *((char **)t79);
    memset(t80, 0, 8);
    t81 = 1U;
    t82 = t81;
    t83 = (t3 + 4);
    t84 = *((unsigned int *)t3);
    t81 = (t81 & t84);
    t85 = *((unsigned int *)t83);
    t82 = (t82 & t85);
    t86 = (t80 + 4);
    t87 = *((unsigned int *)t80);
    *((unsigned int *)t80) = (t87 | t81);
    t88 = *((unsigned int *)t86);
    *((unsigned int *)t86) = (t88 | t82);
    xsi_driver_vfirst_trans(t76, 0, 0);
    t89 = (t0 + 43664);
    *((int *)t89) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t17 = (t0 + 21112U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t17) != 0)
        goto LAB13;

LAB14:    t27 = *((unsigned int *)t5);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t5 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t19) = 1;
    goto LAB14;

LAB13:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB14;

LAB15:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t5 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t5);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB17;

LAB18:    *((unsigned int *)t4) = 1;
    goto LAB21;

LAB20:    t64 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB21;

LAB22:    t69 = (t0 + 17272U);
    t70 = *((char **)t69);
    memcpy(t71, t70, 8);
    goto LAB23;

LAB24:    t69 = ((char*)((ng16)));
    goto LAB25;

LAB26:    xsi_vlog_unsigned_bit_combine(t3, 32, t71, 32, t69, 32);
    goto LAB30;

LAB28:    memcpy(t3, t71, 8);
    goto LAB30;

}

static void Cont_849_6(char *t0)
{
    char t3[8];
    char t4[8];
    char t5[8];
    char t19[8];
    char t26[8];
    char t71[8];
    char *t1;
    char *t2;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;
    char *t70;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    char *t76;
    char *t77;
    char *t78;
    char *t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    unsigned int t87;
    unsigned int t88;
    char *t89;

LAB0:    t1 = (t0 + 38800U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng16)));
    memset(t5, 0, 8);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t2);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB8;

LAB9:    memcpy(t26, t5, 8);

LAB10:    memset(t4, 0, 8);
    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 & 1U);
    if (t63 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t58) != 0)
        goto LAB20;

LAB21:    t65 = (t4 + 4);
    t66 = *((unsigned int *)t4);
    t67 = *((unsigned int *)t65);
    t68 = (t66 || t67);
    if (t68 > 0)
        goto LAB22;

LAB23:    t72 = *((unsigned int *)t4);
    t73 = (~(t72));
    t74 = *((unsigned int *)t65);
    t75 = (t73 || t74);
    if (t75 > 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t65) > 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t4) > 0)
        goto LAB28;

LAB29:    memcpy(t3, t69, 8);

LAB30:    t76 = (t0 + 44368);
    t77 = (t76 + 56U);
    t78 = *((char **)t77);
    t79 = (t78 + 56U);
    t80 = *((char **)t79);
    memset(t80, 0, 8);
    t81 = 1U;
    t82 = t81;
    t83 = (t3 + 4);
    t84 = *((unsigned int *)t3);
    t81 = (t81 & t84);
    t85 = *((unsigned int *)t83);
    t82 = (t82 & t85);
    t86 = (t80 + 4);
    t87 = *((unsigned int *)t80);
    *((unsigned int *)t80) = (t87 | t81);
    t88 = *((unsigned int *)t86);
    *((unsigned int *)t86) = (t88 | t82);
    xsi_driver_vfirst_trans(t76, 0, 0);
    t89 = (t0 + 43680);
    *((int *)t89) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t17 = (t0 + 21272U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t17) != 0)
        goto LAB13;

LAB14:    t27 = *((unsigned int *)t5);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t5 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t19) = 1;
    goto LAB14;

LAB13:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB14;

LAB15:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t5 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t5);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB17;

LAB18:    *((unsigned int *)t4) = 1;
    goto LAB21;

LAB20:    t64 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB21;

LAB22:    t69 = (t0 + 18552U);
    t70 = *((char **)t69);
    memcpy(t71, t70, 8);
    goto LAB23;

LAB24:    t69 = ((char*)((ng16)));
    goto LAB25;

LAB26:    xsi_vlog_unsigned_bit_combine(t3, 32, t71, 32, t69, 32);
    goto LAB30;

LAB28:    memcpy(t3, t71, 8);
    goto LAB30;

}

static void Cont_850_7(char *t0)
{
    char t3[8];
    char t4[8];
    char t18[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;

LAB0:    t1 = (t0 + 39048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng9)));
    memset(t4, 0, 8);
    t5 = (t2 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t2);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t5) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t19 = *((unsigned int *)t4);
    t20 = (~(t19));
    t21 = *((unsigned int *)t12);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t16, 8);

LAB16:    t23 = (t0 + 44432);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t27, 0, 8);
    t28 = 1U;
    t29 = t28;
    t30 = (t3 + 4);
    t31 = *((unsigned int *)t3);
    t28 = (t28 & t31);
    t32 = *((unsigned int *)t30);
    t29 = (t29 & t32);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t34 | t28);
    t35 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t35 | t29);
    xsi_driver_vfirst_trans(t23, 0, 0);
    t36 = (t0 + 43696);
    *((int *)t36) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 21112U);
    t17 = *((char **)t16);
    memcpy(t18, t17, 8);
    goto LAB9;

LAB10:    t16 = ((char*)((ng16)));
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t18, 32, t16, 32);
    goto LAB16;

LAB14:    memcpy(t3, t18, 8);
    goto LAB16;

}

static void Cont_851_8(char *t0)
{
    char t3[8];
    char t4[8];
    char t18[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;

LAB0:    t1 = (t0 + 39296U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng16)));
    memset(t4, 0, 8);
    t5 = (t2 + 4);
    t6 = *((unsigned int *)t5);
    t7 = (~(t6));
    t8 = *((unsigned int *)t2);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t5) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t19 = *((unsigned int *)t4);
    t20 = (~(t19));
    t21 = *((unsigned int *)t12);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t16, 8);

LAB16:    t23 = (t0 + 44496);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memset(t27, 0, 8);
    t28 = 1U;
    t29 = t28;
    t30 = (t3 + 4);
    t31 = *((unsigned int *)t3);
    t28 = (t28 & t31);
    t32 = *((unsigned int *)t30);
    t29 = (t29 & t32);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t27);
    *((unsigned int *)t27) = (t34 | t28);
    t35 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t35 | t29);
    xsi_driver_vfirst_trans(t23, 0, 0);
    t36 = (t0 + 43712);
    *((int *)t36) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 21272U);
    t17 = *((char **)t16);
    memcpy(t18, t17, 8);
    goto LAB9;

LAB10:    t16 = ((char*)((ng16)));
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 32, t18, 32, t16, 32);
    goto LAB16;

LAB14:    memcpy(t3, t18, 8);
    goto LAB16;

}

static void Cont_855_9(char *t0)
{
    char t4[8];
    char t5[8];
    char t19[8];
    char t26[8];
    char t58[8];
    char t72[8];
    char t73[8];
    char t81[8];
    char t113[8];
    char t128[8];
    char t129[8];
    char t143[8];
    char t150[8];
    char t182[8];
    char t196[8];
    char t197[8];
    char t205[8];
    char t237[8];
    char t245[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    char *t86;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    char *t95;
    char *t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    int t105;
    int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;
    char *t127;
    char *t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;
    char *t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    char *t141;
    char *t142;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    char *t149;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    char *t154;
    char *t155;
    char *t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    char *t164;
    char *t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    int t174;
    int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    char *t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    char *t189;
    char *t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    char *t194;
    char *t195;
    char *t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    char *t204;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    char *t209;
    char *t210;
    char *t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    unsigned int t218;
    char *t219;
    char *t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    int t229;
    int t230;
    unsigned int t231;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    char *t238;
    unsigned int t239;
    unsigned int t240;
    unsigned int t241;
    unsigned int t242;
    unsigned int t243;
    char *t244;
    unsigned int t246;
    unsigned int t247;
    unsigned int t248;
    char *t249;
    char *t250;
    char *t251;
    unsigned int t252;
    unsigned int t253;
    unsigned int t254;
    unsigned int t255;
    unsigned int t256;
    unsigned int t257;
    unsigned int t258;
    char *t259;
    char *t260;
    unsigned int t261;
    unsigned int t262;
    unsigned int t263;
    int t264;
    unsigned int t265;
    unsigned int t266;
    unsigned int t267;
    int t268;
    unsigned int t269;
    unsigned int t270;
    unsigned int t271;
    unsigned int t272;
    char *t273;
    char *t274;
    char *t275;
    char *t276;
    char *t277;
    unsigned int t278;
    unsigned int t279;
    char *t280;
    unsigned int t281;
    unsigned int t282;
    char *t283;
    unsigned int t284;
    unsigned int t285;
    char *t286;

LAB0:    t1 = (t0 + 39544U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 2104);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    xsi_vlog_signed_equal(t4, 32, t3, 32, t2, 32);
    memset(t5, 0, 8);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB8;

LAB9:    memcpy(t26, t5, 8);

LAB10:    memset(t58, 0, 8);
    t59 = (t26 + 4);
    t60 = *((unsigned int *)t59);
    t61 = (~(t60));
    t62 = *((unsigned int *)t26);
    t63 = (t62 & t61);
    t64 = (t63 & 1U);
    if (t64 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t59) != 0)
        goto LAB20;

LAB21:    t66 = (t58 + 4);
    t67 = *((unsigned int *)t58);
    t68 = *((unsigned int *)t66);
    t69 = (t67 || t68);
    if (t69 > 0)
        goto LAB22;

LAB23:    memcpy(t81, t58, 8);

LAB24:    memset(t113, 0, 8);
    t114 = (t81 + 4);
    t115 = *((unsigned int *)t114);
    t116 = (~(t115));
    t117 = *((unsigned int *)t81);
    t118 = (t117 & t116);
    t119 = (t118 & 1U);
    if (t119 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t114) != 0)
        goto LAB34;

LAB35:    t121 = (t113 + 4);
    t122 = *((unsigned int *)t113);
    t123 = (!(t122));
    t124 = *((unsigned int *)t121);
    t125 = (t123 || t124);
    if (t125 > 0)
        goto LAB36;

LAB37:    memcpy(t245, t113, 8);

LAB38:    t273 = (t0 + 44560);
    t274 = (t273 + 56U);
    t275 = *((char **)t274);
    t276 = (t275 + 56U);
    t277 = *((char **)t276);
    memset(t277, 0, 8);
    t278 = 1U;
    t279 = t278;
    t280 = (t245 + 4);
    t281 = *((unsigned int *)t245);
    t278 = (t278 & t281);
    t282 = *((unsigned int *)t280);
    t279 = (t279 & t282);
    t283 = (t277 + 4);
    t284 = *((unsigned int *)t277);
    *((unsigned int *)t277) = (t284 | t278);
    t285 = *((unsigned int *)t283);
    *((unsigned int *)t283) = (t285 | t279);
    xsi_driver_vfirst_trans(t273, 0, 0);
    t286 = (t0 + 43728);
    *((int *)t286) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t17 = (t0 + 16792U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t17) != 0)
        goto LAB13;

LAB14:    t27 = *((unsigned int *)t5);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t5 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t19) = 1;
    goto LAB14;

LAB13:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB14;

LAB15:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t5 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t5);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB17;

LAB18:    *((unsigned int *)t58) = 1;
    goto LAB21;

LAB20:    t65 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t65) = 1;
    goto LAB21;

LAB22:    t70 = (t0 + 11896);
    t71 = *((char **)t70);
    t70 = ((char*)((ng4)));
    memset(t72, 0, 8);
    xsi_vlog_signed_equal(t72, 32, t71, 32, t70, 32);
    memset(t73, 0, 8);
    t74 = (t72 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t72);
    t78 = (t77 & t76);
    t79 = (t78 & 1U);
    if (t79 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t74) != 0)
        goto LAB27;

LAB28:    t82 = *((unsigned int *)t58);
    t83 = *((unsigned int *)t73);
    t84 = (t82 & t83);
    *((unsigned int *)t81) = t84;
    t85 = (t58 + 4);
    t86 = (t73 + 4);
    t87 = (t81 + 4);
    t88 = *((unsigned int *)t85);
    t89 = *((unsigned int *)t86);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t91 = *((unsigned int *)t87);
    t92 = (t91 != 0);
    if (t92 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t73) = 1;
    goto LAB28;

LAB27:    t80 = (t73 + 4);
    *((unsigned int *)t73) = 1;
    *((unsigned int *)t80) = 1;
    goto LAB28;

LAB29:    t93 = *((unsigned int *)t81);
    t94 = *((unsigned int *)t87);
    *((unsigned int *)t81) = (t93 | t94);
    t95 = (t58 + 4);
    t96 = (t73 + 4);
    t97 = *((unsigned int *)t58);
    t98 = (~(t97));
    t99 = *((unsigned int *)t95);
    t100 = (~(t99));
    t101 = *((unsigned int *)t73);
    t102 = (~(t101));
    t103 = *((unsigned int *)t96);
    t104 = (~(t103));
    t105 = (t98 & t100);
    t106 = (t102 & t104);
    t107 = (~(t105));
    t108 = (~(t106));
    t109 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t109 & t107);
    t110 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t110 & t108);
    t111 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t111 & t107);
    t112 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t112 & t108);
    goto LAB31;

LAB32:    *((unsigned int *)t113) = 1;
    goto LAB35;

LAB34:    t120 = (t113 + 4);
    *((unsigned int *)t113) = 1;
    *((unsigned int *)t120) = 1;
    goto LAB35;

LAB36:    t126 = (t0 + 2104);
    t127 = *((char **)t126);
    t126 = ((char*)((ng3)));
    memset(t128, 0, 8);
    xsi_vlog_signed_equal(t128, 32, t127, 32, t126, 32);
    memset(t129, 0, 8);
    t130 = (t128 + 4);
    t131 = *((unsigned int *)t130);
    t132 = (~(t131));
    t133 = *((unsigned int *)t128);
    t134 = (t133 & t132);
    t135 = (t134 & 1U);
    if (t135 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t130) != 0)
        goto LAB41;

LAB42:    t137 = (t129 + 4);
    t138 = *((unsigned int *)t129);
    t139 = *((unsigned int *)t137);
    t140 = (t138 || t139);
    if (t140 > 0)
        goto LAB43;

LAB44:    memcpy(t150, t129, 8);

LAB45:    memset(t182, 0, 8);
    t183 = (t150 + 4);
    t184 = *((unsigned int *)t183);
    t185 = (~(t184));
    t186 = *((unsigned int *)t150);
    t187 = (t186 & t185);
    t188 = (t187 & 1U);
    if (t188 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t183) != 0)
        goto LAB55;

LAB56:    t190 = (t182 + 4);
    t191 = *((unsigned int *)t182);
    t192 = *((unsigned int *)t190);
    t193 = (t191 || t192);
    if (t193 > 0)
        goto LAB57;

LAB58:    memcpy(t205, t182, 8);

LAB59:    memset(t237, 0, 8);
    t238 = (t205 + 4);
    t239 = *((unsigned int *)t238);
    t240 = (~(t239));
    t241 = *((unsigned int *)t205);
    t242 = (t241 & t240);
    t243 = (t242 & 1U);
    if (t243 != 0)
        goto LAB67;

LAB68:    if (*((unsigned int *)t238) != 0)
        goto LAB69;

LAB70:    t246 = *((unsigned int *)t113);
    t247 = *((unsigned int *)t237);
    t248 = (t246 | t247);
    *((unsigned int *)t245) = t248;
    t249 = (t113 + 4);
    t250 = (t237 + 4);
    t251 = (t245 + 4);
    t252 = *((unsigned int *)t249);
    t253 = *((unsigned int *)t250);
    t254 = (t252 | t253);
    *((unsigned int *)t251) = t254;
    t255 = *((unsigned int *)t251);
    t256 = (t255 != 0);
    if (t256 == 1)
        goto LAB71;

LAB72:
LAB73:    goto LAB38;

LAB39:    *((unsigned int *)t129) = 1;
    goto LAB42;

LAB41:    t136 = (t129 + 4);
    *((unsigned int *)t129) = 1;
    *((unsigned int *)t136) = 1;
    goto LAB42;

LAB43:    t141 = (t0 + 16792U);
    t142 = *((char **)t141);
    memset(t143, 0, 8);
    t141 = (t142 + 4);
    t144 = *((unsigned int *)t141);
    t145 = (~(t144));
    t146 = *((unsigned int *)t142);
    t147 = (t146 & t145);
    t148 = (t147 & 1U);
    if (t148 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t141) != 0)
        goto LAB48;

LAB49:    t151 = *((unsigned int *)t129);
    t152 = *((unsigned int *)t143);
    t153 = (t151 & t152);
    *((unsigned int *)t150) = t153;
    t154 = (t129 + 4);
    t155 = (t143 + 4);
    t156 = (t150 + 4);
    t157 = *((unsigned int *)t154);
    t158 = *((unsigned int *)t155);
    t159 = (t157 | t158);
    *((unsigned int *)t156) = t159;
    t160 = *((unsigned int *)t156);
    t161 = (t160 != 0);
    if (t161 == 1)
        goto LAB50;

LAB51:
LAB52:    goto LAB45;

LAB46:    *((unsigned int *)t143) = 1;
    goto LAB49;

LAB48:    t149 = (t143 + 4);
    *((unsigned int *)t143) = 1;
    *((unsigned int *)t149) = 1;
    goto LAB49;

LAB50:    t162 = *((unsigned int *)t150);
    t163 = *((unsigned int *)t156);
    *((unsigned int *)t150) = (t162 | t163);
    t164 = (t129 + 4);
    t165 = (t143 + 4);
    t166 = *((unsigned int *)t129);
    t167 = (~(t166));
    t168 = *((unsigned int *)t164);
    t169 = (~(t168));
    t170 = *((unsigned int *)t143);
    t171 = (~(t170));
    t172 = *((unsigned int *)t165);
    t173 = (~(t172));
    t174 = (t167 & t169);
    t175 = (t171 & t173);
    t176 = (~(t174));
    t177 = (~(t175));
    t178 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t178 & t176);
    t179 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t179 & t177);
    t180 = *((unsigned int *)t150);
    *((unsigned int *)t150) = (t180 & t176);
    t181 = *((unsigned int *)t150);
    *((unsigned int *)t150) = (t181 & t177);
    goto LAB52;

LAB53:    *((unsigned int *)t182) = 1;
    goto LAB56;

LAB55:    t189 = (t182 + 4);
    *((unsigned int *)t182) = 1;
    *((unsigned int *)t189) = 1;
    goto LAB56;

LAB57:    t194 = (t0 + 2376);
    t195 = *((char **)t194);
    t194 = ((char*)((ng3)));
    memset(t196, 0, 8);
    xsi_vlog_signed_equal(t196, 32, t195, 32, t194, 32);
    memset(t197, 0, 8);
    t198 = (t196 + 4);
    t199 = *((unsigned int *)t198);
    t200 = (~(t199));
    t201 = *((unsigned int *)t196);
    t202 = (t201 & t200);
    t203 = (t202 & 1U);
    if (t203 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t198) != 0)
        goto LAB62;

LAB63:    t206 = *((unsigned int *)t182);
    t207 = *((unsigned int *)t197);
    t208 = (t206 & t207);
    *((unsigned int *)t205) = t208;
    t209 = (t182 + 4);
    t210 = (t197 + 4);
    t211 = (t205 + 4);
    t212 = *((unsigned int *)t209);
    t213 = *((unsigned int *)t210);
    t214 = (t212 | t213);
    *((unsigned int *)t211) = t214;
    t215 = *((unsigned int *)t211);
    t216 = (t215 != 0);
    if (t216 == 1)
        goto LAB64;

LAB65:
LAB66:    goto LAB59;

LAB60:    *((unsigned int *)t197) = 1;
    goto LAB63;

LAB62:    t204 = (t197 + 4);
    *((unsigned int *)t197) = 1;
    *((unsigned int *)t204) = 1;
    goto LAB63;

LAB64:    t217 = *((unsigned int *)t205);
    t218 = *((unsigned int *)t211);
    *((unsigned int *)t205) = (t217 | t218);
    t219 = (t182 + 4);
    t220 = (t197 + 4);
    t221 = *((unsigned int *)t182);
    t222 = (~(t221));
    t223 = *((unsigned int *)t219);
    t224 = (~(t223));
    t225 = *((unsigned int *)t197);
    t226 = (~(t225));
    t227 = *((unsigned int *)t220);
    t228 = (~(t227));
    t229 = (t222 & t224);
    t230 = (t226 & t228);
    t231 = (~(t229));
    t232 = (~(t230));
    t233 = *((unsigned int *)t211);
    *((unsigned int *)t211) = (t233 & t231);
    t234 = *((unsigned int *)t211);
    *((unsigned int *)t211) = (t234 & t232);
    t235 = *((unsigned int *)t205);
    *((unsigned int *)t205) = (t235 & t231);
    t236 = *((unsigned int *)t205);
    *((unsigned int *)t205) = (t236 & t232);
    goto LAB66;

LAB67:    *((unsigned int *)t237) = 1;
    goto LAB70;

LAB69:    t244 = (t237 + 4);
    *((unsigned int *)t237) = 1;
    *((unsigned int *)t244) = 1;
    goto LAB70;

LAB71:    t257 = *((unsigned int *)t245);
    t258 = *((unsigned int *)t251);
    *((unsigned int *)t245) = (t257 | t258);
    t259 = (t113 + 4);
    t260 = (t237 + 4);
    t261 = *((unsigned int *)t259);
    t262 = (~(t261));
    t263 = *((unsigned int *)t113);
    t264 = (t263 & t262);
    t265 = *((unsigned int *)t260);
    t266 = (~(t265));
    t267 = *((unsigned int *)t237);
    t268 = (t267 & t266);
    t269 = (~(t264));
    t270 = (~(t268));
    t271 = *((unsigned int *)t251);
    *((unsigned int *)t251) = (t271 & t269);
    t272 = *((unsigned int *)t251);
    *((unsigned int *)t251) = (t272 & t270);
    goto LAB73;

}

static void Cont_859_10(char *t0)
{
    char t4[8];
    char t5[8];
    char t19[8];
    char t26[8];
    char t58[8];
    char t72[8];
    char t73[8];
    char t81[8];
    char t113[8];
    char t128[8];
    char t129[8];
    char t143[8];
    char t150[8];
    char t182[8];
    char t196[8];
    char t197[8];
    char t205[8];
    char t237[8];
    char t245[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    char *t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    char *t80;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    char *t85;
    char *t86;
    char *t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    char *t95;
    char *t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    int t105;
    int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    char *t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    char *t120;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    char *t126;
    char *t127;
    char *t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;
    char *t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    char *t141;
    char *t142;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    char *t149;
    unsigned int t151;
    unsigned int t152;
    unsigned int t153;
    char *t154;
    char *t155;
    char *t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    char *t164;
    char *t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    unsigned int t171;
    unsigned int t172;
    unsigned int t173;
    int t174;
    int t175;
    unsigned int t176;
    unsigned int t177;
    unsigned int t178;
    unsigned int t179;
    unsigned int t180;
    unsigned int t181;
    char *t183;
    unsigned int t184;
    unsigned int t185;
    unsigned int t186;
    unsigned int t187;
    unsigned int t188;
    char *t189;
    char *t190;
    unsigned int t191;
    unsigned int t192;
    unsigned int t193;
    char *t194;
    char *t195;
    char *t198;
    unsigned int t199;
    unsigned int t200;
    unsigned int t201;
    unsigned int t202;
    unsigned int t203;
    char *t204;
    unsigned int t206;
    unsigned int t207;
    unsigned int t208;
    char *t209;
    char *t210;
    char *t211;
    unsigned int t212;
    unsigned int t213;
    unsigned int t214;
    unsigned int t215;
    unsigned int t216;
    unsigned int t217;
    unsigned int t218;
    char *t219;
    char *t220;
    unsigned int t221;
    unsigned int t222;
    unsigned int t223;
    unsigned int t224;
    unsigned int t225;
    unsigned int t226;
    unsigned int t227;
    unsigned int t228;
    int t229;
    int t230;
    unsigned int t231;
    unsigned int t232;
    unsigned int t233;
    unsigned int t234;
    unsigned int t235;
    unsigned int t236;
    char *t238;
    unsigned int t239;
    unsigned int t240;
    unsigned int t241;
    unsigned int t242;
    unsigned int t243;
    char *t244;
    unsigned int t246;
    unsigned int t247;
    unsigned int t248;
    char *t249;
    char *t250;
    char *t251;
    unsigned int t252;
    unsigned int t253;
    unsigned int t254;
    unsigned int t255;
    unsigned int t256;
    unsigned int t257;
    unsigned int t258;
    char *t259;
    char *t260;
    unsigned int t261;
    unsigned int t262;
    unsigned int t263;
    int t264;
    unsigned int t265;
    unsigned int t266;
    unsigned int t267;
    int t268;
    unsigned int t269;
    unsigned int t270;
    unsigned int t271;
    unsigned int t272;
    char *t273;
    char *t274;
    char *t275;
    char *t276;
    char *t277;
    unsigned int t278;
    unsigned int t279;
    char *t280;
    unsigned int t281;
    unsigned int t282;
    char *t283;
    unsigned int t284;
    unsigned int t285;
    char *t286;

LAB0:    t1 = (t0 + 39792U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 4008);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    xsi_vlog_signed_equal(t4, 32, t3, 32, t2, 32);
    memset(t5, 0, 8);
    t6 = (t4 + 4);
    t7 = *((unsigned int *)t6);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t6) != 0)
        goto LAB6;

LAB7:    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB8;

LAB9:    memcpy(t26, t5, 8);

LAB10:    memset(t58, 0, 8);
    t59 = (t26 + 4);
    t60 = *((unsigned int *)t59);
    t61 = (~(t60));
    t62 = *((unsigned int *)t26);
    t63 = (t62 & t61);
    t64 = (t63 & 1U);
    if (t64 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t59) != 0)
        goto LAB20;

LAB21:    t66 = (t58 + 4);
    t67 = *((unsigned int *)t58);
    t68 = *((unsigned int *)t66);
    t69 = (t67 || t68);
    if (t69 > 0)
        goto LAB22;

LAB23:    memcpy(t81, t58, 8);

LAB24:    memset(t113, 0, 8);
    t114 = (t81 + 4);
    t115 = *((unsigned int *)t114);
    t116 = (~(t115));
    t117 = *((unsigned int *)t81);
    t118 = (t117 & t116);
    t119 = (t118 & 1U);
    if (t119 != 0)
        goto LAB32;

LAB33:    if (*((unsigned int *)t114) != 0)
        goto LAB34;

LAB35:    t121 = (t113 + 4);
    t122 = *((unsigned int *)t113);
    t123 = (!(t122));
    t124 = *((unsigned int *)t121);
    t125 = (t123 || t124);
    if (t125 > 0)
        goto LAB36;

LAB37:    memcpy(t245, t113, 8);

LAB38:    t273 = (t0 + 44624);
    t274 = (t273 + 56U);
    t275 = *((char **)t274);
    t276 = (t275 + 56U);
    t277 = *((char **)t276);
    memset(t277, 0, 8);
    t278 = 1U;
    t279 = t278;
    t280 = (t245 + 4);
    t281 = *((unsigned int *)t245);
    t278 = (t278 & t281);
    t282 = *((unsigned int *)t280);
    t279 = (t279 & t282);
    t283 = (t277 + 4);
    t284 = *((unsigned int *)t277);
    *((unsigned int *)t277) = (t284 | t278);
    t285 = *((unsigned int *)t283);
    *((unsigned int *)t283) = (t285 | t279);
    xsi_driver_vfirst_trans(t273, 0, 0);
    t286 = (t0 + 43744);
    *((int *)t286) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t5) = 1;
    goto LAB7;

LAB6:    t12 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t17 = (t0 + 18072U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t17) != 0)
        goto LAB13;

LAB14:    t27 = *((unsigned int *)t5);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t5 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t19) = 1;
    goto LAB14;

LAB13:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB14;

LAB15:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t5 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t5);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB17;

LAB18:    *((unsigned int *)t58) = 1;
    goto LAB21;

LAB20:    t65 = (t58 + 4);
    *((unsigned int *)t58) = 1;
    *((unsigned int *)t65) = 1;
    goto LAB21;

LAB22:    t70 = (t0 + 12032);
    t71 = *((char **)t70);
    t70 = ((char*)((ng4)));
    memset(t72, 0, 8);
    xsi_vlog_signed_equal(t72, 32, t71, 32, t70, 32);
    memset(t73, 0, 8);
    t74 = (t72 + 4);
    t75 = *((unsigned int *)t74);
    t76 = (~(t75));
    t77 = *((unsigned int *)t72);
    t78 = (t77 & t76);
    t79 = (t78 & 1U);
    if (t79 != 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t74) != 0)
        goto LAB27;

LAB28:    t82 = *((unsigned int *)t58);
    t83 = *((unsigned int *)t73);
    t84 = (t82 & t83);
    *((unsigned int *)t81) = t84;
    t85 = (t58 + 4);
    t86 = (t73 + 4);
    t87 = (t81 + 4);
    t88 = *((unsigned int *)t85);
    t89 = *((unsigned int *)t86);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t91 = *((unsigned int *)t87);
    t92 = (t91 != 0);
    if (t92 == 1)
        goto LAB29;

LAB30:
LAB31:    goto LAB24;

LAB25:    *((unsigned int *)t73) = 1;
    goto LAB28;

LAB27:    t80 = (t73 + 4);
    *((unsigned int *)t73) = 1;
    *((unsigned int *)t80) = 1;
    goto LAB28;

LAB29:    t93 = *((unsigned int *)t81);
    t94 = *((unsigned int *)t87);
    *((unsigned int *)t81) = (t93 | t94);
    t95 = (t58 + 4);
    t96 = (t73 + 4);
    t97 = *((unsigned int *)t58);
    t98 = (~(t97));
    t99 = *((unsigned int *)t95);
    t100 = (~(t99));
    t101 = *((unsigned int *)t73);
    t102 = (~(t101));
    t103 = *((unsigned int *)t96);
    t104 = (~(t103));
    t105 = (t98 & t100);
    t106 = (t102 & t104);
    t107 = (~(t105));
    t108 = (~(t106));
    t109 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t109 & t107);
    t110 = *((unsigned int *)t87);
    *((unsigned int *)t87) = (t110 & t108);
    t111 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t111 & t107);
    t112 = *((unsigned int *)t81);
    *((unsigned int *)t81) = (t112 & t108);
    goto LAB31;

LAB32:    *((unsigned int *)t113) = 1;
    goto LAB35;

LAB34:    t120 = (t113 + 4);
    *((unsigned int *)t113) = 1;
    *((unsigned int *)t120) = 1;
    goto LAB35;

LAB36:    t126 = (t0 + 4008);
    t127 = *((char **)t126);
    t126 = ((char*)((ng3)));
    memset(t128, 0, 8);
    xsi_vlog_signed_equal(t128, 32, t127, 32, t126, 32);
    memset(t129, 0, 8);
    t130 = (t128 + 4);
    t131 = *((unsigned int *)t130);
    t132 = (~(t131));
    t133 = *((unsigned int *)t128);
    t134 = (t133 & t132);
    t135 = (t134 & 1U);
    if (t135 != 0)
        goto LAB39;

LAB40:    if (*((unsigned int *)t130) != 0)
        goto LAB41;

LAB42:    t137 = (t129 + 4);
    t138 = *((unsigned int *)t129);
    t139 = *((unsigned int *)t137);
    t140 = (t138 || t139);
    if (t140 > 0)
        goto LAB43;

LAB44:    memcpy(t150, t129, 8);

LAB45:    memset(t182, 0, 8);
    t183 = (t150 + 4);
    t184 = *((unsigned int *)t183);
    t185 = (~(t184));
    t186 = *((unsigned int *)t150);
    t187 = (t186 & t185);
    t188 = (t187 & 1U);
    if (t188 != 0)
        goto LAB53;

LAB54:    if (*((unsigned int *)t183) != 0)
        goto LAB55;

LAB56:    t190 = (t182 + 4);
    t191 = *((unsigned int *)t182);
    t192 = *((unsigned int *)t190);
    t193 = (t191 || t192);
    if (t193 > 0)
        goto LAB57;

LAB58:    memcpy(t205, t182, 8);

LAB59:    memset(t237, 0, 8);
    t238 = (t205 + 4);
    t239 = *((unsigned int *)t238);
    t240 = (~(t239));
    t241 = *((unsigned int *)t205);
    t242 = (t241 & t240);
    t243 = (t242 & 1U);
    if (t243 != 0)
        goto LAB67;

LAB68:    if (*((unsigned int *)t238) != 0)
        goto LAB69;

LAB70:    t246 = *((unsigned int *)t113);
    t247 = *((unsigned int *)t237);
    t248 = (t246 | t247);
    *((unsigned int *)t245) = t248;
    t249 = (t113 + 4);
    t250 = (t237 + 4);
    t251 = (t245 + 4);
    t252 = *((unsigned int *)t249);
    t253 = *((unsigned int *)t250);
    t254 = (t252 | t253);
    *((unsigned int *)t251) = t254;
    t255 = *((unsigned int *)t251);
    t256 = (t255 != 0);
    if (t256 == 1)
        goto LAB71;

LAB72:
LAB73:    goto LAB38;

LAB39:    *((unsigned int *)t129) = 1;
    goto LAB42;

LAB41:    t136 = (t129 + 4);
    *((unsigned int *)t129) = 1;
    *((unsigned int *)t136) = 1;
    goto LAB42;

LAB43:    t141 = (t0 + 18072U);
    t142 = *((char **)t141);
    memset(t143, 0, 8);
    t141 = (t142 + 4);
    t144 = *((unsigned int *)t141);
    t145 = (~(t144));
    t146 = *((unsigned int *)t142);
    t147 = (t146 & t145);
    t148 = (t147 & 1U);
    if (t148 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t141) != 0)
        goto LAB48;

LAB49:    t151 = *((unsigned int *)t129);
    t152 = *((unsigned int *)t143);
    t153 = (t151 & t152);
    *((unsigned int *)t150) = t153;
    t154 = (t129 + 4);
    t155 = (t143 + 4);
    t156 = (t150 + 4);
    t157 = *((unsigned int *)t154);
    t158 = *((unsigned int *)t155);
    t159 = (t157 | t158);
    *((unsigned int *)t156) = t159;
    t160 = *((unsigned int *)t156);
    t161 = (t160 != 0);
    if (t161 == 1)
        goto LAB50;

LAB51:
LAB52:    goto LAB45;

LAB46:    *((unsigned int *)t143) = 1;
    goto LAB49;

LAB48:    t149 = (t143 + 4);
    *((unsigned int *)t143) = 1;
    *((unsigned int *)t149) = 1;
    goto LAB49;

LAB50:    t162 = *((unsigned int *)t150);
    t163 = *((unsigned int *)t156);
    *((unsigned int *)t150) = (t162 | t163);
    t164 = (t129 + 4);
    t165 = (t143 + 4);
    t166 = *((unsigned int *)t129);
    t167 = (~(t166));
    t168 = *((unsigned int *)t164);
    t169 = (~(t168));
    t170 = *((unsigned int *)t143);
    t171 = (~(t170));
    t172 = *((unsigned int *)t165);
    t173 = (~(t172));
    t174 = (t167 & t169);
    t175 = (t171 & t173);
    t176 = (~(t174));
    t177 = (~(t175));
    t178 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t178 & t176);
    t179 = *((unsigned int *)t156);
    *((unsigned int *)t156) = (t179 & t177);
    t180 = *((unsigned int *)t150);
    *((unsigned int *)t150) = (t180 & t176);
    t181 = *((unsigned int *)t150);
    *((unsigned int *)t150) = (t181 & t177);
    goto LAB52;

LAB53:    *((unsigned int *)t182) = 1;
    goto LAB56;

LAB55:    t189 = (t182 + 4);
    *((unsigned int *)t182) = 1;
    *((unsigned int *)t189) = 1;
    goto LAB56;

LAB57:    t194 = (t0 + 4280);
    t195 = *((char **)t194);
    t194 = ((char*)((ng3)));
    memset(t196, 0, 8);
    xsi_vlog_signed_equal(t196, 32, t195, 32, t194, 32);
    memset(t197, 0, 8);
    t198 = (t196 + 4);
    t199 = *((unsigned int *)t198);
    t200 = (~(t199));
    t201 = *((unsigned int *)t196);
    t202 = (t201 & t200);
    t203 = (t202 & 1U);
    if (t203 != 0)
        goto LAB60;

LAB61:    if (*((unsigned int *)t198) != 0)
        goto LAB62;

LAB63:    t206 = *((unsigned int *)t182);
    t207 = *((unsigned int *)t197);
    t208 = (t206 & t207);
    *((unsigned int *)t205) = t208;
    t209 = (t182 + 4);
    t210 = (t197 + 4);
    t211 = (t205 + 4);
    t212 = *((unsigned int *)t209);
    t213 = *((unsigned int *)t210);
    t214 = (t212 | t213);
    *((unsigned int *)t211) = t214;
    t215 = *((unsigned int *)t211);
    t216 = (t215 != 0);
    if (t216 == 1)
        goto LAB64;

LAB65:
LAB66:    goto LAB59;

LAB60:    *((unsigned int *)t197) = 1;
    goto LAB63;

LAB62:    t204 = (t197 + 4);
    *((unsigned int *)t197) = 1;
    *((unsigned int *)t204) = 1;
    goto LAB63;

LAB64:    t217 = *((unsigned int *)t205);
    t218 = *((unsigned int *)t211);
    *((unsigned int *)t205) = (t217 | t218);
    t219 = (t182 + 4);
    t220 = (t197 + 4);
    t221 = *((unsigned int *)t182);
    t222 = (~(t221));
    t223 = *((unsigned int *)t219);
    t224 = (~(t223));
    t225 = *((unsigned int *)t197);
    t226 = (~(t225));
    t227 = *((unsigned int *)t220);
    t228 = (~(t227));
    t229 = (t222 & t224);
    t230 = (t226 & t228);
    t231 = (~(t229));
    t232 = (~(t230));
    t233 = *((unsigned int *)t211);
    *((unsigned int *)t211) = (t233 & t231);
    t234 = *((unsigned int *)t211);
    *((unsigned int *)t211) = (t234 & t232);
    t235 = *((unsigned int *)t205);
    *((unsigned int *)t205) = (t235 & t231);
    t236 = *((unsigned int *)t205);
    *((unsigned int *)t205) = (t236 & t232);
    goto LAB66;

LAB67:    *((unsigned int *)t237) = 1;
    goto LAB70;

LAB69:    t244 = (t237 + 4);
    *((unsigned int *)t237) = 1;
    *((unsigned int *)t244) = 1;
    goto LAB70;

LAB71:    t257 = *((unsigned int *)t245);
    t258 = *((unsigned int *)t251);
    *((unsigned int *)t245) = (t257 | t258);
    t259 = (t113 + 4);
    t260 = (t237 + 4);
    t261 = *((unsigned int *)t259);
    t262 = (~(t261));
    t263 = *((unsigned int *)t113);
    t264 = (t263 & t262);
    t265 = *((unsigned int *)t260);
    t266 = (~(t265));
    t267 = *((unsigned int *)t237);
    t268 = (t267 & t266);
    t269 = (~(t264));
    t270 = (~(t268));
    t271 = *((unsigned int *)t251);
    *((unsigned int *)t251) = (t271 & t269);
    t272 = *((unsigned int *)t251);
    *((unsigned int *)t251) = (t272 & t270);
    goto LAB73;

}

static void Initial_1428_11(char *t0)
{
    char t18[8];
    char t19[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;

LAB0:    t1 = (t0 + 40040U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:
LAB4:    t2 = (t0 + 39848);
    t3 = (t0 + 15136);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB7:    t5 = (t0 + 39944);
    t6 = *((char **)t5);
    t7 = (t6 + 80U);
    t8 = *((char **)t7);
    t9 = (t8 + 272U);
    t10 = *((char **)t9);
    t11 = (t10 + 0U);
    t12 = *((char **)t11);
    t13 = ((int  (*)(char *, char *))t12)(t0, t6);

LAB9:    if (t13 != 0)
        goto LAB10;

LAB5:    t6 = (t0 + 15136);
    xsi_vlog_subprogram_popinvocation(t6);

LAB6:    t14 = (t0 + 39944);
    t15 = *((char **)t14);
    t14 = (t0 + 15136);
    t16 = (t0 + 39848);
    t17 = 0;
    xsi_delete_subprogram_invocation(t14, t15, t0, t16, t17);
    t2 = (t0 + 27432);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 25832);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    xsi_vlog_bit_copy(t18, 0, t7, 0, 32);
    *((int *)t19) = xsi_vlogfile_sscanf(t4, 256, ng22, 2, t0, (char)118, t18, 32);
    t8 = (t19 + 4);
    *((int *)t8) = 0;
    t9 = (t0 + 25832);
    xsi_vlogvar_assign_value(t9, t18, 0, 0, 32);
    t10 = (t19 + 4);
    t20 = *((unsigned int *)t10);
    t21 = (~(t20));
    t22 = *((unsigned int *)t19);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB11;

LAB12:
LAB15:    t2 = ((char*)((ng4)));
    t3 = (t0 + 25032);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB13:    t2 = (t0 + 27592);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 25992);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    xsi_vlog_bit_copy(t18, 0, t7, 0, 32);
    *((int *)t19) = xsi_vlogfile_sscanf(t4, 256, ng22, 2, t0, (char)118, t18, 32);
    t8 = (t19 + 4);
    *((int *)t8) = 0;
    t9 = (t0 + 25992);
    xsi_vlogvar_assign_value(t9, t18, 0, 0, 32);
    t10 = (t19 + 4);
    t20 = *((unsigned int *)t10);
    t21 = (~(t20));
    t22 = *((unsigned int *)t19);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB16;

LAB17:
LAB20:    t2 = ((char*)((ng4)));
    t3 = (t0 + 25192);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB18:    t2 = ((char*)((ng16)));
    t3 = (t0 + 25352);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 25512);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 25672);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 7);
    t2 = (t0 + 3872);
    t3 = *((char **)t2);
    t2 = (t0 + 9992);
    t4 = *((char **)t2);
    t2 = (t0 + 39848);
    t5 = (t0 + 15568);
    t6 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t7 = (t0 + 33352);
    xsi_vlogvar_assign_value(t7, t4, 0, 0, 32);

LAB21:    t8 = (t0 + 39944);
    t9 = *((char **)t8);
    t10 = (t9 + 80U);
    t11 = *((char **)t10);
    t12 = (t11 + 272U);
    t14 = *((char **)t12);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t13 = ((int  (*)(char *, char *))t16)(t0, t9);
    if (t13 != 0)
        goto LAB23;

LAB22:    t9 = (t0 + 39944);
    t17 = *((char **)t9);
    t9 = (t0 + 33512);
    t25 = (t9 + 56U);
    t26 = *((char **)t25);
    memcpy(t18, t26, 8);
    t27 = (t0 + 15568);
    t28 = (t0 + 39848);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t17, t0, t28, t29);
    memset(t19, 0, 8);
    xsi_vlog_signed_minus(t19, 32, t3, 32, t18, 32);
    t30 = (t0 + 28232);
    xsi_vlogvar_assign_value(t30, t19, 0, 0, 32);
    t2 = (t0 + 3872);
    t3 = *((char **)t2);
    t2 = (t0 + 10128);
    t4 = *((char **)t2);
    t2 = (t0 + 39848);
    t5 = (t0 + 15568);
    t6 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t7 = (t0 + 33352);
    xsi_vlogvar_assign_value(t7, t4, 0, 0, 32);

LAB24:    t8 = (t0 + 39944);
    t9 = *((char **)t8);
    t10 = (t9 + 80U);
    t11 = *((char **)t10);
    t12 = (t11 + 272U);
    t14 = *((char **)t12);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t13 = ((int  (*)(char *, char *))t16)(t0, t9);
    if (t13 != 0)
        goto LAB26;

LAB25:    t9 = (t0 + 39944);
    t17 = *((char **)t9);
    t9 = (t0 + 33512);
    t25 = (t9 + 56U);
    t26 = *((char **)t25);
    memcpy(t18, t26, 8);
    t27 = (t0 + 15568);
    t28 = (t0 + 39848);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t17, t0, t28, t29);
    memset(t19, 0, 8);
    xsi_vlog_signed_minus(t19, 32, t3, 32, t18, 32);
    t30 = (t0 + 28392);
    xsi_vlogvar_assign_value(t30, t19, 0, 0, 32);
    t2 = (t0 + 5776);
    t3 = *((char **)t2);
    t2 = (t0 + 10264);
    t4 = *((char **)t2);
    t2 = (t0 + 39848);
    t5 = (t0 + 15568);
    t6 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t7 = (t0 + 33352);
    xsi_vlogvar_assign_value(t7, t4, 0, 0, 32);

LAB27:    t8 = (t0 + 39944);
    t9 = *((char **)t8);
    t10 = (t9 + 80U);
    t11 = *((char **)t10);
    t12 = (t11 + 272U);
    t14 = *((char **)t12);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t13 = ((int  (*)(char *, char *))t16)(t0, t9);
    if (t13 != 0)
        goto LAB29;

LAB28:    t9 = (t0 + 39944);
    t17 = *((char **)t9);
    t9 = (t0 + 33512);
    t25 = (t9 + 56U);
    t26 = *((char **)t25);
    memcpy(t18, t26, 8);
    t27 = (t0 + 15568);
    t28 = (t0 + 39848);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t17, t0, t28, t29);
    memset(t19, 0, 8);
    xsi_vlog_signed_minus(t19, 32, t3, 32, t18, 32);
    t30 = (t0 + 28552);
    xsi_vlogvar_assign_value(t30, t19, 0, 0, 32);
    t2 = (t0 + 5776);
    t3 = *((char **)t2);
    t2 = (t0 + 10400);
    t4 = *((char **)t2);
    t2 = (t0 + 39848);
    t5 = (t0 + 15568);
    t6 = xsi_create_subprogram_invocation(t2, 0, t0, t5, 0, 0);
    t7 = (t0 + 33352);
    xsi_vlogvar_assign_value(t7, t4, 0, 0, 32);

LAB30:    t8 = (t0 + 39944);
    t9 = *((char **)t8);
    t10 = (t9 + 80U);
    t11 = *((char **)t10);
    t12 = (t11 + 272U);
    t14 = *((char **)t12);
    t15 = (t14 + 0U);
    t16 = *((char **)t15);
    t13 = ((int  (*)(char *, char *))t16)(t0, t9);
    if (t13 != 0)
        goto LAB32;

LAB31:    t9 = (t0 + 39944);
    t17 = *((char **)t9);
    t9 = (t0 + 33512);
    t25 = (t9 + 56U);
    t26 = *((char **)t25);
    memcpy(t18, t26, 8);
    t27 = (t0 + 15568);
    t28 = (t0 + 39848);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t17, t0, t28, t29);
    memset(t19, 0, 8);
    xsi_vlog_signed_minus(t19, 32, t3, 32, t18, 32);
    t30 = (t0 + 28712);
    xsi_vlogvar_assign_value(t30, t19, 0, 0, 32);
    xsi_vlogfile_write(1, 0, 0, ng32, 1, t0);

LAB1:    return;
LAB8:;
LAB10:    t5 = (t0 + 40040U);
    *((char **)t5) = &&LAB7;
    goto LAB1;

LAB11:
LAB14:    t11 = (t0 + 25832);
    t12 = (t11 + 56U);
    t14 = *((char **)t12);
    t15 = (t0 + 25032);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 32);
    goto LAB13;

LAB16:
LAB19:    t11 = (t0 + 25992);
    t12 = (t11 + 56U);
    t14 = *((char **)t12);
    t15 = (t0 + 25192);
    xsi_vlogvar_assign_value(t15, t14, 0, 0, 32);
    goto LAB18;

LAB23:    t8 = (t0 + 40040U);
    *((char **)t8) = &&LAB21;
    goto LAB1;

LAB26:    t8 = (t0 + 40040U);
    *((char **)t8) = &&LAB24;
    goto LAB1;

LAB29:    t8 = (t0 + 40040U);
    *((char **)t8) = &&LAB27;
    goto LAB1;

LAB32:    t8 = (t0 + 40040U);
    *((char **)t8) = &&LAB30;
    goto LAB1;

}

static void Always_1735_12(char *t0)
{
    char t37[16];
    char t38[8];
    char t42[8];
    char t55[8];
    char t61[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;
    char *t98;
    char *t99;
    char *t100;
    int t101;
    char *t102;
    char *t103;
    char *t104;
    char *t105;

LAB0:    t1 = (t0 + 40288U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 43760);
    *((int *)t2) = 1;
    t3 = (t0 + 40320);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 21752U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng11)));
    xsi_vlog_unsigned_equal(t37, 64, t2, 64, t3, 64);
    memset(t38, 0, 8);
    t4 = (t37 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t37);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t4) != 0)
        goto LAB17;

LAB18:    t11 = (t38 + 4);
    t39 = *((unsigned int *)t38);
    t40 = *((unsigned int *)t11);
    t41 = (t39 || t40);
    if (t41 > 0)
        goto LAB19;

LAB20:    memcpy(t61, t38, 8);

LAB21:    t24 = (t61 + 4);
    t87 = *((unsigned int *)t24);
    t88 = (~(t87));
    t89 = *((unsigned int *)t61);
    t90 = (t89 & t88);
    t91 = (t90 != 0);
    if (t91 > 0)
        goto LAB33;

LAB34:
LAB55:    t2 = (t0 + 22072U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB56;

LAB57:
LAB58:
LAB35:    goto LAB2;

LAB6:    t11 = (t0 + 17432U);
    t12 = *((char **)t11);
    t11 = (t0 + 21752U);
    t13 = *((char **)t11);
    t11 = (t0 + 17592U);
    t14 = *((char **)t11);
    t11 = (t0 + 19192U);
    t15 = *((char **)t11);
    t11 = (t0 + 19352U);
    t16 = *((char **)t11);
    t11 = (t0 + 40096);
    t17 = (t0 + 12544);
    t18 = xsi_create_subprogram_invocation(t11, 0, t0, t17, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t17, t18);
    t19 = (t0 + 28872);
    xsi_vlogvar_assign_value(t19, t12, 0, 0, 7);
    t20 = (t0 + 29032);
    xsi_vlogvar_assign_value(t20, t13, 0, 0, 1);
    t21 = (t0 + 29192);
    xsi_vlogvar_assign_value(t21, t14, 0, 0, 32);
    t22 = (t0 + 29352);
    xsi_vlogvar_assign_value(t22, t15, 0, 0, 1);
    t23 = (t0 + 29512);
    xsi_vlogvar_assign_value(t23, t16, 0, 0, 1);

LAB11:    t24 = (t0 + 40192);
    t25 = *((char **)t24);
    t26 = (t25 + 80U);
    t27 = *((char **)t26);
    t28 = (t27 + 272U);
    t29 = *((char **)t28);
    t30 = (t29 + 0U);
    t31 = *((char **)t30);
    t32 = ((int  (*)(char *, char *))t31)(t0, t25);

LAB13:    if (t32 != 0)
        goto LAB14;

LAB9:    t25 = (t0 + 12544);
    xsi_vlog_subprogram_popinvocation(t25);

LAB10:    t33 = (t0 + 40192);
    t34 = *((char **)t33);
    t33 = (t0 + 12544);
    t35 = (t0 + 40096);
    t36 = 0;
    xsi_delete_subprogram_invocation(t33, t34, t0, t35, t36);
    goto LAB8;

LAB12:;
LAB14:    t24 = (t0 + 40288U);
    *((char **)t24) = &&LAB11;
    goto LAB1;

LAB15:    *((unsigned int *)t38) = 1;
    goto LAB18;

LAB17:    t5 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB18;

LAB19:    t12 = ((char*)((ng33)));
    t13 = ((char*)((ng34)));
    memset(t42, 0, 8);
    t14 = (t12 + 4);
    t15 = (t13 + 4);
    t43 = *((unsigned int *)t12);
    t44 = *((unsigned int *)t13);
    t45 = (t43 ^ t44);
    t46 = *((unsigned int *)t14);
    t47 = *((unsigned int *)t15);
    t48 = (t46 ^ t47);
    t49 = (t45 | t48);
    t50 = *((unsigned int *)t14);
    t51 = *((unsigned int *)t15);
    t52 = (t50 | t51);
    t53 = (~(t52));
    t54 = (t49 & t53);
    if (t54 != 0)
        goto LAB25;

LAB22:    if (t52 != 0)
        goto LAB24;

LAB23:    *((unsigned int *)t42) = 1;

LAB25:    memset(t55, 0, 8);
    t17 = (t42 + 4);
    t56 = *((unsigned int *)t17);
    t57 = (~(t56));
    t58 = *((unsigned int *)t42);
    t59 = (t58 & t57);
    t60 = (t59 & 1U);
    if (t60 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t17) != 0)
        goto LAB28;

LAB29:    t62 = *((unsigned int *)t38);
    t63 = *((unsigned int *)t55);
    t64 = (t62 & t63);
    *((unsigned int *)t61) = t64;
    t19 = (t38 + 4);
    t20 = (t55 + 4);
    t21 = (t61 + 4);
    t65 = *((unsigned int *)t19);
    t66 = *((unsigned int *)t20);
    t67 = (t65 | t66);
    *((unsigned int *)t21) = t67;
    t68 = *((unsigned int *)t21);
    t69 = (t68 != 0);
    if (t69 == 1)
        goto LAB30;

LAB31:
LAB32:    goto LAB21;

LAB24:    t16 = (t42 + 4);
    *((unsigned int *)t42) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB25;

LAB26:    *((unsigned int *)t55) = 1;
    goto LAB29;

LAB28:    t18 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB29;

LAB30:    t70 = *((unsigned int *)t61);
    t71 = *((unsigned int *)t21);
    *((unsigned int *)t61) = (t70 | t71);
    t22 = (t38 + 4);
    t23 = (t55 + 4);
    t72 = *((unsigned int *)t38);
    t73 = (~(t72));
    t74 = *((unsigned int *)t22);
    t75 = (~(t74));
    t76 = *((unsigned int *)t55);
    t77 = (~(t76));
    t78 = *((unsigned int *)t23);
    t79 = (~(t78));
    t32 = (t73 & t75);
    t80 = (t77 & t79);
    t81 = (~(t32));
    t82 = (~(t80));
    t83 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t83 & t81);
    t84 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t84 & t82);
    t85 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t85 & t81);
    t86 = *((unsigned int *)t61);
    *((unsigned int *)t61) = (t86 & t82);
    goto LAB32;

LAB33:
LAB36:    t25 = (t0 + 21432U);
    t26 = *((char **)t25);
    t25 = (t26 + 4);
    t92 = *((unsigned int *)t25);
    t93 = (~(t92));
    t94 = *((unsigned int *)t26);
    t95 = (t94 & t93);
    t96 = (t95 != 0);
    if (t96 > 0)
        goto LAB37;

LAB38:    t2 = (t0 + 22072U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB46;

LAB47:
LAB48:
LAB39:    goto LAB35;

LAB37:    t27 = (t0 + 21432U);
    t28 = *((char **)t27);
    t27 = (t0 + 40096);
    t29 = (t0 + 14272);
    t30 = xsi_create_subprogram_invocation(t27, 0, t0, t29, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t29, t30);
    t31 = (t0 + 32392);
    xsi_vlogvar_assign_value(t31, t28, 0, 0, 1);

LAB42:    t33 = (t0 + 40192);
    t34 = *((char **)t33);
    t35 = (t34 + 80U);
    t36 = *((char **)t35);
    t97 = (t36 + 272U);
    t98 = *((char **)t97);
    t99 = (t98 + 0U);
    t100 = *((char **)t99);
    t101 = ((int  (*)(char *, char *))t100)(t0, t34);

LAB44:    if (t101 != 0)
        goto LAB45;

LAB40:    t34 = (t0 + 14272);
    xsi_vlog_subprogram_popinvocation(t34);

LAB41:    t102 = (t0 + 40192);
    t103 = *((char **)t102);
    t102 = (t0 + 14272);
    t104 = (t0 + 40096);
    t105 = 0;
    xsi_delete_subprogram_invocation(t102, t103, t0, t104, t105);
    goto LAB39;

LAB43:;
LAB45:    t33 = (t0 + 40288U);
    *((char **)t33) = &&LAB42;
    goto LAB1;

LAB46:    t4 = (t0 + 17432U);
    t5 = *((char **)t4);
    t4 = (t0 + 21432U);
    t11 = *((char **)t4);
    t4 = (t0 + 40096);
    t12 = (t0 + 13408);
    t13 = xsi_create_subprogram_invocation(t4, 0, t0, t12, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t12, t13);
    t14 = (t0 + 31112);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 7);
    t15 = (t0 + 31272);
    xsi_vlogvar_assign_value(t15, t11, 0, 0, 1);

LAB51:    t16 = (t0 + 40192);
    t17 = *((char **)t16);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t32 = ((int  (*)(char *, char *))t23)(t0, t17);

LAB53:    if (t32 != 0)
        goto LAB54;

LAB49:    t17 = (t0 + 13408);
    xsi_vlog_subprogram_popinvocation(t17);

LAB50:    t24 = (t0 + 40192);
    t25 = *((char **)t24);
    t24 = (t0 + 13408);
    t26 = (t0 + 40096);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    goto LAB48;

LAB52:;
LAB54:    t16 = (t0 + 40288U);
    *((char **)t16) = &&LAB51;
    goto LAB1;

LAB56:    t4 = (t0 + 17432U);
    t5 = *((char **)t4);
    t4 = (t0 + 21432U);
    t11 = *((char **)t4);
    t4 = (t0 + 40096);
    t12 = (t0 + 13408);
    t13 = xsi_create_subprogram_invocation(t4, 0, t0, t12, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t12, t13);
    t14 = (t0 + 31112);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 7);
    t15 = (t0 + 31272);
    xsi_vlogvar_assign_value(t15, t11, 0, 0, 1);

LAB61:    t16 = (t0 + 40192);
    t17 = *((char **)t16);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t32 = ((int  (*)(char *, char *))t23)(t0, t17);

LAB63:    if (t32 != 0)
        goto LAB64;

LAB59:    t17 = (t0 + 13408);
    xsi_vlog_subprogram_popinvocation(t17);

LAB60:    t24 = (t0 + 40192);
    t25 = *((char **)t24);
    t24 = (t0 + 13408);
    t26 = (t0 + 40096);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    goto LAB58;

LAB62:;
LAB64:    t16 = (t0 + 40288U);
    *((char **)t16) = &&LAB61;
    goto LAB1;

}

static void Always_1777_13(char *t0)
{
    char t33[16];
    char t34[8];
    char t38[8];
    char t51[8];
    char t57[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    int t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    char *t93;
    char *t94;
    char *t95;
    char *t96;
    char *t97;
    char *t98;
    char *t99;
    char *t100;
    int t101;
    char *t102;
    char *t103;
    char *t104;
    char *t105;

LAB0:    t1 = (t0 + 40536U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 43776);
    *((int *)t2) = 1;
    t3 = (t0 + 40568);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 21912U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    t2 = ((char*)((ng11)));
    t3 = ((char*)((ng11)));
    xsi_vlog_unsigned_equal(t33, 64, t2, 64, t3, 64);
    memset(t34, 0, 8);
    t4 = (t33 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t33);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t4) != 0)
        goto LAB17;

LAB18:    t11 = (t34 + 4);
    t35 = *((unsigned int *)t34);
    t36 = *((unsigned int *)t11);
    t37 = (t35 || t36);
    if (t37 > 0)
        goto LAB19;

LAB20:    memcpy(t57, t34, 8);

LAB21:    t24 = (t57 + 4);
    t83 = *((unsigned int *)t24);
    t84 = (~(t83));
    t85 = *((unsigned int *)t57);
    t86 = (t85 & t84);
    t87 = (t86 != 0);
    if (t87 > 0)
        goto LAB33;

LAB34:
LAB55:    t2 = (t0 + 22232U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB56;

LAB57:
LAB58:
LAB35:    goto LAB2;

LAB6:    t11 = (t0 + 18712U);
    t12 = *((char **)t11);
    t11 = (t0 + 21912U);
    t13 = *((char **)t11);
    t11 = (t0 + 18872U);
    t14 = *((char **)t11);
    t11 = (t0 + 40344);
    t15 = (t0 + 12976);
    t16 = xsi_create_subprogram_invocation(t11, 0, t0, t15, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t15, t16);
    t17 = (t0 + 30152);
    xsi_vlogvar_assign_value(t17, t12, 0, 0, 7);
    t18 = (t0 + 30312);
    xsi_vlogvar_assign_value(t18, t13, 0, 0, 1);
    t19 = (t0 + 30472);
    xsi_vlogvar_assign_value(t19, t14, 0, 0, 32);

LAB11:    t20 = (t0 + 40440);
    t21 = *((char **)t20);
    t22 = (t21 + 80U);
    t23 = *((char **)t22);
    t24 = (t23 + 272U);
    t25 = *((char **)t24);
    t26 = (t25 + 0U);
    t27 = *((char **)t26);
    t28 = ((int  (*)(char *, char *))t27)(t0, t21);

LAB13:    if (t28 != 0)
        goto LAB14;

LAB9:    t21 = (t0 + 12976);
    xsi_vlog_subprogram_popinvocation(t21);

LAB10:    t29 = (t0 + 40440);
    t30 = *((char **)t29);
    t29 = (t0 + 12976);
    t31 = (t0 + 40344);
    t32 = 0;
    xsi_delete_subprogram_invocation(t29, t30, t0, t31, t32);
    goto LAB8;

LAB12:;
LAB14:    t20 = (t0 + 40536U);
    *((char **)t20) = &&LAB11;
    goto LAB1;

LAB15:    *((unsigned int *)t34) = 1;
    goto LAB18;

LAB17:    t5 = (t34 + 4);
    *((unsigned int *)t34) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB18;

LAB19:    t12 = ((char*)((ng33)));
    t13 = ((char*)((ng34)));
    memset(t38, 0, 8);
    t14 = (t12 + 4);
    t15 = (t13 + 4);
    t39 = *((unsigned int *)t12);
    t40 = *((unsigned int *)t13);
    t41 = (t39 ^ t40);
    t42 = *((unsigned int *)t14);
    t43 = *((unsigned int *)t15);
    t44 = (t42 ^ t43);
    t45 = (t41 | t44);
    t46 = *((unsigned int *)t14);
    t47 = *((unsigned int *)t15);
    t48 = (t46 | t47);
    t49 = (~(t48));
    t50 = (t45 & t49);
    if (t50 != 0)
        goto LAB25;

LAB22:    if (t48 != 0)
        goto LAB24;

LAB23:    *((unsigned int *)t38) = 1;

LAB25:    memset(t51, 0, 8);
    t17 = (t38 + 4);
    t52 = *((unsigned int *)t17);
    t53 = (~(t52));
    t54 = *((unsigned int *)t38);
    t55 = (t54 & t53);
    t56 = (t55 & 1U);
    if (t56 != 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t17) != 0)
        goto LAB28;

LAB29:    t58 = *((unsigned int *)t34);
    t59 = *((unsigned int *)t51);
    t60 = (t58 & t59);
    *((unsigned int *)t57) = t60;
    t19 = (t34 + 4);
    t20 = (t51 + 4);
    t21 = (t57 + 4);
    t61 = *((unsigned int *)t19);
    t62 = *((unsigned int *)t20);
    t63 = (t61 | t62);
    *((unsigned int *)t21) = t63;
    t64 = *((unsigned int *)t21);
    t65 = (t64 != 0);
    if (t65 == 1)
        goto LAB30;

LAB31:
LAB32:    goto LAB21;

LAB24:    t16 = (t38 + 4);
    *((unsigned int *)t38) = 1;
    *((unsigned int *)t16) = 1;
    goto LAB25;

LAB26:    *((unsigned int *)t51) = 1;
    goto LAB29;

LAB28:    t18 = (t51 + 4);
    *((unsigned int *)t51) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB29;

LAB30:    t66 = *((unsigned int *)t57);
    t67 = *((unsigned int *)t21);
    *((unsigned int *)t57) = (t66 | t67);
    t22 = (t34 + 4);
    t23 = (t51 + 4);
    t68 = *((unsigned int *)t34);
    t69 = (~(t68));
    t70 = *((unsigned int *)t22);
    t71 = (~(t70));
    t72 = *((unsigned int *)t51);
    t73 = (~(t72));
    t74 = *((unsigned int *)t23);
    t75 = (~(t74));
    t28 = (t69 & t71);
    t76 = (t73 & t75);
    t77 = (~(t28));
    t78 = (~(t76));
    t79 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t79 & t77);
    t80 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t80 & t78);
    t81 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t81 & t77);
    t82 = *((unsigned int *)t57);
    *((unsigned int *)t57) = (t82 & t78);
    goto LAB32;

LAB33:
LAB36:    t25 = (t0 + 21592U);
    t26 = *((char **)t25);
    t25 = (t26 + 4);
    t88 = *((unsigned int *)t25);
    t89 = (~(t88));
    t90 = *((unsigned int *)t26);
    t91 = (t90 & t89);
    t92 = (t91 != 0);
    if (t92 > 0)
        goto LAB37;

LAB38:    t2 = (t0 + 22232U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t3);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB46;

LAB47:
LAB48:
LAB39:    goto LAB35;

LAB37:    t27 = (t0 + 21592U);
    t29 = *((char **)t27);
    t27 = (t0 + 40344);
    t30 = (t0 + 14704);
    t31 = xsi_create_subprogram_invocation(t27, 0, t0, t30, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t30, t31);
    t32 = (t0 + 32552);
    xsi_vlogvar_assign_value(t32, t29, 0, 0, 1);

LAB42:    t93 = (t0 + 40440);
    t94 = *((char **)t93);
    t95 = (t94 + 80U);
    t96 = *((char **)t95);
    t97 = (t96 + 272U);
    t98 = *((char **)t97);
    t99 = (t98 + 0U);
    t100 = *((char **)t99);
    t101 = ((int  (*)(char *, char *))t100)(t0, t94);

LAB44:    if (t101 != 0)
        goto LAB45;

LAB40:    t94 = (t0 + 14704);
    xsi_vlog_subprogram_popinvocation(t94);

LAB41:    t102 = (t0 + 40440);
    t103 = *((char **)t102);
    t102 = (t0 + 14704);
    t104 = (t0 + 40344);
    t105 = 0;
    xsi_delete_subprogram_invocation(t102, t103, t0, t104, t105);
    goto LAB39;

LAB43:;
LAB45:    t93 = (t0 + 40536U);
    *((char **)t93) = &&LAB42;
    goto LAB1;

LAB46:    t4 = (t0 + 18712U);
    t5 = *((char **)t4);
    t4 = (t0 + 21592U);
    t11 = *((char **)t4);
    t4 = (t0 + 40344);
    t12 = (t0 + 13840);
    t13 = xsi_create_subprogram_invocation(t4, 0, t0, t12, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t12, t13);
    t14 = (t0 + 31752);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 7);
    t15 = (t0 + 31912);
    xsi_vlogvar_assign_value(t15, t11, 0, 0, 1);

LAB51:    t16 = (t0 + 40440);
    t17 = *((char **)t16);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t28 = ((int  (*)(char *, char *))t23)(t0, t17);

LAB53:    if (t28 != 0)
        goto LAB54;

LAB49:    t17 = (t0 + 13840);
    xsi_vlog_subprogram_popinvocation(t17);

LAB50:    t24 = (t0 + 40440);
    t25 = *((char **)t24);
    t24 = (t0 + 13840);
    t26 = (t0 + 40344);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    goto LAB48;

LAB52:;
LAB54:    t16 = (t0 + 40536U);
    *((char **)t16) = &&LAB51;
    goto LAB1;

LAB56:    t4 = (t0 + 18712U);
    t5 = *((char **)t4);
    t4 = (t0 + 21592U);
    t11 = *((char **)t4);
    t4 = (t0 + 40344);
    t12 = (t0 + 13840);
    t13 = xsi_create_subprogram_invocation(t4, 0, t0, t12, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t12, t13);
    t14 = (t0 + 31752);
    xsi_vlogvar_assign_value(t14, t5, 0, 0, 7);
    t15 = (t0 + 31912);
    xsi_vlogvar_assign_value(t15, t11, 0, 0, 1);

LAB61:    t16 = (t0 + 40440);
    t17 = *((char **)t16);
    t18 = (t17 + 80U);
    t19 = *((char **)t18);
    t20 = (t19 + 272U);
    t21 = *((char **)t20);
    t22 = (t21 + 0U);
    t23 = *((char **)t22);
    t28 = ((int  (*)(char *, char *))t23)(t0, t17);

LAB63:    if (t28 != 0)
        goto LAB64;

LAB59:    t17 = (t0 + 13840);
    xsi_vlog_subprogram_popinvocation(t17);

LAB60:    t24 = (t0 + 40440);
    t25 = *((char **)t24);
    t24 = (t0 + 13840);
    t26 = (t0 + 40344);
    t27 = 0;
    xsi_delete_subprogram_invocation(t24, t25, t0, t26, t27);
    goto LAB58;

LAB62:;
LAB64:    t16 = (t0 + 40536U);
    *((char **)t16) = &&LAB61;
    goto LAB1;

}

static void NetDecl_1948_14(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 40784U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 17432U);
    t3 = *((char **)t2);
    t2 = (t0 + 44688);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 127U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans_delayed(t2, 0, 6U, 2000LL, 0);
    t16 = (t0 + 43792);
    *((int *)t16) = 1;

LAB1:    return;
}

static void NetDecl_1949_15(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 41032U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 21752U);
    t3 = *((char **)t2);
    t2 = (t0 + 44752);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans_delayed(t2, 0, 0U, 2000LL, 0);
    t16 = (t0 + 43808);
    *((int *)t16) = 1;

LAB1:    return;
}

static void NetDecl_1950_16(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 41280U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 21112U);
    t3 = *((char **)t2);
    t2 = (t0 + 44816);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans_delayed(t2, 0, 0U, 2000LL, 0);
    t16 = (t0 + 43824);
    *((int *)t16) = 1;

LAB1:    return;
}

static void NetDecl_1951_17(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 41528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 18712U);
    t3 = *((char **)t2);
    t2 = (t0 + 44880);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 127U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans_delayed(t2, 0, 6U, 2000LL, 0);
    t16 = (t0 + 43840);
    *((int *)t16) = 1;

LAB1:    return;
}

static void NetDecl_1952_18(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 41776U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 21912U);
    t3 = *((char **)t2);
    t2 = (t0 + 44944);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans_delayed(t2, 0, 0U, 2000LL, 0);
    t16 = (t0 + 43856);
    *((int *)t16) = 1;

LAB1:    return;
}

static void NetDecl_1953_19(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 42024U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 21272U);
    t3 = *((char **)t2);
    t2 = (t0 + 45008);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans_delayed(t2, 0, 0U, 2000LL, 0);
    t16 = (t0 + 43872);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Always_1956_20(char *t0)
{
    char t6[8];
    char t19[8];
    char t26[8];
    char t66[8];
    char t80[8];
    char t87[8];
    char t124[8];
    char t127[8];
    char t146[8];
    char t151[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    char *t79;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    char *t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    char *t101;
    char *t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    char *t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    char *t121;
    char *t122;
    char *t123;
    char *t125;
    char *t126;
    char *t128;
    char *t129;
    char *t130;
    char *t131;
    char *t132;
    char *t133;
    char *t134;
    char *t135;
    char *t136;
    char *t137;
    char *t138;
    char *t139;
    char *t140;
    char *t141;
    int t142;
    char *t143;
    char *t144;
    char *t145;
    char *t147;
    char *t148;
    char *t149;
    char *t150;

LAB0:    t1 = (t0 + 42272U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 43888);
    *((int *)t2) = 1;
    t3 = (t0 + 42304);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 21112U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB10;

LAB11:    memcpy(t26, t6, 8);

LAB12:    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB20;

LAB21:
LAB46:    t2 = ((char*)((ng4)));
    t3 = (t0 + 26312);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB22:    t2 = (t0 + 21112U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t2) != 0)
        goto LAB49;

LAB50:    t5 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t5);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB51;

LAB52:    memcpy(t26, t6, 8);

LAB53:    t40 = (t26 + 4);
    t59 = *((unsigned int *)t40);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB61;

LAB62:
LAB87:    t2 = ((char*)((ng4)));
    t3 = (t0 + 26472);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB63:    t2 = (t0 + 26312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB88;

LAB89:    if (*((unsigned int *)t5) != 0)
        goto LAB90;

LAB91:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB92;

LAB93:    memcpy(t26, t6, 8);

LAB94:    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB102;

LAB103:    t2 = (t0 + 26472);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB119;

LAB120:    if (*((unsigned int *)t5) != 0)
        goto LAB121;

LAB122:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB123;

LAB124:    memcpy(t26, t6, 8);

LAB125:    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB133;

LAB134:
LAB135:
LAB104:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t17 = (t0 + 21272U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t17) != 0)
        goto LAB15;

LAB16:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t6 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t19) = 1;
    goto LAB16;

LAB15:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB16;

LAB17:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t6 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB19;

LAB20:
LAB23:    t64 = (t0 + 21752U);
    t65 = *((char **)t64);
    memset(t66, 0, 8);
    t64 = (t65 + 4);
    t67 = *((unsigned int *)t64);
    t68 = (~(t67));
    t69 = *((unsigned int *)t65);
    t70 = (t69 & t68);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t64) != 0)
        goto LAB26;

LAB27:    t73 = (t66 + 4);
    t74 = *((unsigned int *)t66);
    t75 = (!(t74));
    t76 = *((unsigned int *)t73);
    t77 = (t75 || t76);
    if (t77 > 0)
        goto LAB28;

LAB29:    memcpy(t87, t66, 8);

LAB30:    t115 = (t87 + 4);
    t116 = *((unsigned int *)t115);
    t117 = (~(t116));
    t118 = *((unsigned int *)t87);
    t119 = (t118 & t117);
    t120 = (t119 != 0);
    if (t120 > 0)
        goto LAB38;

LAB39:
LAB45:    t2 = ((char*)((ng4)));
    t3 = (t0 + 26312);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB40:    goto LAB22;

LAB24:    *((unsigned int *)t66) = 1;
    goto LAB27;

LAB26:    t72 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB27;

LAB28:    t78 = (t0 + 21912U);
    t79 = *((char **)t78);
    memset(t80, 0, 8);
    t78 = (t79 + 4);
    t81 = *((unsigned int *)t78);
    t82 = (~(t81));
    t83 = *((unsigned int *)t79);
    t84 = (t83 & t82);
    t85 = (t84 & 1U);
    if (t85 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t78) != 0)
        goto LAB33;

LAB34:    t88 = *((unsigned int *)t66);
    t89 = *((unsigned int *)t80);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t91 = (t66 + 4);
    t92 = (t80 + 4);
    t93 = (t87 + 4);
    t94 = *((unsigned int *)t91);
    t95 = *((unsigned int *)t92);
    t96 = (t94 | t95);
    *((unsigned int *)t93) = t96;
    t97 = *((unsigned int *)t93);
    t98 = (t97 != 0);
    if (t98 == 1)
        goto LAB35;

LAB36:
LAB37:    goto LAB30;

LAB31:    *((unsigned int *)t80) = 1;
    goto LAB34;

LAB33:    t86 = (t80 + 4);
    *((unsigned int *)t80) = 1;
    *((unsigned int *)t86) = 1;
    goto LAB34;

LAB35:    t99 = *((unsigned int *)t87);
    t100 = *((unsigned int *)t93);
    *((unsigned int *)t87) = (t99 | t100);
    t101 = (t66 + 4);
    t102 = (t80 + 4);
    t103 = *((unsigned int *)t101);
    t104 = (~(t103));
    t105 = *((unsigned int *)t66);
    t106 = (t105 & t104);
    t107 = *((unsigned int *)t102);
    t108 = (~(t107));
    t109 = *((unsigned int *)t80);
    t110 = (t109 & t108);
    t111 = (~(t106));
    t112 = (~(t110));
    t113 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t113 & t111);
    t114 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t114 & t112);
    goto LAB37;

LAB38:
LAB41:    t121 = (t0 + 17432U);
    t122 = *((char **)t121);
    t121 = (t0 + 21752U);
    t123 = *((char **)t121);
    memcpy(t124, t123, 8);
    t121 = (t0 + 18712U);
    t125 = *((char **)t121);
    t121 = (t0 + 21912U);
    t126 = *((char **)t121);
    memcpy(t127, t126, 8);
    t121 = (t0 + 42080);
    t128 = (t0 + 16000);
    t129 = xsi_create_subprogram_invocation(t121, 0, t0, t128, 0, 0);
    t130 = (t0 + 33992);
    xsi_vlogvar_assign_value(t130, t122, 0, 0, 7);
    t131 = (t0 + 34152);
    xsi_vlogvar_assign_value(t131, t124, 0, 0, 32);
    t132 = (t0 + 34312);
    xsi_vlogvar_assign_value(t132, t125, 0, 0, 7);
    t133 = (t0 + 34472);
    xsi_vlogvar_assign_value(t133, t127, 0, 0, 32);

LAB42:    t134 = (t0 + 42176);
    t135 = *((char **)t134);
    t136 = (t135 + 80U);
    t137 = *((char **)t136);
    t138 = (t137 + 272U);
    t139 = *((char **)t138);
    t140 = (t139 + 0U);
    t141 = *((char **)t140);
    t142 = ((int  (*)(char *, char *))t141)(t0, t135);
    if (t142 != 0)
        goto LAB44;

LAB43:    t135 = (t0 + 42176);
    t143 = *((char **)t135);
    t135 = (t0 + 34632);
    t144 = (t135 + 56U);
    t145 = *((char **)t144);
    memcpy(t146, t145, 8);
    t147 = (t0 + 16000);
    t148 = (t0 + 42080);
    t149 = 0;
    xsi_delete_subprogram_invocation(t147, t143, t0, t148, t149);
    t150 = (t0 + 26312);
    xsi_vlogvar_wait_assign_value(t150, t146, 0, 0, 1, 0LL);
    goto LAB40;

LAB44:    t134 = (t0 + 42272U);
    *((char **)t134) = &&LAB42;
    goto LAB1;

LAB47:    *((unsigned int *)t6) = 1;
    goto LAB50;

LAB49:    t4 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB50;

LAB51:    t12 = (t0 + 23192U);
    t13 = *((char **)t12);
    memset(t19, 0, 8);
    t12 = (t13 + 4);
    t20 = *((unsigned int *)t12);
    t21 = (~(t20));
    t22 = *((unsigned int *)t13);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t12) != 0)
        goto LAB56;

LAB57:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t18 = (t6 + 4);
    t25 = (t19 + 4);
    t30 = (t26 + 4);
    t33 = *((unsigned int *)t18);
    t34 = *((unsigned int *)t25);
    t35 = (t33 | t34);
    *((unsigned int *)t30) = t35;
    t36 = *((unsigned int *)t30);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB58;

LAB59:
LAB60:    goto LAB53;

LAB54:    *((unsigned int *)t19) = 1;
    goto LAB57;

LAB56:    t17 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB57;

LAB58:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t30);
    *((unsigned int *)t26) = (t38 | t39);
    t31 = (t6 + 4);
    t32 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t31);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t32);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t54 & t52);
    t55 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB60;

LAB61:
LAB64:    t41 = (t0 + 21752U);
    t58 = *((char **)t41);
    memset(t66, 0, 8);
    t41 = (t58 + 4);
    t67 = *((unsigned int *)t41);
    t68 = (~(t67));
    t69 = *((unsigned int *)t58);
    t70 = (t69 & t68);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB65;

LAB66:    if (*((unsigned int *)t41) != 0)
        goto LAB67;

LAB68:    t65 = (t66 + 4);
    t74 = *((unsigned int *)t66);
    t75 = (!(t74));
    t76 = *((unsigned int *)t65);
    t77 = (t75 || t76);
    if (t77 > 0)
        goto LAB69;

LAB70:    memcpy(t87, t66, 8);

LAB71:    t101 = (t87 + 4);
    t116 = *((unsigned int *)t101);
    t117 = (~(t116));
    t118 = *((unsigned int *)t87);
    t119 = (t118 & t117);
    t120 = (t119 != 0);
    if (t120 > 0)
        goto LAB79;

LAB80:
LAB86:    t2 = ((char*)((ng4)));
    t3 = (t0 + 26472);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB81:    goto LAB63;

LAB65:    *((unsigned int *)t66) = 1;
    goto LAB68;

LAB67:    t64 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB68;

LAB69:    t72 = (t0 + 23032U);
    t73 = *((char **)t72);
    memset(t80, 0, 8);
    t72 = (t73 + 4);
    t81 = *((unsigned int *)t72);
    t82 = (~(t81));
    t83 = *((unsigned int *)t73);
    t84 = (t83 & t82);
    t85 = (t84 & 1U);
    if (t85 != 0)
        goto LAB72;

LAB73:    if (*((unsigned int *)t72) != 0)
        goto LAB74;

LAB75:    t88 = *((unsigned int *)t66);
    t89 = *((unsigned int *)t80);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t79 = (t66 + 4);
    t86 = (t80 + 4);
    t91 = (t87 + 4);
    t94 = *((unsigned int *)t79);
    t95 = *((unsigned int *)t86);
    t96 = (t94 | t95);
    *((unsigned int *)t91) = t96;
    t97 = *((unsigned int *)t91);
    t98 = (t97 != 0);
    if (t98 == 1)
        goto LAB76;

LAB77:
LAB78:    goto LAB71;

LAB72:    *((unsigned int *)t80) = 1;
    goto LAB75;

LAB74:    t78 = (t80 + 4);
    *((unsigned int *)t80) = 1;
    *((unsigned int *)t78) = 1;
    goto LAB75;

LAB76:    t99 = *((unsigned int *)t87);
    t100 = *((unsigned int *)t91);
    *((unsigned int *)t87) = (t99 | t100);
    t92 = (t66 + 4);
    t93 = (t80 + 4);
    t103 = *((unsigned int *)t92);
    t104 = (~(t103));
    t105 = *((unsigned int *)t66);
    t106 = (t105 & t104);
    t107 = *((unsigned int *)t93);
    t108 = (~(t107));
    t109 = *((unsigned int *)t80);
    t110 = (t109 & t108);
    t111 = (~(t106));
    t112 = (~(t110));
    t113 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t113 & t111);
    t114 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t114 & t112);
    goto LAB78;

LAB79:
LAB82:    t102 = (t0 + 17432U);
    t115 = *((char **)t102);
    t102 = (t0 + 21752U);
    t121 = *((char **)t102);
    memcpy(t124, t121, 8);
    t102 = (t0 + 22872U);
    t122 = *((char **)t102);
    t102 = (t0 + 23032U);
    t123 = *((char **)t102);
    memcpy(t127, t123, 8);
    t102 = (t0 + 42080);
    t125 = (t0 + 16000);
    t126 = xsi_create_subprogram_invocation(t102, 0, t0, t125, 0, 0);
    t128 = (t0 + 33992);
    xsi_vlogvar_assign_value(t128, t115, 0, 0, 7);
    t129 = (t0 + 34152);
    xsi_vlogvar_assign_value(t129, t124, 0, 0, 32);
    t130 = (t0 + 34312);
    xsi_vlogvar_assign_value(t130, t122, 0, 0, 7);
    t131 = (t0 + 34472);
    xsi_vlogvar_assign_value(t131, t127, 0, 0, 32);

LAB83:    t132 = (t0 + 42176);
    t133 = *((char **)t132);
    t134 = (t133 + 80U);
    t135 = *((char **)t134);
    t136 = (t135 + 272U);
    t137 = *((char **)t136);
    t138 = (t137 + 0U);
    t139 = *((char **)t138);
    t142 = ((int  (*)(char *, char *))t139)(t0, t133);
    if (t142 != 0)
        goto LAB85;

LAB84:    t133 = (t0 + 42176);
    t140 = *((char **)t133);
    t133 = (t0 + 34632);
    t141 = (t133 + 56U);
    t143 = *((char **)t141);
    memcpy(t146, t143, 8);
    t144 = (t0 + 16000);
    t145 = (t0 + 42080);
    t147 = 0;
    xsi_delete_subprogram_invocation(t144, t140, t0, t145, t147);
    t148 = (t0 + 26472);
    xsi_vlogvar_wait_assign_value(t148, t146, 0, 0, 1, 0LL);
    goto LAB81;

LAB85:    t132 = (t0 + 42272U);
    *((char **)t132) = &&LAB83;
    goto LAB1;

LAB88:    *((unsigned int *)t6) = 1;
    goto LAB91;

LAB90:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB91;

LAB92:    t17 = (t0 + 21912U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB95;

LAB96:    if (*((unsigned int *)t17) != 0)
        goto LAB97;

LAB98:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t6 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB99;

LAB100:
LAB101:    goto LAB94;

LAB95:    *((unsigned int *)t19) = 1;
    goto LAB98;

LAB97:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB98;

LAB99:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t6 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB101;

LAB102:
LAB105:    t64 = ((char*)((ng0)));
    t65 = ((char*)((ng2)));
    t72 = xsi_vlog_time(t151, 1.0000000000000000, 1.0000000000000000);
    xsi_vlogfile_fwrite(*((unsigned int *)t64), 0, 0, 1, ng35, 3, t0, (char)118, t65, 128, (char)118, t151, 64);
    t2 = ((char*)((ng0)));
    t3 = (t0 + 21752U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t3 = (t4 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB106;

LAB107:    if (*((unsigned int *)t3) != 0)
        goto LAB108;

LAB109:    t12 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t12);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB110;

LAB111:    t20 = *((unsigned int *)t6);
    t21 = (~(t20));
    t22 = *((unsigned int *)t12);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB112;

LAB113:    if (*((unsigned int *)t12) > 0)
        goto LAB114;

LAB115:    if (*((unsigned int *)t6) > 0)
        goto LAB116;

LAB117:    memcpy(t151, t17, 16);

LAB118:    t18 = (t0 + 17432U);
    t25 = *((char **)t18);
    t18 = (t0 + 18712U);
    t30 = *((char **)t18);
    xsi_vlogfile_fwrite(*((unsigned int *)t2), 0, 0, 1, ng36, 4, t0, (char)118, t151, 40, (char)118, t25, 7, (char)118, t30, 7);
    goto LAB104;

LAB106:    *((unsigned int *)t6) = 1;
    goto LAB109;

LAB108:    t5 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB109;

LAB110:    t13 = ((char*)((ng37)));
    goto LAB111;

LAB112:    t17 = ((char*)((ng38)));
    goto LAB113;

LAB114:    xsi_vlog_unsigned_bit_combine(t151, 40, t13, 40, t17, 40);
    goto LAB118;

LAB116:    memcpy(t151, t13, 16);
    goto LAB118;

LAB119:    *((unsigned int *)t6) = 1;
    goto LAB122;

LAB121:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB122;

LAB123:    t17 = (t0 + 23032U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB126;

LAB127:    if (*((unsigned int *)t17) != 0)
        goto LAB128;

LAB129:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t6 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB130;

LAB131:
LAB132:    goto LAB125;

LAB126:    *((unsigned int *)t19) = 1;
    goto LAB129;

LAB128:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB129;

LAB130:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t6 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB132;

LAB133:
LAB136:    t64 = ((char*)((ng0)));
    t65 = ((char*)((ng2)));
    t72 = xsi_vlog_time(t151, 1.0000000000000000, 1.0000000000000000);
    xsi_vlogfile_fwrite(*((unsigned int *)t64), 0, 0, 1, ng35, 3, t0, (char)118, t65, 128, (char)118, t151, 64);
    t2 = ((char*)((ng0)));
    t3 = (t0 + 21752U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t3 = (t4 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB137;

LAB138:    if (*((unsigned int *)t3) != 0)
        goto LAB139;

LAB140:    t12 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t12);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB141;

LAB142:    t20 = *((unsigned int *)t6);
    t21 = (~(t20));
    t22 = *((unsigned int *)t12);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB143;

LAB144:    if (*((unsigned int *)t12) > 0)
        goto LAB145;

LAB146:    if (*((unsigned int *)t6) > 0)
        goto LAB147;

LAB148:    memcpy(t151, t17, 16);

LAB149:    t18 = (t0 + 17432U);
    t25 = *((char **)t18);
    t18 = (t0 + 22872U);
    t30 = *((char **)t18);
    xsi_vlogfile_fwrite(*((unsigned int *)t2), 0, 0, 1, ng36, 4, t0, (char)118, t151, 40, (char)118, t25, 7, (char)118, t30, 7);
    goto LAB135;

LAB137:    *((unsigned int *)t6) = 1;
    goto LAB140;

LAB139:    t5 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t5) = 1;
    goto LAB140;

LAB141:    t13 = ((char*)((ng37)));
    goto LAB142;

LAB143:    t17 = ((char*)((ng38)));
    goto LAB144;

LAB145:    xsi_vlog_unsigned_bit_combine(t151, 40, t13, 40, t17, 40);
    goto LAB149;

LAB147:    memcpy(t151, t13, 16);
    goto LAB149;

}

static void Always_1997_21(char *t0)
{
    char t6[8];
    char t19[8];
    char t26[8];
    char t66[8];
    char t80[8];
    char t87[8];
    char t124[8];
    char t127[8];
    char t146[8];
    char t151[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    char *t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    char *t64;
    char *t65;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t72;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    char *t79;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    unsigned int t85;
    char *t86;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    char *t92;
    char *t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    char *t101;
    char *t102;
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    int t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    char *t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    char *t121;
    char *t122;
    char *t123;
    char *t125;
    char *t126;
    char *t128;
    char *t129;
    char *t130;
    char *t131;
    char *t132;
    char *t133;
    char *t134;
    char *t135;
    char *t136;
    char *t137;
    char *t138;
    char *t139;
    char *t140;
    char *t141;
    int t142;
    char *t143;
    char *t144;
    char *t145;
    char *t147;
    char *t148;
    char *t149;
    char *t150;

LAB0:    t1 = (t0 + 42520U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 43904);
    *((int *)t2) = 1;
    t3 = (t0 + 42552);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:
LAB5:    t4 = (t0 + 21112U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB10;

LAB11:    memcpy(t26, t6, 8);

LAB12:    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB20;

LAB21:
LAB46:    t2 = ((char*)((ng4)));
    t3 = (t0 + 26632);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB22:    t2 = (t0 + 22712U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB47;

LAB48:    if (*((unsigned int *)t2) != 0)
        goto LAB49;

LAB50:    t5 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t5);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB51;

LAB52:    memcpy(t26, t6, 8);

LAB53:    t40 = (t26 + 4);
    t59 = *((unsigned int *)t40);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB61;

LAB62:
LAB87:    t2 = ((char*)((ng4)));
    t3 = (t0 + 26792);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB63:    t2 = (t0 + 26632);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB88;

LAB89:    if (*((unsigned int *)t5) != 0)
        goto LAB90;

LAB91:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB92;

LAB93:    memcpy(t26, t6, 8);

LAB94:    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB102;

LAB103:    t2 = (t0 + 26792);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t7 = *((unsigned int *)t5);
    t8 = (~(t7));
    t9 = *((unsigned int *)t4);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB119;

LAB120:    if (*((unsigned int *)t5) != 0)
        goto LAB121;

LAB122:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB123;

LAB124:    memcpy(t26, t6, 8);

LAB125:    t58 = (t26 + 4);
    t59 = *((unsigned int *)t58);
    t60 = (~(t59));
    t61 = *((unsigned int *)t26);
    t62 = (t61 & t60);
    t63 = (t62 != 0);
    if (t63 > 0)
        goto LAB133;

LAB134:
LAB135:
LAB104:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t17 = (t0 + 21272U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t17) != 0)
        goto LAB15;

LAB16:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t6 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t19) = 1;
    goto LAB16;

LAB15:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB16;

LAB17:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t6 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB19;

LAB20:
LAB23:    t64 = (t0 + 21752U);
    t65 = *((char **)t64);
    memset(t66, 0, 8);
    t64 = (t65 + 4);
    t67 = *((unsigned int *)t64);
    t68 = (~(t67));
    t69 = *((unsigned int *)t65);
    t70 = (t69 & t68);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t64) != 0)
        goto LAB26;

LAB27:    t73 = (t66 + 4);
    t74 = *((unsigned int *)t66);
    t75 = (!(t74));
    t76 = *((unsigned int *)t73);
    t77 = (t75 || t76);
    if (t77 > 0)
        goto LAB28;

LAB29:    memcpy(t87, t66, 8);

LAB30:    t115 = (t87 + 4);
    t116 = *((unsigned int *)t115);
    t117 = (~(t116));
    t118 = *((unsigned int *)t87);
    t119 = (t118 & t117);
    t120 = (t119 != 0);
    if (t120 > 0)
        goto LAB38;

LAB39:
LAB45:    t2 = ((char*)((ng4)));
    t3 = (t0 + 26632);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB40:    goto LAB22;

LAB24:    *((unsigned int *)t66) = 1;
    goto LAB27;

LAB26:    t72 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t72) = 1;
    goto LAB27;

LAB28:    t78 = (t0 + 21912U);
    t79 = *((char **)t78);
    memset(t80, 0, 8);
    t78 = (t79 + 4);
    t81 = *((unsigned int *)t78);
    t82 = (~(t81));
    t83 = *((unsigned int *)t79);
    t84 = (t83 & t82);
    t85 = (t84 & 1U);
    if (t85 != 0)
        goto LAB31;

LAB32:    if (*((unsigned int *)t78) != 0)
        goto LAB33;

LAB34:    t88 = *((unsigned int *)t66);
    t89 = *((unsigned int *)t80);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t91 = (t66 + 4);
    t92 = (t80 + 4);
    t93 = (t87 + 4);
    t94 = *((unsigned int *)t91);
    t95 = *((unsigned int *)t92);
    t96 = (t94 | t95);
    *((unsigned int *)t93) = t96;
    t97 = *((unsigned int *)t93);
    t98 = (t97 != 0);
    if (t98 == 1)
        goto LAB35;

LAB36:
LAB37:    goto LAB30;

LAB31:    *((unsigned int *)t80) = 1;
    goto LAB34;

LAB33:    t86 = (t80 + 4);
    *((unsigned int *)t80) = 1;
    *((unsigned int *)t86) = 1;
    goto LAB34;

LAB35:    t99 = *((unsigned int *)t87);
    t100 = *((unsigned int *)t93);
    *((unsigned int *)t87) = (t99 | t100);
    t101 = (t66 + 4);
    t102 = (t80 + 4);
    t103 = *((unsigned int *)t101);
    t104 = (~(t103));
    t105 = *((unsigned int *)t66);
    t106 = (t105 & t104);
    t107 = *((unsigned int *)t102);
    t108 = (~(t107));
    t109 = *((unsigned int *)t80);
    t110 = (t109 & t108);
    t111 = (~(t106));
    t112 = (~(t110));
    t113 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t113 & t111);
    t114 = *((unsigned int *)t93);
    *((unsigned int *)t93) = (t114 & t112);
    goto LAB37;

LAB38:
LAB41:    t121 = (t0 + 17432U);
    t122 = *((char **)t121);
    t121 = (t0 + 21752U);
    t123 = *((char **)t121);
    memcpy(t124, t123, 8);
    t121 = (t0 + 18712U);
    t125 = *((char **)t121);
    t121 = (t0 + 21912U);
    t126 = *((char **)t121);
    memcpy(t127, t126, 8);
    t121 = (t0 + 42328);
    t128 = (t0 + 16000);
    t129 = xsi_create_subprogram_invocation(t121, 0, t0, t128, 0, 0);
    t130 = (t0 + 33992);
    xsi_vlogvar_assign_value(t130, t122, 0, 0, 7);
    t131 = (t0 + 34152);
    xsi_vlogvar_assign_value(t131, t124, 0, 0, 32);
    t132 = (t0 + 34312);
    xsi_vlogvar_assign_value(t132, t125, 0, 0, 7);
    t133 = (t0 + 34472);
    xsi_vlogvar_assign_value(t133, t127, 0, 0, 32);

LAB42:    t134 = (t0 + 42424);
    t135 = *((char **)t134);
    t136 = (t135 + 80U);
    t137 = *((char **)t136);
    t138 = (t137 + 272U);
    t139 = *((char **)t138);
    t140 = (t139 + 0U);
    t141 = *((char **)t140);
    t142 = ((int  (*)(char *, char *))t141)(t0, t135);
    if (t142 != 0)
        goto LAB44;

LAB43:    t135 = (t0 + 42424);
    t143 = *((char **)t135);
    t135 = (t0 + 34632);
    t144 = (t135 + 56U);
    t145 = *((char **)t144);
    memcpy(t146, t145, 8);
    t147 = (t0 + 16000);
    t148 = (t0 + 42328);
    t149 = 0;
    xsi_delete_subprogram_invocation(t147, t143, t0, t148, t149);
    t150 = (t0 + 26632);
    xsi_vlogvar_wait_assign_value(t150, t146, 0, 0, 1, 0LL);
    goto LAB40;

LAB44:    t134 = (t0 + 42520U);
    *((char **)t134) = &&LAB42;
    goto LAB1;

LAB47:    *((unsigned int *)t6) = 1;
    goto LAB50;

LAB49:    t4 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB50;

LAB51:    t12 = (t0 + 21272U);
    t13 = *((char **)t12);
    memset(t19, 0, 8);
    t12 = (t13 + 4);
    t20 = *((unsigned int *)t12);
    t21 = (~(t20));
    t22 = *((unsigned int *)t13);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB54;

LAB55:    if (*((unsigned int *)t12) != 0)
        goto LAB56;

LAB57:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t18 = (t6 + 4);
    t25 = (t19 + 4);
    t30 = (t26 + 4);
    t33 = *((unsigned int *)t18);
    t34 = *((unsigned int *)t25);
    t35 = (t33 | t34);
    *((unsigned int *)t30) = t35;
    t36 = *((unsigned int *)t30);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB58;

LAB59:
LAB60:    goto LAB53;

LAB54:    *((unsigned int *)t19) = 1;
    goto LAB57;

LAB56:    t17 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t17) = 1;
    goto LAB57;

LAB58:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t30);
    *((unsigned int *)t26) = (t38 | t39);
    t31 = (t6 + 4);
    t32 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t31);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t32);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t54 & t52);
    t55 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB60;

LAB61:
LAB64:    t41 = (t0 + 22552U);
    t58 = *((char **)t41);
    memset(t66, 0, 8);
    t41 = (t58 + 4);
    t67 = *((unsigned int *)t41);
    t68 = (~(t67));
    t69 = *((unsigned int *)t58);
    t70 = (t69 & t68);
    t71 = (t70 & 1U);
    if (t71 != 0)
        goto LAB65;

LAB66:    if (*((unsigned int *)t41) != 0)
        goto LAB67;

LAB68:    t65 = (t66 + 4);
    t74 = *((unsigned int *)t66);
    t75 = (!(t74));
    t76 = *((unsigned int *)t65);
    t77 = (t75 || t76);
    if (t77 > 0)
        goto LAB69;

LAB70:    memcpy(t87, t66, 8);

LAB71:    t101 = (t87 + 4);
    t116 = *((unsigned int *)t101);
    t117 = (~(t116));
    t118 = *((unsigned int *)t87);
    t119 = (t118 & t117);
    t120 = (t119 != 0);
    if (t120 > 0)
        goto LAB79;

LAB80:
LAB86:    t2 = ((char*)((ng4)));
    t3 = (t0 + 26792);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB81:    goto LAB63;

LAB65:    *((unsigned int *)t66) = 1;
    goto LAB68;

LAB67:    t64 = (t66 + 4);
    *((unsigned int *)t66) = 1;
    *((unsigned int *)t64) = 1;
    goto LAB68;

LAB69:    t72 = (t0 + 21912U);
    t73 = *((char **)t72);
    memset(t80, 0, 8);
    t72 = (t73 + 4);
    t81 = *((unsigned int *)t72);
    t82 = (~(t81));
    t83 = *((unsigned int *)t73);
    t84 = (t83 & t82);
    t85 = (t84 & 1U);
    if (t85 != 0)
        goto LAB72;

LAB73:    if (*((unsigned int *)t72) != 0)
        goto LAB74;

LAB75:    t88 = *((unsigned int *)t66);
    t89 = *((unsigned int *)t80);
    t90 = (t88 | t89);
    *((unsigned int *)t87) = t90;
    t79 = (t66 + 4);
    t86 = (t80 + 4);
    t91 = (t87 + 4);
    t94 = *((unsigned int *)t79);
    t95 = *((unsigned int *)t86);
    t96 = (t94 | t95);
    *((unsigned int *)t91) = t96;
    t97 = *((unsigned int *)t91);
    t98 = (t97 != 0);
    if (t98 == 1)
        goto LAB76;

LAB77:
LAB78:    goto LAB71;

LAB72:    *((unsigned int *)t80) = 1;
    goto LAB75;

LAB74:    t78 = (t80 + 4);
    *((unsigned int *)t80) = 1;
    *((unsigned int *)t78) = 1;
    goto LAB75;

LAB76:    t99 = *((unsigned int *)t87);
    t100 = *((unsigned int *)t91);
    *((unsigned int *)t87) = (t99 | t100);
    t92 = (t66 + 4);
    t93 = (t80 + 4);
    t103 = *((unsigned int *)t92);
    t104 = (~(t103));
    t105 = *((unsigned int *)t66);
    t106 = (t105 & t104);
    t107 = *((unsigned int *)t93);
    t108 = (~(t107));
    t109 = *((unsigned int *)t80);
    t110 = (t109 & t108);
    t111 = (~(t106));
    t112 = (~(t110));
    t113 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t113 & t111);
    t114 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t114 & t112);
    goto LAB78;

LAB79:
LAB82:    t102 = (t0 + 22392U);
    t115 = *((char **)t102);
    t102 = (t0 + 22552U);
    t121 = *((char **)t102);
    memcpy(t124, t121, 8);
    t102 = (t0 + 18712U);
    t122 = *((char **)t102);
    t102 = (t0 + 21912U);
    t123 = *((char **)t102);
    memcpy(t127, t123, 8);
    t102 = (t0 + 42328);
    t125 = (t0 + 16000);
    t126 = xsi_create_subprogram_invocation(t102, 0, t0, t125, 0, 0);
    t128 = (t0 + 33992);
    xsi_vlogvar_assign_value(t128, t115, 0, 0, 7);
    t129 = (t0 + 34152);
    xsi_vlogvar_assign_value(t129, t124, 0, 0, 32);
    t130 = (t0 + 34312);
    xsi_vlogvar_assign_value(t130, t122, 0, 0, 7);
    t131 = (t0 + 34472);
    xsi_vlogvar_assign_value(t131, t127, 0, 0, 32);

LAB83:    t132 = (t0 + 42424);
    t133 = *((char **)t132);
    t134 = (t133 + 80U);
    t135 = *((char **)t134);
    t136 = (t135 + 272U);
    t137 = *((char **)t136);
    t138 = (t137 + 0U);
    t139 = *((char **)t138);
    t142 = ((int  (*)(char *, char *))t139)(t0, t133);
    if (t142 != 0)
        goto LAB85;

LAB84:    t133 = (t0 + 42424);
    t140 = *((char **)t133);
    t133 = (t0 + 34632);
    t141 = (t133 + 56U);
    t143 = *((char **)t141);
    memcpy(t146, t143, 8);
    t144 = (t0 + 16000);
    t145 = (t0 + 42328);
    t147 = 0;
    xsi_delete_subprogram_invocation(t144, t140, t0, t145, t147);
    t148 = (t0 + 26792);
    xsi_vlogvar_wait_assign_value(t148, t146, 0, 0, 1, 0LL);
    goto LAB81;

LAB85:    t132 = (t0 + 42520U);
    *((char **)t132) = &&LAB83;
    goto LAB1;

LAB88:    *((unsigned int *)t6) = 1;
    goto LAB91;

LAB90:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB91;

LAB92:    t17 = (t0 + 21752U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB95;

LAB96:    if (*((unsigned int *)t17) != 0)
        goto LAB97;

LAB98:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t6 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB99;

LAB100:
LAB101:    goto LAB94;

LAB95:    *((unsigned int *)t19) = 1;
    goto LAB98;

LAB97:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB98;

LAB99:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t6 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB101;

LAB102:
LAB105:    t64 = ((char*)((ng0)));
    t65 = ((char*)((ng2)));
    t72 = xsi_vlog_time(t151, 1.0000000000000000, 1.0000000000000000);
    xsi_vlogfile_fwrite(*((unsigned int *)t64), 0, 0, 1, ng35, 3, t0, (char)118, t65, 128, (char)118, t151, 64);
    t2 = ((char*)((ng0)));
    t3 = (t0 + 17432U);
    t4 = *((char **)t3);
    t3 = (t0 + 21912U);
    t5 = *((char **)t3);
    memset(t6, 0, 8);
    t3 = (t5 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB106;

LAB107:    if (*((unsigned int *)t3) != 0)
        goto LAB108;

LAB109:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB110;

LAB111:    t20 = *((unsigned int *)t6);
    t21 = (~(t20));
    t22 = *((unsigned int *)t13);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB112;

LAB113:    if (*((unsigned int *)t13) > 0)
        goto LAB114;

LAB115:    if (*((unsigned int *)t6) > 0)
        goto LAB116;

LAB117:    memcpy(t151, t18, 16);

LAB118:    t25 = (t0 + 18712U);
    t30 = *((char **)t25);
    xsi_vlogfile_fwrite(*((unsigned int *)t2), 0, 0, 1, ng39, 4, t0, (char)118, t4, 7, (char)118, t151, 40, (char)118, t30, 7);
    goto LAB104;

LAB106:    *((unsigned int *)t6) = 1;
    goto LAB109;

LAB108:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB109;

LAB110:    t17 = ((char*)((ng37)));
    goto LAB111;

LAB112:    t18 = ((char*)((ng38)));
    goto LAB113;

LAB114:    xsi_vlog_unsigned_bit_combine(t151, 40, t17, 40, t18, 40);
    goto LAB118;

LAB116:    memcpy(t151, t17, 16);
    goto LAB118;

LAB119:    *((unsigned int *)t6) = 1;
    goto LAB122;

LAB121:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB122;

LAB123:    t17 = (t0 + 22552U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t18 + 4);
    t20 = *((unsigned int *)t17);
    t21 = (~(t20));
    t22 = *((unsigned int *)t18);
    t23 = (t22 & t21);
    t24 = (t23 & 1U);
    if (t24 != 0)
        goto LAB126;

LAB127:    if (*((unsigned int *)t17) != 0)
        goto LAB128;

LAB129:    t27 = *((unsigned int *)t6);
    t28 = *((unsigned int *)t19);
    t29 = (t27 & t28);
    *((unsigned int *)t26) = t29;
    t30 = (t6 + 4);
    t31 = (t19 + 4);
    t32 = (t26 + 4);
    t33 = *((unsigned int *)t30);
    t34 = *((unsigned int *)t31);
    t35 = (t33 | t34);
    *((unsigned int *)t32) = t35;
    t36 = *((unsigned int *)t32);
    t37 = (t36 != 0);
    if (t37 == 1)
        goto LAB130;

LAB131:
LAB132:    goto LAB125;

LAB126:    *((unsigned int *)t19) = 1;
    goto LAB129;

LAB128:    t25 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t25) = 1;
    goto LAB129;

LAB130:    t38 = *((unsigned int *)t26);
    t39 = *((unsigned int *)t32);
    *((unsigned int *)t26) = (t38 | t39);
    t40 = (t6 + 4);
    t41 = (t19 + 4);
    t42 = *((unsigned int *)t6);
    t43 = (~(t42));
    t44 = *((unsigned int *)t40);
    t45 = (~(t44));
    t46 = *((unsigned int *)t19);
    t47 = (~(t46));
    t48 = *((unsigned int *)t41);
    t49 = (~(t48));
    t50 = (t43 & t45);
    t51 = (t47 & t49);
    t52 = (~(t50));
    t53 = (~(t51));
    t54 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t54 & t52);
    t55 = *((unsigned int *)t32);
    *((unsigned int *)t32) = (t55 & t53);
    t56 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t56 & t52);
    t57 = *((unsigned int *)t26);
    *((unsigned int *)t26) = (t57 & t53);
    goto LAB132;

LAB133:
LAB136:    t64 = ((char*)((ng0)));
    t65 = ((char*)((ng2)));
    t72 = xsi_vlog_time(t151, 1.0000000000000000, 1.0000000000000000);
    xsi_vlogfile_fwrite(*((unsigned int *)t64), 0, 0, 1, ng35, 3, t0, (char)118, t65, 128, (char)118, t151, 64);
    t2 = ((char*)((ng0)));
    t3 = (t0 + 22392U);
    t4 = *((char **)t3);
    t3 = (t0 + 21912U);
    t5 = *((char **)t3);
    memset(t6, 0, 8);
    t3 = (t5 + 4);
    t7 = *((unsigned int *)t3);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB137;

LAB138:    if (*((unsigned int *)t3) != 0)
        goto LAB139;

LAB140:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB141;

LAB142:    t20 = *((unsigned int *)t6);
    t21 = (~(t20));
    t22 = *((unsigned int *)t13);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB143;

LAB144:    if (*((unsigned int *)t13) > 0)
        goto LAB145;

LAB146:    if (*((unsigned int *)t6) > 0)
        goto LAB147;

LAB148:    memcpy(t151, t18, 16);

LAB149:    t25 = (t0 + 18712U);
    t30 = *((char **)t25);
    xsi_vlogfile_fwrite(*((unsigned int *)t2), 0, 0, 1, ng39, 4, t0, (char)118, t4, 7, (char)118, t151, 40, (char)118, t30, 7);
    goto LAB135;

LAB137:    *((unsigned int *)t6) = 1;
    goto LAB140;

LAB139:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB140;

LAB141:    t17 = ((char*)((ng37)));
    goto LAB142;

LAB143:    t18 = ((char*)((ng38)));
    goto LAB144;

LAB145:    xsi_vlog_unsigned_bit_combine(t151, 40, t17, 40, t18, 40);
    goto LAB149;

LAB147:    memcpy(t151, t17, 16);
    goto LAB149;

}

static void implSig1_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 42768U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng16)));
    t3 = (t0 + 45072);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void implSig2_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 43016U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng16)));
    t3 = (t0 + 45136);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 0);

LAB1:    return;
}

static void implSig3_execute(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 43264U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = ((char*)((ng16)));
    t3 = (t0 + 45200);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 127U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 6);

LAB1:    return;
}


extern void xilinxcorelib_ver_m_00000000000414557669_1431215541_init()
{
	static char *pe[] = {(void *)Cont_840_0,(void *)Cont_841_1,(void *)Cont_842_2,(void *)Cont_846_3,(void *)Cont_847_4,(void *)Cont_848_5,(void *)Cont_849_6,(void *)Cont_850_7,(void *)Cont_851_8,(void *)Cont_855_9,(void *)Cont_859_10,(void *)Initial_1428_11,(void *)Always_1735_12,(void *)Always_1777_13,(void *)NetDecl_1948_14,(void *)NetDecl_1949_15,(void *)NetDecl_1950_16,(void *)NetDecl_1951_17,(void *)NetDecl_1952_18,(void *)NetDecl_1953_19,(void *)Always_1956_20,(void *)Always_1997_21,(void *)implSig1_execute,(void *)implSig2_execute,(void *)implSig3_execute};
	static char *se[] = {(void *)sp_write_a,(void *)sp_write_b,(void *)sp_read_a,(void *)sp_read_b,(void *)sp_reset_a,(void *)sp_reset_b,(void *)sp_init_memory,(void *)sp_log2roundup,(void *)sp_collision_check};
	xsi_register_didat("xilinxcorelib_ver_m_00000000000414557669_1431215541", "isim/test_isim_beh.exe.sim/xilinxcorelib_ver/m_00000000000414557669_1431215541.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
