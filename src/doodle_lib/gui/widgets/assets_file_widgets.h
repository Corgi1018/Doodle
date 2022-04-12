//
// Created by TD on 2021/9/16.
//

#pragma once
#include <doodle_lib/doodle_lib_fwd.h>
#include <doodle_lib/gui/gui_ref/base_window.h>

#include <boost/signals2.hpp>
namespace doodle {

class assets_file_widgets;

/**
 * @brief 文件列表显示
 * 文件列表显示了在资产项目下所有的文件文件
 * 在显示的文件中，路径并不是所有的， 而是最主要的一条
 * @note 每次上传文件都会递增版本号， 如果需要新的条目请创建新条目
 *
 */
class DOODLELIB_API assets_file_widgets
    : public gui::window_panel {
  class impl;
  std::unique_ptr<impl> p_i;

  void render_context_menu(const entt::handle& in_);
  void render_by_icon();
  void render_by_icon(std::size_t in_index);
  void render_by_info();
  void render_by_info(std::size_t in_index);
  void switch_rander();
  void generate_lists(const std::vector<entt::handle>& in_list);

  void set_select(std::size_t in_size);
  void open_drag(std::size_t in_size);

 public:
  assets_file_widgets();
  ~assets_file_widgets() override;

  constexpr static std::string_view name{gui::config::menu_w::assets_file};

  void refresh(const std::vector<entt::handle>& in_list);
  void init() override;
  void failed() override;
  void render() override;
};
namespace assets_file_widgets_ns {
constexpr auto init = []() {
  entt::meta<assets_file_widgets>()
      .type()
      .prop("name"_hs, std::string{assets_file_widgets::name})
      .base<gui::window_panel>();
};
class init_class
    : public init_register::registrar_lambda<init, 3> {};

}  // namespace assets_file_widgets_ns
}  // namespace doodle
