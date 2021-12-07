#include <gtest/gtest.h>
#include "../Dungeon.cpp"

class DungeonTest : public ::testing::Test
{
protected:
    int x = 5;
    int y = 5;
    int vampires = 2;
    int moves = 10;
    Dungeon dungeon = Dungeon(x, y, vampires, moves);
};

TEST_F(DungeonTest, MovesCounter)
{
    ASSERT_EQ(moves, dungeon.getMoves());
}

TEST_F(DungeonTest, VampiresCreation)
{
    ASSERT_EQ(vampires, dungeon.getVampiresCount());
}

TEST_F(DungeonTest, MoveLeft)
{
    //player need to be moved right because he can't moves left if he's in the starting point [0][0]
    dungeon.setPosition(1, 1);
    Direction left(-1, 0);
    int pos = dungeon.getPlayerX();
    dungeon.movePlayer(left);
    ASSERT_EQ(pos + left.getX(), dungeon.getPlayerX());
    ASSERT_EQ(pos + left.getY(), dungeon.getPlayerY());
}

TEST_F(DungeonTest, MoveRightTest)
{
    dungeon.setPosition(1, 1);
    Direction right(1, 0);
    int pos = dungeon.getPlayerX();
    dungeon.movePlayer(right);
    ASSERT_EQ(pos + right.getX(), dungeon.getPlayerX());
    ASSERT_EQ(pos + right.getY(), dungeon.getPlayerY());
}

TEST_F(DungeonTest, MoveUpTest)
{
    dungeon.setPosition(1, 1);
    Direction up(0, -1);
    int pos = dungeon.getPlayerX();
    dungeon.movePlayer(up);
    ASSERT_EQ(pos + up.getX(), dungeon.getPlayerX());
    ASSERT_EQ(pos + up.getY(), dungeon.getPlayerY());
}

TEST_F(DungeonTest, MoveDownTest)
{
    dungeon.setPosition(1, 1);
    Direction down(0, 1);
    int pos = dungeon.getPlayerX();
    dungeon.movePlayer(down);
    ASSERT_EQ(pos + down.getX(), dungeon.getPlayerX());
    ASSERT_EQ(pos + down.getY(), dungeon.getPlayerY());
}
