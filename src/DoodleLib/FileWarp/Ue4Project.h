
#pragma once

#include <DoodleLib/DoodleLib_fwd.h>
#include <DoodleLib/Logger/Logger.h>
#include <DoodleLib/libWarp/json_warp.h>
#include <DoodleLib/threadPool/long_term.h>

#include <cereal/types/base_class.hpp>
#include <cereal/types/common.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>

namespace doodle {

class DOODLELIB_API Ue4Project {
  class DOODLELIB_API Ue4ProjectFilePulgins {
   public:
    std::string Name;
    bool Enabled;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Ue4ProjectFilePulgins, Name, Enabled)
  };
  class DOODLELIB_API Ue4ProjectFile {
   public:
    int32_t FileVersion{};
    std::string EngineAssociation;
    std::string Category;
    std::string Description;
    std::vector<Ue4ProjectFilePulgins> Plugins;

    // NLOHMANN_DEFINE_TYPE_INTRUSIVE(Ue4ProjectFile, FileVersion,
    //                                EngineAssociation,
    //                                Category,
    //                                Description,
    //                                Plugins);
    friend void to_json(nlohmann::json& nlohmann_json_j, const Ue4ProjectFile& nlohmann_json_t) {
      nlohmann_json_j["FileVersion"]       = nlohmann_json_t.FileVersion;
      nlohmann_json_j["EngineAssociation"] = nlohmann_json_t.EngineAssociation;
      nlohmann_json_j["Category"]          = nlohmann_json_t.Category;
      nlohmann_json_j["Description"]       = nlohmann_json_t.Description;
      nlohmann_json_j["Plugins"]           = nlohmann_json_t.Plugins;
    };
    friend void from_json(const nlohmann::json& nlohmann_json_j, Ue4ProjectFile& nlohmann_json_t) {
      nlohmann_json_j.at("FileVersion").get_to(nlohmann_json_t.FileVersion);
      nlohmann_json_j.at("EngineAssociation").get_to(nlohmann_json_t.EngineAssociation);
      nlohmann_json_j.at("Category").get_to(nlohmann_json_t.Category);
      nlohmann_json_j.at("Description").get_to(nlohmann_json_t.Description);
      try {
        nlohmann_json_j.at("Plugins").get_to(nlohmann_json_t.Plugins);
      } catch (const nlohmann::json::exception& error) {
        DOODLE_LOG_INFO(error.what());
      }
    };
  };

  enum class import_type {
    None,
    Abc,
    Fbx
  };
  class DOODLELIB_API import_settting {
   public:
    import_settting()  = default;
    ~import_settting() = default;

    FSys::path import_file_path;
    FSys::path import_file_save_dir;
    FSys::path fbx_skeleton_dir;
    FSys::path fbx_skeleton_file_name;
    import_type import_type;
    std::uint64_t start_frame;
    std::uint64_t end_frame;

    friend void to_json(nlohmann::json& nlohmann_json_j, const import_settting& nlohmann_json_t) {
      nlohmann_json_j["import_file_path"]       = nlohmann_json_t.import_file_path;
      nlohmann_json_j["import_file_save_dir"]   = nlohmann_json_t.import_file_save_dir;
      nlohmann_json_j["fbx_skeleton_dir"]       = nlohmann_json_t.fbx_skeleton_dir;
      nlohmann_json_j["fbx_skeleton_file_name"] = nlohmann_json_t.fbx_skeleton_file_name;
      nlohmann_json_j["import_type"]            = nlohmann_json_t.import_type;
      nlohmann_json_j["start_frame"]            = nlohmann_json_t.start_frame;
      nlohmann_json_j["end_frame"]              = nlohmann_json_t.end_frame;
    };
    friend void from_json(const nlohmann::json& nlohmann_json_j, import_settting& nlohmann_json_t) {
      nlohmann_json_j.at("import_file_path").get_to(nlohmann_json_t.import_file_path);
      nlohmann_json_j.at("import_file_save_dir").get_to(nlohmann_json_t.import_file_save_dir);
      nlohmann_json_j.at("fbx_skeleton_dir").get_to(nlohmann_json_t.fbx_skeleton_dir);
      nlohmann_json_j.at("fbx_skeleton_file_name").get_to(nlohmann_json_t.fbx_skeleton_file_name);
      nlohmann_json_j.at("import_type").get_to(nlohmann_json_t.import_type);
      nlohmann_json_j.at("start_frame").get_to(nlohmann_json_t.start_frame);
      nlohmann_json_j.at("end_frame").get_to(nlohmann_json_t.end_frame);
    };

    // NLOHMANN_DEFINE_TYPE_INTRUSIVE(
    //     import_settting,
    //     import_file_path,
    //     import_file_save_dir,
    //     fbx_skeleton_dir,
    //     fbx_skeleton_file_name,
    //     import_type,
    //     start_frame,
    //     end_frame);
  };

  FSys::path p_ue_path;
  FSys::path p_ue_Project_path;
  long_term_ptr p_term;
  std::vector<std::future<void>> p_futurn_list;

  void addUe4ProjectPlugins(const std::vector<std::string>& in_strs) const;

  void run_cmd_scipt(const std::string& run_com) const;
  void runPythonScript(const std::string& python_str) const;
  void runPythonScript(const FSys::path& python_file) const;

 public:
  const static std::string Content;
  const static std::string ContentShot;
  const static std::string UE4PATH;
  const static std::string Character;
  const static std::string Prop;

  /**
   * @brief 创建ue类， 必须有项目文件指示
   * 
   * @param project_path 项目文件路径
   */
  Ue4Project(FSys::path project_path);

  ~Ue4Project();
  /**
   * @brief 同步创建镜头和集数文件夹
   * 
   * @param inShotList 镜头列表
   */
  void createShotFolder(const std::vector<ShotPtr>& inShotList);
  /**
   * @brief 异步创建镜头和集数文件夹
   * 
   * @param inShotList 镜头列表
   * @return long_term_ptr 进度指示
   */
  long_term_ptr create_shot_folder_asyn(const std::vector<ShotPtr>& inShotList);
  /**
   * @brief 将文件导入到ue
   * 
   * @param in_paths 需要导入的文件
   * @return long_term_ptr 时间指示
   */
  long_term_ptr import_files_asyn(const std::vector<FSys::path>& in_paths);

  /**
   * @brief ue4 项目中的文件系统路径转换为以/Game/开头的复合ue4 标准的路径
   * 
   * @param in_path 常规路径
   * @return FSys::path  ue 路径
   */
  [[nodiscard]] FSys::path convert_path_to_game(const FSys::path& in_path) const;
  /**
   * @brief 在项目中寻找fbx 对应的ue4 skeleton 包
   * 
   * @param in_path 导入的fbx文件路径
   * @return FSys::path 寻找到的ue4 已经格式化为ue格式路径
   */
  FSys::path find_ue4_skeleton(const FSys::path& in_path);

  /**
   * @brief 文件是可以通过脚本导入ue
   * 
   * @param in_path 要导入的文件路径
   * @return true 可以导入
   * @return false 不可以导入
   */
  static bool can_import_ue4(const FSys::path& in_path);
  static bool is_ue4_file(const FSys::path& in_path);

  /**
   * @brief 将路径中的集数信息和镜头信息提取出来， 并放在规范的ue4文件夹中
   * 
   * @param in_path 需要提取信息的路径
   * @return FSys::path 整理信息后返回的路径
   * @warning 返回的路径都是以 /Game/开头的ue4路径
   */
  static FSys::path analysis_path_to_gamepath(const FSys::path& in_path);
};
}  // namespace doodle
