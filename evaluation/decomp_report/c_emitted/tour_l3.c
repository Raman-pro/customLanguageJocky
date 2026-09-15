// JOCKY build 6C17147E0965930B seed=12345 date=2026-09-03 05:00:01
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
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ (2 + 33);
    j_rb[(0 + 16)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x22, 0x23, 0x20, 0x21, 0x26, 0x27, 0x24, 0x25, 0x2A, 0x2B, 0x73, 0x70, 0x71, 0x76, 0x77, 0x74};
static const char* j_dc_1(void) {
    static char j_rb[((4 + 13) ^ (7510 ^ 7510))];
    for (int j_i = ((0 + 0) ^ (6065 ^ 6065)); j_i < 16; j_i++) j_rb[j_i] = j_enc_1[j_i] ^ ((16 + 2) ^ (5077 ^ 5077));
    j_rb[(14 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0xBA, 0xAA};
static const char* j_dc_2(void) {
    static char j_rb[(1 + 2)];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_2[j_i] ^ (190 + 10);
    j_rb[(1 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x58, 0x4D};
static const char* j_dc_3(void) {
    static char j_rb[3];
    for (int j_i = (0 + 0); j_i < (1 + 1); j_i++) j_rb[j_i] = j_enc_3[j_i] ^ ((34 + 13) ^ (6900 ^ 6900));
    j_rb[((0 + 2) ^ (366 ^ 366))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0xDC, 0x83, 0x81, 0x9C, 0x90};
static const char* j_dc_4(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ (206 + 37);
    j_rb[((3 + 2) ^ (1874 ^ 1874))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xDB};
static const char* j_dc_5(void) {
    static char j_rb[((2 + 0) ^ (6385 ^ 6385))];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ 169;
    j_rb[((1 + 0) ^ (3337 ^ 3337))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x64};
static const char* j_dc_6(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < (0 + 1); j_i++) j_rb[j_i] = j_enc_6[j_i] ^ 110;
    j_rb[1] = ((0 + 0) ^ (317 ^ 317));
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x8E};
static const char* j_dc_7(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < (0 + 1); j_i++) j_rb[j_i] = j_enc_7[j_i] ^ (201 + 51);
    j_rb[((0 + 1) ^ (3172 ^ 3172))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0x5F};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < (0 + 1); j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 96;
    j_rb[(0 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0xDD, 0xD8, 0xC2, 0xC5, 0xD4, 0xDF};
static const char* j_dc_9(void) {
    static char j_rb[7];
    for (int j_i = (0 + 0); j_i < ((1 + 5) ^ (8315 ^ 8315)); j_i++) j_rb[j_i] = j_enc_9[j_i] ^ 145;
    j_rb[(0 + 6)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0x71, 0x67, 0x60, 0x75, 0x76, 0x78, 0x7D, 0x67, 0x7C, 0x71, 0x70};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_10[j_i] ^ 52;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0x82, 0x8D, 0x8E, 0x92, 0x84, 0x9E, 0x96, 0x80, 0x88, 0x95};
static const char* j_dc_11(void) {
    static char j_rb[((2 + 9) ^ (3233 ^ 3233))];
    for (int j_i = 0; j_i < 10; j_i++) j_rb[j_i] = j_enc_11[j_i] ^ 193;
    j_rb[10] = ((0 + 0) ^ (7904 ^ 7904));
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0x36, 0x2B, 0x2F, 0x27, 0x3D, 0x35, 0x23, 0x2B, 0x36};
static const char* j_dc_12(void) {
    static char j_rb[(9 + 1)];
    for (int j_i = ((0 + 0) ^ (1747 ^ 1747)); j_i < ((6 + 3) ^ (9308 ^ 9308)); j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 98;
    j_rb[9] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x0B, 0x10, 0x0C, 0x01, 0x16};
static const char* j_dc_13(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (6326 ^ 6326)); j_i < ((2 + 3) ^ (2934 ^ 2934)); j_i++) j_rb[j_i] = j_enc_13[j_i] ^ (8 + 60);
    j_rb[(1 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x3C, 0x37, 0x26, 0x21, 0x26, 0x33, 0x26, 0x72, 0x7F, 0x33, 0x3C, 0x72, 0x7F, 0x22, 0x72, 0x26, 0x31, 0x22, 0x72, 0x60, 0x6C, 0x7D, 0x36, 0x37, 0x24, 0x7D, 0x3C, 0x27, 0x3E, 0x3E};
static const char* j_dc_14(void) {
    static char j_rb[31];
    for (int j_i = 0; j_i < (22 + 8); j_i++) j_rb[j_i] = j_enc_14[j_i] ^ ((23 + 59) ^ (3723 ^ 3723));
    j_rb[30] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0x92};
static const char* j_dc_15(void) {
    static char j_rb[(0 + 2)];
    for (int j_i = ((0 + 0) ^ (7225 ^ 7225)); j_i < ((0 + 1) ^ (9649 ^ 9649)); j_i++) j_rb[j_i] = j_enc_15[j_i] ^ ((118 + 106) ^ (7380 ^ 7380));
    j_rb[(1 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x80, 0x97, 0x84};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = ((0 + 0) ^ (2370 ^ 2370)); j_i < 3; j_i++) j_rb[j_i] = j_enc_16[j_i] ^ (236 + 8);
    j_rb[((0 + 3) ^ (3798 ^ 3798))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0xE6, 0xB9, 0xBB, 0xA6, 0xAA, 0xE6, 0xA7, 0xAC, 0xBD, 0xE6, 0xBD, 0xAA, 0xB9};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = ((0 + 0) ^ (5418 ^ 5418)); j_i < 13; j_i++) j_rb[j_i] = j_enc_17[j_i] ^ 201;
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0x04, 0x5B, 0x59, 0x44, 0x48, 0x04, 0x45, 0x4E, 0x5F, 0x04, 0x5F, 0x48, 0x5B, 0x1D};
static const char* j_dc_18(void) {
    static char j_rb[(8 + 7)];
    for (int j_i = (0 + 0); j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ (3 + 40);
    j_rb[(14 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0xA3, 0xA0, 0xA7, 0xA6, 0xB7};
static const char* j_dc_19(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_19[j_i] ^ ((4 + 231) ^ (9400 ^ 9400));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0x36, 0x35, 0x3D, 0x2B, 0x22};
static const char* j_dc_20(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((0 + 5) ^ (2786 ^ 2786)); j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 126;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x1A, 0x19, 0x11, 0x00, 0x0E};
static const char* j_dc_21(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (2300 ^ 2300)); j_i < ((5 + 0) ^ (2923 ^ 2923)); j_i++) j_rb[j_i] = j_enc_21[j_i] ^ 82;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0x29, 0x2A, 0x34, 0x3D};
static const char* j_dc_22(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = (0 + 0); j_i < ((3 + 1) ^ (9728 ^ 9728)); j_i++) j_rb[j_i] = j_enc_22[j_i] ^ 97;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0xF1, 0xE4};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = (0 + 0); j_i < ((2 + 0) ^ (4582 ^ 4582)); j_i++) j_rb[j_i] = j_enc_23[j_i] ^ ((110 + 24) ^ (7984 ^ 7984));
    j_rb[((1 + 1) ^ (7092 ^ 7092))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0x9F, 0x99, 0x9E, 0x8E};
static const char* j_dc_24(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (8020 ^ 8020)); j_i < 4; j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 235;
    j_rb[(2 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0xC9, 0xCE, 0xC3, 0xDC, 0xCA};
static const char* j_dc_25(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = (0 + 0); j_i < (4 + 1); j_i++) j_rb[j_i] = j_enc_25[j_i] ^ ((159 + 16) ^ (1637 ^ 1637));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x64, 0x62, 0x65, 0x75};
static const char* j_dc_26(void) {
    static char j_rb[((2 + 3) ^ (8254 ^ 8254))];
    for (int j_i = ((0 + 0) ^ (6387 ^ 6387)); j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_26[j_i] ^ (14 + 2);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0xE5, 0xE2, 0xEF, 0xF0, 0xE6};
static const char* j_dc_27(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (6733 ^ 6733)); j_i < 5; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 131;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x80, 0x86, 0x81, 0x91};
static const char* j_dc_28(void) {
    static char j_rb[((5 + 0) ^ (2674 ^ 2674))];
    for (int j_i = 0; j_i < ((1 + 3) ^ (6256 ^ 6256)); j_i++) j_rb[j_i] = j_enc_28[j_i] ^ (196 + 48);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0x03, 0x04, 0x09, 0x16, 0x00};
static const char* j_dc_29(void) {
    static char j_rb[((4 + 2) ^ (7062 ^ 7062))];
    for (int j_i = 0; j_i < (4 + 1); j_i++) j_rb[j_i] = j_enc_29[j_i] ^ (85 + 16);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0x80, 0x86, 0x81, 0x91};
static const char* j_dc_30(void) {
    static char j_rb[((1 + 4) ^ (4902 ^ 4902))];
    for (int j_i = 0; j_i < ((2 + 2) ^ (3261 ^ 3261)); j_i++) j_rb[j_i] = j_enc_30[j_i] ^ (187 + 57);
    j_rb[((0 + 4) ^ (3801 ^ 3801))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0x88, 0x8F, 0x82, 0x9D, 0x8B};
static const char* j_dc_31(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((5 + 0) ^ (8083 ^ 8083)); j_i++) j_rb[j_i] = j_enc_31[j_i] ^ ((66 + 172) ^ (4399 ^ 4399));
    j_rb[5] = ((0 + 0) ^ (2124 ^ 2124));
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0x59, 0x5F, 0x58, 0x48};
static const char* j_dc_32(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = 0; j_i < ((0 + 4) ^ (5364 ^ 5364)); j_i++) j_rb[j_i] = j_enc_32[j_i] ^ ((23 + 22) ^ (4089 ^ 4089));
    j_rb[((4 + 0) ^ (528 ^ 528))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0xA7, 0xA0, 0xAD, 0xB2, 0xA4};
static const char* j_dc_33(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_33[j_i] ^ 193;
    j_rb[((2 + 3) ^ (905 ^ 905))] = ((0 + 0) ^ (7901 ^ 7901));
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x6E, 0x68, 0x6F, 0x7F};
static const char* j_dc_34(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = (0 + 0); j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_34[j_i] ^ ((16 + 10) ^ (6716 ^ 6716));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0xE2, 0xE5, 0xE8, 0xF7, 0xE1};
static const char* j_dc_35(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 132;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0xA6, 0xA0, 0xA7, 0xB7};
static const char* j_dc_36(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((2 + 2) ^ (2354 ^ 2354)); j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 210;
    j_rb[4] = ((0 + 0) ^ (937 ^ 937));
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0xA2, 0xA5, 0xA8, 0xB7, 0xA1};
static const char* j_dc_37(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = (0 + 0); j_i < ((4 + 1) ^ (4736 ^ 4736)); j_i++) j_rb[j_i] = j_enc_37[j_i] ^ ((52 + 144) ^ (7406 ^ 7406));
    j_rb[(4 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0xBB, 0xBD, 0xBA, 0xAA};
static const char* j_dc_38(void) {
    static char j_rb[((4 + 1) ^ (4190 ^ 4190))];
    for (int j_i = (0 + 0); j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_38[j_i] ^ (126 + 81);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x11, 0x16, 0x1B, 0x04, 0x12};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_39[j_i] ^ (35 + 84);
    j_rb[(5 + 0)] = ((0 + 0) ^ (9438 ^ 9438));
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0xBA, 0xBC, 0xBB, 0xAB};
static const char* j_dc_40(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_40[j_i] ^ (128 + 78);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0xA2, 0xA5, 0xA8, 0xB7, 0xA1};
static const char* j_dc_41(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_41[j_i] ^ ((85 + 111) ^ (195 ^ 195));
    j_rb[5] = ((0 + 0) ^ (4840 ^ 4840));
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0x85, 0x83, 0x84, 0x94};
static const char* j_dc_42(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ (172 + 69);
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x4A, 0x4D, 0x40, 0x5F, 0x49};
static const char* j_dc_43(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((3 + 2) ^ (4248 ^ 4248)); j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 44;
    j_rb[(1 + 4)] = ((0 + 0) ^ (1871 ^ 1871));
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x42, 0x44, 0x43, 0x53};
static const char* j_dc_44(void) {
    static char j_rb[((0 + 5) ^ (2036 ^ 2036))];
    for (int j_i = ((0 + 0) ^ (9921 ^ 9921)); j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_44[j_i] ^ 54;
    j_rb[((2 + 2) ^ (8120 ^ 8120))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0xA2, 0xA5, 0xA8, 0xB7, 0xA1};
static const char* j_dc_45(void) {
    static char j_rb[((3 + 3) ^ (7576 ^ 7576))];
    for (int j_i = 0; j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_45[j_i] ^ 196;
    j_rb[5] = ((0 + 0) ^ (2377 ^ 2377));
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x52, 0x54, 0x53, 0x43};
static const char* j_dc_46(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_46[j_i] ^ ((15 + 23) ^ (8350 ^ 8350));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x3A, 0x3D, 0x30, 0x2F, 0x39};
static const char* j_dc_47(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (7345 ^ 7345)); j_i < ((5 + 0) ^ (9385 ^ 9385)); j_i++) j_rb[j_i] = j_enc_47[j_i] ^ (24 + 68);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0xF8, 0xFE, 0xF9, 0xE9};
static const char* j_dc_48(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = ((0 + 0) ^ (8784 ^ 8784)); j_i < ((3 + 1) ^ (3748 ^ 3748)); j_i++) j_rb[j_i] = j_enc_48[j_i] ^ ((116 + 24) ^ (3995 ^ 3995));
    j_rb[(3 + 1)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0x02, 0x05, 0x08, 0x17, 0x01};
static const char* j_dc_49(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = (0 + 0); j_i < ((1 + 4) ^ (592 ^ 592)); j_i++) j_rb[j_i] = j_enc_49[j_i] ^ ((41 + 59) ^ (1550 ^ 1550));
    j_rb[((2 + 3) ^ (5524 ^ 5524))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0x61, 0x67, 0x60, 0x70};
static const char* j_dc_50(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((4 + 0) ^ (1614 ^ 1614)); j_i++) j_rb[j_i] = j_enc_50[j_i] ^ 21;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0x43, 0x44, 0x49, 0x56, 0x40};
static const char* j_dc_51(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_51[j_i] ^ 37;
    j_rb[(5 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0x7E, 0x78, 0x7F, 0x6F};
static const char* j_dc_52(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_52[j_i] ^ (3 + 7);
    j_rb[(1 + 3)] = ((0 + 0) ^ (446 ^ 446));
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0x90, 0x97, 0x9A, 0x85, 0x93};
static const char* j_dc_53(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (4 + 1); j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 246;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0x5F, 0x59, 0x5E, 0x4E};
static const char* j_dc_54(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ 43;
    j_rb[((0 + 4) ^ (3471 ^ 3471))] = ((0 + 0) ^ (6608 ^ 6608));
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x3D, 0x3A, 0x37, 0x28, 0x3E};
static const char* j_dc_55(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = ((0 + 0) ^ (9969 ^ 9969)); j_i < ((0 + 5) ^ (562 ^ 562)); j_i++) j_rb[j_i] = j_enc_55[j_i] ^ ((30 + 61) ^ (6425 ^ 6425));
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0xF2, 0xF4, 0xF3, 0xE3};
static const char* j_dc_56(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = ((0 + 0) ^ (4343 ^ 4343)); j_i < 4; j_i++) j_rb[j_i] = j_enc_56[j_i] ^ 134;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0x3B, 0x3C, 0x31, 0x2E, 0x38};
static const char* j_dc_57(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_57[j_i] ^ ((76 + 17) ^ (9574 ^ 9574));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0x7B, 0x7D, 0x7A, 0x6A};
static const char* j_dc_58(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 15;
    j_rb[4] = ((0 + 0) ^ (3244 ^ 3244));
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0xBB, 0xBC, 0xB1, 0xAE, 0xB8};
static const char* j_dc_59(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (3 + 2); j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 221;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0xF9, 0xFF, 0xF8, 0xE8};
static const char* j_dc_60(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = ((0 + 0) ^ (8724 ^ 8724)); j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_60[j_i] ^ 141;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_61[] = {0x7C, 0x7B, 0x76, 0x69, 0x7F};
static const char* j_dc_61(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_61[j_i] ^ 26;
    j_rb[(5 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_62[] = {0xC4, 0xC2, 0xC5, 0xD5};
static const char* j_dc_62(void) {
    static char j_rb[((4 + 1) ^ (7330 ^ 7330))];
    for (int j_i = 0; j_i < ((2 + 2) ^ (255 ^ 255)); j_i++) j_rb[j_i] = j_enc_62[j_i] ^ 176;
    j_rb[(1 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_63[] = {0xBD, 0xBA, 0xB7, 0xA8, 0xBE};
static const char* j_dc_63(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_63[j_i] ^ 219;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_64[] = {0xD1, 0xD7, 0xD0, 0xC0};
static const char* j_dc_64(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_64[j_i] ^ ((134 + 31) ^ (1566 ^ 1566));
    j_rb[4] = ((0 + 0) ^ (7843 ^ 7843));
    return j_rb;
}

static const volatile uint8_t j_enc_65[] = {0x4C, 0x4B, 0x46, 0x59, 0x4F};
static const char* j_dc_65(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((1 + 4) ^ (9048 ^ 9048)); j_i++) j_rb[j_i] = j_enc_65[j_i] ^ (31 + 11);
    j_rb[5] = ((0 + 0) ^ (5652 ^ 5652));
    return j_rb;
}

static const volatile uint8_t j_enc_66[] = {0xF3, 0xF5, 0xF2, 0xE2};
static const char* j_dc_66(void) {
    static char j_rb[((5 + 0) ^ (2815 ^ 2815))];
    for (int j_i = 0; j_i < ((3 + 1) ^ (7308 ^ 7308)); j_i++) j_rb[j_i] = j_enc_66[j_i] ^ 135;
    j_rb[((0 + 4) ^ (9830 ^ 9830))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_67[] = {0x1F, 0x18, 0x15, 0x0A, 0x1C};
static const char* j_dc_67(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (5450 ^ 5450)); j_i < 5; j_i++) j_rb[j_i] = j_enc_67[j_i] ^ ((7 + 114) ^ (495 ^ 495));
    j_rb[((2 + 3) ^ (3268 ^ 3268))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_68[] = {0x87, 0x81, 0x86, 0x96};
static const char* j_dc_68(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_68[j_i] ^ 243;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_69[] = {0xC7, 0xC0, 0xCD, 0xD2, 0xC4};
static const char* j_dc_69(void) {
    static char j_rb[((4 + 2) ^ (6662 ^ 6662))];
    for (int j_i = 0; j_i < ((1 + 4) ^ (875 ^ 875)); j_i++) j_rb[j_i] = j_enc_69[j_i] ^ 161;
    j_rb[((4 + 1) ^ (9004 ^ 9004))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_70[] = {0x2B, 0x2D, 0x2A, 0x3A};
static const char* j_dc_70(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = ((0 + 0) ^ (1766 ^ 1766)); j_i < 4; j_i++) j_rb[j_i] = j_enc_70[j_i] ^ 95;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_71[] = {0x43, 0x44, 0x49, 0x56, 0x40};
static const char* j_dc_71(void) {
    static char j_rb[((1 + 5) ^ (6087 ^ 6087))];
    for (int j_i = 0; j_i < ((0 + 5) ^ (4303 ^ 4303)); j_i++) j_rb[j_i] = j_enc_71[j_i] ^ 37;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_72[] = {0x13, 0x15, 0x12, 0x02};
static const char* j_dc_72(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_72[j_i] ^ 103;
    j_rb[(4 + 0)] = ((0 + 0) ^ (5774 ^ 5774));
    return j_rb;
}

static const volatile uint8_t j_enc_73[] = {0x04, 0x03, 0x0E, 0x11, 0x07};
static const char* j_dc_73(void) {
    static char j_rb[((6 + 0) ^ (8984 ^ 8984))];
    for (int j_i = 0; j_i < ((2 + 3) ^ (5065 ^ 5065)); j_i++) j_rb[j_i] = j_enc_73[j_i] ^ (72 + 26);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_74[] = {0xC4, 0xC2, 0xC5, 0xD5};
static const char* j_dc_74(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_74[j_i] ^ (49 + 127);
    j_rb[((1 + 3) ^ (3259 ^ 3259))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_75[] = {0xD7, 0xD0, 0xDD, 0xC2, 0xD4};
static const char* j_dc_75(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_75[j_i] ^ 177;
    j_rb[((0 + 5) ^ (2549 ^ 2549))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_76[] = {0xBA, 0xBC, 0xBB, 0xAB};
static const char* j_dc_76(void) {
    static char j_rb[((4 + 1) ^ (7872 ^ 7872))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_76[j_i] ^ ((29 + 177) ^ (4782 ^ 4782));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_77[] = {0x76, 0x71, 0x7C, 0x63, 0x75};
static const char* j_dc_77(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = 0; j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_77[j_i] ^ (0 + 16);
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_78[] = {0x03, 0x05, 0x02, 0x12};
static const char* j_dc_78(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_78[j_i] ^ 119;
    j_rb[4] = ((0 + 0) ^ (8902 ^ 8902));
    return j_rb;
}

static const volatile uint8_t j_enc_79[] = {0xB5, 0xB2, 0xBF, 0xA0, 0xB6};
static const char* j_dc_79(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_79[j_i] ^ ((53 + 158) ^ (1154 ^ 1154));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_80[] = {0x22, 0x24, 0x23, 0x33};
static const char* j_dc_80(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_80[j_i] ^ ((30 + 56) ^ (6545 ^ 6545));
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_81[] = {0x99, 0x9E, 0x93, 0x8C, 0x9A};
static const char* j_dc_81(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_81[j_i] ^ 255;
    j_rb[(2 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_82[] = {0x19, 0x1F, 0x18, 0x08};
static const char* j_dc_82(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_82[j_i] ^ 109;
    j_rb[4] = ((0 + 0) ^ (3390 ^ 3390));
    return j_rb;
}

static const volatile uint8_t j_enc_83[] = {0xB8, 0xBF, 0xB2, 0xAD, 0xBB};
static const char* j_dc_83(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_83[j_i] ^ 222;
    j_rb[((5 + 0) ^ (5735 ^ 5735))] = ((0 + 0) ^ (9772 ^ 9772));
    return j_rb;
}

static const volatile uint8_t j_enc_84[] = {0x7B, 0x7D, 0x7A, 0x6A};
static const char* j_dc_84(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = (0 + 0); j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_84[j_i] ^ (2 + 13);
    j_rb[4] = ((0 + 0) ^ (7412 ^ 7412));
    return j_rb;
}

static const volatile uint8_t j_enc_85[] = {0xD9, 0xDE, 0xD3, 0xCC, 0xDA};
static const char* j_dc_85(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (8599 ^ 8599)); j_i < 5; j_i++) j_rb[j_i] = j_enc_85[j_i] ^ ((141 + 50) ^ (9852 ^ 9852));
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_86[] = {0x4E, 0x48, 0x4F, 0x5F};
static const char* j_dc_86(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = ((0 + 0) ^ (2676 ^ 2676)); j_i < 4; j_i++) j_rb[j_i] = j_enc_86[j_i] ^ (7 + 51);
    j_rb[((0 + 4) ^ (748 ^ 748))] = ((0 + 0) ^ (3261 ^ 3261));
    return j_rb;
}

static const volatile uint8_t j_enc_87[] = {0xFC, 0xFB, 0xF6, 0xE9, 0xFF};
static const char* j_dc_87(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_87[j_i] ^ (103 + 51);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_88[] = {0xF5, 0xF3, 0xF4, 0xE4};
static const char* j_dc_88(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (5976 ^ 5976)); j_i < ((2 + 2) ^ (4684 ^ 4684)); j_i++) j_rb[j_i] = j_enc_88[j_i] ^ ((102 + 27) ^ (1800 ^ 1800));
    j_rb[(3 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_89[] = {0x24, 0x23, 0x2E, 0x31, 0x27};
static const char* j_dc_89(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = (0 + 0); j_i < (4 + 1); j_i++) j_rb[j_i] = j_enc_89[j_i] ^ ((23 + 43) ^ (2260 ^ 2260));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_90[] = {0xE5, 0xE3, 0xE4, 0xF4};
static const char* j_dc_90(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = ((0 + 0) ^ (1814 ^ 1814)); j_i < 4; j_i++) j_rb[j_i] = j_enc_90[j_i] ^ (139 + 6);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_91[] = {0x02, 0x05, 0x08, 0x17, 0x01};
static const char* j_dc_91(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_91[j_i] ^ ((12 + 88) ^ (2968 ^ 2968));
    j_rb[((0 + 5) ^ (5054 ^ 5054))] = ((0 + 0) ^ (3362 ^ 3362));
    return j_rb;
}

static const volatile uint8_t j_enc_92[] = {0xF2, 0xF7, 0xE6, 0xFF, 0xE7};
static const char* j_dc_92(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = 0; j_i < ((0 + 5) ^ (1876 ^ 1876)); j_i++) j_rb[j_i] = j_enc_92[j_i] ^ (122 + 25);
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_93[] = {0x6C, 0x6A, 0x6D, 0x7D};
static const char* j_dc_93(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (7360 ^ 7360)); j_i < ((1 + 3) ^ (4091 ^ 4091)); j_i++) j_rb[j_i] = j_enc_93[j_i] ^ 24;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_94[] = {0xC8, 0xCF, 0xC2, 0xDD, 0xCB};
static const char* j_dc_94(void) {
    static char j_rb[((6 + 0) ^ (7763 ^ 7763))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_94[j_i] ^ 174;
    j_rb[(0 + 5)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_95[] = {0x3A, 0x3C, 0x3B, 0x2B};
static const char* j_dc_95(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((4 + 0) ^ (4344 ^ 4344)); j_i++) j_rb[j_i] = j_enc_95[j_i] ^ ((22 + 56) ^ (4306 ^ 4306));
    j_rb[((2 + 2) ^ (8023 ^ 8023))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_96[] = {0xE9, 0xEE, 0xE3, 0xFC, 0xEA};
static const char* j_dc_96(void) {
    static char j_rb[(5 + 1)];
    for (int j_i = 0; j_i < ((5 + 0) ^ (7532 ^ 7532)); j_i++) j_rb[j_i] = j_enc_96[j_i] ^ 143;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_97[] = {0x87, 0x81, 0x86, 0x96};
static const char* j_dc_97(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (6245 ^ 6245)); j_i < 4; j_i++) j_rb[j_i] = j_enc_97[j_i] ^ 243;
    j_rb[(1 + 3)] = ((0 + 0) ^ (6554 ^ 6554));
    return j_rb;
}

static const volatile uint8_t j_enc_98[] = {0x5B, 0x5C, 0x51, 0x4E, 0x58};
static const char* j_dc_98(void) {
    static char j_rb[((6 + 0) ^ (229 ^ 229))];
    for (int j_i = ((0 + 0) ^ (7846 ^ 7846)); j_i < 5; j_i++) j_rb[j_i] = j_enc_98[j_i] ^ (55 + 6);
    j_rb[5] = ((0 + 0) ^ (7739 ^ 7739));
    return j_rb;
}

static const volatile uint8_t j_enc_99[] = {0xCD, 0xC9, 0xCE, 0xCF, 0xD2};
static const char* j_dc_99(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((5 + 0) ^ (8552 ^ 8552)); j_i++) j_rb[j_i] = j_enc_99[j_i] ^ 160;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_100[] = {0xBB, 0xBB, 0xA6, 0xEF, 0xE8, 0xF2, 0xE3, 0xE1, 0xE3, 0xF4, 0xF5, 0xA6, 0xBB, 0xBB};
static const char* j_dc_100(void) {
    static char j_rb[15];
    for (int j_i = (0 + 0); j_i < 14; j_i++) j_rb[j_i] = j_enc_100[j_i] ^ ((126 + 8) ^ (8190 ^ 8190));
    j_rb[(12 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_101[] = {0x20, 0x20, 0x3D, 0x7F, 0x72, 0x72, 0x71, 0x78, 0x7C, 0x73, 0x6E, 0x3D, 0x20, 0x20};
static const char* j_dc_101(void) {
    static char j_rb[(0 + 15)];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_101[j_i] ^ (21 + 8);
    j_rb[(8 + 6)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_102[] = {0x91, 0x97, 0x90, 0x80};
static const char* j_dc_102(void) {
    static char j_rb[((0 + 5) ^ (4154 ^ 4154))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_102[j_i] ^ ((79 + 150) ^ (2429 ^ 2429));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_103[] = {0xC3, 0xC4, 0xC9, 0xD6, 0xC0};
static const char* j_dc_103(void) {
    static char j_rb[((6 + 0) ^ (845 ^ 845))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_103[j_i] ^ 165;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_104[] = {0xD1, 0xD7, 0xD0, 0xC0};
static const char* j_dc_104(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (6438 ^ 6438)); j_i < 4; j_i++) j_rb[j_i] = j_enc_104[j_i] ^ 165;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_105[] = {0xA7, 0xA0, 0xAD, 0xB2, 0xA4};
static const char* j_dc_105(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_105[j_i] ^ (82 + 111);
    j_rb[5] = ((0 + 0) ^ (712 ^ 712));
    return j_rb;
}

static const volatile uint8_t j_enc_106[] = {0xC5, 0xC5, 0xD8, 0x8B, 0x8C, 0x8A, 0x91, 0x96, 0x9F, 0x8B, 0xD8, 0xC5, 0xC5};
static const char* j_dc_106(void) {
    static char j_rb[(4 + 10)];
    for (int j_i = 0; j_i < ((11 + 2) ^ (2943 ^ 2943)); j_i++) j_rb[j_i] = j_enc_106[j_i] ^ (101 + 147);
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_107[] = {0x90, 0x9D, 0x94, 0x94, 0x97, 0xD4, 0xD8, 0x8F, 0x97, 0x8A, 0x94, 0x9C};
static const char* j_dc_107(void) {
    static char j_rb[(9 + 4)];
    for (int j_i = ((0 + 0) ^ (3659 ^ 3659)); j_i < ((6 + 6) ^ (358 ^ 358)); j_i++) j_rb[j_i] = j_enc_107[j_i] ^ ((87 + 161) ^ (8843 ^ 8843));
    j_rb[((10 + 2) ^ (253 ^ 253))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_108[] = {0x90, 0x86, 0x96, 0x94, 0x85, 0x90, 0x91, 0xCF, 0xD5, 0xA9, 0xD5, 0x97, 0x94, 0x96, 0x9E, 0x86, 0x99, 0x94, 0x86, 0x9D, 0xD9, 0xD5, 0xD7, 0xD5, 0x84, 0x80, 0x9A, 0x81, 0x90};
static const char* j_dc_108(void) {
    static char j_rb[30];
    for (int j_i = 0; j_i < 29; j_i++) j_rb[j_i] = j_enc_108[j_i] ^ 245;
    j_rb[29] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_109[] = {0x56, 0x53, 0x54, 0x5F, 0x0B, 0x30, 0x56, 0x53, 0x54, 0x5F, 0x08};
static const char* j_dc_109(void) {
    static char j_rb[12];
    for (int j_i = ((0 + 0) ^ (9973 ^ 9973)); j_i < 11; j_i++) j_rb[j_i] = j_enc_109[j_i] ^ 58;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_110[] = {0x04, 0x04, 0x19, 0x4F, 0x58, 0x4B, 0x50, 0x58, 0x5B, 0x55, 0x5C, 0x4A, 0x19, 0x04, 0x04};
static const char* j_dc_110(void) {
    static char j_rb[(8 + 8)];
    for (int j_i = ((0 + 0) ^ (1912 ^ 1912)); j_i < ((11 + 4) ^ (1693 ^ 1693)); j_i++) j_rb[j_i] = j_enc_110[j_i] ^ 57;
    j_rb[15] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_111[] = {0x83, 0x86, 0x8A, 0x82, 0x90};
static const char* j_dc_111(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_111[j_i] ^ 233;
    j_rb[((4 + 1) ^ (2395 ^ 2395))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_112[] = {0xEF, 0xE9, 0xEE, 0xFE};
static const char* j_dc_112(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_112[j_i] ^ (5 + 150);
    j_rb[(3 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_113[] = {0x48, 0x4F, 0x42, 0x5D, 0x4B};
static const char* j_dc_113(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < ((2 + 3) ^ (5515 ^ 5515)); j_i++) j_rb[j_i] = j_enc_113[j_i] ^ (22 + 24);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_114[] = {0x7D, 0x7B, 0x7C, 0x6C};
static const char* j_dc_114(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (7735 ^ 7735)); j_i < 4; j_i++) j_rb[j_i] = j_enc_114[j_i] ^ ((7 + 2) ^ (7130 ^ 7130));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_115[] = {0x69, 0x6E, 0x63, 0x7C, 0x6A};
static const char* j_dc_115(void) {
    static char j_rb[(3 + 3)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_115[j_i] ^ 15;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_116[] = {0xC9, 0xC9, 0xD4, 0x95, 0x86, 0x9D, 0x80, 0x9C, 0x99, 0x91, 0x80, 0x9D, 0x97, 0xD4, 0xC9, 0xC9};
static const char* j_dc_116(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_116[j_i] ^ (84 + 160);
    j_rb[16] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_117[] = {0x6B, 0x6B, 0x76, 0x35, 0x39, 0x3B, 0x26, 0x37, 0x24, 0x3F, 0x25, 0x39, 0x38, 0x25, 0x76, 0x6B, 0x6B};
static const char* j_dc_117(void) {
    static char j_rb[18];
    for (int j_i = 0; j_i < ((12 + 5) ^ (222 ^ 222)); j_i++) j_rb[j_i] = j_enc_117[j_i] ^ ((18 + 68) ^ (8694 ^ 8694));
    j_rb[17] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_118[] = {0xC1, 0xC7, 0xC0, 0xD0};
static const char* j_dc_118(void) {
    static char j_rb[((5 + 0) ^ (512 ^ 512))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_118[j_i] ^ 181;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_119[] = {0xA7, 0xA0, 0xAD, 0xB2, 0xA4};
static const char* j_dc_119(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_119[j_i] ^ 193;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_120[] = {0x66, 0x60, 0x67, 0x77};
static const char* j_dc_120(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_120[j_i] ^ (7 + 11);
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_121[] = {0x69, 0x6E, 0x63, 0x7C, 0x6A};
static const char* j_dc_121(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_121[j_i] ^ 15;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_122[] = {0x84, 0x82, 0x85, 0x95};
static const char* j_dc_122(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_122[j_i] ^ 240;
    j_rb[((3 + 1) ^ (4006 ^ 4006))] = ((0 + 0) ^ (735 ^ 735));
    return j_rb;
}

static const volatile uint8_t j_enc_123[] = {0xF6, 0xF1, 0xFC, 0xE3, 0xF5};
static const char* j_dc_123(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_123[j_i] ^ 144;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_124[] = {0x5E, 0x58, 0x5F, 0x4F};
static const char* j_dc_124(void) {
    static char j_rb[((0 + 5) ^ (1399 ^ 1399))];
    for (int j_i = 0; j_i < ((0 + 4) ^ (5248 ^ 5248)); j_i++) j_rb[j_i] = j_enc_124[j_i] ^ 42;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_125[] = {0x90, 0x97, 0x9A, 0x85, 0x93};
static const char* j_dc_125(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((5 + 0) ^ (1267 ^ 1267)); j_i++) j_rb[j_i] = j_enc_125[j_i] ^ 246;
    j_rb[(2 + 3)] = ((0 + 0) ^ (5953 ^ 5953));
    return j_rb;
}

static const volatile uint8_t j_enc_126[] = {0x7F, 0x79, 0x7E, 0x6E};
static const char* j_dc_126(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = 0; j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_126[j_i] ^ (10 + 1);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_127[] = {0xA5, 0xA2, 0xAF, 0xB0, 0xA6};
static const char* j_dc_127(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_127[j_i] ^ 195;
    j_rb[5] = ((0 + 0) ^ (8452 ^ 8452));
    return j_rb;
}

static const volatile uint8_t j_enc_128[] = {0x64, 0x62, 0x65, 0x75};
static const char* j_dc_128(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((0 + 4) ^ (6203 ^ 6203)); j_i++) j_rb[j_i] = j_enc_128[j_i] ^ 16;
    j_rb[((0 + 4) ^ (4968 ^ 4968))] = ((0 + 0) ^ (454 ^ 454));
    return j_rb;
}

static const volatile uint8_t j_enc_129[] = {0x59, 0x5E, 0x53, 0x4C, 0x5A};
static const char* j_dc_129(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = ((0 + 0) ^ (9585 ^ 9585)); j_i < 5; j_i++) j_rb[j_i] = j_enc_129[j_i] ^ 63;
    j_rb[(4 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_130[] = {0xCE, 0xCE, 0xD3, 0x9F, 0x9C, 0x94, 0x9A, 0x90, 0xD3, 0xCE, 0xCE};
static const char* j_dc_130(void) {
    static char j_rb[(3 + 9)];
    for (int j_i = (0 + 0); j_i < 11; j_i++) j_rb[j_i] = j_enc_130[j_i] ^ 243;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_131[] = {0x8C, 0x8A, 0x8D, 0x9D};
static const char* j_dc_131(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_131[j_i] ^ ((223 + 25) ^ (6147 ^ 6147));
    j_rb[4] = ((0 + 0) ^ (8137 ^ 8137));
    return j_rb;
}

static const volatile uint8_t j_enc_132[] = {0xEF, 0xE8, 0xE5, 0xFA, 0xEC};
static const char* j_dc_132(void) {
    static char j_rb[((4 + 2) ^ (5718 ^ 5718))];
    for (int j_i = ((0 + 0) ^ (2970 ^ 2970)); j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_132[j_i] ^ 137;
    j_rb[(1 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_133[] = {0x3F, 0x39, 0x3E, 0x2E};
static const char* j_dc_133(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_133[j_i] ^ 75;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_134[] = {0x85, 0x82, 0x8F, 0x90, 0x86};
static const char* j_dc_134(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_134[j_i] ^ 227;
    j_rb[(2 + 3)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_135[] = {0x86, 0x80, 0x87, 0x97};
static const char* j_dc_135(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((0 + 4) ^ (6971 ^ 6971)); j_i++) j_rb[j_i] = j_enc_135[j_i] ^ 242;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_136[] = {0x8F, 0x88, 0x85, 0x9A, 0x8C};
static const char* j_dc_136(void) {
    static char j_rb[((6 + 0) ^ (1327 ^ 1327))];
    for (int j_i = ((0 + 0) ^ (8996 ^ 8996)); j_i < ((1 + 4) ^ (1205 ^ 1205)); j_i++) j_rb[j_i] = j_enc_136[j_i] ^ 233;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_137[] = {0x92, 0x94, 0x93, 0x83};
static const char* j_dc_137(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_137[j_i] ^ 230;
    j_rb[(1 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_138[] = {0x7C, 0x7B, 0x76, 0x69, 0x7F};
static const char* j_dc_138(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_138[j_i] ^ ((3 + 23) ^ (4123 ^ 4123));
    j_rb[(3 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_139[] = {0x6B, 0x6D, 0x6A, 0x7A};
static const char* j_dc_139(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < ((0 + 4) ^ (7304 ^ 7304)); j_i++) j_rb[j_i] = j_enc_139[j_i] ^ 31;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_140[] = {0xC2, 0xC5, 0xC8, 0xD7, 0xC1};
static const char* j_dc_140(void) {
    static char j_rb[((5 + 1) ^ (5942 ^ 5942))];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_140[j_i] ^ ((125 + 39) ^ (8509 ^ 8509));
    j_rb[((5 + 0) ^ (7647 ^ 7647))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_141[] = {0xBF, 0xBF, 0xA2, 0xF1, 0xF6, 0xF0, 0xEB, 0xEC, 0xE5, 0xA2, 0xED, 0xF2, 0xE7, 0xF0, 0xE3, 0xF6, 0xEB, 0xED, 0xEC, 0xF1, 0xA2, 0xBF, 0xBF};
static const char* j_dc_141(void) {
    static char j_rb[((20 + 4) ^ (526 ^ 526))];
    for (int j_i = 0; j_i < ((7 + 16) ^ (3338 ^ 3338)); j_i++) j_rb[j_i] = j_enc_141[j_i] ^ 130;
    j_rb[(17 + 6)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_142[] = {0x98, 0x9D, 0x91, 0x99, 0x8B};
static const char* j_dc_142(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_142[j_i] ^ ((69 + 141) ^ (2068 ^ 2068));
    j_rb[5] = ((0 + 0) ^ (3464 ^ 3464));
    return j_rb;
}

static const volatile uint8_t j_enc_143[] = {0x84, 0x82, 0x85, 0x95};
static const char* j_dc_143(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_143[j_i] ^ (5 + 235);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_144[] = {0x7B, 0x7C, 0x71, 0x6E, 0x78};
static const char* j_dc_144(void) {
    static char j_rb[((4 + 2) ^ (5984 ^ 5984))];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_144[j_i] ^ 29;
    j_rb[5] = ((0 + 0) ^ (1452 ^ 1452));
    return j_rb;
}

static const volatile uint8_t j_enc_145[] = {0x27, 0x21, 0x26, 0x36};
static const char* j_dc_145(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (3028 ^ 3028)); j_i < ((2 + 2) ^ (9636 ^ 9636)); j_i++) j_rb[j_i] = j_enc_145[j_i] ^ 83;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_146[] = {0x96, 0x91, 0x9C, 0x83, 0x95};
static const char* j_dc_146(void) {
    static char j_rb[((1 + 5) ^ (8294 ^ 8294))];
    for (int j_i = 0; j_i < ((1 + 4) ^ (9652 ^ 9652)); j_i++) j_rb[j_i] = j_enc_146[j_i] ^ ((148 + 92) ^ (3537 ^ 3537));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_147[] = {0x90, 0x95, 0x99, 0x91, 0x83};
static const char* j_dc_147(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_147[j_i] ^ (75 + 143);
    j_rb[(3 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_148[] = {0xEF, 0xE9, 0xEE, 0xFE};
static const char* j_dc_148(void) {
    static char j_rb[((2 + 3) ^ (115 ^ 115))];
    for (int j_i = (0 + 0); j_i < ((1 + 3) ^ (8935 ^ 8935)); j_i++) j_rb[j_i] = j_enc_148[j_i] ^ ((94 + 61) ^ (3593 ^ 3593));
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_149[] = {0xC2, 0xC5, 0xC8, 0xD7, 0xC1};
static const char* j_dc_149(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_149[j_i] ^ 164;
    j_rb[(3 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_150[] = {0x15, 0x10, 0x1C, 0x14, 0x06};
static const char* j_dc_150(void) {
    static char j_rb[((3 + 3) ^ (7161 ^ 7161))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_150[j_i] ^ ((0 + 127) ^ (2514 ^ 2514));
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_151[] = {0x5D, 0x5B, 0x5C, 0x4C};
static const char* j_dc_151(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((0 + 4) ^ (9119 ^ 9119)); j_i++) j_rb[j_i] = j_enc_151[j_i] ^ (9 + 32);
    j_rb[(1 + 3)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_152[] = {0x6B, 0x6C, 0x61, 0x7E, 0x68};
static const char* j_dc_152(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (7310 ^ 7310)); j_i < 5; j_i++) j_rb[j_i] = j_enc_152[j_i] ^ 13;
    j_rb[(4 + 1)] = ((0 + 0) ^ (1862 ^ 1862));
    return j_rb;
}

static const volatile uint8_t j_enc_153[] = {0xD3, 0xD6, 0xDA, 0xD2, 0xC0};
static const char* j_dc_153(void) {
    static char j_rb[((6 + 0) ^ (8730 ^ 8730))];
    for (int j_i = ((0 + 0) ^ (1408 ^ 1408)); j_i < 5; j_i++) j_rb[j_i] = j_enc_153[j_i] ^ 153;
    j_rb[((5 + 0) ^ (847 ^ 847))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_154[] = {0x5E, 0x58, 0x5F, 0x4F};
static const char* j_dc_154(void) {
    static char j_rb[(0 + 5)];
    for (int j_i = ((0 + 0) ^ (962 ^ 962)); j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_154[j_i] ^ (4 + 38);
    j_rb[((3 + 1) ^ (8264 ^ 8264))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_155[] = {0x14, 0x13, 0x1E, 0x01, 0x17};
static const char* j_dc_155(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (8241 ^ 8241)); j_i < 5; j_i++) j_rb[j_i] = j_enc_155[j_i] ^ 114;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_156[] = {0xAC, 0xAC, 0xB1, 0xF8, 0xF7, 0xB1, 0xBE, 0xB1, 0xF4, 0xFD, 0xE2, 0xF4, 0xB1, 0xAC, 0xAC};
static const char* j_dc_156(void) {
    static char j_rb[16];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_156[j_i] ^ (145 + 0);
    j_rb[15] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_157[] = {0x31, 0x22, 0x31, 0x3A};
static const char* j_dc_157(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_157[j_i] ^ ((55 + 29) ^ (5056 ^ 5056));
    j_rb[(2 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_158[] = {0xAC, 0xA7, 0xA7};
static const char* j_dc_158(void) {
    static char j_rb[4];
    for (int j_i = (0 + 0); j_i < 3; j_i++) j_rb[j_i] = j_enc_158[j_i] ^ ((68 + 127) ^ (6665 ^ 6665));
    j_rb[((1 + 2) ^ (8263 ^ 8263))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_159[] = {0x32, 0x39, 0x37};
static const char* j_dc_159(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < (2 + 1); j_i++) j_rb[j_i] = j_enc_159[j_i] ^ (73 + 7);
    j_rb[3] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_160[] = {0xDC, 0xDB, 0xC9, 0xD8, 0xCF, 0x9D, 0xD4, 0xDB};
static const char* j_dc_160(void) {
    static char j_rb[9];
    for (int j_i = 0; j_i < (5 + 3); j_i++) j_rb[j_i] = j_enc_160[j_i] ^ 189;
    j_rb[8] = ((0 + 0) ^ (7152 ^ 7152));
    return j_rb;
}

static const volatile uint8_t j_enc_161[] = {0xD7, 0xD7, 0xCA, 0x9D, 0x82, 0x83, 0x86, 0x8F, 0xCA, 0xD7, 0xD7};
static const char* j_dc_161(void) {
    static char j_rb[12];
    for (int j_i = (0 + 0); j_i < (4 + 7); j_i++) j_rb[j_i] = j_enc_161[j_i] ^ 234;
    j_rb[11] = ((0 + 0) ^ (4491 ^ 4491));
    return j_rb;
}

static const volatile uint8_t j_enc_162[] = {0xA1, 0xA1, 0xBC, 0xFA, 0xF3, 0xEE, 0xBC, 0xA1, 0xA1};
static const char* j_dc_162(void) {
    static char j_rb[(3 + 7)];
    for (int j_i = (0 + 0); j_i < ((7 + 2) ^ (1047 ^ 1047)); j_i++) j_rb[j_i] = j_enc_162[j_i] ^ 156;
    j_rb[(0 + 9)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_163[] = {0x68, 0x68, 0x75, 0x34, 0x26, 0x26, 0x3C, 0x32, 0x3B, 0x38, 0x30, 0x3B, 0x21, 0x75, 0x68, 0x68};
static const char* j_dc_163(void) {
    static char j_rb[17];
    for (int j_i = ((0 + 0) ^ (3318 ^ 3318)); j_i < ((16 + 0) ^ (4539 ^ 4539)); j_i++) j_rb[j_i] = j_enc_163[j_i] ^ 85;
    j_rb[((1 + 15) ^ (8429 ^ 8429))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_164[] = {0xDD, 0xDD, 0xC0, 0x93, 0x88, 0x81, 0x84, 0x8F, 0x97, 0x89, 0x8E, 0x87, 0xC0, 0xDD, 0xDD};
static const char* j_dc_164(void) {
    static char j_rb[((9 + 7) ^ (3632 ^ 3632))];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_164[j_i] ^ 224;
    j_rb[15] = ((0 + 0) ^ (5757 ^ 5757));
    return j_rb;
}

static const volatile uint8_t j_enc_165[] = {0x37, 0x37, 0x2A, 0x6C, 0x7F, 0x64, 0x69, 0x7E, 0x63, 0x65, 0x64, 0x79, 0x2A, 0x37, 0x37};
static const char* j_dc_165(void) {
    static char j_rb[((12 + 4) ^ (2635 ^ 2635))];
    for (int j_i = (0 + 0); j_i < ((14 + 1) ^ (5319 ^ 5319)); j_i++) j_rb[j_i] = j_enc_165[j_i] ^ 10;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_166[] = {0xBC, 0xB1, 0xB8, 0xB8, 0xBB, 0xF4, 0xB2, 0xA6, 0xBB, 0xB9, 0xF4, 0xB5, 0xF4, 0xA2, 0xBB, 0xBD, 0xB0, 0xF4, 0xB2, 0xA1, 0xBA, 0xB7, 0xA0, 0xBD, 0xBB, 0xBA};
static const char* j_dc_166(void) {
    static char j_rb[27];
    for (int j_i = (0 + 0); j_i < ((19 + 7) ^ (6976 ^ 6976)); j_i++) j_rb[j_i] = j_enc_166[j_i] ^ 212;
    j_rb[((21 + 5) ^ (5497 ^ 5497))] = ((0 + 0) ^ (1427 ^ 1427));
    return j_rb;
}

static const volatile uint8_t j_enc_167[] = {0xBD, 0x98, 0x9D};
static const char* j_dc_167(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_167[j_i] ^ 252;
    j_rb[((1 + 2) ^ (890 ^ 890))] = ((0 + 0) ^ (9747 ^ 9747));
    return j_rb;
}

static const volatile uint8_t j_enc_168[] = {0x9C, 0x9C, 0x81, 0xCC, 0xD4, 0xD5, 0xD4, 0xC0, 0xCD, 0x81, 0xD3, 0xC4, 0xC2, 0xD4, 0xD3, 0xD2, 0xC8, 0xCE, 0xCF, 0x81, 0x9C, 0x9C};
static const char* j_dc_168(void) {
    static char j_rb[23];
    for (int j_i = ((0 + 0) ^ (4248 ^ 4248)); j_i < ((22 + 0) ^ (756 ^ 756)); j_i++) j_rb[j_i] = j_enc_168[j_i] ^ ((5 + 156) ^ (2750 ^ 2750));
    j_rb[((20 + 2) ^ (8228 ^ 8228))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_169[] = {0xBB, 0xBD, 0xBA, 0xAA};
static const char* j_dc_169(void) {
    static char j_rb[((0 + 5) ^ (562 ^ 562))];
    for (int j_i = ((0 + 0) ^ (7892 ^ 7892)); j_i < ((4 + 0) ^ (3747 ^ 3747)); j_i++) j_rb[j_i] = j_enc_169[j_i] ^ ((19 + 188) ^ (8681 ^ 8681));
    j_rb[(4 + 0)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_170[] = {0xDE, 0xD9, 0xD4, 0xCB, 0xDD};
static const char* j_dc_170(void) {
    static char j_rb[((1 + 5) ^ (9583 ^ 9583))];
    for (int j_i = (0 + 0); j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_170[j_i] ^ (8 + 176);
    j_rb[((1 + 4) ^ (3369 ^ 3369))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_171[] = {0xF5, 0xF3, 0xF4, 0xE4};
static const char* j_dc_171(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_171[j_i] ^ ((25 + 104) ^ (6072 ^ 6072));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_172[] = {0xCB, 0xCC, 0xC1, 0xDE, 0xC8};
static const char* j_dc_172(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_172[j_i] ^ 173;
    j_rb[((4 + 1) ^ (4892 ^ 4892))] = ((0 + 0) ^ (1156 ^ 1156));
    return j_rb;
}

static const volatile uint8_t j_enc_173[] = {0x67, 0x61, 0x66, 0x76};
static const char* j_dc_173(void) {
    static char j_rb[((0 + 5) ^ (1265 ^ 1265))];
    for (int j_i = (0 + 0); j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_173[j_i] ^ ((10 + 9) ^ (5983 ^ 5983));
    j_rb[(3 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_174[] = {0xC1, 0xC6, 0xCB, 0xD4, 0xC2};
static const char* j_dc_174(void) {
    static char j_rb[(3 + 3)];
    for (int j_i = ((0 + 0) ^ (4026 ^ 4026)); j_i < 5; j_i++) j_rb[j_i] = j_enc_174[j_i] ^ 167;
    j_rb[5] = ((0 + 0) ^ (2051 ^ 2051));
    return j_rb;
}

static const volatile uint8_t j_enc_175[] = {0x83, 0x83, 0x9E, 0xDD, 0xD1, 0xD3, 0xCE, 0xD1, 0xCD, 0xD7, 0xCA, 0xD7, 0xD1, 0xD0, 0x9E, 0x83, 0x83};
static const char* j_dc_175(void) {
    static char j_rb[((2 + 16) ^ (7353 ^ 7353))];
    for (int j_i = (0 + 0); j_i < 17; j_i++) j_rb[j_i] = j_enc_175[j_i] ^ 190;
    j_rb[(8 + 9)] = ((0 + 0) ^ (8978 ^ 8978));
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[65536];
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
                    out[o++] = j_dc_0()[c >> (2 + 2)];
                    out[o++] = j_dc_1()[c & 15];
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
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (long)(ms % 1000) * 1000000L;
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
    return access(path, F_OK) == 0;
#endif
}

static const char* j_fs_read(const char* path) {
    FILE* f = fopen(path, j_dc_2());
    if (!f) return "";
    size_t n = fread(j_buf, 1, J_BUF_CAP - 1, f);
    fclose(f);
    j_buf[n] = '\0';
    return j_buf;
}

static void j_fs_write(const char* path, const char* data) {
    FILE* f = fopen(path, j_dc_3());
    if (f) { fputs(data, f); fclose(f); }
}

static const char* j_fs_list(const char* dir) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = (0 + 1);
#if defined(_WIN32)
    char pattern[((799 + 225) ^ (3892 ^ 3892))];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[0] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[1024];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] == '.') continue;
            if (off > J_BUF_CAP - ((132 + 68) ^ (9743 ^ 9743))) break;
            if (!first) j_buf[off++] = ',';
            first = (0 + 0);
            char esc[(226 + 798)];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > ((0 + 0) ^ (168 ^ 168)) ? n : 0);
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_sys_process_list(void) {
    size_t off = 0;
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
                char name[((951 + 73) ^ (5633 ^ 5633))];
                size_t k = 0;
                for (size_t i = 0; pe.szExeFile[i] && k + ((1 + 0) ^ (8030 ^ 8030)) < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[((999 + 1049) ^ (5112 ^ 5112))];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > (0 + 0) ? n : 0);
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[8192];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = 0; i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - ((155 + 245) ^ (9363 ^ 9363))) break;
        char name[256];
        int len = proc_name(pid, name, sizeof name);
        if (len <= 0) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = (0 + 0);
        char esc[512];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : ((0 + 0) ^ (2763 ^ 2763)));
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[((0 + 0) ^ (7917 ^ 7917))] > '9') continue;
            int pid = atoi(de->d_name);
            char p[((35 + 29) ^ (7840 ^ 7840))], name[256];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - (232 + 168)) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[((211 + 301) ^ (2712 ^ 2712))];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > 0 ? n : ((0 + 0) ^ (2865 ^ 2865)));
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
    char line[512];
    int skip = 1;
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = 0; continue; }
        char laddr[((39 + 25) ^ (9940 ^ 9940))], raddr[((12 + 52) ^ (6049 ^ 6049))], st[16];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != 3) continue;
        if (*off > J_BUF_CAP - 300) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = 0;
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > (0 + 0) ? n : ((0 + 0) ^ (2620 ^ 2620)));
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = 1;
#if defined(_WIN32)
    ULONG sz = 0;
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, (0 + 0));
    char* t = (char*)malloc(sz ? sz : 1);
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, ((0 + 0) ^ (9977 ^ 9977))) == NO_ERROR) {
            for (DWORD i = ((0 + 0) ^ (5350 ^ 5350)); i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[64], ri[(37 + 27)];
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
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > (0 + 0) ? n : (0 + 0));
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[8], laddr[((2 + 62) ^ (5762 ^ 5762))], raddr[(1 + 63)], st[((28 + 4) ^ (1066 ^ 1066))];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == 4) {
                if (strncmp(proto, j_dc_16(), (3 + 0)) != 0) continue;
                if (off > J_BUF_CAP - ((23 + 277) ^ (9651 ^ 9651))) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
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
    size_t off = 0;
    j_buf[off++] = '[';
    int first = ((1 + 0) ^ (9181 ^ 9181));
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), 5) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + ((2 + 3) ^ (1968 ^ 1968)); }
    else if (strncmp(key, j_dc_20(), 5) == ((0 + 0) ^ (781 ^ 781))) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, j_dc_21(), 5) == 0) { root = HKEY_CLASSES_ROOT; sub = key + (2 + 3); }
    else if (strncmp(key, j_dc_22(), (1 + 3)) == 0) { root = HKEY_USERS; sub = key + 4; }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, ((0 + 0) ^ (7781 ^ 7781)), KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = ((0 + 0) ^ (3660 ^ 3660)); ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[512];
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
    unsigned long regions = ((0 + 0) ^ (8576 ^ 8576));
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < (58447 + 41553)) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : ((1 + 0) ^ (2295 ^ 2295)));
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

static volatile int32_t j_052rhh3g = 12438;
static volatile int32_t j_utsi31nd = 24323;

static int32_t j_4f7g6fui(int32_t j_zjsufqwi);
static int32_t j_t2hghb9f(int32_t j_oiwo6t0n, int32_t j_vls2wrj8);
static void j_m2p7e3pa(const char* j_doqql8pa);
static int32_t j_t8lvogp4(int32_t j_vxxehlw0);
static int32_t j_m3tuz7o1(int32_t j_vxxehlw0);
static bool j_dwwcl9v0(int32_t j_vxxehlw0);
static bool j_u1jd8trj(int32_t j_vxxehlw0);
static const char* j_gcfgd3i4(const char* j_eu3wz7tw, int32_t j_w6mesi0m);

static int32_t j_4f7g6fui(int32_t j_zjsufqwi)
{
    int32_t j_e63tox7h = 0;
    while ((j_e63tox7h != -1))
    {
        switch (j_e63tox7h)
        {
            case 0:
                static volatile int64_t j_gmqpdmt0 = (13164 + 40539);
                if ((((j_gmqpdmt0 * j_gmqpdmt0) + j_gmqpdmt0) < 0))
                {
                    volatile int64_t j_c8jewur5 = ((j_gmqpdmt0 * 85) + 703);
                    (void)printf("%s\n", ((0 + 0) ^ (5428 ^ 5428)) ? j_dc_24() : j_dc_25());
                }
                j_e63tox7h = ((0 + 1) ^ (6261 ^ 6261));
                break;
            case 1:
                static volatile int64_t j_468tmzoa = ((46602 + 27782) ^ (7774 ^ 7774));
                if ((((j_468tmzoa * (j_468tmzoa + 1)) % 2) == 1))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_26() : j_dc_27());
                }
                j_e63tox7h = (0 + 2);
                break;
            case 2:
                static volatile int64_t j_qo32bb5q = ((11630 + 4251) ^ (166 ^ 166));
                if ((((j_qo32bb5q * j_qo32bb5q) + j_qo32bb5q) < 0))
                {
                    volatile int64_t j_ifxsxp8l = ((j_qo32bb5q * 94) + ((408 + 473) ^ (3853 ^ 3853)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_28() : j_dc_29());
                }
                j_e63tox7h = 3;
                break;
            case 3:
                static volatile int64_t j_l9dl9lcd = ((10393 + 5327) ^ (5671 ^ 5671));
                if ((((j_l9dl9lcd * j_l9dl9lcd) + j_l9dl9lcd) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_30() : j_dc_31());
                }
                j_e63tox7h = 4;
                break;
            case 4:
                static volatile int64_t j_7m5fgot7 = 17713;
                if ((((j_7m5fgot7 * j_7m5fgot7) + j_7m5fgot7) < 0))
                {
                    volatile int64_t j_yn30xwb1 = ((j_7m5fgot7 * (5 + 0)) + ((458 + 255) ^ (6757 ^ 6757)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_32() : j_dc_33());
                }
                j_e63tox7h = (0 + 5);
                break;
            case 5:
                return (j_zjsufqwi * 2);
                break;
            case 6:
                static volatile int64_t j_kiietxma = (5629 + 4243);
                if ((((j_kiietxma * j_kiietxma) + j_kiietxma) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_34() : j_dc_35());
                }
                j_e63tox7h = -((1 + 0) ^ (9568 ^ 9568));
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_t2hghb9f(int32_t j_oiwo6t0n, int32_t j_vls2wrj8)
{
    int32_t j_v3huvf2v = ((0 + 0) ^ (1230 ^ 1230));
    while ((j_v3huvf2v != -1))
    {
        switch (j_v3huvf2v)
        {
            case 0:
                static volatile int64_t j_qb8n9rkr = ((21979 + 17370) ^ (3360 ^ 3360));
                static volatile int64_t j_fy0gpnl9 = (76387 + 17492);
                if ((((j_fy0gpnl9 * j_fy0gpnl9) + j_fy0gpnl9) < 0))
                {
                    volatile int64_t j_c1wchsa4 = ((j_fy0gpnl9 * ((0 + 2) ^ (2023 ^ 2023))) + (12 + 867));
                    (void)printf("%s\n", ((0 + 0) ^ (5566 ^ 5566)) ? j_dc_36() : j_dc_37());
                }
                j_v3huvf2v = 1;
                break;
            case 1:
                if ((((j_qb8n9rkr * j_qb8n9rkr) + j_qb8n9rkr) < 0))
                {
                    volatile int64_t j_lyd9q6x2 = ((j_qb8n9rkr * ((0 + 3) ^ (4889 ^ 4889))) + ((314 + 35) ^ (8617 ^ 8617)));
                    (void)printf("%s\n", 0 ? j_dc_38() : j_dc_39());
                }
                j_v3huvf2v = ((1 + 1) ^ (1785 ^ 1785));
                break;
            case 2:
                static volatile int64_t j_xsop1o4p = 31811;
                static volatile int64_t j_ney0af9f = 98926;
                if ((((j_ney0af9f * j_ney0af9f) + j_ney0af9f) < 0))
                {
                    volatile int64_t j_dj8cfjgn = ((j_ney0af9f * (82 + 6)) + 926);
                    (void)printf("%s\n", ((0 + 0) ^ (2605 ^ 2605)) ? j_dc_40() : j_dc_41());
                }
                j_v3huvf2v = 3;
                break;
            case 3:
                if ((((j_xsop1o4p * j_xsop1o4p) + j_xsop1o4p) < 0))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_42() : j_dc_43());
                }
                j_v3huvf2v = 4;
                break;
            case 4:
                return (j_oiwo6t0n + j_vls2wrj8);
                break;
            case 5:
                static volatile int64_t j_mbs50pn8 = 80177;
                if ((((j_mbs50pn8 * j_mbs50pn8) + j_mbs50pn8) < 0))
                {
                    volatile int64_t j_gzdn22af = ((j_mbs50pn8 * 29) + 177);
                    (void)printf("%s\n", 0 ? j_dc_44() : j_dc_45());
                }
                j_v3huvf2v = -((1 + 0) ^ (6414 ^ 6414));
                break;
            default:
                break;
        }
    }
    return 0;
}

static void j_m2p7e3pa(const char* j_doqql8pa)
{
    int32_t j_2ct6q877 = 0;
    while ((j_2ct6q877 != -(1 + 0)))
    {
        switch (j_2ct6q877)
        {
            case 0:
                static volatile int64_t j_f1hbv9t4 = (6693 + 71268);
                if ((((j_f1hbv9t4 * j_f1hbv9t4) + j_f1hbv9t4) < 0))
                {
                    volatile int64_t j_v19rzg9k = ((j_f1hbv9t4 * ((1 + 7) ^ (6210 ^ 6210))) + 961);
                    (void)printf("%s\n", ((0 + 0) ^ (9399 ^ 9399)) ? j_dc_46() : j_dc_47());
                }
                j_2ct6q877 = (1 + 0);
                break;
            case 1:
                static volatile int64_t j_kwyqhptu = ((52107 + 10943) ^ (1846 ^ 1846));
                if ((((j_kwyqhptu * j_kwyqhptu) + j_kwyqhptu) < 0))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (8125 ^ 8125)) ? j_dc_48() : j_dc_49());
                }
                j_2ct6q877 = (1 + 1);
                break;
            case 2:
                static volatile int64_t j_v0z664x0 = 59705;
                if ((((j_v0z664x0 * j_v0z664x0) + j_v0z664x0) < 0))
                {
                    volatile int64_t j_27a2qis4 = ((j_v0z664x0 * (31 + 9)) + 705);
                    (void)printf("%s\n", ((0 + 0) ^ (4553 ^ 4553)) ? j_dc_50() : j_dc_51());
                }
                j_2ct6q877 = ((2 + 1) ^ (2889 ^ 2889));
                break;
            case 3:
                static volatile int64_t j_zhoekmdo = 46563;
                if ((((j_zhoekmdo * j_zhoekmdo) + j_zhoekmdo) >= ((0 + 0) ^ (9824 ^ 9824))))
                {
                    (void)printf("%s\n", j_doqql8pa);
                }
                else
                {
                    volatile int64_t j_wkye35n7 = ((j_zhoekmdo * (2 + 0)) + 1);
                }
                j_2ct6q877 = 4;
                break;
            case 4:
                static volatile int64_t j_vyo8ezrt = 9886;
                static volatile int64_t j_nywn77f5 = 2697;
                if ((((j_nywn77f5 * j_nywn77f5) + j_nywn77f5) < (0 + 0)))
                {
                    volatile int64_t j_00zpd4o1 = ((j_nywn77f5 * ((33 + 25) ^ (8836 ^ 8836))) + ((564 + 133) ^ (449 ^ 449)));
                    (void)printf("%s\n", ((0 + 0) ^ (6928 ^ 6928)) ? j_dc_52() : j_dc_53());
                }
                j_2ct6q877 = ((1 + 4) ^ (8273 ^ 8273));
                break;
            case 5:
                if ((((j_vyo8ezrt * j_vyo8ezrt) + j_vyo8ezrt) < 0))
                {
                    volatile int64_t j_46wox3cs = ((j_vyo8ezrt * (70 + 5)) + ((91 + 795) ^ (1017 ^ 1017)));
                    (void)printf("%s\n", ((0 + 0) ^ (2476 ^ 2476)) ? j_dc_54() : j_dc_55());
                }
                j_2ct6q877 = -1;
                break;
            default:
                break;
        }
    }
}

static int32_t j_t8lvogp4(int32_t j_vxxehlw0)
{
    int32_t j_7yom7oru = ((0 + 0) ^ (4169 ^ 4169));
    while ((j_7yom7oru != -(1 + 0)))
    {
        switch (j_7yom7oru)
        {
            case 0:
                static volatile int64_t j_c4i39azk = ((7499 + 6092) ^ (2384 ^ 2384));
                if ((((j_c4i39azk * j_c4i39azk) + j_c4i39azk) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (2885 ^ 2885)) ? j_dc_56() : j_dc_57());
                }
                j_7yom7oru = (1 + 0);
                break;
            case 1:
                static volatile int64_t j_tr73225m = ((2029 + 1394) ^ (951 ^ 951));
                static volatile int64_t j_6lcv1ym4 = ((16971 + 13406) ^ (95 ^ 95));
                if ((((j_6lcv1ym4 * j_6lcv1ym4) + j_6lcv1ym4) < 0))
                {
                    volatile int64_t j_s1u5c2bw = ((j_6lcv1ym4 * (47 + 41)) + 377);
                    (void)printf("%s\n", 0 ? j_dc_58() : j_dc_59());
                }
                j_7yom7oru = (2 + 0);
                break;
            case 2:
                if ((((j_tr73225m * j_tr73225m) + j_tr73225m) < 0))
                {
                    volatile int64_t j_eexnkan3 = ((j_tr73225m * (15 + 80)) + ((107 + 316) ^ (3956 ^ 3956)));
                    (void)printf("%s\n", 0 ? j_dc_60() : j_dc_61());
                }
                j_7yom7oru = 3;
                break;
            case 3:
                static volatile int64_t j_r3lyvytq = 78682;
                if ((((j_r3lyvytq * j_r3lyvytq) + j_r3lyvytq) < 0))
                {
                    volatile int64_t j_qv6uminn = ((j_r3lyvytq * 20) + 682);
                    (void)printf("%s\n", (0 + 0) ? j_dc_62() : j_dc_63());
                }
                j_7yom7oru = 4;
                break;
            case 4:
                if ((j_vxxehlw0 <= 1))
                {
                    return ((1 + 0) ^ (6825 ^ 6825));
                }
                j_7yom7oru = 5;
                break;
            case 5:
                return (j_vxxehlw0 * j_t8lvogp4((j_vxxehlw0 - (0 + 1))));
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

static int32_t j_m3tuz7o1(int32_t j_vxxehlw0)
{
    int32_t j_2c53ign6 = ((0 + 0) ^ (5346 ^ 5346));
    while ((j_2c53ign6 != -(0 + 1)))
    {
        switch (j_2c53ign6)
        {
            case 0:
                if ((j_vxxehlw0 < 2))
                {
                    return j_vxxehlw0;
                }
                j_2c53ign6 = 1;
                break;
            case 1:
                static volatile int64_t j_9kqju9v1 = (14295 + 11363);
                static volatile int64_t j_0dnkds5g = 90894;
                if ((((j_0dnkds5g * j_0dnkds5g) + j_0dnkds5g) < ((0 + 0) ^ (9371 ^ 9371))))
                {
                    volatile int64_t j_6t4eaaox = ((j_0dnkds5g * 71) + 894);
                    (void)printf("%s\n", 0 ? j_dc_64() : j_dc_65());
                }
                j_2c53ign6 = 2;
                break;
            case 2:
                if ((((j_9kqju9v1 * j_9kqju9v1) + j_9kqju9v1) < (0 + 0)))
                {
                    volatile int64_t j_f8wwr90p = ((j_9kqju9v1 * 4) + ((291 + 367) ^ (9526 ^ 9526)));
                    (void)printf("%s\n", ((0 + 0) ^ (8331 ^ 8331)) ? j_dc_66() : j_dc_67());
                }
                j_2c53ign6 = 3;
                break;
            case 3:
                static volatile int64_t j_andim2q7 = 69803;
                if ((((j_andim2q7 * j_andim2q7) + j_andim2q7) < (0 + 0)))
                {
                    volatile int64_t j_ybligual = ((j_andim2q7 * (57 + 2)) + ((768 + 35) ^ (6040 ^ 6040)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_68() : j_dc_69());
                }
                j_2c53ign6 = 4;
                break;
            case 4:
                static volatile int64_t j_r5oqef5n = ((55377 + 24848) ^ (1492 ^ 1492));
                if ((((j_r5oqef5n * j_r5oqef5n) % 4) == 3))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (903 ^ 903)) ? j_dc_70() : j_dc_71());
                }
                j_2c53ign6 = (0 + 5);
                break;
            case 5:
                return (j_m3tuz7o1((j_vxxehlw0 - 1)) + j_m3tuz7o1((j_vxxehlw0 - 2)));
                break;
            case 6:
                static volatile int64_t j_2561o13g = 88147;
                if ((((j_2561o13g * j_2561o13g) + j_2561o13g) < 0))
                {
                    volatile int64_t j_45k0m0xl = ((j_2561o13g * 90) + ((63 + 84) ^ (8793 ^ 8793)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_72() : j_dc_73());
                }
                j_2c53ign6 = -((0 + 1) ^ (7190 ^ 7190));
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

static bool j_dwwcl9v0(int32_t j_vxxehlw0)
{
    int32_t j_3p7qt3hh = 0;
    while ((j_3p7qt3hh != -((0 + 1) ^ (4926 ^ 4926))))
    {
        switch (j_3p7qt3hh)
        {
            case 0:
                static volatile int64_t j_ey467ne8 = 67944;
                if ((((j_ey467ne8 * (j_ey467ne8 + 1)) % 2) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (967 ^ 967)) ? j_dc_74() : j_dc_75());
                }
                j_3p7qt3hh = 1;
                break;
            case 1:
                static volatile int64_t j_eymlwma1 = (11243 + 8133);
                if ((((j_eymlwma1 * j_eymlwma1) + j_eymlwma1) < 0))
                {
                    volatile int64_t j_5tphmacs = ((j_eymlwma1 * 58) + 376);
                    (void)printf("%s\n", 0 ? j_dc_76() : j_dc_77());
                }
                j_3p7qt3hh = 2;
                break;
            case 2:
                if ((j_vxxehlw0 == ((0 + 0) ^ (2777 ^ 2777))))
                {
                    return true;
                }
                j_3p7qt3hh = 3;
                break;
            case 3:
                return j_u1jd8trj((j_vxxehlw0 - 1));
                break;
            case 4:
                static volatile int64_t j_8o5fuudq = 66284;
                if ((((j_8o5fuudq * j_8o5fuudq) + j_8o5fuudq) < ((0 + 0) ^ (8479 ^ 8479))))
                {
                    volatile int64_t j_qana0zdj = ((j_8o5fuudq * ((27 + 0) ^ (4065 ^ 4065))) + ((111 + 173) ^ (2345 ^ 2345)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_78() : j_dc_79());
                }
                j_3p7qt3hh = 5;
                break;
            case 5:
                static volatile int64_t j_htb3rgly = 56266;
                if ((((j_htb3rgly * j_htb3rgly) + j_htb3rgly) < 0))
                {
                    volatile int64_t j_81x1jf3y = ((j_htb3rgly * 91) + 266);
                    (void)printf("%s\n", (0 + 0) ? j_dc_80() : j_dc_81());
                }
                j_3p7qt3hh = 6;
                break;
            case 6:
                static volatile int64_t j_qumacpti = 86031;
                if ((((j_qumacpti * j_qumacpti) + j_qumacpti) < ((0 + 0) ^ (6265 ^ 6265))))
                {
                    volatile int64_t j_7n3fh0c0 = ((j_qumacpti * 96) + (19 + 12));
                    (void)printf("%s\n", 0 ? j_dc_82() : j_dc_83());
                }
                j_3p7qt3hh = -1;
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

static bool j_u1jd8trj(int32_t j_vxxehlw0)
{
    int32_t j_qwk265v2 = 0;
    while ((j_qwk265v2 != -1))
    {
        switch (j_qwk265v2)
        {
            case 0:
                static volatile int64_t j_jhb16brr = (47367 + 41605);
                if ((((j_jhb16brr * j_jhb16brr) + j_jhb16brr) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_84() : j_dc_85());
                }
                j_qwk265v2 = 1;
                break;
            case 1:
                static volatile int64_t j_kpt5jy74 = (8696 + 32401);
                if ((((j_kpt5jy74 * j_kpt5jy74) + j_kpt5jy74) >= (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_86() : j_dc_87());
                }
                j_qwk265v2 = 2;
                break;
            case 2:
                if ((j_vxxehlw0 == (0 + 0)))
                {
                    return false;
                }
                j_qwk265v2 = 3;
                break;
            case 3:
                return j_dwwcl9v0((j_vxxehlw0 - 1));
                break;
            case 4:
                static volatile int64_t j_je3bxu1e = 79878;
                if ((((j_je3bxu1e * j_je3bxu1e) + j_je3bxu1e) < (0 + 0)))
                {
                    volatile int64_t j_l17cumr5 = ((j_je3bxu1e * (6 + 7)) + 878);
                    (void)printf("%s\n", 0 ? j_dc_88() : j_dc_89());
                }
                j_qwk265v2 = ((3 + 2) ^ (5354 ^ 5354));
                break;
            case 5:
                static volatile int64_t j_vl90z625 = 42708;
                if ((((j_vl90z625 * j_vl90z625) + j_vl90z625) < ((0 + 0) ^ (954 ^ 954))))
                {
                    volatile int64_t j_yackb9o9 = ((j_vl90z625 * (13 + 7)) + 708);
                    (void)printf("%s\n", 0 ? j_dc_90() : j_dc_91());
                }
                j_qwk265v2 = -((0 + 1) ^ (8551 ^ 8551));
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (3414 ^ 3414));
}

static const char* j_gcfgd3i4(const char* j_eu3wz7tw, int32_t j_w6mesi0m)
{
    int32_t j_obdh3w0k = ((0 + 0) ^ (443 ^ 443));
    while ((j_obdh3w0k != -((0 + 1) ^ (527 ^ 527))))
    {
        switch (j_obdh3w0k)
        {
            case 0:
                if ((j_w6mesi0m >= 18))
                {
                    return j_dc_92();
                }
                j_obdh3w0k = 1;
                break;
            case 1:
                static volatile int64_t j_mt0qotjl = 80575;
                static volatile int64_t j_051xehyu = (1844 + 3782);
                if ((((j_051xehyu * j_051xehyu) + j_051xehyu) < (0 + 0)))
                {
                    volatile int64_t j_pcrwneap = ((j_051xehyu * 76) + 626);
                    (void)printf("%s\n", (0 + 0) ? j_dc_93() : j_dc_94());
                }
                j_obdh3w0k = 2;
                break;
            case 2:
                if ((((j_mt0qotjl * j_mt0qotjl) + j_mt0qotjl) < 0))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_95() : j_dc_96());
                }
                j_obdh3w0k = ((1 + 2) ^ (5839 ^ 5839));
                break;
            case 3:
                static volatile int64_t j_1mi6kv9r = 51638;
                if ((((j_1mi6kv9r * j_1mi6kv9r) + j_1mi6kv9r) < ((0 + 0) ^ (9749 ^ 9749))))
                {
                    (void)printf("%s\n", 0 ? j_dc_97() : j_dc_98());
                }
                j_obdh3w0k = (2 + 2);
                break;
            case 4:
                return j_dc_99();
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (7450 ^ 7450));
}

__attribute__((used)) static int32_t j_z_5ppufq(int32_t j_n) {
    int32_t j_s = 0;
    int32_t j_i = (0 + 1);
    while (j_i <= j_n) {
        if ((j_i % 3) == ((0 + 0) ^ (2371 ^ 2371))) j_s = j_s + j_i;
        else j_s = j_s + j_i * (2 + 0);
        j_i = j_i + (0 + 1);
    }
    return j_s;
}

__attribute__((used)) static int32_t j_z_x7fm52(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = ((0 + 0) ^ (1353 ^ 1353));
    while (j_t < j_b) {
        j_r = (j_r * (2 + 29) + j_c) % ((7484 + 2523) ^ (1989 ^ 1989));
        j_t = j_t + 1;
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_hy797h(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = 0;
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % (3098 + 6909);
        j_t = j_t + ((1 + 0) ^ (1951 ^ 1951));
    }
    return j_r;
}

static int32_t j_tr_w8kitx(void) {
    int32_t j_lqdsll6a = (0 + 0);
    while ((j_lqdsll6a != -1))
    {
        switch (j_lqdsll6a)
        {
            case 0:
                (void)printf("%s\n", j_dc_100());
                (void)printf("%d\n", ((0 + 0) ^ (9623 ^ 9623)));
                static volatile int64_t j_lhwxqj9r = 70902;
                if ((((j_lhwxqj9r * j_lhwxqj9r) + j_lhwxqj9r) >= 0))
                {
                    (void)printf("%d\n", 42);
                }
                else
                {
                    volatile int64_t j_an62svr9 = ((j_lhwxqj9r * (1 + 1)) + 1);
                }
                j_lqdsll6a = 1;
                break;
            case 1:
                (void)printf("%d\n", -((2 + 15)));
                static volatile int64_t j_x7von3v7 = 71748;
                if ((((j_x7von3v7 * j_x7von3v7) + j_x7von3v7) >= 0))
                {
                    (void)printf("%d\n", ((37856 + 962144) ^ (4293 ^ 4293)));
                }
                else
                {
                    volatile int64_t j_l68dw28g = ((j_x7von3v7 * ((2 + 0) ^ (1941 ^ 1941))) + ((0 + 1) ^ (2820 ^ 2820)));
                }
                j_lqdsll6a = 2;
                break;
            case 2:
                (void)printf("%s\n", j_dc_101());
                (void)printf("%s\n", true ? j_dc_102() : j_dc_103());
                (void)printf("%s\n", false ? j_dc_104() : j_dc_105());
                (void)printf("%s\n", j_dc_106());
                static volatile int64_t j_hoslr0at = 35707;
                if ((((j_hoslr0at * j_hoslr0at) + j_hoslr0at) >= ((0 + 0) ^ (5196 ^ 5196))))
                {
                    (void)printf("%s\n", j_dc_107());
                }
                else
                {
                    volatile int64_t j_jbb11t8c = ((j_hoslr0at * ((0 + 2) ^ (2078 ^ 2078))) + 1);
                }
                j_lqdsll6a = ((2 + 1) ^ (98 ^ 98));
                break;
            case 3:
                (void)printf("%s\n", "");
                static volatile int64_t j_mhn3wxje = 56955;
                if ((((j_mhn3wxje * j_mhn3wxje) + j_mhn3wxje) >= 0))
                {
                    (void)printf("%s\n", j_dc_108());
                }
                else
                {
                    volatile int64_t j_3cdvb16f = ((j_mhn3wxje * 2) + ((0 + 1) ^ (4140 ^ 4140)));
                }
                j_lqdsll6a = 4;
                break;
            case 4:
                (void)printf("%s\n", j_dc_109());
                static volatile int64_t j_n8l8nii7 = (35530 + 28400);
                if ((((j_n8l8nii7 * j_n8l8nii7) + j_n8l8nii7) >= 0))
                {
                    (void)printf("%s\n", j_dc_110());
                }
                else
                {
                    volatile int64_t j_9q46v2mt = ((j_n8l8nii7 * 2) + 1);
                }
                j_lqdsll6a = (1 + 4);
                break;
            case 5:
                int32_t j_ddji0doq = (0 + 10);
                int32_t j_y3ncgfwg = (3 + 17);
                static volatile int64_t j_vo7u5hag = (41552 + 2760);
                if ((((j_vo7u5hag * j_vo7u5hag) + j_vo7u5hag) >= 0))
                {
                    (void)printf("%d\n", j_ddji0doq);
                }
                else
                {
                    volatile int64_t j_7gvi8asa = ((j_vo7u5hag * 2) + 1);
                }
                j_lqdsll6a = (3 + 3);
                break;
            case 6:
                static volatile int64_t j_2166sej3 = 60293;
                if ((((j_2166sej3 * j_2166sej3) + j_2166sej3) >= 0))
                {
                    (void)printf("%d\n", j_y3ncgfwg);
                }
                else
                {
                    volatile int64_t j_07ikarzd = ((j_2166sej3 * ((1 + 1) ^ (1398 ^ 1398))) + 1);
                }
                j_lqdsll6a = (1 + 6);
                break;
            case 7:
                const char* j_doqql8pa = j_dc_111();
                bool j_g6d1yvyy = true;
                static volatile int64_t j_vemeoo7a = 40393;
                if ((((j_vemeoo7a * j_vemeoo7a) + j_vemeoo7a) >= 0))
                {
                    (void)printf("%s\n", j_doqql8pa);
                }
                else
                {
                    volatile int64_t j_iw1z5vc6 = ((j_vemeoo7a * 2) + 1);
                }
                j_lqdsll6a = ((4 + 4) ^ (6024 ^ 6024));
                break;
            case 8:
                (void)printf("%s\n", j_g6d1yvyy ? j_dc_112() : j_dc_113());
                j_g6d1yvyy = false;
                (void)printf("%s\n", j_g6d1yvyy ? j_dc_114() : j_dc_115());
                (void)printf("%s\n", j_dc_116());
                (void)printf("%d\n", (2 + (3 * ((3 + 1) ^ (6813 ^ 6813)))));
                (void)printf("%d\n", (((2 + 0) + 3) * 4));
                static volatile int64_t j_lrm1gehh = ((9485 + 63012) ^ (8155 ^ 8155));
                if ((((j_lrm1gehh * j_lrm1gehh) + j_lrm1gehh) >= (0 + 0)))
                {
                    (void)printf("%d\n", ((((7 + 3) ^ (2914 ^ 2914)) - ((3 + 0) ^ (1143 ^ 1143))) - (2 + 0)));
                }
                else
                {
                    volatile int64_t j_vgpverpo = ((j_lrm1gehh * ((1 + 1) ^ (3694 ^ 3694))) + 1);
                }
                j_lqdsll6a = 9;
                break;
            case 9:
                (void)printf("%d\n", (100 / (1 + 6)));
                static volatile int64_t j_uztk75r5 = (14811 + 78242);
                if ((((j_uztk75r5 * j_uztk75r5) + j_uztk75r5) >= (0 + 0)))
                {
                    (void)printf("%d\n", ((51 + 49) % 7));
                }
                else
                {
                    volatile int64_t j_rrinilmx = ((j_uztk75r5 * (2 + 0)) + (0 + 1));
                }
                j_lqdsll6a = ((6 + 4) ^ (9995 ^ 9995));
                break;
            case 10:
                (void)printf("%d\n", -((((0 + 3) ^ (7721 ^ 7721)) + 4)));
                (void)printf("%d\n", ((((0 + 7) ^ (8398 ^ 8398)) / (1 + 1)) * 2));
                static volatile int64_t j_gq4jxv9a = 1887;
                if ((((j_gq4jxv9a * j_gq4jxv9a) + j_gq4jxv9a) >= 0))
                {
                    (void)printf("%d\n", (1 + (((1 + 1) * 3) % (3 + 1))));
                }
                else
                {
                    volatile int64_t j_qio12h5g = ((j_gq4jxv9a * ((2 + 0) ^ (5495 ^ 5495))) + 1);
                }
                j_lqdsll6a = ((9 + 2) ^ (1806 ^ 1806));
                break;
            case 11:
                (void)printf("%s\n", j_dc_117());
                (void)printf("%s\n", (1 == 1) ? j_dc_118() : j_dc_119());
                static volatile int64_t j_naocmdn5 = 53282;
                if ((((j_naocmdn5 * j_naocmdn5) + j_naocmdn5) >= 0))
                {
                    (void)printf("%s\n", ((0 + 1) != 2) ? j_dc_120() : j_dc_121());
                }
                else
                {
                    volatile int64_t j_fc11v1m4 = ((j_naocmdn5 * ((0 + 2) ^ (1511 ^ 1511))) + (0 + 1));
                }
                j_lqdsll6a = ((4 + 8) ^ (2692 ^ 2692));
                break;
            case 12:
                (void)printf("%s\n", ((2 + 1) < (3 + 2)) ? j_dc_122() : j_dc_123());
                static volatile int64_t j_8iipg4vh = ((5850 + 21595) ^ (2116 ^ 2116));
                if ((((j_8iipg4vh * j_8iipg4vh) + j_8iipg4vh) >= 0))
                {
                    (void)printf("%s\n", (5 <= ((1 + 4) ^ (1989 ^ 1989))) ? j_dc_124() : j_dc_125());
                }
                else
                {
                    volatile int64_t j_awdsb5zl = ((j_8iipg4vh * (2 + 0)) + 1);
                }
                j_lqdsll6a = 13;
                break;
            case 13:
                (void)printf("%s\n", (((4 + 0) ^ (7671 ^ 7671)) > 9) ? j_dc_126() : j_dc_127());
                (void)printf("%s\n", (9 >= 10) ? j_dc_128() : j_dc_129());
                static volatile int64_t j_43e124er = 62587;
                if ((((j_43e124er * j_43e124er) + j_43e124er) >= 0))
                {
                    (void)printf("%s\n", j_dc_130());
                }
                else
                {
                    volatile int64_t j_7k0d2soo = ((j_43e124er * ((1 + 1) ^ (759 ^ 759))) + 1);
                }
                j_lqdsll6a = (3 + 11);
                break;
            case 14:
                (void)printf("%s\n", (true && true) ? j_dc_131() : j_dc_132());
                (void)printf("%s\n", (true && false) ? j_dc_133() : j_dc_134());
                (void)printf("%s\n", (false || true) ? j_dc_135() : j_dc_136());
                (void)printf("%s\n", !(true) ? j_dc_137() : j_dc_138());
                static volatile int64_t j_ym23c5kb = (18123 + 37460);
                if ((((j_ym23c5kb * j_ym23c5kb) + j_ym23c5kb) >= ((0 + 0) ^ (7502 ^ 7502))))
                {
                    (void)printf("%s\n", !(!(true)) ? j_dc_139() : j_dc_140());
                }
                else
                {
                    volatile int64_t j_mceeviu9 = ((j_ym23c5kb * (0 + 2)) + 1);
                }
                j_lqdsll6a = (2 + 13);
                break;
            case 15:
                static volatile int64_t j_bffhgg0u = 32972;
                if ((((j_bffhgg0u * j_bffhgg0u) + j_bffhgg0u) >= 0))
                {
                    (void)printf("%s\n", j_dc_141());
                }
                else
                {
                    volatile int64_t j_mpcerarz = ((j_bffhgg0u * (0 + 2)) + 1);
                }
                j_lqdsll6a = (8 + 8);
                break;
            case 16:
                const char* j_76zh2lsi = j_dc_142();
                static volatile int64_t j_a4a9xqpg = (9453 + 77480);
                static volatile int64_t j_wcvk9ns5 = ((79834 + 1657) ^ (7024 ^ 7024));
                if ((((j_wcvk9ns5 * j_wcvk9ns5) + j_wcvk9ns5) < (0 + 0)))
                {
                    volatile int64_t j_97rqq5iy = ((j_wcvk9ns5 * (7 + 20)) + ((404 + 87) ^ (5827 ^ 5827)));
                    (void)printf("%s\n", 0 ? j_dc_143() : j_dc_144());
                }
                j_lqdsll6a = 17;
                break;
            case 17:
                if ((((j_a4a9xqpg * (j_a4a9xqpg + 1)) % 2) == 1))
                {
                    (void)printf("%s\n", 0 ? j_dc_145() : j_dc_146());
                }
                j_lqdsll6a = 18;
                break;
            case 18:
                static volatile int64_t j_qz5gkrpa = ((48738 + 48984) ^ (4975 ^ 4975));
                if ((((j_qz5gkrpa * j_qz5gkrpa) + j_qz5gkrpa) >= ((0 + 0) ^ (2882 ^ 2882))))
                {
                    (void)printf("%d\n", j_str_len(j_76zh2lsi));
                }
                else
                {
                    volatile int64_t j_e7kc7myx = ((j_qz5gkrpa * (0 + 2)) + 1);
                }
                j_lqdsll6a = 19;
                break;
            case 19:
                (void)printf("%d\n", j_str_len(""));
                (void)printf("%s\n", j_str_eq(j_76zh2lsi, j_dc_147()) ? j_dc_148() : j_dc_149());
                (void)printf("%s\n", j_str_eq(j_76zh2lsi, j_dc_150()) ? j_dc_151() : j_dc_152());
                (void)printf("%s\n", !j_str_eq(j_76zh2lsi, j_dc_153()) ? j_dc_154() : j_dc_155());
                static volatile int64_t j_rpogoku2 = (5160 + 32668);
                if ((((j_rpogoku2 * j_rpogoku2) + j_rpogoku2) >= ((0 + 0) ^ (4502 ^ 4502))))
                {
                    (void)printf("%s\n", j_dc_156());
                }
                else
                {
                    volatile int64_t j_1cfns2nj = ((j_rpogoku2 * (2 + 0)) + ((0 + 1) ^ (7363 ^ 7363)));
                }
                j_lqdsll6a = (3 + 17);
                break;
            case 20:
                int32_t j_vxxehlw0 = 7;
                if (((j_vxxehlw0 % 2) == ((0 + 0) ^ (3148 ^ 3148))))
                {
                    (void)printf("%s\n", j_dc_157());
                }
                else
                {
                    (void)printf("%s\n", j_dc_158());
                }
                j_lqdsll6a = ((20 + 1) ^ (7958 ^ 7958));
                break;
            case 21:
                if ((j_vxxehlw0 > ((6 + 4) ^ (8870 ^ 8870))))
                {
                    (void)printf("%s\n", j_dc_159());
                }
                j_lqdsll6a = ((6 + 16) ^ (7986 ^ 7986));
                break;
            case 22:
                (void)printf("%s\n", j_dc_160());
                static volatile int64_t j_oh0sw3nj = 53041;
                if ((((j_oh0sw3nj * j_oh0sw3nj) + j_oh0sw3nj) >= 0))
                {
                    (void)printf("%s\n", j_dc_161());
                }
                else
                {
                    volatile int64_t j_85qwutqy = ((j_oh0sw3nj * 2) + (0 + 1));
                }
                j_lqdsll6a = 23;
                break;
            case 23:
                int32_t j_17noej0r = ((0 + 0) ^ (439 ^ 439));
                while ((j_17noej0r < ((0 + 3) ^ (8497 ^ 8497))))
                {
                    (void)printf("%d\n", j_17noej0r);
                    j_17noej0r = (j_17noej0r + ((0 + 1) ^ (9524 ^ 9524)));
                }
                j_lqdsll6a = ((2 + 22) ^ (8139 ^ 8139));
                break;
            case 24:
                static volatile int64_t j_0ksabr2h = ((5810 + 8440) ^ (1512 ^ 1512));
                if ((((j_0ksabr2h * j_0ksabr2h) + j_0ksabr2h) >= 0))
                {
                    (void)printf("%s\n", j_dc_162());
                }
                else
                {
                    volatile int64_t j_cr5orrps = ((j_0ksabr2h * ((2 + 0) ^ (4308 ^ 4308))) + 1);
                }
                j_lqdsll6a = 25;
                break;
            case 25:
                for (int32_t j_cnqg14qg = ((0 + 0) ^ (8871 ^ 8871)); (j_cnqg14qg < ((4 + 0) ^ (4788 ^ 4788))); j_cnqg14qg = (j_cnqg14qg + 1))
                {
                    (void)printf("%d\n", j_cnqg14qg);
                }
                j_lqdsll6a = (20 + 6);
                break;
            case 26:
                (void)printf("%s\n", j_dc_163());
                int32_t j_zjsufqwi = ((0 + 0) ^ (6450 ^ 6450));
                int32_t j_qpr98c2m = j_zjsufqwi = 5;
                (void)printf("%d\n", j_zjsufqwi);
                (void)printf("%d\n", j_qpr98c2m);
                (void)printf("%s\n", j_dc_164());
                int32_t j_3tuhslui = ((1 + 0) ^ (4828 ^ 4828));
                if (true)
                {
                    int32_t j_3tuhslui = 2;
                    (void)printf("%d\n", j_3tuhslui);
                }
                j_lqdsll6a = 27;
                break;
            case 27:
                (void)printf("%d\n", j_3tuhslui);
                (void)printf("%s\n", j_dc_165());
                (void)printf("%d\n", j_4f7g6fui(((20 + 1) ^ (2782 ^ 2782))));
                (void)printf("%d\n", j_t2hghb9f((0 + 2), 3));
                (void)j_m2p7e3pa(j_dc_166());
                (void)printf("%d\n", j_t8lvogp4(((3 + 2) ^ (3660 ^ 3660))));
                (void)printf("%d\n", j_m3tuz7o1(10));
                (void)printf("%s\n", j_gcfgd3i4(j_dc_167(), ((3 + 18) ^ (9695 ^ 9695))));
                (void)printf("%s\n", j_dc_168());
                (void)printf("%s\n", j_dwwcl9v0(10) ? j_dc_169() : j_dc_170());
                static volatile int64_t j_gjjcndpq = (2967 + 85660);
                if ((((j_gjjcndpq * j_gjjcndpq) + j_gjjcndpq) >= 0))
                {
                    (void)printf("%s\n", j_u1jd8trj(10) ? j_dc_171() : j_dc_172());
                }
                else
                {
                    volatile int64_t j_grn6l72x = ((j_gjjcndpq * ((0 + 2) ^ (2750 ^ 2750))) + (0 + 1));
                }
                j_lqdsll6a = ((0 + 28) ^ (9081 ^ 9081));
                break;
            case 28:
                (void)printf("%s\n", j_dwwcl9v0(7) ? j_dc_173() : j_dc_174());
                static volatile int64_t j_g3h3jvgx = 93141;
                if ((((j_g3h3jvgx * j_g3h3jvgx) + j_g3h3jvgx) >= 0))
                {
                    (void)printf("%s\n", j_dc_175());
                }
                else
                {
                    volatile int64_t j_rae6r2fb = ((j_g3h3jvgx * 2) + (0 + 1));
                }
                j_lqdsll6a = (11 + 18);
                break;
            case 29:
                (void)printf("%d\n", j_4f7g6fui(j_4f7g6fui(((0 + 2) ^ (5356 ^ 5356)))));
                (void)printf("%d\n", j_t8lvogp4(j_m3tuz7o1(5)));
                j_lqdsll6a = -1;
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (3009 ^ 3009));
}
static int32_t j_tr_bib5dw(void) { return j_tr_w8kitx(); }
static int32_t j_tr_zyw4k4(void) { return j_tr_bib5dw(); }
int32_t main(void) { return j_tr_zyw4k4(); }

