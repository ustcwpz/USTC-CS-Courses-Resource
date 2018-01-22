                                       

                    Core name: Xilinx LogiCORE IP Block Memory Generator
                    Version: 4.3
                    Release Date: September 21 2010


================================================================================

This document contains the following sections: 

1. Introduction
2. New Features
3. Supported Devices
4. Resolved Issues
5. Known Issues
6. Technical Support
7. Core Release History
8. Legal Disclaimer
 
================================================================================
 
1. INTRODUCTION

For the most recent updates to the IP installation instructions for this core,
please go to:

   http://www.xilinx.com/ipcenter/coregen/ip_update_install_instructions.htm

 
For system requirements:

   http://www.xilinx.com/ipcenter/coregen/ip_update_system_requirements.htm 



This file contains release notes for the Xilinx LogiCORE IP Block Memory 
Generator v4.3 solution. For the latest core updates, see the product page at:
 
  http://www.xilinx.com/products/ipcenter/Block_Memory_Generator.htm


2. NEW FEATURES  

- ISE 12.3 support
- Soft-ECC support for Virtex-6 and Spartan-6 devices

3. SUPPORTED DEVICES

   SPARTAN-3, SPARTAN-3 XA, SPARTAN-3E SPARTAN-3E XA, SPARTAN-3A, SPARTAN-3A XA,
   SPARTAN-3ADSP, SPARTAN-3ADSP XA, SPARTAN-6, SPARTAN-6L, SPARTAN-6 XA
   VIRTEX-4, VIRTEX-5, VIRTEX-6, VIRTEX-6L , QVIRTEX-6
   QVIRTEX-4, QRVIRTEX-4, QVIRTEX-5

4. RESOLVED ISSUES 
   
- Spartan-6 BRAM Memory collision error 
- Version fixed : 4.3
  1. When the user selects SDP - in Virtex-6 devices
      Solution: For SDP configuration, the write_mode is set as Read_First when Common Clock is enabled otherwise the write_mode is set as Write_First
  - CR 564035
  
5. KNOWN ISSUES 
   
   The following are known issues for v4.3 of this core at time of release:

- Virtex-6 BRAM Memory collision error 

  1. When the user selects TDP (write_mode= Read First)
      Impact: User will have to consider collision Issue

- Spartan-6 BRAM Memory collision error
  1. When the user selects TDP (write_mode= Read First)
      Impact: User will have to consider collision Issue

  Note: Refer to UG383, 'Conflict Avoidance' section while using TDP Memory, with 
        Write Mode = Read First in conjunction with asynchronous clocking
 
- Power estimation figures in the datasheet are preliminary.

- Core does not generate for large memories. Depending on the
  machine the ISE CORE Generator software runs on, the maximum size of the memory that
  can be generated will vary.  For example, a Dual Pentium-4 server 
  with 2 GB RAM can generate a memory core of size 1.8 MBits or 230 KBytes
  - CR 415768
  - AR 24034

- Out-of-range address input can cause the core to generate X's on the DOUT bus
  - AR 23744

- When the IP core is generated for Spartan-6 devices, the core should combine 
  two adjacent 9k BRAMs into one 18K BRAM.
  - CR 526429

The most recent information, including known issues, workarounds, and resolutions for 
this version is provided in the IP Release Notes User Guide located at

     www.xilinx.com/support/documentation/user_guides/xtp025.pdf

6. TECHNICAL SUPPORT 

To obtain technical support, create a WebCase at www.xilinx.com/support.
Questions are routed to a team with expertise using this product.  
  
Xilinx provides technical support for use of this product when used
according to the guidelines described in the core documentation, and
cannot guarantee timing, functionality, or support of this product for
designs that do not follow specified guidelines.

7. CORE RELEASE HISTORY 

Date        By            Version      Description
================================================================================
09/21/2010  Xilinx, Inc.  4.3          ISE 12.3 support;
07/23/2010  Xilinx, Inc.  4.2          ISE 12.2 support;
04/19/2010  Xilinx, Inc.  4.1          ISE 12.1 support;
03/09/2010  Xilinx, Inc.  3.3 rev 2    Fix for V6 Memory collision issue 
12/02/2009  Xilinx, Inc.  3.3 rev 1    ISE 11.4 support; Spartan-6 Low Power
                                       Device support; Automotive Spartan 3A
                                       DSP device support
09/16/2009  Xilinx, Inc.  3.3          Revised to v3.3
06/24/2009  Xilinx, Inc.  3.2          Revised to v3.2
04/24/2009  Xilinx, Inc.  3.1          Revised to v3.1
09/19/2008  Xilinx, Inc.  2.8          Revised to v2.8
03/24/2008  Xilinx, Inc.  2.7          10.1 support; Revised to v2.7
10/03/2007  Xilinx, Inc.  2.6          Revised to v2.6
07/2007     Xilinx, Inc.  2.5          Revised to v2.5
04/2007     Xilinx, Inc.  2.4          Revised to v2.4 rev 1
02/2007     Xilinx, Inc.  2.4          Revised to v2.4
11/2006     Xilinx, Inc.  2.3          Revised to v2.3
09/2006     Xilinx, Inc.  2.2          Revised to v2.2
06/2006     Xilinx, Inc.  2.1          Revised to v2.1
01/2006     Xilinx, Inc.  1.1          Initial release
================================================================================

8. Legal Disclaimer

(c) Copyright 2006 - 2010 Xilinx, Inc. All rights reserved.

This file contains confidential and proprietary information
of Xilinx, Inc. and is protected under U.S. and
international copyright and other intellectual property
laws.

DISCLAIMER
This disclaimer is not a license and does not grant any
rights to the materials distributed herewith. Except as
otherwise provided in a valid license issued to you by
Xilinx, and to the maximum extent permitted by applicable
law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
(2) Xilinx shall not be liable (whether in contract or tort,
including negligence, or under any other theory of
liability) for any loss or damage of any kind or nature
related to, arising under or in connection with these
materials, including for any direct, or any indirect,
special, incidental, or consequential loss or damage
(including loss of data, profits, goodwill, or any type of
loss or damage suffered as a result of any action brought
by a third party) even if such damage or loss was
reasonably foreseeable or Xilinx had been advised of the
possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-
safe, or for use in any application requiring fail-safe
performance, such as life-support or safety devices or
systems, Class III medical devices, nuclear facilities,
applications related to the deployment of airbags, or any
other applications that could lead to death, personal
injury, or severe property or environmental damage
(individually and collectively, "Critical
Applications"). Customer assumes the sole risk and
liability of any use of Xilinx products in Critical
Applications, subject only to applicable laws and
regulations governing limitations on product liability.

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
PART OF THIS FILE AT ALL TIMES.

