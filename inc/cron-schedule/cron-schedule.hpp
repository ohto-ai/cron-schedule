/**
 * @file cron-schedule.hpp
 * @brief Include file for the cron-schedule library.
 * @author ohto-ai
*/

#pragma once

#include <functional>
#include <memory>
#include <map>
#include "croncpp/croncpp.h"

namespace ohtoai{
    namespace cron_schedule{

        class cron_task;
        class cron_schedule;
        class time_wheel;


        
        class cron_schedule {
        public: // interface
            /// @brief run tick to invoke callback function.
            void tick();

            /// @brief add cron task.
            /// @param task_name The taks name. e.g. "myTask"
            /// @param cron The cron schedule. e.g. "0 0 0 * * *"
            /// @param callback The callback function.
            /// @return The cron task.
            cron_task& add_task(const std::string& task_name, const cron::cronexpr& cron, std::function<void(cron_task& )> callback);

            /// @brief task count
            /// @return task count
            size_t size() const;
        private: // member variables
            // todo: add member variables here.
            std::map<std::string, std::shared_ptr<cron_task>> tasks_;

        };

        class cron_task {
        public: // interface
            /// @brief Constructor.
            cron_task(const std::string&, const cron::cronexpr&, std::function<void(cron_task& )> callback);

            /// @brief Get the task name.
            /// @return The task name.
            const std::string& task_name() const;

            /// @brief Get the cron schedule.
            /// @return The cron schedule.
            const cron::cronexpr& cron() const;

            /// @brief Get the next time of the cron schedule.
            /// @param base_time The base time.
            /// @return The next time of the cron schedule.
            std::time_t next_time(const std::time_t& base_time) const;
        private: // member variables
            std::string task_name_;
            cron::cronexpr cron_;
            std::function<void(cron_task& )> callback_;
        };
    }
}

/******************************************************************************/
// ohtoai::cron_schedule::cron_schedule
/******************************************************************************/
void ohtoai::cron_schedule::cron_schedule::tick() {
    // todo: implement here.
}

ohtoai::cron_schedule::cron_task& ohtoai::cron_schedule::cron_schedule::add_task(const std::string& task_name, const cron::cronexpr& cron, std::function<void(cron_task& )> callback) {
    // todo: implement here. Add task to time_wheel.
    auto p =  tasks_.emplace(task_name, std::make_shared<cron_task>(task_name, cron, callback));
    return *(p.first->second);
}

size_t ohtoai::cron_schedule::cron_schedule::size() const {
    return tasks_.size();
}

/******************************************************************************/
// ohtoai::cron_schedule::cron_task
/******************************************************************************/
ohtoai::cron_schedule::cron_task::cron_task(const std::string& task_name, const cron::cronexpr& cron, std::function<void(cron_task& )> callback)
    : task_name_(task_name)
    , cron_(cron)
    , callback_(callback)
{
}

const std::string& ohtoai::cron_schedule::cron_task::task_name() const {
    return task_name_;
}

const cron::cronexpr& ohtoai::cron_schedule::cron_task::cron() const {
    return cron_;
}

std::time_t ohtoai::cron_schedule::cron_task::next_time(const std::time_t& base_time) const {
    return cron::cron_next(cron_, base_time);
}
