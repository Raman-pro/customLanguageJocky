// JOCKY build 6E68DFCF73E0FDE1 seed=12345 date=2026-09-03 05:00:03
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
    static char j_rb[((14 + 3) ^ (7892 ^ 7892))];
    for (int j_i = ((0 + 0) ^ (3747 ^ 3747)); j_i < ((12 + 4) ^ (8681 ^ 8681)); j_i++) j_rb[j_i] = j_enc_0[j_i] ^ (20 + 15);
    j_rb[(12 + 4)] = ((0 + 0) ^ (9583 ^ 9583));
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x22, 0x23, 0x20, 0x21, 0x26, 0x27, 0x24, 0x25, 0x2A, 0x2B, 0x73, 0x70, 0x71, 0x76, 0x77, 0x74};
static const char* j_dc_1(void) {
    static char j_rb[(10 + 7)];
    for (int j_i = (0 + 0); j_i < (12 + 4); j_i++) j_rb[j_i] = j_enc_1[j_i] ^ ((0 + 18) ^ (3369 ^ 3369));
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0xBA, 0xAA};
static const char* j_dc_2(void) {
    static char j_rb[3];
    for (int j_i = (0 + 0); j_i < ((0 + 2) ^ (6072 ^ 6072)); j_i++) j_rb[j_i] = j_enc_2[j_i] ^ 200;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x58, 0x4D};
static const char* j_dc_3(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ ((40 + 7) ^ (4892 ^ 4892));
    j_rb[((2 + 0) ^ (1156 ^ 1156))] = ((0 + 0) ^ (1265 ^ 1265));
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0xDC, 0x83, 0x81, 0x9C, 0x90};
static const char* j_dc_4(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = (0 + 0); j_i < ((0 + 5) ^ (5983 ^ 5983)); j_i++) j_rb[j_i] = j_enc_4[j_i] ^ (25 + 218);
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xDB};
static const char* j_dc_5(void) {
    static char j_rb[((1 + 1) ^ (4026 ^ 4026))];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ 169;
    j_rb[((0 + 1) ^ (2051 ^ 2051))] = ((0 + 0) ^ (7353 ^ 7353));
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x64};
static const char* j_dc_6(void) {
    static char j_rb[(2 + 0)];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_6[j_i] ^ (68 + 42);
    j_rb[((0 + 1) ^ (8978 ^ 8978))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x8E};
static const char* j_dc_7(void) {
    static char j_rb[2];
    for (int j_i = (0 + 0); j_i < 1; j_i++) j_rb[j_i] = j_enc_7[j_i] ^ (151 + 101);
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0x5F};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 96;
    j_rb[1] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0xDD, 0xD8, 0xC2, 0xC5, 0xD4, 0xDF};
