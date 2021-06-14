//
// fips_selftest.c - Algorithm selftests for FIPS 140 compliance
//
// Copyright (c) Microsoft Corporation. Licensed under the MIT license.
//

#include "precomp.h"

SYMCRYPT_FIPS_SELFTEST g_SymCryptFipsSelftestsPerformed = SYMCRYPT_SELFTEST_NONE;

const BYTE rgbDh2048Modulus[] =
{
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC9, 0x0F, 0xDA, 0xA2, 0x21, 0x68, 0xC2, 0x34,
    0xC4, 0xC6, 0x62, 0x8B, 0x80, 0xDC, 0x1C, 0xD1, 0x29, 0x02, 0x4E, 0x08, 0x8A, 0x67, 0xCC, 0x74,
    0x02, 0x0B, 0xBE, 0xA6, 0x3B, 0x13, 0x9B, 0x22, 0x51, 0x4A, 0x08, 0x79, 0x8E, 0x34, 0x04, 0xDD,
    0xEF, 0x95, 0x19, 0xB3, 0xCD, 0x3A, 0x43, 0x1B, 0x30, 0x2B, 0x0A, 0x6D, 0xF2, 0x5F, 0x14, 0x37,
    0x4F, 0xE1, 0x35, 0x6D, 0x6D, 0x51, 0xC2, 0x45, 0xE4, 0x85, 0xB5, 0x76, 0x62, 0x5E, 0x7E, 0xC6,
    0xF4, 0x4C, 0x42, 0xE9, 0xA6, 0x37, 0xED, 0x6B, 0x0B, 0xFF, 0x5C, 0xB6, 0xF4, 0x06, 0xB7, 0xED,
    0xEE, 0x38, 0x6B, 0xFB, 0x5A, 0x89, 0x9F, 0xA5, 0xAE, 0x9F, 0x24, 0x11, 0x7C, 0x4B, 0x1F, 0xE6,
    0x49, 0x28, 0x66, 0x51, 0xEC, 0xE4, 0x5B, 0x3D, 0xC2, 0x00, 0x7C, 0xB8, 0xA1, 0x63, 0xBF, 0x05,
    0x98, 0xDA, 0x48, 0x36, 0x1C, 0x55, 0xD3, 0x9A, 0x69, 0x16, 0x3F, 0xA8, 0xFD, 0x24, 0xCF, 0x5F,
    0x83, 0x65, 0x5D, 0x23, 0xDC, 0xA3, 0xAD, 0x96, 0x1C, 0x62, 0xF3, 0x56, 0x20, 0x85, 0x52, 0xBB,
    0x9E, 0xD5, 0x29, 0x07, 0x70, 0x96, 0x96, 0x6D, 0x67, 0x0C, 0x35, 0x4E, 0x4A, 0xBC, 0x98, 0x04,
    0xF1, 0x74, 0x6C, 0x08, 0xCA, 0x18, 0x21, 0x7C, 0x32, 0x90, 0x5E, 0x46, 0x2E, 0x36, 0xCE, 0x3B,
    0xE3, 0x9E, 0x77, 0x2C, 0x18, 0x0E, 0x86, 0x03, 0x9B, 0x27, 0x83, 0xA2, 0xEC, 0x07, 0xA2, 0x8F,
    0xB5, 0xC5, 0x5D, 0xF0, 0x6F, 0x4C, 0x52, 0xC9, 0xDE, 0x2B, 0xCB, 0xF6, 0x95, 0x58, 0x17, 0x18,
    0x39, 0x95, 0x49, 0x7C, 0xEA, 0x95, 0x6A, 0xE5, 0x15, 0xD2, 0x26, 0x18, 0x98, 0xFA, 0x05, 0x10,
    0x15, 0x72, 0x8E, 0x5A, 0x8A, 0xAC, 0xAA, 0x68, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

const BYTE rgbDh2048Generator[] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02
};

