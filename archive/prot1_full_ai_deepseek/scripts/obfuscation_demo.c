// JOCKY build 87A9F8B641C7EB81 seed=1 date=2026-09-03 04:27:14
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

static const volatile uint8_t j_enc_0[] = {0xEB, 0xEA, 0xE9, 0xE8, 0xEF, 0xEE, 0xED, 0xEC, 0xE3, 0xE2, 0xBA, 0xB9, 0xB8, 0xBF, 0xBE, 0xBD};
static const char* j_dc_0(void) {
    static char j_rb[((15 + 2) ^ (3853 ^ 3853))];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ ((145 + 74) ^ (7528 ^ 7528));
    j_rb[16] = ((0 + 0) ^ (6829 ^ 6829));
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0x1D, 0x1C, 0x1F, 0x1E, 0x19, 0x18, 0x1B, 0x1A, 0x15, 0x14, 0x4C, 0x4F, 0x4E, 0x49, 0x48, 0x4B};
static const char* j_dc_1(void) {
    static char j_rb[(14 + 3)];
    for (int j_i = (0 + 0); j_i < ((16 + 0) ^ (4919 ^ 4919)); j_i++) j_rb[j_i] = j_enc_1[j_i] ^ 45;
    j_rb[((6 + 10) ^ (5690 ^ 5690))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0x59, 0x49};
static const char* j_dc_2(void) {
    static char j_rb[3];
    for (int j_i = ((0 + 0) ^ (1498 ^ 1498)); j_i < 2; j_i++) j_rb[j_i] = j_enc_2[j_i] ^ 43;
    j_rb[((2 + 0) ^ (3525 ^ 3525))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0x97, 0x82};
static const char* j_dc_3(void) {
    static char j_rb[((2 + 1) ^ (2545 ^ 2545))];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ ((184 + 40) ^ (9524 ^ 9524));
    j_rb[(0 + 2)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0xFF, 0xA0, 0xA2, 0xBF, 0xB3};
static const char* j_dc_4(void) {
    static char j_rb[((0 + 6) ^ (7257 ^ 7257))];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ 208;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xA6};
static const char* j_dc_5(void) {
    static char j_rb[((0 + 2) ^ (4941 ^ 4941))];
    for (int j_i = (0 + 0); j_i < (1 + 0); j_i++) j_rb[j_i] = j_enc_5[j_i] ^ ((55 + 157) ^ (6765 ^ 6765));
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0x75};
static const char* j_dc_6(void) {
    static char j_rb[(0 + 2)];
    for (int j_i = (0 + 0); j_i < 1; j_i++) j_rb[j_i] = j_enc_6[j_i] ^ (63 + 64);
    j_rb[1] = ((0 + 0) ^ (374 ^ 374));
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0x35};
static const char* j_dc_7(void) {
    static char j_rb[((0 + 2) ^ (8702 ^ 8702))];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_7[j_i] ^ (3 + 68);
    j_rb[1] = ((0 + 0) ^ (621 ^ 621));
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0xBC};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 131;
    j_rb[1] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0x24, 0x21, 0x3B, 0x3C, 0x2D, 0x26};
static const char* j_dc_9(void) {
    static char j_rb[7];
    for (int j_i = 0; j_i < 6; j_i++) j_rb[j_i] = j_enc_9[j_i] ^ 104;
    j_rb[6] = ((0 + 0) ^ (4175 ^ 4175));
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0xB6, 0xA0, 0xA7, 0xB2, 0xB1, 0xBF, 0xBA, 0xA0, 0xBB, 0xB6, 0xB7};
static const char* j_dc_10(void) {
    static char j_rb[(2 + 10)];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_10[j_i] ^ 243;
    j_rb[11] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0xDB, 0xD4, 0xD7, 0xCB, 0xDD, 0xC7, 0xCF, 0xD9, 0xD1, 0xCC};
static const char* j_dc_11(void) {
    static char j_rb[(9 + 2)];
    for (int j_i = ((0 + 0) ^ (9290 ^ 9290)); j_i < ((3 + 7) ^ (6240 ^ 6240)); j_i++) j_rb[j_i] = j_enc_11[j_i] ^ ((116 + 36) ^ (822 ^ 822));
    j_rb[10] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0xD6, 0xCB, 0xCF, 0xC7, 0xDD, 0xD5, 0xC3, 0xCB, 0xD6};
static const char* j_dc_12(void) {
    static char j_rb[10];
    for (int j_i = 0; j_i < (1 + 8); j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 130;
    j_rb[9] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x72, 0x69, 0x75, 0x78, 0x6F};
static const char* j_dc_13(void) {
    static char j_rb[((2 + 4) ^ (456 ^ 456))];
    for (int j_i = ((0 + 0) ^ (3893 ^ 3893)); j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 61;
    j_rb[((3 + 2) ^ (7399 ^ 7399))] = ((0 + 0) ^ (2167 ^ 2167));
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0xE3, 0xE8, 0xF9, 0xFE, 0xF9, 0xEC, 0xF9, 0xAD, 0xA0, 0xEC, 0xE3, 0xAD, 0xA0, 0xFD, 0xAD, 0xF9, 0xEE, 0xFD, 0xAD, 0xBF, 0xB3, 0xA2, 0xE9, 0xE8, 0xFB, 0xA2, 0xE3, 0xF8, 0xE1, 0xE1};
static const char* j_dc_14(void) {
    static char j_rb[31];
    for (int j_i = ((0 + 0) ^ (7928 ^ 7928)); j_i < 30; j_i++) j_rb[j_i] = j_enc_14[j_i] ^ 141;
    j_rb[((6 + 24) ^ (6578 ^ 6578))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0xF2};
static const char* j_dc_15(void) {
    static char j_rb[(2 + 0)];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 128;
    j_rb[(0 + 1)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0x4C, 0x5B, 0x48};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = (0 + 0); j_i < (3 + 0); j_i++) j_rb[j_i] = j_enc_16[j_i] ^ (24 + 32);
    j_rb[(0 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0x39, 0x66, 0x64, 0x79, 0x75, 0x39, 0x78, 0x73, 0x62, 0x39, 0x62, 0x75, 0x66};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < ((0 + 13) ^ (3449 ^ 3449)); j_i++) j_rb[j_i] = j_enc_17[j_i] ^ 22;
    j_rb[(5 + 8)] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0xCF, 0x90, 0x92, 0x8F, 0x83, 0xCF, 0x8E, 0x85, 0x94, 0xCF, 0x94, 0x83, 0x90, 0xD6};
static const char* j_dc_18(void) {
    static char j_rb[15];
    for (int j_i = ((0 + 0) ^ (9592 ^ 9592)); j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ 224;
    j_rb[((10 + 4) ^ (4879 ^ 4879))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0xF2, 0xF1, 0xF6, 0xF7, 0xE6};
static const char* j_dc_19(void) {
    static char j_rb[((1 + 5) ^ (6701 ^ 6701))];
    for (int j_i = 0; j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_19[j_i] ^ ((6 + 180) ^ (4926 ^ 4926));
    j_rb[5] = ((0 + 0) ^ (6448 ^ 6448));
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0xE9, 0xEA, 0xE2, 0xF4, 0xFD};
static const char* j_dc_20(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((0 + 5) ^ (2439 ^ 2439)); j_i++) j_rb[j_i] = j_enc_20[j_i] ^ ((30 + 131) ^ (9017 ^ 9017));
    j_rb[5] = ((0 + 0) ^ (1034 ^ 1034));
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x31, 0x32, 0x3A, 0x2B, 0x25};
static const char* j_dc_21(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = (0 + 0); j_i < (4 + 1); j_i++) j_rb[j_i] = j_enc_21[j_i] ^ 121;
    j_rb[((5 + 0) ^ (2378 ^ 2378))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0xA8, 0xAB, 0xB5, 0xBC};
static const char* j_dc_22(void) {
    static char j_rb[((2 + 3) ^ (8565 ^ 8565))];
    for (int j_i = ((0 + 0) ^ (8220 ^ 8220)); j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ (80 + 144);
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0x99, 0x8C};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_23[j_i] ^ ((205 + 33) ^ (5097 ^ 5097));
    j_rb[2] = ((0 + 0) ^ (5487 ^ 5487));
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0x32, 0x34, 0x33, 0x23};
static const char* j_dc_24(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = (0 + 0); j_i < ((3 + 1) ^ (8976 ^ 8976)); j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 70;
    j_rb[((2 + 2) ^ (7736 ^ 7736))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0x29, 0x2E, 0x23, 0x3C, 0x2A};
static const char* j_dc_25(void) {
    static char j_rb[((3 + 3) ^ (4410 ^ 4410))];
    for (int j_i = 0; j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_25[j_i] ^ ((2 + 77) ^ (4738 ^ 4738));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x4B, 0x40, 0x42, 0x44, 0x51, 0x4C, 0x53, 0x40};
static const char* j_dc_26(void) {
    static char j_rb[(9 + 0)];
    for (int j_i = ((0 + 0) ^ (4500 ^ 4500)); j_i < (8 + 0); j_i++) j_rb[j_i] = j_enc_26[j_i] ^ ((23 + 14) ^ (6979 ^ 6979));
    j_rb[(1 + 7)] = ((0 + 0) ^ (8131 ^ 8131));
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0x70, 0x76, 0x71, 0x61};
static const char* j_dc_27(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 4;
    j_rb[((4 + 0) ^ (5616 ^ 5616))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x7C, 0x7B, 0x76, 0x69, 0x7F};
static const char* j_dc_28(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_28[j_i] ^ ((19 + 7) ^ (6053 ^ 6053));
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0x94, 0x92, 0x95, 0x85};
static const char* j_dc_29(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_29[j_i] ^ (180 + 44);
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0xF8, 0xFF, 0xF2, 0xED, 0xFB};
static const char* j_dc_30(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_30[j_i] ^ 158;
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0x9C, 0x83, 0x94, 0x89};
static const char* j_dc_31(void) {
    static char j_rb[((0 + 5) ^ (6088 ^ 6088))];
    for (int j_i = 0; j_i < ((3 + 1) ^ (1896 ^ 1896)); j_i++) j_rb[j_i] = j_enc_31[j_i] ^ 230;
    j_rb[((0 + 4) ^ (9841 ^ 9841))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0xF2, 0xE1, 0xF2, 0xF9};
static const char* j_dc_32(void) {
    static char j_rb[(2 + 3)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_32[j_i] ^ ((31 + 120) ^ (3887 ^ 3887));
    j_rb[(3 + 1)] = ((0 + 0) ^ (4658 ^ 4658));
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0x88, 0x8E, 0x89, 0x99};
static const char* j_dc_33(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (2106 ^ 2106)); j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_33[j_i] ^ 252;
    j_rb[4] = ((0 + 0) ^ (8445 ^ 8445));
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x90, 0x97, 0x9A, 0x85, 0x93};
static const char* j_dc_34(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < ((1 + 4) ^ (6849 ^ 6849)); j_i++) j_rb[j_i] = j_enc_34[j_i] ^ (131 + 115);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0x4E, 0x48, 0x4F, 0x5F};
static const char* j_dc_35(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (4909 ^ 4909)); j_i < 4; j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 58;
    j_rb[4] = ((0 + 0) ^ (9100 ^ 9100));
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0x65, 0x62, 0x6F, 0x70, 0x66};
static const char* j_dc_36(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 3;
    j_rb[(1 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0x51, 0x5A, 0x5A};
static const char* j_dc_37(void) {
    static char j_rb[4];
    for (int j_i = ((0 + 0) ^ (7621 ^ 7621)); j_i < 3; j_i++) j_rb[j_i] = j_enc_37[j_i] ^ (35 + 27);
    j_rb[3] = ((0 + 0) ^ (9127 ^ 9127));
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0x91, 0x97, 0x90, 0x80};
static const char* j_dc_38(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (0 + 4); j_i++) j_rb[j_i] = j_enc_38[j_i] ^ (174 + 55);
    j_rb[((4 + 0) ^ (7465 ^ 7465))] = ((0 + 0) ^ (5580 ^ 5580));
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x67, 0x60, 0x6D, 0x72, 0x64};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_39[j_i] ^ 1;
    j_rb[((2 + 3) ^ (5171 ^ 5171))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0x91, 0x97, 0x90, 0x80};
static const char* j_dc_40(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_40[j_i] ^ 229;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0xD3, 0xD4, 0xD9, 0xC6, 0xD0};
static const char* j_dc_41(void) {
    static char j_rb[(2 + 4)];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_41[j_i] ^ ((140 + 41) ^ (2067 ^ 2067));
    j_rb[((1 + 4) ^ (1421 ^ 1421))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0xD7, 0xD1, 0xD6, 0xC6};
static const char* j_dc_42(void) {
    static char j_rb[((4 + 1) ^ (6237 ^ 6237))];
    for (int j_i = (0 + 0); j_i < 4; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ 163;
    j_rb[4] = ((0 + 0) ^ (7653 ^ 7653));
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0x88, 0x8F, 0x82, 0x9D, 0x8B};
static const char* j_dc_43(void) {
    static char j_rb[((2 + 4) ^ (3318 ^ 3318))];
    for (int j_i = (0 + 0); j_i < (5 + 0); j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 238;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x7F, 0x79, 0x7E, 0x6E};
static const char* j_dc_44(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = ((0 + 0) ^ (103 ^ 103)); j_i < 4; j_i++) j_rb[j_i] = j_enc_44[j_i] ^ ((11 + 0) ^ (1401 ^ 1401));
    j_rb[((4 + 0) ^ (7457 ^ 7457))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0xC3, 0xC4, 0xC9, 0xD6, 0xC0};
static const char* j_dc_45(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = 0; j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_45[j_i] ^ 165;
    j_rb[((2 + 3) ^ (4725 ^ 4725))] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0x0A, 0x0C, 0x0B, 0x1B};
static const char* j_dc_46(void) {
    static char j_rb[5];
    for (int j_i = ((0 + 0) ^ (8752 ^ 8752)); j_i < ((0 + 4) ^ (4641 ^ 4641)); j_i++) j_rb[j_i] = j_enc_46[j_i] ^ (54 + 72);
    j_rb[(0 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x3D, 0x3A, 0x37, 0x28, 0x3E};
static const char* j_dc_47(void) {
    static char j_rb[(0 + 6)];
    for (int j_i = 0; j_i < (4 + 1); j_i++) j_rb[j_i] = j_enc_47[j_i] ^ 91;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0x56, 0x50, 0x57, 0x47};
static const char* j_dc_48(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_48[j_i] ^ ((7 + 27) ^ (5781 ^ 5781));
    j_rb[(1 + 3)] = ((0 + 0) ^ (5043 ^ 5043));
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0x55, 0x52, 0x5F, 0x40, 0x56};
static const char* j_dc_49(void) {
    static char j_rb[((4 + 2) ^ (1433 ^ 1433))];
    for (int j_i = ((0 + 0) ^ (6116 ^ 6116)); j_i < (3 + 2); j_i++) j_rb[j_i] = j_enc_49[j_i] ^ ((44 + 7) ^ (9815 ^ 9815));
    j_rb[(1 + 4)] = ((0 + 0) ^ (4564 ^ 4564));
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0xF2, 0xF4, 0xF3, 0xE3};
static const char* j_dc_50(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_50[j_i] ^ (70 + 64);
    j_rb[(1 + 3)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0xFB, 0xFC, 0xF1, 0xEE, 0xF8};
static const char* j_dc_51(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < (1 + 4); j_i++) j_rb[j_i] = j_enc_51[j_i] ^ 157;
    j_rb[(1 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0xDC, 0xDA, 0xDD, 0xCD};
static const char* j_dc_52(void) {
    static char j_rb[((4 + 1) ^ (8865 ^ 8865))];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_52[j_i] ^ 168;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0xC5, 0xC2, 0xCF, 0xD0, 0xC6};
static const char* j_dc_53(void) {
    static char j_rb[((5 + 1) ^ (5861 ^ 5861))];
    for (int j_i = ((0 + 0) ^ (1903 ^ 1903)); j_i < ((2 + 3) ^ (2281 ^ 2281)); j_i++) j_rb[j_i] = j_enc_53[j_i] ^ ((96 + 67) ^ (6149 ^ 6149));
    j_rb[((1 + 4) ^ (1525 ^ 1525))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0xA6, 0xA0, 0xA7, 0xB7};
static const char* j_dc_54(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ ((167 + 43) ^ (2207 ^ 2207));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0xFA, 0xFD, 0xF0, 0xEF, 0xF9};
static const char* j_dc_55(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (4232 ^ 4232)); j_i < 5; j_i++) j_rb[j_i] = j_enc_55[j_i] ^ 156;
    j_rb[5] = ((0 + 0) ^ (262 ^ 262));
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0xCC, 0xCA, 0xCD, 0xDD};
static const char* j_dc_56(void) {
    static char j_rb[(4 + 1)];
    for (int j_i = ((0 + 0) ^ (8571 ^ 8571)); j_i < 4; j_i++) j_rb[j_i] = j_enc_56[j_i] ^ (15 + 169);
    j_rb[4] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0x35, 0x32, 0x3F, 0x20, 0x36};
static const char* j_dc_57(void) {
    static char j_rb[6];
    for (int j_i = (0 + 0); j_i < 5; j_i++) j_rb[j_i] = j_enc_57[j_i] ^ ((73 + 10) ^ (8216 ^ 8216));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0x2E, 0x28, 0x2F, 0x3F};
static const char* j_dc_58(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = (0 + 0); j_i < (3 + 1); j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 90;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0xF2, 0xF5, 0xF8, 0xE7, 0xF1};
static const char* j_dc_59(void) {
    static char j_rb[((3 + 3) ^ (5751 ^ 5751))];
    for (int j_i = ((0 + 0) ^ (1340 ^ 1340)); j_i < (2 + 3); j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 148;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0xC0, 0xC6, 0xC1, 0xD1};
static const char* j_dc_60(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_60[j_i] ^ ((50 + 130) ^ (2190 ^ 2190));
    j_rb[(0 + 4)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_61[] = {0x30, 0x37, 0x3A, 0x25, 0x33};
static const char* j_dc_61(void) {
    static char j_rb[((0 + 6) ^ (2855 ^ 2855))];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_61[j_i] ^ (30 + 56);
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_62[] = {0x8D, 0x8B, 0x8C, 0x9C};
static const char* j_dc_62(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = (0 + 0); j_i < (4 + 0); j_i++) j_rb[j_i] = j_enc_62[j_i] ^ 249;
    j_rb[((4 + 0) ^ (695 ^ 695))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_63[] = {0xFC, 0xFB, 0xF6, 0xE9, 0xFF};
static const char* j_dc_63(void) {
    static char j_rb[(4 + 2)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_63[j_i] ^ (76 + 78);
    j_rb[(3 + 2)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_64[] = {0x98, 0x98, 0x98, 0x85, 0xE6, 0xEA, 0xE9, 0xE9, 0xE4, 0xF1, 0xFF, 0x85, 0xF6, 0xF1, 0xE0, 0xF5, 0xF6, 0x85, 0x98, 0x98, 0x98};
static const char* j_dc_64(void) {
    static char j_rb[22];
    for (int j_i = 0; j_i < 21; j_i++) j_rb[j_i] = j_enc_64[j_i] ^ 165;
    j_rb[(7 + 14)] = ((0 + 0) ^ (9296 ^ 9296));
    return j_rb;
}

static const volatile uint8_t j_enc_65[] = {0x2A, 0x2C, 0x2B, 0x3B};
static const char* j_dc_65(void) {
    static char j_rb[((1 + 4) ^ (2190 ^ 2190))];
    for (int j_i = ((0 + 0) ^ (684 ^ 684)); j_i < 4; j_i++) j_rb[j_i] = j_enc_65[j_i] ^ ((2 + 92) ^ (8815 ^ 8815));
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_66[] = {0x52, 0x55, 0x58, 0x47, 0x51};
static const char* j_dc_66(void) {
    static char j_rb[(1 + 5)];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_66[j_i] ^ ((24 + 28) ^ (4874 ^ 4874));
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_67[] = {0x8E, 0x8E, 0x8E, 0x93, 0xF0, 0xFF, 0xF2, 0xE0, 0xE0, 0xFA, 0xF5, 0xFA, 0xF0, 0xF2, 0xE7, 0xFA, 0xFC, 0xFD, 0x93, 0x8E, 0x8E, 0x8E};
static const char* j_dc_67(void) {
    static char j_rb[23];
    for (int j_i = ((0 + 0) ^ (9784 ^ 9784)); j_i < 22; j_i++) j_rb[j_i] = j_enc_67[j_i] ^ 179;
    j_rb[(14 + 8)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_68[] = {0x08, 0x08, 0x08, 0x15, 0x74, 0x72, 0x72, 0x67, 0x70, 0x72, 0x74, 0x61, 0x70, 0x15, 0x08, 0x08, 0x08};
static const char* j_dc_68(void) {
    static char j_rb[((2 + 16) ^ (1487 ^ 1487))];
    for (int j_i = 0; j_i < 17; j_i++) j_rb[j_i] = j_enc_68[j_i] ^ 53;
    j_rb[((5 + 12) ^ (1188 ^ 1188))] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_69[] = {0x4B, 0x4D, 0x4A, 0x5A};
static const char* j_dc_69(void) {
    static char j_rb[5];
    for (int j_i = (0 + 0); j_i < (1 + 3); j_i++) j_rb[j_i] = j_enc_69[j_i] ^ 63;
    j_rb[4] = ((0 + 0) ^ (9235 ^ 9235));
    return j_rb;
}

static const volatile uint8_t j_enc_70[] = {0x76, 0x71, 0x7C, 0x63, 0x75};
static const char* j_dc_70(void) {
    static char j_rb[6];
    for (int j_i = ((0 + 0) ^ (5594 ^ 5594)); j_i < 5; j_i++) j_rb[j_i] = j_enc_70[j_i] ^ 16;
    j_rb[((2 + 3) ^ (117 ^ 117))] = ((0 + 0) ^ (5852 ^ 5852));
    return j_rb;
}

static const volatile uint8_t j_enc_71[] = {0xC1, 0xC7, 0xC0, 0xD0};
static const char* j_dc_71(void) {
    static char j_rb[(1 + 4)];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_71[j_i] ^ (178 + 3);
    j_rb[4] = ((0 + 0) ^ (7088 ^ 7088));
    return j_rb;
}

static const volatile uint8_t j_enc_72[] = {0x8B, 0x8C, 0x81, 0x9E, 0x88};
static const char* j_dc_72(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_72[j_i] ^ 237;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_73[] = {0x6E, 0x68, 0x6F, 0x7F};
static const char* j_dc_73(void) {
    static char j_rb[(5 + 0)];
    for (int j_i = ((0 + 0) ^ (8691 ^ 8691)); j_i < (2 + 2); j_i++) j_rb[j_i] = j_enc_73[j_i] ^ ((26 + 0) ^ (5530 ^ 5530));
    j_rb[(4 + 0)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_74[] = {0x68, 0x6F, 0x62, 0x7D, 0x6B};
static const char* j_dc_74(void) {
    static char j_rb[((6 + 0) ^ (1770 ^ 1770))];
    for (int j_i = ((0 + 0) ^ (1309 ^ 1309)); j_i < ((5 + 0) ^ (1887 ^ 1887)); j_i++) j_rb[j_i] = j_enc_74[j_i] ^ ((2 + 12) ^ (2424 ^ 2424));
    j_rb[5] = (0 + 0);
    return j_rb;
}

static const volatile uint8_t j_enc_75[] = {0xBC, 0xBC, 0xBC, 0xA1, 0xD3, 0xC4, 0xD2, 0xD4, 0xCD, 0xD5, 0xA1, 0xBC, 0xBC, 0xBC};
static const char* j_dc_75(void) {
    static char j_rb[15];
    for (int j_i = ((0 + 0) ^ (4859 ^ 4859)); j_i < ((13 + 1) ^ (9542 ^ 9542)); j_i++) j_rb[j_i] = j_enc_75[j_i] ^ 129;
    j_rb[(5 + 9)] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_76[] = {0x3F, 0x32, 0x32, 0x7E, 0x3C, 0x2B, 0x37, 0x32, 0x3A, 0x2D, 0x7E, 0x2E, 0x2C, 0x31, 0x3A, 0x2B, 0x3D, 0x3B, 0x7E, 0x37, 0x3A, 0x3B, 0x30, 0x2A, 0x37, 0x3D, 0x3F, 0x32, 0x7E, 0x31, 0x2B, 0x2A, 0x2E, 0x2B, 0x2A};
static const char* j_dc_76(void) {
    static char j_rb[(17 + 19)];
    for (int j_i = (0 + 0); j_i < 35; j_i++) j_rb[j_i] = j_enc_76[j_i] ^ 94;
    j_rb[(30 + 5)] = 0;
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == (0 + 0); }

static char j_buf[(53167 + 12369)];
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
                    out[o++] = j_dc_0()[c >> (0 + 4)];
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
    ts.tv_sec = ms / (233 + 767);
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
    size_t off = ((0 + 0) ^ (9471 ^ 9471));
    j_buf[off++] = '[';
    int first = (0 + 1);
#if defined(_WIN32)
    char pattern[(20 + 1004)];
    snprintf(pattern, sizeof pattern, "%s\\*", dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pattern, &fd);
    if (h != INVALID_HANDLE_VALUE) {
        do {
            if (fd.cFileName[((0 + 0) ^ (9768 ^ 9768))] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = ((0 + 0) ^ (1780 ^ 1780));
            char esc[((970 + 54) ^ (9679 ^ 9679))];
            j_json_escape(esc, sizeof esc, fd.cFileName);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : ((0 + 0) ^ (8115 ^ 8115)));
        } while (FindNextFileA(h, &fd));
        FindClose(h);
    }
#else
    DIR* d = opendir(dir);
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[((0 + 0) ^ (8359 ^ 8359))] == '.') continue;
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[((108 + 916) ^ (8100 ^ 8100))];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > (0 + 0) ? n : ((0 + 0) ^ (1186 ^ 1186)));
        }
        closedir(d);
    }
#endif
    j_buf[off++] = ']';
    j_buf[off] = '\0';
    return j_buf;
}

static const char* j_sys_process_list(void) {
    size_t off = (0 + 0);
    j_buf[off++] = '[';
    int first = (0 + 1);
#if defined(_WIN32)
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32W pe;
        pe.dwSize = sizeof pe;
        if (Process32FirstW(snap, &pe)) {
            do {
                if (off > J_BUF_CAP - 400) break;
                char name[1024];
                size_t k = 0;
                for (size_t i = 0; pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[((1952 + 96) ^ (553 ^ 553))];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%lu,\"name\":\"%s\"}", (unsigned long)pe.th32ProcessID, esc);
                off += (size_t)(n > (0 + 0) ? n : (0 + 0));
            } while (Process32NextW(snap, &pe));
        }
        CloseHandle(snap);
    }
#elif defined(__APPLE__)
    int all_pids[(3310 + 4882)];
    int np = proc_listallpids(all_pids, sizeof all_pids);
    for (int i = ((0 + 0) ^ (7419 ^ 7419)); i < np; ++i) {
        int pid = all_pids[i];
        if (off > J_BUF_CAP - 400) break;
        char name[(115 + 141)];
        int len = proc_name(pid, name, sizeof name);
        if (len <= (0 + 0)) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = (0 + 0);
        char esc[512];
        j_json_escape(esc, sizeof esc, name);
        int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
        off += (size_t)(n > 0 ? n : 0);
    }
#else
    DIR* d = opendir(j_dc_4());
    if (d) {
        struct dirent* de;
        while ((de = readdir(d)) != NULL) {
            if (de->d_name[0] < '0' || de->d_name[(0 + 0)] > '9') continue;
            int pid = atoi(de->d_name);
            char p[64], name[(140 + 116)];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - ((116 + 284) ^ (4975 ^ 4975))) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[(296 + 216)];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > (0 + 0) ? n : ((0 + 0) ^ (3426 ^ 3426)));
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
    char line[(410 + 102)];
    int skip = (1 + 0);
    while (fgets(line, sizeof line, f)) {
        if (skip) { skip = (0 + 0); continue; }
        char laddr[(27 + 37)], raddr[64], st[(1 + 15)];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != 3) continue;
        if (*off > J_BUF_CAP - 300) break;
        if (!*first) j_buf[(*off)++] = ',';
        *first = ((0 + 0) ^ (6717 ^ 6717));
        int n = snprintf(j_buf + *off, J_BUF_CAP - *off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", laddr, raddr, st);
        *off += (size_t)(n > 0 ? n : (0 + 0));
    }
    fclose(f);
}

static const char* j_net_sockets(void) {
    size_t off = 0;
    j_buf[off++] = '[';
    int first = (1 + 0);
#if defined(_WIN32)
    ULONG sz = 0;
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, ((0 + 0) ^ (8004 ^ 8004)));
    char* t = (char*)malloc(sz ? sz : ((1 + 0) ^ (7685 ^ 7685)));
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, ((0 + 0) ^ (1369 ^ 1369))) == NO_ERROR) {
            for (DWORD i = 0; i < tab->dwNumEntries; ++i) {
                MIB_TCPROW_OWNER_PID* r = &tab->table[i];
                char li[((26 + 38) ^ (8845 ^ 8845))], ri[((49 + 15) ^ (7544 ^ 7544))];
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
                if (off > J_BUF_CAP - (153 + 147)) break;
                if (!first) j_buf[off++] = ',';
                first = (0 + 0);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > 0 ? n : (0 + 0));
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[(6 + 2)], laddr[64], raddr[64], st[32];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == 4) {
                if (strncmp(proto, j_dc_16(), 3) != 0) continue;
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = ((0 + 0) ^ (5370 ^ 5370));
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
    int first = (1 + 0);
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), (1 + 4)) == ((0 + 0) ^ (5477 ^ 5477))) { root = HKEY_LOCAL_MACHINE; sub = key + ((2 + 3) ^ (1558 ^ 1558)); }
    else if (strncmp(key, j_dc_20(), ((2 + 3) ^ (8400 ^ 8400))) == 0) { root = HKEY_CURRENT_USER; sub = key + ((1 + 4) ^ (1366 ^ 1366)); }
    else if (strncmp(key, j_dc_21(), ((2 + 3) ^ (2493 ^ 2493))) == 0) { root = HKEY_CLASSES_ROOT; sub = key + ((1 + 4) ^ (5748 ^ 5748)); }
    else if (strncmp(key, j_dc_22(), 4) == ((0 + 0) ^ (8899 ^ 8899))) { root = HKEY_USERS; sub = key + 4; }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, ((0 + 0) ^ (9729 ^ 9729)), KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = 0; ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - (291 + 109)) break;
            if (!first) j_buf[off++] = ',';
            first = (0 + 0);
            char esc[((458 + 54) ^ (728 ^ 728))];
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
    unsigned long regions = ((0 + 0) ^ (5789 ^ 5789));
    while (VirtualQueryEx(h, base, &mbi, sizeof mbi) == sizeof mbi && regions++ < (31643 + 68357)) {
        if (mbi.State == MEM_COMMIT && !(mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) &&
            (mbi.Protect == PAGE_READWRITE || mbi.Protect == PAGE_READONLY ||
             mbi.Protect == PAGE_EXECUTE_READWRITE || mbi.Protect == PAGE_EXECUTE_READ)) {
            unsigned char* chunk = (unsigned char*)malloc(mbi.RegionSize ? mbi.RegionSize : 1);
            SIZE_T read = (0 + 0);
            if (chunk && ReadProcessMemory(h, mbi.BaseAddress, chunk, mbi.RegionSize, &read) && read) {
                fwrite(chunk, (1 + 0), read, out);
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

static volatile int32_t j_u0yg17qi = 11090;
static volatile int32_t j_66zt01po = (28634 + 6689);

static const char* j_6gssa7uj(int32_t j_6euxfluj);
static int32_t j_n49ux56p(int32_t j_6euxfluj);
static int32_t j_xg1b6c1n(int32_t j_6euxfluj);

static const char* j_6gssa7uj(int32_t j_6euxfluj)
{
    int32_t j_myf0h1xk = ((0 + 0) ^ (9546 ^ 9546));
    while ((j_myf0h1xk != -(0 + 1)))
    {
        switch (j_myf0h1xk)
        {
            case 0:
                static volatile int64_t j_zpha6hrr = 37400;
                if ((((j_zpha6hrr * j_zpha6hrr) + j_zpha6hrr) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_24() : j_dc_25());
                }
                j_myf0h1xk = 1;
                break;
            case 1:
                if ((j_6euxfluj < (0 + 0)))
                {
                    return j_dc_26();
                }
                j_myf0h1xk = ((0 + 2) ^ (7285 ^ 7285));
                break;
            case 2:
                static volatile int64_t j_5osqeg9x = ((29343 + 2180) ^ (581 ^ 581));
                if ((((j_5osqeg9x * j_5osqeg9x) + j_5osqeg9x) < 0))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (6331 ^ 6331)) ? j_dc_27() : j_dc_28());
                }
                j_myf0h1xk = (3 + 0);
                break;
            case 3:
                static volatile int64_t j_5rzljczn = 86848;
                if ((((j_5rzljczn * j_5rzljczn) % 4) < (1 + 1)))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_29() : j_dc_30());
                }
                j_myf0h1xk = 4;
                break;
            case 4:
                if ((j_6euxfluj == (0 + 0)))
                {
                    return j_dc_31();
                }
                j_myf0h1xk = 5;
                break;
            case 5:
                if (((j_6euxfluj % (1 + 1)) == ((0 + 0) ^ (1557 ^ 1557))))
                {
                    return j_dc_32();
                }
                j_myf0h1xk = ((1 + 5) ^ (4299 ^ 4299));
                break;
            case 6:
                static volatile int64_t j_b8aacxad = 56229;
                if ((((j_b8aacxad * j_b8aacxad) + j_b8aacxad) < (0 + 0)))
                {
                    volatile int64_t j_10s9i6c6 = ((j_b8aacxad * 21) + (152 + 77));
                    (void)printf("%s\n", (0 + 0) ? j_dc_33() : j_dc_34());
                }
                j_myf0h1xk = ((5 + 2) ^ (3633 ^ 3633));
                break;
            case 7:
                static volatile int64_t j_x6f0al08 = (11243 + 28374);
                if ((((j_x6f0al08 * j_x6f0al08) + j_x6f0al08) < 0))
                {
                    volatile int64_t j_o3mndp56 = ((j_x6f0al08 * (0 + 15)) + (288 + 329));
                    (void)printf("%s\n", (0 + 0) ? j_dc_35() : j_dc_36());
                }
                j_myf0h1xk = (8 + 0);
                break;
            case 8:
                return j_dc_37();
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_n49ux56p(int32_t j_6euxfluj)
{
    int32_t j_139q79jz = 0;
    while ((j_139q79jz != -1))
    {
        switch (j_139q79jz)
        {
            case 0:
                static volatile int64_t j_x6pkp6j9 = 22220;
                if ((((j_x6pkp6j9 * j_x6pkp6j9) + j_x6pkp6j9) < (0 + 0)))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (3100 ^ 3100)) ? j_dc_38() : j_dc_39());
                }
                j_139q79jz = 1;
                break;
            case 1:
                static volatile int64_t j_5do8dg39 = ((80683 + 15497) ^ (3730 ^ 3730));
                static volatile int64_t j_6e7d49xt = 44133;
                static volatile int64_t j_2qddaemk = 2040;
                if ((((j_2qddaemk * j_2qddaemk) + j_2qddaemk) < 0))
                {
                    volatile int64_t j_x2zwwr6e = ((j_2qddaemk * (15 + 38)) + ((24 + 16) ^ (7552 ^ 7552)));
                    (void)printf("%s\n", 0 ? j_dc_40() : j_dc_41());
                }
                j_139q79jz = 2;
                break;
            case 2:
                if ((((j_6e7d49xt * j_6e7d49xt) + j_6e7d49xt) < ((0 + 0) ^ (8363 ^ 8363))))
                {
                    volatile int64_t j_21ahhhe3 = ((j_6e7d49xt * ((6 + 12) ^ (9185 ^ 9185))) + 133);
                    (void)printf("%s\n", 0 ? j_dc_42() : j_dc_43());
                }
                j_139q79jz = (0 + 3);
                break;
            case 3:
                if ((((j_5do8dg39 * (j_5do8dg39 + ((1 + 0) ^ (7194 ^ 7194)))) % 2) == (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (8786 ^ 8786)) ? j_dc_44() : j_dc_45());
                }
                j_139q79jz = (1 + 3);
                break;
            case 4:
                static volatile int64_t j_vxs0t3hw = (40561 + 33653);
                if ((((j_vxs0t3hw * j_vxs0t3hw) + j_vxs0t3hw) < ((0 + 0) ^ (8414 ^ 8414))))
                {
                    volatile int64_t j_eee7mwgd = ((j_vxs0t3hw * ((27 + 19) ^ (3454 ^ 3454))) + 214);
                    (void)printf("%s\n", (0 + 0) ? j_dc_46() : j_dc_47());
                }
                j_139q79jz = ((3 + 2) ^ (8746 ^ 8746));
                break;
            case 5:
                if (((j_6euxfluj % (0 + 2)) == 0))
                {
                    return (j_6euxfluj / 2);
                }
                j_139q79jz = 6;
                break;
            case 6:
                static volatile int64_t j_rm2fs6zk = 34474;
                if ((((j_rm2fs6zk * j_rm2fs6zk) + j_rm2fs6zk) < ((0 + 0) ^ (7709 ^ 7709))))
                {
                    volatile int64_t j_2bkxss77 = ((j_rm2fs6zk * ((36 + 43) ^ (9329 ^ 9329))) + 474);
                    (void)printf("%s\n", 0 ? j_dc_48() : j_dc_49());
                }
                j_139q79jz = ((3 + 4) ^ (7201 ^ 7201));
                break;
            case 7:
                return ((j_6euxfluj * 3) + ((0 + 1) ^ (6758 ^ 6758)));
                break;
            case 8:
                static volatile int64_t j_exm0gcsl = (34715 + 53598);
                if ((((j_exm0gcsl * j_exm0gcsl) + j_exm0gcsl) >= ((0 + 0) ^ (8854 ^ 8854))))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (4379 ^ 4379)) ? j_dc_50() : j_dc_51());
                }
                j_139q79jz = -1;
                break;
            default:
                break;
        }
    }
    return (0 + 0);
}

static int32_t j_xg1b6c1n(int32_t j_6euxfluj)
{
    int32_t j_g74a8z83 = 0;
    while ((j_g74a8z83 != -(0 + 1)))
    {
        switch (j_g74a8z83)
        {
            case 0:
                int32_t j_vsv48048 = (0 + 0);
                static volatile int64_t j_hg2beufw = (61097 + 27809);
                if ((((j_hg2beufw * j_hg2beufw) + j_hg2beufw) < 0))
                {
                    volatile int64_t j_mu5791fg = ((j_hg2beufw * ((11 + 9) ^ (1565 ^ 1565))) + 906);
                    (void)printf("%s\n", ((0 + 0) ^ (2745 ^ 2745)) ? j_dc_52() : j_dc_53());
                }
                j_g74a8z83 = 1;
                break;
            case 1:
                int32_t j_urz8amwl = j_6euxfluj;
                static volatile int64_t j_xef5gypb = 77638;
                static volatile int64_t j_y5asbtjo = (62249 + 21665);
                if ((((j_y5asbtjo * j_y5asbtjo) + j_y5asbtjo) < ((0 + 0) ^ (1842 ^ 1842))))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (6367 ^ 6367)) ? j_dc_54() : j_dc_55());
                }
                j_g74a8z83 = ((2 + 0) ^ (7902 ^ 7902));
                break;
            case 2:
                if ((((j_xef5gypb * j_xef5gypb) + j_xef5gypb) < 0))
                {
                    (void)printf("%s\n", ((0 + 0) ^ (2052 ^ 2052)) ? j_dc_56() : j_dc_57());
                }
                j_g74a8z83 = ((2 + 1) ^ (8093 ^ 8093));
                break;
            case 3:
                static volatile int64_t j_62tmwofx = ((187 + 14879) ^ (8246 ^ 8246));
                if ((((j_62tmwofx * j_62tmwofx) + j_62tmwofx) < (0 + 0)))
                {
                    volatile int64_t j_9r0hu4z5 = ((j_62tmwofx * 65) + (9 + 57));
                    (void)printf("%s\n", 0 ? j_dc_58() : j_dc_59());
                }
                j_g74a8z83 = 4;
                break;
            case 4:
                while ((j_urz8amwl != 1))
                {
                    j_urz8amwl = j_n49ux56p(j_urz8amwl);
                    j_vsv48048 = (j_vsv48048 + 1);
                }
                j_g74a8z83 = ((4 + 1) ^ (1394 ^ 1394));
                break;
            case 5:
                return j_vsv48048;
                break;
            default:
                break;
        }
    }
    return ((0 + 0) ^ (155 ^ 155));
}

__attribute__((used)) static int32_t j_z_vbxa3z(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = ((0 + 0) ^ (1883 ^ 1883));
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % ((4220 + 5787) ^ (2902 ^ 2902));
        j_t = j_t + 1;
    }
    return j_r;
}

__attribute__((used)) static int32_t j_z_scsp2i(int32_t j_a, int32_t j_b, int32_t j_c) {
    int32_t j_r = j_a;
    int32_t j_t = ((0 + 0) ^ (2206 ^ 2206));
    while (j_t < j_b) {
        j_r = (j_r * 31 + j_c) % ((1911 + 8096) ^ (8111 ^ 8111));
        j_t = j_t + 1;
    }
    return j_r;
}

static int32_t j_tr_khv5jb(void) {
    int32_t j_v14jdemq = ((0 + 0) ^ (5393 ^ 5393));
    while ((j_v14jdemq != -((1 + 0) ^ (7176 ^ 7176))))
    {
        switch (j_v14jdemq)
        {
            case 0:
                static volatile int64_t j_09cizgcp = ((7579 + 4807) ^ (6420 ^ 6420));
                if ((((j_09cizgcp * j_09cizgcp) + j_09cizgcp) < 0))
                {
                    volatile int64_t j_xqd52eow = ((j_09cizgcp * ((10 + 62) ^ (9548 ^ 9548))) + 386);
                    (void)printf("%s\n", 0 ? j_dc_60() : j_dc_61());
                }
                j_v14jdemq = ((0 + 1) ^ (7071 ^ 7071));
                break;
            case 1:
                static volatile int64_t j_3q4ei1h5 = ((6090 + 5974) ^ (1175 ^ 1175));
                if ((((j_3q4ei1h5 * j_3q4ei1h5) + j_3q4ei1h5) >= (0 + 0)))
                {
                }
                else
                {
                    (void)printf("%s\n", (0 + 0) ? j_dc_62() : j_dc_63());
                }
                j_v14jdemq = (0 + 2);
                break;
            case 2:
                (void)printf("%s\n", j_dc_64());
                int32_t j_ylegiqx7 = 1;
                static volatile int64_t j_a9w4oskl = 13140;
                if ((((j_a9w4oskl * j_a9w4oskl) % ((2 + 2) ^ (1537 ^ 1537))) == ((2 + 1) ^ (8104 ^ 8104))))
                {
                    (void)printf("%s\n", 0 ? j_dc_65() : j_dc_66());
                }
                j_v14jdemq = 3;
                break;
            case 3:
                while ((j_ylegiqx7 <= (5 + 3)))
                {
                    (void)printf("%d\n", j_xg1b6c1n(j_ylegiqx7));
                    j_ylegiqx7 = (j_ylegiqx7 + (1 + 0));
                }
                j_v14jdemq = (0 + 4);
                break;
            case 4:
                (void)printf("%s\n", j_dc_67());
                for (int32_t j_250ezy55 = -(((2 + 1) ^ (7438 ^ 7438))); (j_250ezy55 <= 6); j_250ezy55 = (j_250ezy55 + ((0 + 1) ^ (2498 ^ 2498))))
                {
                    (void)printf("%s\n", j_6gssa7uj(j_250ezy55));
                }
                j_v14jdemq = 5;
                break;
            case 5:
                (void)printf("%s\n", j_dc_68());
                int32_t j_eh2w5xyw = 0;
                int32_t j_6euxfluj = (0 + 1);
                while ((j_6euxfluj <= ((6 + 4) ^ (1879 ^ 1879))))
                {
                    j_eh2w5xyw = (j_eh2w5xyw + j_xg1b6c1n(j_6euxfluj));
                    j_6euxfluj = (j_6euxfluj + ((0 + 1) ^ (183 ^ 183)));
                }
                j_v14jdemq = 6;
                break;
            case 6:
                static volatile int64_t j_l7ytm7y1 = 3802;
                if ((((j_l7ytm7y1 * j_l7ytm7y1) + j_l7ytm7y1) < 0))
                {
                    volatile int64_t j_tt18d6dl = ((j_l7ytm7y1 * ((18 + 32) ^ (5208 ^ 5208))) + 802);
                    (void)printf("%s\n", ((0 + 0) ^ (5617 ^ 5617)) ? j_dc_69() : j_dc_70());
                }
                j_v14jdemq = 7;
                break;
            case 7:
                static volatile int64_t j_alg1znte = 39270;
                if ((((j_alg1znte * (j_alg1znte + 1)) % (1 + 1)) == ((0 + 0) ^ (6562 ^ 6562))))
                {
                }
                else
                {
                    (void)printf("%s\n", ((0 + 0) ^ (5332 ^ 5332)) ? j_dc_71() : j_dc_72());
                }
                j_v14jdemq = (5 + 3);
                break;
            case 8:
                static volatile int64_t j_zpit4y0w = 72319;
                if ((((j_zpit4y0w * j_zpit4y0w) + j_zpit4y0w) < ((0 + 0) ^ (1845 ^ 1845))))
                {
                    volatile int64_t j_jc0hahjx = ((j_zpit4y0w * 83) + ((143 + 176) ^ (3799 ^ 3799)));
                    (void)printf("%s\n", 0 ? j_dc_73() : j_dc_74());
                }
                j_v14jdemq = ((0 + 9) ^ (7456 ^ 7456));
                break;
            case 9:
                (void)printf("%d\n", j_eh2w5xyw);
                (void)printf("%s\n", j_dc_75());
                (void)printf("%s\n", j_dc_76());
                j_v14jdemq = -((1 + 0) ^ (4341 ^ 4341));
                break;
            default:
                break;
        }
    }
    return 0;
}
static int32_t j_tr_ov70na(void) { return j_tr_khv5jb(); }
static int32_t j_tr_f2y9g1(void) { return j_tr_ov70na(); }
static int32_t j_tr_p29y2w(void) { return j_tr_f2y9g1(); }
int32_t main(void) { return j_tr_p29y2w(); }