static const char* j_dc_9(void) {
    static char j_rb[((3 + 4) ^ (3892 ^ 3892))];
    for (int j_i = 0; j_i < 6; j_i++) j_rb[j_i] = j_enc_9[j_i] ^ 145;
    j_rb[6] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0x71, 0x67, 0x60, 0x75, 0x76, 0x78, 0x7D, 0x67, 0x7C, 0x71, 0x70};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < ((9 + 2) ^ (9743 ^ 9743)); j_i++) j_rb[j_i] = j_enc_10[j_i] ^ (23 + 29);
    j_rb[(8 + 3)] = ((0 + 0) ^ (168 ^ 168));
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0x82, 0x8D, 0x8E, 0x92, 0x84, 0x9E, 0x96, 0x80, 0x88, 0x95};
static const char* j_dc_11(void) {
    static char j_rb[11];
    for (int j_i = 0; j_i < 10; j_i++) j_rb[j_i] = j_enc_11[j_i] ^ 193;
    j_rb[10] = ((0 + 0) ^ (5633 ^ 5633));
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0x36, 0x2B, 0x2F, 0x27, 0x3D, 0x35, 0x23, 0x2B, 0x36};
static const char* j_dc_12(void) {
    static char j_rb[10];
    for (int j_i = 0; j_i < ((5 + 4) ^ (8030 ^ 8030)); j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 98;
    j_rb[((8 + 1) ^ (5112 ^ 5112))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x0B, 0x10, 0x0C, 0x01, 0x16};
static const char* j_dc_13(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ ((59 + 9) ^ (9363 ^ 9363));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x3C, 0x37, 0x26, 0x21, 0x26, 0x33, 0x26, 0x72, 0x7F, 0x33, 0x3C, 0x72, 0x7F, 0x22, 0x72, 0x26, 0x31, 0x22, 0x72, 0x60, 0x6C, 0x7D, 0x36, 0x37, 0x24, 0x7D, 0x3C, 0x27, 0x3E, 0x3E};
static const char* j_dc_14(void) {
    static char j_rb[(29 + 2)];
    for (int j_i = 0; j_i < 30; j_i++) j_rb[j_i] = j_enc_14[j_i] ^ ((0 + 82) ^ (2763 ^ 2763));
    j_rb[30] = ((0 + 0) ^ (7917 ^ 7917));
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0x92};
static const char* j_dc_15(void) {
    static char j_rb[((2 + 0) ^ (7840 ^ 7840))];
    for (int j_i = 0; j_i < (0 + 1); j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 224;
    j_rb[((0 + 1) ^ (2712 ^ 2712))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x80, 0x97, 0x84};
static const char* j_dc_16(void) {
    static char j_rb[((0 + 4) ^ (2865 ^ 2865))];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_16[j_i] ^ 244;
    j_rb[((0 + 3) ^ (9940 ^ 9940))] = ((0 + 0) ^ (6049 ^ 6049));
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0xE6, 0xB9, 0xBB, 0xA6, 0xAA, 0xE6, 0xA7, 0xAC, 0xBD, 0xE6, 0xBD, 0xAA, 0xB9};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < 13; j_i++) j_rb[j_i] = j_enc_17[j_i] ^ 201;
    j_rb[(3 + 10)] = ((0 + 0) ^ (2620 ^ 2620));
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0x04, 0x5B, 0x59, 0x44, 0x48, 0x04, 0x45, 0x4E, 0x5F, 0x04, 0x5F, 0x48, 0x5B, 0x1D};
static const char* j_dc_18(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ (10 + 33);
    j_rb[14] = ((0 + 0) ^ (9977 ^ 9977));
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0xA3, 0xA0, 0xA7, 0xA6, 0xB7};
static const char* j_dc_19(void) {
    static char j_rb[((1 + 5) ^ (5350 ^ 5350))];
    for (int j_i = 0; j_i < (0 + 5); j_i++) j_rb[j_i] = j_enc_19[j_i] ^ 235;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0x36, 0x35, 0x3D, 0x2B, 0x22};
static const char* j_dc_20(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_20[j_i] ^ ((10 + 116) ^ (5762 ^ 5762));
    j_rb[(2 + 3)] = ((0 + 0) ^ (1066 ^ 1066));
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x1A, 0x19, 0x11, 0x00, 0x0E};
static const char* j_dc_21(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_21[j_i] ^ ((75 + 7) ^ (9651 ^ 9651));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0x29, 0x2A, 0x34, 0x3D};
static const char* j_dc_22(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < ((3 + 1) ^ (9181 ^ 9181)); j_i++) j_rb[j_i] = j_enc_22[j_i] ^ 97;
    j_rb[4] = ((0 + 0) ^ (1968 ^ 1968));
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0xF1, 0xE4};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = ((0 + 0) ^ (781 ^ 781)); j_i < 2; j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 134;
    j_rb[2] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0x85, 0x8E, 0x8C, 0x8A, 0x9F, 0x82, 0x9D, 0x8E};
static const char* j_dc_24(void) {
    static char j_rb[(6 + 3)];
    for (int j_i = 0; j_i < 8; j_i++) j_rb[j_i] = j_enc_24[j_i] ^ ((233 + 2) ^ (7781 ^ 7781));
    j_rb[((3 + 5) ^ (3660 ^ 3660))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0xDB, 0xDD, 0xDA, 0xCA};
static const char* j_dc_25(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_25[j_i] ^ (104 + 71);
    j_rb[(0 + 4)] = ((0 + 0) ^ (8576 ^ 8576));
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x76, 0x71, 0x7C, 0x63, 0x75};
static const char* j_dc_26(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = ((0 + 0) ^ (2295 ^ 2295)); j_i < 5; j_i++) j_rb[j_i] = j_enc_26[j_i] ^ 16;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0xF9, 0xE6, 0xF1, 0xEC};
static const char* j_dc_27(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 131;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x91, 0x82, 0x91, 0x9A};
static const char* j_dc_28(void) {
    static char j_rb[((2 + 3) ^ (5428 ^ 5428))];
    for (int j_i = ((0 + 0) ^ (6261 ^ 6261)); j_i < ((2 + 2) ^ (7774 ^ 7774)); j_i++) j_rb[j_i] = j_enc_28[j_i] ^ 244;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0x0A, 0x01, 0x01};
static const char* j_dc_29(void) {
    static char j_rb[(4 + 0)];
    for (int j_i = (0 + 0); j_i < ((2 + 1) ^ (166 ^ 166)); j_i++) j_rb[j_i] = j_enc_29[j_i] ^ 101;
    j_rb[3] = ((0 + 0) ^ (3853 ^ 3853));
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0x80, 0x86, 0x81, 0x91};
static const char* j_dc_30(void) {
    static char j_rb[(3 + 2)];
    for (int j_i = 0; j_i < ((0 + 4) ^ (5671 ^ 5671)); j_i++) j_rb[j_i] = j_enc_30[j_i] ^ 244;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0x88, 0x8F, 0x82, 0x9D, 0x8B};
