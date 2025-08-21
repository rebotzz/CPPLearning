#ifndef RESMGR_H
#define RESMGR_H

#include <vector>
#include <string>
#include <unordered_map>
#include <QJsonObject>

class ResMgr
{
public:
    using MuiscInfoDict = std::unordered_map<std::string, std::string>;
    using MuiscInfoDictList = std::vector<MuiscInfoDict>;

public:
    static ResMgr& getInstance();
    void loadMusic(const std::string& path);
    const MuiscInfoDict& findMusic(uint id);
    const MuiscInfoDictList& getMusicPool() const { return music_pool; };

private:
    ResMgr();
    ResMgr(ResMgr&) = delete;
    ResMgr& operator=(const ResMgr&&) = delete;
    MuiscInfoDict getMusicMetaInfo(const std::string& path);
    MuiscInfoDict getMusicMetaInfo2(const std::string& path);
    std::string trim(const std::string& str, const std::string& sep = " ");

private:
    std::unordered_map<std::string, int> index_by_music_name;  // 通过音乐名字索引ID
    std::unordered_map<std::string, int> index_by_singer; // 通过歌手名字索引ID
    MuiscInfoDictList music_pool;
};

#endif // RESMGR_H
