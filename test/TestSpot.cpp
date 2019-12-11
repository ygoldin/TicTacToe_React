#include "Spot.h"

#include <gtest/gtest.h>

namespace TicTacToe {
    
    class SpotTest : public ::testing::Test {
        protected:
          Spot m_spot;
    };

TEST_F(SpotTest, CreatedEmptySpot) {
    ASSERT_EQ(m_spot.getStatus(), SpotStatus::Empty);
}

TEST_F(SpotTest, SetEmpty) {
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::Empty));
    ASSERT_EQ(m_spot.getStatus(), SpotStatus::Empty);
}

TEST_F(SpotTest, SetX) {
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::X));
    ASSERT_EQ(m_spot.getStatus(), SpotStatus::X);
}

TEST_F(SpotTest, SetO) {
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::O));
    ASSERT_EQ(m_spot.getStatus(), SpotStatus::O);
}

TEST_F(SpotTest, SetEmptyWhileX) {
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::X));
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::Empty));
    ASSERT_EQ(m_spot.getStatus(), SpotStatus::Empty);
}

TEST_F(SpotTest, SetXWhileX) {
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::X));
    ASSERT_FALSE(m_spot.updateStatus(SpotStatus::X));
    ASSERT_EQ(m_spot.getStatus(), SpotStatus::X);
}

TEST_F(SpotTest, SetOWhileX) {
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::X));
    ASSERT_FALSE(m_spot.updateStatus(SpotStatus::O));
    ASSERT_EQ(m_spot.getStatus(), SpotStatus::X);
}

TEST_F(SpotTest, SetEmptyWhileO) {
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::O));
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::Empty));
    ASSERT_EQ(m_spot.getStatus(), SpotStatus::Empty);
}

TEST_F(SpotTest, SetXWhileO) {
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::O));
    ASSERT_FALSE(m_spot.updateStatus(SpotStatus::X));
    ASSERT_EQ(m_spot.getStatus(), SpotStatus::O);
}

TEST_F(SpotTest, SetOWhileO) {
    ASSERT_TRUE(m_spot.updateStatus(SpotStatus::O));
    ASSERT_FALSE(m_spot.updateStatus(SpotStatus::O));
    ASSERT_EQ(m_spot.getStatus(), SpotStatus::O);
}

} // namespace TicTacToe