static const char* j_dc_31(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_31[j_i] ^ ((237 + 1) ^ (6757 ^ 6757));
    j_rb[(3 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0x59, 0x5F, 0x58, 0x48};
static const char* j_dc_32(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_32[j_i] ^ 45;
    j_rb[((2 + 2) ^ (9568 ^ 9568))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0xA7, 0xA0, 0xAD, 0xB2, 0xA4};
static const char* j_dc_33(void) {
    static char j_rb[((4 + 2) ^ (1230 ^ 1230))];
    for (int j_i = 0; j_i < ((1 + 4) ^ (3360 ^ 3360)); j_i++) j_rb[j_i] = j_enc_33[j_i] ^ (15 + 178);
    j_rb[5] = ((0 + 0) ^ (2023 ^ 2023));
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x6E, 0x68, 0x6F, 0x7F};
static const char* j_dc_34(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = ((0 + 0) ^ (5566 ^ 5566)); j_i < 4; j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 26;
    j_rb[((4 + 0) ^ (4889 ^ 4889))] = ((0 + 0) ^ (8617 ^ 8617));
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0xE2, 0xE5, 0xE8, 0xF7, 0xE1};
static const char* j_dc_35(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (1785 ^ 1785)); j_i < 5; j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 132;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0xA6, 0xA0, 0xA7, 0xB7};
static const char* j_dc_36(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (2605 ^ 2605)); j_i < 4; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 210;
    j_rb[(1 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0xA2, 0xA5, 0xA8, 0xB7, 0xA1};
static const char* j_dc_37(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_37[j_i] ^ 196;
    j_rb[5] = ((0 + 0) ^ (6414 ^ 6414));
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0xBB, 0xBD, 0xBA, 0xAA};
static const char* j_dc_38(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_38[j_i] ^ (47 + 160);
    j_rb[4] = ((0 + 0) ^ (6210 ^ 6210));
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x11, 0x16, 0x1B, 0x04, 0x12};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (9399 ^ 9399)); j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_39[j_i] ^ ((111 + 8) ^ (1846 ^ 1846));
    j_rb[5] = ((0 + 0) ^ (8125 ^ 8125));
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0xBA, 0xBC, 0xBB, 0xAB};
static const char* j_dc_40(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_40[j_i] ^ (17 + 189);
    j_rb[4] = ((0 + 0) ^ (4553 ^ 4553));
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0xA2, 0xA5, 0xA8, 0xB7, 0xA1};
static const char* j_dc_41(void) {
    static char j_rb[((6 + 0) ^ (2889 ^ 2889))];
    for (int j_i = 0; j_i < ((1 + 4) ^ (9824 ^ 9824)); j_i++) j_rb[j_i] = j_enc_41[j_i] ^ (190 + 6);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0x85, 0x83, 0x84, 0x94};
static const char* j_dc_42(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_42[j_i] ^ ((62 + 179) ^ (8836 ^ 8836));
    j_rb[((0 + 4) ^ (449 ^ 449))] = ((0 + 0) ^ (6928 ^ 6928));
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x4A, 0x4D, 0x40, 0x5F, 0x49};
static const char* j_dc_43(void) {
    static char j_rb[((5 + 1) ^ (8273 ^ 8273))];
    for (int j_i = 0; j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_43[j_i] ^ ((11 + 33) ^ (1017 ^ 1017));
    j_rb[((4 + 1) ^ (2476 ^ 2476))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x42, 0x44, 0x43, 0x53};
static const char* j_dc_44(void) {
    static char j_rb[((3 + 2) ^ (4169 ^ 4169))];
    for (int j_i = (0 + 0); j_i < ((0 + 4) ^ (2384 ^ 2384)); j_i++) j_rb[j_i] = j_enc_44[j_i] ^ 54;
    j_rb[((1 + 3) ^ (2885 ^ 2885))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0xA2, 0xA5, 0xA8, 0xB7, 0xA1};
static const char* j_dc_45(void) {
    static char j_rb[((6 + 0) ^ (951 ^ 951))];
    for (int j_i = ((0 + 0) ^ (95 ^ 95)); j_i < 5; j_i++) j_rb[j_i] = j_enc_45[j_i] ^ (160 + 36);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x52, 0x54, 0x53, 0x43};
static const char* j_dc_46(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = 0; j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_46[j_i] ^ ((38 + 0) ^ (3956 ^ 3956));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x3A, 0x3D, 0x30, 0x2F, 0x39};
static const char* j_dc_47(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_47[j_i] ^ 92;
    j_rb[(5 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0xF8, 0xFE, 0xF9, 0xE9};
static const char* j_dc_48(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (6825 ^ 6825)); j_i < 4; j_i++) j_rb[j_i] = j_enc_48[j_i] ^ (91 + 49);
    j_rb[(3 + 1)] = ((0 + 0) ^ (5346 ^ 5346));
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0x02, 0x05, 0x08, 0x17, 0x01};
static const char* j_dc_49(void) {
    static char j_rb[(3 + 3)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_49[j_i] ^ (60 + 40);
    j_rb[5] = ((0 + 0) ^ (9371 ^ 9371));
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0x61, 0x67, 0x60, 0x70};
static const char* j_dc_50(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_50[j_i] ^ 21;
    j_rb[(2 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0x43, 0x44, 0x49, 0x56, 0x40};
static const char* j_dc_51(void) {
    static char j_rb[((1 + 5) ^ (9526 ^ 9526))];
    for (int j_i = ((0 + 0) ^ (8331 ^ 8331)); j_i < 5; j_i++) j_rb[j_i] = j_enc_51[j_i] ^ 37;
    j_rb[(5 + 0)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0x37, 0x37, 0x37, 0x2A, 0x49, 0x45, 0x46, 0x46, 0x4B, 0x5E, 0x50, 0x2A, 0x59, 0x5E, 0x4F, 0x5A, 0x59, 0x2A, 0x37, 0x37, 0x37};
static const char* j_dc_52(void) {
    static char j_rb[((5 + 17) ^ (6040 ^ 6040))];
    for (int j_i = (0 + 0); j_i < 21; j_i++) j_rb[j_i] = j_enc_52[j_i] ^ ((3 + 7) ^ (1492 ^ 1492));
    j_rb[21] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0x82, 0x84, 0x83, 0x93};
static const char* j_dc_53(void) {
    static char j_rb[((1 + 4) ^ (903 ^ 903))];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 246;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0x4D, 0x4A, 0x47, 0x58, 0x4E};
static const char* j_dc_54(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (8793 ^ 8793)); j_i < (3 + 2); j_i++) j_rb[j_i] = j_enc_54[j_i] ^ ((8 + 35) ^ (7190 ^ 7190));
    j_rb[(4 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x2F, 0x29, 0x2E, 0x3E};
static const char* j_dc_55(void) {
    static char j_rb[((0 + 5) ^ (4926 ^ 4926))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_55[j_i] ^ 91;
    j_rb[4] = ((0 + 0) ^ (967 ^ 967));
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0xE0, 0xE7, 0xEA, 0xF5, 0xE3};
static const char* j_dc_56(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_56[j_i] ^ 134;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0x60, 0x60, 0x60, 0x7D, 0x1E, 0x11, 0x1C, 0x0E, 0x0E, 0x14, 0x1B, 0x14, 0x1E, 0x1C, 0x09, 0x14, 0x12, 0x13, 0x7D, 0x60, 0x60, 0x60};
static const char* j_dc_57(void) {
    static char j_rb[23];
    for (int j_i = ((0 + 0) ^ (2777 ^ 2777)); j_i < 22; j_i++) j_rb[j_i] = j_enc_57[j_i] ^ 93;
    j_rb[22] = ((0 + 0) ^ (8479 ^ 8479));
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0x32, 0x32, 0x32, 0x2F, 0x4E, 0x48, 0x48, 0x5D, 0x4A, 0x48, 0x4E, 0x5B, 0x4A, 0x2F, 0x32, 0x32, 0x32};
static const char* j_dc_58(void) {
    static char j_rb[((15 + 3) ^ (4065 ^ 4065))];
    for (int j_i = ((0 + 0) ^ (2345 ^ 2345)); j_i < (6 + 11); j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 15;
    j_rb[17] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0xA9, 0xAF, 0xA8, 0xB8};
static const char* j_dc_59(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 221;
    j_rb[4] = ((0 + 0) ^ (6265 ^ 6265));
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0xEB, 0xEC, 0xE1, 0xFE, 0xE8};
static const char* j_dc_60(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_60[j_i] ^ 141;
    j_rb[(2 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_61[] = {0x6E, 0x68, 0x6F, 0x7F};
static const char* j_dc_61(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_61[j_i] ^ 26;
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_62[] = {0xD6, 0xD1, 0xDC, 0xC3, 0xD5};
static const char* j_dc_62(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_62[j_i] ^ (47 + 129);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_63[] = {0xE6, 0xE6, 0xE6, 0xFB, 0x89, 0x9E, 0x88, 0x8E, 0x97, 0x8F, 0xFB, 0xE6, 0xE6, 0xE6};
static const char* j_dc_63(void) {
    static char j_rb[15];
    for (int j_i = (0 + 0); j_i < (7 + 7); j_i++) j_rb[j_i] = j_enc_63[j_i] ^ 219;
    j_rb[14] = ((0 + 0) ^ (5354 ^ 5354));
    return j_rb;
}

static const volatile uint8_t j_enc_64[] = {0xC4, 0xC9, 0xC9, 0x85, 0xC7, 0xD0, 0xCC, 0xC9, 0xC1, 0xD6, 0x85, 0xD5, 0xD7, 0xCA, 0xC1, 0xD0, 0xC6, 0xC0, 0x85, 0xCC, 0xC1, 0xC0, 0xCB, 0xD1, 0xCC, 0xC6, 0xC4, 0xC9, 0x85, 0xCA, 0xD0, 0xD1, 0xD5, 0xD0, 0xD1};
static const char* j_dc_64(void) {
    static char j_rb[36];
    for (int j_i = ((0 + 0) ^ (954 ^ 954)); j_i < (16 + 19); j_i++) j_rb[j_i] = j_enc_64[j_i] ^ 165;
    j_rb[35] = ((0 + 0) ^ (8551 ^ 8551));
    return j_rb;
}

static const volatile uint8_t j_enc_65[] = {0x5E, 0x58, 0x5F, 0x4F};
static const char* j_dc_65(void) {
    static char j_rb[((2 + 3) ^ (3414 ^ 3414))];
    for (int j_i = ((0 + 0) ^ (443 ^ 443)); j_i < ((0 + 4) ^ (527 ^ 527)); j_i++) j_rb[j_i] = j_enc_65[j_i] ^ 42;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_66[] = {0xE1, 0xE6, 0xEB, 0xF4, 0xE2};
static const char* j_dc_66(void) {
    static char j_rb[(6 + 0)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_66[j_i] ^ 135;
    j_rb[(3 + 2)] = 0;
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[(8141 + 57395)];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = ((0 + 0) ^ (5839 ^ 5839));
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
                    out[o++] = j_dc_0()[c >> ((1 + 3) ^ (9749 ^ 9749))];
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
    ts.tv_sec = ms / (201 + 799);
    ts.tv_nsec = (long)(ms % ((813 + 187) ^ (7450 ^ 7450))) * 1000000L;
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
    size_t n = fread(j_buf, (0 + 1), J_BUF_CAP - 1, f);
    fclose(f);
    j_buf[n] = '\0';
    return j_buf;
}

static void j_fs_write(const char* path, const char* data) {
    FILE* f = fopen(path, j_dc_3());
    if (f) { fputs(data, f); fclose(f); }
}

static const char* j_fs_list(const char* dir) {
    size_t off = ((0 + 0) ^ (2371 ^ 2371));
    j_buf[off++] = '[';
    int first = (1 + 0);
#if defined(_WIN32)
    char pattern[(797 + 227)];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[((0 + 0) ^ (1353 ^ 1353))] == '.') continue;
            if (off > J_BUF_CAP - (189 + 11)) break;
            if (!first) j_buf[off++] = ',';
            first = ((0 + 0) ^ (1989 ^ 1989));
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
            if (de->d_name[(0 + 0)] == '.') continue;
            if (off > J_BUF_CAP - ((162 + 38) ^ (1951 ^ 1951))) break;
            if (!first) j_buf[off++] = ',';
            first = (0 + 0);
            char esc[1024];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > ((0 + 0) ^ (9623 ^ 9623)) ? n : 0);
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
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, (0 + 0));
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - 400) break;
                char name[1024];
                size_t k = (0 + 0);
                for (size_t i = 0; pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = ((0 + 0) ^ (4293 ^ 4293));
                char esc[((1847 + 201) ^ (1941 ^ 1941))];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > ((0 + 0) ^ (2820 ^ 2820)) ? n : 0);
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[8192];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = ((0 + 0) ^ (5196 ^ 5196)); i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - ((207 + 193) ^ (2078 ^ 2078))) break;
        char name[256];
        int len = proc_name(pid, name, sizeof name);
        if (len <= ((0 + 0) ^ (98 ^ 98))) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = 0;
        char esc[512];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : ((0 + 0) ^ (4140 ^ 4140)));
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[(0 + 0)] > '9') continue;
            int pid = atoi(de->d_name);
            char p[64], name[256];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                char esc[(78 + 434)];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > (0 + 0) ? n : (0 + 0));
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
        char laddr[(2 + 62)], raddr[64], st[16];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != ((3 + 0) ^ (1398 ^ 1398))) continue;
        if (*off > J_BUF_CAP - 300) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = (0 + 0);
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
    ULONG sz = ((0 + 0) ^ (6024 ^ 6024));
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
    char* t = (char*)malloc(sz ? sz : 1);
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, ((0 + 0) ^ (6813 ^ 6813))) == NO_ERROR) {
            for (DWORD i = (0 + 0); i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[64], ri[64];
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
                if (off > J_BUF_CAP - ((25 + 275) ^ (8155 ^ 8155))) break;
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > ((0 + 0) ^ (2914 ^ 2914)) ? n : ((0 + 0) ^ (1143 ^ 1143)));
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[(74 + 438)];
        while (fgets(line, sizeof line, ns)) {
            char proto[((4 + 4) ^ (3694 ^ 3694))], laddr[64], raddr[64], st[32];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == (2 + 2)) {
                if (strncmp(proto, j_dc_16(), (1 + 2)) != (0 + 0)) continue;
                if (off > J_BUF_CAP - (23 + 277)) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
                off += (size_t)(n > (0 + 0) ? n : (0 + 0));
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
    size_t off = ((0 + 0) ^ (9995 ^ 9995));
    j_buf[off++] = '[';
    int first = ((0 + 1) ^ (7721 ^ 7721));
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), 5) == ((0 + 0) ^ (8398 ^ 8398))) { root = HKEY_LOCAL_MACHINE; sub = key + (1 + 4); }
    else if (strncmp(key, j_dc_20(), 5) == 0) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, j_dc_21(), 5) == (0 + 0)) { root = HKEY_CLASSES_ROOT; sub = key + 5; }
    else if (strncmp(key, j_dc_22(), (3 + 1)) == ((0 + 0) ^ (5495 ^ 5495))) { root = HKEY_USERS; sub = key + 4; }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, ((0 + 0) ^ (1806 ^ 1806)), KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = 0; ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[(64 + 448)];
            j_json_escape(esc, sizeof esc, s);
            int n2 = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n2 > 0 ? n2 : ((0 + 0) ^ (1511 ^ 1511)));
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
    unsigned long regions = (0 + 0);
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < ((77695 + 22305) ^ (2692 ^ 2692))) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : (0 + 1));
            SIZE_T read = (0 + 0);
            if (chunk && ReadProcessMemory(h, mbi.BaseAddress, chunk, mbi.RegionSize, &read) && read) {
                fwrite(chunk, ((0 + 1) ^ (2116 ^ 2116)), read, out);
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

static volatile int32_t j_ls2wrj8m = 63390;
static volatile int32_t j_2p7e3pad = 28372;

static const char* j_4f7g6fui(int32_t j_zjsufqwi);
static int32_t j_t2hghb9f(int32_t j_zjsufqwi);
static int32_t j_oiwo6t0n(int32_t j_zjsufqwi);

static const char* j_4f7g6fui(int32_t j_zjsufqwi)
{
    int32_t j_ql8pat8l = ((0 + 0) ^ (1989 ^ 1989));
    while ((j_ql8pat8l != -(1 + 0)))
    {
        switch (j_ql8pat8l)
        {
            case 0:
                if ((j_zjsufqwi < 0))
                {
                    return j_dc_24();
                }
                j_ql8pat8l = 1;
                break;
            case 1:
                static volatile int64_t j_vogp4vxx = ((19089 + 67844) ^ (7671 ^ 7671));
                if ((((j_vogp4vxx * (j_vogp4vxx + 1)) % 2) == 1))
                {
                    (void)printf("%s\n", 0 ? j_dc_25() : j_dc_26());
                }
                j_ql8pat8l = 2;
                break;
            case 2:
                if ((j_zjsufqwi == ((0 + 0) ^ (759 ^ 759))))
                {
                    return j_dc_27();
                }
                j_ql8pat8l = 3;
                break;
            case 3:
                if (((j_zjsufqwi % (0 + 2)) == (0 + 0)))
                {
                    return j_dc_28();
                }
                j_ql8pat8l = ((4 + 0) ^ (7502 ^ 7502));
                break;
            case 4:
                return j_dc_29();
                break;
            case 5:
                static volatile int64_t j_ehlw0m3t = (23316 + 58175);
                if ((((j_ehlw0m3t * j_ehlw0m3t) + j_ehlw0m3t) < 0))
                {
                    volatile int64_t j_uz7o1dww = ((j_ehlw0m3t * (26 + 1)) + 491);
                    (void)printf("%s\n", 0 ? j_dc_30() : j_dc_31());
                }
                j_ql8pat8l = -(1 + 0);
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_t2hghb9f(int32_t j_zjsufqwi)
{
    int32_t j_cl9v0u1j = (0 + 0);
    while ((j_cl9v0u1j != -(1 + 0)))
    {
        switch (j_cl9v0u1j)
        {
            case 0:
                static volatile int64_t j_d8trjgcf = ((29872 + 11314) ^ (7024 ^ 7024));
                if ((((j_d8trjgcf * j_d8trjgcf) + j_d8trjgcf) < (0 + 0)))
                {
                    volatile int64_t j_gd3i4eu3 = ((j_d8trjgcf * (79 + 6)) + ((117 + 69) ^ (5827 ^ 5827)));
                    (void)printf("%s\n", 0 ? j_dc_32() : j_dc_33());
                }
                j_cl9v0u1j = 1;
                break;
            case 1:
                static volatile int64_t j_wz7tww6m = 2672;
                static volatile int64_t j_esi0ml05 = 71748;
                if ((((j_esi0ml05 * j_esi0ml05) + j_esi0ml05) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_34() : j_dc_35());
                }
                j_cl9v0u1j = 2;
                break;
            case 2:
                if ((((j_wz7tww6m * j_wz7tww6m) + j_wz7tww6m) >= ((0 + 0) ^ (4975 ^ 4975))))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (2882 ^ 2882)) ? j_dc_36() : j_dc_37());
                }
                j_cl9v0u1j = (3 + 0);
                break;
            case 3:
                static volatile int64_t j_2rhh3gut = 39925;
                if ((((j_2rhh3gut * j_2rhh3gut) + j_2rhh3gut) < 0))
                {
                    volatile int64_t j_si31ndk9 = ((j_2rhh3gut * (3 + 16)) + ((539 + 386) ^ (4502 ^ 4502)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_38() : j_dc_39());
                }
                j_cl9v0u1j = ((0 + 4) ^ (7363 ^ 7363));
                break;
            case 4:
                static volatile int64_t j_e63tox7h = (28299 + 49559);
                if ((((j_e63tox7h * (j_e63tox7h + 1)) % 2) == ((1 + 0) ^ (3148 ^ 3148))))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (7958 ^ 7958)) ? j_dc_40() : j_dc_41());
                }
                j_cl9v0u1j = ((3 + 2) ^ (8870 ^ 8870));
                break;
            case 5:
                if (((j_zjsufqwi % ((0 + 2) ^ (7986 ^ 7986))) == 0))
                {
                    return (j_zjsufqwi / 2);
                }
                j_cl9v0u1j = 6;
                break;
            case 6:
                return ((j_zjsufqwi * (2 + 1)) + 1);
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (439 ^ 439));
}

static int32_t j_oiwo6t0n(int32_t j_zjsufqwi)
{
    int32_t j_gmqpdmt0 = ((0 + 0) ^ (8497 ^ 8497));
    while ((j_gmqpdmt0 != -((0 + 1) ^ (9524 ^ 9524))))
    {
        switch (j_gmqpdmt0)
        {
            case 0:
                static volatile int64_t j_c8jewur5 = ((180 + 396) ^ (8139 ^ 8139));
                if ((((j_c8jewur5 * j_c8jewur5) + j_c8jewur5) < ((0 + 0) ^ (1512 ^ 1512))))
                {
                    (void)printf("%s\n", 0 ? j_dc_42() : j_dc_43());
                }
                j_gmqpdmt0 = ((1 + 0) ^ (4308 ^ 4308));
                break;
            case 1:
                int32_t j_468tmzoa = 0;
                int32_t j_qo32bb5q = j_zjsufqwi;
                while ((j_qo32bb5q != 1))
                {
                    j_qo32bb5q = j_t2hghb9f(j_qo32bb5q);
                    j_468tmzoa = (j_468tmzoa + ((1 + 0) ^ (8871 ^ 8871)));
                }
                j_gmqpdmt0 = ((0 + 2) ^ (4788 ^ 4788));
                break;
            case 2:
                static volatile int64_t j_ifxsxp8l = 88161;
                if ((((j_ifxsxp8l * j_ifxsxp8l) + j_ifxsxp8l) >= (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (6450 ^ 6450)) ? j_dc_44() : j_dc_45());
                }
                j_gmqpdmt0 = 3;
                break;
            case 3:
                static volatile int64_t j_l9dl9lcd = ((77029 + 21879) ^ (4828 ^ 4828));
                if ((((j_l9dl9lcd * j_l9dl9lcd) + j_l9dl9lcd) < 0))
                {
                    volatile int64_t j_7m5fgot7 = ((j_l9dl9lcd * 97) + ((413 + 495) ^ (2782 ^ 2782)));
                    (void)printf("%s\n", (0 + 0) ? j_dc_46() : j_dc_47());
                }
                j_gmqpdmt0 = 4;
                break;
            case 4:
                static volatile int64_t j_yn30xwb1 = ((7077 + 34607) ^ (3660 ^ 3660));
                if ((((j_yn30xwb1 * j_yn30xwb1) + j_yn30xwb1) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (9695 ^ 9695)) ? j_dc_48() : j_dc_49());
                }
                j_gmqpdmt0 = 5;
                break;
            case 5:
                return j_468tmzoa;
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

__attribute__((used)) static int32_t j_z_5ppufq(int32_t j_n) {
    int32_t j_s = 0;
    int32_t j_i = 1;
    while (j_i <= j_n) {
        if ((j_i % ((0 + 3) ^ (2750 ^ 2750))) == (0 + 0)) j_s = j_s + j_i;
        else j_s = j_s + j_i * ((1 + 1) ^ (9081 ^ 9081));
        j_i = j_i + 1;
    }
    return j_s;
}

__attribute__((used)) static int32_t j_z_x7fm52(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = 0;
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % 10007;
        j_t = j_t + (0 + 1);
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_hy797h(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = (0 + 0);
    while (j_t < j_b) {
        j_r = (j_r * ((10 + 21) ^ (5356 ^ 5356)) + j_c) % 10007;
        j_t = j_t + 1;
    }
    return j_r;
}

static int32_t j_tr_w8kitx(void) {
    int32_t j_kiietxma = ((0 + 0) ^ (3009 ^ 3009));
    while ((j_kiietxma != -(0 + 1)))
    {
        switch (j_kiietxma)
        {
            case 0:
                static volatile int64_t j_v3huvf2v = 211;
                if ((((j_v3huvf2v * j_v3huvf2v) + j_v3huvf2v) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_50() : j_dc_51());
                }
                j_kiietxma = 1;
                break;
            case 1:
                (void)printf("%s\n", j_dc_52());
                int32_t j_qb8n9rkr = 1;
                static volatile int64_t j_fy0gpnl9 = 2698;
                static volatile int64_t j_c1wchsa4 = 34428;
                if ((((j_c1wchsa4 * j_c1wchsa4) + j_c1wchsa4) < (0 + 0)))
                {
                    volatile int64_t j_lyd9q6x2 = ((j_c1wchsa4 * 46) + (254 + 174));
                    (void)printf("%s\n", 0 ? j_dc_53() : j_dc_54());
                }
                j_kiietxma = (0 + 2);
                break;
            case 2:
                if ((((j_fy0gpnl9 * j_fy0gpnl9) + j_fy0gpnl9) >= (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (3135 ^ 3135)) ? j_dc_55() : j_dc_56());
                }
                j_kiietxma = ((2 + 1) ^ (4652 ^ 4652));
                break;
            case 3:
                while ((j_qb8n9rkr <= 8))
                {
                    (void)printf("%d\n", j_oiwo6t0n(j_qb8n9rkr));
                    j_qb8n9rkr = (j_qb8n9rkr + (0 + 1));
                }
                j_kiietxma = (0 + 4);
                break;
            case 4:
                static volatile int64_t j_xsop1o4p = 62587;
                if ((((j_xsop1o4p * j_xsop1o4p) + j_xsop1o4p) >= 0))
                {
                    (void)printf("%s\n", j_dc_57());
                }
                else
                {
                    volatile int64_t j_ney0af9f = ((j_xsop1o4p * (2 + 0)) + 1);
                }
                j_kiietxma = (5 + 0);
                break;
            case 5:
                for (int32_t j_dj8cfjgn = -(3); (j_dj8cfjgn <= 6); j_dj8cfjgn = (j_dj8cfjgn + (0 + 1)))
                {
                    (void)printf("%s\n", j_4f7g6fui(j_dj8cfjgn));
                }
                j_kiietxma = 6;
                break;
            case 6:
                (void)printf("%s\n", j_dc_58());
                static volatile int64_t j_mbs50pn8 = (1675 + 212);
                if ((((j_mbs50pn8 * j_mbs50pn8) + j_mbs50pn8) < 0))
                {
                    volatile int64_t j_gzdn22af = ((j_mbs50pn8 * ((17 + 38) ^ (1465 ^ 1465))) + 887);
                    (void)printf("%s\n", (0 + 0) ? j_dc_59() : j_dc_60());
                }
                j_kiietxma = 7;
                break;
            case 7:
                int32_t j_2ct6q877 = (0 + 0);
                int32_t j_zjsufqwi = 1;
                while ((j_zjsufqwi <= (2 + 8)))
                {
                    j_2ct6q877 = (j_2ct6q877 + j_oiwo6t0n(j_zjsufqwi));
                    j_zjsufqwi = (j_zjsufqwi + (1 + 0));
                }
                j_kiietxma = ((1 + 7) ^ (8635 ^ 8635));
                break;
            case 8:
                (void)printf("%d\n", j_2ct6q877);
                static volatile int64_t j_f1hbv9t4 = 11559;
                if ((((j_f1hbv9t4 * j_f1hbv9t4) + j_f1hbv9t4) < ((0 + 0) ^ (8778 ^ 8778))))
                {
                    volatile int64_t j_v19rzg9k = ((j_f1hbv9t4 * 83) + ((322 + 237) ^ (283 ^ 283)));
                    (void)printf("%s\n", 0 ? j_dc_61() : j_dc_62());
                }
                j_kiietxma = 9;
                break;
            case 9:
                (void)printf("%s\n", j_dc_63());
                (void)printf("%s\n", j_dc_64());
                static volatile int64_t j_kwyqhptu = 66990;
                if ((((j_kwyqhptu * j_kwyqhptu) % 4) == (0 + 3)))
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_65() : j_dc_66());
                }
                j_kiietxma = -((1 + 0) ^ (4440 ^ 4440));
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (7084 ^ 7084));
}
static int32_t j_tr_bib5dw(void) { return j_tr_w8kitx(); }
static int32_t j_tr_zyw4k4(void) { return j_tr_bib5dw(); }
int32_t main(void) { return j_tr_zyw4k4(); }