const BYTE rgbDh2048PublicKey1[] = 
{
    0xC7, 0xCF, 0x6A, 0xA3, 0x34, 0x61, 0x7A, 0x6B, 0x65, 0x2E, 0xE3, 0x73, 0xD8, 0x59, 0x5E, 0x0C,
    0x35, 0x7D, 0x22, 0x5C, 0xC3, 0x9E, 0x3E, 0xAC, 0x81, 0x85, 0x8C, 0x19, 0x86, 0xCC, 0xB4, 0x33,
    0x26, 0x72, 0x6B, 0xD3, 0xE7, 0x6F, 0x99, 0x7A, 0x65, 0x28, 0x10, 0xC9, 0x75, 0xF2, 0x57, 0x45,
    0xD3, 0x4A, 0x9E, 0x00, 0xB7, 0x8F, 0xA7, 0xDA, 0xBF, 0x1D, 0x5C, 0xBD, 0xF6, 0xEA, 0xAB, 0x66,
    0x25, 0x26, 0x74, 0x67, 0xC5, 0x79, 0xEA, 0x69, 0x56, 0x89, 0x89, 0xCE, 0x11, 0x9F, 0xA1, 0xE3,
    0x0B, 0x61, 0x63, 0x10, 0x89, 0x75, 0x0D, 0xAB, 0x1A, 0x59, 0x5E, 0xEF, 0xDC, 0xDD, 0x24, 0x49,
    0xF3, 0x0C, 0x13, 0x04, 0x60, 0x4C, 0xCD, 0x25, 0x82, 0x07, 0xD5, 0x9B, 0x7A, 0x99, 0x86, 0x86,
    0x4F, 0xC6, 0x43, 0x87, 0x55, 0xB2, 0x52, 0x90, 0x8B, 0xB3, 0xDA, 0x71, 0x51, 0x8D, 0x5A, 0xBD,
    0x24, 0xE1, 0x4E, 0x9B, 0xDF, 0xBB, 0xAD, 0x0F, 0xFF, 0x4A, 0xE8, 0xFA, 0xD8, 0xE7, 0x52, 0x10,
    0x65, 0x91, 0x61, 0x0D, 0x09, 0x09, 0xE2, 0x2E, 0x20, 0xC9, 0x0C, 0x76, 0x61, 0x5E, 0xA7, 0xDA,
    0xD0, 0x08, 0x7A, 0xD7, 0x4F, 0xAD, 0x37, 0x57, 0x45, 0x92, 0x38, 0x83, 0x17, 0xF1, 0x04, 0xA9,
    0x38, 0x45, 0xD2, 0xA6, 0xC0, 0xDA, 0x2B, 0xD0, 0xBA, 0x81, 0xD6, 0xF0, 0x2A, 0x0F, 0x03, 0xD6,
    0xD4, 0x31, 0x54, 0x49, 0x0D, 0x87, 0x04, 0x53, 0x51, 0xED, 0xF1, 0x96, 0x65, 0xEA, 0xA1, 0x28,
    0x60, 0x9D, 0xB7, 0x50, 0xA8, 0x66, 0x22, 0x70, 0x74, 0x51, 0x28, 0x81, 0xB2, 0xCA, 0x37, 0x83,
    0xDC, 0x55, 0x4D, 0xF2, 0xBB, 0xBB, 0xD6, 0x33, 0xA4, 0xD4, 0x2A, 0x01, 0xEF, 0xD8, 0xDA, 0xC2,
    0xE1, 0x20, 0xD8, 0xAE, 0x41, 0xEF, 0x5A, 0x63, 0x0D, 0x2B, 0x05, 0xD2, 0x21, 0xCC, 0x2A, 0xCC
};

const BYTE rgbDh2048PrivateKey1[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x04, 0x5A, 0x39, 0xD6, 0x42, 0xB3, 0xEE, 0xD0, 0x12, 0x2C, 0x47, 0xB3, 0x52, 0xC1, 0xC5, 0x00,
    0x21, 0xAD, 0x3F, 0x1B, 0xFA, 0x3D, 0x9A, 0xD3, 0x6D, 0x28, 0x5C, 0xDE, 0x08, 0xA5, 0xA5, 0xF6,
    0xCA, 0xD0, 0x22, 0xD1, 0x4F, 0x85, 0xF4, 0x49, 0x9F, 0x04, 0x84, 0x8D, 0x72, 0xEA, 0xD8, 0x3F,
    0xE4, 0x2E, 0xE1, 0xF8, 0xE4, 0x7C, 0x4F, 0xDC, 0x16, 0xF6, 0x3D, 0x28, 0x2E, 0x79, 0x8F, 0xC5
};

