//
// Created by Zhengxuan Guo on 2024/8/15.
//
#include "bandersnatch/Element.h"
#include "testutils/TestPromptFixture.h"
#include "Constants.h"
#include <boost/test/unit_test.hpp>

namespace verkle::test
{
BOOST_FIXTURE_TEST_SUITE(ElementTest, TestPromptFixture)

BOOST_AUTO_TEST_CASE(testAdd)
{
    uint8_t raw[96] = {
        0x5, 0x72, 0xcb, 0xea, 0x90, 0x4d, 0x67, 0x46, 0x88, 0x8, 0xc8, 0xeb, 0x50, 0xa9, 0x45, 0xc, 
        0x97, 0x21, 0xdb, 0x30, 0x91, 0x28, 0x1, 0x25, 0x43, 0x90, 0x2d, 0xa, 0xc3, 0x58, 0xa6, 0x2a, 
        0xe2, 0x8f, 0x75, 0xbb, 0x8f, 0x1c, 0x7c, 0x42, 0xc3, 0x9a, 0x8c, 0x55, 0x29, 0xbf, 0xf, 0x4e, 
        0x16, 0x6a, 0x9d, 0x8c, 0xab, 0xc6, 0x73, 0xa3, 0x22, 0xfd, 0xa6, 0x73, 0x77, 0x9d, 0x8e, 0x38, 
        0x22, 0xba, 0x3e, 0xcb, 0x86, 0x70, 0xe4, 0x61, 0xf7, 0x3b, 0xb9, 0x2, 0x1d, 0x5f, 0xd7, 0x6a, 
        0x4c, 0x56, 0xd9, 0xd4, 0xcd, 0x16, 0xbd, 0x1b, 0xba, 0x86, 0x88, 0x19, 0x79, 0x74, 0x9d, 0x28
    };
    bandersnatch::Element exp(raw, 96);
    auto g = FixedGenerator();
    auto res = bandersnatch::Element::add(g, g);
    BOOST_ASSERT(res == exp);

    bandersnatch::Element g2(g);
    g2.add(g);
    BOOST_ASSERT(g2 == exp);
}

BOOST_AUTO_TEST_CASE(testDouble)
{
    uint8_t raw[96] = {
        0x5, 0x72, 0xcb, 0xea, 0x90, 0x4d, 0x67, 0x46, 0x88, 0x8, 0xc8, 0xeb, 0x50, 0xa9, 0x45, 0xc, 
        0x97, 0x21, 0xdb, 0x30, 0x91, 0x28, 0x1, 0x25, 0x43, 0x90, 0x2d, 0xa, 0xc3, 0x58, 0xa6, 0x2a, 
        0xe2, 0x8f, 0x75, 0xbb, 0x8f, 0x1c, 0x7c, 0x42, 0xc3, 0x9a, 0x8c, 0x55, 0x29, 0xbf, 0xf, 0x4e, 
        0x16, 0x6a, 0x9d, 0x8c, 0xab, 0xc6, 0x73, 0xa3, 0x22, 0xfd, 0xa6, 0x73, 0x77, 0x9d, 0x8e, 0x38, 
        0x22, 0xba, 0x3e, 0xcb, 0x86, 0x70, 0xe4, 0x61, 0xf7, 0x3b, 0xb9, 0x2, 0x1d, 0x5f, 0xd7, 0x6a, 
        0x4c, 0x56, 0xd9, 0xd4, 0xcd, 0x16, 0xbd, 0x1b, 0xba, 0x86, 0x88, 0x19, 0x79, 0x74, 0x9d, 0x28
    };
    bandersnatch::Element exp(raw, 96);
    auto g = FixedGenerator();
    auto res = bandersnatch::Element::dbl(g);
    BOOST_ASSERT(res == exp);

    bandersnatch::Element g2(g);
    g2.dbl();
    BOOST_ASSERT(g2 == exp);
}

BOOST_AUTO_TEST_CASE(testMult)
{
    uint8_t raw[96] = {
        0x16, 0xf8, 0x9e, 0x71, 0x6a, 0xbc, 0x6e, 0x4f, 0x4e, 0xc9, 0xd7, 0x1a, 0x5f, 0x5, 0x38, 0x32, 
        0x51, 0xc0, 0x1e, 0xd9, 0xc4, 0xf, 0x2f, 0x4d, 0xdc, 0x9a, 0x77, 0xd8, 0x7b, 0xf6, 0xc, 0x4a, 
        0xa2, 0xea, 0x60, 0x3a, 0x8d, 0x3a, 0xda, 0x49, 0x4f, 0x6f, 0x6d, 0x15, 0x87, 0x87, 0xa4, 0x49, 
        0xd, 0x83, 0x9, 0x7b, 0xa7, 0x85, 0x97, 0x4, 0x2, 0x4b, 0x49, 0x41, 0xfd, 0x76, 0xf, 0x85, 
        0xbc, 0xa6, 0xdb, 0xc4, 0xa8, 0x4a, 0x7, 0x1a, 0xf9, 0xef, 0x44, 0x3c, 0x1a, 0x55, 0x3f, 0xc8, 
        0x7f, 0xc6, 0x1e, 0x9, 0x92, 0xa4, 0x0, 0x6d, 0x54, 0xfa, 0x36, 0x70, 0x5f, 0x61, 0x16, 0x90
    };
    bandersnatch::Element exp(raw, 96);
    auto g = FixedGenerator();
    auto fr1 = FixedFr1();
    auto res1 = bandersnatch::Element::mult(fr1, g);
    BOOST_ASSERT(res1 == exp);

    bandersnatch::Element g2(g);
    g2.mult(fr1);
    BOOST_ASSERT(g2 == exp);
}

BOOST_AUTO_TEST_CASE(testEqual)
{
    uint8_t raw[96] = {
        0x5, 0x72, 0xcb, 0xea, 0x90, 0x4d, 0x67, 0x46, 0x88, 0x8, 0xc8, 0xeb, 0x50, 0xa9, 0x45, 0xc, 
        0x97, 0x21, 0xdb, 0x30, 0x91, 0x28, 0x1, 0x25, 0x43, 0x90, 0x2d, 0xa, 0xc3, 0x58, 0xa6, 0x2a, 
        0xe2, 0x8f, 0x75, 0xbb, 0x8f, 0x1c, 0x7c, 0x42, 0xc3, 0x9a, 0x8c, 0x55, 0x29, 0xbf, 0xf, 0x4e, 
        0x16, 0x6a, 0x9d, 0x8c, 0xab, 0xc6, 0x73, 0xa3, 0x22, 0xfd, 0xa6, 0x73, 0x77, 0x9d, 0x8e, 0x38, 
        0x22, 0xba, 0x3e, 0xcb, 0x86, 0x70, 0xe4, 0x61, 0xf7, 0x3b, 0xb9, 0x2, 0x1d, 0x5f, 0xd7, 0x6a, 
        0x4c, 0x56, 0xd9, 0xd4, 0xcd, 0x16, 0xbd, 0x1b, 0xba, 0x86, 0x88, 0x19, 0x79, 0x74, 0x9d, 0x28
    };
    bandersnatch::Element e(raw, 96);
    bandersnatch::Element e1(e);
    bandersnatch::Element e2(e);
    BOOST_ASSERT(e1 == e2);
}

BOOST_AUTO_TEST_CASE(testSerialize)
{
    auto g = FixedGenerator();

    byte out[96];
    g.serialize(out);

    bandersnatch::Element recover(out, 96);
    BOOST_ASSERT(recover == g);
}

BOOST_AUTO_TEST_CASE(testCompress)
{
    auto g = FixedGenerator();

    byte out[48];
    g.compress(out);

    bandersnatch::Element recover(out, 48);
    BOOST_ASSERT(recover == g);
}

BOOST_AUTO_TEST_SUITE_END()
}