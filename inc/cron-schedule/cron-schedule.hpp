/**
 * @file cron-schedule.hpp
 * @brief Include file for the cron-schedule library.
 * @author ohto-ai
*/

#pragma once

#include <functional>
#include "croncpp/croncpp.h"

namespace ohtoai{
    namespace cron_schedule{
        /**
         * @brief Get the next time of the cron schedule.
         * @param cron_schedule The cron schedule.
         * @param base_time The base time.
         * @return The next time of the cron schedule.
        */
        std::time_t get_next_time(const std::string& cron_schedule, const std::time_t& base_time);

        class cron_schedule {
        public: // interface

            /// @brief get next time from base time.
            /// @param base_time now time
            /// @return next time tick
            std::time_t get_next_time(const std::time_t& base_time);

            /// @brief run tick to invoke callback function.
            void tick();

            /// @brief set callback function.
            /// @param cron The cron schedule. e.g. "0 0 0 * * *"
            /// @param callback The callback function.
            void schedule(const std::string& cron, std::function<void(cron_schedule& )> callback);

        private: // member variables
            // todo: add member variables here.
        };
    }
}