const BYTE rgbDh2048PublicKey2[] = 
{
    0x4F, 0x43, 0xD9, 0x96, 0x07, 0xFE, 0x75, 0x0A, 0xB9, 0x70, 0x6A, 0x45, 0xB9, 0xCF, 0xA6, 0xA9,
    0x1D, 0x56, 0x7A, 0x2A, 0x87, 0xA1, 0xE6, 0xFF, 0x77, 0xDD, 0x9E, 0x87, 0x45, 0x1E, 0xEC, 0x8D,
    0x6A, 0x31, 0x84, 0xB9, 0x79, 0x9A, 0x1E, 0xFE, 0xEF, 0x4C, 0x3A, 0xF8, 0xA0, 0xEB, 0xCE, 0xA4,
    0x8A, 0xA1, 0x93, 0x55, 0x54, 0x2B, 0x52, 0x9E, 0xF3, 0xE0, 0x61, 0x42, 0x8E, 0x77, 0x7E, 0x2C,
    0xB7, 0x6A, 0xC1, 0x1F, 0xB2, 0xAF, 0x63, 0x48, 0xDC, 0xB6, 0x5D, 0xCB, 0x6B, 0x73, 0xD8, 0x39,
    0x88, 0xFC, 0xC0, 0xCA, 0x90, 0x0A, 0x47, 0x84, 0xA2, 0xC8, 0xB7, 0x43, 0x63, 0x19, 0x4B, 0x8F,
    0x1E, 0x06, 0x77, 0x75, 0x94, 0xF4, 0xD5, 0x50, 0x4B, 0x32, 0xA4, 0xB8, 0xC2, 0xF0, 0xA3, 0xE1,
    0xED, 0x08, 0x7B, 0x52, 0xFF, 0x6D, 0x99, 0xD2, 0x93, 0xD1, 0x7F, 0xA8, 0xF3, 0x01, 0x2D, 0x0B,
    0x4E, 0x51, 0xA3, 0x23, 0x7E, 0xC1, 0x97, 0x30, 0x15, 0xF2, 0xEC, 0x4C, 0x29, 0x0D, 0xEF, 0xF5,
    0xCA, 0x02, 0x0F, 0x46, 0x56, 0xF5, 0xC6, 0xE0, 0x82, 0xBB, 0x4F, 0x9C, 0xC3, 0x35, 0x04, 0x4A,
    0x58, 0x63, 0xA4, 0x4E, 0x23, 0x1B, 0x86, 0xA2, 0x1D, 0x1F, 0x7A, 0x34, 0x3B, 0x9C, 0x81, 0x2F,
    0x9E, 0xFF, 0x9B, 0x32, 0x6B, 0x18, 0x9C, 0xAA, 0xC4, 0x0E, 0x63, 0xAD, 0x56, 0x4A, 0x3A, 0x02,
    0x3F, 0xE9, 0x8A, 0xA1, 0x87, 0xF9, 0xCE, 0x39, 0xEB, 0x47, 0x3A, 0xC2, 0x82, 0x65, 0x7D, 0xC6,
    0x52, 0x33, 0x8B, 0x56, 0xCB, 0x18, 0xD9, 0x08, 0x13, 0xA1, 0xC8, 0x4D, 0xB2, 0x93, 0x1F, 0x4F,
    0x81, 0xBF, 0xD6, 0x5F, 0x58, 0x39, 0x2D, 0xE9, 0xF3, 0x44, 0xC1, 0x46, 0x48, 0x2E, 0xC3, 0x59,
    0xAD, 0xC4, 0x40, 0xED, 0x8D, 0x2C, 0xC4, 0x62, 0x43, 0xA8, 0x42, 0xE1, 0x72, 0xAC, 0xDE, 0x11
};

