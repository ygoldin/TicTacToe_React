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

TEST_F(SpotTest, SetEmptySpot) {
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

} // namespace TicTacToe