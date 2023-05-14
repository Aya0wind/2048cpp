
#pragma once
#include <sqlite_orm/sqlite_orm.h>

#include <memory>
#include <string>

struct HighScore {
    int id;
    std::string name;
    int score;
    int level;
};

namespace tables {
using sqlite_orm::columns;
using sqlite_orm::is_equal;
using sqlite_orm::make_column;
using sqlite_orm::make_storage;
using sqlite_orm::make_table;
using sqlite_orm::primary_key;
using sqlite_orm::unique;
using sqlite_orm::where;
inline auto high_score_table = make_table(
    "HIGHSCORE", make_column("ID", &HighScore::id, primary_key()), make_column("NAME", &HighScore::name, unique()),
    make_column("SCORE", &HighScore::score), make_column("LEVEL", &HighScore::level));
}  // namespace tables

template <class table_type>
using storage_type = sqlite_orm::internal::storage_t<table_type>;