const BYTE rgbDh2048PrivateKey2[] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xCE, 0x80, 0x11, 0x1E, 0x79, 0xCA, 0xBC, 0x8E, 0xBE, 0x82, 0x57, 0xF9, 0x13, 0x17, 0x89, 0x47,
    0xE7, 0xED, 0x1A, 0x0A, 0x29, 0x8E, 0x7A, 0x40, 0xB5, 0xF4, 0x1E, 0xF0, 0x4B, 0x13, 0x28, 0x77,
    0x9B, 0xBF, 0x15, 0xFE, 0xD4, 0xF2, 0x4B, 0x2A, 0x65, 0x40, 0x64, 0xC3, 0x75, 0x16, 0xF8, 0x21,
    0x30, 0x47, 0x08, 0x55, 0x94, 0xD7, 0x4B, 0x9A, 0x26, 0x38, 0xAC, 0x71, 0x44, 0x39, 0x64, 0x8F
};

typedef struct _SYMCRYPT_SELFTEST_ECKEY_P256
{
    BYTE Qx[32];
    BYTE Qy[32];
    BYTE d[32];
} SYMCRYPT_SELFTEST_ECKEY_P256;

SYMCRYPT_SELFTEST_ECKEY_P256 eckey1 =
{
    // Qx
    {
        0xdd, 0xd5, 0x15, 0x20, 0x43, 0x8d, 0x41, 0xa9,
        0x18, 0xcf, 0x62, 0xc2, 0x13, 0xf7, 0xed, 0xb2,
        0xf9, 0x8f, 0x02, 0xa3, 0x78, 0x30, 0x7e, 0x22,
        0x8f, 0xc1, 0x44, 0xbe, 0xde, 0xc6, 0x65, 0x91
    },
    //Qy
    {
        0x72, 0xad, 0x17, 0xad, 0x51, 0x8c, 0xd3, 0x60,
        0x0f, 0x54, 0xc0, 0xf4, 0xc3, 0x22, 0x5b, 0x44,
        0xab, 0xad, 0x28, 0xb5, 0x56, 0x8e, 0x78, 0x0a,
        0x6a, 0x09, 0x6b, 0x65, 0x81, 0x6d, 0x6f, 0x99
    },
    //d
    {
        0x07, 0x36, 0x9f, 0xb2, 0x35, 0xce, 0xe2, 0xd4,
        0x7e, 0x13, 0x35, 0x31, 0xae, 0xa5, 0x6e, 0x6c,
        0x96, 0xd3, 0x9f, 0x3b, 0xa7, 0x74, 0xae, 0xf9,
        0x7a, 0x56, 0x6e, 0xfe, 0x32, 0x3f, 0x43, 0xaa
    },
};

SYMCRYPT_SELFTEST_ECKEY_P256 eckey2 =
{
    //Qx
    {
        0x21, 0xf2, 0xf7, 0x08, 0x8c, 0x71, 0x59, 0xa7,
        0x0c, 0xe1, 0xb9, 0x1a, 0xe0, 0xed, 0x69, 0xbe,
        0x44, 0xeb, 0xa3, 0x51, 0xfd, 0x32, 0x4a, 0x90,
        0xdc, 0xde, 0xa4, 0x10, 0xe4, 0x44, 0x69, 0x29
    },
    //Qy
    {
        0x74, 0xd0, 0xc6, 0xbd, 0xe5, 0x13, 0x68, 0x07,
        0x9f, 0x40, 0x5e, 0xbf, 0x9e, 0x61, 0x7c, 0x3f,
        0xc8, 0x16, 0xe2, 0xd5, 0x0e, 0xf8, 0x09, 0x15,
        0xf3, 0x30, 0xba, 0x45, 0x25, 0xab, 0x9a, 0xae
    },
    //d
    {
        0xd0, 0x93, 0xf2, 0x34, 0x82, 0x39, 0xa6, 0x5c,
        0xd7, 0xe5, 0x10, 0x27, 0x0f, 0xfc, 0x0a, 0x0d,
        0x89, 0x97, 0x10, 0xa7, 0x50, 0x5a, 0xc4, 0x1b,
        0x5d, 0x18, 0x03, 0x2f, 0x7d, 0x46, 0x58, 0x4d
    }
};

