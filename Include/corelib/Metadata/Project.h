#pragma once
#include <corelib/core_global.h>

#include <cereal/cereal.hpp>
#include <cereal/types/common.hpp>
#include <cereal/types/string.hpp>
namespace doodle {
class CORE_API Project {
  std::string p_name;
  FSys::path p_path;

 public:
  Project();
  Project(FSys::path in_path, std::string in_name);

  const std::string& Name() const noexcept;
  void setName(const std::string& Name) noexcept;

  const FSys::path& Path() const noexcept;
  void setPath(const FSys::path& Path);

  const std::string str() const;
  const std::string ShortStr() const;

 private:
  friend class cereal::access;

  template <class Archive>
  void save(Archive& ar, std::uint32_t const version) const;

  template <class Archive>
  void load(Archive& ar, std::uint32_t const version);
};

template <class Archive>
void Project::save(Archive& ar, std::uint32_t const version) const {
  ar(
      cereal::make_nvp("name", p_name),
      cereal::make_nvp("path", p_path));
}

template <class Archive>
void Project::load(Archive& ar, std::uint32_t const version) {
  ar(
      p_name,
      p_path);
}

}  // namespace doodle
CEREAL_CLASS_VERSION(doodle::Project, 1);