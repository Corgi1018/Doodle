//
// Created by TD on 2022/4/8.
//

#include "base_window.h"
#include <doodle_core/core/core_set.h>
#include <doodle_core/core/init_register.h>
namespace doodle::gui {

void to_json(nlohmann::json &j, const base_window &p) {
  j["show"] = p.show_;
}
void from_json(const nlohmann::json &j, base_window &p) {
  if (j.count("show"))
    j["show"].get_to(p.show_);
}

void base_window::failed() {}

base_window *base_window::find_window_by_title(const std::string &in_title) {
  auto &l_list = g_reg()->ctx().emplace<base_window::list>();
  auto it      = ranges::find_if(
           l_list,
           [&](const base_window *in_window) -> bool {
        return in_window->title() == in_title;
      });
  if (it != l_list.end())
    return *it;
  else
    return nullptr;
}
bool base_window::is_show() const {
  return show_;
}
void base_window::show(bool in_show) {
  show_ = in_show;
}
void base_window::read_setting() {
  get_setting().get_to(*this);
}
void base_window::save_setting() const {
  get_setting() = *this;
}
void base_window::aborted() {}
nlohmann::json &base_window::get_setting() const {
  return (*core_set::getSet().json_data)[title()];
}
const ImVec2 &base_window::size() const {
  return size_;
}
void base_window::size(const ImVec2 &in_size) {
  size_ = in_size;
}

void window_panel::init() {
  read_setting();
}
void window_panel::succeeded() {
  save_setting();
}
void window_panel::aborted() {
  save_setting();
}
const std::string &window_panel::title() const {
  return title_name_;
}
void window_panel::update(const chrono::system_clock::duration &in_duration, void *in_data) {
  for (auto &&i : begin_fun) {
    i();
  }
  begin_fun.clear();

  this->render();
  //  dear::Begin{title().c_str(), &show_} &&
  //      [&]() {
  //      };
}

modal_window::modal_window() {
  show_ = true;
  begin_fun.emplace_back([this]() {
    ImGui::OpenPopup(title().data());
    ImGui::SetNextWindowSize({640, 360});
    close.connect([]() {
      ImGui::CloseCurrentPopup();
    });
  });
}
void modal_window::update(const chrono::system_clock::duration &in_dalta, void *in_data) {
  for (auto &&i : begin_fun) {
    i();
  }
  begin_fun.clear();

  dear::PopupModal{title().data(), &show_, ImGuiWindowFlags_NoSavedSettings} &&
      [&]() {
        render();
      };
}

windows_proc::~windows_proc() = default;
}  // namespace doodle::gui