VOID
SYMCRYPT_CALL
SymCryptDhSecretAgreementSelftest()
{
    SYMCRYPT_ERROR scError = SYMCRYPT_NO_ERROR;

    PSYMCRYPT_DLGROUP pDlgroup = NULL;
    PSYMCRYPT_DLKEY pkKey1Private = NULL;
    PSYMCRYPT_DLKEY pkKey1Public = NULL;
    PSYMCRYPT_DLKEY pkKey2Private = NULL;
    PSYMCRYPT_DLKEY pkKey2Public = NULL;

    BYTE rgbSecret1[sizeof(rgbDh2048PublicKey1)];
    BYTE rgbSecret2[sizeof(rgbDh2048PublicKey1)];

    pDlgroup = SymCryptDlgroupAllocate( sizeof(rgbDh2048PublicKey1) * 8, 0 );
    SYMCRYPT_FIPS_ASSERT(pDlgroup != NULL);

    scError = SymCryptDlgroupSetValue(
        rgbDh2048Modulus,
        sizeof(rgbDh2048Modulus),
        NULL, // pbPrimeQ
        0,  // cbPrimeQ
        rgbDh2048Generator,
        sizeof(rgbDh2048Generator),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        NULL, // pHashAlgorithm
        NULL, // pbSeed
        0, // cbSeed
        0, // genCounter
        SYMCRYPT_DLGROUP_FIPS_NONE,
        pDlgroup);
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    pkKey1Private = SymCryptDlkeyAllocate( pDlgroup );
    SYMCRYPT_FIPS_ASSERT( pkKey1Private != NULL );

    scError = SymCryptDlkeySetValue(
        rgbDh2048PrivateKey1,
        sizeof(rgbDh2048PrivateKey1),
        rgbDh2048PublicKey1,
        sizeof(rgbDh2048PublicKey1),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0,
        pkKey1Private );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    pkKey1Public = SymCryptDlkeyAllocate( pDlgroup );
    SYMCRYPT_FIPS_ASSERT( pkKey1Public != NULL );

    scError = SymCryptDlkeySetValue(
        NULL, // pbPrivateKey
        0, // cbPrivateKey
        rgbDh2048PublicKey1,
        sizeof(rgbDh2048PublicKey1),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0,
        pkKey1Public );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    pkKey2Private = SymCryptDlkeyAllocate( pDlgroup );
    SYMCRYPT_FIPS_ASSERT( pkKey2Private != NULL );

    scError = SymCryptDlkeySetValue(
        rgbDh2048PrivateKey2,
        sizeof(rgbDh2048PrivateKey2),
        rgbDh2048PublicKey2,
        sizeof(rgbDh2048PublicKey2),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0,
        pkKey2Private );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Allocate a new Dlkey for the test public key so we can do secret agreement with
    // (test public key, caller private key)
    pkKey2Public = SymCryptDlkeyAllocate( pDlgroup );
    SYMCRYPT_FIPS_ASSERT( pkKey2Public != NULL );

    scError = SymCryptDlkeySetValue(
        NULL, // pbPrivateKey
        0, // cbPrivateKey
        rgbDh2048PublicKey2,
        sizeof(rgbDh2048PublicKey2),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0,
        pkKey2Public );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Calculate secret 1 using private key 1 and public key 2
    scError = SymCryptDhSecretAgreement(
        pkKey1Private,
        pkKey2Public,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_FLAG_BYPASS_FIPS_SELFTEST,
        rgbSecret1,
        sizeof(rgbSecret1) );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Calculate secret 2 using private key 2 and public key 1
    scError = SymCryptDhSecretAgreement(
        pkKey2Private,
        pkKey1Public,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_FLAG_BYPASS_FIPS_SELFTEST,
        rgbSecret2,
        sizeof(rgbSecret2) );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Verify that secret1 == secret2
    SYMCRYPT_FIPS_ASSERT( memcmp( rgbSecret1, rgbSecret2, sizeof(rgbSecret1) ) == 0 );

    SymCryptDlkeyFree( pkKey2Public );
    SymCryptDlkeyFree( pkKey2Private );
    SymCryptDlkeyFree( pkKey1Public );
    SymCryptCallbackFree( pkKey1Private );
    SymCryptDlgroupFree( pDlgroup );
}

