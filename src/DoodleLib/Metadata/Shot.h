#pragma once

#include <DoodleLib/DoodleLib_fwd.h>
#include <DoodleLib/Metadata/Metadata.h>

#include <magic_enum.hpp>
namespace doodle {
class DOODLELIB_API Shot : public Metadata {
 public:
  enum class ShotAbEnum;

 private:
  int64_t p_shot;
  std::string p_shot_ab;

 public:
  Shot();
  Shot(std::weak_ptr<Metadata> in_metadata,
       decltype(p_shot) in_shot,
       decltype(p_shot_ab) in_shot_ab = {});

  // clang-format off
  enum class ShotAbEnum { A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z };
  // clang-format on

  [[nodiscard]] const std::int64_t &getShot() const noexcept;
  void setShot(const std::int64_t &in_shot);

  [[nodiscard]] const std::string &getShotAb() const noexcept;
  void setShotAb(const std::string &ShotAb) noexcept;
  inline void setShotAb(const ShotAbEnum &ShotAb) {
    setShotAb(std::string{magic_enum::enum_name(ShotAb)});
  };

  [[nodiscard]] EpisodesPtr getEpisodesPtr() const;
  void setEpisodesPtr(const EpisodesPtr &Episodes_) noexcept;

  [[nodiscard]] std::string str() const override;
  virtual void create_menu(const attribute_factory_ptr &in_factoryPtr) override;
  bool operator<(const Shot &rhs) const;
  bool operator>(const Shot &rhs) const;
  bool operator<=(const Shot &rhs) const;
  bool operator>=(const Shot &rhs) const;

  inline bool analysis(const FSys::path &in_path) {
    return analysis(in_path.generic_string());
  };
  bool analysis(const std::string &in_path);

  static ShotPtr analysis_static(const std::string &in_path);
  inline static ShotPtr analysis_static(const FSys::path &in_path) {
    return analysis_static(in_path.generic_string());
  };

 private:
  friend class boost::serialization::access;
  template <class Archive>
  void serialize(Archive &ar, std::uint32_t const version);
};
template <class Archive>
void Shot::serialize(Archive &ar, const std::uint32_t version) {
  if (version == 1)
    ar &boost::serialization::make_nvp("Metadata", boost::serialization::base_object<Metadata>(*this)) &
        p_shot &
            p_shot_ab;
}
}  // namespace doodle

namespace cereal {
template <class Archive>
std::string save_minimal(Archive const &, doodle::Shot::ShotAbEnum const &shotab) {
  return std::string{magic_enum::enum_name(shotab)};
}
template <class Archive>
void load_minimal(Archive const &, doodle::Shot::ShotAbEnum &shotab, std::string const &value) {
  shotab = magic_enum::enum_cast<doodle::Shot::ShotAbEnum>(value).value_or(doodle::Shot::ShotAbEnum::A);
};
}  // namespace cereal

BOOST_CLASS_VERSION(doodle::Shot, 1)
BOOST_CLASS_EXPORT_KEY(doodle::Shot)
