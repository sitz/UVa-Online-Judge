#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <tchar.h>

#include "10315.cpp"

using namespace std;

TEST(PokerHandTest, testFlush) {
	PokerHand p;
	p.fetchCard("TC JC 9C QC AC");
	EXPECT_TRUE(p.isFlush());
	EXPECT_TRUE(p.getRank() == FLUSH);
	p.fetchCard("4S 9S TS QS 3S");
	EXPECT_TRUE(p.isFlush());
}

TEST(PokerHandTest, testStraight) {
	PokerHand p;
	p.fetchCard("TR JQ 9T QO KG");
	EXPECT_EQ(p.getRank(), STRAIGHT);
	EXPECT_TRUE(p.isStraight());
}

TEST(PokerHandTest, testStraightFlush) {
	PokerHand p;
	p.fetchCard("2C 3C 4C 5C 6C");
	EXPECT_TRUE(p.isStraight());
	EXPECT_TRUE(p.isFlush());
	EXPECT_EQ(p.getRank(), STRAIGHT_FLUSH);
}

TEST(PokerHandTest, test4Kind) {
	PokerHand p;
	p.fetchCard("4A 4B 4C 7A 4C");
	EXPECT_TRUE(p.is4Kind());
	EXPECT_EQ(p.getRank(), FOUR_KIND);
}

TEST(PokerHandTest, testFullHouse) {
	PokerHand p;
	p.fetchCard("8C 2C 8D 2R 8E");
	EXPECT_EQ(p.getRank(), FULL_HOUSE);
	EXPECT_TRUE(p.is3Kind());
	EXPECT_EQ(p.numPairs(), 2);
	EXPECT_FALSE(p.is4Kind());
}

TEST(PokerHandTest, test3Kind) {
	PokerHand p;
	p.fetchCard("AD 2C AC 4V AH");
	EXPECT_TRUE(p.is3Kind());
	EXPECT_EQ(p.getRank(), THREE_KIND);
}

TEST(PokerHandTest, testNumPairs) {
	PokerHand p;
	p.fetchCard("1C 2C 1E 4A 3A");
	EXPECT_EQ(p.numPairs(), 1);
	EXPECT_EQ(p.getRank(), PAIR);
	p.fetchCard("JC QR JH 4C QH");
	EXPECT_EQ(p.numPairs(), 2);
	EXPECT_EQ(p.getRank(), TWO_PAIR);
	p.fetchCard("3B 6H AH AC AY");
	EXPECT_EQ(p.numPairs(), 1);
	EXPECT_EQ(p.getRank(), THREE_KIND);
}

TEST(PokerHandTest, testHighCard) {
	PokerHand p;
	p.fetchCard("6C 7C 8H JQ KQ");
	EXPECT_EQ(p.getRank(), HIGH_CARD);
}

TEST(PokerHandTest, compare1) {
	PokerHand p1, p2;
	p1.fetchCard("6C 7H 8C 9C TC");
	p2.fetchCard("AC AH 7H AD 7C");
	EXPECT_EQ(p1.compareTo(p2), -1);
	EXPECT_EQ(p2.compareTo(p1), 1);
}

TEST(PokerHandTest, compareTwoPair) {
	PokerHand p1, p2;
	p1.fetchCard("6C 6H 8C 8C TC");
	p2.fetchCard("AC AH 2H 9D 9C");
	EXPECT_EQ(p1.compareTo(p2), -1);
	EXPECT_EQ(p2.compareTo(p1), 1);
	p1.fetchCard("3D 3S 4C 4H KS");
	p2.fetchCard("3C 3H 4D 4D 7H");
	EXPECT_EQ(p1.compareTo(p2), 1);
	EXPECT_EQ(p2.compareTo(p1), -1);
	p1.fetchCard("3C 3H 4D 4D 7H");
	EXPECT_EQ(p1.compareTo(p2), 0);
}

TEST(PokerHand, comparePair) {
	PokerHand p1, p2;
	p1.fetchCard("3C 6H 8C 8C TC");
	p2.fetchCard("2C AH 8H AD 9C");
	EXPECT_EQ(p2.compareTo(p1), 1);
	p1.fetchCard("3C 6H 8C 8C TC");
	p2.fetchCard("2C AH 8H 8D 9C");
	EXPECT_EQ(p1.compareTo(p2), -1);
	EXPECT_EQ(p2.compareTo(p1), 1);
	p1.fetchCard("3C 6H 8S 8C TC");
	p2.fetchCard("2C 6H 8H 8D TC");
	EXPECT_EQ(p1.compareTo(p2), 1);
	p1.fetchCard("9C 5H 8C JC JS");
	p2.fetchCard("9D 5H 8H JD JC");
	EXPECT_EQ(p1.compareTo(p2), 0);
}

TEST(PokerHand, compareHighCard) {
	PokerHand p1, p2;
	p1.fetchCard("3C 6H 8C KC TC");
	p2.fetchCard("2C AH 8H 4D 9C");
	EXPECT_EQ(p2.compareTo(p1), 1);
	EXPECT_EQ(p1.compareTo(p2), -1);
}

TEST(PokerHand, compareTie) {
	PokerHand p1, p2;
	p1.fetchCard("7C 8H 9C TC JC");
	p2.fetchCard("7H 8D 9H TD JS");
	EXPECT_EQ(p1.compareTo(p2), 0);
	p1.fetchCard("7C 7H 7H TC 7D");
	p2.fetchCard("AH 7D 7H 7D 7S");
	EXPECT_EQ(p1.compareTo(p2), 0);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	int r = RUN_ALL_TESTS();
	cin.get();
	return r;
}