VOID
SYMCRYPT_CALL
SymCryptEcDhSecretAgreementSelftest( )
{
    SYMCRYPT_ERROR scError = SYMCRYPT_NO_ERROR;

    PSYMCRYPT_ECURVE pCurve = NULL;
    PSYMCRYPT_ECKEY pkKey1Private = NULL;
    PSYMCRYPT_ECKEY pkKey1Public = NULL;
    PSYMCRYPT_ECKEY pkKey2Private = NULL;
    PSYMCRYPT_ECKEY pkKey2Public = NULL;

    PBYTE pbSecret1 = NULL;
    PBYTE pbSecret2 = NULL;
    UINT32 cbSecret = 0;

    pCurve = SymCryptEcurveAllocate( SymCryptEcurveParamsNistP256, 0 );
    SYMCRYPT_FIPS_ASSERT( pCurve != NULL );

    pkKey1Private = SymCryptEckeyAllocate( pCurve );
    SYMCRYPT_FIPS_ASSERT( pkKey1Private != NULL );

    scError = SymCryptEckeySetValue(
        eckey1.d,
        sizeof(eckey1.d),
        NULL,
        0,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_ECPOINT_FORMAT_XY,
        0, // flags
        pkKey1Private);
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    pkKey1Public = SymCryptEckeyAllocate( pCurve );
    SYMCRYPT_FIPS_ASSERT( pkKey1Public != NULL );

    scError = SymCryptEckeySetValue(
        NULL,
        0,
        eckey1.Qx,
        sizeof(eckey1.Qx) + sizeof(eckey1.Qy),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_ECPOINT_FORMAT_XY,
        0, // flags
        pkKey1Public );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    pkKey2Private = SymCryptEckeyAllocate( pCurve );
    SYMCRYPT_FIPS_ASSERT( pkKey2Private != NULL );

    scError = SymCryptEckeySetValue(
        eckey2.d,
        sizeof(eckey2.d),
        NULL,
        0,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_ECPOINT_FORMAT_XY,
        0, // flags
        pkKey2Private);
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    pkKey2Public = SymCryptEckeyAllocate( pCurve );
    SYMCRYPT_FIPS_ASSERT( pkKey2Public != NULL );

    scError = SymCryptEckeySetValue(
        NULL,
        0,
        eckey2.Qx,
        sizeof(eckey2.Qx) + sizeof(eckey2.Qy),
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_ECPOINT_FORMAT_XY,
        0,
        pkKey2Public );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    cbSecret = SymCryptEcurveSizeofFieldElement( pCurve );
    pbSecret1 = SymCryptCallbackAlloc( cbSecret );
    SYMCRYPT_FIPS_ASSERT( pbSecret1 != NULL );

    pbSecret2 = SymCryptCallbackAlloc( cbSecret );
    SYMCRYPT_FIPS_ASSERT( pbSecret2 != NULL );

    // Calculate secret 1 using private key 1 and public key 2
    scError = SymCryptEcDhSecretAgreement(
        pkKey1Private,
        pkKey2Public,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_FLAG_BYPASS_FIPS_SELFTEST,
        pbSecret1,
        cbSecret);
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Calculate secret 2 using private key 2 and public key 1
    scError = SymCryptEcDhSecretAgreement(
        pkKey2Private,
        pkKey1Public,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SYMCRYPT_FLAG_BYPASS_FIPS_SELFTEST,
        pbSecret2,
        cbSecret);
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    // Verify secret 1 == secret 2
    SYMCRYPT_FIPS_ASSERT( memcmp(pbSecret1, pbSecret2, cbSecret) == 0 );

    SymCryptCallbackFree( pbSecret2 );
    SymCryptCallbackFree( pbSecret1 );
    SymCryptEckeyFree( pkKey2Public );
    SymCryptEckeyFree( pkKey2Private );
    SymCryptEckeyFree( pkKey1Public );
    SymCryptEckeyFree( pkKey1Private );
    SymCryptEcurveFree( pCurve );
}

