#include <doodle_lib/Exception/exception.h>
#include <doodle_lib/gui/factory/attribute_factory_interface.h>
#include <doodle_lib/metadata/episodes.h>
#include <doodle_lib/metadata/metadata_factory.h>

BOOST_CLASS_EXPORT_IMPLEMENT(doodle::episodes)
namespace doodle {

episodes::episodes()
    :      p_episodes(-1) {
}

episodes::episodes( int64_t in_episodes)
    :       p_episodes(in_episodes) {
  if (p_episodes < 0)
    throw doodle_error("集数无法为负");
}

// Episodes::~Episodes() {
//   if (p_metadata_flctory_ptr_)
//     updata_db(p_metadata_flctory_ptr_);
// }

const int64_t& episodes::get_episodes() const noexcept {
  return p_episodes;
}

void episodes::set_episodes(const int64_t& Episodes_) {
  if (Episodes_ <= 0)
    throw doodle_error("集数无法为负");
  p_episodes = Episodes_;
}

std::string episodes::str() const {
  return fmt::format("ep{:04d}", p_episodes);
}

bool episodes::operator<(const episodes& in_rhs) const {
  //  return std::tie(static_cast<const doodle::metadata&>(*this), p_episodes) < std::tie(static_cast<const doodle::metadata&>(in_rhs), in_rhs.p_episodes);
  return std::tie(p_episodes) < std::tie(in_rhs.p_episodes);
}
bool episodes::operator>(const episodes& in_rhs) const {
  return in_rhs < *this;
}
bool episodes::operator<=(const episodes& in_rhs) const {
  return !(in_rhs < *this);
}
bool episodes::operator>=(const episodes& in_rhs) const {
  return !(*this < in_rhs);
}

bool episodes::analysis(const std::string& in_path) {
  static std::regex reg{R"(ep_?(\d+))", std::regex_constants::icase};
  std::smatch k_match{};
  const auto& k_r = std::regex_search(in_path, k_match, reg);
  if (k_r) {
    p_episodes = std::stoi(k_match[1].str());
  }
  return k_r;
}

episodes episodes::analysis_static(const std::string& in_path) {
  auto k_eps = episodes{};
  if (k_eps.analysis(in_path))
    return k_eps;
  else
    return {};
}

void episodes::attribute_widget(const attribute_factory_ptr& in_factoryPtr) {
  in_factoryPtr->show_attribute(this);
}

}  // namespace doodle

