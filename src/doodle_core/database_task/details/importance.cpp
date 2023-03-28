#include "importance.h"

#include <doodle_core/database_task/details/tool.h>
#include <doodle_core/generate/core/sql_sql.h>
#include <doodle_core/logger/logger.h>
#include <doodle_core/metadata/importance.h>

#include <rttr/type.h>
#include <sqlpp11/parameter.h>
#include <sqlpp11/sqlite3/sqlite3.h>
#include <sqlpp11/sqlpp11.h>

namespace doodle::database_n {
namespace sql = doodle_database;

void sql_com<doodle::importance>::insert(conn_ptr& in_ptr, const entt::observer& in_observer) {
  namespace uuids = boost::uuids;
  auto& l_conn    = *in_ptr;
  auto l_handles  = in_observer | ranges::views::transform([&](entt::entity in_entity) {
                     return entt::handle{*reg_, in_entity};
                   }) |
                   ranges::to_vector;
  sql::Importance l_tabl{};
  auto l_pre = l_conn.prepare(sqlpp::insert_into(l_tabl).set(        
      l_tabl.entityId  = sqlpp::parameter(l_tabl.entityId),
      l_tabl.cutoffP       = sqlpp::parameter(l_tabl.cutoffP)
  ));

  for (auto& l_h : l_handles) {
    auto&  l_importance     = l_h.get<importance>();
    l_pre.params.cutoffP    = l_importance.cutoff_p;
    l_pre.params.entityId = boost::numeric_cast<std::int64_t>(l_h.get<database>().get_id());
    
    auto l_r                     = l_conn(l_pre);
    DOODLE_LOG_INFO("插入数据库id {} -> 实体 {} 组件 {} ", l_r, l_h.entity(),rttr::type::get<importance>().get_name());
  }
}

void sql_com<doodle::importance>::update(conn_ptr& in_ptr, const entt::observer& in_observer) {
  namespace uuids = boost::uuids;
  auto& l_conn    = *in_ptr;
  auto l_handles  = in_observer | ranges::views::transform([&](entt::entity in_entity) {
                     return entt::handle{*reg_, in_entity};
                   }) |
                   ranges::to_vector;

  sql::Importance l_tabl{};

  auto l_pre = l_conn.prepare(sqlpp::update(l_tabl)
                                  .set(
                                      l_tabl.cutoffP        = sqlpp::parameter(l_tabl.cutoffP)
                                  )
                                  .where(l_tabl.entityId == sqlpp::parameter(l_tabl.entityId)));

  for (auto& l_h : l_handles) {
    auto& l_importance      = l_h.get<importance>();
    l_pre.params.cutoffP      = l_importance.cutoff_p;
    l_pre.params.entityId = boost::numeric_cast<std::int64_t>(l_h.get<database>().get_id());

    auto l_r                     = l_conn(l_pre);
    DOODLE_LOG_INFO("更新数据库id {} -> 实体 {} 组件 {} ", l_r, l_h.entity(), rttr::type::get<importance>().get_name());
  }
}

void sql_com<doodle::importance>::select(conn_ptr& in_ptr, const std::map<std::int64_t, entt::entity>& in_handle) {
  namespace uuids = boost::uuids;
  auto& l_conn    = *in_ptr;

  {
    sql::Importance l_tabl{};
    std::vector<importance> l_works{};
    std::vector<entt::entity> l_entts{};

    /// 选择大小并进行调整内存
    for (auto&& raw :
         l_conn(sqlpp::select(sqlpp::count(l_tabl.entityId)).from(l_tabl).where(l_tabl.entityId.is_not_null()))) {
      l_works.reserve(raw.count.value());
      l_entts.reserve(raw.count.value());
      break;
    }

    for (auto& row : l_conn(sqlpp::select(l_tabl.entityId, l_tabl.cutoffP)
                                .from(l_tabl)
                                .where(l_tabl.entityId.is_null()))) {
      importance l_u{};
      l_u.cutoff_p = row.cutoffP.value();
      auto l_id     = row.entityId.value();

      if (in_handle.find(l_id) != in_handle.end()) {
        l_works.emplace_back(std::move(l_u));
        l_entts.emplace_back(in_handle.at(l_id));
        DOODLE_LOG_INFO("选择数据库id {} 插入实体 {}", l_id, in_handle.at(l_id));
      } else {
        DOODLE_LOG_INFO("选择数据库id {} 未找到实体", l_id);
      }
    }
    reg_->insert(l_entts.begin(), l_entts.end(), l_works.begin());
  }
}

void sql_com<doodle::importance>::destroy(conn_ptr& in_ptr, const std::vector<std::int64_t>& in_handle) {
  detail::sql_com_destroy<sql::Importance>(in_ptr, in_handle);
}

}  // namespace doodle::database_n
