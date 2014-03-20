#include "amftest.hpp"

#include "amf.hpp"
#include "types/amfbool.hpp"
#include "types/amfnull.hpp"
#include "types/amfundefined.hpp"

static void isEqual(const std::vector<u8>& expected, bool value) {
	isEqual(expected, AmfBool(value));
}

TEST(BoolSerializationTest, SimpleValues) {
	isEqual(v8 { 0x02 }, false);
	isEqual(v8 { 0x03 }, true);
}

TEST(BoolEquality, SimpleValues) {
	AmfBool b1(true);
	AmfBool b2(true);
	EXPECT_EQ(b1, b2);

	AmfBool b3(false);
	AmfBool b4(false);
	EXPECT_EQ(b3, b4);

	EXPECT_NE(b1, b3);
	EXPECT_NE(b4, b2);
}

TEST(BoolEquality, MixedTypes) {
	AmfBool b1(true);
	AmfBool b2(false);
	AmfUndefined u;
	EXPECT_NE(b1, u);
	EXPECT_NE(b2, u);

	AmfNull n;
	EXPECT_NE(b1, n);
	EXPECT_NE(b2, n);
}

TEST(BoolEquality, ImplicitBoolConversion) {
	AmfBool b1(true);
	AmfBool b2(false);
	EXPECT_EQ(b1, true);
	EXPECT_NE(b1, false);

	EXPECT_EQ(b2, false);
	EXPECT_NE(b2, true);
}
