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

static const volatile uint8_t j_enc_0[] = {0x22, 0x23, 0x20, 0x21, 0x26, 0x27, 0x24, 0x25, 0x2A, 0x2B, 0x73, 0x70, 0x71, 0x76, 0x77, 0x74};
static const char* j_dc_0(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_0[j_i] ^ 18;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_1[] = {0xB9, 0xB8, 0xBB, 0xBA, 0xBD, 0xBC, 0xBF, 0xBE, 0xB1, 0xB0, 0xE8, 0xEB, 0xEA, 0xED, 0xEC, 0xEF};
static const char* j_dc_1(void) {
    static char j_rb[17];
    for (int j_i = 0; j_i < 16; j_i++) j_rb[j_i] = j_enc_1[j_i] ^ 137;
    j_rb[16] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_2[] = {0x20, 0x30};
static const char* j_dc_2(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_2[j_i] ^ 82;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_3[] = {0xD4, 0xC1};
static const char* j_dc_3(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_3[j_i] ^ 163;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_4[] = {0x31, 0x6E, 0x6C, 0x71, 0x7D};
static const char* j_dc_4(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_4[j_i] ^ 30;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_5[] = {0xFF};
static const char* j_dc_5(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_5[j_i] ^ 141;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_6[] = {0xD7};
static const char* j_dc_6(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_6[j_i] ^ 221;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_7[] = {0xEA};
static const char* j_dc_7(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_7[j_i] ^ 152;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_8[] = {0x6B};
static const char* j_dc_8(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_8[j_i] ^ 84;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_9[] = {0xB6, 0xB3, 0xA9, 0xAE, 0xBF, 0xB4};
static const char* j_dc_9(void) {
    static char j_rb[7];
    for (int j_i = 0; j_i < 6; j_i++) j_rb[j_i] = j_enc_9[j_i] ^ 250;
    j_rb[6] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_10[] = {0x57, 0x41, 0x46, 0x53, 0x50, 0x5E, 0x5B, 0x41, 0x5A, 0x57, 0x56};
static const char* j_dc_10(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_10[j_i] ^ 18;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_11[] = {0x79, 0x76, 0x75, 0x69, 0x7F, 0x65, 0x6D, 0x7B, 0x73, 0x6E};
static const char* j_dc_11(void) {
    static char j_rb[11];
    for (int j_i = 0; j_i < 10; j_i++) j_rb[j_i] = j_enc_11[j_i] ^ 58;
    j_rb[10] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_12[] = {0x66, 0x7B, 0x7F, 0x77, 0x6D, 0x65, 0x73, 0x7B, 0x66};
static const char* j_dc_12(void) {
    static char j_rb[10];
    for (int j_i = 0; j_i < 9; j_i++) j_rb[j_i] = j_enc_12[j_i] ^ 50;
    j_rb[9] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_13[] = {0x38, 0x23, 0x3F, 0x32, 0x25};
static const char* j_dc_13(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_13[j_i] ^ 119;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_14[] = {0x0D, 0x06, 0x17, 0x10, 0x17, 0x02, 0x17, 0x43, 0x4E, 0x02, 0x0D, 0x43, 0x4E, 0x13, 0x43, 0x17, 0x00, 0x13, 0x43, 0x51, 0x5D, 0x4C, 0x07, 0x06, 0x15, 0x4C, 0x0D, 0x16, 0x0F, 0x0F};
static const char* j_dc_14(void) {
    static char j_rb[31];
    for (int j_i = 0; j_i < 30; j_i++) j_rb[j_i] = j_enc_14[j_i] ^ 99;
    j_rb[30] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_15[] = {0x9D};
static const char* j_dc_15(void) {
    static char j_rb[2];
    for (int j_i = 0; j_i < 1; j_i++) j_rb[j_i] = j_enc_15[j_i] ^ 239;
    j_rb[1] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_16[] = {0xA7, 0xB0, 0xA3};
static const char* j_dc_16(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_16[j_i] ^ 211;
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_17[] = {0x45, 0x1A, 0x18, 0x05, 0x09, 0x45, 0x04, 0x0F, 0x1E, 0x45, 0x1E, 0x09, 0x1A};
static const char* j_dc_17(void) {
    static char j_rb[14];
    for (int j_i = 0; j_i < 13; j_i++) j_rb[j_i] = j_enc_17[j_i] ^ 106;
    j_rb[13] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_18[] = {0xEC, 0xB3, 0xB1, 0xAC, 0xA0, 0xEC, 0xAD, 0xA6, 0xB7, 0xEC, 0xB7, 0xA0, 0xB3, 0xF5};
static const char* j_dc_18(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_18[j_i] ^ 195;
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_19[] = {0x9E, 0x9D, 0x9A, 0x9B, 0x8A};
static const char* j_dc_19(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_19[j_i] ^ 214;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_20[] = {0x95, 0x96, 0x9E, 0x88, 0x81};
static const char* j_dc_20(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_20[j_i] ^ 221;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_21[] = {0x4E, 0x4D, 0x45, 0x54, 0x5A};
static const char* j_dc_21(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_21[j_i] ^ 6;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_22[] = {0xA4, 0xA7, 0xB9, 0xB0};
static const char* j_dc_22(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_22[j_i] ^ 236;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_23[] = {0x49, 0x5C};
static const char* j_dc_23(void) {
    static char j_rb[3];
    for (int j_i = 0; j_i < 2; j_i++) j_rb[j_i] = j_enc_23[j_i] ^ 62;
    j_rb[2] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_24[] = {0xD7, 0xDC, 0xDE, 0xD8, 0xCD, 0xD0, 0xCF, 0xDC};
static const char* j_dc_24(void) {
    static char j_rb[9];
    for (int j_i = 0; j_i < 8; j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 185;
    j_rb[8] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0xFB, 0xFD, 0xFA, 0xEA};
static const char* j_dc_25(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_25[j_i] ^ 143;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x42, 0x45, 0x48, 0x57, 0x41};
static const char* j_dc_26(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_26[j_i] ^ 36;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0x8F, 0x90, 0x87, 0x9A};
static const char* j_dc_27(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 245;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x32, 0x21, 0x32, 0x39};
static const char* j_dc_28(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_28[j_i] ^ 87;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0xFA, 0xF1, 0xF1};
static const char* j_dc_29(void) {
    static char j_rb[4];
    for (int j_i = 0; j_i < 3; j_i++) j_rb[j_i] = j_enc_29[j_i] ^ 149;
    j_rb[3] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_30[] = {0x20, 0x26, 0x21, 0x31};
static const char* j_dc_30(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_30[j_i] ^ 84;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_31[] = {0x12, 0x15, 0x18, 0x07, 0x11};
static const char* j_dc_31(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_31[j_i] ^ 116;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_32[] = {0x33, 0x35, 0x32, 0x22};
static const char* j_dc_32(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_32[j_i] ^ 71;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_33[] = {0xBA, 0xBD, 0xB0, 0xAF, 0xB9};
static const char* j_dc_33(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_33[j_i] ^ 220;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_34[] = {0x63, 0x65, 0x62, 0x72};
static const char* j_dc_34(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_34[j_i] ^ 23;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_35[] = {0x08, 0x0F, 0x02, 0x1D, 0x0B};
static const char* j_dc_35(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_35[j_i] ^ 110;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_36[] = {0x80, 0x86, 0x81, 0x91};
static const char* j_dc_36(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_36[j_i] ^ 244;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_37[] = {0x3A, 0x3D, 0x30, 0x2F, 0x39};
static const char* j_dc_37(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_37[j_i] ^ 92;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_38[] = {0x67, 0x61, 0x66, 0x76};
static const char* j_dc_38(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_38[j_i] ^ 19;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_39[] = {0x35, 0x32, 0x3F, 0x20, 0x36};
static const char* j_dc_39(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_39[j_i] ^ 83;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_40[] = {0x15, 0x13, 0x14, 0x04};
static const char* j_dc_40(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_40[j_i] ^ 97;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_41[] = {0x45, 0x42, 0x4F, 0x50, 0x46};
static const char* j_dc_41(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_41[j_i] ^ 35;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_42[] = {0x66, 0x60, 0x67, 0x77};
static const char* j_dc_42(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_42[j_i] ^ 18;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_43[] = {0xAE, 0xA9, 0xA4, 0xBB, 0xAD};
static const char* j_dc_43(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_43[j_i] ^ 200;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_44[] = {0x5B, 0x5D, 0x5A, 0x4A};
static const char* j_dc_44(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_44[j_i] ^ 47;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_45[] = {0x95, 0x92, 0x9F, 0x80, 0x96};
static const char* j_dc_45(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_45[j_i] ^ 243;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_46[] = {0xDD, 0xDB, 0xDC, 0xCC};
static const char* j_dc_46(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_46[j_i] ^ 169;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_47[] = {0x08, 0x0F, 0x02, 0x1D, 0x0B};
static const char* j_dc_47(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_47[j_i] ^ 110;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_48[] = {0x88, 0x8E, 0x89, 0x99};
static const char* j_dc_48(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_48[j_i] ^ 252;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_49[] = {0x06, 0x01, 0x0C, 0x13, 0x05};
static const char* j_dc_49(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_49[j_i] ^ 96;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_50[] = {0xE5, 0xE3, 0xE4, 0xF4};
static const char* j_dc_50(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_50[j_i] ^ 145;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_51[] = {0x52, 0x55, 0x58, 0x47, 0x51};
static const char* j_dc_51(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_51[j_i] ^ 52;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_52[] = {0xFC, 0xFC, 0xFC, 0xE1, 0x82, 0x8E, 0x8D, 0x8D, 0x80, 0x95, 0x9B, 0xE1, 0x92, 0x95, 0x84, 0x91, 0x92, 0xE1, 0xFC, 0xFC, 0xFC};
static const char* j_dc_52(void) {
    static char j_rb[22];
    for (int j_i = 0; j_i < 21; j_i++) j_rb[j_i] = j_enc_52[j_i] ^ 193;
    j_rb[21] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0x16, 0x10, 0x17, 0x07};
static const char* j_dc_53(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 98;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0x22, 0x25, 0x28, 0x37, 0x21};
static const char* j_dc_54(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ 68;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x26, 0x20, 0x27, 0x37};
static const char* j_dc_55(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_55[j_i] ^ 82;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0x86, 0x81, 0x8C, 0x93, 0x85};
static const char* j_dc_56(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_56[j_i] ^ 224;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0xC9, 0xC9, 0xC9, 0xD4, 0xB7, 0xB8, 0xB5, 0xA7, 0xA7, 0xBD, 0xB2, 0xBD, 0xB7, 0xB5, 0xA0, 0xBD, 0xBB, 0xBA, 0xD4, 0xC9, 0xC9, 0xC9};
static const char* j_dc_57(void) {
    static char j_rb[23];
    for (int j_i = 0; j_i < 22; j_i++) j_rb[j_i] = j_enc_57[j_i] ^ 244;
    j_rb[22] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0xF4, 0xF4, 0xF4, 0xE9, 0x88, 0x8E, 0x8E, 0x9B, 0x8C, 0x8E, 0x88, 0x9D, 0x8C, 0xE9, 0xF4, 0xF4, 0xF4};
static const char* j_dc_58(void) {
    static char j_rb[18];
    for (int j_i = 0; j_i < 17; j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 201;
    j_rb[17] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0x5F, 0x59, 0x5E, 0x4E};
static const char* j_dc_59(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 43;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0x8D, 0x8A, 0x87, 0x98, 0x8E};
static const char* j_dc_60(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_60[j_i] ^ 235;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_61[] = {0x0A, 0x0C, 0x0B, 0x1B};
static const char* j_dc_61(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_61[j_i] ^ 126;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_62[] = {0x34, 0x33, 0x3E, 0x21, 0x37};
static const char* j_dc_62(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_62[j_i] ^ 82;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_63[] = {0x5C, 0x5C, 0x5C, 0x41, 0x33, 0x24, 0x32, 0x34, 0x2D, 0x35, 0x41, 0x5C, 0x5C, 0x5C};
static const char* j_dc_63(void) {
    static char j_rb[15];
    for (int j_i = 0; j_i < 14; j_i++) j_rb[j_i] = j_enc_63[j_i] ^ 97;
    j_rb[14] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_64[] = {0xE7, 0xEA, 0xEA, 0xA6, 0xE4, 0xF3, 0xEF, 0xEA, 0xE2, 0xF5, 0xA6, 0xF6, 0xF4, 0xE9, 0xE2, 0xF3, 0xE5, 0xE3, 0xA6, 0xEF, 0xE2, 0xE3, 0xE8, 0xF2, 0xEF, 0xE5, 0xE7, 0xEA, 0xA6, 0xE9, 0xF3, 0xF2, 0xF6, 0xF3, 0xF2};
static const char* j_dc_64(void) {
    static char j_rb[36];
    for (int j_i = 0; j_i < 35; j_i++) j_rb[j_i] = j_enc_64[j_i] ^ 134;
    j_rb[35] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_65[] = {0x9F, 0x99, 0x9E, 0x8E};
static const char* j_dc_65(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_65[j_i] ^ 235;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_66[] = {0xC9, 0xCE, 0xC3, 0xDC, 0xCA};
static const char* j_dc_66(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_66[j_i] ^ 175;
    j_rb[5] = 0;
    return j_rb;
}

static int32_t j_str_len(const char* s) { return (int32_t)strlen(s); }
static bool j_str_eq(const char* a, const char* b) { return strcmp(a, b) == 0; }

static char j_buf[65536];
#define J_BUF_CAP (sizeof j_buf)

static void j_json_escape(char* out, size_t cap, const char* s) {
    size_t o = 0;
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
    int first = 1;
#if defined(_WIN32)
    char pattern[1024];
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
            if (off > J_BUF_CAP - 200) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[1024];
            j_json_escape(esc, sizeof esc, de->d_name);
            int n = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n > 0 ? n : 0);
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
                char name[1024];
                size_t k = 0;
                for (size_t i = 0; pe.szExeFile[i] && k + 1 < sizeof name; ++i)
                    name[k++] = (char)(pe.szExeFile[i] & 0xFF);
                name[k] = '\0';
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[2048];
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
        if (off > J_BUF_CAP - 400) break;
        char name[256];
        int len = proc_name(pid, name, sizeof name);
        if (len <= 0) snprintf(name, sizeof name, "pid_%d", pid);
        if (!first) j_buf[off++] = ',';
        first = 0;
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
            if (de->d_name[0] < '0' || de->d_name[0] > '9') continue;
            int pid = atoi(de->d_name);
            char p[64], name[256];
            snprintf(p, sizeof p, "/proc/%d/comm", pid);
            FILE* f = fopen(p, j_dc_5());
            if (f) {
                if (fgets(name, sizeof name, f)) name[strcspn(name, j_dc_6())] = '\0';
                fclose(f);
                if (off > J_BUF_CAP - 400) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                char esc[512];
                j_json_escape(esc, sizeof esc, name);
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"pid\":%d,\"name\":\"%s\"}", pid, esc);
                off += (size_t)(n > 0 ? n : 0);
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
        char laddr[64], raddr[64], st[16];
        if (sscanf(line, "%*s %63s %63s %15s", laddr, raddr, st) != 3) continue;
        if (*off > J_BUF_CAP - 300) break;
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
    GetExtendedTcpTable(NULL, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0);
    char* t = (char*)malloc(sz ? sz : 1);
    if (t) {
        MIB_TCPTABLE_OWNER_PID* tab = (MIB_TCPTABLE_OWNER_PID*)t;
        if (GetExtendedTcpTable(tab, &sz, FALSE, AF_INET, TCP_TABLE_OWNER_PID_ALL, 0) == NO_ERROR) {
            for (DWORD i = 0; i < tab->dwNumEntries; ++i) {
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
                if (off > J_BUF_CAP - 300) break;
                if (!first) j_buf[off++] = ',';
                first = 0;
                int n = snprintf(j_buf + off, J_BUF_CAP - off, "{\"local\":\"%s\",\"remote\":\"%s\",\"state\":\"%s\"}", li, ri, state);
                off += (size_t)(n > 0 ? n : 0);
            }
        }
        free(t);
    }
#elif defined(__APPLE__)
    FILE* ns = popen(j_dc_14(), j_dc_15());
    if (ns) {
        char line[512];
        while (fgets(line, sizeof line, ns)) {
            char proto[8], laddr[64], raddr[64], st[32];
            if (sscanf(line, "%7s %*s %*s %63s %63s %31s", proto, laddr, raddr, st) == 4) {
                if (strncmp(proto, j_dc_16(), 3) != 0) continue;
                if (off > J_BUF_CAP - 300) break;
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
    int first = 1;
#if defined(_WIN32)
    HKEY root = HKEY_LOCAL_MACHINE;
    const char* sub = key;
    if (strncmp(key, j_dc_19(), 5) == 0) { root = HKEY_LOCAL_MACHINE; sub = key + 5; }
    else if (strncmp(key, j_dc_20(), 5) == 0) { root = HKEY_CURRENT_USER; sub = key + 5; }
    else if (strncmp(key, j_dc_21(), 5) == 0) { root = HKEY_CLASSES_ROOT; sub = key + 5; }
    else if (strncmp(key, j_dc_22(), 4) == 0) { root = HKEY_USERS; sub = key + 4; }
    HKEY hk = NULL;
    if (RegOpenKeyExA(root, sub, 0, KEY_READ, &hk) == ERROR_SUCCESS) {
        for (DWORD i = 0; ; ++i) {
            char s[256];
            DWORD n = sizeof s;
            if (RegEnumKeyExA(hk, i, s, &n, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) break;
            if (off > J_BUF_CAP - 400) break;
            if (!first) j_buf[off++] = ',';
            first = 0;
            char esc[512];
            j_json_escape(esc, sizeof esc, s);
            int n2 = snprintf(j_buf + off, J_BUF_CAP - off, "\"%s\"", esc);
            off += (size_t)(n2 > 0 ? n2 : 0);
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
    unsigned long regions = 0;
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

static volatile int32_t j_ls2wrj8m = 63390;
static volatile int32_t j_2p7e3pad = 28372;

static const char* j_4f7g6fui(int32_t j_zjsufqwi);
static int32_t j_t2hghb9f(int32_t j_zjsufqwi);
static int32_t j_oiwo6t0n(int32_t j_zjsufqwi);

static const char* j_4f7g6fui(int32_t j_zjsufqwi)
{
    int32_t j_ql8pat8l = 0;
    while ((j_ql8pat8l != -1))
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
                static volatile int64_t j_vogp4vxx = 86933;
                if ((((j_vogp4vxx * (j_vogp4vxx + 1)) % 2) == 1))
                {
                    (void)printf("%s\n", 0 ? j_dc_25() : j_dc_26());
                }
                j_ql8pat8l = 2;
                break;
            case 2:
                if ((j_zjsufqwi == 0))
                {
                    return j_dc_27();
                }
                j_ql8pat8l = 3;
                break;
            case 3:
                if (((j_zjsufqwi % 2) == 0))
                {
                    return j_dc_28();
                }
                j_ql8pat8l = 4;
                break;
            case 4:
                return j_dc_29();
                break;
            case 5:
                static volatile int64_t j_ehlw0m3t = 81491;
                if ((((j_ehlw0m3t * j_ehlw0m3t) + j_ehlw0m3t) < 0))
                {
                    volatile int64_t j_uz7o1dww = ((j_ehlw0m3t * 27) + 491);
                    (void)printf("%s\n", 0 ? j_dc_30() : j_dc_31());
                }
                j_ql8pat8l = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_t2hghb9f(int32_t j_zjsufqwi)
{
    int32_t j_cl9v0u1j = 0;
    while ((j_cl9v0u1j != -1))
    {
        switch (j_cl9v0u1j)
        {
            case 0:
                static volatile int64_t j_d8trjgcf = 41186;
                if ((((j_d8trjgcf * j_d8trjgcf) + j_d8trjgcf) < 0))
                {
                    volatile int64_t j_gd3i4eu3 = ((j_d8trjgcf * 85) + 186);
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
                if ((((j_wz7tww6m * j_wz7tww6m) + j_wz7tww6m) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_36() : j_dc_37());
                }
                j_cl9v0u1j = 3;
                break;
            case 3:
                static volatile int64_t j_2rhh3gut = 39925;
                if ((((j_2rhh3gut * j_2rhh3gut) + j_2rhh3gut) < 0))
                {
                    volatile int64_t j_si31ndk9 = ((j_2rhh3gut * 19) + 925);
                    (void)printf("%s\n", 0 ? j_dc_38() : j_dc_39());
                }
                j_cl9v0u1j = 4;
                break;
            case 4:
                static volatile int64_t j_e63tox7h = 77858;
                if ((((j_e63tox7h * (j_e63tox7h + 1)) % 2) == 1))
                {
                    (void)printf("%s\n", 0 ? j_dc_40() : j_dc_41());
                }
                j_cl9v0u1j = 5;
                break;
            case 5:
                if (((j_zjsufqwi % 2) == 0))
                {
                    return (j_zjsufqwi / 2);
                }
                j_cl9v0u1j = 6;
                break;
            case 6:
                return ((j_zjsufqwi * 3) + 1);
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_oiwo6t0n(int32_t j_zjsufqwi)
{
    int32_t j_gmqpdmt0 = 0;
    while ((j_gmqpdmt0 != -1))
    {
        switch (j_gmqpdmt0)
        {
            case 0:
                static volatile int64_t j_c8jewur5 = 576;
                if ((((j_c8jewur5 * j_c8jewur5) + j_c8jewur5) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_42() : j_dc_43());
                }
                j_gmqpdmt0 = 1;
                break;
            case 1:
                int32_t j_468tmzoa = 0;
                int32_t j_qo32bb5q = j_zjsufqwi;
                while ((j_qo32bb5q != 1))
                {
                    j_qo32bb5q = j_t2hghb9f(j_qo32bb5q);
                    j_468tmzoa = (j_468tmzoa + 1);
                }
                j_gmqpdmt0 = 2;
                break;
            case 2:
                static volatile int64_t j_ifxsxp8l = 88161;
                if ((((j_ifxsxp8l * j_ifxsxp8l) + j_ifxsxp8l) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_44() : j_dc_45());
                }
                j_gmqpdmt0 = 3;
                break;
            case 3:
                static volatile int64_t j_l9dl9lcd = 98908;
                if ((((j_l9dl9lcd * j_l9dl9lcd) + j_l9dl9lcd) < 0))
                {
                    volatile int64_t j_7m5fgot7 = ((j_l9dl9lcd * 97) + 908);
                    (void)printf("%s\n", 0 ? j_dc_46() : j_dc_47());
                }
                j_gmqpdmt0 = 4;
                break;
            case 4:
                static volatile int64_t j_yn30xwb1 = 41684;
                if ((((j_yn30xwb1 * j_yn30xwb1) + j_yn30xwb1) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_48() : j_dc_49());
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
    return 0;
}

int32_t main(void)
{
    int32_t j_kiietxma = 0;
    while ((j_kiietxma != -1))
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
                if ((((j_c1wchsa4 * j_c1wchsa4) + j_c1wchsa4) < 0))
                {
                    volatile int64_t j_lyd9q6x2 = ((j_c1wchsa4 * 46) + 428);
                    (void)printf("%s\n", 0 ? j_dc_53() : j_dc_54());
                }
                j_kiietxma = 2;
                break;
            case 2:
                if ((((j_fy0gpnl9 * j_fy0gpnl9) + j_fy0gpnl9) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_55() : j_dc_56());
                }
                j_kiietxma = 3;
                break;
            case 3:
                while ((j_qb8n9rkr <= 8))
                {
                    (void)printf("%d\n", j_oiwo6t0n(j_qb8n9rkr));
                    j_qb8n9rkr = (j_qb8n9rkr + 1);
                }
                j_kiietxma = 4;
                break;
            case 4:
                static volatile int64_t j_xsop1o4p = 62587;
                if ((((j_xsop1o4p * j_xsop1o4p) + j_xsop1o4p) >= 0))
                {
                    (void)printf("%s\n", j_dc_57());
                }
                else
                {
                    volatile int64_t j_ney0af9f = ((j_xsop1o4p * 2) + 1);
                }
                j_kiietxma = 5;
                break;
            case 5:
                for (int32_t j_dj8cfjgn = -(3); (j_dj8cfjgn <= 6); j_dj8cfjgn = (j_dj8cfjgn + 1))
                {
                    (void)printf("%s\n", j_4f7g6fui(j_dj8cfjgn));
                }
                j_kiietxma = 6;
                break;
            case 6:
                (void)printf("%s\n", j_dc_58());
                static volatile int64_t j_mbs50pn8 = 1887;
                if ((((j_mbs50pn8 * j_mbs50pn8) + j_mbs50pn8) < 0))
                {
                    volatile int64_t j_gzdn22af = ((j_mbs50pn8 * 55) + 887);
                    (void)printf("%s\n", 0 ? j_dc_59() : j_dc_60());
                }
                j_kiietxma = 7;
                break;
            case 7:
                int32_t j_2ct6q877 = 0;
                int32_t j_zjsufqwi = 1;
                while ((j_zjsufqwi <= 10))
                {
                    j_2ct6q877 = (j_2ct6q877 + j_oiwo6t0n(j_zjsufqwi));
                    j_zjsufqwi = (j_zjsufqwi + 1);
                }
                j_kiietxma = 8;
                break;
            case 8:
                (void)printf("%d\n", j_2ct6q877);
                static volatile int64_t j_f1hbv9t4 = 11559;
                if ((((j_f1hbv9t4 * j_f1hbv9t4) + j_f1hbv9t4) < 0))
                {
                    volatile int64_t j_v19rzg9k = ((j_f1hbv9t4 * 83) + 559);
                    (void)printf("%s\n", 0 ? j_dc_61() : j_dc_62());
                }
                j_kiietxma = 9;
                break;
            case 9:
                (void)printf("%s\n", j_dc_63());
                (void)printf("%s\n", j_dc_64());
                static volatile int64_t j_kwyqhptu = 66990;
                if ((((j_kwyqhptu * j_kwyqhptu) % 4) == 3))
                {
                    (void)printf("%s\n", 0 ? j_dc_65() : j_dc_66());
                }
                j_kiietxma = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}
