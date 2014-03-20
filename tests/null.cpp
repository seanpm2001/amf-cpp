#include "amftest.hpp"

#include "amf.hpp"
#include "types/amfbool.hpp"
#include "types/amfnull.hpp"
#include "types/amfundefined.hpp"

TEST(NullSerializationTest, SimpleValue) {
	ASSERT_EQ(v8 { 0x01 }, AmfNull().serialize());
}

TEST(NullEquality, SimpleValue) {
	AmfNull n1, n2;
	EXPECT_EQ(n1, n2);
}

TEST(NullEquality, MixedType) {
	AmfNull n;
	AmfUndefined u;
	EXPECT_NE(n, u);

	AmfBool b(false);
	EXPECT_NE(n, b);
}
