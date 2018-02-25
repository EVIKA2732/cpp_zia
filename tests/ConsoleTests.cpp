#include "gtest/gtest.h"

#include "../src/Console/Console.hh"

TEST(Console, ConsoleHelp)
{
  nz::zia Zia;
  nz::Console console(Zia);
  std::string cmd("help");

  testing::internal::CaptureStdout();
  console.runCmd(cmd);
  std::string output = testing::internal::GetCapturedStdout();
  ASSERT_STREQ(output.c_str(), "List of available commands:\n\tmodules add <module name>\n\tmodules remove <module name>\n\tnetwork set <module name>\n\tmodules list\n\tnetwork reload\n\thelp\n\tstart\n\tstop\n\treload\n");
}

TEST(Console, ConsoleStart) {
    nz::zia Zia;
    nz::Console console(Zia);
    std::string cmd("start");

    // console.runCmd(cmd); // exception thrown ?
}

TEST(Console, ConsoleStop) {
    nz::zia Zia;
    nz::Console console(Zia);
    std::string cmd("stop");

    console.runCmd(cmd);
}

TEST(Console, ConsoleReload) {
    nz::zia Zia;
    nz::Console console(Zia);
    std::string cmd("reload");

    console.runCmd(cmd);
}

TEST(Console, ConsoleNetworkReloadNoModulesNetLoaded) {
    nz::zia Zia;
    nz::Console console(Zia);
    std::string cmd("network reload");

<<<<<<< HEAD
    // testing::internal::CaptureStdout();
    // console.runCmd(cmd); // << SigSegv
    // std::string output = testing::internal::GetCapturedStdout();
    // ASSERT_STREQ(output.c_str(), "[ERROR 4] - Zia Core: No module net is load");
=======
    console.runCmd(cmd);
>>>>>>> 71730086155b103380b0a470c182eecddcaef4d2
}

TEST(Console, ConsoleModulesAdd) {
    nz::zia Zia;
    nz::Console console(Zia);
    std::string cmd("modules add a_module");

    console.runCmd(cmd);
}

TEST(Console, ConsoleModulesRemove) {
    nz::zia Zia;
    nz::Console console(Zia);
    std::string cmd("modules remove a_module");

    console.runCmd(cmd);
}

TEST(Console, ConsoleModulesList) {
    nz::zia Zia;
    nz::Console console(Zia);
    std::string cmd("modules list");

    testing::internal::CaptureStdout();
    console.runCmd(cmd);
    std::string output = testing::internal::GetCapturedStdout();
    //Why no modules ?
    ASSERT_STREQ(output.c_str(), "List of loaded modules\n");
}

TEST(Console, ConsoleBadCmdName) {
    nz::zia Zia;
    nz::Console console(Zia);
    std::string cmd("yes42man");

    testing::internal::CaptureStdout();
    console.runCmd(cmd);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(output.c_str(), "Invalid command\n");
}

TEST(Console, ConsoleBadCmdNbArgs) {
    nz::zia Zia;
    nz::Console console(Zia);
    std::string cmd("yes42man yes42man yes42man yes42man yes42man yes42man yes42man");

    testing::internal::CaptureStdout();
    console.runCmd(cmd);
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_STREQ(output.c_str(), "Invalid command\n");
}