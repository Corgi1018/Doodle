//
// Created by TD on 2022/1/14.
//

#include "main_menu_bar.h"
#include <lib_warp/imgui_warp.h>
#include <doodle_lib/doodle_app.h>
#include <doodle_lib/core/core_set.h>
#include <doodle_lib/client/client.h>
#include <doodle_lib/long_task/process_pool.h>
#include <doodle_lib/core/open_file_dialog.h>
#include <toolkit/toolkit.h>
#include <gui/action/command_tool.h>
#include <gui/action/command_video.h>
#include <gui/action/command_meta.h>
#include <gui/widgets/tool_box_widget.h>
namespace doodle {
class main_menu_bar::impl {
 public:
  bool p_debug_show{false};
  bool p_style_show{false};
  bool p_about_show{false};
};

main_menu_bar::main_menu_bar()
    : p_i(std::make_unique<impl>()) {
}

main_menu_bar::~main_menu_bar() = default;

void main_menu_bar::menu_file() {
  if (dear::MenuItem("新项目"s)) {
    g_main_loop().attach<file_dialog>(
        [](const FSys::path &in_path) {
          core::client{}.add_project(in_path);
          g_reg()->set<project>(in_path, "none");
          core_set::getSet().add_recent_project(in_path);
        },
        "选择目录"s);
  }
  if (dear::MenuItem("打开项目"s)) {
    g_main_loop().attach<file_dialog>(
        [](const FSys::path &in_path) {
          g_reg()->set<project>(in_path, "temp_project");
          core::client{}.open_project(in_path);
          core_set::getSet().add_recent_project(in_path);
        },
        "选择目录"s);
  }
  dear::Menu{"最近的项目"} && []() {
    auto &k_list = core_set::getSet().project_root;
    for (int l_i = 0; l_i < k_list.size(); ++l_i) {
      auto &l_p = k_list[l_i];
      if (!l_p.empty())
        if (dear::MenuItem(fmt::format("{0}##{1}", l_p.generic_string(), l_i))) {
          g_reg()->set<project>(l_p, "temp_project");
          core::client{}.open_project(l_p);
        }
    }
  };

  ImGui::Separator();
  dear::MenuItem("调试"s, &p_i->p_debug_show);
  dear::MenuItem("样式设置"s, &p_i->p_style_show);
  dear::MenuItem("关于"s, &p_i->p_about_show);
  ImGui::Separator();
  if (dear::MenuItem(u8"退出")) {
    doodle_app::Get()->p_done = true;
  }
}

void main_menu_bar::menu_windows() {
}
void main_menu_bar::menu_edit() {
  if (dear::MenuItem(u8"maya 工具"))
    g_reg()->ctx<tool_box_widget>().set_tool_widget(new_object<comm_maya_tool>());
  if (dear::MenuItem(u8"创建视频"))
    g_reg()->ctx<tool_box_widget>().set_tool_widget(new_object<comm_create_video>());
  if (dear::MenuItem(u8"ue工具"))
    g_reg()->ctx<tool_box_widget>().set_tool_widget(new_object<comm_import_ue_files>());
}
void main_menu_bar::menu_tool() {
  if (dear::MenuItem("安装maya插件"))
    toolkit::installMayaPath();
  if (dear::MenuItem("安装ue4插件"))
    toolkit::installUePath(core_set::getSet().get_ue4_setting().get_path() / "Engine");
  if (dear::MenuItem("安装ue4项目插件")) {
    g_main_loop().attach<file_dialog>(
        [](const FSys::path &in_path) {
          toolkit::installUePath(in_path);
        },
        "select_ue_project",
        string_list{".uproject"});
  }
  if (dear::MenuItem("删除ue4缓存"))
    toolkit::deleteUeCache();
  if (dear::MenuItem("修改ue4缓存位置"))
    toolkit::modifyUeCachePath();
}

void main_menu_bar::init() {
  g_reg()->set<main_menu_bar &>(*this);
}
void main_menu_bar::succeeded() {
}
void main_menu_bar::failed() {
}
void main_menu_bar::aborted() {
}
void main_menu_bar::update(
    std::chrono::duration<std::chrono::system_clock::rep, std::chrono::system_clock::period>,
    void *data) {
  dear::MainMenuBar{} && [this]() {
    dear::Menu{"文件"} && [this]() { this->menu_file(); };
    dear::Menu{"窗口"} && [this]() { this->menu_windows(); };
    dear::Menu{"编辑"} && [this]() { this->menu_edit(); };
    dear::Menu{"工具"} && [this]() { this->menu_tool(); };
#ifndef NDEBUG
    ImGui::Text("%.3f ms/%.1f FPS", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
#endif
  };
}

}  // namespace doodle
