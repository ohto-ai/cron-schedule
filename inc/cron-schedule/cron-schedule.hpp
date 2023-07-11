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

        class cron_task;
        class cron_schedule;
        /**
         * @brief Get the next time of the cron schedule.
         * @param task The cron task.
         * @param base_time The base time.
         * @return The next time of the cron schedule.
        */
        std::time_t get_next_time(const cron_task& task, const std::time_t& base_time);

        
        class cron_schedule {
        public: // interface
            /// @brief run tick to invoke callback function.
            void tick();

            /// @brief add cron task.
            /// @param task_name The taks name. e.g. "myTask"
            /// @param cron The cron schedule. e.g. "0 0 0 * * *"
            /// @param callback The callback function.
            void add_task(const std::string& task_name, const cron::cronexpr& cron, std::function<void(cron_task& )> callback);

        private: // member variables
            // todo: add member variables here.
        };
    }
}
