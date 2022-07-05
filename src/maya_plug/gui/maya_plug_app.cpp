//
// Created by TD on 2021/10/14.
//

#include "maya_plug_app.h"

#include <doodle_lib/gui/main_status_bar.h>
#include <doodle_lib/gui/main_menu_bar.h>
#include <doodle_core/thread_pool/process_pool.h>
#include <doodle_core/core/core_set.h>
#include <maya_plug/gui/maya_layout.h>
#include <doodle_lib/gui/main_proc_handle.h>
namespace doodle::maya_plug {

void maya_plug_app::load_windows() {
  g_main_loop().attach<main_menu_bar>();
  g_main_loop().attach<main_status_bar>();
  g_main_loop().attach<maya_layout>();
}
void maya_plug_app::close_windows() {
  ::ShowWindow(p_hwnd, SW_HIDE);
}

maya_plug_app::maya_plug_app(const win::wnd_instance& in_instance,
                             const win::wnd_handle& in_parent)
    : app(in_instance,
          in_parent) {
  self = this;
}

}  // namespace doodle::maya_plug
