﻿#pragma once

#include <DoodleConfig.h>
#include <doodle_lib/Logger/logger.h>
#include <doodle_lib/doodle_lib_pch.h>
#include <doodle_lib/doodle_macro.h>
#include <doodle_lib/lib_warp/boost_serialization_warp.h>
#include <doodle_lib/lib_warp/cmrcWarp.h>
#include <doodle_lib/lib_warp/sqlppWarp.h>
#include <doodle_lib/lib_warp/std_warp.h>
#include <doodle_lib_export.h>

// namespace fmt {
// namespace FSys = std::filesystem;
// template <class Char>
// struct formatter<FSys::path, Char> : formatter<basic_string_view<Char>, Char> {
//   template <typename FormatContext>
//   auto format(const FSys::path &in_path, FormatContext &ctx) {
//     if constexpr (std::is_same_v<Char, char>)
//       return formatter<basic_string_view<Char>, Char>::format(in_path.generic_string(), ctx);
//     else if constexpr (std::is_same_v<Char, wchar_t>)
//       return formatter<basic_string_view<Char>, Char>::format(in_path.generic_wstring(), ctx);
//   }
// };
// }  // namespace fmt

//开始我们的名称空间
namespace doodle {
namespace details {
/**
 * @brief 不可复制类
 *
 */
class no_copy {
 public:
  no_copy()                = default;
  no_copy(const no_copy &) = delete;
  no_copy &operator=(const no_copy &) = delete;
};
/**
 * @brief 判断是否是智能指针
 *
 * @tparam T 需要判断的类型
 * @tparam Enable 辅助类
 */
template <typename T, typename Enable = void>
struct is_smart_pointer {
  /**
   * @brief 不是智能指针
   *
   */
  static const auto value = std::false_type::value;
};
/**
 * @brief 判断是否是智能指针
 *
 * @tparam T 需要判断的类型
 * @tparam Enable 辅助类
 */
template <typename T>
struct is_smart_pointer<T,
                        typename std::enable_if<
                            std::is_same<
                                typename std::remove_cv<T>::type,
                                std::shared_ptr<typename T::element_type>>::value>::type> {
  /**
   * @brief 是智能指针
   *
   */
  static const auto value = std::true_type::value;
};
/**
 * @brief 判断是否是智能指针
 *
 * @tparam T 需要判断的类型
 * @tparam Enable 辅助类
 */
template <typename T>
struct is_smart_pointer<T,
                        typename std::enable_if<
                            std::is_same<
                                typename std::remove_cv<T>::type,
                                std::unique_ptr<typename T::element_type>>::value>::type> {
  /**
   * @brief 是智能指针
   *
   */
  static const auto value = std::true_type::value;
};
/**
 * @brief 判断是否是智能指针
 *
 * @tparam T 需要判断的类型
 * @tparam Enable 辅助类
 */
template <typename T>
struct is_smart_pointer<T,
                        typename std::enable_if<
                            std::is_same<
                                typename std::remove_cv<T>::type,
                                std::weak_ptr<typename T::element_type>>::value>::type> {
  /**
   * @brief 是智能指针
   *
   */
  static const auto value = std::true_type::value;
};

/**
 * 这个是判断指针或者共享指针是什么类的帮助函数
 * @tparam T 是否是这个类
 * @tparam RT 传入的类型
 * @param in_rt 输入的
 * @return 是否是可以转换的
 */
template <class T, class RT>
bool is_class(const RT &in_rt) {
  if constexpr (is_smart_pointer<RT>::value) {
    if (!in_rt)
      return false;
    const auto &k_item = *in_rt;
    return typeid(T) == typeid(k_item);
  } else {
    return typeid(T) == typeid(in_rt);
  }
}

template <class less_type>
bool less(const less_type &in_r, const less_type &in_l) {
  return *in_r < in_l;
};
}  // namespace details

namespace chrono {
namespace literals {
using namespace std::chrono_literals;
using namespace date::literals;

}  // namespace literals

using namespace std::chrono;
using namespace date;

using hours_double   = duration<std::double_t, std::ratio<3600>>;
using days_double    = duration<std::double_t, std::ratio<28800>>;
using sys_time_pos   = time_point<system_clock>;
using local_time_pos = time_point<local_t, seconds>;

/**
 * @brief 判断是否是休息日 周六日
 *
 * @todo 这里我们暂时使用周六和周日作为判断, 但是实际上还有各种假期和其他情况要计入
 */
bool is_rest_day(const sys_days &in_days);
template <class dur>
std::time_t to_time_t(const time_point<local_t, dur> &in_timePoint) {
  return duration_cast<seconds>(in_timePoint.time_since_epoch()).count();
};
// template <class Clock>
// bool is_morning_works(const std::chrono::time_point<Clock, typename Clock::duration>& in_time) {
// }
}  // namespace chrono

template <typename IntType = std::int32_t>
std::vector<IntType> range(IntType start, IntType stop, IntType step = 1) {
  std::vector<IntType> x{};
  boost::push_back(x, boost::irange(start, stop, step));
  return x;
};

namespace FSys {
// namespace details{
// using namespace std::filesystem;
//
// }
using namespace std::filesystem;
using fstream  = std::fstream;
using istream  = std::istream;
using ifstream = std::ifstream;
using ofstream = std::ofstream;
using ostream  = std::ostream;

// class path : public ::std::filesystem::path{
//  public:
//
// };

// using std::filesystem::filesystem_error;
// using std::filesystem::directory_entry;
// using std::filesystem::directory_iteratorr;
// using std::filesystem::recursive_directory_iterator;
// using std::filesystem::file_status;
// using std::filesystem::space_info;
// using std::filesystem::file_type;
// using std::filesystem::perms;
// using std::filesystem::perm_options;
// using std::filesystem::copy_options;
// using std::filesystem::directory_options;
// using std::filesystem::file_time_type;
//
// using std::filesystem::absolute;
// using std::filesystem::canonical;
// using std::filesystem::weakly_canonical;
// using std::filesystem::copy;
// using std::filesystem::copy_file;
// using std::filesystem::copy_symlink;
// using std::filesystem::create_directories;
// using std::filesystem::create_directory;
// using std::filesystem::create_hard_link;
// using std::filesystem::create_symlink;
// using std::filesystem::create_directory_symlink;
// using std::filesystem::current_path;
// using std::filesystem::exists;
// using std::filesystem::equivalent;
// using std::filesystem::file_size;
// using std::filesystem::hard_link_count;
// using std::filesystem::last_write_time;
// using std::filesystem::permissions;
// using std::filesystem::read_symlink;
// using std::filesystem::remove;
// using std::filesystem::remove_all;
// using std::filesystem::rename;
// using std::filesystem::resize_file;
// using std::filesystem::space;
// using std::filesystem::status;
// using std::filesystem::symlink_status;
// using std::filesystem::temp_directory_path;
//
// using std::filesystem::is_block_file;
// using std::filesystem::is_character_file;
// using std::filesystem::is_directory;
// using std::filesystem::is_empty;
// using std::filesystem::is_fifo;
// using std::filesystem::is_other;
// using std::filesystem::is_regular_file;
// using std::filesystem::is_socket;
// using std::filesystem::is_symlink;
// using std::filesystem::status;
DOODLELIB_API inline path make_path(const std::string &in_string) {
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t> convert;
  return path{convert.from_bytes(in_string)};
}
DOODLELIB_API std::time_t last_write_time_t(const path &in_path);
DOODLELIB_API inline chrono::sys_time_pos last_write_time_point(const path &in_path) {
  return std::chrono::system_clock::from_time_t(last_write_time_t(in_path));
}
DOODLELIB_API path add_time_stamp(const path &in_path);
DOODLELIB_API void open_explorer(const path &in_path);
DOODLELIB_API void backup_file(const path &source);
DOODLELIB_API std::string file_hash_sha224(const path &in_file);
DOODLELIB_API std::vector<path> list_files(const path &in_dir);

}  // namespace FSys

class core_set;
class project;
class episodes;
class shot;
class metadata;
class assets;
class core_sql;
class assets_file;
class metadata_factory;
class time_point_wrap;
class comment;
class assets_path;

class rpc_metadata_client;
class rpc_metadaata_server;
class ProjectManage;
class rpc_server_handle;
class rpc_file_system_client;
class rpc_file_system_server;
class doodle_lib;
class thread_pool;
class attribute_factory_interface;
class long_term;
class image_sequence;
class season;
class video_sequence;
class ue4_project;
class maya_file;
class setting_windows;
class base_widget;
class comment_vector;
class assets_path_vector;
class widget_register;
using base_widget_ptr = std::shared_ptr<base_widget>;
class command_base;
class rpc_trans_path;
class doodle_app;

class ue4_project_async;
class image_sequence_async;

using image_sequence_async_ptr   = std::shared_ptr<image_sequence_async>;

/**
 * @brief 数据库连接指针
 *
 */
using conn_ptr                   = std::unique_ptr<sqlpp::mysql::connection>;
/**
 * @brief Ue4Project智能g'x指针
 *
 */
using ue4_project_ptr            = std::shared_ptr<ue4_project>;
/**
 * @brief VideoSequence 智能共享指针
 *
 */
using video_sequence_ptr         = std::shared_ptr<video_sequence>;

/**
 * @brief std 智能共享指针
 *
 */
using string_list                = std::vector<std::string>;
/**
 * @brief string_list 智能共享指针
 *
 */
using string_matrix2             = std::vector<string_list>;
/**
 * @brief string_matrix2 智能共享指针
 *
 */
using string_matrix2_ptr         = std::shared_ptr<string_matrix2>;
/**
 * @brief string_list 智能共享指针
 *
 */
using string_list_ptr            = std::shared_ptr<string_list>;

/**
 * @brief season 智能共享指针
 *
 */
using season_ptr                 = std::shared_ptr<season>;
/**
 * @brief metadata 智能共享指针
 *
 */
using metadata_ptr               = std::shared_ptr<metadata>;
/**
 * @brief const 智能共享指针
 *
 */
using metadata_const_ptr         = std::shared_ptr<const metadata>;
/**
 * @brief RpcMetadataClient 智能共享指针
 *
 */
using rpc_metadata_client_ptr    = std::shared_ptr<rpc_metadata_client>;
/**
 * @brief RpcMetadaataServer 智能共享指针
 *
 */
using rpc_metadata_server_ptr    = std::shared_ptr<rpc_metadaata_server>;
/**
 * @brief RpcServerHandle 智能共享指针
 *
 */
using rpc_server_handle_ptr      = std::shared_ptr<rpc_server_handle>;
/**
 * @brief RpcFileSystemServer 智能共享指针
 *
 */
using rpc_file_system_server_ptr = std::shared_ptr<rpc_file_system_server>;
/**
 * @brief RpcFileSystemClient 智能共享指针
 *
 */
using rpc_file_system_client_ptr = std::shared_ptr<rpc_file_system_client>;
/**
 * @brief Project 智能共享指针
 *
 */
using project_ptr                = std::shared_ptr<project>;
/**
 * @brief Episodes 智能共享指针
 *
 */
using episodes_ptr               = std::shared_ptr<episodes>;
/**
 * @brief Shot 智能共享指针
 *
 */
using shot_ptr                   = std::shared_ptr<shot>;
/**
 * @brief Assets 智能共享指针
 *
 */
using assets_ptr                 = std::shared_ptr<assets>;
/**
 * @brief AssetsFile 智能共享指针
 *
 */
using assets_file_ptr            = std::shared_ptr<assets_file>;
/**
 * @brief CoreSql 智能共享指针
 *
 */
using core_sql_ptr               = std::shared_ptr<core_sql>;

/**
 * @brief MetadataFactory 智能共享指针
 *
 */
using metadata_factory_ptr       = std::shared_ptr<metadata_factory>;
/**
 * @brief TimeDuration 智能共享指针
 *
 */
using time_wrap_ptr              = std::shared_ptr<time_point_wrap>;
/**
 * @brief Comment 智能共享指针
 *
 */
using comment_ptr                = std::shared_ptr<comment>;
/**
 * @brief AssetsPath 智能共享指针
 *
 */
using assets_path_ptr            = std::shared_ptr<assets_path>;

/**
 * @brief doodle_lib 智能共享指针
 *
 */
using doodle_lib_ptr             = std::unique_ptr<doodle_lib>;
/**
 * @brief ThreadPool 智能共享指针
 *
 */
using thread_pool_ptr            = std::shared_ptr<thread_pool>;
/**
 * @brief attribute_factory_interface 智能共享指针
 *
 */
using attribute_factory_ptr      = std::shared_ptr<attribute_factory_interface>;
/**
 * @brief long_term 智能共享指针
 *
 */
using long_term_ptr              = std::shared_ptr<long_term>;
/**
 * @brief ImageSequence 智能共享指针
 *
 */
using image_sequence_ptr         = std::shared_ptr<image_sequence>;
/**
 * @brief MayaFile 智能共享指针
 */
class time_widget;

using maya_file_ptr           = std::shared_ptr<maya_file>;
using setting_windows_ptr     = std::shared_ptr<setting_windows>;
using ue4_project_async_ptr   = std::shared_ptr<ue4_project_async>;
using bool_ptr                = std::shared_ptr<bool>;

using string                  = std::string;
using string_ptr              = std::shared_ptr<string>;

using command_ptr             = std::shared_ptr<command_base>;
using comment_vector_ptr      = std::shared_ptr<comment_vector>;
using assets_path_vector_ptr  = std::shared_ptr<assets_path_vector>;
using time_widget_ptr         = std::shared_ptr<time_widget>;
using widget_register_ptr     = std::shared_ptr<widget_register>;

using rpc_trans_path_ptr      = std::unique_ptr<rpc_trans_path>;
using rpc_trans_path_ptr_list = std::vector<rpc_trans_path_ptr>;

namespace rpc_trans {
class down_file;
class down_dir;
class up_file;
class up_dir;
class trans_file;
class trans_files;
using trans_file_ptr = std::shared_ptr<trans_file>;
}  // namespace rpc_trans
class Doodle;
[[maybe_unused]] DOODLELIB_API doodle_lib_ptr make_doodle_lib();

namespace details {
template <class in_type>
std::pair<string, string> make_show_shr(const string &in_key, const in_type *in_ptr) {
  return std::make_pair(in_key, fmt::format("{}##{}", in_key, typeid(*in_ptr).name()));
};
}  // namespace details
template <class... Args, class in_type>
std::map<string, string> make_imgui_name(const in_type *in_ptr, Args &&...in_args) {
  return std::map<string, string>{details::make_show_shr(in_args, in_ptr)...};
};
}  // namespace doodle

