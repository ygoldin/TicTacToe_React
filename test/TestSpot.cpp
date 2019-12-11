#include "Spot.h"

#include <gtest/gtest.h>

namespace TicTacToe {

TEST(Spot, CreateEmptySpot) {
    Spot s;
    ASSERT_EQ(s.getStatus(), SpotStatus::Empty);
}

} // namespace TicTacToe