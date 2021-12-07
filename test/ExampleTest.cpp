#include <gtest/gtest.h>
#include "../Dungeon.cpp"

class DungeonTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    Dungeon dungeon = (Dungeon(5, 5, 2, 10));
};

TEST_F(DungeonTest, MovesCounter)
{
    ASSERT_EQ(10, dungeon.getMoves());
}
