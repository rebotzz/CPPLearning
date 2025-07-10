#ifndef RESMGR_H
#define RESMGR_H

#include <vector>
#include <string>
#include <unordered_map>
#include <QJsonObject>

class ResMgr
{
public:
    static ResMgr& getInstance();
    void loadMusic(std::string path);
    const QJsonObject& findMusic(int id);
    const std::vector<QJsonObject>& getMusicPool() const { return musicPool; };

private:
    ResMgr();
    ResMgr(ResMgr&) = delete;
    ResMgr& operator=(const ResMgr&&) = delete;

private:
    std::vector<QJsonObject> musicPool;
    std::unordered_map<std::string, int> indexByMusicName;  // 通过音乐名字索引ID
    std::unordered_map<std::string, int> indexBySingerName; // 通过歌手名字索引ID
};

#endif // RESMGR_H