namespace boost::serialization {
// class _Rep, class _Period
template <class Archive, class Clock, class Duration>
inline void serialize(Archive &ar, doodle::chrono::time_point<Clock, Duration> &t, const unsigned int file_version) {
  split_free(ar, t, file_version);
}

template <class Archive, class Clock, class Duration>
inline void save(Archive &ar, const doodle::chrono::time_point<Clock, Duration> &time, const std::uint32_t version) {
  ar &boost::serialization::make_nvp("time", time.time_since_epoch());
}
template <class Archive, class Clock, class Duration>
inline void load(Archive &ar, doodle::chrono::time_point<Clock, Duration> &time, const std::uint32_t version) {
  Duration time_since_epoch;
  ar &boost::serialization::make_nvp("time", time_since_epoch);
  time = doodle::chrono::time_point<Clock, Duration>{time_since_epoch};
}

template <class Archive, class Rep, class Period>
inline void serialize(Archive &ar, doodle::chrono::duration<Rep, Period> &t, const unsigned int file_version) {
  split_free(ar, t, file_version);
}

template <class Archive, class Rep, class Period>
inline void save(Archive &ar, const doodle::chrono::duration<Rep, Period> &dur, const std::uint32_t version) {
  auto count = dur.count();
  ar &boost::serialization::make_nvp("duration", count);
}
template <class Archive, class Rep, class Period>
inline void load(Archive &ar, doodle::chrono::duration<Rep, Period> &dur, const std::uint32_t version) {
  Rep count;
  ar &boost::serialization::make_nvp("duration", count);
  dur = doodle::chrono::duration<Rep, Period>{count};
}

}  // namespace boost::serialization
