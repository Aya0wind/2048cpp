
#pragma once
#include "Tables.hpp"
#include "user-save/Tables.hpp"

class HighScoreManager {
    using table_type = decltype(tables::high_score_table);
    storage_type<table_type> storage;

public:
    HighScoreManager(const std::string& db_path)
        : storage(sqlite_orm::make_storage(db_path, tables::high_score_table))
    {
        storage.sync_schema();
    }

    void addHighScore(const HighScore& high_score)
    {
        storage.insert(high_score);
    }

    std::vector<HighScore> getHighScores()
    {
        return storage.get_all<HighScore>();
    }

    void clearHighScores()
    {
        storage.remove_all<HighScore>();
    }

    std::unique_ptr<HighScore> getHighScore(int id)
    {
        using sqlite_orm::columns;
        using sqlite_orm::is_equal;
        using sqlite_orm::where;
        return storage.get_pointer<HighScore>(id);
    }

    HighScore getHighScore(const std::string& name)
    {
        using sqlite_orm::asterisk;
        using sqlite_orm::columns;
        using sqlite_orm::is_equal;
        using sqlite_orm::where;
        auto res = storage.get_all<HighScore>(where(is_equal(&HighScore::name, name)));
        if (res.empty()) {
            throw std::runtime_error("No high score found for name: " + name);
        }
        return res[ 0 ];
    }
};
