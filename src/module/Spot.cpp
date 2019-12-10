// Created by Yael Goldin

#include "Spot.h"

namespace TicTacToe
{
    bool Spot::updateStatus(SpotStatus status) {
        switch (status) {
            case Empty:
                m_status = status;
                return true;
            case X:
            case O:
                if (m_status == SpotStatus::Empty) {
                    m_status = status;
                    return true;
                } else {
                    return false;
                }
            default: return false;
        }
    }
} // namespace TicTacToe