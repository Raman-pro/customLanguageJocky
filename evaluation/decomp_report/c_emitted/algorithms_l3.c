// JOCKY build 2AA95D66ECF0C36B seed=12345 date=2026-09-03 05:00:02
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <tlhelp32.h>
#include <direct.h>
#elif defined(__APPLE__)
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <libproc.h>
#else
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#endif

static const volatile uint8_t j_enc_0[] = {0x13, 0x12, 0x11, 0x10, 0x17, 0x16, 0x15, 0x14, 0x1B, 0x1A, 0x42, 0x41, 0x40, 0x47, 0x46, 0x45};
static const char* j_dc_0(void) {
    static char j_rb[17];
    for (int j_i = ((0 + 0) ^ (6269 ^ 6269)); j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ 35;
    j_rb[16] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x22, 0x23, 0x20, 0x21, 0x26, 0x27, 0x24, 0x25, 0x2A, 0x2B, 0x73, 0x70, 0x71, 0x76, 0x77, 0x74};
static const char* j_dc_1(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < (0 + 16); j_i++) j_rb[j_i] = j_enc_1[j_i] ^ (8 + 10);
    j_rb[((16 + 0) ^ (1391 ^ 1391))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0xBA, 0xAA};
static const char* j_dc_2(void) {
    static char j_rb[((2 + 1) ^ (8485 ^ 8485))];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_2[j_i] ^ (58 + 142);
    j_rb[((2 + 0) ^ (7387 ^ 7387))] = ((0 + 0) ^ (710 ^ 710));
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x58, 0x4D};
static const char* j_dc_3(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ (38 + 9);
    j_rb[(1 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0xDC, 0x83, 0x81, 0x9C, 0x90};
static const char* j_dc_4(void) {
    static char j_rb[((1 + 5) ^ (7510 ^ 7510))];
    for (int j_i = ((0 + 0) ^ (6065 ^ 6065)); j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ ((14 + 229) ^ (5077 ^ 5077));
    j_rb[(2 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xDB};
static const char* j_dc_5(void) {
    static char j_rb[(0 + 2)];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ (71 + 98);
    j_rb[(0 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x64};
static const char* j_dc_6(void) {
    static char j_rb[2];
    for (int j_i = (0 + 0); j_i < (0 + 1); j_i++) j_rb[j_i] = j_enc_6[j_i] ^ ((109 + 1) ^ (6900 ^ 6900));
    j_rb[((1 + 0) ^ (366 ^ 366))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x8E};
static const char* j_dc_7(void) {
    static char j_rb[(1 + 1)];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_7[j_i] ^ (177 + 75);
    j_rb[((1 + 0) ^ (1874 ^ 1874))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0x5F};
static const char* j_dc_8(void) {
    static char j_rb[((2 + 0) ^ (6385 ^ 6385))];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 96;
    j_rb[((1 + 0) ^ (3337 ^ 3337))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0xDD, 0xD8, 0xC2, 0xC5, 0xD4, 0xDF};
static const char* j_dc_9(void) {
    static char j_rb[7];
    for (int j_i = 0; j_i < (6 + 0); j_i++) j_rb[j_i] = j_enc_9[j_i] ^ 145;
    j_rb[6] = ((0 + 0) ^ (317 ^ 317));
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0x71, 0x67, 0x60, 0x75, 0x76, 0x78, 0x7D, 0x67, 0x7C, 0x71, 0x70};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < (4 + 7); j_i++) j_rb[j_i] = j_enc_10[j_i] ^ (18 + 34);
    j_rb[((2 + 9) ^ (3172 ^ 3172))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0x82, 0x8D, 0x8E, 0x92, 0x84, 0x9E, 0x96, 0x80, 0x88, 0x95};
static const char* j_dc_11(void) {
    static char j_rb[11];
    for (int j_i = 0; j_i < (3 + 7); j_i++) j_rb[j_i] = j_enc_11[j_i] ^ 193;
    j_rb[(1 + 9)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0x36, 0x2B, 0x2F, 0x27, 0x3D, 0x35, 0x23, 0x2B, 0x36};
static const char* j_dc_12(void) {
    static char j_rb[10];
    for (int j_i = (0 + 0); j_i < ((3 + 6) ^ (8315 ^ 8315)); j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 98;
    j_rb[(3 + 6)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x0B, 0x10, 0x0C, 0x01, 0x16};
static const char* j_dc_13(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 68;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x3C, 0x37, 0x26, 0x21, 0x26, 0x33, 0x26, 0x72, 0x7F, 0x33, 0x3C, 0x72, 0x7F, 0x22, 0x72, 0x26, 0x31, 0x22, 0x72, 0x60, 0x6C, 0x7D, 0x36, 0x37, 0x24, 0x7D, 0x3C, 0x27, 0x3E, 0x3E};
static const char* j_dc_14(void) {
    static char j_rb[((6 + 25) ^ (3233 ^ 3233))];
    for (int j_i = 0; j_i < 30; j_i++) j_rb[j_i] = j_enc_14[j_i] ^ 82;
    j_rb[30] = ((0 + 0) ^ (7904 ^ 7904));
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0x92};
static const char* j_dc_15(void) {
    static char j_rb[(1 + 1)];
    for (int j_i = ((0 + 0) ^ (1747 ^ 1747)); j_i < ((0 + 1) ^ (9308 ^ 9308)); j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 224;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x80, 0x97, 0x84};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = ((0 + 0) ^ (6326 ^ 6326)); j_i < ((0 + 3) ^ (2934 ^ 2934)); j_i++) j_rb[j_i] = j_enc_16[j_i] ^ (27 + 217);
    j_rb[(3 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0xE6, 0xB9, 0xBB, 0xA6, 0xAA, 0xE6, 0xA7, 0xAC, 0xBD, 0xE6, 0xBD, 0xAA, 0xB9};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < (8 + 5); j_i++) j_rb[j_i] = j_enc_17[j_i] ^ ((34 + 167) ^ (3723 ^ 3723));
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0x04, 0x5B, 0x59, 0x44, 0x48, 0x04, 0x45, 0x4E, 0x5F, 0x04, 0x5F, 0x48, 0x5B, 0x1D};
static const char* j_dc_18(void) {
    static char j_rb[(10 + 5)];
    for (int j_i = ((0 + 0) ^ (7225 ^ 7225)); j_i < ((9 + 5) ^ (9649 ^ 9649)); j_i++) j_rb[j_i] = j_enc_18[j_i] ^ ((26 + 17) ^ (7380 ^ 7380));
    j_rb[(13 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0xA3, 0xA0, 0xA7, 0xA6, 0xB7};
static const char* j_dc_19(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (2370 ^ 2370)); j_i < 5; j_i++) j_rb[j_i] = j_enc_19[j_i] ^ (24 + 211);
    j_rb[((0 + 5) ^ (3798 ^ 3798))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0x36, 0x35, 0x3D, 0x2B, 0x22};
static const char* j_dc_20(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (5418 ^ 5418)); j_i < 5; j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 126;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x1A, 0x19, 0x11, 0x00, 0x0E};
static const char* j_dc_21(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_21[j_i] ^ (26 + 56);
    j_rb[(5 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0x29, 0x2A, 0x34, 0x3D};
static const char* j_dc_22(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ ((28 + 69) ^ (9400 ^ 9400));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0xF1, 0xE4};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < ((0 + 2) ^ (2786 ^ 2786)); j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 134;
    j_rb[2] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0x9F, 0x99, 0x9E, 0x8E};
static const char* j_dc_24(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (2300 ^ 2300)); j_i < ((3 + 1) ^ (2923 ^ 2923)); j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 235;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0xC9, 0xCE, 0xC3, 0xDC, 0xCA};
static const char* j_dc_25(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = (0 + 0); j_i < ((1 + 4) ^ (9728 ^ 9728)); j_i++) j_rb[j_i] = j_enc_25[j_i] ^ 175;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x64, 0x62, 0x65, 0x75};
static const char* j_dc_26(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((1 + 3) ^ (4582 ^ 4582)); j_i++) j_rb[j_i] = j_enc_26[j_i] ^ ((3 + 13) ^ (7984 ^ 7984));
    j_rb[((3 + 1) ^ (7092 ^ 7092))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0xE5, 0xE2, 0xEF, 0xF0, 0xE6};
static const char* j_dc_27(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (8020 ^ 8020)); j_i < 5; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 131;
    j_rb[(2 + 3)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x80, 0x86, 0x81, 0x91};
static const char* j_dc_28(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = (0 + 0); j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_28[j_i] ^ ((132 + 112) ^ (1637 ^ 1637));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0x03, 0x04, 0x09, 0x16, 0x00};
static const char* j_dc_29(void) {
    static char j_rb[((3 + 3) ^ (8254 ^ 8254))];
    for (int j_i = ((0 + 0) ^ (6387 ^ 6387)); j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_29[j_i] ^ (48 + 53);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0x80, 0x86, 0x81, 0x91};
static const char* j_dc_30(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (6733 ^ 6733)); j_i < 4; j_i++) j_rb[j_i] = j_enc_30[j_i] ^ 244;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0x88, 0x8F, 0x82, 0x9D, 0x8B};
static const char* j_dc_31(void) {
    static char j_rb[((5 + 1) ^ (2674 ^ 2674))];
    for (int j_i = 0; j_i < ((1 + 4) ^ (6256 ^ 6256)); j_i++) j_rb[j_i] = j_enc_31[j_i] ^ (39 + 199);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0x59, 0x5F, 0x58, 0x48};
static const char* j_dc_32(void) {
    static char j_rb[((0 + 5) ^ (7062 ^ 7062))];
    for (int j_i = 0; j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_32[j_i] ^ (37 + 8);
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0xA7, 0xA0, 0xAD, 0xB2, 0xA4};
static const char* j_dc_33(void) {
    static char j_rb[((6 + 0) ^ (4902 ^ 4902))];
    for (int j_i = 0; j_i < ((0 + 5) ^ (3261 ^ 3261)); j_i++) j_rb[j_i] = j_enc_33[j_i] ^ (93 + 100);
    j_rb[((0 + 5) ^ (3801 ^ 3801))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x6E, 0x68, 0x6F, 0x7F};
static const char* j_dc_34(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((4 + 0) ^ (8083 ^ 8083)); j_i++) j_rb[j_i] = j_enc_34[j_i] ^ ((14 + 12) ^ (4399 ^ 4399));
    j_rb[4] = ((0 + 0) ^ (2124 ^ 2124));
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0xE2, 0xE5, 0xE8, 0xF7, 0xE1};
static const char* j_dc_35(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = 0; j_i < ((5 + 0) ^ (5364 ^ 5364)); j_i++) j_rb[j_i] = j_enc_35[j_i] ^ ((120 + 12) ^ (4089 ^ 4089));
    j_rb[((0 + 5) ^ (528 ^ 528))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0xA6, 0xA0, 0xA7, 0xB7};
static const char* j_dc_36(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 210;
    j_rb[((4 + 0) ^ (905 ^ 905))] = ((0 + 0) ^ (7901 ^ 7901));
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0xA2, 0xA5, 0xA8, 0xB7, 0xA1};
static const char* j_dc_37(void) {
    static char j_rb[(3 + 3)];
    for (int j_i = (0 + 0); j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_37[j_i] ^ ((11 + 185) ^ (6716 ^ 6716));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0xBB, 0xBD, 0xBA, 0xAA};
static const char* j_dc_38(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_38[j_i] ^ 207;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x11, 0x16, 0x1B, 0x04, 0x12};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < ((5 + 0) ^ (2354 ^ 2354)); j_i++) j_rb[j_i] = j_enc_39[j_i] ^ 119;
    j_rb[5] = ((0 + 0) ^ (937 ^ 937));
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0xBA, 0xBC, 0xBB, 0xAB};
static const char* j_dc_40(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = (0 + 0); j_i < ((0 + 4) ^ (4736 ^ 4736)); j_i++) j_rb[j_i] = j_enc_40[j_i] ^ ((150 + 56) ^ (7406 ^ 7406));
    j_rb[(2 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0xA2, 0xA5, 0xA8, 0xB7, 0xA1};
static const char* j_dc_41(void) {
    static char j_rb[((2 + 4) ^ (4190 ^ 4190))];
    for (int j_i = (0 + 0); j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_41[j_i] ^ (21 + 175);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0x85, 0x83, 0x84, 0x94};
static const char* j_dc_42(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ (79 + 162);
    j_rb[(3 + 1)] = ((0 + 0) ^ (9438 ^ 9438));
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x4A, 0x4D, 0x40, 0x5F, 0x49};
static const char* j_dc_43(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_43[j_i] ^ (11 + 33);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x42, 0x44, 0x43, 0x53};
static const char* j_dc_44(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_44[j_i] ^ ((47 + 7) ^ (195 ^ 195));
    j_rb[4] = ((0 + 0) ^ (4840 ^ 4840));
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0xA2, 0xA5, 0xA8, 0xB7, 0xA1};
static const char* j_dc_45(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_45[j_i] ^ (33 + 163);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x52, 0x54, 0x53, 0x43};
static const char* j_dc_46(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((1 + 3) ^ (4248 ^ 4248)); j_i++) j_rb[j_i] = j_enc_46[j_i] ^ 38;
    j_rb[(1 + 3)] = ((0 + 0) ^ (1871 ^ 1871));
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x3A, 0x3D, 0x30, 0x2F, 0x39};
static const char* j_dc_47(void) {
    static char j_rb[((3 + 3) ^ (2036 ^ 2036))];
    for (int j_i = ((0 + 0) ^ (9921 ^ 9921)); j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_47[j_i] ^ 92;
    j_rb[((1 + 4) ^ (8120 ^ 8120))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0xF8, 0xFE, 0xF9, 0xE9};
static const char* j_dc_48(void) {
    static char j_rb[((1 + 4) ^ (7576 ^ 7576))];
    for (int j_i = 0; j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_48[j_i] ^ 140;
    j_rb[4] = ((0 + 0) ^ (2377 ^ 2377));
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0x02, 0x05, 0x08, 0x17, 0x01};
static const char* j_dc_49(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_49[j_i] ^ ((72 + 28) ^ (8350 ^ 8350));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0x61, 0x67, 0x60, 0x70};
static const char* j_dc_50(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (7345 ^ 7345)); j_i < ((3 + 1) ^ (9385 ^ 9385)); j_i++) j_rb[j_i] = j_enc_50[j_i] ^ (21 + 0);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0x43, 0x44, 0x49, 0x56, 0x40};
static const char* j_dc_51(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = ((0 + 0) ^ (8784 ^ 8784)); j_i < ((4 + 1) ^ (3748 ^ 3748)); j_i++) j_rb[j_i] = j_enc_51[j_i] ^ ((15 + 22) ^ (3995 ^ 3995));
    j_rb[(4 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0x7E, 0x78, 0x7F, 0x6F};
static const char* j_dc_52(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = (0 + 0); j_i < ((0 + 4) ^ (592 ^ 592)); j_i++) j_rb[j_i] = j_enc_52[j_i] ^ ((9 + 1) ^ (1550 ^ 1550));
    j_rb[((0 + 4) ^ (5524 ^ 5524))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0x90, 0x97, 0x9A, 0x85, 0x93};
static const char* j_dc_53(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < ((1 + 4) ^ (1614 ^ 1614)); j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 246;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0x5F, 0x59, 0x5E, 0x4E};
static const char* j_dc_54(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ 43;
    j_rb[(4 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x3D, 0x3A, 0x37, 0x28, 0x3E};
static const char* j_dc_55(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_55[j_i] ^ (39 + 52);
    j_rb[(2 + 3)] = ((0 + 0) ^ (446 ^ 446));
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0xF2, 0xF4, 0xF3, 0xE3};
static const char* j_dc_56(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_56[j_i] ^ 134;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0x3B, 0x3C, 0x31, 0x2E, 0x38};
static const char* j_dc_57(void) {
    static char j_rb[(3 + 3)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_57[j_i] ^ 93;
    j_rb[((3 + 2) ^ (3471 ^ 3471))] = ((0 + 0) ^ (6608 ^ 6608));
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0x7B, 0x7D, 0x7A, 0x6A};
static const char* j_dc_58(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = ((0 + 0) ^ (9969 ^ 9969)); j_i < ((4 + 0) ^ (562 ^ 562)); j_i++) j_rb[j_i] = j_enc_58[j_i] ^ ((2 + 13) ^ (6425 ^ 6425));
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0xBB, 0xBC, 0xB1, 0xAE, 0xB8};
static const char* j_dc_59(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = ((0 + 0) ^ (4343 ^ 4343)); j_i < 5; j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 221;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0xF9, 0xFF, 0xF8, 0xE8};
static const char* j_dc_60(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_60[j_i] ^ ((86 + 55) ^ (9574 ^ 9574));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_61[] = {0x7C, 0x7B, 0x76, 0x69, 0x7F};
static const char* j_dc_61(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_61[j_i] ^ 26;
    j_rb[5] = ((0 + 0) ^ (3244 ^ 3244));
    return j_rb;
}

static const volatile uint8_t j_enc_62[] = {0xC4, 0xC2, 0xC5, 0xD5};
static const char* j_dc_62(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_62[j_i] ^ 176;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_63[] = {0xBD, 0xBA, 0xB7, 0xA8, 0xBE};
static const char* j_dc_63(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = ((0 + 0) ^ (8724 ^ 8724)); j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_63[j_i] ^ 219;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_64[] = {0xD1, 0xD7, 0xD0, 0xC0};
static const char* j_dc_64(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_64[j_i] ^ 165;
    j_rb[(3 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_65[] = {0x4C, 0x4B, 0x46, 0x59, 0x4F};
static const char* j_dc_65(void) {
    static char j_rb[((1 + 5) ^ (7330 ^ 7330))];
    for (int j_i = 0; j_i < ((5 + 0) ^ (255 ^ 255)); j_i++) j_rb[j_i] = j_enc_65[j_i] ^ 42;
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_66[] = {0xF3, 0xF5, 0xF2, 0xE2};
static const char* j_dc_66(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_66[j_i] ^ 135;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_67[] = {0x1F, 0x18, 0x15, 0x0A, 0x1C};
static const char* j_dc_67(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_67[j_i] ^ ((40 + 81) ^ (1566 ^ 1566));
    j_rb[5] = ((0 + 0) ^ (7843 ^ 7843));
    return j_rb;
}

static const volatile uint8_t j_enc_68[] = {0x87, 0x81, 0x86, 0x96};
static const char* j_dc_68(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((1 + 3) ^ (9048 ^ 9048)); j_i++) j_rb[j_i] = j_enc_68[j_i] ^ (120 + 123);
    j_rb[4] = ((0 + 0) ^ (5652 ^ 5652));
    return j_rb;
}

static const volatile uint8_t j_enc_69[] = {0xC7, 0xC0, 0xCD, 0xD2, 0xC4};
static const char* j_dc_69(void) {
    static char j_rb[((2 + 4) ^ (2815 ^ 2815))];
    for (int j_i = 0; j_i < ((5 + 0) ^ (7308 ^ 7308)); j_i++) j_rb[j_i] = j_enc_69[j_i] ^ 161;
    j_rb[((2 + 3) ^ (9830 ^ 9830))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_70[] = {0x2B, 0x2D, 0x2A, 0x3A};
static const char* j_dc_70(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (5450 ^ 5450)); j_i < 4; j_i++) j_rb[j_i] = j_enc_70[j_i] ^ ((31 + 64) ^ (495 ^ 495));
    j_rb[((3 + 1) ^ (3268 ^ 3268))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_71[] = {0x43, 0x44, 0x49, 0x56, 0x40};
static const char* j_dc_71(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_71[j_i] ^ 37;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_72[] = {0x13, 0x15, 0x12, 0x02};
static const char* j_dc_72(void) {
    static char j_rb[((1 + 4) ^ (6662 ^ 6662))];
    for (int j_i = 0; j_i < ((4 + 0) ^ (875 ^ 875)); j_i++) j_rb[j_i] = j_enc_72[j_i] ^ 103;
    j_rb[((2 + 2) ^ (9004 ^ 9004))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_73[] = {0x04, 0x03, 0x0E, 0x11, 0x07};
static const char* j_dc_73(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = ((0 + 0) ^ (1766 ^ 1766)); j_i < 5; j_i++) j_rb[j_i] = j_enc_73[j_i] ^ 98;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_74[] = {0xC4, 0xC2, 0xC5, 0xD5};
static const char* j_dc_74(void) {
    static char j_rb[((2 + 3) ^ (6087 ^ 6087))];
    for (int j_i = 0; j_i < ((1 + 3) ^ (4303 ^ 4303)); j_i++) j_rb[j_i] = j_enc_74[j_i] ^ 176;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_75[] = {0xD7, 0xD0, 0xDD, 0xC2, 0xD4};
static const char* j_dc_75(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_75[j_i] ^ 177;
    j_rb[(1 + 4)] = ((0 + 0) ^ (5774 ^ 5774));
    return j_rb;
}

static const volatile uint8_t j_enc_76[] = {0xBA, 0xBC, 0xBB, 0xAB};
static const char* j_dc_76(void) {
    static char j_rb[((1 + 4) ^ (8984 ^ 8984))];
    for (int j_i = 0; j_i < ((2 + 2) ^ (5065 ^ 5065)); j_i++) j_rb[j_i] = j_enc_76[j_i] ^ (9 + 197);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_77[] = {0x76, 0x71, 0x7C, 0x63, 0x75};
static const char* j_dc_77(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_77[j_i] ^ (5 + 11);
    j_rb[((2 + 3) ^ (3259 ^ 3259))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_78[] = {0x03, 0x05, 0x02, 0x12};
static const char* j_dc_78(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_78[j_i] ^ 119;
    j_rb[((2 + 2) ^ (2549 ^ 2549))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_79[] = {0xB5, 0xB2, 0xBF, 0xA0, 0xB6};
static const char* j_dc_79(void) {
    static char j_rb[((4 + 2) ^ (7872 ^ 7872))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_79[j_i] ^ ((134 + 77) ^ (4782 ^ 4782));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_80[] = {0x22, 0x24, 0x23, 0x33};
static const char* j_dc_80(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = 0; j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_80[j_i] ^ (44 + 42);
    j_rb[(2 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_81[] = {0x99, 0x9E, 0x93, 0x8C, 0x9A};
static const char* j_dc_81(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_81[j_i] ^ 255;
    j_rb[5] = ((0 + 0) ^ (8902 ^ 8902));
    return j_rb;
}

static const volatile uint8_t j_enc_82[] = {0x19, 0x1F, 0x18, 0x08};
static const char* j_dc_82(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_82[j_i] ^ ((95 + 14) ^ (1154 ^ 1154));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_83[] = {0xB8, 0xBF, 0xB2, 0xAD, 0xBB};
static const char* j_dc_83(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_83[j_i] ^ ((112 + 110) ^ (6545 ^ 6545));
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_84[] = {0x7B, 0x7D, 0x7A, 0x6A};
static const char* j_dc_84(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_84[j_i] ^ 15;
    j_rb[(3 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_85[] = {0xD9, 0xDE, 0xD3, 0xCC, 0xDA};
static const char* j_dc_85(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_85[j_i] ^ 191;
    j_rb[5] = ((0 + 0) ^ (3390 ^ 3390));
    return j_rb;
}

static const volatile uint8_t j_enc_86[] = {0x4E, 0x48, 0x4F, 0x5F};
static const char* j_dc_86(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_86[j_i] ^ 58;
    j_rb[((1 + 3) ^ (5735 ^ 5735))] = ((0 + 0) ^ (9772 ^ 9772));
    return j_rb;
}

static const volatile uint8_t j_enc_87[] = {0xFC, 0xFB, 0xF6, 0xE9, 0xFF};
static const char* j_dc_87(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = (0 + 0); j_i < (4 + 1); j_i++) j_rb[j_i] = j_enc_87[j_i] ^ (103 + 51);
    j_rb[5] = ((0 + 0) ^ (7412 ^ 7412));
    return j_rb;
}

static const volatile uint8_t j_enc_88[] = {0xF5, 0xF3, 0xF4, 0xE4};
static const char* j_dc_88(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (8599 ^ 8599)); j_i < 4; j_i++) j_rb[j_i] = j_enc_88[j_i] ^ ((107 + 22) ^ (9852 ^ 9852));
    j_rb[(1 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_89[] = {0x24, 0x23, 0x2E, 0x31, 0x27};
static const char* j_dc_89(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = ((0 + 0) ^ (2676 ^ 2676)); j_i < 5; j_i++) j_rb[j_i] = j_enc_89[j_i] ^ (38 + 28);
    j_rb[((2 + 3) ^ (748 ^ 748))] = ((0 + 0) ^ (3261 ^ 3261));
    return j_rb;
}

static const volatile uint8_t j_enc_90[] = {0xE5, 0xE3, 0xE4, 0xF4};
static const char* j_dc_90(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_90[j_i] ^ (134 + 11);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_91[] = {0x02, 0x05, 0x08, 0x17, 0x01};
static const char* j_dc_91(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (5976 ^ 5976)); j_i < ((4 + 1) ^ (4684 ^ 4684)); j_i++) j_rb[j_i] = j_enc_91[j_i] ^ ((33 + 67) ^ (1800 ^ 1800));
    j_rb[(4 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_92[] = {0xE7, 0xE1, 0xE6, 0xF6};
static const char* j_dc_92(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = (0 + 0); j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_92[j_i] ^ ((98 + 49) ^ (2260 ^ 2260));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_93[] = {0x7E, 0x79, 0x74, 0x6B, 0x7D};
static const char* j_dc_93(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = ((0 + 0) ^ (1814 ^ 1814)); j_i < 5; j_i++) j_rb[j_i] = j_enc_93[j_i] ^ (17 + 7);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_94[] = {0xDA, 0xDC, 0xDB, 0xCB};
static const char* j_dc_94(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_94[j_i] ^ ((138 + 36) ^ (2968 ^ 2968));
    j_rb[((2 + 2) ^ (5054 ^ 5054))] = ((0 + 0) ^ (3362 ^ 3362));
    return j_rb;
}

static const volatile uint8_t j_enc_95[] = {0x28, 0x2F, 0x22, 0x3D, 0x2B};
static const char* j_dc_95(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = 0; j_i < ((0 + 5) ^ (1876 ^ 1876)); j_i++) j_rb[j_i] = j_enc_95[j_i] ^ (35 + 43);
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_96[] = {0xFB, 0xFD, 0xFA, 0xEA};
static const char* j_dc_96(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (7360 ^ 7360)); j_i < ((1 + 3) ^ (4091 ^ 4091)); j_i++) j_rb[j_i] = j_enc_96[j_i] ^ 143;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_97[] = {0x95, 0x92, 0x9F, 0x80, 0x96};
static const char* j_dc_97(void) {
    static char j_rb[((6 + 0) ^ (7763 ^ 7763))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_97[j_i] ^ 243;
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_98[] = {0x49, 0x4F, 0x48, 0x58};
static const char* j_dc_98(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((4 + 0) ^ (4344 ^ 4344)); j_i++) j_rb[j_i] = j_enc_98[j_i] ^ ((0 + 61) ^ (4306 ^ 4306));
    j_rb[((2 + 2) ^ (8023 ^ 8023))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_99[] = {0xC6, 0xC1, 0xCC, 0xD3, 0xC5};
static const char* j_dc_99(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = 0; j_i < ((5 + 0) ^ (7532 ^ 7532)); j_i++) j_rb[j_i] = j_enc_99[j_i] ^ 160;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_100[] = {0xF2, 0xF4, 0xF3, 0xE3};
static const char* j_dc_100(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (6245 ^ 6245)); j_i < 4; j_i++) j_rb[j_i] = j_enc_100[j_i] ^ 134;
    j_rb[(1 + 3)] = ((0 + 0) ^ (6554 ^ 6554));
    return j_rb;
}

static const volatile uint8_t j_enc_101[] = {0x7B, 0x7C, 0x71, 0x6E, 0x78};
static const char* j_dc_101(void) {
    static char j_rb[((6 + 0) ^ (229 ^ 229))];
    for (int j_i = ((0 + 0) ^ (7846 ^ 7846)); j_i < 5; j_i++) j_rb[j_i] = j_enc_101[j_i] ^ (9 + 20);
    j_rb[5] = ((0 + 0) ^ (7739 ^ 7739));
    return j_rb;
}

static const volatile uint8_t j_enc_102[] = {0x91, 0x97, 0x90, 0x80};
static const char* j_dc_102(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((3 + 1) ^ (8552 ^ 8552)); j_i++) j_rb[j_i] = j_enc_102[j_i] ^ 229;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_103[] = {0xC3, 0xC4, 0xC9, 0xD6, 0xC0};
static const char* j_dc_103(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_103[j_i] ^ ((30 + 135) ^ (8190 ^ 8190));
    j_rb[(3 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_104[] = {0xD1, 0xD7, 0xD0, 0xC0};
static const char* j_dc_104(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_104[j_i] ^ (161 + 4);
    j_rb[(3 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_105[] = {0xA7, 0xA0, 0xAD, 0xB2, 0xA4};
static const char* j_dc_105(void) {
    static char j_rb[((5 + 1) ^ (4154 ^ 4154))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_105[j_i] ^ ((193 + 0) ^ (2429 ^ 2429));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_106[] = {0x8C, 0x8A, 0x8D, 0x9D};
static const char* j_dc_106(void) {
    static char j_rb[((2 + 3) ^ (845 ^ 845))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_106[j_i] ^ 248;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_107[] = {0x9E, 0x99, 0x94, 0x8B, 0x9D};
static const char* j_dc_107(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (6438 ^ 6438)); j_i < 5; j_i++) j_rb[j_i] = j_enc_107[j_i] ^ 248;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_108[] = {0x81, 0x87, 0x80, 0x90};
static const char* j_dc_108(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_108[j_i] ^ (174 + 71);
    j_rb[4] = ((0 + 0) ^ (712 ^ 712));
    return j_rb;
}

static const volatile uint8_t j_enc_109[] = {0x5C, 0x5B, 0x56, 0x49, 0x5F};
static const char* j_dc_109(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = 0; j_i < ((3 + 2) ^ (2943 ^ 2943)); j_i++) j_rb[j_i] = j_enc_109[j_i] ^ (19 + 39);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_110[] = {0x4D, 0x4B, 0x4C, 0x5C};
static const char* j_dc_110(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = ((0 + 0) ^ (3659 ^ 3659)); j_i < ((4 + 0) ^ (358 ^ 358)); j_i++) j_rb[j_i] = j_enc_110[j_i] ^ ((51 + 6) ^ (8843 ^ 8843));
    j_rb[((4 + 0) ^ (253 ^ 253))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_111[] = {0x8F, 0x88, 0x85, 0x9A, 0x8C};
static const char* j_dc_111(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_111[j_i] ^ 233;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_112[] = {0xEF, 0xE9, 0xEE, 0xFE};
static const char* j_dc_112(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (9973 ^ 9973)); j_i < 4; j_i++) j_rb[j_i] = j_enc_112[j_i] ^ 155;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_113[] = {0x48, 0x4F, 0x42, 0x5D, 0x4B};
static const char* j_dc_113(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = ((0 + 0) ^ (1912 ^ 1912)); j_i < ((1 + 4) ^ (1693 ^ 1693)); j_i++) j_rb[j_i] = j_enc_113[j_i] ^ 46;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_114[] = {0x7D, 0x7B, 0x7C, 0x6C};
static const char* j_dc_114(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_114[j_i] ^ 9;
    j_rb[((0 + 4) ^ (2395 ^ 2395))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_115[] = {0x69, 0x6E, 0x63, 0x7C, 0x6A};
static const char* j_dc_115(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_115[j_i] ^ (1 + 14);
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_116[] = {0x80, 0x86, 0x81, 0x91};
static const char* j_dc_116(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((1 + 3) ^ (5515 ^ 5515)); j_i++) j_rb[j_i] = j_enc_116[j_i] ^ (148 + 96);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_117[] = {0x30, 0x37, 0x3A, 0x25, 0x33};
static const char* j_dc_117(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (7735 ^ 7735)); j_i < 5; j_i++) j_rb[j_i] = j_enc_117[j_i] ^ ((20 + 66) ^ (7130 ^ 7130));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_118[] = {0xC1, 0xC7, 0xC0, 0xD0};
static const char* j_dc_118(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_118[j_i] ^ 181;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_119[] = {0xA7, 0xA0, 0xAD, 0xB2, 0xA4};
static const char* j_dc_119(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_119[j_i] ^ (144 + 49);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_120[] = {0x66, 0x60, 0x67, 0x77};
static const char* j_dc_120(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((1 + 3) ^ (222 ^ 222)); j_i++) j_rb[j_i] = j_enc_120[j_i] ^ ((1 + 17) ^ (8694 ^ 8694));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_121[] = {0x69, 0x6E, 0x63, 0x7C, 0x6A};
static const char* j_dc_121(void) {
    static char j_rb[((0 + 6) ^ (512 ^ 512))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_121[j_i] ^ 15;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_122[] = {0x84, 0x82, 0x85, 0x95};
static const char* j_dc_122(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_122[j_i] ^ 240;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_123[] = {0xF6, 0xF1, 0xFC, 0xE3, 0xF5};
static const char* j_dc_123(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_123[j_i] ^ (0 + 144);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_124[] = {0x5E, 0x58, 0x5F, 0x4F};
static const char* j_dc_124(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_124[j_i] ^ 42;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_125[] = {0x90, 0x97, 0x9A, 0x85, 0x93};
static const char* j_dc_125(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_125[j_i] ^ 246;
    j_rb[((1 + 4) ^ (4006 ^ 4006))] = ((0 + 0) ^ (735 ^ 735));
    return j_rb;
}

static const volatile uint8_t j_enc_126[] = {0x7F, 0x79, 0x7E, 0x6E};
static const char* j_dc_126(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_126[j_i] ^ 11;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_127[] = {0xA5, 0xA2, 0xAF, 0xB0, 0xA6};
static const char* j_dc_127(void) {
    static char j_rb[((4 + 2) ^ (1399 ^ 1399))];
    for (int j_i = 0; j_i < ((1 + 4) ^ (5248 ^ 5248)); j_i++) j_rb[j_i] = j_enc_127[j_i] ^ 195;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_128[] = {0x64, 0x62, 0x65, 0x75};
static const char* j_dc_128(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((4 + 0) ^ (1267 ^ 1267)); j_i++) j_rb[j_i] = j_enc_128[j_i] ^ 16;
    j_rb[(0 + 4)] = ((0 + 0) ^ (5953 ^ 5953));
    return j_rb;
}

static const volatile uint8_t j_enc_129[] = {0x59, 0x5E, 0x53, 0x4C, 0x5A};
static const char* j_dc_129(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = 0; j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_129[j_i] ^ (30 + 33);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_130[] = {0x87, 0x81, 0x86, 0x96};
static const char* j_dc_130(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_130[j_i] ^ 243;
    j_rb[4] = ((0 + 0) ^ (8452 ^ 8452));
    return j_rb;
}

static const volatile uint8_t j_enc_131[] = {0x9E, 0x99, 0x94, 0x8B, 0x9D};
static const char* j_dc_131(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((1 + 4) ^ (6203 ^ 6203)); j_i++) j_rb[j_i] = j_enc_131[j_i] ^ 248;
    j_rb[((5 + 0) ^ (4968 ^ 4968))] = ((0 + 0) ^ (454 ^ 454));
    return j_rb;
}

static const volatile uint8_t j_enc_132[] = {0xFD, 0xFB, 0xFC, 0xEC};
static const char* j_dc_132(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = ((0 + 0) ^ (9585 ^ 9585)); j_i < 4; j_i++) j_rb[j_i] = j_enc_132[j_i] ^ 137;
    j_rb[(2 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_133[] = {0x2D, 0x2A, 0x27, 0x38, 0x2E};
static const char* j_dc_133(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_133[j_i] ^ 75;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_134[] = {0xDE, 0xDE, 0xC3, 0x85, 0x8A, 0x81, 0x8C, 0x8D, 0x82, 0x80, 0x80, 0x8A, 0xC3, 0xCB, 0x8A, 0x97, 0x86, 0x91, 0x82, 0x97, 0x8A, 0x95, 0x86, 0xCA, 0xC3, 0xDE, 0xDE};
static const char* j_dc_134(void) {
    static char j_rb[28];
    for (int j_i = 0; j_i < (7 + 20); j_i++) j_rb[j_i] = j_enc_134[j_i] ^ ((55 + 172) ^ (6147 ^ 6147));
    j_rb[27] = ((0 + 0) ^ (8137 ^ 8137));
    return j_rb;
}

static const volatile uint8_t j_enc_135[] = {0x86, 0x80, 0x87, 0x97};
static const char* j_dc_135(void) {
    static char j_rb[((0 + 5) ^ (5718 ^ 5718))];
    for (int j_i = ((0 + 0) ^ (2970 ^ 2970)); j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_135[j_i] ^ 242;
    j_rb[(3 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_136[] = {0x8F, 0x88, 0x85, 0x9A, 0x8C};
static const char* j_dc_136(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_136[j_i] ^ 233;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_137[] = {0x92, 0x94, 0x93, 0x83};
static const char* j_dc_137(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_137[j_i] ^ 230;
    j_rb[(2 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_138[] = {0x7C, 0x7B, 0x76, 0x69, 0x7F};
static const char* j_dc_138(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((0 + 5) ^ (6971 ^ 6971)); j_i++) j_rb[j_i] = j_enc_138[j_i] ^ 26;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_139[] = {0x22, 0x22, 0x3F, 0x79, 0x76, 0x7D, 0x70, 0x71, 0x7E, 0x7C, 0x7C, 0x76, 0x3F, 0x37, 0x6D, 0x7A, 0x7C, 0x6A, 0x6D, 0x6C, 0x76, 0x69, 0x7A, 0x36, 0x3F, 0x22, 0x22};
static const char* j_dc_139(void) {
    static char j_rb[((10 + 18) ^ (1327 ^ 1327))];
    for (int j_i = ((0 + 0) ^ (8996 ^ 8996)); j_i < ((1 + 26) ^ (1205 ^ 1205)); j_i++) j_rb[j_i] = j_enc_139[j_i] ^ 31;
    j_rb[27] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_140[] = {0x99, 0x99, 0x84, 0xC2, 0xC5, 0xC7, 0xD0, 0xCB, 0xD6, 0xCD, 0xC5, 0xC8, 0x84, 0x99, 0x99};
static const char* j_dc_140(void) {
    static char j_rb[16];
    for (int j_i = (0 + 0); j_i < (10 + 5); j_i++) j_rb[j_i] = j_enc_140[j_i] ^ 164;
    j_rb[(1 + 14)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_141[] = {0xBF, 0xBF, 0xA2, 0xE5, 0xF0, 0xE7, 0xE3, 0xF6, 0xE7, 0xF1, 0xF6, 0xA2, 0xE1, 0xED, 0xEF, 0xEF, 0xED, 0xEC, 0xA2, 0xE6, 0xEB, 0xF4, 0xEB, 0xF1, 0xED, 0xF0, 0xA2, 0xBF, 0xBF};
static const char* j_dc_141(void) {
    static char j_rb[30];
    for (int j_i = (0 + 0); j_i < 29; j_i++) j_rb[j_i] = j_enc_141[j_i] ^ ((8 + 122) ^ (4123 ^ 4123));
    j_rb[(15 + 14)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_142[] = {0xEF, 0xEF, 0xF2, 0xA2, 0xA0, 0xBB, 0xBF, 0xB3, 0xBE, 0xBB, 0xA6, 0xAB, 0xF2, 0xEF, 0xEF};
static const char* j_dc_142(void) {
    static char j_rb[16];
    for (int j_i = (0 + 0); j_i < ((2 + 13) ^ (7304 ^ 7304)); j_i++) j_rb[j_i] = j_enc_142[j_i] ^ 210;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_143[] = {0x84, 0x82, 0x85, 0x95};
static const char* j_dc_143(void) {
    static char j_rb[((1 + 4) ^ (5942 ^ 5942))];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_143[j_i] ^ ((50 + 190) ^ (8509 ^ 8509));
    j_rb[((3 + 1) ^ (7647 ^ 7647))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_144[] = {0x7B, 0x7C, 0x71, 0x6E, 0x78};
static const char* j_dc_144(void) {
    static char j_rb[((6 + 0) ^ (526 ^ 526))];
    for (int j_i = 0; j_i < ((1 + 4) ^ (3338 ^ 3338)); j_i++) j_rb[j_i] = j_enc_144[j_i] ^ 29;
    j_rb[(5 + 0)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_145[] = {0x27, 0x21, 0x26, 0x36};
static const char* j_dc_145(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_145[j_i] ^ ((45 + 38) ^ (2068 ^ 2068));
    j_rb[4] = ((0 + 0) ^ (3464 ^ 3464));
    return j_rb;
}

static const volatile uint8_t j_enc_146[] = {0x96, 0x91, 0x9C, 0x83, 0x95};
static const char* j_dc_146(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (3 + 2); j_i++) j_rb[j_i] = j_enc_146[j_i] ^ (5 + 235);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_147[] = {0xAE, 0xA8, 0xAF, 0xBF};
static const char* j_dc_147(void) {
    static char j_rb[((5 + 0) ^ (5984 ^ 5984))];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_147[j_i] ^ 218;
    j_rb[4] = ((0 + 0) ^ (1452 ^ 1452));
    return j_rb;
}

static const volatile uint8_t j_enc_148[] = {0xFD, 0xFA, 0xF7, 0xE8, 0xFE};
static const char* j_dc_148(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (3028 ^ 3028)); j_i < ((3 + 2) ^ (9636 ^ 9636)); j_i++) j_rb[j_i] = j_enc_148[j_i] ^ 155;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_149[] = {0xD0, 0xD6, 0xD1, 0xC1};
static const char* j_dc_149(void) {
    static char j_rb[((4 + 1) ^ (8294 ^ 8294))];
    for (int j_i = 0; j_i < ((0 + 4) ^ (9652 ^ 9652)); j_i++) j_rb[j_i] = j_enc_149[j_i] ^ ((112 + 52) ^ (3537 ^ 3537));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_150[] = {0x19, 0x1E, 0x13, 0x0C, 0x1A};
static const char* j_dc_150(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_150[j_i] ^ (109 + 18);
    j_rb[(3 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_151[] = {0x14, 0x14, 0x09, 0x59, 0x5B, 0x40, 0x44, 0x4C, 0x5A, 0x09, 0x5C, 0x59, 0x09, 0x5D, 0x46, 0x09, 0x1A, 0x19, 0x09, 0x14, 0x14};
static const char* j_dc_151(void) {
    static char j_rb[((6 + 16) ^ (115 ^ 115))];
    for (int j_i = (0 + 0); j_i < ((20 + 1) ^ (8935 ^ 8935)); j_i++) j_rb[j_i] = j_enc_151[j_i] ^ ((10 + 31) ^ (3593 ^ 3593));
    j_rb[21] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_152[] = {0x30, 0x30, 0x2D, 0x6E, 0x62, 0x61, 0x61, 0x6C, 0x79, 0x77, 0x2D, 0x7E, 0x79, 0x68, 0x7D, 0x7E, 0x2D, 0x30, 0x30};
static const char* j_dc_152(void) {
    static char j_rb[20];
    for (int j_i = 0; j_i < (1 + 18); j_i++) j_rb[j_i] = j_enc_152[j_i] ^ 13;
    j_rb[(19 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_153[] = {0xA4, 0xA4, 0xB9, 0xEA, 0xEC, 0xF4, 0xB9, 0xF6, 0xFF, 0xB9, 0xFD, 0xF0, 0xFE, 0xF0, 0xED, 0xEA, 0xB9, 0xA4, 0xA4};
static const char* j_dc_153(void) {
    static char j_rb[((10 + 10) ^ (7161 ^ 7161))];
    for (int j_i = 0; j_i < 19; j_i++) j_rb[j_i] = j_enc_153[j_i] ^ ((80 + 73) ^ (2514 ^ 2514));
    j_rb[19] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_154[] = {0x17, 0x17, 0x0A, 0x58, 0x4F, 0x5C, 0x4F, 0x58, 0x59, 0x4F, 0x0A, 0x4E, 0x43, 0x4D, 0x43, 0x5E, 0x59, 0x0A, 0x17, 0x17};
static const char* j_dc_154(void) {
    static char j_rb[21];
    for (int j_i = 0; j_i < ((0 + 20) ^ (9119 ^ 9119)); j_i++) j_rb[j_i] = j_enc_154[j_i] ^ (0 + 42);
    j_rb[(2 + 18)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_155[] = {0x4F, 0x4F, 0x52, 0x02, 0x1D, 0x05, 0x17, 0x00, 0x52, 0x4F, 0x4F};
static const char* j_dc_155(void) {
    static char j_rb[12];
    for (int j_i = ((0 + 0) ^ (7310 ^ 7310)); j_i < 11; j_i++) j_rb[j_i] = j_enc_155[j_i] ^ 114;
    j_rb[(4 + 7)] = ((0 + 0) ^ (1862 ^ 1862));
    return j_rb;
}

static const volatile uint8_t j_enc_156[] = {0xAC, 0xAC, 0xB1, 0xFC, 0xF8, 0xFF, 0xB1, 0xBE, 0xB1, 0xFC, 0xF0, 0xE9, 0xB1, 0xFE, 0xF7, 0xB1, 0xE5, 0xF9, 0xE3, 0xF4, 0xF4, 0xB1, 0xAC, 0xAC};
static const char* j_dc_156(void) {
    static char j_rb[((21 + 4) ^ (8730 ^ 8730))];
    for (int j_i = ((0 + 0) ^ (1408 ^ 1408)); j_i < 24; j_i++) j_rb[j_i] = j_enc_156[j_i] ^ 145;
    j_rb[((15 + 9) ^ (847 ^ 847))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_157[] = {0x69, 0x69, 0x74, 0x24, 0x35, 0x38, 0x3D, 0x3A, 0x30, 0x26, 0x3B, 0x39, 0x31, 0x74, 0x3A, 0x21, 0x39, 0x36, 0x31, 0x26, 0x74, 0x69, 0x69};
static const char* j_dc_157(void) {
    static char j_rb[(4 + 20)];
    for (int j_i = ((0 + 0) ^ (962 ^ 962)); j_i < (22 + 1); j_i++) j_rb[j_i] = j_enc_157[j_i] ^ (24 + 60);
    j_rb[((17 + 6) ^ (8264 ^ 8264))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_158[] = {0xB7, 0xB1, 0xB6, 0xA6};
static const char* j_dc_158(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (8241 ^ 8241)); j_i < 4; j_i++) j_rb[j_i] = j_enc_158[j_i] ^ 195;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_159[] = {0x36, 0x31, 0x3C, 0x23, 0x35};
static const char* j_dc_159(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_159[j_i] ^ (38 + 42);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_160[] = {0xC9, 0xCF, 0xC8, 0xD8};
static const char* j_dc_160(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_160[j_i] ^ ((185 + 4) ^ (5056 ^ 5056));
    j_rb[(2 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_161[] = {0x8C, 0x8B, 0x86, 0x99, 0x8F};
static const char* j_dc_161(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_161[j_i] ^ ((26 + 208) ^ (6665 ^ 6665));
    j_rb[((5 + 0) ^ (8263 ^ 8263))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_162[] = {0xE8, 0xEE, 0xE9, 0xF9};
static const char* j_dc_162(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_162[j_i] ^ (21 + 135);
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_163[] = {0x33, 0x34, 0x39, 0x26, 0x30};
static const char* j_dc_163(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_163[j_i] ^ 85;
    j_rb[5] = ((0 + 0) ^ (7152 ^ 7152));
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[(50959 + 14577)];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = (0 + 0);
    for (const char* p = s; *p && o + 8 < cap; ++p) {
        unsigned char c = (unsigned char)*p;
        switch (c) {
            case '"': out[o++] = '\\'; out[o++] = '"'; break;
            case '\\': out[o++] = '\\'; out[o++] = '\\'; break;
            case '\n': out[o++] = '\\'; out[o++] = 'n'; break;
            case '\r': out[o++] = '\\'; out[o++] = 'r'; break;
            case '\t': out[o++] = '\\'; out[o++] = 't'; break;
            default:
                if (c < 0x20) {
                    out[o++] = '\\'; out[o++] = 'u'; out[o++] = '0'; out[o++] = '0';
                    out[o++] = j_dc_0()[c >> 4];
                    out[o++] = j_dc_1()[c & ((4 + 11) ^ (4491 ^ 4491))];
                } else out[o++] = (char)c;
        }
    }
    out[o] = '\0';
}

static const char* j_sys_now(void) {
    time_t t = time(NULL);
#if defined(_WIN32)
    struct tm* tmv = localtime(&t);
    strftime(j_buf, J_BUF_CAP, "%Y-%m-%dT%H:%M:%S", tmv);
#else
    struct tm tmv;
    localtime_r(&t, &tmv);
    strftime(j_buf, J_BUF_CAP, "%Y-%m-%dT%H:%M:%S", &tmv);
#endif
    return j_buf;
}

static void j_sys_sleep(int32_t ms) {
#if defined(_WIN32)
    Sleep((DWORD)ms);
#else
    struct timespec ts;
    ts.tv_sec = ms / (531 + 469);
    ts.tv_nsec = (long)(ms % (652 + 348)) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}

static const char* j_sys_cwd(void) {
#if defined(_WIN32)
    _getcwd(j_buf, (int)J_BUF_CAP);
#else
    getcwd(j_buf, J_BUF_CAP);
#endif
    return j_buf;
}

static const char* j_env_get(const char* name) {
    const char* v = getenv(name);
    return v ? v : "";
}

static bool j_fs_exists(const char* path) {
#if defined(_WIN32)
    return GetFileAttributesA(path) != INVALID_FILE_ATTRIBUTES;
#else
    return access(path, F_OK) == ((0 + 0) ^ (1047 ^ 1047));
#endif
}

static const char* j_fs_read(const char* path) {
    FILE* f = fopen(path, j_dc_2());
    if (!f) return "";
    size_t n = fread(j_buf, 1, J_BUF_CAP - (0 + 1), f);
    fclose(f);
    j_buf[n] = '\0';
    return j_buf;
}

static void j_fs_write(const char* path, const char* data) {
    FILE* f = fopen(path, j_dc_3());
    if (f) { fputs(data, f); fclose(f); }
}

static const char* j_fs_list(const char* dir) {
    size_t off = (0 + 0);
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    char pattern[((72 + 952) ^ (3318 ^ 3318))];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[((0 + 0) ^ (4539 ^ 4539))] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = ((0 + 0) ^ (8429 ^ 8429));
            char esc[1024];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > ((0 + 0) ^ (3632 ^ 3632)) ? n : 0);
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[((475 + 549) ^ (5757 ^ 5757))];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > ((0 + 0) ^ (2635 ^ 2635)) ? n : (0 + 0));
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_sys_process_list(void) {
    size_t off = ((0 + 0) ^ (5319 ^ 5319));
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - 400) break;
                char name[1024];
                size_t k = (0 + 0);
                for (size_t i = ((0 + 0) ^ (6976 ^ 6976)); pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = ((0 + 0) ^ (5497 ^ 5497));
                char esc[((689 + 1359) ^ (1427 ^ 1427))];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > 0 ? n : 0);
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[8192];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = 0; i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - ((20 + 380) ^ (890 ^ 890))) break;
        char name[((185 + 71) ^ (9747 ^ 9747))];
        int len = proc_name(pid, name, sizeof name);
        if (len <= 0) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = ((0 + 0) ^ (4248 ^ 4248));
        char esc[((341 + 171) ^ (756 ^ 756))];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > ((0 + 0) ^ (2750 ^ 2750)) ? n : ((0 + 0) ^ (8228 ^ 8228)));
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[(0 + 0)] < '0' || de->d_name[((0 + 0) ^ (562 ^ 562))] > '9') continue;
            int pid = atoi(de->d_name);
            char p[((20 + 44) ^ (7892 ^ 7892))], name[((155 + 101) ^ (3747 ^ 3747))];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - ((332 + 68) ^ (8681 ^ 8681))) break;
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                char esc[(502 + 10)];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > ((0 + 0) ^ (9583 ^ 9583)) ? n : (0 + 0));
            }
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static void j_net_proc_parse(const char* path, size_t* off, int* first) {
    FILE* f = fopen(path, j_dc_7());
    if (!f) return;
    char line[(158 + 354)];
    int skip = (1 + 0);
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = ((0 + 0) ^ (3369 ^ 3369)); continue; }
        char laddr[64], raddr[64], st[16];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != (0 + 3)) continue;
        if (*off > J_BUF_CAP - ((50 + 250) ^ (6072 ^ 6072))) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = 0;
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : 0);
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    ULONG sz = 0;
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, ((0 + 0) ^ (4892 ^ 4892)));
    char* t = (char*)malloc(sz ? sz : ((1 + 0) ^ (1156 ^ 1156)));
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, ((0 + 0) ^ (1265 ^ 1265))) == NO_ERROR) {
            for (DWORD i = (0 + 0); i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[(23 + 41)], ri[((45 + 19) ^ (5983 ^ 5983))];
                snprintf(li, sizeof li, "%s:%u", inet_ntoa(*(struct in_addr*)&r->dwLocalAddr), (unsigned)ntohs((u_short)r->dwLocalPort));
                snprintf(ri, sizeof ri, "%s:%u", inet_ntoa(*(struct in_addr*)&r->dwRemoteAddr), (unsigned)ntohs((u_short)r->dwRemotePort));
                const char* state = j_dc_8();
                switch (r->dwState) {
                    case 2:  state = j_dc_9(); break;
                    case 5:  state = j_dc_10(); break;
                    case 8:  state = j_dc_11(); break;
                    case 11: state = j_dc_12(); break;
                    default: state = j_dc_13(); break;
                }
                if (off > J_BUF_CAP - (56 + 244)) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > (0 + 0) ? n : ((0 + 0) ^ (4026 ^ 4026)));
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[8], laddr[64], raddr[((21 + 43) ^ (2051 ^ 2051))], st[((22 + 10) ^ (7353 ^ 7353))];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == (3 + 1)) {
                if (strncmp(proto, j_dc_16(), 3) != 0) continue;
                if (off > J_BUF_CAP - (293 + 7)) break;
                if (!first) j_buf[off++] = ',';
                first = ((0 + 0) ^ (8978 ^ 8978));
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        pclose(ns);
    }
#else
    j_net_proc_parse(j_dc_17(), &off, &first);
    j_net_proc_parse(j_dc_18(), &off, &first);
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_reg_list(const char* key) {
    size_t off = (0 + 0);
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), (2 + 3)) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + 5; }
    else if (strncmp(key, j_dc_20(), 5) == 0) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, j_dc_21(), 5) == 0) { root = HKEY_CLASSES_ROOT; sub = key + (2 + 3); }
    else if (strncmp(key, j_dc_22(), ((4 + 0) ^ (3892 ^ 3892))) == 0) { root = HKEY_USERS; sub = key + 4; }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, 0, KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = 0; ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[((258 + 254) ^ (9743 ^ 9743))];
            j_json_escape(esc, sizeof esc, s);
            int n2 = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n2 > (0 + 0) ? n2 : (0 + 0));
        }
        RegCloseKey(hk);
    }
#else
    (void)key;
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static void j_mem_dump(int32_t pid, const char* path) {
#if defined(_WIN32)
    HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, (DWORD)pid);
    if (!h) return;
    FILE* out = fopen(path, j_dc_23());
    if (!out) { CloseHandle(h); return; }
    unsigned char* base = NULL;
    MEMORY_BASIC_INFORMATION mbi;
    unsigned long regions = ((0 + 0) ^ (168 ^ 168));
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < 100000) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : 1);
            SIZE_T read = 0;
            if (chunk && ReadProcessMemory(h, mbi.BaseAddress, chunk, mbi.RegionSize, &read) && read) {
                fwrite(chunk, 1, read, out);
            }
            free(chunk);
        }
        base = (unsigned char*)mbi.BaseAddress + mbi.RegionSize;
    }
    fclose(out);
    CloseHandle(h);
#else
    (void)pid; (void)path;
#endif
}

static volatile int32_t j_7hgmqpdm = 42673;
static volatile int32_t j_t0c8jewu = ((20860 + 4823) ^ (5633 ^ 5633));

static int32_t j_4f7g6fui(int32_t j_zjsufqwi);
static int32_t j_t2hghb9f(int32_t j_zjsufqwi);
static int32_t j_oiwo6t0n(int32_t j_zjsufqwi);
static int32_t j_vls2wrj8(int32_t j_m2p7e3pa, int32_t j_doqql8pa);
static bool j_t8lvogp4(int32_t j_zjsufqwi);
static int32_t j_vxxehlw0(int32_t j_zjsufqwi);
static int32_t j_m3tuz7o1(int32_t j_zjsufqwi);
static int32_t j_dwwcl9v0(int32_t j_zjsufqwi);
static int32_t j_u1jd8trj(int32_t j_gcfgd3i4, int32_t j_eu3wz7tw);
static int32_t j_w6mesi0m(int32_t j_m2p7e3pa, int32_t j_doqql8pa, int32_t j_l052rhh3);
static int32_t j_gutsi31n(int32_t j_m2p7e3pa, int32_t j_doqql8pa, int32_t j_l052rhh3);
static bool j_dk9e63to(int32_t j_zjsufqwi);

static int32_t j_4f7g6fui(int32_t j_zjsufqwi)
{
    int32_t j_468tmzoa = 0;
    while ((j_468tmzoa != -1))
    {
        switch (j_468tmzoa)
        {
            case 0:
                if ((j_zjsufqwi < ((2 + 0) ^ (8030 ^ 8030))))
                {
                    return j_zjsufqwi;
                }
                j_468tmzoa = 1;
                break;
            case 1:
                int32_t j_m2p7e3pa = ((0 + 0) ^ (5112 ^ 5112));
                int32_t j_doqql8pa = (1 + 0);
                int32_t j_qo32bb5q = 2;
                static volatile int64_t j_ifxsxp8l = 57815;
                if ((((j_ifxsxp8l * j_ifxsxp8l) + j_ifxsxp8l) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (9363 ^ 9363)) ? j_dc_24() : j_dc_25());
                }
                j_468tmzoa = 2;
                break;
            case 2:
                static volatile int64_t j_l9dl9lcd = 64539;
                static volatile int64_t j_7m5fgot7 = (1205 + 30300);
                if ((((j_7m5fgot7 * j_7m5fgot7) + j_7m5fgot7) < 0))
                {
                    volatile int64_t j_yn30xwb1 = ((j_7m5fgot7 * 28) + ((48 + 457) ^ (2763 ^ 2763)));
                    (void)printf("%s\n", 0 ? j_dc_26() : j_dc_27());
                }
                j_468tmzoa = ((2 + 1) ^ (7917 ^ 7917));
                break;
            case 3:
                if ((((j_l9dl9lcd * j_l9dl9lcd) + j_l9dl9lcd) < ((0 + 0) ^ (7840 ^ 7840))))
                {
                    volatile int64_t j_kiietxma = ((j_l9dl9lcd * 97) + (418 + 121));
                    (void)printf("%s\n", 0 ? j_dc_28() : j_dc_29());
                }
                j_468tmzoa = ((0 + 4) ^ (2712 ^ 2712));
                break;
            case 4:
                while ((j_qo32bb5q <= j_zjsufqwi))
                {
                    int32_t j_v3huvf2v = (j_m2p7e3pa + j_doqql8pa);
                    j_m2p7e3pa = j_doqql8pa;
                    j_doqql8pa = j_v3huvf2v;
                    j_qo32bb5q = (j_qo32bb5q + 1);
                }
                j_468tmzoa = ((1 + 4) ^ (2865 ^ 2865));
                break;
            case 5:
                return j_doqql8pa;
                break;
            case 6:
                static volatile int64_t j_qb8n9rkr = 76321;
                static volatile int64_t j_fy0gpnl9 = 23976;
                if ((((j_fy0gpnl9 * j_fy0gpnl9) + j_fy0gpnl9) < 0))
                {
                    volatile int64_t j_c1wchsa4 = ((j_fy0gpnl9 * ((20 + 15) ^ (9940 ^ 9940))) + ((844 + 132) ^ (6049 ^ 6049)));
                    (void)printf("%s\n", 0 ? j_dc_30() : j_dc_31());
                }
                j_468tmzoa = 7;
                break;
            case 7:
                if ((((j_qb8n9rkr * j_qb8n9rkr) + j_qb8n9rkr) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_32() : j_dc_33());
                }
                j_468tmzoa = -(1 + 0);
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (2620 ^ 2620));
}

static int32_t j_t2hghb9f(int32_t j_zjsufqwi)
{
    int32_t j_lyd9q6x2 = 0;
    while ((j_lyd9q6x2 != -1))
    {
        switch (j_lyd9q6x2)
        {
            case 0:
                static volatile int64_t j_xsop1o4p = 41575;
                if ((((j_xsop1o4p * (j_xsop1o4p + (0 + 1))) % 2) == ((0 + 1) ^ (9977 ^ 9977))))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (5350 ^ 5350)) ? j_dc_34() : j_dc_35());
                }
                j_lyd9q6x2 = 1;
                break;
            case 1:
                if ((j_zjsufqwi < (0 + 2)))
                {
                    return j_zjsufqwi;
                }
                j_lyd9q6x2 = 2;
                break;
            case 2:
                static volatile int64_t j_ney0af9f = 46539;
                if ((((j_ney0af9f * j_ney0af9f) + j_ney0af9f) < (0 + 0)))
                {
                    volatile int64_t j_dj8cfjgn = ((j_ney0af9f * (30 + 43)) + 539);
                    (void)printf("%s\n", 0 ? j_dc_36() : j_dc_37());
                }
                j_lyd9q6x2 = ((0 + 3) ^ (5762 ^ 5762));
                break;
            case 3:
                static volatile int64_t j_mbs50pn8 = (45886 + 3858);
                if ((((j_mbs50pn8 * j_mbs50pn8) + j_mbs50pn8) < ((0 + 0) ^ (1066 ^ 1066))))
                {
                    volatile int64_t j_gzdn22af = ((j_mbs50pn8 * 15) + (599 + 145));
                    (void)printf("%s\n", 0 ? j_dc_38() : j_dc_39());
                }
                j_lyd9q6x2 = ((2 + 2) ^ (9651 ^ 9651));
                break;
            case 4:
                return (j_t2hghb9f((j_zjsufqwi - 1)) + j_t2hghb9f((j_zjsufqwi - 2)));
                break;
            case 5:
                static volatile int64_t j_2ct6q877 = 73005;
                if ((((j_2ct6q877 * (j_2ct6q877 + 1)) % ((1 + 1) ^ (9181 ^ 9181))) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_40() : j_dc_41());
                }
                j_lyd9q6x2 = -((0 + 1) ^ (1968 ^ 1968));
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_oiwo6t0n(int32_t j_zjsufqwi)
{
    int32_t j_f1hbv9t4 = ((0 + 0) ^ (781 ^ 781));
    while ((j_f1hbv9t4 != -1))
    {
        switch (j_f1hbv9t4)
        {
            case 0:
                if ((j_zjsufqwi <= 1))
                {
                    return 1;
                }
                j_f1hbv9t4 = (0 + 1);
                break;
            case 1:
                return (j_zjsufqwi * j_oiwo6t0n((j_zjsufqwi - (0 + 1))));
                break;
            case 2:
                static volatile int64_t j_v19rzg9k = 41872;
                static volatile int64_t j_kwyqhptu = 9402;
                if ((((j_kwyqhptu * j_kwyqhptu) + j_kwyqhptu) < ((0 + 0) ^ (7781 ^ 7781))))
                {
                    volatile int64_t j_v0z664x0 = ((j_kwyqhptu * ((3 + 5) ^ (3660 ^ 3660))) + 402);
                    (void)printf("%s\n", 0 ? j_dc_42() : j_dc_43());
                }
                j_f1hbv9t4 = 3;
                break;
            case 3:
                if ((((j_v19rzg9k * j_v19rzg9k) + j_v19rzg9k) < 0))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_44() : j_dc_45());
                }
                j_f1hbv9t4 = (0 + 4);
                break;
            case 4:
                static volatile int64_t j_27a2qis4 = ((80644 + 16992) ^ (8576 ^ 8576));
                if ((((j_27a2qis4 * j_27a2qis4) + j_27a2qis4) < (0 + 0)))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (2295 ^ 2295)) ? j_dc_46() : j_dc_47());
                }
                j_f1hbv9t4 = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_vls2wrj8(int32_t j_m2p7e3pa, int32_t j_doqql8pa)
{
    int32_t j_zhoekmdo = 0;
    while ((j_zhoekmdo != -1))
    {
        switch (j_zhoekmdo)
        {
            case 0:
                static volatile int64_t j_wkye35n7 = 65840;
                if ((((j_wkye35n7 * j_wkye35n7) + j_wkye35n7) < 0))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_48() : j_dc_49());
                }
                j_zhoekmdo = 1;
                break;
            case 1:
                static volatile int64_t j_vyo8ezrt = 91539;
                if ((((j_vyo8ezrt * j_vyo8ezrt) + j_vyo8ezrt) < 0))
                {
                    volatile int64_t j_nywn77f5 = ((j_vyo8ezrt * ((83 + 15) ^ (5428 ^ 5428))) + ((36 + 503) ^ (6261 ^ 6261)));
                    (void)printf("%s\n", ((0 + 0) ^ (7774 ^ 7774)) ? j_dc_50() : j_dc_51());
                }
                j_zhoekmdo = 2;
                break;
            case 2:
                static volatile int64_t j_00zpd4o1 = 65614;
                static volatile int64_t j_46wox3cs = 61084;
                static volatile int64_t j_7yom7oru = (3891 + 29777);
                if ((((j_7yom7oru * j_7yom7oru) + j_7yom7oru) < (0 + 0)))
                {
                    volatile int64_t j_c4i39azk = ((j_7yom7oru * ((26 + 6) ^ (166 ^ 166))) + 668);
                    (void)printf("%s\n", 0 ? j_dc_52() : j_dc_53());
                }
                j_zhoekmdo = ((0 + 3) ^ (3853 ^ 3853));
                break;
            case 3:
                if ((((j_46wox3cs * j_46wox3cs) + j_46wox3cs) < (0 + 0)))
                {
                    (void)printf("%s\n", 0 ? j_dc_54() : j_dc_55());
                }
                j_zhoekmdo = ((0 + 4) ^ (5671 ^ 5671));
                break;
            case 4:
                if ((((j_00zpd4o1 * j_00zpd4o1) % 4) < 2))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_56() : j_dc_57());
                }
                j_zhoekmdo = 5;
                break;
            case 5:
                if ((j_doqql8pa == 0))
                {
                    return j_m2p7e3pa;
                }
                j_zhoekmdo = (0 + 6);
                break;
            case 6:
                return j_vls2wrj8(j_doqql8pa, (j_m2p7e3pa % j_doqql8pa));
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (6757 ^ 6757));
}

static bool j_t8lvogp4(int32_t j_zjsufqwi)
{
    int32_t j_tr73225m = (0 + 0);
    while ((j_tr73225m != -(0 + 1)))
    {
        switch (j_tr73225m)
        {
            case 0:
                static volatile int64_t j_6lcv1ym4 = 18008;
                if ((((j_6lcv1ym4 * j_6lcv1ym4) + j_6lcv1ym4) >= (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_58() : j_dc_59());
                }
                j_tr73225m = 1;
                break;
            case 1:
                static volatile int64_t j_s1u5c2bw = ((47787 + 6562) ^ (9568 ^ 9568));
                if ((((j_s1u5c2bw * j_s1u5c2bw) + j_s1u5c2bw) < 0))
                {
                    volatile int64_t j_eexnkan3 = ((j_s1u5c2bw * ((4 + 41) ^ (1230 ^ 1230))) + 349);
                    (void)printf("%s\n", ((0 + 0) ^ (3360 ^ 3360)) ? j_dc_60() : j_dc_61());
                }
                j_tr73225m = (0 + 2);
                break;
            case 2:
                if ((j_zjsufqwi < 2))
                {
                    return false;
                }
                j_tr73225m = ((3 + 0) ^ (2023 ^ 2023));
                break;
            case 3:
                int32_t j_qo32bb5q = (2 + 0);
                while (((j_qo32bb5q * j_qo32bb5q) <= j_zjsufqwi))
                {
                    if (((j_zjsufqwi % j_qo32bb5q) == ((0 + 0) ^ (5566 ^ 5566))))
                    {
                        return false;
                    }
                    j_qo32bb5q = (j_qo32bb5q + 1);
                }
                j_tr73225m = 4;
                break;
            case 4:
                static volatile int64_t j_r3lyvytq = ((12573 + 25869) ^ (4889 ^ 4889));
                if ((((j_r3lyvytq * j_r3lyvytq) + j_r3lyvytq) < ((0 + 0) ^ (8617 ^ 8617))))
                {
                    volatile int64_t j_qv6uminn = ((j_r3lyvytq * 51) + ((286 + 156) ^ (1785 ^ 1785)));
                    (void)printf("%s\n", 0 ? j_dc_62() : j_dc_63());
                }
                j_tr73225m = 5;
                break;
            case 5:
                return true;
                break;
            case 6:
                static volatile int64_t j_2c53ign6 = 21165;
                static volatile int64_t j_9kqju9v1 = (12072 + 60581);
                if ((((j_9kqju9v1 * j_9kqju9v1) + j_9kqju9v1) < 0))
                {
                    volatile int64_t j_0dnkds5g = ((j_9kqju9v1 * ((75 + 25) ^ (2605 ^ 2605))) + 653);
                    (void)printf("%s\n", 0 ? j_dc_64() : j_dc_65());
                }
                j_tr73225m = (6 + 1);
                break;
            case 7:
                static volatile int64_t j_6t4eaaox = 16918;
                if ((((j_6t4eaaox * j_6t4eaaox) + j_6t4eaaox) < 0))
                {
                    volatile int64_t j_f8wwr90p = ((j_6t4eaaox * 15) + 918);
                    (void)printf("%s\n", 0 ? j_dc_66() : j_dc_67());
                }
                j_tr73225m = 8;
                break;
            case 8:
                if ((((j_2c53ign6 * j_2c53ign6) + j_2c53ign6) < ((0 + 0) ^ (6414 ^ 6414))))
                {
                    (void)printf("%s\n", 0 ? j_dc_68() : j_dc_69());
                }
                j_tr73225m = -1;
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

static int32_t j_vxxehlw0(int32_t j_zjsufqwi)
{
    int32_t j_andim2q7 = (0 + 0);
    while ((j_andim2q7 != -1))
    {
        switch (j_andim2q7)
        {
            case 0:
                static volatile int64_t j_ybligual = ((6724 + 27475) ^ (6210 ^ 6210));
                if ((((j_ybligual * j_ybligual) % 4) < ((0 + 2) ^ (9399 ^ 9399))))
                {
                }
                else
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_70() : j_dc_71());
                }
                j_andim2q7 = ((1 + 0) ^ (1846 ^ 1846));
                break;
            case 1:
                static volatile int64_t j_r5oqef5n = 56002;
                if ((((j_r5oqef5n * j_r5oqef5n) + j_r5oqef5n) < ((0 + 0) ^ (8125 ^ 8125))))
                {
                    volatile int64_t j_2561o13g = ((j_r5oqef5n * (30 + 13)) + 2);
                    (void)printf("%s\n", 0 ? j_dc_72() : j_dc_73());
                }
                j_andim2q7 = (2 + 0);
                break;
            case 2:
                int32_t j_45k0m0xl = 0;
                int32_t j_3p7qt3hh = j_zjsufqwi;
                static volatile int64_t j_ey467ne8 = ((59935 + 19508) ^ (4553 ^ 4553));
                if ((((j_ey467ne8 * j_ey467ne8) + j_ey467ne8) < ((0 + 0) ^ (2889 ^ 2889))))
                {
                    volatile int64_t j_eymlwma1 = ((j_ey467ne8 * 59) + ((271 + 172) ^ (9824 ^ 9824)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_74() : j_dc_75());
                }
                j_andim2q7 = 3;
                break;
            case 3:
                static volatile int64_t j_5tphmacs = 85453;
                static volatile int64_t j_8o5fuudq = 32307;
                if ((((j_8o5fuudq * j_8o5fuudq) + j_8o5fuudq) < 0))
                {
                    volatile int64_t j_qana0zdj = ((j_8o5fuudq * (24 + 7)) + ((84 + 223) ^ (8836 ^ 8836)));
                    (void)printf("%s\n", ((0 + 0) ^ (449 ^ 449)) ? j_dc_76() : j_dc_77());
                }
                j_andim2q7 = ((0 + 4) ^ (6928 ^ 6928));
                break;
            case 4:
                if ((((j_5tphmacs * j_5tphmacs) + j_5tphmacs) < ((0 + 0) ^ (8273 ^ 8273))))
                {
                    (void)printf("%s\n", 0 ? j_dc_78() : j_dc_79());
                }
                j_andim2q7 = (2 + 3);
                break;
            case 5:
                while ((j_3p7qt3hh != ((0 + 1) ^ (1017 ^ 1017))))
                {
                    if (((j_3p7qt3hh % ((1 + 1) ^ (2476 ^ 2476))) == 0))
                    {
                        j_3p7qt3hh = (j_3p7qt3hh / ((0 + 2) ^ (4169 ^ 4169)));
                    }
                    else
                    {
                        j_3p7qt3hh = ((j_3p7qt3hh * (1 + 2)) + ((1 + 0) ^ (2384 ^ 2384)));
                    }
                    j_45k0m0xl = (j_45k0m0xl + 1);
                }
                j_andim2q7 = ((6 + 0) ^ (2885 ^ 2885));
                break;
            case 6:
                return j_45k0m0xl;
                break;
            case 7:
                static volatile int64_t j_htb3rgly = (12173 + 87524);
                if ((((j_htb3rgly * j_htb3rgly) % ((0 + 4) ^ (951 ^ 951))) == ((1 + 2) ^ (95 ^ 95))))
                {
                    (void)printf("%s\n", 0 ? j_dc_80() : j_dc_81());
                }
                j_andim2q7 = -(1 + 0);
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_m3tuz7o1(int32_t j_zjsufqwi)
{
    int32_t j_81x1jf3y = 0;
    while ((j_81x1jf3y != -(0 + 1)))
    {
        switch (j_81x1jf3y)
        {
            case 0:
                int32_t j_qumacpti = 0;
                int32_t j_7n3fh0c0 = j_zjsufqwi;
                static volatile int64_t j_qwk265v2 = (16409 + 8111);
                static volatile int64_t j_jhb16brr = ((14019 + 44796) ^ (3956 ^ 3956));
                if ((((j_jhb16brr * j_jhb16brr) + j_jhb16brr) < 0))
                {
                    volatile int64_t j_kpt5jy74 = ((j_jhb16brr * 68) + 815);
                    (void)printf("%s\n", 0 ? j_dc_82() : j_dc_83());
                }
                j_81x1jf3y = 1;
                break;
            case 1:
                if ((((j_qwk265v2 * j_qwk265v2) + j_qwk265v2) < 0))
                {
                    volatile int64_t j_je3bxu1e = ((j_qwk265v2 * (29 + 26)) + 520);
                    (void)printf("%s\n", 0 ? j_dc_84() : j_dc_85());
                }
                j_81x1jf3y = ((1 + 1) ^ (6825 ^ 6825));
                break;
            case 2:
                static volatile int64_t j_l17cumr5 = 60766;
                if ((((j_l17cumr5 * j_l17cumr5) + j_l17cumr5) >= (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_86() : j_dc_87());
                }
                j_81x1jf3y = ((0 + 3) ^ (5346 ^ 5346));
                break;
            case 3:
                while ((j_7n3fh0c0 > (0 + 0)))
                {
                    j_qumacpti = (j_qumacpti + (j_7n3fh0c0 % 10));
                    j_7n3fh0c0 = (j_7n3fh0c0 / 10);
                }
                j_81x1jf3y = (2 + 2);
                break;
            case 4:
                static volatile int64_t j_vl90z625 = 67712;
                if ((((j_vl90z625 * j_vl90z625) % ((0 + 4) ^ (9371 ^ 9371))) == 3))
                {
                    (void)printf("%s\n", 0 ? j_dc_88() : j_dc_89());
                }
                j_81x1jf3y = 5;
                break;
            case 5:
                static volatile int64_t j_yackb9o9 = 48641;
                if ((((j_yackb9o9 * (j_yackb9o9 + (0 + 1))) % 2) == ((0 + 0) ^ (9526 ^ 9526))))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (8331 ^ 8331)) ? j_dc_90() : j_dc_91());
                }
                j_81x1jf3y = 6;
                break;
            case 6:
                return j_qumacpti;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_dwwcl9v0(int32_t j_zjsufqwi)
{
    int32_t j_obdh3w0k = (0 + 0);
    while ((j_obdh3w0k != -(1 + 0)))
    {
        switch (j_obdh3w0k)
        {
            case 0:
                if ((j_zjsufqwi < ((0 + 0) ^ (6040 ^ 6040))))
                {
                    return -(j_dwwcl9v0(-(j_zjsufqwi)));
                }
                j_obdh3w0k = (0 + 1);
                break;
            case 1:
                int32_t j_mt0qotjl = 0;
                static volatile int64_t j_051xehyu = ((712 + 10506) ^ (1492 ^ 1492));
                if ((((j_051xehyu * j_051xehyu) + j_051xehyu) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_92() : j_dc_93());
                }
                j_obdh3w0k = ((1 + 1) ^ (903 ^ 903));
                break;
            case 2:
                int32_t j_7n3fh0c0 = j_zjsufqwi;
                while ((j_7n3fh0c0 > (0 + 0)))
                {
                    j_mt0qotjl = ((j_mt0qotjl * 10) + (j_7n3fh0c0 % 10));
                    j_7n3fh0c0 = (j_7n3fh0c0 / 10);
                }
                j_obdh3w0k = 3;
                break;
            case 3:
                return j_mt0qotjl;
                break;
            case 4:
                static volatile int64_t j_pcrwneap = 24352;
                if ((((j_pcrwneap * j_pcrwneap) + j_pcrwneap) < ((0 + 0) ^ (8793 ^ 8793))))
                {
                    volatile int64_t j_1mi6kv9r = ((j_pcrwneap * (9 + 32)) + ((286 + 66) ^ (7190 ^ 7190)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_94() : j_dc_95());
                }
                j_obdh3w0k = -1;
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (4926 ^ 4926));
}

static int32_t j_u1jd8trj(int32_t j_gcfgd3i4, int32_t j_eu3wz7tw)
{
    int32_t j_lqdsll6a = 0;
    while ((j_lqdsll6a != -1))
    {
        switch (j_lqdsll6a)
        {
            case 0:
                static volatile int64_t j_lhwxqj9r = 44455;
                if ((((j_lhwxqj9r * j_lhwxqj9r) + j_lhwxqj9r) < 0))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (967 ^ 967)) ? j_dc_96() : j_dc_97());
                }
                j_lqdsll6a = 1;
                break;
            case 1:
                int32_t j_an62svr9 = (1 + 0);
                static volatile int64_t j_x7von3v7 = 84314;
                if ((((j_x7von3v7 * j_x7von3v7) + j_x7von3v7) < 0))
                {
                    volatile int64_t j_l68dw28g = ((j_x7von3v7 * 95) + 314);
                    (void)printf("%s\n", 0 ? j_dc_98() : j_dc_99());
                }
                j_lqdsll6a = ((2 + 0) ^ (2777 ^ 2777));
                break;
            case 2:
                static volatile int64_t j_hoslr0at = 96157;
                if ((((j_hoslr0at * j_hoslr0at) + j_hoslr0at) < 0))
                {
                    volatile int64_t j_jbb11t8c = ((j_hoslr0at * 42) + ((118 + 39) ^ (8479 ^ 8479)));
                    (void)printf("%s\n", ((0 + 0) ^ (4065 ^ 4065)) ? j_dc_100() : j_dc_101());
                }
                j_lqdsll6a = ((0 + 3) ^ (2345 ^ 2345));
                break;
            case 3:
                int32_t j_qo32bb5q = (0 + 0);
                static volatile int64_t j_mhn3wxje = 79526;
                if ((((j_mhn3wxje * j_mhn3wxje) + j_mhn3wxje) < 0))
                {
                    volatile int64_t j_3cdvb16f = ((j_mhn3wxje * 37) + 526);
                    (void)printf("%s\n", 0 ? j_dc_102() : j_dc_103());
                }
                j_lqdsll6a = (4 + 0);
                break;
            case 4:
                while ((j_qo32bb5q < j_eu3wz7tw))
                {
                    j_an62svr9 = (j_an62svr9 * j_gcfgd3i4);
                    j_qo32bb5q = (j_qo32bb5q + 1);
                }
                j_lqdsll6a = 5;
                break;
            case 5:
                return j_an62svr9;
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (6265 ^ 6265));
}

static int32_t j_w6mesi0m(int32_t j_m2p7e3pa, int32_t j_doqql8pa, int32_t j_l052rhh3)
{
    int32_t j_n8l8nii7 = 0;
    while ((j_n8l8nii7 != -(1 + 0)))
    {
        switch (j_n8l8nii7)
        {
            case 0:
                if (((j_m2p7e3pa >= j_doqql8pa) && (j_m2p7e3pa >= j_l052rhh3)))
                {
                    return j_m2p7e3pa;
                }
                j_n8l8nii7 = 1;
                break;
            case 1:
                static volatile int64_t j_9q46v2mt = 17582;
                if ((((j_9q46v2mt * j_9q46v2mt) + j_9q46v2mt) < (0 + 0)))
                {
                    volatile int64_t j_ddji0doq = ((j_9q46v2mt * 9) + 582);
                    (void)printf("%s\n", (0 + 0) ? j_dc_104() : j_dc_105());
                }
                j_n8l8nii7 = 2;
                break;
            case 2:
                static volatile int64_t j_y3ncgfwg = 74624;
                if ((((j_y3ncgfwg * j_y3ncgfwg) + j_y3ncgfwg) < 0))
                {
                    volatile int64_t j_vo7u5hag = ((j_y3ncgfwg * (2 + 42)) + (271 + 353));
                    (void)printf("%s\n", 0 ? j_dc_106() : j_dc_107());
                }
                j_n8l8nii7 = 3;
                break;
            case 3:
                static volatile int64_t j_7gvi8asa = (35779 + 17322);
                if ((((j_7gvi8asa * j_7gvi8asa) % 4) < 2))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_108() : j_dc_109());
                }
                j_n8l8nii7 = (2 + 2);
                break;
            case 4:
                if (((j_doqql8pa >= j_m2p7e3pa) && (j_doqql8pa >= j_l052rhh3)))
                {
                    return j_doqql8pa;
                }
                j_n8l8nii7 = (4 + 1);
                break;
            case 5:
                static volatile int64_t j_2166sej3 = 53483;
                if ((((j_2166sej3 * j_2166sej3) + j_2166sej3) < 0))
                {
                    volatile int64_t j_07ikarzd = ((j_2166sej3 * ((52 + 14) ^ (5354 ^ 5354))) + 483);
                    (void)printf("%s\n", ((0 + 0) ^ (954 ^ 954)) ? j_dc_110() : j_dc_111());
                }
                j_n8l8nii7 = (6 + 0);
                break;
            case 6:
                return j_l052rhh3;
                break;
            case 7:
                static volatile int64_t j_g6d1yvyy = 39975;
                if ((((j_g6d1yvyy * j_g6d1yvyy) + j_g6d1yvyy) < 0))
                {
                    volatile int64_t j_vemeoo7a = ((j_g6d1yvyy * ((61 + 17) ^ (8551 ^ 8551))) + ((770 + 205) ^ (3414 ^ 3414)));
                    (void)printf("%s\n", ((0 + 0) ^ (443 ^ 443)) ? j_dc_112() : j_dc_113());
                }
                j_n8l8nii7 = -((0 + 1) ^ (527 ^ 527));
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_gutsi31n(int32_t j_m2p7e3pa, int32_t j_doqql8pa, int32_t j_l052rhh3)
{
    int32_t j_iw1z5vc6 = 0;
    while ((j_iw1z5vc6 != -1))
    {
        switch (j_iw1z5vc6)
        {
            case 0:
                if (((j_m2p7e3pa <= j_doqql8pa) && (j_m2p7e3pa <= j_l052rhh3)))
                {
                    return j_m2p7e3pa;
                }
                j_iw1z5vc6 = (1 + 0);
                break;
            case 1:
                static volatile int64_t j_lrm1gehh = (9132 + 11673);
                if ((((j_lrm1gehh * (j_lrm1gehh + 1)) % 2) == (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_114() : j_dc_115());
                }
                j_iw1z5vc6 = 2;
                break;
            case 2:
                static volatile int64_t j_vgpverpo = (89 + 1629);
                if ((((j_vgpverpo * j_vgpverpo) + j_vgpverpo) < ((0 + 0) ^ (5839 ^ 5839))))
                {
                    volatile int64_t j_uztk75r5 = ((j_vgpverpo * 45) + ((331 + 387) ^ (9749 ^ 9749)));
                    (void)printf("%s\n", 0 ? j_dc_116() : j_dc_117());
                }
                j_iw1z5vc6 = (0 + 3);
                break;
            case 3:
                static volatile int64_t j_rrinilmx = ((5279 + 121) ^ (7450 ^ 7450));
                if ((((j_rrinilmx * j_rrinilmx) + j_rrinilmx) < 0))
                {
                    volatile int64_t j_gq4jxv9a = ((j_rrinilmx * (50 + 23)) + 400);
                    (void)printf("%s\n", ((0 + 0) ^ (2371 ^ 2371)) ? j_dc_118() : j_dc_119());
                }
                j_iw1z5vc6 = (4 + 0);
                break;
            case 4:
                static volatile int64_t j_qio12h5g = (94533 + 4179);
                if ((((j_qio12h5g * (j_qio12h5g + ((1 + 0) ^ (1353 ^ 1353)))) % (0 + 2)) == ((0 + 0) ^ (1989 ^ 1989))))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_120() : j_dc_121());
                }
                j_iw1z5vc6 = 5;
                break;
            case 5:
                if (((j_doqql8pa <= j_m2p7e3pa) && (j_doqql8pa <= j_l052rhh3)))
                {
                    return j_doqql8pa;
                }
                j_iw1z5vc6 = 6;
                break;
            case 6:
                return j_l052rhh3;
                break;
            case 7:
                static volatile int64_t j_naocmdn5 = (28122 + 41856);
                if ((((j_naocmdn5 * (j_naocmdn5 + ((1 + 0) ^ (1951 ^ 1951)))) % (0 + 2)) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (9623 ^ 9623)) ? j_dc_122() : j_dc_123());
                }
                j_iw1z5vc6 = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

static bool j_dk9e63to(int32_t j_zjsufqwi)
{
    int32_t j_fc11v1m4 = 0;
    while ((j_fc11v1m4 != -(0 + 1)))
    {
        switch (j_fc11v1m4)
        {
            case 0:
                static volatile int64_t j_8iipg4vh = 13403;
                static volatile int64_t j_awdsb5zl = 34752;
                static volatile int64_t j_43e124er = (1907 + 2631);
                if ((((j_43e124er * j_43e124er) + j_43e124er) < 0))
                {
                    volatile int64_t j_7k0d2soo = ((j_43e124er * 80) + ((219 + 319) ^ (4293 ^ 4293)));
                    (void)printf("%s\n", ((0 + 0) ^ (1941 ^ 1941)) ? j_dc_124() : j_dc_125());
                }
                j_fc11v1m4 = ((0 + 1) ^ (2820 ^ 2820));
                break;
            case 1:
                static volatile int64_t j_ym23c5kb = 96715;
                if ((((j_ym23c5kb * j_ym23c5kb) + j_ym23c5kb) < 0))
                {
                    volatile int64_t j_mceeviu9 = ((j_ym23c5kb * ((31 + 64) ^ (5196 ^ 5196))) + ((567 + 148) ^ (2078 ^ 2078)));
                    (void)printf("%s\n", 0 ? j_dc_126() : j_dc_127());
                }
                j_fc11v1m4 = ((2 + 0) ^ (98 ^ 98));
                break;
            case 2:
                if ((((j_awdsb5zl * j_awdsb5zl) % 4) < 2))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_128() : j_dc_129());
                }
                j_fc11v1m4 = ((2 + 1) ^ (4140 ^ 4140));
                break;
            case 3:
                if ((((j_8iipg4vh * (j_8iipg4vh + 1)) % (2 + 0)) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_130() : j_dc_131());
                }
                j_fc11v1m4 = 4;
                break;
            case 4:
                return (j_zjsufqwi == j_dwwcl9v0(j_zjsufqwi));
                break;
            case 5:
                static volatile int64_t j_bffhgg0u = (410 + 4042);
                if ((((j_bffhgg0u * j_bffhgg0u) + j_bffhgg0u) < (0 + 0)))
                {
                    volatile int64_t j_mpcerarz = ((j_bffhgg0u * (4 + 0)) + (110 + 342));
                    (void)printf("%s\n", 0 ? j_dc_132() : j_dc_133());
                }
                j_fc11v1m4 = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

__attribute__((used)) static int32_t j_z_5ppufq(int32_t j_n) {
    int32_t j_s = (0 + 0);
    int32_t j_i = 1;
    while (j_i <= j_n) {
        if ((j_i % 3) == ((0 + 0) ^ (1398 ^ 1398))) j_s = j_s + j_i;
        else j_s = j_s + j_i * 2;
        j_i = j_i + (1 + 0);
    }
    return j_s;
}

__attribute__((used)) static int32_t j_z_x7fm52(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = 0;
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % 10007;
        j_t = j_t + 1;
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_hy797h(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = ((0 + 0) ^ (6024 ^ 6024));
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % 10007;
        j_t = j_t + ((1 + 0) ^ (6813 ^ 6813));
    }
    return j_r;
}

static int32_t j_tr_w8kitx(void) {
    int32_t j_76zh2lsi = (0 + 0);
    while ((j_76zh2lsi != -1))
    {
        switch (j_76zh2lsi)
        {
            case 0:
                (void)printf("%s\n", j_dc_134());
                static volatile int64_t j_a4a9xqpg = 81491;
                if ((((j_a4a9xqpg * j_a4a9xqpg) + j_a4a9xqpg) < ((0 + 0) ^ (8155 ^ 8155))))
                {
                    volatile int64_t j_wcvk9ns5 = ((j_a4a9xqpg * (19 + 8)) + ((376 + 115) ^ (2914 ^ 2914)));
                    (void)printf("%s\n", ((0 + 0) ^ (1143 ^ 1143)) ? j_dc_135() : j_dc_136());
                }
                j_76zh2lsi = (1 + 0);
                break;
            case 1:
                (void)printf("%d\n", j_4f7g6fui(((0 + 0) ^ (3694 ^ 3694))));
                static volatile int64_t j_97rqq5iy = 70902;
                if ((((j_97rqq5iy * j_97rqq5iy) + j_97rqq5iy) >= 0))
                {
                    (void)printf("%d\n", j_4f7g6fui(1));
                }
                else
                {
                    volatile int64_t j_qz5gkrpa = ((j_97rqq5iy * (0 + 2)) + (1 + 0));
                }
                j_76zh2lsi = (1 + 1);
                break;
            case 2:
                static volatile int64_t j_e7kc7myx = (12373 + 74560);
                if ((((j_e7kc7myx * (j_e7kc7myx + 1)) % (2 + 0)) == (0 + 1)))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (9995 ^ 9995)) ? j_dc_137() : j_dc_138());
                }
                j_76zh2lsi = ((0 + 3) ^ (7721 ^ 7721));
                break;
            case 3:
                (void)printf("%d\n", j_4f7g6fui(10));
                static volatile int64_t j_rpogoku2 = ((51703 + 20045) ^ (8398 ^ 8398));
                if ((((j_rpogoku2 * j_rpogoku2) + j_rpogoku2) >= (0 + 0)))
                {
                    (void)printf("%d\n", j_4f7g6fui(20));
                }
                else
                {
                    volatile int64_t j_1cfns2nj = ((j_rpogoku2 * 2) + 1);
                }
                j_76zh2lsi = 4;
                break;
            case 4:
                (void)printf("%s\n", j_dc_139());
                (void)printf("%d\n", j_t2hghb9f((0 + 0)));
                (void)printf("%d\n", j_t2hghb9f(1));
                (void)printf("%d\n", j_t2hghb9f((0 + 10)));
                static volatile int64_t j_oh0sw3nj = ((15790 + 19917) ^ (5495 ^ 5495));
                if ((((j_oh0sw3nj * j_oh0sw3nj) + j_oh0sw3nj) >= 0))
                {
                    (void)printf("%s\n", j_dc_140());
                }
                else
                {
                    volatile int64_t j_85qwutqy = ((j_oh0sw3nj * ((0 + 2) ^ (1806 ^ 1806))) + 1);
                }
                j_76zh2lsi = 5;
                break;
            case 5:
                (void)printf("%d\n", j_oiwo6t0n(0));
                static volatile int64_t j_17noej0r = 56955;
                if ((((j_17noej0r * j_17noej0r) + j_17noej0r) >= (0 + 0)))
                {
                    (void)printf("%d\n", j_oiwo6t0n(5));
                }
                else
                {
                    volatile int64_t j_0ksabr2h = ((j_17noej0r * ((0 + 2) ^ (1511 ^ 1511))) + (0 + 1));
                }
                j_76zh2lsi = ((5 + 1) ^ (2692 ^ 2692));
                break;
            case 6:
                (void)printf("%d\n", j_oiwo6t0n((6 + 2)));
                static volatile int64_t j_cr5orrps = (651 + 63279);
                if ((((j_cr5orrps * j_cr5orrps) + j_cr5orrps) >= ((0 + 0) ^ (2116 ^ 2116))))
                {
                    (void)printf("%s\n", j_dc_141());
                }
                else
                {
                    volatile int64_t j_cnqg14qg = ((j_cr5orrps * 2) + 1);
                }
                j_76zh2lsi = ((7 + 0) ^ (1989 ^ 1989));
                break;
            case 7:
                static volatile int64_t j_qpr98c2m = (33929 + 10383);
                if ((((j_qpr98c2m * j_qpr98c2m) + j_qpr98c2m) >= 0))
                {
                    (void)printf("%d\n", j_vls2wrj8(48, ((6 + 30) ^ (7671 ^ 7671))));
                }
                else
                {
                    volatile int64_t j_3tuhslui = ((j_qpr98c2m * 2) + 1);
                }
                j_76zh2lsi = 8;
                break;
            case 8:
                static volatile int64_t j_gjjcndpq = 60293;
                if ((((j_gjjcndpq * j_gjjcndpq) + j_gjjcndpq) >= 0))
                {
                    (void)printf("%d\n", j_vls2wrj8(((10 + 7) ^ (759 ^ 759)), 5));
                }
                else
                {
                    volatile int64_t j_grn6l72x = ((j_gjjcndpq * (0 + 2)) + (1 + 0));
                }
                j_76zh2lsi = ((4 + 5) ^ (7502 ^ 7502));
                break;
            case 9:
                static volatile int64_t j_g3h3jvgx = (3550 + 36843);
                if ((((j_g3h3jvgx * j_g3h3jvgx) + j_g3h3jvgx) >= 0))
                {
                    (void)printf("%d\n", j_vls2wrj8((52 + 48), 10));
                }
                else
                {
                    volatile int64_t j_rae6r2fb = ((j_g3h3jvgx * 2) + (1 + 0));
                }
                j_76zh2lsi = 10;
                break;
            case 10:
                (void)printf("%s\n", j_dc_142());
                (void)printf("%s\n", j_t8lvogp4((0 + 2)) ? j_dc_143() : j_dc_144());
                (void)printf("%s\n", j_t8lvogp4((15 + 2)) ? j_dc_145() : j_dc_146());
                (void)printf("%s\n", j_t8lvogp4(((6 + 12) ^ (7024 ^ 7024))) ? j_dc_147() : j_dc_148());
                (void)printf("%s\n", j_t8lvogp4((4 + 93)) ? j_dc_149() : j_dc_150());
                (void)printf("%s\n", j_dc_151());
                for (int32_t j_qo32bb5q = (0 + 2); (j_qo32bb5q <= ((2 + 28) ^ (5827 ^ 5827))); j_qo32bb5q = (j_qo32bb5q + 1))
                {
                    if (j_t8lvogp4(j_qo32bb5q))
                    {
                        (void)printf("%d\n", j_qo32bb5q);
                    }
                }
                j_76zh2lsi = 11;
                break;
            case 11:
                static volatile int64_t j_9zf361hb = 72497;
                if ((((j_9zf361hb * j_9zf361hb) + j_9zf361hb) >= 0))
                {
                    (void)printf("%s\n", j_dc_152());
                }
                else
                {
                    volatile int64_t j_s8kz4vi9 = ((j_9zf361hb * 2) + 1);
                }
                j_76zh2lsi = 12;
                break;
            case 12:
                (void)printf("%d\n", j_vxxehlw0(((1 + 0) ^ (4975 ^ 4975))));
                static volatile int64_t j_7v7plshw = ((35814 + 57239) ^ (2882 ^ 2882));
                if ((((j_7v7plshw * j_7v7plshw) + j_7v7plshw) >= (0 + 0)))
                {
                    (void)printf("%d\n", j_vxxehlw0(27));
                }
                else
                {
                    volatile int64_t j_u3gu1f94 = ((j_7v7plshw * 2) + (1 + 0));
                }
                j_76zh2lsi = ((3 + 10) ^ (4502 ^ 4502));
                break;
            case 13:
                (void)printf("%d\n", j_vxxehlw0((3 + 3)));
                (void)printf("%s\n", j_dc_153());
                static volatile int64_t j_ofao25xe = ((1348 + 539) ^ (7363 ^ 7363));
                if ((((j_ofao25xe * j_ofao25xe) + j_ofao25xe) >= (0 + 0)))
                {
                    (void)printf("%d\n", j_m3tuz7o1(0));
                }
                else
                {
                    volatile int64_t j_xj6ndiho = ((j_ofao25xe * 2) + ((1 + 0) ^ (3148 ^ 3148)));
                }
                j_76zh2lsi = ((1 + 13) ^ (7958 ^ 7958));
                break;
            case 14:
                (void)printf("%d\n", j_m3tuz7o1(((8905 + 3440) ^ (8870 ^ 8870))));
                (void)printf("%d\n", j_m3tuz7o1(((929 + 70) ^ (7986 ^ 7986))));
                static volatile int64_t j_ffqn8op7 = 53282;
                if ((((j_ffqn8op7 * j_ffqn8op7) + j_ffqn8op7) >= 0))
                {
                    (void)printf("%s\n", j_dc_154());
                }
                else
                {
                    volatile int64_t j_tfol4141 = ((j_ffqn8op7 * 2) + (0 + 1));
                }
                j_76zh2lsi = 15;
                break;
            case 15:
                (void)printf("%d\n", j_dwwcl9v0(((9697 + 2648) ^ (439 ^ 439))));
                static volatile int64_t j_pvwnb34a = ((15646 + 11799) ^ (8497 ^ 8497));
                if ((((j_pvwnb34a * j_pvwnb34a) + j_pvwnb34a) >= ((0 + 0) ^ (9524 ^ 9524))))
                {
                    (void)printf("%d\n", j_dwwcl9v0(-(((114 + 9) ^ (8139 ^ 8139)))));
                }
                else
                {
                    volatile int64_t j_liko43bd = ((j_pvwnb34a * ((2 + 0) ^ (1512 ^ 1512))) + 1);
                }
                j_76zh2lsi = ((5 + 11) ^ (4308 ^ 4308));
                break;
            case 16:
                (void)printf("%d\n", j_dwwcl9v0(7));
                (void)printf("%s\n", j_dc_155());
                static volatile int64_t j_tc75tvri = 62587;
                if ((((j_tc75tvri * j_tc75tvri) + j_tc75tvri) >= ((0 + 0) ^ (8871 ^ 8871))))
                {
                    (void)printf("%d\n", j_u1jd8trj(((0 + 2) ^ (4788 ^ 4788)), 10));
                }
                else
                {
                    volatile int64_t j_bujcm0h3 = ((j_tc75tvri * (2 + 0)) + ((1 + 0) ^ (6450 ^ 6450)));
                }
                j_76zh2lsi = 17;
                break;
            case 17:
                (void)printf("%d\n", j_u1jd8trj(((3 + 0) ^ (4828 ^ 4828)), 3));
                (void)printf("%d\n", j_u1jd8trj(5, ((0 + 0) ^ (2782 ^ 2782))));
                (void)printf("%s\n", j_dc_156());
                (void)printf("%d\n", j_w6mesi0m((2 + 1), 9, ((0 + 6) ^ (3660 ^ 3660))));
                static volatile int64_t j_fn1iksnr = 55583;
                if ((((j_fn1iksnr * j_fn1iksnr) + j_fn1iksnr) >= ((0 + 0) ^ (9695 ^ 9695))))
                {
                    (void)printf("%d\n", j_gutsi31n(3, (7 + 2), 6));
                }
                else
                {
                    volatile int64_t j_56c7eycx = ((j_fn1iksnr * 2) + ((0 + 1) ^ (2750 ^ 2750)));
                }
                j_76zh2lsi = (4 + 14);
                break;
            case 18:
                static volatile int64_t j_5w4kujpr = ((6583 + 26389) ^ (9081 ^ 9081));
                if ((((j_5w4kujpr * j_5w4kujpr) + j_5w4kujpr) >= 0))
                {
                    (void)printf("%d\n", j_w6mesi0m(-(5), -(1), -(3)));
                }
                else
                {
                    volatile int64_t j_14vod2s2 = ((j_5w4kujpr * (2 + 0)) + (1 + 0));
                }
                j_76zh2lsi = ((18 + 1) ^ (5356 ^ 5356));
                break;
            case 19:
                static volatile int64_t j_1wb4ebz5 = 97722;
                if ((((j_1wb4ebz5 * j_1wb4ebz5) + j_1wb4ebz5) >= 0))
                {
                    (void)printf("%s\n", j_dc_157());
                }
                else
                {
                    volatile int64_t j_xdco6bu7 = ((j_1wb4ebz5 * ((2 + 0) ^ (3009 ^ 3009))) + (0 + 1));
                }
                j_76zh2lsi = 20;
                break;
            case 20:
                (void)printf("%s\n", j_dk9e63to(121) ? j_dc_158() : j_dc_159());
                (void)printf("%s\n", j_dk9e63to(12321) ? j_dc_160() : j_dc_161());
                (void)printf("%s\n", j_dk9e63to(123) ? j_dc_162() : j_dc_163());
                j_76zh2lsi = -1;
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (6171 ^ 6171));
}
static int32_t j_tr_bib5dw(void) { return j_tr_w8kitx(); }
static int32_t j_tr_zyw4k4(void) { return j_tr_bib5dw(); }
int32_t main(void) { return j_tr_zyw4k4(); }

