//
// Created by TD on 2022/9/29.
//
#include "doodle_core/core/app_base.h"
#include "doodle_core/core/core_help_impl.h"
#include "doodle_core/core/doodle_lib.h"
#include "doodle_core/doodle_core_fwd.h"
#include <doodle_core/doodle_core.h>
#include <doodle_core/json_rpc/core/server.h>
#include <doodle_core/metadata/user.h>
#include <doodle_core/platform/win/get_prot.h>

#include <doodle_app/app/app_command.h>
#include <doodle_app/app/facet/gui_facet.h>
#include <doodle_app/app/this_rpc_exe.h>

#include "doodle_lib/distributed_computing/client.h"
#include <doodle_lib/app/doodle_main_app.h>
#include <doodle_lib/app/rpc_server_facet.h>
#include <doodle_lib/distributed_computing/server.h>
#include <doodle_lib/long_task/image_to_move.h>

#include <boost/asio/executor_work_guard.hpp>
#include <boost/asio/post.hpp>
#include <boost/asio/static_thread_pool.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/process.hpp>
#include <boost/test/tools/interface.hpp>
#include <boost/test/unit_test.hpp>

#include <fmt/core.h>
#include <fmt/format.h>
#include <iostream>
#include <main_fixtures/lib_fixtures.h>

using namespace doodle;
struct loop_rpc {
  doodle_lib l_ib{};
  distributed_computing::server l_s{};
};
BOOST_FIXTURE_TEST_SUITE(rpc, loop_rpc)
BOOST_AUTO_TEST_CASE(base) {
  l_s.run();
  auto l_w = boost::asio::make_work_guard(g_io_context());
  bool run{};
  boost::asio::post(g_thread(), [this, l_run = &run]() {
    distributed_computing::client l_c{};
    // l_c.list_users();
    l_c.close();
    std::cout << "stop run"
              << "\n";
    l_s.work_guard->reset();
    g_io_context().stop();
    *l_run = true;
  });
  // auto l_timer = std::make_shared<boost::asio::high_resolution_timer>(g_io_context());
  // l_timer->expires_after(1s);
  // l_timer->async_wait([l_timer, &l_s](auto) {});

  l_ib.io_context_attr().run();
  BOOST_TEST(run);
}

BOOST_AUTO_TEST_CASE(list_users) {
  l_s.run();
  for (auto i = 0u; i < 10; ++i) {
    auto l_h = make_handle();
    l_h.emplace<user>().set_name(fmt::format("user{}", i));
    l_h.emplace<database>();
  }

  auto l_w = boost::asio::make_work_guard(g_io_context());
  boost::asio::post(g_thread(), [this]() {
    distributed_computing::client l_c{};
    auto l_users = l_c.list_users();
    BOOST_TEST(l_users.size() == 10);
    for (auto&& l_f : l_users) {
      std::cout << "user : " << fmt::to_string(l_f.get<user>()) << std::endl;
    }
    l_c.close();
    std::cout << "stop run"
              << "\n";
    l_s.work_guard->reset();
    g_io_context().stop();
  });
  g_io_context().run();
}

BOOST_AUTO_TEST_SUITE_END()
