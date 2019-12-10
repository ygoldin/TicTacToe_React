// Created by Yael Goldin

#ifndef TIC_TAC_TOE_SPOT_H
#define TIC_TAC_TOE_SPOT_H

#include "SpotStatus.h"

namespace TicTacToe
{
    class Spot {
        public:
            // create an empty spot
            Spot() : m_status(SpotStatus::Empty) {}

            // see what is in the spot
            SpotStatus getStatus() { return m_status; }

            // update what is in the spot, return whether it was successful
            bool updateStatus(SpotStatus status);
        private:
            SpotStatus m_status;
    };
} // namespace TicTacToe

#endif