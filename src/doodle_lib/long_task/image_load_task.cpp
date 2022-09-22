//
// Created by TD on 2022/2/25.
//

#include "image_load_task.h"

#include <doodle_core/metadata/image_icon.h>
#include <doodle_core/thread_pool/thread_pool.h>
#include <doodle_core/metadata/project.h>

#include <core/image_loader.h>
namespace doodle {
class image_load_task::impl {
 public:
  entt::handle handle_;
  image_icon image_;
};
image_load_task::image_load_task()
    : p_i(std::make_unique<impl>()) {
}

void image_load_task::read_image(const entt::handle& in_handle) {
  boost::ignore_unused(p_i);
  auto& image_ = in_handle.get<image_icon>();
  DOODLE_LOG_INFO("准备加载图片 {}", image_.path);
  if (!image_.image) {
    auto l_root = image_.image_root(in_handle);
    image_loader{}.load(image_, l_root);
    DOODLE_LOG_INFO("加载图片 {} 完成", l_root);
  }
}
image_load_task::~image_load_task() = default;
}  // namespace doodle
