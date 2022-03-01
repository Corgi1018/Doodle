﻿//
// Created by TD on 2021/5/7.
//

#include <doodle_lib/metadata/assets_file.h>
#include <doodle_lib/metadata/comment.h>

#include <google/protobuf/util/time_util.h>
#include <metadata/time_point_wrap.h>
#include <pin_yin/convert.h>

namespace doodle {

assets_file::assets_file() = default;

assets_file::assets_file(FSys::path in_path)
    : assets_file(in_path, in_path.stem().generic_string(), 0) {
}

assets_file::assets_file(FSys::path in_path,
                         std::string in_name,
                         std::uint64_t in_version)
    : path(),
      p_name(std::move(in_name)),
      p_version(in_version),
      p_user(core_set::getSet().get_user()),
      p_department(core_set::getSet().get_department_enum()),
      p_ShowName(in_path.stem().generic_string()) {
  if (auto l_prj = g_reg()->try_ctx<project>(); l_prj)
    path = in_path.lexically_relative(l_prj->p_path);
}

std::string assets_file::str() const {
  return p_name;
}
std::string assets_file::show_str() const {
  return p_ShowName;
}

bool assets_file::operator<(const assets_file& in_rhs) const {
  // return std::tie(p_version, p_time->getUTCTime()) < std::tie(p_version, p_time->getUTCTime());
  return std::tie(p_name,p_version) < std::tie(in_rhs.p_name,in_rhs.p_version);
//  return std::tie(p_name,p_version) < std::tie(p_name,in_rhs.p_version);
  //  return std::tie(static_cast<const doodle::metadata&>(*this), p_name, p_ShowName) < std::tie(static_cast<const doodle::metadata&>(in_rhs), in_rhs.p_name, in_rhs.p_ShowName);
}
bool assets_file::operator>(const assets_file& in_rhs) const {
  return in_rhs < *this;
}
bool assets_file::operator<=(const assets_file& in_rhs) const {
  return !(in_rhs < *this);
}
bool assets_file::operator>=(const assets_file& in_rhs) const {
  return !(*this < in_rhs);
}

const std::string& assets_file::get_user() const {
  return p_user;
}
void assets_file::set_user(const std::string& in_user) {
  p_user = in_user;
}

const std::uint64_t& assets_file::get_version() const noexcept {
  return p_version;
}

std::string assets_file::get_version_str() const {
  return fmt::format("v{:04d}", p_version);
}

void assets_file::set_version(const std::uint64_t& in_Version) noexcept {
  p_version = in_Version;
}

department assets_file::get_department() const {
  return p_department;
}
void assets_file::set_department(department in_department) {
  p_department = in_department;
}

}  // namespace doodle