VOID
SYMCRYPT_CALL
SymCryptDsaPairwiseSelftest(
    _In_ PCSYMCRYPT_DLKEY pkCallerKey )
{
    SYMCRYPT_ERROR scError = SYMCRYPT_NO_ERROR;

    BYTE rbHashValue[SYMCRYPT_SHA256_RESULT_SIZE];
    SIZE_T cbHashValue = sizeof(rbHashValue);

    PBYTE pbSignature = NULL;
    SIZE_T cbSignature = 0;

    scError = SymCryptCallbackRandom( rbHashValue, cbHashValue );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    cbSignature = 2 * SymCryptDlkeySizeofPrivateKey( pkCallerKey );
    pbSignature = SymCryptCallbackAlloc( cbSignature );
    SYMCRYPT_FIPS_ASSERT( pbSignature != NULL );

    scError = SymCryptDsaSign(
                pkCallerKey,
                rbHashValue,
                cbHashValue,
                SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
                0,
                pbSignature,
                cbSignature );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    scError = SymCryptDsaVerify(
                pkCallerKey,
                rbHashValue,
                cbHashValue,
                pbSignature,
                cbSignature,
                SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
                0 );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    SymCryptCallbackFree( pbSignature );
}

VOID
SYMCRYPT_CALL
SymCryptEcDsaPairwiseSelftest(
    _In_ PCSYMCRYPT_ECKEY pkCallerKey )
{
    SYMCRYPT_ERROR scError = SYMCRYPT_NO_ERROR;

    BYTE rbHashValue[SYMCRYPT_SHA256_RESULT_SIZE];
    SIZE_T cbHashValue = sizeof(rbHashValue);

    PBYTE pbSignature = NULL;
    SIZE_T cbSignature = 0;

    scError = SymCryptCallbackRandom( rbHashValue, cbHashValue );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    cbSignature = 2 * SymCryptEcurveSizeofFieldElement( pkCallerKey->pCurve );
    pbSignature = SymCryptCallbackAlloc( cbSignature );
    SYMCRYPT_FIPS_ASSERT( pbSignature != NULL );

    scError = SymCryptEcDsaSign(
        pkCallerKey,
        rbHashValue,
        cbHashValue,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0,
        pbSignature,
        cbSignature );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    scError = SymCryptEcDsaVerify(
        pkCallerKey,
        rbHashValue,
        cbHashValue,
        pbSignature,
        cbSignature,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        0 );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR )

    SymCryptCallbackFree( pbSignature );
}

VOID
SYMCRYPT_CALL
SymCryptRsaPairwiseSelftest(
    _In_ PCSYMCRYPT_RSAKEY pkCallerKey )
{
    SYMCRYPT_ERROR scError = SYMCRYPT_NO_ERROR;

    BYTE rbHashValue[SYMCRYPT_SHA256_RESULT_SIZE] = { 0 };
    SIZE_T cbHashValue = sizeof(rbHashValue);

    PBYTE pbSignature = NULL;
    SIZE_T cbSignature = 0;

    scError = SymCryptCallbackRandom( rbHashValue, cbHashValue );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    cbSignature = pkCallerKey->nBitsOfModulus / 8;
    pbSignature = SymCryptCallbackAlloc( cbSignature );
    SYMCRYPT_FIPS_ASSERT( pbSignature != NULL );

    scError = SymCryptRsaPkcs1Sign(
        pkCallerKey,
        rbHashValue,
        cbHashValue,
        SymCryptSha256OidList,
        SYMCRYPT_SHA256_OID_COUNT,
        0,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        pbSignature,
        cbSignature,
        &cbSignature );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    scError = SymCryptRsaPkcs1Verify(
        pkCallerKey,
        rbHashValue,
        cbHashValue,
        pbSignature,
        cbSignature,
        SYMCRYPT_NUMBER_FORMAT_MSB_FIRST,
        SymCryptSha256OidList,
        SYMCRYPT_SHA256_OID_COUNT,
        0 );
    SYMCRYPT_FIPS_ASSERT( scError == SYMCRYPT_NO_ERROR );

    SymCryptCallbackFree( pbSignature );
}