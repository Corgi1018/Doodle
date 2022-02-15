//
// Created by TD on 2022/1/20.
//

#include "project.h"

#include <lib_warp/imgui_warp.h>
#include <gui/gui_ref/path.h>
#include <metadata/project.h>

#include <doodle_lib/lib_warp/imgui_warp.h>

namespace doodle::gui {
class project_edit::impl {
 public:
  gui_cache<std::string> project_path;
  gui_cache<std::string> project_name;
  impl()
      : project_path("路径"s, ""s),
        project_name("名称"s, ""s) {}
  project p_prj;
  std::string path;
  project::cloth_config cloth_config;
  std::string cloth_config_path;
};
project_edit::project_edit()
    : p_i(std::make_unique<impl>()) {
}

void project_edit::init_(const entt::handle& in) {
  auto& l_prj            = in.get<project>();
  p_i->p_prj             = l_prj;
  p_i->path              = l_prj.get_path().generic_string();

  p_i->cloth_config      = in.get_or_emplace<project::cloth_config>();
  p_i->cloth_config_path = p_i->cloth_config.vfx_cloth_sim_path.generic_string();
}
void project_edit::save_(const entt::handle& in) const {
  in.emplace_or_replace<project>(p_i->p_prj);
  g_reg()->set<project>(in.get<project>());
}
void project_edit::render(const entt::handle& in) {
  ImGui::Text("基本配置");
  dear::Text(fmt::format("路径: {}", p_i->path));

  if (ImGui::InputText("名称", &p_i->p_prj.p_name)) {
    set_modify(true);
  }

  dear::TreeNode{"解算配置"} &&
      [&]() {
        if (imgui::InputText("解算路径", &(p_i->cloth_config_path))) {
          in.patch<project::cloth_config>([&](project::cloth_config& in) {
            in.vfx_cloth_sim_path = p_i->cloth_config_path;
          });
          set_modify(true);
        }

        if (imgui::InputText("导出节点", &(p_i->cloth_config.export_group))) {
          in.patch<project::cloth_config>([&](project::cloth_config& in) {
            in.export_group = p_i->cloth_config.export_group;
          });
          set_modify(true);
        }
      };
}

project_edit::~project_edit() = default;
}  // namespace doodle
