#include <catch2/catch.hpp>
#include <iostream>
#include <cron-schedule/cron-schedule.hpp>

TEST_CASE("Test simple", "") {
    ohtoai::cron_schedule::cron_schedule schedule;
    const auto task_name = "myTask";
    const auto cron = cron::make_cron("* * * * * *");

    auto& task = schedule.add_task("myTask", cron::make_cron("* * * * * *"), [](ohtoai::cron_schedule::cron_task& task){});

    const auto base_time = std::time(nullptr);
    const auto next_time = task.next_time(base_time);
    const auto expected_next_time = base_time + 1;

    REQUIRE(task.task_name() == task_name);
    REQUIRE(task.cron() == cron);
    REQUIRE(schedule.size() == 1);
    REQUIRE(next_time == expected_next_time);
}
