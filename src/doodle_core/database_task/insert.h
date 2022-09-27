//
// Created by TD on 2022/5/30.
//
#pragma once

#include <doodle_core/doodle_core_fwd.h>
#include <doodle_core/gui_template/gui_process.h>
namespace doodle::database_n {

class DOODLE_CORE_API insert : public process_handy_tools {
 private:
  class impl;
  std::unique_ptr<impl> p_i;

 public:
  insert();

  virtual ~insert() override;

  void operator()(
      const entt::registry& in_registry,
      const std::vector<entt::entity>& in_insert_data,
      conn_ptr& in_connect
  );
};

}  // namespace doodle::database_n
