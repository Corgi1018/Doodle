#include <pinyinlib/convert.h>
#include <boost/locale.hpp>
#include <loggerlib/logger.h>
#include <doodlePinyin.h>

#include <stdexcept>
#include <thread>
#include <regex>

PINYIN_NAMESPACE_S
static std::vector<std::string> pinyin_list{};
convert::convert() {
  const auto &resource = bin2cpp::getPinyinDataFile();
  resource.getBuffer();
  std::string ZhongWenToPinYin{resource.getBuffer(), resource.getSize()};
  std::regex regex{R"(\s)"};
  auto iter = std::sregex_token_iterator(
      ZhongWenToPinYin.begin(), ZhongWenToPinYin.end(), regex, -1);
  while (iter != std::sregex_token_iterator{}) {
    pinyin_list.push_back(*iter);
    ++iter;
  }
}

convert::~convert() {
}

std::string convert::toEn(const std::string &conStr) {
  auto datas = boost::locale::conv::to_utf<wchar_t>(conStr, "UTF-8");
  std::string result{};
  for (auto data : datas) {
    if (data >= 0x4e00 && data <= 0x9fa5) {
      result.append(pinyin_list[data - 0x4e00]);
    } else {
      result.append(boost::locale::conv::utf_to_utf<char>(std::wstring{data}));
    }
  }
  DOODLE_LOG_INFO(conStr << " to " << result);
  return result;
}

convert &convert::Get() noexcept {
  static convert instance;
  return instance;
}

DNAMESPACE_E
